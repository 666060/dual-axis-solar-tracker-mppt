#include <Servo.h>

Servo horizontal; 
int servoh = 90;  

Servo vertical;   
int servov = 90;  

int ldrlt = A0; 
int ldrrt = A1; 
int ldrld = A2; 
int ldrrd = A3; 

void setup()
{
  Serial.begin(9600);
  horizontal.attach(9);   // غيرنا لـ 9
  vertical.attach(10);    // غيرنا لـ 10
  horizontal.write(90);
  vertical.write(90);
  delay(2000);
}

void loop() 
{
  int lt = analogRead(ldrlt); 
  int rt = analogRead(ldrrt); 
  int ld = analogRead(ldrld); 
  int rd = analogRead(ldrrd); 
  
  int dtime = analogRead(A4)/20;  // سرعة الحركة
  int tol = analogRead(A5)/4;     // الحساسية
  
  int avt = (lt + rt) / 2; 
  int avd = (ld + rd) / 2; 
  int avl = (lt + ld) / 2; 
  int avr = (rt + rd) / 2; 

  int dvert = avt - avd;  
  int dhoriz = avl - avr;
  
  // Vertical movement
  if (-tol > dvert || dvert > tol) 
  {
    if (avt > avd) 
      servov--;
    else if (avt < avd) 
      servov++;
    
    servov = constrain(servov, 0, 180);
    vertical.write(servov);
  }
  
  // Horizontal movement
  if (-tol > dhoriz || dhoriz > tol)  
  {
    if (avl > avr)
      servoh--;
    else if (avl < avr) 
      servoh++;
    
    servoh = constrain(servoh, 0, 180);
    horizontal.write(servoh);
  }
  
  delay(dtime);
}