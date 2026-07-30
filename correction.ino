void calcCorrect()
{
  corr = err * kp;
  int de = err - pErr;
  corr += kd * de;
  // if(abs(de)>0) wheel(bSpeed+kd*de,bSpeed-kd*de);
  // else if(de<0 && abs(err)<2) wheel(bSpeed-kd*de,bSpeed-kd*de);

  // wheel(bSpeed-corr,bSpeed+corr);
}

void mkCorrect()
{
  //  if(bspeed>corr) {
  if (corr == 0)
    wheel(bSpeed, bSpeed);
  else
    wheel(bSpeed - corr, bSpeed + corr);
  //    delay(10);
  //  }

  // if (corr == 0) wheel(bSpeed, bSpeed);
  //  else if(corr<0) wheel(bSpeed-abs(corr),bSpeed+abs(corr));
  //  else if(corr>0) wheel(bSpeed+abs(corr),bSpeed-abs(corr));
}
