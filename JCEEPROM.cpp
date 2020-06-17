#include <avr/eeprom.h>
#include "JCEEPROM.h"

void JCEEPROM::Write_8Bits(int Address, int8_t Value) {
  eeprom_write_byte((uint8_t*) Address, Value);
}

void JCEEPROM::Write_16Bits(int Address, int Value) {
  eeprom_write_word((uint16_t*) Address, Value);
}

void JCEEPROM::Write_32Bits(int Address, long Value) {
  eeprom_write_dword((uint32_t*) Address, Value);
}

void JCEEPROM::Write_Float(int Address, float Value) {
  _Type_Union.FloatValue = Value;
  Write_32Bits(Address, _Type_Union.LongValue);
}

int JCEEPROM::Read_8Bits(int Address) {
  return eeprom_read_byte((const uint8_t*) Address);
}

int JCEEPROM::Read_16Bits(int Address) {
  return eeprom_read_word((const uint16_t*) Address);
}

long JCEEPROM::Read_32Bits(int Address) {
  return eeprom_read_dword((const uint32_t*) Address);
}

float JCEEPROM::Read_Float(int Address) {
  _Type_Union.LongValue = eeprom_read_dword((const uint32_t*) Address);
  return _Type_Union.FloatValue;
}
