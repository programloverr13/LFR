const int s[4]={};
const int sig=;

int readings[14];

void setup()
{
    for(int i=0;i<4;i++)
    {
        pinMode(s[i],OUTPUT);
    }
    pinMode(sig,INPUT);
    Serial.begin(9600);
}
// void binBit(int m, int n)
// {

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
        readings[i]=analogRead(sig);
    }
}
void loop()
{
    read();
    for(int i=0;i<14;i++)
    {
        Serial.print(readings[i]);
        Serial.print("\t");
    }
    Serial.println();
    delay(1000);
}