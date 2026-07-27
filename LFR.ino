const int s[4]={4,5,6,7};
const int sig=A0;
const int sensor_count=14;
int reading[14];

const int pwma=3;
const int ain1=4;
const int ain2=5;
const int pwmb=6;
const int bin1=7;
const int bin2=8;

void setup()
{
    for(int i=0;i<4;i++)
    {
        pinMode(s[i],OUTPUT);
    }
    pinMode(sig,INPUT);
    
    pinMode(pwma,OUTPUT); 
    pinMode(ain1,OUTPUT);
    pinMode(ain2,OUTPUT);
    pinMode(pwmb,OUTPUT);
    pinMode(bin1,OUTPUT);
    pinMode(bin2,OUTPUT);
    pinMode(s1,INPUT);
}
void loop()
{
    wheel(-100,100);
    delay(100);
}