const int center=7;
int totalRead=0;  
int wSum=0;
for(int i=0;i<sensor_count;i++){
    wSum+=(i+1)*reading[i];
    totalRead+=reading[i];
}
int error=-1*(center-wSum/totalRead);