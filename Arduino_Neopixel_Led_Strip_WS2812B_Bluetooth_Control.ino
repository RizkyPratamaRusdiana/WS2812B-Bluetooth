/*
 * Arduino Control Led Strip WS2812B Using App
 * Sindangkerta, 20 Apr 2020
 * Created by Ngulik.id
 */

#include <Adafruit_NeoPixel.h>
#include <SoftwareSerial.h>

#define LED_PIN 4     //Pin yang terhubung ke Digital Input Led Strp
#define LED_COUNT 85  //Jumlah Neopixel LED yang akan digunakan

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_RGB + NEO_KHZ800);//Deklarasi objek LED Strip Neopixel Led Strip
SoftwareSerial Bluetooth(10, 11); // Arduino(RX, TX) - Bluetooth (TX, RX)


int brightness = 100;   //Mengatur Cahaya
int redColor = 0;
int greenColor = 0;
int blueColor = 0;

int redColor2 = 0;
int greenColor2 = 0;
int blueColor2 = 0;

String dataIn = "";   //Variabel Menerima data dari App

unsigned long timer1 = 0;


void setup(){
  strip.begin();
  strip.show();   
  strip.setBrightness(brightness);
  Bluetooth.begin(38400);
  Serial.begin(38400);
}


void loop(){
  
  if (Bluetooth.available() > 0);{
    dataIn = Bluetooth.readString();
    delay(20);
    Serial.println(dataIn);
    
    if (dataIn.startsWith("1")){
//      delay(10);
//      digitalWrite(6, 1);
      String R = dataIn.substring(dataIn.indexOf("R") +1, dataIn.indexOf("G"));
      redColor = R.toInt();
      Serial.println(R);
      String G = dataIn.substring(dataIn.indexOf("G") +1, dataIn.indexOf("B"));
      greenColor = G.toInt();
      Serial.println(G);
      String B = dataIn.substring(dataIn.indexOf("B") +1, dataIn.indexOf("E"));
      blueColor = B.toInt();
      Serial.println(B);
//
      }

    if (dataIn.startsWith("2")){
      String stringBrightness = dataIn.substring(dataIn.indexOf("2") + 1, dataIn.length());
      brightness = stringBrightness.toInt();
      strip.setBrightness(brightness); 
      Serial.println(brightness);
    }

//    if (dataIn.startsWith("3")){
//      delay(10);
//      digitalWrite(6, 0);
//      String R = dataIn.substring(dataIn.indexOf("R") +1, dataIn.indexOf("G"));
//      redColor = R.toInt();
//      Serial.println(R);
//      String G = dataIn.substring(dataIn.indexOf("G") +1, dataIn.indexOf("B"));
//      greenColor = G.toInt();
//      Serial.println(G);
//      String B = dataIn.substring(dataIn.indexOf("B") +1, dataIn.indexOf("E"));
//      blueColor = B.toInt();
//      Serial.println(B);
//
//    }

    
       for (int i = 0; i < LED_COUNT; i++){
      strip.setPixelColor(i, strip.Color(greenColor, redColor, blueColor));
  
    }
  }

  strip.show();
  delay(20);
}
