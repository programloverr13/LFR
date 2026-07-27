void calcError()
{
  for(int i=0;i<sensor_count;i++){
    wSum+=(i+1)*reading[i];
    totalRead+=reading[i];
  }
  error=-1*(center-wSum/totalRead);
}
