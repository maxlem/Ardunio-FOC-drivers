#ifndef SIMPLEFOC_SpiDriver
#define SIMPLEFOC_SpiDriver

#include <Arduino.h>
#include <SPI.h>

class SpiDriver
{
    public: 
        SpiDriver(int cs):cs(cs){}
        virtual void init(SPIClass* spi) = 0;
	protected:
		uint16_t readSPI(uint8_t addr);
		uint16_t writeSPI(uint8_t addr, uint8_t data);
		bool getParity(uint16_t data);

		int cs;
		SPIClass* spi;
		SPISettings settings;
};
#endif