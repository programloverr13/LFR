const int s[4]={11,12,13,10};
const int sig=A1;
const int pwma=3;
const int ain1=4;
const int ain2=5;
const int pwmb=6;
const int bin1=7;
const int bin2=8;

const int sensor_count=14;
int reading[14];


const int kp=20;
int correction=0;
const int bspeed=150;
const int center=7.5;
int totalRead=0;  
int wSum=0;
float error=0;

//void read(){}
//void showReading(){}
//void calcError(){}
//void calcCorrect(){}
//void mkCorrect(){}
void free()
{
  totalRead=0;  
  wSum=0;
  error=0;
}
void setup()
{
    pinMode(sig,INPUT);
    for(int i=0;i<4;i++) pinMode(s[i],OUTPUT);
    
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
    readSensors();
    showReading();

    calcError();
    calcCorrect();


    Serial.println(correction);
    delay(1000);
    Serial.println();Serial.println();Serial.println();Serial.println();Serial.println();
    free();

//     calcCorrect();
    // mkCorrect();
}
