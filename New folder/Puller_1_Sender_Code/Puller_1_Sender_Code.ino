#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
 
RF24 radio(PB0, PA4); // CE, CSN on Blue Pill 
const uint64_t address = 0xF0F0F0F0E1LL;
const byte address1[6] = "00001";
int counter = 0;
 const byte addresses[][6] = {"00001", "00002"};
boolean buttonState = 0;
boolean buttonState2 = 0;


int K01 = 0;
int K02 = 0;
int K03 = 0;
int K04 = 0;
int K05 = 0;
int K06 = 0;
int K07 = 0;
int K08 = 0;
int K09 = 0;
int K1=0;
int K10=0;
int K11=0;
int K12=0;
int K13=0;

#define X1 PB3
#define X2 PB4
#define X3 PB5
#define X4 PB6
#define X5 PB7 //PB8
#define X6 PB8  //PB9
#define X7 PB9
#define X8 PA8  
#define X9 PA9  
#define X10 PA10  //PA10
#define X11 PA11 //PA11
#define X12  PA12  


int ledState = LOW;             // ledState used to set the LED

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change:
const long interval = 500;           // interval at which to blink (milliseconds

void setup() 
{
  pinMode(PC13, OUTPUT);
   pinMode(X1, INPUT);
   pinMode(X2, INPUT);
   pinMode(X3, INPUT);
   pinMode(X4, INPUT);
   pinMode(X5, INPUT);
   pinMode(X6, INPUT);
   pinMode(X7, INPUT);
   pinMode(X8, INPUT);
    pinMode(X9, INPUT);
     pinMode(X10, INPUT);
      pinMode(X11, INPUT);
       pinMode(X12, INPUT);
  digitalWrite(PC13, LOW);
  
Serial.begin(9600);
radio.begin();                  //Starting the Wireless communication
radio.openWritingPipe(address1); //Setting the address where we will send the data
//radio.setPALevel(RF24_PA_MAX,1);  //You can set it as minimum or maximum depending on the distance between the transmitter and receiver.
// radio.setChannel(95); //select a channel (in which there is no noise!) 0 ... 125
//transmitter power level. To choose RF24_PA_MIN, RF24_PA_LOW, RF24_PA_HIGH, RF24_PA_MAX
  //radio.setDataRate (RF24_2MBPS);
  radio.setPALevel(RF24_PA_MIN);
radio.stopListening();          //This sets the module as transmitter

//
// radio.openWritingPipe(addresses[1]); // 00002
//  radio.openReadingPipe(1, addresses[0]); // 00001
//  radio.setPALevel(RF24_PA_MIN);
}
 
void loop()
{



  
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

  
 //delay(5);

  radio.stopListening();
  Serial.println(K01);
  K09 = ledState;
         K01 = digitalRead(X1);
         K02 = digitalRead(X2);
         K03 = digitalRead(X3);
         K04 = digitalRead(X4);
         K05 = digitalRead(X5);
         K06 = digitalRead(X6);
         K07 = digitalRead(X7);
         K08 = digitalRead(X8);
           K13 = digitalRead(X9);
             K10 = digitalRead(X10);
               K11 = digitalRead(X11);
                 K12 = digitalRead(X12);


  if (K01 == 1)
  {
    K01 = 1;
  }
  else  if (K01 == 0)
  {
    K01 = 0;
  }
  if (K02 == 1)
  {
    K02 = 3;
  }
  else  if (K02 == 0)
  {
    K02 = 2;
  }


 if (K03 == 1)
  {
    K03 = 5;
  }
  else  if (K03 == 0)
  {
    K03 = 4;
  }
  if (K04 == 1)
  {
    K04 = 7;
  }
  else  if (K04 == 0)
  {
    K04 = 6;
  }




 if (K05 == 1)
  {
    K05 = 9;
  }
  else  if (K05 == 0)
  {
    K05 = 8;
  }
  if (K06 == 1)
  {
    K06 = 11;
  }
  else  if (K06 == 0)
  {
    K06 = 10;
  }





 if (K07 == 1)
  {
    K07 = 13;
  }
  else  if (K07 == 0)
  {
    K07 = 12;
  }
  if (K08 == 1)
  {
    K08 = 15;
  }
  else  if (K08 == 0)
  {
    K08 = 14;
  }

if (K09 == 1)
  {
    K09 = 17;
  }
  else  if (K09 == 0)
  {
    K09 = 16;
  }



if (K10 == 1)
  {
    K10 = 19;
  }
  else  if (K10 == 0)
  {
    K10 = 18;
  }



  if (K11 == 1)
  {
    K11 = 21;
  }
  else  if (K11 == 0)
  {
    K11 = 20;
  }




  if (K12 == 1)
  {
    K12 = 23;
  }
  else  if (K12 == 0)
  {
    K12 = 22;
  }



  if (K13 == 1)
  {
    K13 = 25;
  }
  else  if (K13 == 0)
  {
    K13 = 24;
  }

Serial.print(K01);
  Serial.print("\t");
  Serial.println(K02);
  Serial.print("\t");
  Serial.println(K03);
  Serial.print("\t");
  Serial.println(K04);
  Serial.print("\t");
  Serial.println(K05);
  Serial.print("\t");
  Serial.println(K06);
  Serial.print("\t");
  Serial.println(K07);
  Serial.print("\t");
  Serial.println(K08);
  Serial.print("\t");
   Serial.println(K09);
  Serial.print("\t");

   Serial.println(K10);
  Serial.print("\t");

   Serial.println(K11);
  Serial.print("\t");

   Serial.println(K12);
  Serial.print("\t");
  
  


            radio.write(&K01, sizeof(K01));
            radio.write(&K02, sizeof(K02));
            radio.write(&K03, sizeof(K03));
            radio.write(&K04, sizeof(K04));
            radio.write(&K05, sizeof(K05));
            radio.write(&K06, sizeof(K06));
            radio.write(&K07, sizeof(K07));
            radio.write(&K08, sizeof(K08));
             radio.write(&K09, sizeof(K09));
             radio.write(&K10, sizeof(K10));
             radio.write(&K11, sizeof(K11));
             radio.write(&K12, sizeof(K12));
             radio.write(&K13, sizeof(K13));


// delay(5);
//  radio.startListening();
//  while (!radio.available());
//  radio.read(&K10, sizeof(K10));
//  Serial.println(K10);
//  if (K10 == 1) {
//    digitalWrite(PC13, HIGH);
//  }
//  else  if (K10 == 0) {
//    digitalWrite(PC13, LOW);
//  }
             

  
}
