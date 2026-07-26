const int s[4]={4,5,6,7};
const int sig=A0;
const int sensor_count=14;
int reading[14];

void setup()
{
    for(int i=0;i<4;i++)
    {
        pinMode(s[i],OUTPUT);
    }
    pinMode(sig,INPUT);
    Serial.begin(9600);
}
void read()
{
    for(int i=0;i<14;i++)
    {
        int b=i;
        for(int j=0;j<4;j++)
        {
            digitalWrite(s[j],(b%2==0)?LOW:HIGH);
            b/=2;
        }
        reading[i]=analogRead(sig);
    }
}
void loop()
{
    read();
    for(int i=0;i<14;i++)
    {
        Serial.print(reading[i]);
        Serial.print("\t");
    }
    Serial.println();
    delay(1000);
}