//-------------------------------------------
//Author- miniProjects
//Arduino wireless interface using nRF24L01-- Tx code
//Code transmits pot value connected to pin A0
//-------------------------------------------
#include <SPI.h>
#include <RF24.h>

const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
int sensorValue = 0;         // value read from the pot
RF24 radio(7, 8);            // CE, CSN
const byte address[6] = "00001";

void setup() {
      pinMode(analogInPin,INPUT);
      
      radio.begin();
      Serial.println("checking if chip connected");
      bool check = radio.isChipConnected();
      Serial.print("check-");
      Serial.println(check);
  
      radio.openWritingPipe(address);
      radio.setPALevel(RF24_PA_MIN);
      radio.stopListening();
}
void loop() {
      sensorValue = analogRead(analogInPin);
      radio.write(&sensorValue, sizeof(sensorValue));
      delay(500);
}
