#include<Arduino.h>

const int pwma=;
const int an1=;
const int an2=;
const int pwmb=;
const int bn1=;
const int bn2=;
void setup()
{
    pinMode(pwma,OUTPUT); 
    pinMode(an1,OUTPUT);
    pinMode(an2,OUTPUT);
    pinMode(pwmb,OUTPUT);
    pinMode(bn1,OUTPUT);
    pinMode(bn2,OUTPUT);
}
void loop()
{
    //forward speed slow to fast
    digitalWrite(an1,HIGH);
    digitalWrite(an2,LOW);
    digitalWrite(bn1,HIGH);
    digitalWrite(bn2,LOW);
    for(int i=0;i<256;i++){
        analogWrite(pwma,i);
        analogWrite(pwmb,i);
    }
    for(int i=255;i>=0;i--){
        analogWrite(pwma,i);
        analogWrite(pwmb,i);
    }

    //backward speed slow to fast
    digitalWrite(an1,LOW);
    digitalWrite(an2,HIGH);
    digitalWrite(bn1,LOW);
    digitalWrite(bn2,HIGH);
    for(int i=0;i<256;i++){
        analogWrite(pwma,i);
        analogWrite(pwmb,i);
    }
    for(int i=255;i>=0;i--){
        analogWrite(pwma,i);
        analogWrite(pwmb,i);
    }
}