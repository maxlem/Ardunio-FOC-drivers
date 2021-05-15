#pragma once

#include <SPI.h>
#include <drivers/BLDCDriver3PWM.h>
#include <drivers/BLDCDriver6PWM.h>
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

class DRV8305Driver3PWM : public BLDCDriver3PWM
{
public:
    DRV8305Driver3PWM(int phA,int phB,int phC, int cs, bool currentLimit = false, int en = NOT_SET, int nFault = NOT_SET) :
        BLDCDriver3PWM(phA, phB, phC, en), drv8305(cs, nFault), currentLimit(currentLimit) {};
    virtual ~DRV8305Driver3PWM() {};

    int init(SPIClass* spi = &SPI)
    {
        drv8305.init(spi);
        
        drv8305.gateDriveControl.PWM_MODE_.setValue(DRV8305RegisterPWM_MODE::PWM_MODE_PWM_with_3_independent_inputs);
        drv8305.gateDriveControl.commit();
        return BLDCDriver3PWM::init();
    }

    DRV8305 drv8305;

    bool currentLimit;
};

class DRV8305Driver6PWM : public BLDCDriver6PWM
{
public:
	DRV8305Driver6PWM(int phA_h,int phA_l,int phB_h,int phB_l,int phC_h,int phC_l, int cs, bool currentLimit = false, int en = NOT_SET, int nFault = NOT_SET) :
			BLDCDriver6PWM(phA_h, phA_l, phB_h, phB_l, phC_h, phC_l, en), drv8305(cs, nFault), currentLimit(currentLimit) {};
    virtual ~DRV8305Driver6PWM() {};

    int init(SPIClass* spi = &SPI)
    {
        drv8305.init(spi);
        drv8305.gateDriveControl.PWM_MODE_.setValue(DRV8305RegisterPWM_MODE::PWM_MODE_PWM_with_6_independent_inputs);
        drv8305.gateDriveControl.commit();

        drv8305.shuntAmplifierControl.GAIN_CS1_.setValue(DRV8305RegisterGAIN_CS::GAIN_CS_80_VperV);
        drv8305.shuntAmplifierControl.GAIN_CS2_.setValue(DRV8305RegisterGAIN_CS::GAIN_CS_80_VperV);
        drv8305.shuntAmplifierControl.GAIN_CS3_.setValue(DRV8305RegisterGAIN_CS::GAIN_CS_80_VperV);
        drv8305.shuntAmplifierControl.commit();
        return BLDCDriver6PWM::init();
    }

    DRV8305 drv8305;

    bool currentLimit;
};