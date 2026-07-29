void calcCorrect()
{
  correction=error*kp;
  int de=error-pError;
  (abs(de)>1)?
  correction-=kd*abs(de)
}

void mkCorrect()
{
//  if(bspeed>correction) {
//    wheel(bSpeed-correction,bSpeed+correction);
//    delay(10);
//  }



   if(correction==0) wheel(bSpeed,bSpeed);
   else if(correction<0) wheel(bSpeed-abs(correction),bSpeed+abs(correction));
   else if(correction>0) wheel(bSpeed+abs(correction),bSpeed-abs(correction));
  
}
