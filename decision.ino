void tFree()
{
    isBlack = 0;
    isLeft = 0;
    isRight = 0;
}
String isTurn()
{
    tFree();
    for (uint8_t i = 3; i <= 10; i++)
    {
        isBlack += bw[i];
        if (i <= 5)
            isLeft += bw[i];
        if (i >= 8)
            isRight += bw[i];
    }
    if (isBlack < 1)
    {
        lost();
        return "aWhite";
    }
    // else if (isBlack > 7)
    // {
    //     intersection();
    //     return "aBlack";
    // }
    // else if (isLeft == 0 && isRight != 0)
    // {
    //     tR();
    //     return "tR";
    // }
    // else if (isRight == 0 && isLeft != 0)
    // {
    //     tL();
    //     return "tL";
    // }
    else
    {
        fLine();
        return "fLine";
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
    wheel(tspdL, tspdH);
}
void tR()
{
    wheel(tspdH, tspdL);
}
void intersection()
{
    tL();
}
