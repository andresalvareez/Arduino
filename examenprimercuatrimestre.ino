#include <SR04.h>

// Definimos a qué pines conectamos trigger y echo
#define TRIG_PIN 11
#define ECHO_PIN 10

// Creamos un objeto de tipo sensor de distancia
SR04 sensor = SR04(ECHO_PIN, TRIG_PIN);

// Variable que almacenará la distancia
long distancia;
int contador; //variable para aumentar el parpadeo

void setup() {
  pinMode(9, OUTPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  delay(1000);
}

void loop() {
  distancia = sensor.Distance();
  delay(100);


  if (distancia < 5 || distancia > 30) { //creo la condicion para que el led este apagado si es menor que 5 la distancia o mayor que 30
    digitalWrite(9, LOW);
  }
  else {
    for (int i = 5; i <= 30; i++) {//este for es para que aumentase proporcionalmente el parpadeo pero no he sabido terminarlo
      digitalWrite(9, HIGH);
    }
  }
}
