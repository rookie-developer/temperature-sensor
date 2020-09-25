#include <dht.h>   // you need to download the dht library for the temprature sensor i've put it in the deposite
#include <LiquidCrystal.h>

LiquidCrystal lcd(13,12,11,10,9,8);

#define dht_pin A0     // Analog Pin A0 of Arduino is connected to DHT11 out pin
#define blue 3
#define yellow 4
#define red 5
#define green 6
#define buzzer 7
 
dht DHT;
 
void setup()
{
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("rookie developeur");
  delay(1000);lcd.clear();delay(1000);
  pinMode(blue,OUTPUT);pinMode(yellow,OUTPUT);
  pinMode(red,OUTPUT);pinMode(green,OUTPUT);
  pinMode(buzzer,OUTPUT);
}
 
void loop()
{
    DHT.read11(dht_pin);
    lcd.setCursor(0,0);
    lcd.print("Humidity=");
    lcd.setCursor(13,0);
    lcd.print(DHT.humidity);
    lcd.setCursor(15,0);
    lcd.print("%");
    lcd.setCursor(0,1);
    lcd.print("Temperature=");
    lcd.setCursor(13,1);
    lcd.print(DHT.temperature);
    lcd.setCursor(15,1); 
    lcd.println("C");

    // check temperature
    
    if(DHT.temperature>=30)
     {
       digitalWrite(red,HIGH);digitalWrite(buzzer,HIGH);
       digitalWrite(green,LOW);   
     }else {
      digitalWrite(green,HIGH);digitalWrite(buzzer,LOW);
      digitalWrite(red,LOW);
      }

    // check humidity

    if(DHT.humidity>=50 )
    {
      digitalWrite(yellow,HIGH);digitalWrite(buzzer,HIGH);
      digitalWrite(blue,LOW);
    }else {
      digitalWrite(blue,HIGH);digitalWrite(buzzer,LOW);
    digitalWrite(yellow,LOW);
    }
    
    delay(500); //Reduce Time for Quick Reply 
}
