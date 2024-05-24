
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
 
RF24 radio(PB0, PA4); // CE, CSN on Blue Pill
const uint64_t address = 0xF0F0F0F0E1LL;
const byte addresses[][6] = {"00001", "00002"};
boolean buttonState = 0;
boolean buttonState2 = 0;
int K1 = 0;
int K10 = 0;
int setrelay=0;
int setrelay2=0;
int set1=0;
int set2=0;
boolean toggle = true;

#define Y1 PA8
#define Y2 PB9
#define Y3 PB8
#define Y4 PB7
#define Y5 PB6
#define Y6 PB5
#define Y7 PB4
#define Y8 PB3
#define Y9 PA9
#define Y10 PA4
#define Y11 PA3
#define Y12 PA12

int ledState = LOW;             // ledState used to set the LED

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time LED was updated
unsigned long previousMillis2 = 0; 
unsigned long previousMillis3 = 0;

unsigned long lastRecvTime = 0;
// constants won't change:
const long interval = 500;           // interval at which to blink (milliseconds
 
void setup() 
{
   pinMode(PC13, OUTPUT);
   pinMode(PC14, OUTPUT);
   //pinMode(PB9, INPUT);
   pinMode(Y1, OUTPUT);
   pinMode(Y2, OUTPUT);
   pinMode(Y3, OUTPUT);
   pinMode(Y4, OUTPUT);
   pinMode(Y5, OUTPUT);
   pinMode(Y6, OUTPUT);
   pinMode(Y7, OUTPUT);
   pinMode(Y8, OUTPUT);
   pinMode(Y9, OUTPUT);
    pinMode(Y10, OUTPUT);
     pinMode(Y11, OUTPUT);
      pinMode(Y12, OUTPUT);
      
   digitalWrite(Y1, LOW);
   digitalWrite(Y2, LOW);
   digitalWrite(Y3, LOW);
   digitalWrite(Y4, LOW);
   digitalWrite(Y5, LOW);
   digitalWrite(Y6, LOW);
   digitalWrite(Y7, LOW);
   digitalWrite(Y8, LOW);
   digitalWrite(Y9, LOW);
    digitalWrite(Y10, LOW);
     digitalWrite(Y11, LOW);
      digitalWrite(Y12, LOW);
   digitalWrite(PC13, LOW);
   digitalWrite(PC14, LOW);
Serial.begin(9600);
radio.begin();
Serial.print("ADDRESS :");
radio.openReadingPipe(0, address);   //Setting the address at which we will receive the data
radio.setPALevel(RF24_PA_MAX,1);       //You can set this as minimum or maximum depending on the distance between the transmitter and receiver.
 radio.setChannel(123); //select a channel (in which there is no noise!) 0 ... 125

 radio.setAutoAck(false);
//transmitter power level. To choose RF24_PA_MIN, RF24_PA_LOW, RF24_PA_HIGH, RF24_PA_MAX
  radio.setDataRate(RF24_2MBPS);  //RF24_250KBPS for 250kbs, RF24_1MBPS for 1Mbps, or RF24_2MBPS for 2Mbps

radio.startListening();              //This sets the module as receiver


//   radio.openWritingPipe(addresses[0]); // 00001
//  radio.openReadingPipe(1, addresses[1]); // 00002
//  radio.setPALevel(RF24_PA_MIN);
   
  
}
void loop()
{

recvData();

//lastRecvTime = millis();  


unsigned long now = millis();
if ( now - lastRecvTime > 1500 ) 

{
   ResetData();
   digitalWrite(PC14, HIGH);
  
  // Signal lost.. Reset data | Sinyal kayıpsa data resetleniyor
}
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = 1;
    } else {
      ledState = 0;
    }

    // set the LED with the ledState of the variable:
    //digitalWrite(outpin, ledState);
  }

if (digitalRead(Y1) == HIGH && digitalRead(Y2) == HIGH)
{ // if BOTH the switches read HIGH
  // statements


 digitalWrite(Y1, LOW);
   digitalWrite(Y2, LOW);
  
}

  if (K1 == 1) {
    digitalWrite(Y1, HIGH);
   // digitalWrite(Y1, !digitalRead(Y1));
    //delay(300);
  }
  else  if (K1 == 0) {
   
   //delay(300);
    //digitalWrite(Y1, LOW);
    
  }
  else if (K1 == 3) {
    digitalWrite(Y2, HIGH);
   // digitalWrite(Y2, !digitalRead(Y2));
    //delay(300);
  }
  else  if (K1 == 2) {
   
     
   //delay(300);
  //  digitalWrite(Y2, LOW);
   
  }
  

