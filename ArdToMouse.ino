#include <Mouse.h>

int horzPin = A1;                     // x-axis                                                           
int vertPin = A0;                      // y-axis                                                           
int selPin = 9;                           // switch                                                        

int vertZero, horzZero;                                                                           
int vertValue, horzValue;                                                                         
const int sensitivity = 200;                                                                      
int mouseClickFlag = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(horzPin, INPUT);                                                                      
  pinMode(vertPin, INPUT);
  pinMode(selPin, INPUT);                                                                         
  digitalWrite(selPin, HIGH);                                                                     
  delay(1000);                                                                                    
  vertZero = analogRead(vertPin);                                                                 
  horzZero = analogRead(horzPin);                                                                

}

void loop()
{
  vertValue = analogRead(vertPin) - vertZero;                                                    
  horzValue = analogRead(horzPin) - horzZero;                                                    

/*
  Serial.print("x ");
  Serial.println(horzValue);
  Serial.print("y ");
  Serial.println(vertValue);
 */
 

                                                                                                  
                                                                                                

  if (vertValue != 0)
    Mouse.move(0, vertValue/sensitivity, 0);                                                    
  if (horzValue != 0)
    Mouse.move((horzValue/sensitivity)*-1, 0, 0);                                           

    
  if ((digitalRead(selPin) == 0) && (!mouseClickFlag))                                        
  {
    mouseClickFlag = 1;
    Mouse.press(MOUSE_LEFT);                                                                 
  }
  else if ((digitalRead(selPin))&&(mouseClickFlag))                                           
  {
    mouseClickFlag = 0;
    Mouse.release(MOUSE_LEFT);                                                                
  }
}

/*
Author:  OrbitX.Space
Discord:  https://discord.gg/cK4Abxxw
*/