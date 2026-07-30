void calcError()
{
  //  for(int i=0;i<sensor_count;i++){
  //
  //  }
  pErr=err;                                           
  if (totalRead > 0)
  {
    err = ((float)wSum / totalRead) - center;
  }
}
// void calcPos()
//{
//   pos=-1*(center-wSum/totalRead);
// }
