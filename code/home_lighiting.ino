#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

int livingroom = 5;
int bedroom1 = 6;
int diningroom = 7;
int ldrPin = A0;
int led = 4;
int threshold = 120;  
SoftwareSerial Bluetooth(10, 11);
char Data;
void sendData(String transmitData){
Bluetooth.println(transmitData);}
void setup(){
    Bluetooth.begin(9600);
    pinMode(livingroom,OUTPUT);
    pinMode(bedroom1,OUTPUT);
    pinMode(diningroom,OUTPUT);
    pinMode(led, OUTPUT);
}
void loop(){
  int data = analogRead(ldrPin);
    if(Bluetooth.available()){
        Data=Bluetooth.read();
        if(Data==('1')){
            digitalWrite(livingroom,1);
            sendData("Living Room Light ON");
        }
        if(Data==('2')){
            digitalWrite(livingroom,0);
            sendData("Living Room Light OFF");
        }
        if(Data==('3')){
            digitalWrite(bedroom1,1);
            sendData("Bedroom Light ON");
        }
        if(Data==('4')){
            digitalWrite(bedroom1,0);
            sendData("Bedroom Light OFF");
        }
        if(Data==('5')){
            digitalWrite(diningroom,1);
            sendData("Dining Room Light ON");
        }
        if(Data==('6')){
            digitalWrite(diningroom,0);
            sendData("Dining Room Light OFF");
        }      
        if(Data==('9')){
            digitalWrite(livingroom,1);
            digitalWrite(bedroom1,1);
            digitalWrite(diningroom,1);
            Data= '7';
            sendData("ALL LIGHTS ON");
        }
        if(Data==('0')){
            digitalWrite(livingroom,0);
            digitalWrite(bedroom1,0);
            digitalWrite(diningroom,0);
            Data='8';
            sendData("ALL LIGHTS OFF");
        }
        if(Data==('7')){
            if(data <= threshold)
            {
              digitalWrite(led, 1);
              sendData("BALCONY LIGHTS OFF");
            }
            else
            {
              digitalWrite(led, 0);
              sendData("BALCONY LIGHTS OFF");
            } 
        }
        if(Data==('8')){
            digitalWrite(led,0); 
            sendData("BALCONY LIGHTS OFF");       
        }     
    }
}
