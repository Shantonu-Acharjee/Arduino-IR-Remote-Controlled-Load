#include <IRremote.h>
#define IR_RECEIVE_PIN 8 // Connet ir signal pin
int value = 0;
int Light = 13;
int Fan = 11;

bool LightState = 0;
bool FanState = 0;




void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN);
  pinMode(Light, OUTPUT);
  pinMode(Fan, OUTPUT);
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