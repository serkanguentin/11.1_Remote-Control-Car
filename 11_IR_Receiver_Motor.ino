#include <Arduino.h>
#include "PinDefinitionsAndMore.h"
#include <IRremote.hpp>


int enA=9;
int in1=8;
int in2=7; 
int enB=3; 
int in3=4; 
int in4=5;

void setup() {

    
    Serial.begin(115200);
    IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);

    pinMode(enA, OUTPUT);   
    pinMode(in1, OUTPUT);   
    pinMode(in2, OUTPUT);    
  
    pinMode(enB, OUTPUT);   
    pinMode(in3, OUTPUT);   
    pinMode(in4,OUTPUT);
}

void loop() {
   analogWrite(enA ,255);
   analogWrite(enB ,255);

   if (IrReceiver.decode()) {
       if (IrReceiver.decodedIRData.protocol != UNKNOWN) {
        Serial.println(IrReceiver.decodedIRData.command);
           switch(IrReceiver.decodedIRData.command) {
                
                case 8 ://4
                  forward();
                  break ;

               case 28: //5
                  stop();
                     break ;

              case 90 ://6
                 back();
                   
                   break;
                   
               case 66://7
                  right();
                   
                   break;
               case 82://8
                  left();
                
                   break;
               
                default:
                  break;
            }
        }
        IrReceiver.resume();
      }  
}


void forward(){
    
  digitalWrite (in4 , LOW ) ;
  digitalWrite (in3,HIGH ) ;  
  digitalWrite(in1,HIGH);  
  digitalWrite(in2 ,LOW ); 
  Serial.println("forward ") ;  
  delay(50) ;
}

void stop(){
    
  digitalWrite (in4,LOW ); 
  digitalWrite (in3 , LOW ); 
  digitalWrite(in1 ,LOW );
  digitalWrite(in2 ,LOW );
  Serial.println ("stop"); 
  delay(50 ) ;
}

void back(){
  digitalWrite (in3 , LOW ) ;
  digitalWrite (in4,HIGH ) ;  
  digitalWrite(in2,HIGH);  
  digitalWrite(in1 ,LOW ); 
  Serial.println("back ");
  delay(10);
}

void right(){
  digitalWrite (in4 , LOW ) ;
  digitalWrite (in3,HIGH ) ;  
  digitalWrite(in2,HIGH);  
  digitalWrite(in1 ,LOW );   
  Serial.println(" right ");
  delay(10);
}
void left(){
    
  digitalWrite (in3 , LOW ) ;
  digitalWrite (in4,HIGH ) ;  
  digitalWrite(in1,HIGH);  
  digitalWrite(in2 ,LOW );   
  Serial.println(" left ");
  delay(10);
}

