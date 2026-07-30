void readSensors()
{
    for(uint8_t i=0;i<14;i++)
    {
        uint8_t b=15-i;
        for(uint8_t j=0;j<4;j++)
        {
            digitalWrite(s[j],b%2);b/=2;
        }
        delayMicroseconds(50);
        reading[i]=analogRead(sig);
        bw[i]=(analogRead(sig)>100)?1:0;
        
        // if(i>=3 && i<=10){
        //   wSum+=(i+1)*reading[i];
        //   totalRead+=reading[i];
        // }
    }
}
void threshold()
{
    
}
void showReading()
{
    for(uint8_t i=0;i<14;i++)
    {
        Serial.print((reading[i]));//<100)?0:1);
        Serial.print("  ");
    }
    Serial.println();
    delay(150);
}
