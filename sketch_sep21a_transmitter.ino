//Include Libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

//create an RF24 object
RF24 radio(9, 8);  // CE, CSN

//address through which two modules communicate.
const byte address[6] = "00001";

void setup()
{
  radio.begin();
  
  //set the address
  radio.openWritingPipe(address);
  
  //Set module as transmitter
  radio.stopListening();
}
void loop()
{
  //Send message to receiver
  int text[5] = {0, 0, 0, 0, 0};
  for (int i = 0; i < 1000; i++){
    text[0] = i;
    text[1] = i + 1;
    text[2] = i + 2;
    text[3] = i + 3;
    text[4] = i + 4;
    radio.write(&text, sizeof(text));
    delay(1000);
  }
  
  
}
