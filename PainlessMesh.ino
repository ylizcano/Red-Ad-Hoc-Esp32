// Importación de la librería "painlessMesh" para habilitar la comunicación en red
#include "painlessMesh.h"

// Definición de parámetros de la red ad hoc:
#define MESH_PREFIX "MiRedAdHoc"   // Definimos el nombre de la red
#define MESH_PASSWORD "clave1234"  // Establecemos la contraseña de acceso
#define MESH_PORT 5555             // Definimos el puerto de comunicación para la red de malla

// Variables globales:
uint32_t nodeNumber; // Asignamos manualmente el número de este nodo

// Intervalo de tiempo para mostrar el número de nodos conectados (en milisegundos)
const unsigned long updateInterval = 20000; // Actualizamos cada 20 segundos

// Prototipo de la función para manejar mensajes recibidos
void receivedCallback(uint32_t from, String &msg);

// Instancia de la red de malla:
painlessMesh mesh;

// Variable para registrar el tiempo de la última actualización
unsigned long previousUpdate = 0;

// Configuración inicial del dispositivo
void setup() {
  // Inicializamos la comunicación serial a 115200 baudios para la depuración
  Serial.begin(115200);

  // Configuramos los tipos de mensajes de depuración que se mostrarán (solo mensajes de error)
  mesh.setDebugMsgTypes(ERROR);

  // Asignamos manualmente el número de nodo a este ESP32
  nodeNumber = 1;

  // Inicializamos la red de malla con los parámetros definidos y configuramos la función "receivedCallback"
  mesh.init(MESH_PREFIX, MESH_PASSWORD, MESH_PORT);
  mesh.onReceive(&receivedCallback);

  // Mostramos un mensaje de bienvenida en la consola
  Serial.println("Bienvenido al chat del Nodo " + String(nodeNumber));
}

// Función que se ejecuta en un ciclo repetitivo
void loop() {
  // Actualizamos el estado de la red de malla
  mesh.update();

  // Obtenemos el tiempo actual en milisegundos
  unsigned long currentMillis = millis();

  // Verificamos si es tiempo de actualizar el número de nodos conectados
  if (currentMillis - previousUpdate >= updateInterval) {
    previousUpdate = currentMillis;
    // Mostramos en la consola la cantidad de nodos conectados a la red
    Serial.println("Número de nodos conectados: " + String(mesh.getNodeList().size()));
  }

  // Manejamos el envío de mensajes desde el nodo actual
  if (Serial.available()) {
    // Leemos el mensaje ingresado por el usuario hasta que se presione Enter
    String message = Serial.readStringUntil('\n');
    if (message.length() > 0) {
      // Creamos un mensaje completo con información del nodo y el mensaje ingresado
      String sentMessage = "Mensaje Enviado desde Nodo " + String(nodeNumber) + ": " + message;
      Serial.println(sentMessage);

      // Enviamos el mensaje a todos los nodos de la red utilizando la función "sendBroadcast"
      mesh.sendBroadcast(sentMessage);
    }
  }
}

// Implementación simple para la función receivedCallback
void receivedCallback(uint32_t from, String &msg) {
  // Mostramos en la consola los mensajes recibidos de otros nodos
  Serial.println(msg);
}