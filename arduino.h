#ifndef ARDUINO_H
#define ARDUINO_H

extern "C" {
#include "firmata.h"
}

class Arduino {
public:
    Arduino(std::string port="/dev/ttyACM0") {
        firmata = firmata_new(&port[0]);
        while (!firmata->isReady) {
            tick();
        }
    }

    float analogRead(uint32_t pin) {
        if (!(firmata->pins[pin].mode == MODE_ANALOG)) {
            firmata_pinMode(firmata, pin, MODE_ANALOG);
        }

        return firmata->pins[pin].value / 1024.f;
    }

    void analogWrite(uint32_t pin, float value) {
        if (!(firmata->pins[pin].mode == MODE_PWM)) {
            firmata_pinMode(firmata, pin, MODE_PWM);
        }
        firmata_analogWrite(firmata, pin, value * 255);
    }

    bool digitalRead(uint32_t pin) {
        if (!(firmata->pins[pin].mode == MODE_INPUT)) {
            firmata_pinMode(firmata, pin, MODE_INPUT);
        }
        return firmata->pins[pin].value == HIGH;
    }

    void digitalWrite(uint32_t pin, bool value) {
        if (!(firmata->pins[pin].mode == MODE_OUTPUT)) {
            firmata_pinMode(firmata, pin, MODE_OUTPUT);
        }
        firmata_digitalWrite(firmata, pin, value ? HIGH : LOW);
    }

    void pullUp(uint32_t pin, bool value) {
        if (!(firmata->pins[pin].mode == MODE_INPUT)) {
            firmata_pinMode(firmata, pin, MODE_INPUT);
        }
        firmata_digitalWrite(firmata, pin, value ? HIGH : LOW);
    }

    void tick() {
        firmata_pull(firmata);
    }

private:
    t_firmata *firmata;
};

#endif

