#ifndef _bluetooth_H    
#define _bluetooth_H  
#include "steppermotor_init.h"

extern int myStepper1ShouldRun;
char value;
float vel = 200;
float v = 0;
float w = 0;
const int pump = 51;
float vel_max = 255;
float vel_max_side = 1500;
int dutycycle = 0;
int motor_dir;
enum
{
  MOTOR_FORWARD=0 , MOTOR_BACKWARD, MOTOR_LEFT, MOTOR_RIGHT
};


void read_bluetooth()
{
  if(Serial.available())
  {   
    value = Serial.read();
    //Serial.print(value);
    if(value == 'Z' )
    {
      digitalWrite(pump, HIGH);
    }

    if(value == 'X' )
    {
      digitalWrite(pump, LOW);
    }
    
    if(value == 'W' )
    {
      v = vel;
      w = 0; 
      motor_dir = MOTOR_FORWARD;
    }
    
    else if(value == 'S' )
    {
      v = -vel;
      w = 0;
      motor_dir = MOTOR_BACKWARD;
    }
    
    else if(value == 'D' )
    {
      v = vel;
      w = 0;
      motor_dir = MOTOR_RIGHT;
    }
    
    else if(value == 'A' )
    {
      v = vel;
      w = 0;
      motor_dir = MOTOR_LEFT;
    }
    
    else if(value == 'T' )                     //Stop_robot
    {
      v = 0;
      w = 0;
      
    }

    else if (value == '+' ){
      Serial.print( value );
      delay( 200 );
      while( Serial.available() ){
        value = Serial.read();
        Serial.print( value );
      }
    }
    
  /*  else if ( value == 'I' )                    //ARM UP
    {
      enable_yaxis_stepper();
    } 
    
    else if ( value == 'K' )                    //ARM STOP
    {
      steps = 0;
      TCCR1A = 0;
      TCCR1B = 0;
      digitalWrite(en_y, HIGH);
    }
    
    else if(value == 'J')                       //ARM LEFT
     { 
      steps = 0;
      digitalWrite(dirx, HIGH);
      enable_xaxis_stepper();
      proxy_to_read = PROXY_LEFT;
     }
     
      else if(value == 'L')                    //ARM RIGHT
     {
      digitalWrite(dirx, LOW);
      enable_xaxis_stepper();
      proxy_to_read = PROXY_RIGHT;
  
     }*/
  }
}
#endif // _bluetooth_H   
