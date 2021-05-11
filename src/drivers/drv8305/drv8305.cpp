#include "drv8305.h"
#include <SPI.h>

void DRV8305::init(SPIClass* spi)
{
// TODO make SPI speed configurable
    this->spi = spi;
    settings = SPISettings(1000000, MSBFIRST, SPI_MODE1);

    //setup pins
    pinMode(cs, OUTPUT);
    digitalWrite(cs, HIGH); // switch off

    //SPI has an internal SPI-device counter, it is possible to call "begin()" from different devices
    spi->begin();

    // TODO add interrupt handler on the nFault pin if configured
    // add configuration for how to handle faults... idea: interrupt handler calls a callback, depending on the type of fault
    // consider what would be a useful configuration in practice? What do we want to do on a fault, e.g. over-temperature for example?
}