void calcCorrect()
{
  correction=error*kp;
}

void mkCorrect()
{
  if(bspeed>correction) wheel(bspeed-correction,bspeed+correction);



  // if(correction==0) wheel(bSpeed,bSpeed);
  // else if(correction<0) wheel(bspeed-abs(correction),bspeed+abs(correction));
  // else if(correction>0) wheel(bspeed+abs(correction),bspeed-abs(correction));
  
}