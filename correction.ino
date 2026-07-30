void calcCorrect()
{
  corr = err * kp;
  int de = err - pErr;
  corr += kd * de;
}

void mkCorrect()
{
  if (corr == 0)
    wheel(bSpeed, bSpeed);
  else
    wheel(bSpeed - corr, bSpeed + corr);
}
