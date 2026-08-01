int run() {
  tFree();
  int resetI = 1;
  for (uint8_t i = 0; i < 14; i++) {
    if (i >= 3 && i <= 10) {
      blackAmount += bwRead[i];
      if (i <= 5)
        isLeft += bwRead[i];
      else if (i >= 8)
        isRight += bwRead[i];
    } else if (i < 3)
      downL += bwRead[i];
    else if (i > 10)
      downR += bwRead[i];
  }

  // t-shape
  if (blackAmount < 2 && checkDownS() == 3) {
    if (MODE == 0)
      tL();
    else if (MODE == 1)
      tR();
    return 1;
  }
  // plus shape
  else if (blackAmount >= 6) {
    if (FRONT == 0) {
      if (MODE == 0)
        tL();
      else if (MODE == 1)
        tR();
    }
    return 2;
  } else if (blackAmount == 0) {
    switch (checkDownS()) {
      case 1:
        tL();
        break;
      case 2:
        tR();
        break;
      case 0:
        lost();
        break;
    }
    return 3;
  }

  else if (isRight == 0 && isLeft >= 2 && checkDownS() == 1 && isCenter() > 0 &&
           (MODE == 0 || LEFT_RIGHT == 1)) {
    tL();
    return 4;
  } else if (isLeft == 0 && isRight >= 2 && checkDownS() == 2 &&
             isCenter() > 0 && (MODE == 1 || LEFT_RIGHT == 1)) {
    tR();
    return 5;
  } else if (blackAmount == 8 && downL == 3 && downR == 3) {
    wheel(0, 0);
    return 6;
  } else {
    fLine();
    return 0;
  }
  //        resetI=0;
  //    if(resetI!=0) I=0;
}
void fLine() {
  if (downL > 1 & downR == 0) {
    lineOnLeft = 1;
    lineOnRight = 0;
  }
  if (downR > 1 & downL == 0) {
    lineOnRight = 1;
    lineOnLeft = 0;
  }
  calcError();
  calcCorrect();
  mkCorrect();
}
void tL() {
  Serial.println("tl");
  aWheel(0, turnHigh);
  delay(backDelay);
  while (turningOff(3, 4, 5) < 1) {
    aWheel(-turnLow, turnHigh);
  }
}
void tR() {
  Serial.println("tr");
  aWheel(turnHigh, 0);
  delay(backDelay);
  while (turningOff(8, 9, 10) < 1) {
    aWheel(turnHigh, -turnLow);
  }
}



int checkDownS() {
  if (downL > 0 && downR == 0)
    return 1;
  else if (downR > 0 && downL == 0)
    return 2;
  else if (downL > 0 && downR > 0)
    return 3;
  else
    return 0;
}
