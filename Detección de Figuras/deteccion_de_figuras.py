import cv2
import mediapipe as mp
import serial

# Configura el puerto serial y la velocidad de comunicación
serialArduino = serial.Serial('COM6', 19200)

# Inicializar Mediapipe para la detección de manos
mp_hands = mp.solutions.hands
hands = mp_hands.Hands(static_image_mode=False, max_num_hands=1, min_detection_confidence=0.7)

# Captura de video desde la cámara
cap = cv2.VideoCapture(0)

while True:
    ret, frame = cap.read()
    if not ret:
        break

    # Dividir el frame en cuadrantes
    height, width, _ = frame.shape
    half_width = width // 2
    half_height = height // 2

    # Convertir la imagen a RGB para Mediapipe
    frame_rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
    results = hands.process(frame_rgb)

    # Inicializar el comando en Off
    command = "Off"

    if results.multi_hand_landmarks:
        for hand_landmarks in results.multi_hand_landmarks:
            # Obtener la posición de la punta del dedo índice
            index_x = int(hand_landmarks.landmark[mp_hands.HandLandmark.INDEX_FINGER_TIP].x * width)
            index_y = int(hand_landmarks.landmark[mp_hands.HandLandmark.INDEX_FINGER_TIP].y * height)

            # Determinar en qué cuadrante se encuentra el índice con la inversión
            if index_x < half_width and index_y < half_height:
                command = "Right Up"   # Cuadrante 1 (inversión de derecha)
            elif index_x >= half_width and index_y < half_height:
                command = "Left Up"    # Cuadrante 2 (inversión de izquierda)
            elif index_x < half_width and index_y >= half_height:
                command = "Right Down" # Cuadrante 3 (inversión de derecha)
            elif index_x >= half_width and index_y >= half_height:
                command = "Left Down"  # Cuadrante 4 (inversión de izquierda)

            # Dibujar el cuadrante y la posición de la punta del dedo índice
            cv2.circle(frame, (index_x, index_y), 5, (0, 255, 0), -1)  # Posición del índice

    # Enviar el comando al Arduino
    serialArduino.write((command + '\n').encode())
    print(f"Comando enviado: {command}")

    # Mostrar el comando en pantalla
    cv2.putText(frame, f"Comando: {command}", (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (255, 0, 0), 2)

    # Mostrar los cuadrantes en la imagen
    cv2.line(frame, (half_width, 0), (half_width, height), (255, 255, 255), 1)
    cv2.line(frame, (0, half_height), (width, half_height), (255, 255, 255), 1)

    # Muestra el fotograma procesado
    cv2.imshow("Frame", frame)

    # Salir al presionar 'Esc'
    if cv2.waitKey(1) & 0xFF == 27:
        break

# Liberar recursos
cap.release()
cv2.destroyAllWindows()
serialArduino.close()
