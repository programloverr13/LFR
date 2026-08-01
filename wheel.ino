void wheel(int l,int r)
{
   if(l>0) dwL(1,0);
   else  {dwL(0,0);l=0;}
   analogWrite(pwma,constrain(abs(l),0,255));
   if(r>0) dwR(1,0);
   else {dwR(0,0);r=0;}
   analogWrite(pwmb,constrain(abs(r),0,255));
}
void aWheel(int l,int r)
{
   if(l>0) dwL(1,0);
   else if(l<0) dwL(0,1);
   else dwL(0,0);
   analogWrite(pwma,constrain(abs(l),0,255));
   if(r>0) dwR(1,0);
   else if(r<0) dwR(0,1);
   else dwR(0,0);
   analogWrite(pwmb,constrain(abs(r),0,255));
}
void dwL(uint8_t a1,uint8_t a2)
{
    digitalWrite(ain1,a1);
    digitalWrite(ain2,a2);
}
void dwR(uint8_t b1,uint8_t b2)
{
    digitalWrite(bin1,b1);
    digitalWrite(bin2,b2);
}