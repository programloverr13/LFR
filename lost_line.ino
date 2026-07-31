void lost()
{
    if (lineOnLeft==1) {tL();Serial.println("lef");}
    else if (lineOnRight==1) {tR();Serial.println("lef");}
    else wheel(0,0);
//    delay(backDelay);
//    aWheel(-bSpeed, -bSpeed);
//    while(1)
//    {
//      if (checkDownS() == 2)
//        {
//            tR();break;
////            delay(turnDelay);
////            Serial.println("downR");
//        }
//        else if(checkDownS() == 1){tL();break;}
//    }
    
    // tL();
    Serial.println("im lost");
}