else if (K1 == 5) {
    digitalWrite(Y3, HIGH);
    
    //delay(300);
  }
  else  if (K1 == 4) {

   digitalWrite(Y3, LOW);

  
  

   
  
  }
    
  
  else if (K1 == 7) {
    digitalWrite(Y4, HIGH);
    digitalWrite(Y1, LOW);
    digitalWrite(Y2, LOW);
    digitalWrite(Y3, LOW);
    digitalWrite(Y4, LOW);
    digitalWrite(Y5, LOW);
    digitalWrite(Y6, LOW);
    
    //delay(300);
  }
  else  if (K1 == 6) {
    digitalWrite(Y4, LOW);
  }
  
    else if (K1 == 9) {
   digitalWrite(Y5, HIGH);
   //delay(300);
    // digitalWrite(Y5, !digitalRead(Y5));
   //  //delay(300);
    
    
  }
  else  if (K1 == 8) {
    digitalWrite(Y5, LOW);
    
  }

  
  
  else if (K1 == 11) {
    digitalWrite(Y6, HIGH);
    //delay(300);
     //digitalWrite(Y6, !digitalRead(Y6));
    // //delay(300);
  }
  else  if (K1 == 10) {
digitalWrite(Y6, LOW);
  }


  else if (K1 == 13) {
   digitalWrite(Y7, HIGH);
    //delay(300);
  }
  else  if (K1 == 12) {
    digitalWrite(Y7, LOW);
  }
  else if (K1 == 15) {
    digitalWrite(Y8, HIGH);
    //delay(300);
  }
  else  if (K1 == 14) {
    digitalWrite(Y8, LOW);
  }
  else if (K1 == 17) {
    digitalWrite(PC13, HIGH);
     digitalWrite(PC14, HIGH);
    //digitalWrite(Y9, HIGH);
  }
  else  if (K1 == 16) {
    digitalWrite(PC13, LOW);
     digitalWrite(PC14, LOW);
   // digitalWrite(Y9, LOW);
  }

  else if (K1 == 19) {
    digitalWrite(Y9, HIGH);
    //delay(300);
  }
  else  if (K1 == 18) {
    digitalWrite(Y9, LOW);
  }


  else if (K1 == 21) {
    digitalWrite(Y10, HIGH);
  }
  else  if (K1 == 20) {
    digitalWrite(Y10, LOW);
  }


  else if (K1 == 23) {
    //digitalWrite(Y11, HIGH);
    //delay(300);
  }
  else  if (K1 == 22) {
    digitalWrite(Y11, LOW);
  }

  else if (K1 == 25) {
    digitalWrite(Y12, HIGH);
    //delay(300);
  }
  else  if (K1 == 24) {
    digitalWrite(Y12, LOW);
  }
  
delay(5);

 

// else {
   // delay(3000);
//   digitalWrite(Y1, LOW);
//   digitalWrite(Y2, LOW);
//   digitalWrite(Y3, LOW);
//   digitalWrite(Y4, LOW);
//   digitalWrite(Y5, LOW);
//   digitalWrite(Y6, LOW);
//   digitalWrite(Y7, LOW);
//   digitalWrite(Y8, LOW);
//   digitalWrite(Y9, LOW);
//   digitalWrite(Y10, LOW);
//   digitalWrite(Y11, LOW);
//   digitalWrite(Y12, LOW);
//   digitalWrite(PC13, HIGH);
  
 //}

//  delay(5);
//   radio.stopListening();
//   K10 = ledState;
//   if (K10 == 1)
//  {
//    K10 = 1;
//  }
//  else  if (K10 == 0)
//  {
//    K10 = 0;
//  }
//    radio.write(&K10, sizeof(K10));




}


void recvData()
{
  radio.startListening();  
  while (radio.available())
  {
  radio.read(&K1, sizeof(K1));
  Serial.println(K1);

//   if(K1 == 9)
//  {
//    if(toggle)
//    {
//      digitalWrite(Y5, HIGH);   // set the LED on
//      toggle = !toggle;
//    }
//    else
//    {
//      digitalWrite(Y5, LOW);    // set the LED off
//      toggle = !toggle;
//    }
//  }


 
  

   
  
 
 
 lastRecvTime = millis();   
}
}


void ResetData()
{
    digitalWrite(Y1, LOW);
   digitalWrite(Y2, LOW);
   digitalWrite(Y3, LOW);
   digitalWrite(Y4, LOW);
   digitalWrite(Y5, LOW);
   digitalWrite(Y6, LOW);
   digitalWrite(Y7, LOW);
   digitalWrite(Y8, LOW);
   digitalWrite(Y9, LOW);
   digitalWrite(Y10, LOW);
   digitalWrite(Y11, LOW);
   digitalWrite(Y12, LOW);
   digitalWrite(PC13, HIGH);
                                                    
}
