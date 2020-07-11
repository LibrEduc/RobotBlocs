/*
  A partir de l'exemple BASIC_TX

  Demonstrates simple RX and TX operation.
  Please read the notes in NRFLite.h for a description of all library features.

  Radio    Arduino
  CE    -> 9
  CSN   -> 10 (Hardware SPI SS)
  MOSI  -> 11 (Hardware SPI MOSI)
  MISO  -> 12 (Hardware SPI MISO)
  SCK   -> 13 (Hardware SPI SCK)
  IRQ   -> No connection
  VCC   -> No more than 3.6 volts
  GND   -> GND

*/

#include <SPI.h>
#include <NRFLite.h>

const static byte RADIO_ID = 1;             // Our radio's id.
const static byte DESTINATION_RADIO_ID = 0; // Id of the radio we will transmit to.
const static byte PIN_RADIO_CE = 9;
const static byte PIN_RADIO_CSN = 10;

int val = 0;
boolean test;

NRFLite MyRadio;

void setup()
{
  Serial.begin(115200);

  if (!MyRadio.init(RADIO_ID, PIN_RADIO_CE, PIN_RADIO_CSN))
  {
    Serial.println("Cannot communicate with radio");
    while (1); // Wait here forever.
  }

}

void loop()
{
  Serial.print(val);
  test = MyRadio.send(DESTINATION_RADIO_ID, &val, sizeof(val));// & -> pointeur vers la variable
  Serial.print(" ");
  if (test)
    Serial.println("Success");
  else
    Serial.println("Erreur");
  delay(1000);
  val++;

  delay(1000);
  /*
    By default, 'send' transmits data and waits for an acknowledgement.
    You can also send without requesting an acknowledgement.
    _radio.send(DESTINATION_RADIO_ID, &_radioData, sizeof(_radioData), NRFLite::NO_ACK)
    _radio.send(DESTINATION_RADIO_ID, &_radioData, sizeof(_radioData), NRFLite::REQUIRE_ACK) // THE DEFAULT
  */
}
