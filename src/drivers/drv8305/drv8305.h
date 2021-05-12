#pragma once

#include <SPI.h>
#include "drv8305_registers.h"


class DRV8305
{

public: 
    DRV8305(int cs, int nFault): cs(cs), nFault(nFault)
    {

    }

    void init(SPIClass* spi = &SPI);

    void refresh();
    void report(Stream & stream, bool refresh = true);

    WarningAndWatchdog      warningAndWatchdog;
    OVandVDSFaults          oVandVDSFaults;
    ICFaults                icFaults;
    GateDriverVGSFaults     gateDriverVGSFaults;
    HSGateControl           hsGateControl;
    LSGateControl           lsGateControl;
    GateDriveControl        gateDriveControl;
    ICOperation             icOperation;
    ShuntAmplifierControl   shuntAmplifierControl;
    VoltageRegulatorControl voltageRegulatorControl;
    VDSSenseControl         vdsSenseControl;

protected:

    int cs;
	int nFault;
    SPIClass * spi = nullptr;
    SPISettings settings;
};