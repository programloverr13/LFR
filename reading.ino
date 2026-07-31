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
        reading[i]=analogRead(sig)-wThreshold[i];
        bwRead[i]=(reading[i]>startBlack)?1:0;
        
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
        Serial.print((reading[i]));
        Serial.print("  ");
    }
    Serial.println();
    // delay(150);
}
void showBlack()
{
    for(uint8_t i=0;i<14;i++)
    {
        Serial.print((bwRead[i]));
        Serial.print("  ");
    }
    Serial.println();
    // delay(150);
}
void serialMonitor()
{
    showReading();
    showBlack();
    // Serial.print(err);
    // Serial.print("\t");
    // Serial.print(corr);
    // Serial.print("\t");
    // Serial.println(calcCorrect());

    // String dec=decide();
    // Serial.println(dec);
    Serial.println(downL);
    Serial.println();
    Serial.println();
    Serial.println();
    Serial.println();
    Serial.println();
}