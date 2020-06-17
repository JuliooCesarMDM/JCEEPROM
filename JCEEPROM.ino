#include "JCEEPROM.h"

/******************************INFO**********************************/
//AUTOR:JULIO CESAR MATIAS
//DESENVOLVIDO OFICIALMENTE PARA A CONTROLADORA DE VOO JCFLIGHT
//DATA:SETEMBRO DE 2019
/********************************************************************/

uint8_t Byte_Value  = 99;
int16_t Short_Value = 30000;
int32_t Long_Value  = 123456789;
float   Float_Value = .01234;

JCEEPROM AVREEPROM;

void setup() {
  Serial.begin(115200);
  Serial.println("JCEEPROM EXEMPLO DE USO...");
  delay(250);

  AVREEPROM.Write_8Bits  (0, Byte_Value);  //1 BYTE  = APENAS 1 ENDEREÇO DA EEPROM
  AVREEPROM.Write_16Bits (1, Short_Value); //2 BYTES = 2 ENDEREÇOS DA EEPROM
  AVREEPROM.Write_32Bits (3, Long_Value);  //4 BYTES = 4 ENDEREÇOS DA EEPROM
  AVREEPROM.Write_Float  (7, Float_Value); //4 BYTES = 4 ENDEREÇOS DA EEPROM
  //O PROXIMO ENDEREÇO QUE SE PODE SER UTILIZADO É A PARTIR DO 12º

  Serial.println(AVREEPROM.Read_8Bits (0));
  Serial.println(AVREEPROM.Read_16Bits(1));
  Serial.println(AVREEPROM.Read_32Bits(3));
  Serial.println(AVREEPROM.Read_Float (7), 5);

}

void loop() {}
