// const int pwma=3;
// const int ain1=4;
// const int ain2=5;
// const int pwmb=6;
// const int bin1=7;
// const int bin2=8;
const int s1=A3;

// void wheel(int l,int r)
// {
//     if(l>0)
//     {
//         digitalWrite(ain1,HIGH);
//         digitalWrite(ain2,LOW);
//         analogWrite(pwma,l);
//     }
//     else if(l<0)
//     {
//         digitalWrite(ain1,LOW);
//         digitalWrite(ain2,HIGH);
//         analogWrite(pwma,l*(-1));
//     }
//     else if(l==0)
//     {
//         digitalWrite(ain1,LOW);
//         digitalWrite(ain2,LOW);
//     }
//     if(r>0)
//     {
//         digitalWrite(bin1,HIGH);
//         digitalWrite(bin2,LOW);
//         analogWrite(pwmb,r);
//     }
//     else if(r<0)
//     {
//         digitalWrite(bin1,LOW);
//         digitalWrite(bin2,HIGH);
//         analogWrite(pwmb,r*(-1));
//     }
//     else if(r==0)
//     {
//         digitalWrite(bin1,LOW);
//         digitalWrite(bin2,LOW);
//     }

// }
// void forward(int i)
// //forward(speed)
// {
//     delay(10);
//     digitalWrite(ain1,HIGH);
//     digitalWrite(ain2,LOW);
//     digitalWrite(bin1,HIGH);
//     digitalWrite(bin2,LOW);
//     speed(i);
// }
// void backward(int i)
// {
//     delay(40);
//     digitalWrite(ain1,LOW);
//     digitalWrite(ain2,HIGH);
//     digitalWrite(bin1,LOW);
//     digitalWrite(bin2,HIGH);
//     speed(i);
// }
// void speed(int i)
// {
//     analogWrite(pwma,i);
//     analogWrite(pwmb,i);
// }

// void stop()
// {
//     digitalWrite(ain1,LOW);
//     digitalWrite(ain2,LOW);
//     digitalWrite(bin1,LOW);
//     digitalWrite(bin2,LOW);
// }
void setup()
{
    // pinMode(pwma,OUTPUT); 
    // pinMode(ain1,OUTPUT);
    // pinMode(ain2,OUTPUT);
    // pinMode(pwmb,OUTPUT);
    // pinMode(bin1,OUTPUT);
    // pinMode(bin2,OUTPUT);
    pinMode(s1,INPUT);
    Serial.begin(9600);
}
void loop()
{
    // wheel(-100,100);
    int s1read=(analogRead(s1));//>=600)?0:1;
    Serial.println(s1read);
    delay(100);
}