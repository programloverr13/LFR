void tFree()
{
    blackAmount = 0;
    isLeft = 0;
    isRight = 0;
    isCenter = 0;
    downL = 0;
    downR = 0;
}
void decide()
{
    tFree(); int resetI=1;
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
    isCenter = blackAmount + bwRead[6] + bwRead[7];
//    if (blackAmount == 0)
//    {
//        if (downS() == 0)
//            lost();
//        Serial.println("aWhite");
//    }
    // else if (blackAmount > 7)
    // {
    //     intersection();
    //     Serial.println("aBlack");
    // }
    // else if (isLeft == 0 && isRight != 0)
    // {
    //     tR();
    //     Serial.println("tR");
    // }
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
//    else
        fLine(); resetI=0;
    
    if(resetI!=0) I=0;
}
void fLine()
{
    calcError();
    calcCorrect();
    mkCorrect();
}
void tL()
{
    // aWheel(turnLow, turnHigh);
    aWheel(0, turnHigh);
    delay(backDelay);
    aWheel(-turnLow, turnHigh);
}
void tR()
{
    aWheel(turnHigh, 0);
    delay(backDelay);
    aWheel(turnHigh, -turnLow);
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
void lost()
{
    wheel(0, 0);
    // tL();
}
int checkDownS()
{
    if (downL > 0 && downR<1)
        return 1;
    else if (downR > 0 && downL<1)
        return 2;
    else if (downL > 0 && downR > 0)
        return 3;
    else
        return 0;
}
void downS(int n)
{
  switch(n){
    case 1:
        tR();
    case 2:
        tL();
    case 3:
        tL();
  }
}
