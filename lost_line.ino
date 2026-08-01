void lost() {
  delay(100);
  if (lineOnLeft == 1) {
    tL();
    lineOnLeft = 0;
    // Serial.println("lef");
  } else if (lineOnRight == 1) {
    tR();
    lineOnRight = 0;
    // Serial.println("r");
  }

  else {
    aWheel(turnHigh, 0);
    // Serial.println("tr");
    delay(backDelay);
    int t = millis();
    for (int i = -turnLow; blackAmount == 0 && checkDownS() == 0 && i < turnLow;
         i++) {
      read();
      aWheel(turnHigh, i);
      if ((millis() - t) > 2000) {
        wheel(0, 0);
        break;
      }
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
  // Serial.println("im lost");
  // wheel(0,0);
}
