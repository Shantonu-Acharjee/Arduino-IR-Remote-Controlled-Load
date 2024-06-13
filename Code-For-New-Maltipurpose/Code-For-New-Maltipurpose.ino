#include <IRremote.h>
#define IR_RECEIVE_PIN 5 // Connet ir signal pin
int value = 0;
int Light = A1;
int Fan = A2;

bool LightState = 0;
bool FanState = 0;


//Vertural GND FOR IR
int Vcc = 6;
int Gnd = 7;


//Vertural GND FOR Relay
int VccR = A0;
int GndR = A3;




void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN);
  pinMode(Light, OUTPUT);
  pinMode(Fan, OUTPUT);

  // Vertural Gnd for ir
  pinMode(Vcc, OUTPUT);
  pinMode(Gnd, OUTPUT);
  digitalWrite(Vcc, HIGH);
  digitalWrite(Gnd, LOW);


  // Vertural Gnd for Relay
  pinMode(VccR, OUTPUT);
  pinMode(GndR, OUTPUT);
  digitalWrite(VccR, HIGH);
  digitalWrite(GndR, LOW);
}

void loop() {

  if(IrReceiver.decode()) {

    value = IrReceiver.decodedIRData.command;
    Serial.println(value);

    if(value == 70){
      LightState = !LightState;
      digitalWrite(Light, LightState);
      delay(200);
    }

    
    else if(value == 69){
      FanState = !FanState;
      digitalWrite(Fan, FanState);
      delay(200);
    }

  else if(value == 28){
    LightState = !LightState;
    FanState = !FanState;
    digitalWrite(Light, LightState);
    digitalWrite(Fan, FanState);
    delay(200);
  }

    IrReceiver.resume();
    
  }

  
  
}// Void Loop End