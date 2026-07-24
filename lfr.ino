const int pwma=3;
const int ain1=4;
const int ain2=5;
const int pwmb=6;
const int bin1=7;
const int bin2=8;

void forward(int i)
//forward(speed)
{
    delay(10);
    digitalWrite(ain1,HIGH);
    digitalWrite(ain2,LOW);
    digitalWrite(bin1,HIGH);
    digitalWrite(bin2,LOW);
    speed(i);
}
void backward(int i)
{
    delay(40);
    digitalWrite(ain1,LOW);
    digitalWrite(ain2,HIGH);
    digitalWrite(bin1,LOW);
    digitalWrite(bin2,HIGH);
    speed(i);
}
void speed(int i)
{
    analogWrite(pwma,i);
    analogWrite(pwmb,i);
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
void stop()
{
    digitalWrite(ain1,LOW);
    digitalWrite(ain2,LOW);
    digitalWrite(bin1,LOW);
    digitalWrite(bin2,LOW);
}
void tl180()
{
    digitalWrite(ain1,HIGH);
    digitalWrite(ain2,LOW);
    analogWrite(pwma,200);
    digitalWrite(bin1,HIGH);
    digitalWrite(bin2,HIGH);
    delay(2000);
}
void setup()
{
    pinMode(pwma,OUTPUT); 
    pinMode(ain1,OUTPUT);
    pinMode(ain2,OUTPUT);
    pinMode(pwmb,OUTPUT);
    pinMode(bin1,OUTPUT);
    pinMode(bin2,OUTPUT);
    Serial.begin(9600);
}
void loop()
{
    forward(100);
    delay(5000);
    tl180();
    forward(100);
    delay(5000);
}