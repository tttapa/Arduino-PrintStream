#include <PrintStream.h>

void setup() {
  Serial.begin(115200);
  while(!Serial);

  /* Strings */
  Serial << "Strings" << endl
  << "This is a normal null-terminated char array" << endl 
  << String("This is a String") << endl
  << F("And this is a PROGMEM string")<< endl << endl;

  /* Characters */
  Serial << "Characters" << endl
  << 'a' << 'b' << 'c' << '-' << '1' << '2' << '3' << endl << endl;

  /* Integers */
  Serial << "Integers" << endl
  << (int8_t) 0x80 << endl
  << (uint8_t) 0xFF << endl
  << (int) 0x8000 << endl
  << (unsigned int) 0xFFFF << endl
  << (long) 0x80000000 << endl
  << (unsigned long) 0xFFFFFFFF << endl << endl;

  /* Hexadecimal */
  Serial << "Hexadecimal" << endl
  << hex 
  << (int8_t) 0x80 << endl
  << (uint8_t) 0xFF << endl
  << (int) 0x8000 << endl
  << (unsigned int) 0xFFFF << endl
  << (long) 0x80000000 << endl
  << (unsigned long) 0xFFFFFFFF << endl << endl;

  /* Case */
  Serial << "Case" << endl
  << uppercase
  << (uint8_t) 0xFF << endl
  << nouppercase
  << (uint8_t) 0xFF << endl << endl;

  /* Show base */
  Serial << "Show base" << endl
  << showbase
  << (uint8_t) 0xFF << endl
  << noshowbase
  << (uint8_t) 0xFF << endl << endl;

  /* Decimal */
  Serial << "Decimal" << endl
  << dec
  << 42 << endl << endl;

  /* Set base */
  Serial << "Set base"  << endl
  << setbase(16)
  << 0x1234 << endl
  << setbase(10)
  << 1234 << endl << endl;

  /* Booleans */
  Serial << "Booleans" << endl
  << false << ' ' << true << endl
  << boolalpha
  << false << ' ' << true << endl
  <<  noboolalpha 
  << false << ' ' << true << endl << endl;

  /* Floats */
  Serial << "Floats" << endl
  << PI << endl          // 2 decimal digits of precision by default
  << setprecision(7)
  << PI << endl << endl;

  /* Flush */
  // 'flush' waits until all output characters are printed
  Serial << flush; // Note: endl flushes automatically

/********************************************* 
 *Non-standard (not supported using iostreams)
 *********************************************/

  /* Binary */  
  Serial << "Binary" << endl
  << setbase(2)
  << (uint8_t) 0xAA << endl
  << (int) 0xAAAA << endl;
  Serial << bin
  << (uint8_t) 0xAA << endl
  << (int) 0xAAAA << endl << endl;

  /* Leading zeros */
  Serial << "Leading zeros" << endl
  << noleadingzeros
  << (uint8_t) 0x08 << endl
  << (uint8_t) 0x01 << endl
  << leadingzeros
  << (uint8_t) 0x08 << endl
  << (uint8_t) 0x01 << endl << endl;

  /* Byte separators */  
  Serial << "Byte separators" << endl
  << setbytesep(' ')
  << (int) 0xAAAA << endl
  << hex
  << (int) 0xAAAA << endl;
  Serial
  << setbytesep('\0')
  << bin
  << 0xAAAA << endl
  << hex
  << 0xAAAA << endl << endl;

  /* Printable */
  struct HelloWorld : public Printable {
    size_t printTo(Print &printer) const {
      return printer.print(F("Hello, World!"));
    }
  } helloworld;
  Serial << "Printable" << endl
  << helloworld << endl << endl;

}

void loop() { }
