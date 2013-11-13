# ArduinoCPP

A quick, naive C++ wrapper around [FirmataC](https://github.com/jdourlens/FirmataC/).

## Using ArduinoCPP

1. Include ArduinoCPP by adding the following to your project:
    ```cpp
    #include "arduino.h"
    ```

2. Add the directory which contains `arduino.h` to your compiler's include path.
3. Add FirmataC's include directory to your compiler's include path.
4. Make your compiler link with the FirmataC library.

## API Documentation

```cpp
Arduino(std::string port="/dev/ttyACM0");
```

Create an object to control the Arduino attached at a given port.

```cpp
bool Arduino::digitalRead(uint32_t pin);
```

Set a pin to digital input mode, and read its value.  Returns `true` if the pin is high, or `false` if the pin is low.

```cpp
void Arduino::digitalWrite(uint32_t pin, bool value);
```

Set a pin to digital output mode, and write to the pin.  A value of `true` set the pin high, and a value of `false` sets the pin low.

```cpp
void Arduino::pullUp(uint32_t pin, bool value);
```

Set a pin to digital input mode, and enable or disable its pull-up resistor.  A value of `true` enables the pull-up, and a value of `false` disables the pull-up.

```cpp
float Arduino::analogRead(uint32_t pin);
```

Set a pin to analog input mode, and read its value.  Returns a value in the range 0-1.

```cpp
void Arduino::analogWrite(uint32_t pin, float value);
```

Set a pin to PWM output mode, and write to the pin.  A value of 0 sets gives 0% duty cycle, 0.5 gives a 50% duty cycle, and 1 gives a 100% duty cycle.
