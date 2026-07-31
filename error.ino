void sFree()
{
    totalRead = 0;
    wSum = 0;
}
void calcError()
{
  sFree();
  for (uint8_t i = 3; i <= 10; i++)
  {
    wSum += (i + 1) * reading[i];
    totalRead += reading[i];
  }
  pErr = err;
  if (totalRead > 0)
  {
    err = ((float)wSum / totalRead) - center;
  }
  Serial.print("err  ");
  Serial.println(err);
}

// void calcPos()
//{
//   pos=-1*(center-wSum/totalRead);
// }
