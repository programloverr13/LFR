#include<Arduino.h>

const int pwma=;
const int ain1=;
const int ain2=;
const int pwmb=;
const int bin1=;
const int bin2=;

void forward()
{
    digitalWrite(ain1,HIGH);
    digitalWrite(ain2,LOW);
    digitalWrite(bin1,HIGH);
    digitalWrite(bin2,LOW);
    
}
void backward()
{
    digitalWrite(ain1,LOW);
    digitalWrite(ain2,HIGH);
    digitalWrite(bin1,LOW);
    digitalWrite(bin2,HIGH);
    
}
void slow_fast()
{
    delay(400);
    for(int i=0;i<256;i++){
        analogWrite(pwma,i);
        analogWrite(pwmb,i);
        delay(10);
    }
}
void fast_slow()
{
    delay(400);
    for(int i=255;i>=0;i--){
        analogWrite(pwma,i);
        analogWrite(pwmb,i);
        delay(10);
    }
}
void setup()
{
    pinMode(pwma,OUTPUT); 
    pinMode(ain1,OUTPUT);
    pinMode(ain2,OUTPUT);
    pinMode(pwmb,OUTPUT);
    pinMode(bin1,OUTPUT);
    pinMode(bin2,OUTPUT);
}
void loop()
{
    forward();
    slow_fast();
    fast_slow();
    backward();
    slow_fast();
    fast_slow();
}