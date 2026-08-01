void tFree()
{
    blackAmount = 0;
    isLeft = 0;
    isRight = 0;
    downL = 0;
    downR = 0;
}
int isCenter(){
  read();
      return bwRead[6] + bwRead[7];
    }
void run()
{
    tFree();
    int resetI = 1;
    for (uint8_t i = 0; i < 14; i++)
    {
        if (i >= 3 && i <= 10)
        {
            blackAmount += bwRead[i];
            if (i <= 5)
                isLeft += bwRead[i];
            else if (i >= 8)
                isRight += bwRead[i];
        }
        else if (i < 3)
            downL += bwRead[i];
        else if (i > 10)
            downR += bwRead[i];
    }
    
    
    if (blackAmount == 0)
    {
      
        if (checkDownS() == 2)
        {
            tR();
//            delay(turnDelay);
//            Serial.println("downR");
        }
        else if(checkDownS() == 1){tL();}
        else if (checkDownS() == 0)
            lost();
    }
    // else if (blackAmount > 7)
    // {
    //     intersection();
    //     Serial.println("aBlack");
    // }
    //     else if (isLeft == 0 && isRight >1) //&& checkDownS()==0)
    //     {
    ////         tR();
    //         Serial.println("tR");
    //     }
    // else if (isRight == 0 && isLeft != 0)
    // {
    //     tL();
    //     Serial.println("tL");
    // }
    // else if (isCenter == 0 && isLeft != 0 && isRight != 0)
    // {
    //     CurveL();
    //     Serial.println("tL");
    // }
    else
    {
        fLine();
        Serial.println("fline");
    }
    //        resetI=0;
    //    if(resetI!=0) I=0;
}
void fLine()
{
    lineOnLeft=(downL>1 & downR==0)? 1:0;
    lineOnRight=(downR>1 & downL==0)? 1:0;
    calcError();
    calcCorrect();
    mkCorrect();
    
}
void tL()
{
    // aWheel(turnLow, turnHigh);
    aWheel(0, turnHigh);
    delay(backDelay);
    while (isCenter() < 1)
    {
    aWheel(-turnLow, turnHigh);
    }
}
void tR()
{
    aWheel(turnHigh, 0);
    delay(backDelay);
    Serial.println("tr");
    while (isCenter() < 1)
    {
        aWheel(turnHigh, -turnLow);
        int a=isCenter();Serial.println(a);
    }
    Serial.println("finish");
    
}
void CurveL()
{
    wheel(turnLow, turnHigh);
    // delay(80);
    // wheel(-turnLow, turnHigh);
}
void CurveR()
{
    wheel(turnHigh, turnLow);
    // delay(80);
    // wheel(-turnLow, turnHigh);
}
void intersection()
{
    tL();
}

int checkDownS()
{
    if (downL > 0 && downR == 0)
        return 1;
    else if (downR > 0 && downL == 0)
        return 2;
    else if (downL > 0 && downR > 0)
        return 3;
    else
        return 0;
}
void downS(int n)
{
    switch (n)
    {
    case 1:
        tL();
    case 2:
        tR();
    case 3:
        tL();
        
    }
}
