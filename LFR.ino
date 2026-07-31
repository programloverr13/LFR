const uint8_t s[4] = {2, 3, 11, 12};
const uint8_t sig = A1;
const uint8_t pwma = 5;
const uint8_t ain1 = 8;
const uint8_t ain2 = 7;
const uint8_t pwmb = 6;
const uint8_t bin1 = 9;
const uint8_t bin2 = 10;

const uint8_t sensor_count = 14;
uint16_t reading[14];
uint16_t wThreshold[14]={85, 81, 79, 78, 78, 80, 82, 80, 80, 94, 81, 86, 82, 91};
uint8_t bwRead[14];
uint16_t wTh = 0;
uint16_t bTh = 1023;

const float kp = 15;
const float kd = 10;
float corr = 0;
const uint8_t bSpeed = 60;
const float center = 7.66;
float pErr = 0;
float err = 0;
uint16_t totalRead = 0;
uint32_t wSum = 0;

const uint8_t tspdH = bSpeed+70;
const uint8_t tspdL = 70;
uint16_t startBlack = 400;
uint8_t blackAmount = 0;
uint8_t downL = 0;
uint8_t downR = 0;
uint8_t isLeft = 0;
uint8_t isRight = 0;

void setup()
{
    pinMode(sig, INPUT);
    for (uint8_t i = 0; i < 4; i++)
        pinMode(s[i], OUTPUT);

    pinMode(pwma, OUTPUT);
    pinMode(ain1, OUTPUT);
    pinMode(ain2, OUTPUT);
    pinMode(pwmb, OUTPUT);
    pinMode(bin1, OUTPUT);
    pinMode(bin2, OUTPUT);
    Serial.begin(9600);
}
void loop()
{
    readSensors();
    // calcError();
    // calcCorrect();
    // mkCorrect();
    decide();
    // serialMonitor();

}


// void readSensors();
// void showReading();
// void calcError();
// void calcCorrect();
// void mkCorrect();
