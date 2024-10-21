#include <string.h>
#include <stdlib.h>

// Defines

#define MAX_ARGS 16

#define MOVE_COMMAND "move"
#define SENSOR_COMMAND "sensor"

// Globals and Constants



// Functions

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    // Reads a line from the user and converts it to a C style string
    // The string object should not be used as strtok() ruins the array
    String inputString = Serial.readString();
    char *input = const_cast<char *>(inputString.c_str());

    // Read arguments
    char *args[MAX_ARGS];
    args[0] = strtok(input, " ");

    for (int i = 1; (args[i] = strtok(nullptr, " ")) != nullptr; i++);


    // Commands
    if (strcmp(args[0], MOVE_COMMAND) == 0) {
      int distance = atoi(args[1]);

      moveDistance(distance);
    } 
    else if (strcmp(args[0], SENSOR_COMMAND) == 0) {
      char sensorType = *args[1];

      if (sensorType == 'u') {
        checkUltrasonic();
      } else {
        Serial.println("Invalid Sensor command");
      }
    }
    // If the user provides an invalid command
    else {
      Serial.println("Invalid command");
    }
  }
}

void moveDistance(int distance) {
  if (distance >= 0) {
    Serial.print("Moving forward ");
    Serial.print(distance);
    Serial.println(" cm");
  } else {
    Serial.print("Moving backward ");
    Serial.print(distance);
    Serial.println(" cm");
  }
}

void checkUltrasonic() {
  Serial.println("The ultrasonic is 15 cm away");
}

