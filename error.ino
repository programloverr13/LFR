void calcError()
{
  //  for(int i=0;i<sensor_count;i++){
  //
  //  }
  if (totalRead > 0)
  {
    pError=error;                                           
    error = wSum / totalRead - center;
  }
}
// void calcPos()
//{
//   pos=-1*(center-wSum/totalRead);
// }
