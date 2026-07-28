void readSensors()
{
    for(int i=0;i<14;i++)
    {
        int b=15-i;
        for(int j=0;j<4;j++)
        {
            digitalWrite(s[j],b%2);b/=2;
        }
//        digitalWrite(s[0],b%2);b/=2;
//        digitalWrite(s[1],b%2);b/=2;
//        digitalWrite(s[2],b%2);b/=2;
//        digitalWrite(s[3],b%2);b/=2;
        delayMicroseconds(50);
        reading[i]=analogRead(sig);
        if(i>=3 && i<=10){
          wSum+=(i+1)*reading[i];
          totalRead+=reading[i];
        }
    }
}
void showReading()
{
    for(int i=0;i<14;i++)
    {
        Serial.print((reading[i]));//<100)?0:1);
        Serial.print("  ");
    }
    Serial.println();
    delay(150);
}
