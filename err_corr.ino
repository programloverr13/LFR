void sFree() {
  totalRead = 0;
  wSum = 0;
}
void calcError() {
  sFree();
  for (uint8_t i = 3; i <= 10; i++) {
    wSum += (i + 1) * bwRead[i];
    totalRead += bwRead[i];
  }
  pErr = err;
  if (totalRead > 0) {
    err = ((float)wSum / totalRead) - center;
  }
}
void calcCorrect() {
  de = err - pErr;
  corr = (err * kp);
  corr += (kd * de);

  //  if (abs(err) < 0.1 && isCenter > 0 && isLeft != 0 && isRight != 0 &&
  //  abs(I+err) < maxI)
  //    I += err;
  //  corr += I * ki;
}

void mkCorrect() {
  if (abs(corr) < 0.2)  // tune this
    wheel(bSpeed, bSpeed);
  else
    wheel((int)(bSpeed + corr), (int)(bSpeed - corr));
}
