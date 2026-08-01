void read() {
  for (uint8_t i = 0; i < 14; i++) {
    uint8_t b = 15 - i;
    for (uint8_t j = 0; j < 4; j++) {
      digitalWrite(s[j], b % 2);
      b /= 2;
    }
    delayMicroseconds(50);
    reading[i] = analogRead(sig);
    bwRead[i] = (reading[i] > startBlack) ? 1 : 0;

    // if(i>=3 && i<=10){
    //   wSum+=(i+1)*reading[i];
    //   totalRead+=reading[i];
    // }
  }
}
void showReading() {
  for (uint8_t i = 0; i < 14; i++) {
    Serial.print((reading[i]));
    Serial.print("  ");
  }
  Serial.println();
  // delay(150);
}
void showBW() {
  for (uint8_t i = 0; i < 14; i++) {
    Serial.print((bwRead[i]));
    Serial.print("  ");
  }
  Serial.println();
  // delay(150);
}
void run_ShowDetails() {
  //   int n = run();
  showReading();
  showBW();
  Serial.print("State: ");
  switch (run()) {
    case 0:
      Serial.println("fline");
      Serial.print("err: ");
      Serial.println(err);
      Serial.print("PD corr: ");
      Serial.println(corr);
      Serial.print("de: ");
      Serial.println(de);
      break;
    case 1:
      Serial.println("t-shape");
      break;
    case 2:
      Serial.println("plus-shape");
      break;
    case 3:
      Serial.println("frontBlack");
      break;
    case 4:
      Serial.println("tL");
      break;
    case 5:
      Serial.println("tR");
      break;
    case 6:
      Serial.println("14-Black_STOP");
      break;

    default:
      break;
  }
  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println();
}
