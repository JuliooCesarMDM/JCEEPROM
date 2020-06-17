#ifndef JCEEPROM_h
#define JCEEPROM_h

#include "Arduino.h"

class JCEEPROM {
  public:
    JCEEPROM() {}
    int		Read_8Bits   (int Address);
    int		Read_16Bits  (int Address);
    long	Read_32Bits  (int Address);
    float	Read_Float   (int Address);
    void	Write_8Bits  (int Address, int8_t  Value);
    void	Write_16Bits (int Address, int16_t Value);
    void	Write_32Bits (int Address, int32_t Value);
    void	Write_Float  (int Address, float   Value);
  private:
    union Type_Union {
      int8_t BytesArray[4];
      long 	 LongValue;
      int 	 ShortValue;
      float  FloatValue;
    } _Type_Union;
};
#endif
