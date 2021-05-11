#include "SpiDriver.h"

bool SpiDriver::getParity(uint16_t data) {
	//PARITY = XNOR(CMD, A5..A0, D7..D0)
	uint8_t par = 0;
	for (int i=0;i<16;i++) {
		if (((data)>>i) & 0x0001)
			par+=1;
	}
	return (par&0x01)==0x01; // even number of bits means true
}




uint16_t SpiDriver::readSPI(uint8_t addr) {
	digitalWrite(cs, 0);
	spi->beginTransaction(settings);
	uint16_t data = (((addr<<1) | 0x80)<<8)|0x0000;
	if (getParity(data))
		data |= 0x0100;
	uint16_t result = spi->transfer16(data);
	spi->endTransaction();
	digitalWrite(cs, 1);
//	Serial.print("SPI Read Result: ");
//	Serial.print(data, HEX);
//	Serial.print(" -> ");
//	Serial.println(result, HEX);
	return result;
}


uint16_t SpiDriver::writeSPI(uint8_t addr, uint8_t value) {
	digitalWrite(cs, 0);
	spi->beginTransaction(settings);
	uint16_t data = ((addr<<1)<<8)|value;
	if (getParity(data))
		data |= 0x0100;
	uint16_t result = spi->transfer16(data);
	spi->endTransaction();
	digitalWrite(cs, 1);
//	Serial.print("SPI Write Result: ");
//	Serial.print(data, HEX);
//	Serial.print(" -> ");
//	Serial.println(result, HEX);
	return result;
}