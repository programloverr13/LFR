void dwL(int a1,int a2)
{
    digitalWrite(ain1,a1);
    digitalWrite(ain2,a2);
}
void dwR(int b1,int b2)
{
    digitalWrite(bin1,b1);
    digitalWrite(bin2,b2);
}
void wheel(int l,int r)
{
    if(l>0)
    {
        dwL(1,0);
        analogWrite(pwma,l);
    }
    else if(l<0)
    {
        dwL(0,1);
        analogWrite(pwma,l*(-1));
    }
    else if(l==0)
    {
        dwL(0,0);
    }
    if(r>0)
    {
        dwR(1,0);
        analogWrite(pwmb,r);
    }
    else if(r<0)
    {
        dwR(0,1);
        analogWrite(pwmb,r*(-1));
    }
    else if(r==0)
    {
        dwR(0,0);
    }

}

void forward(int i)
{
    delay(10);
    digitalWrite(ain1,HIGH);
    digitalWrite(ain2,LOW);
    digitalWrite(bin1,HIGH);
    digitalWrite(bin2,LOW);
    speed(i);
}
void backward(int i)
{
    delay(40);
    digitalWrite(ain1,LOW);
    digitalWrite(ain2,HIGH);
    digitalWrite(bin1,LOW);
    digitalWrite(bin2,HIGH);
    speed(i);
}
void speed(int i)
{
    analogWrite(pwma,i);
    analogWrite(pwmb,i);
}

void stop()
{
    dwL(0,0);
    dwR(0,0);
}