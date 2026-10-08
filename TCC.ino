#define BLYNK_TEMPLATE_ID "TMPL2EyA5WxxR"
#define BLYNK_TEMPLATE_NAME "COMANDANDO LEDS"
#define BLYNK_AUTH_TOKEN "SAdGUhynzfGCRK7HsoQ-a3iw75qHJDgd"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <ESP32Servo.h> 

char ssid[] = "TCC";
char pass[] = "12345678";

Servo meuServo;  

void setup() {
  Serial.begin(115200);
  
  // Inicializa a conexão com o Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  
  // Configura os pinos dos LEDs
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(27, OUTPUT);
  pinMode(25, OUTPUT);
  
  meuServo.attach(32);  
}

BLYNK_WRITE(V0) {
  int pinValue = param.asInt();
  digitalWrite(13, pinValue);
}

BLYNK_WRITE(V1) {
  int pinValue = param.asInt();
  digitalWrite(12, pinValue);
}

BLYNK_WRITE(V2) {
  int pinValue = param.asInt();
  digitalWrite(14, pinValue);
}

BLYNK_WRITE(V3) {
  int pinValue = param.asInt();
  digitalWrite(26, pinValue);
}

BLYNK_WRITE(V4) {
  int pinValue = param.asInt();
  digitalWrite(27, pinValue);
}

BLYNK_WRITE(V5) {
  int pinValue = param.asInt();
  digitalWrite(25, pinValue);
  digitalWrite(33, pinValue);
}

BLYNK_WRITE(V7) {
  int pinValue = param.asInt();
  digitalWrite(35, pinValue);
}

BLYNK_WRITE(V6) {  // Novo widget do Blynk para controlar o servo
  int pinValue = param.asInt();
  
  if(pinValue == 1) {
    meuServo.write(90);  // Mover o servo para 90 graus
  } else {
    meuServo.write(0);  // Mover o servo para 0 graus (posição inicial)
  }
}


void loop() {
  Blynk.run();
}
