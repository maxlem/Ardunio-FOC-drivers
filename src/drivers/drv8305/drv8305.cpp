#include "drv8305.h"
#include <SPI.h>

void DRV8305::init(SPIClass* spi)
{
    this->spi = spi;
    // TODO make SPI speed configurable
    settings = SPISettings(1000000, MSBFIRST, SPI_MODE1);
    //setup pins
    pinMode(cs, OUTPUT);
    digitalWrite(cs, HIGH); // switch off
    //SPI has an internal SPI-device counter, it is possible to call "begin()" from different devices
    spi->begin();

    // TODO add interrupt handler on the nFault pin if configured
    // add configuration for how to handle faults... idea: interrupt handler calls a callback, depending on the type of fault
    // consider what would be a useful configuration in practice? What do we want to do on a fault, e.g. over-temperature for example?

    warningAndWatchdog.init(spi,&settings, cs);
    oVandVDSFaults.init(spi,&settings, cs);
    icFaults.init(spi,&settings, cs);
    gateDriverVGSFaults.init(spi,&settings, cs);
    hsGateControl.init(spi,&settings, cs);
    lsGateControl.init(spi,&settings, cs);
    gateDriveControl.init(spi,&settings, cs);
    icOperation.init(spi,&settings, cs);
    shuntAmplifierControl.init(spi,&settings, cs);
    voltageRegulatorControl.init(spi,&settings, cs);
    vdsSenseControl.init(spi,&settings, cs);
}

void DRV8305::refresh()
{
    warningAndWatchdog.poll();
    oVandVDSFaults.poll();
    icFaults.poll();
    gateDriverVGSFaults.poll();
    hsGateControl.poll();
    lsGateControl.poll();
    gateDriveControl.poll();
    icOperation.poll();
    shuntAmplifierControl.poll();
    voltageRegulatorControl.poll();
    vdsSenseControl.poll();
}

void DRV8305::report(Stream & stream, bool refresh, bool onlyNonDefaults)
{
    if(refresh)
        this->refresh();

    warningAndWatchdog.report(stream, false, onlyNonDefaults);
    oVandVDSFaults.report(stream, false, onlyNonDefaults);
    icFaults.report(stream, false, onlyNonDefaults);
    gateDriverVGSFaults.report(stream, false, onlyNonDefaults);
    hsGateControl.report(stream, false, onlyNonDefaults);
    lsGateControl.report(stream, false, onlyNonDefaults);
    gateDriveControl.report(stream, false, onlyNonDefaults);
    icOperation.report(stream, false, onlyNonDefaults);
    shuntAmplifierControl.report(stream, false, onlyNonDefaults);
    voltageRegulatorControl.report(stream, false, onlyNonDefaults);
    vdsSenseControl.report(stream, false, onlyNonDefaults);
}


