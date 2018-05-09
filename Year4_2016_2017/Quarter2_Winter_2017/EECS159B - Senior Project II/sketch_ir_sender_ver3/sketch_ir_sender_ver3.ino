#include <IRremote.h>

IRsend irsend;

void setup() {
  //Serial.begin(9600);
  //Serial.println("Sending begin");

  //Send reset code for 3 seconds
  while(millis() < 3000){
    //Serial.println("Sending Reset code");
    irsend.sendSony(0x910, 20);
  }
}

void loop() {
  // Note: IRsend only works with pin 3 on the Arduino Uno 
  // Note: IRsend only works with pin 13 on the Arduino Micro 
 
  //Serial.println("Sending Player code");
  
  //Player 1 code
  irsend.sendSony(0x110, 20);
  
  //Player 2 code
  //irsend.sendSony(0x810, 20);

  //Player 3 code
  //irsend.sendSony(0x410, 20);

  //Player 4 code
  //irsend.sendSony(0x610, 20);

  delay(30);
}



