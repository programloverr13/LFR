void calcCorrect()
{
  float de = err - pErr;
  corr = (err * kp);
  Serial.print("P corr  ");
  Serial.println(corr);
  
  corr += (kd * de);
  Serial.print("PD corr  ");
  Serial.println(corr);

  Serial.print("de  ");
  Serial.println(de);
}

void mkCorrect()
{
  if (corr == 0)
    wheel(bSpeed, bSpeed);
    else
      wheel(bSpeed + corr, bSpeed - corr);


    // else if (corr < 0)
    //   wheel(100, 0);
    // else if (corr > 0)
    //   wheel(0, 100);
  }
