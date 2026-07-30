int isTrun()
{
    for (uint8_t i = 3; i <= 10; i++)
    {
        isBlack += bw[i];
        if(i<=5) isLeft += bw[i];
        if(i>=8) isRight += bw[i];
    }
    if (isBlack == 0)
        lost();
    else if (isBlack >7)
        intersect();
    else if (isLeft == 0)
        tR();
    else if (isRight == 0)
        tL();
    else
        return 0;
    return 1;
}
void stLine()
{
    readSensors();
    calcError();
    calcCorrect();
    mkCorrect();
}
void tL()
{
    wheel(tspdL,tspdH);
}
void tR()
{
    wheel(tspdH,tspdL);
}
void intersection()
{
    tL();
}