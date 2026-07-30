void tFree()
{
    blackAmount = 0;
    isLeft = 0;
    isRight = 0;
}
void decide()
{
    tFree();
    for (uint8_t i = 3; i <= 10; i++)
    {
        blackAmount += bwRead[i];
        if (i <= 5)
            isLeft += bwRead[i];
        if (i >= 8)
            isRight += bwRead[i];
    }
    if (blackAmount ==0)
    {
        lost();
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
// void turn(char st)
// {
//     switch(st)
//     {}
// }
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
