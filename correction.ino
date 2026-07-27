const int kp=;
int correction=error*kp;
const int bSpeed=;






void mkCorrect()
{
  if(correction==0) wheel(bSpeed,bSpeed);
  else if(correction<0) wheel(bSpeed-abs(correction),bSpeed+abs(correction));
  else if(correction>0) wheel(bSpeed+abs(correction),bSpeed-abs(correction));
  
}