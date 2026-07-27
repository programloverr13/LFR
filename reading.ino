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
        delay(10);
        reading[i]=analogRead(sig);
    }
}
void showReading()
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