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

    void refresh()
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
    void report(Stream & stream, bool refresh = true)
    {
        warningAndWatchdog.report(stream, refresh);
        oVandVDSFaults.report(stream, refresh);
        icFaults.report(stream, refresh);
        gateDriverVGSFaults.report(stream, refresh);
        hsGateControl.report(stream, refresh);
        lsGateControl.report(stream, refresh);
        gateDriveControl.report(stream, refresh);
        icOperation.report(stream, refresh);
        shuntAmplifierControl.report(stream, refresh);
        voltageRegulatorControl.report(stream, refresh);
        vdsSenseControl.report(stream, refresh);
    }

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