#ifndef PrintStream_h
#define PrintStream_h

#ifdef ARDUINO
#include <Arduino.h>
typedef Print &manipulator(Print &);

Print &endl(Print &printer);
Print &flush(Print &printer);
Print &hex(Print &printer);
Print &bin(Print &printer);
Print &dec(Print &printer);
Print &oct(Print &printer);
Print &boolalpha(Print &printer);
Print &noboolalpha(Print &printer);
Print &leadingzeros(Print &printer);
Print &noleadingzeros(Print &printer);

Print &operator<<(Print &printer, const __FlashStringHelper *s);
Print &operator<<(Print &printer, const String &s);
Print &operator<<(Print &printer, const char s[]);
Print &operator<<(Print &printer, char c);
Print &operator<<(Print &printer, unsigned char c);
Print &operator<<(Print &printer, int i);
Print &operator<<(Print &printer, unsigned int i);
Print &operator<<(Print &printer, int8_t i);
Print &operator<<(Print &printer, long i);
Print &operator<<(Print &printer, unsigned long i);
Print &operator<<(Print &printer, double d);
Print &operator<<(Print &printer, const Printable &p);
Print &operator<<(Print &printer, bool b);

Print &operator<<(Print &printer, manipulator pf);

struct _Setbase {
    uint8_t _M_base; 
};
_Setbase setbase(uint8_t __base);
Print &operator<<(Print &printer, _Setbase __f);

template <class T>
Print &printIntegral(Print &printer, T i);

#else // #ifndef ARDUINO

#include <iostream>
using std::endl;

#endif

#endif // PrintStream_h