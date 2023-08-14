# Red-Ad-Hoc-Esp32
# Red Ad Hoc Autónoma con painlessMesh en ESP32

Este proyecto presenta la implementación de una red ad hoc autónoma y descentralizada utilizando el protocolo "painlessMesh" en dispositivos ESP32 programados con el entorno de desarrollo Arduino. El objetivo principal es establecer una red de malla inalámbrica en la que los nodos individuales, representados por los ESP32, puedan comunicarse directamente entre sí sin depender de una infraestructura centralizada de redes.
## Requisitos Previos

Antes de comenzar, asegúrate de tener lo siguiente:

- Placa ESP32 compatible
- Entorno de desarrollo Arduino instalado
- Biblioteca "painlessMesh" instalada en Arduino (se puede instalar desde el Administrador de Bibliotecas)

## Configuración Inicial

1. Abre el archivo `painlessMesh_ESP32.ino` en el entorno de desarrollo Arduino.

2. Selecciona la placa ESP32 en el menú "Herramientas > Placa".

3. Configura los siguientes parámetros de red según tus preferencias:

   ```cpp
   #define MESH_PREFIX "MiRedAdHoc"   // Nombre de la red
   #define MESH_PASSWORD "clave1234"  // Contraseña para acceder a la red
   #define MESH_PORT 5555             // Puerto de comunicación para la red de malla

## Características y Funcionalidad

La red ad hoc se configura con los siguientes parámetros:

- Nombre de la red: "MiRedAdHoc"
- Contraseña para acceder a la red: "clave1234"
- Puerto de comunicación: 5555

Cada nodo en la red ad hoc:

1. Inicializa una conexión serial para la depuración a 115200 baudios.
2. Configura mensajes de depuración para mostrar solo errores.
3. Asigna un número de nodo manualmente (en este caso, 1).
4. Inicia la red de malla con los parámetros definidos.
5. Establece una función de manejo de mensajes recibidos.

En el bucle principal:

1. Actualiza el estado de la red de malla.
2. Verifica si es el momento de actualizar el número de nodos conectados y lo muestra.
3. Maneja el envío de mensajes desde el nodo actual a través de la comunicación serial.
4. Envia los mensajes a todos los nodos de la red utilizando "sendBroadcast".

La función "receivedCallback" implementa una simple lógica para mostrar mensajes recibidos en la consola.

## Objetivo y Aplicaciones

Este proyecto busca abordar la falta de comunicación efectiva y confiable en entornos donde las infraestructuras de redes inalámbricas tradicionales son insuficientes o inexistentes. La red ad hoc autónoma creada tiene aplicaciones potenciales en diversas áreas, incluidas zonas rurales, entornos de emergencia y lugares remotos, donde la falta de conectividad digital limita la capacidad de intercambio de información y datos.

## Ejecución

Si deseas utilizar este proyecto, simplemente carga el código en dispositivos ESP32 compatibles y ajusta los parámetros de red según sea necesario.

