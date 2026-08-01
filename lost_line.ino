void lost() {
  if (lineOnLeft == 1) {
    tL();
    lineOnLeft = 0;
    Serial.println("lef");
  } else if (lineOnRight == 1) {
    tR();
    lineOnRight = 0;
    Serial.println("r");
  }

  else {
    aWheel(turnHigh, 0);
    Serial.println("tr");
    delay(backDelay);
    for (int i = -turnLow; turningOff(8, 9, 10) < 1 && i < 255; i++) {
      aWheel(turnHigh, i);
    }
  }

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
  // wheel(0,0);
}
