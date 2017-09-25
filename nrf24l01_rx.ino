//--------------------------------------------
//Author- miniProjects
//Arduino wireless interface using nRF24L01-- Rx code
//
//--------------------------------------------
#include <SPI.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";

void setup() {
      Serial.begin(9600);
      
      radio.begin();
      Serial.println("checking if chip connected");
      bool check = radio.isChipConnected();
      Serial.print("check-");
      Serial.println(check);
      
      radio.openReadingPipe(0, address);
      radio.setPALevel(RF24_PA_MIN);
      radio.startListening();
}
void loop() {
      if (radio.available()) {
            int sensorData = 0;
            radio.read(&sensorData, sizeof(sensorData));
            Serial.println(sensorData);
      }
}
