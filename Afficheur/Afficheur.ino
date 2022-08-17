#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int k=0;
//----- Adressage matériel -----
// En cas de non fonctionnement, mettez la ligne 8 en
// commentaire et retirez le commentaire à la ligne 9.
LiquidCrystal_I2C lcd(0x27, 20, 4);
//LiquidCrystal_I2C lcd(0x3F,20,4);
void setup()
{
 Serial.begin(9600);
 lcd.init(); // initialisation de l'afficheur
}
void loop()
{
 if(Serial.available()){

  String a=Serial.readString();
  lcd.backlight();
 // Envoi du message
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(a);
    k=1;
  
 
 }
 
}
