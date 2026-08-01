const uint8_t s[4] = {10, 3, 11, 12};
const uint8_t sig = A3;
const uint8_t pwma = 5;
const uint8_t ain1 = 8;
const uint8_t ain2 = 7;
const uint8_t pwmb = 6;
const uint8_t bin1 = 4;
const uint8_t bin2 = 9;
// Left 0
// right 1
uint8_t MODE = 0;
uint8_t FRONT = 1;
uint8_t LEFT_RIGHT = 0;
const uint8_t sensor_count = 14;
int reading[14];
// uint16_t wThreshold[14] = {85, 81, 79, 78, 78, 80, 82, 80, 80, 94, 81, 86,
// 82, 91};
uint8_t bwRead[14];
// uint16_t wTh = 0;
// uint16_t bTh = 1023;

const float kp = 20;
const float kd = 5;
const float ki = 0;
float corr = 0;
const uint8_t bSpeed = 80;
const float center = 7.5;
float pErr = 0;
float err = 0;
float de = 0;
float minErr = 0.1;
float I = 0;
float maxI = 4;
uint16_t totalRead = 0;
uint32_t wSum = 0;

const uint8_t turnHigh = bSpeed + 40;
const uint8_t turnLow = bSpeed + 40;
uint16_t startBlack = 400;
uint8_t blackAmount = 0;
uint8_t downL = 0;
uint8_t downR = 0;
uint8_t isLeft = 0;
uint8_t isRight = 0;
uint8_t lineOnLeft = 0;
uint8_t lineOnRight = 0;
int backDelay = 100;
int turnDelay = 200;
void setup() {
  pinMode(sig, INPUT);
  for (uint8_t i = 0; i < 4; i++) pinMode(s[i], OUTPUT);

  pinMode(pwma, OUTPUT);
  pinMode(ain1, OUTPUT);
  pinMode(ain2, OUTPUT);
  pinMode(pwmb, OUTPUT);
  pinMode(bin1, OUTPUT);
  pinMode(bin2, OUTPUT);
  Serial.begin(9600);
  delay(3000);
}
void loop() {
//  wheel(0,150);
read();
//showBW();
run();
}
