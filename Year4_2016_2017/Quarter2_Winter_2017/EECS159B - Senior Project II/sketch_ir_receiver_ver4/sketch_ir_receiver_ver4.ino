#include <IRremote.h>

const int RECV_PIN = 3;
IRrecv irrecv(RECV_PIN);
decode_results results;

int led_placement = 1;
int first = 0;
int second = 0;
int third = 0;
int fourth = 0;

int ledR1 = 13;
int ledG1 = 12;
int ledB1 = 11;

int ledR2 = 10;
int ledG2 = 9;
int ledB2 = 8;

int ledR3 = 7;
int ledG3 = 6;
int ledB3 = 5;

int ledR4 = 2;
int ledG4 = 0;
int ledB4 = 1;

void setup() {
  //Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  //irrecv.blink13(true);

  pinMode(ledR1, OUTPUT);
  pinMode(ledG1, OUTPUT);
  pinMode(ledB1, OUTPUT);

  pinMode(ledR2, OUTPUT);
  pinMode(ledG2, OUTPUT);
  pinMode(ledB2, OUTPUT);

  pinMode(ledR3, OUTPUT);
  pinMode(ledG3, OUTPUT);
  pinMode(ledB3, OUTPUT);

  pinMode(ledR4, OUTPUT);
  pinMode(ledG4, OUTPUT);
  pinMode(ledB4, OUTPUT);

  digitalWrite(ledR4,LOW);
  digitalWrite(ledG4,LOW);
  digitalWrite(ledB4,LOW);
}

void loop() {
  if (irrecv.decode(&results)) {
    /*
    if (results.decode_type == NEC) {
      Serial.print("NEC: ");
    } else if (results.decode_type == SONY) {
      Serial.print("SONY: ");
    } else if (results.decode_type == RC5) {
      Serial.print("RC5: ");
    } else if (results.decode_type == RC6) {
      Serial.print("RC6: ");
    } else if (results.decode_type == UNKNOWN) {
      Serial.print("UNKNOWN: ");
    }
    */
    //Serial.println(results.value, HEX);

    if(validCode()){
      if(led_placement == 1){
        setColor(ledR1, ledG1, ledB1);
        first = results.value;
        led_placement++;
      }
      if(led_placement == 2 && results.value != first){
        setColor(ledR2, ledG2, ledB2);
        second = results.value;
        led_placement++;
      }
      if(led_placement == 3 && results.value != first && results.value != second){
        setColor(ledR3, ledG3, ledB3);
        third = results.value;
        led_placement++;
      }
      if(led_placement == 4 && results.value != first && results.value != second && results.value != third){
        setColor(ledR4, ledG4, ledB4);
        fourth = results.value;
        led_placement++;
      }
    }
    // Reset
    if(results.value == 0x910){
      setColor(ledR1, ledG1, ledB1);
      setColor(ledR2, ledG2, ledB2);
      setColor(ledR3, ledG3, ledB3);
      setColor(ledR4, ledG4, ledB4);
      led_placement = 1;
    }
    
    //Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
  }   
}

boolean validCode(){
  boolean valid = false;

  switch (results.value){
    case 0x110:
      valid = true;
      break;
    case 0x810:
      valid = true;
      break;
    case 0x410:
      valid = true;
      break;
    case 0xC10:
      valid = true;
      break;
    case 0x210:
      valid = true;
      break;
    case 0xA10:
      valid = true;
      break;
    case 0x610:
      valid = true;
      break;
  }
  
  return valid;
}

void setColor(int ledR, int ledG, int ledB){
  switch (results.value){
    //Red
    //Sony code "9"
    case 0x110:
      digitalWrite(ledR,HIGH);
      digitalWrite(ledG,LOW);
      digitalWrite(ledB,LOW);
      break;
    
    //Green
    //Sony code "2"
    case 0x810:
      digitalWrite(ledR,LOW);
      digitalWrite(ledG,HIGH);
      digitalWrite(ledB,LOW);
      break;
    
    //Blue
    //Sony code "3"
    case 0x410:
      digitalWrite(ledR,LOW);
      digitalWrite(ledG,LOW);
      digitalWrite(ledB,HIGH);
      break;
    
    //Red Green (Yellow)
    //Sony code "4"
    case 0xC10:
      digitalWrite(ledR,HIGH);
      digitalWrite(ledG,HIGH);
      digitalWrite(ledB,LOW);
      break;      
    
    //Red Blue (Magenta)
    //Sony code "5"
    case 0x210:
      digitalWrite(ledR,HIGH);
      digitalWrite(ledG,LOW);
      digitalWrite(ledB,HIGH);
      break;      
    
    //Green Blue (Cyan)
    //Sony code "6"
    case 0xA10:
      digitalWrite(ledR,LOW);
      digitalWrite(ledG,HIGH);
      digitalWrite(ledB,HIGH);
      break;
    
    //Red Green Blue (White)
    //Sony code "7"
    case 0x610:
      digitalWrite(ledR,HIGH);
      digitalWrite(ledG,HIGH);
      digitalWrite(ledB,HIGH);
      break;
    
    //Reset
    //Sony code "0"
    case 0x910:
      digitalWrite(ledR,LOW);
      digitalWrite(ledG,LOW);
      digitalWrite(ledB,LOW);
      break;       
  }
}
