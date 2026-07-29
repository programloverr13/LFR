const uint8_t s[4] = {11, 12, 13, 10};
const uint8_t sig = A1;
const uint8_t pwma = 3;
const uint8_t ain1 = 4;
const uint8_t ain2 = 5;
const uint8_t pwmb = 6;
const uint8_t bin1 = 8;
const uint8_t bin2 = 7;

const uint8_t sensor_count = 14;
uint16_t reading[14];

const uint8_t kp = 40;
const uint8_t kd = 40;
float correction = 0;
const uint8_t bSpeed = 0;
const float center = 7.3f;
uint16_t totalRead = 0;
uint16_t wSum = 0;
float error = 0;

// void read(){}
// void showReading(){}
// void calcError(){}
// void calcCorrect(){}
// void mkCorrect(){}
void free()
{
    totalRead = 0;
    wSum = 0;
    error = 0;
}
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
    // digitalWrite(ain1,HIGH);
    // digitalWrite(ain2,LOW);

    // delay(50);
    readSensors();
    showReading();
    calcError();
    calcCorrect();
    mkCorrect();
    free();

    //    Serial.println(error);
    //    Serial.println(correction);
    //    delay(1000);
    //    Serial.println();Serial.println();Serial.println();Serial.println();Serial.println();
    //    free();

    //     calcCorrect();
    // mkCorrect();
}
