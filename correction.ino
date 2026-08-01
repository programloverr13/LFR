void calcCorrect() {
  de = err - pErr;
  corr = (err * kp);

  corr += (kd * de);

  //  if (abs(err) < 0.1 && isCenter > 0 && isLeft != 0 && isRight != 0 &&
  //  abs(I+err) < maxI)
  //    I += err;
  //
  //  corr += I * ki;
}

void mkCorrect() {
  //  if (abs(corr) < 0.1 && downS() == 0)
  //    ;
  //  else
  if (abs(corr) < 0.2)  // tune this
    wheel(bSpeed, bSpeed);
  else
    wheel(bSpeed + corr, bSpeed - corr);

  // else if (corr < 0)
  //   wheel(100, 0);
  // else if (corr > 0)
  //   wheel(0, 100);
}
