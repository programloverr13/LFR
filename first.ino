const int pwma=3;
const int ain1=4;
const int ain2=5;
const int pwmb=6;
const int bin1=7;
const int bin2=8;

void forward()
{
    delay(10);
    digitalWrite(ain1,HIGH);
    digitalWrite(ain2,LOW);
    digitalWrite(bin1,HIGH);
    digitalWrite(bin2,LOW);
    
}
void backward()
{
    delay(40);
    digitalWrite(ain1,LOW);
    digitalWrite(ain2,HIGH);
    digitalWrite(bin1,LOW);
    digitalWrite(bin2,HIGH);
    
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
    digitalWrite(bin1,LOW);
    digitalWrite(bin2,LOW);
    delay(4000);
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
    forward();
    speed(100);
    delay(8000);
    tl180();
    forward();delay(8000);
    // digitalWrite(ain1,LOW);
    // digitalWrite(ain2,LOW);
    // delay(5000);
    // slow_fast();
    // fast_slow();
    // backward();
    //digitalWrite(ain1,LOW);
    //digitalWrite(ain2,LOW);
    // slow_fast();
    // fast_slow();
}