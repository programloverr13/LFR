void tFree()
{
    blackAmount = 0;
    isLeft = 0;
    isRight = 0;
    downL=0;
    downR=0;
}
void decide()
{
    tFree();
    for (uint8_t i = 0; i < 14; i++)
    {
        if (i >= 3 && i <= 10)
        {
            blackAmount += bwRead[i];
            if (i <= 5)
                isLeft += bwRead[i];
            if (i >= 8)
                isRight += bwRead[i];
        }
        else if (i < 3)
            downL += bwRead[i];
        else if (i > 10)
            downR += bwRead[i];
    }
    if (blackAmount == 0)
    {
        if(downS()==0) lost();
        Serial.println("aWhite");
    }
    else if (blackAmount > 7)
    {
        intersection();
        Serial.println("aBlack");
    }
    else if (isLeft == 0 && isRight != 0)
    {
        tR();
        Serial.println("tR");
    }
    else if (isRight == 0 && isLeft != 0)
    {
        tL();
        Serial.println("tL");
    }
    else
    {
        fLine();
        Serial.println("fLine");
    }
}
void fLine()
{
    calcError();
    calcCorrect();
    mkCorrect();
}
void tL()
{
    // wheel(tspdL, tspdH);
    wheel(0, tspdH);
    delay(80);
    wheel(-tspdL, tspdH);
}
void tR()
{
    wheel(tspdH, 0);
    delay(80);
    wheel(tspdH, -tspdL);
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
int downS()
{
    if(downL>0) tR();
        else if(downR>0) tL();
        else return 0;
    return 1;
}