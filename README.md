# Arduino-PrintStream

A simple library, that adds `std::cout`-like support for the Arduino (using the `<<`-operator).

## Example usage

```cpp
#include <PrintStream.h>
void setup() {
  Serial.begin(115200);
  Serial << "Hello, World!" << endl;

  Serial << F("Counting to 0xf in hexadecimal: ")
         << hex << noleadingzeros << showbase;
  for (int i = 0; i < 0x10; i++)
    Serial << i << ' ';
  Serial << dec << endl;

  float voltage = analogRead(A0) * 5 / 1024.0;
  Serial << F("The voltage on analog pin A0 is ") << setprecision(3) << voltage << F(" V.") << endl;
}

void loop() { }
```

## Installation

Download the library as a ZIP file, and import it into the Arduino IDE as explained [here](https://www.arduino.cc/en/guide/libraries#toc4).
