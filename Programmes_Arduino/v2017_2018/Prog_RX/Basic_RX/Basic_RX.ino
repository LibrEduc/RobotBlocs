/*
  A partir de l'exemple Basic_RX

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

const static byte RADIO_ID = 0;       // Our radio's id.  The transmitter will send to this id.
const static byte PIN_RADIO_CE = 9;
const static byte PIN_RADIO_CSN = 10;

NRFLite MyRadio;

int recept;

void setup()
{
  Serial.begin(115200);
  Serial.println("Start...");
  delay(100);

  if (!MyRadio.init(RADIO_ID, PIN_RADIO_CE, PIN_RADIO_CSN))
  {
    Serial.println("Cannot communicate with radio");
    while (1); // Wait here forever.
  }

  /*
    By default, 'init' configures the radio to use a 2MBPS bitrate on channel 100 (channels 0-125 are valid).
    Both the RX and TX radios must have the same bitrate and channel to communicate with each other.
    You can assign a different bitrate and channel as shown below.
    _radio.init(RADIO_ID, PIN_RADIO_CE, PIN_RADIO_CSN, NRFLite::BITRATE250KBPS, 0)
    _radio.init(RADIO_ID, PIN_RADIO_CE, PIN_RADIO_CSN, NRFLite::BITRATE1MBPS, 75)
    _radio.init(RADIO_ID, PIN_RADIO_CE, PIN_RADIO_CSN, NRFLite::BITRATE2MBPS, 100) // THE DEFAULT
  */
}

void loop()
{
  while (MyRadio.hasData())
  {
    MyRadio.readData(&recept);// & -> pointeur cers l'adresse de la variable
    Serial.println(recept);
  }
}
