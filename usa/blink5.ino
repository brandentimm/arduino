#include <Arduino.h>

const int pinRed = 5;
const int pinGreen = 6;
const int pinBlue = 9;

const int PWM_MIN = 10;
const int PWM_MAX = 128;

void rampPWM(int pin, int min, int max, int timeDeltaMS);
void cycleRGB(int red, int green, int blue, int min, int max, int timeDeltaMS);

void setup() {
    pinMode(pinRed, OUTPUT);
    pinMode(pinGreen, OUTPUT);
    pinMode(pinBlue, OUTPUT);
}

void loop() {
    cycleRGB(pinRed, pinGreen, pinBlue, 10, 128, 5000);
}

void rampPWM(int pin, int min, int max, int timeDeltaMS) {
    int sleep = timeDeltaMS / (max - min) / 2;

    for (int i = min; i < max; i++) {
        analogWrite(pin, i);
        delay(sleep);
    }

    for (int i = max; i > min; i--) {
        analogWrite(pin, i);
        delay(sleep);
    }
}

void cycleRGB(int red, int green, int blue, int min, int max, int timeDeltaMS) {
    int colorSlice = timeDeltaMS / 3;
    rampPWM(red, min, max, colorSlice);
    rampPWM(green, min, max, colorSlice);
    rampPWM(blue, min, max, colorSlice);
}
