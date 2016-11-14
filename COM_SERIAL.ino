#include <LiquidCrystal.h>
char inChar;
int i=0;
String string="";
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  Serial.begin(9600);
  string.reserve(200);
}

void loop()
{
  if (Serial.available())
  {
//Lectura de caracteres   
   inChar = Serial.read();
//Suma de caracteres en variable string
   string+=inChar;
   
//Imprime la variable con los caracteres acumulados hasta la ","   
   if (inChar==',')
   {
    for (;i<16;i++)
    {
      //string=""; 
      lcd.setCursor(i, 0);
      lcd.print(string);
      delay(500);
      lcd.setCursor(i, 0);
      lcd.print(" ");     
    }
    

    for(i=16 ;i>=0;i--)
    {
      //string=""; 
          
      lcd.setCursor(i, 1);
      lcd.print(string);
      delay(500);
      lcd.setCursor(i, 1);
      lcd.print("        ");     
    }
   // i=0;
   }
  }
  
}
    



