#pragma once

#include <SPI.h>
#include "drv8305_registers.h"
#include "../common/SpiDriver.h"


class DRV8305 : public SpiDriver
{

public: 
    DRV8305(int cs, int nFault): SpiDriver(cs)
    {

    }

    void init(SPIClass* spi = &SPI) override;

    byte readRegister()
    {

    }
protected:
    int cs;
	int nFault;
    Drv8305Register * drvRegisters = drvRegisters_;
};