#pragma once
#include <Arduino.h>

enum AccessMode: byte
{
    R,
    RW
};

// credits Terence M. 
// https://stackoverflow.com/questions/9907160/how-to-convert-enum-names-to-string-in-c

#define FOREACH_DRV8305RegisterName(GENERATOR) \
GENERATOR(FAULT) \
GENERATOR(RSVD) \
GENERATOR(TEMP_FLAG4) \
GENERATOR(PVDD_UVFL) \
GENERATOR(PVDD_OVFL) \
GENERATOR(VDS_STATUS) \
GENERATOR(VCHP_UVFL) \
GENERATOR(TEMP_FLAG1) \
GENERATOR(TEMP_FLAG2) \
GENERATOR(TEMP_FLAG3) \
GENERATOR(OTW) \
/*0x02*/ \
GENERATOR(VDS_HA) \
GENERATOR(VDS_LA) \
GENERATOR(VDS_HB) \
GENERATOR(VDS_LB) \
GENERATOR(VDS_HC) \
GENERATOR(VDS_LC) \
GENERATOR(SNS_C_OCP) \
GENERATOR(SNS_B_OCP) \
GENERATOR(SNS_A_OCP) \
/*0x03*/ \
GENERATOR(PVDD_UVLO2) \
GENERATOR(WD_FAULT) \
GENERATOR(OTSD) \
GENERATOR(VREG_UV) \
GENERATOR(AVDD_UVLO) \
GENERATOR(VCP_LSD_UVLO2) \
GENERATOR(VCPH_UVLO2) \
GENERATOR(VCPH_OVLO) \
GENERATOR(VCPH_OVLO_ABS) \
/*0x04*/ \
GENERATOR(VGS_HA) \
GENERATOR(VGS_LA) \
GENERATOR(VGS_HB) \
GENERATOR(VGS_LB) \
GENERATOR(VGS_HC) \
GENERATOR(VGS_LC) \
/*0x05*/ \
GENERATOR(TDRIVEN) \
GENERATOR(IDRIVEN_HS) \
GENERATOR(IDRIVEP_HS) \
/*0x06*/ \
GENERATOR(TDRIVEP) \
GENERATOR(IDRIVEN_LS) \
GENERATOR(IDRIVEP_LS) \
/*0x07*/ \
GENERATOR(COMM_OPTION) \
GENERATOR(PWM_MODE) \
GENERATOR(DEAD_TIME) \
GENERATOR(TBLANK) \
GENERATOR(TVDS) \
/*0x09*/ \
GENERATOR(FLIP_OTSD) \
GENERATOR(DIS_PVDD_UVLO2) \
GENERATOR(DIS_GDRV_FAULT) \
GENERATOR(EN_SNS_CLAMP) \
GENERATOR(WD_DLY) \
GENERATOR(DIS_SNS_OCP) \
GENERATOR(WD_EN) \
GENERATOR(SLEEP) \
GENERATOR(CLR_FLTS) \
GENERATOR(SET_VCPH_UV) \
/*0xA*/ \
GENERATOR(DC_CAL_CH3) \
GENERATOR(DC_CAL_CH2) \
GENERATOR(DC_CAL_CH1) \
GENERATOR(CS_BLANK) \
GENERATOR(GAIN_CS3) \
GENERATOR(GAIN_CS2) \
GENERATOR(GAIN_CS1) \
/*0xB*/ \
GENERATOR(VREF_SCALE) \
GENERATOR(SLEEP_DLY) \
GENERATOR(DIS_VREG_PWRGD) \
GENERATOR(VREG_UV_LEVEL) \
/*0xC*/ \
GENERATOR(VDS_LEVEL) \
GENERATOR(VDS_MODE) \

#define GENERATE_ENUM(ENUM) ENUM,
#define GENERATE_STRING(STRING) #STRING,

enum DRV8305RegisterName: byte {
    FOREACH_DRV8305RegisterName(GENERATE_ENUM)
};

static const char *DRV8305RegisterNameStrings[] = {
    FOREACH_DRV8305RegisterName(GENERATE_STRING)
};


#define GENERATE_ENUM_VALUE(ENUM, VALUE) ENUM=(VALUE),

#define GENERATE_STRING_VALUE(STRING, VALUE) #STRING,

#define FOREACH_DRV8305RegisterBOOL(GENERATOR) \
GENERATOR(False, 0b00) \
GENERATOR(True, 0b01)

enum DRV8305RegisterBOOL {
    FOREACH_DRV8305RegisterBOOL(GENERATE_ENUM_VALUE)
};

static const char *DRV8305RegisterBOOLStrings[] = {
    FOREACH_DRV8305RegisterBOOL(GENERATE_STRING_VALUE)
};

#define FOREACH_DRV8305RegisterTDRIVE(GENERATOR) \
GENERATOR(TDRIVEN_220_ns, 0b00) 	\
GENERATOR(TDRIVEN_440_ns, 0b01) 	\
GENERATOR(TDRIVEN_880_ns, 0b10) 	\
GENERATOR(TDRIVEN_1780_ns, 0b11)    

enum DRV8305RegisterTDRIVE {
    FOREACH_DRV8305RegisterTDRIVE(GENERATE_ENUM_VALUE)
};

static const char *DRV8305RegisterTDRIVEStrings[] = {
    FOREACH_DRV8305RegisterTDRIVE(GENERATE_STRING_VALUE)
};

#define FOREACH_DRV8305RegisterIDRIVEN(GENERATOR) \
GENERATOR(IDRIVEN_HS_20_mA, 0b0000) \
GENERATOR(IDRIVEN_HS_60_mA, 0b0100) \  
GENERATOR(IDRIVEN_HS_0_50_A, 0b1000) \ 
GENERATOR(IDRIVEN_HS_60_mA_a, 0b1100) \  
GENERATOR(IDRIVEN_HS_30_mA, 0b0001) \  
GENERATOR(IDRIVEN_HS_70_mA, 0b0101) \  
GENERATOR(IDRIVEN_HS_0_75_A, 0b1001) \ 
GENERATOR(IDRIVEN_HS_60_mA_b, 0b1101) \  
GENERATOR(IDRIVEN_HS_40_mA, 0b0010) \ 	
GENERATOR(IDRIVEN_HS_80_mA, 0b0110) \ 	
GENERATOR(IDRIVEN_HS_1_00_A, 0b1010) \ 	
GENERATOR(IDRIVEN_HS_60_mA_c, 0b1110) \ 	
GENERATOR(IDRIVEN_HS_50_mA, 0b0011) \
GENERATOR(IDRIVEN_HS_0_25_A, 0b0111) \
GENERATOR(IDRIVEN_HS_1_25_A, 0b1011) \
GENERATOR(IDRIVEN_HS_60_mA_d, 0b1111) \


enum DRV8305RegisterIDRIVEN {
    FOREACH_DRV8305RegisterIDRIVEN(GENERATE_ENUM_VALUE)
};

static const char *DRV8305RegisterIDRIVENStrings[] = {
    FOREACH_DRV8305RegisterIDRIVEN(GENERATE_STRING_VALUE)
};

#define FOREACH_DRV8305RegisterIDRIVEP(GENERATOR) \
GENERATOR(IDRIVEP_HS_10_mA, 0b0000) \  
GENERATOR(IDRIVEP_HS_50_mA, 0b0100) \  
GENERATOR(IDRIVEP_HS_0_25_A, 0b1000) \ 
GENERATOR(IDRIVEP_HS_50_mA_a, 0b1100) \  
GENERATOR(IDRIVEP_HS_20_mA, 0b0001) \  
GENERATOR(IDRIVEP_HS_60_mA, 0b0101) \  
GENERATOR(IDRIVEP_HS_0_50_A, 0b1001) \ 
GENERATOR(IDRIVEP_HS_50_mA_b, 0b1101) \  
GENERATOR(IDRIVEP_HS_30_mA, 0b0010) \ 	
GENERATOR(IDRIVEP_HS_70_mA, 0b0110) \ 	
GENERATOR(IDRIVEP_HS_0_75_A, 0b1010) \ 	
GENERATOR(IDRIVEP_HS_50_mA_c, 0b1110) \ 	
GENERATOR(IDRIVEP_HS_40_mA, 0b0011) \
GENERATOR(IDRIVEP_HS_0_125_A, 0b0111) \ 
GENERATOR(IDRIVEP_HS_1_00_A, 0b1011) \
GENERATOR(IDRIVEP_HS_50_mA_d, 0b1111)

enum DRV8305RegisterIDRIVEP {
    FOREACH_DRV8305RegisterIDRIVEP(GENERATE_ENUM_VALUE)
};

static const char *DRV8305RegisterIDRIVEPStrings[] = {
    FOREACH_DRV8305RegisterIDRIVEP(GENERATE_STRING_VALUE)
};



template <typename ValueType
, byte BitStart
, byte BitCount
, AccessMode Mode
, DRV8305RegisterName Name>
class DRV8305Register
{
public:
    static const byte bitStart = BitStart;
    static const byte bitCount = BitCount;
    static const AccessMode mode = Mode;
    static const DRV8305RegisterName name = Name;

	DRV8305Register(ValueType defaultValue, const char * description) : 
	defaultValue(defaultValue), value(defaultValue), description(description)
	{

	}
    ValueType defaultValue;
	ValueType value;
    const char * description;
};



// 7.6.1.1 Warning and Watchdog Reset (Address = 0x1) 
// Table 9. Warning and Watchdog Reset Register Description 
// BIT  RW  NAME  DEFAULT  DESCRIPTION 

template <byte Address>
class Register
{
	static const byte address = Address;
};

class WarningAndWatchdog : Register<0x01>
{

public:
	WarningAndWatchdog():  
	FAULT_(DRV8305RegisterBOOL::False,  "Fault indication"),
	RSVD_(DRV8305RegisterBOOL::False, "-"),
	TEMP_FLAG4_(DRV8305RegisterBOOL::False,  "Temperature flag setting for approximately 175°C"),
	PVDD_UVFL_(DRV8305RegisterBOOL::False,  "PVDD undervoltage flag warning"),
	PVDD_OVFL_(DRV8305RegisterBOOL::False,  "PVDD overvoltage flag warning"),
	VDS_STATUS_(DRV8305RegisterBOOL::False,  "Real time OR of all VDS overcurrent monitors"),
	VCHP_UVFL_(DRV8305RegisterBOOL::False,  "Charge pump undervoltage flag warning"),
	TEMP_FLAG1_(DRV8305RegisterBOOL::False,  "Temperature flag setting for approximately 105°C"),
	TEMP_FLAG2_(DRV8305RegisterBOOL::False,  "Temperature flag setting for approximately 125°C"),
	TEMP_FLAG3_(DRV8305RegisterBOOL::False,  "Temperature flag setting for approximately 135°C"),
	OTW_(DRV8305RegisterBOOL::False,  "Overtemperature warning"){}

	DRV8305Register<DRV8305RegisterBOOL, 10,  1, R,  FAULT> FAULT_;
	DRV8305Register<DRV8305RegisterBOOL, 9,   1, R,  RSVD> RSVD_;
	DRV8305Register<DRV8305RegisterBOOL, 8,   1, R,  TEMP_FLAG4> TEMP_FLAG4_;
	DRV8305Register<DRV8305RegisterBOOL, 7,   1, R,  PVDD_UVFL> PVDD_UVFL_;
	DRV8305Register<DRV8305RegisterBOOL, 6,   1, R,  PVDD_OVFL> PVDD_OVFL_;
	DRV8305Register<DRV8305RegisterBOOL, 5,   1, R,  VDS_STATUS> VDS_STATUS_;
	DRV8305Register<DRV8305RegisterBOOL, 4,   1, R,  VCHP_UVFL> VCHP_UVFL_;
	DRV8305Register<DRV8305RegisterBOOL, 3,   1, R,  TEMP_FLAG1> TEMP_FLAG1_;
	DRV8305Register<DRV8305RegisterBOOL, 2,   1, R,  TEMP_FLAG2> TEMP_FLAG2_;
	DRV8305Register<DRV8305RegisterBOOL, 1,   1, R,  TEMP_FLAG3> TEMP_FLAG3_;
	DRV8305Register<DRV8305RegisterBOOL, 0,   1, R,  OTW> OTW_;
};

// 7.6.1.2 OV/VDS Faults (Address = 0x2) 
// Table 10. OV/VDS Faults Register Description 
// BIT 	RW 	NAME  DEFAULT  DESCRIPTION
class OVandVDSFaults : Register<0x02> 
{

public: 
	OVandVDSFaults():
	VDS_HA_(DRV8305RegisterBOOL::False,  "VDS overcurrent fault for high-side MOSFET A"),
	VDS_LA_(DRV8305RegisterBOOL::False,  "VDS overcurrent fault for low-side MOSFET A"),
	VDS_HB_(DRV8305RegisterBOOL::False,  "VDS overcurrent fault for high-side MOSFET B"),
	VDS_LB_(DRV8305RegisterBOOL::False,  "VDS overcurrent fault for low-side MOSFET B"),
	VDS_HC_(DRV8305RegisterBOOL::False,  "VDS overcurrent fault for high-side MOSFET C"),
	VDS_LC_(DRV8305RegisterBOOL::False,  "VDS overcurrent fault for low-side MOSFET C"),
	RSVD_(DRV8305RegisterBOOL::False,  "-"),
	SNS_C_OCP_(DRV8305RegisterBOOL::False,  "Sense C overcurrent fault"),
	SNS_B_OCP_(DRV8305RegisterBOOL::False,  "Sense B overcurrent fault"),
	SNS_A_OCP_(DRV8305RegisterBOOL::False,  "Sense A overcurrent fault"){}

	DRV8305Register<DRV8305RegisterBOOL, 10, 1, 	R, 	VDS_HA> VDS_HA_;
	DRV8305Register<DRV8305RegisterBOOL, 9,  1, 	R, 	VDS_LA> VDS_LA_;
	DRV8305Register<DRV8305RegisterBOOL, 8,  1, 	R, 	VDS_HB> VDS_HB_;
	DRV8305Register<DRV8305RegisterBOOL, 7,  1, 	R, 	VDS_LB> VDS_LB_;
	DRV8305Register<DRV8305RegisterBOOL, 6,  1, 	R, 	VDS_HC> VDS_HC_;
	DRV8305Register<DRV8305RegisterBOOL, 5,  1, 	R, 	VDS_LC> VDS_LC_;
	DRV8305Register<DRV8305RegisterBOOL, 3,  2, 	R, 	RSVD> RSVD_;
	DRV8305Register<DRV8305RegisterBOOL, 2,  1, 	R, 	SNS_C_OCP> SNS_C_OCP_;
	DRV8305Register<DRV8305RegisterBOOL, 1,  1, 	R, 	SNS_B_OCP> SNS_B_OCP_;
	DRV8305Register<DRV8305RegisterBOOL, 0,  1, 	R, 	SNS_A_OCP> SNS_A_OCP_;
};

// 7.6.1.3 IC Faults (Address = 0x3) 
// Table 11. IC Faults Register Description 
// BIT  RW  NAME  DEFAULT  DESCRIPTION 

class ICFaults: public Register<0x03> 
{

public:
	ICFaults():
	PVDD_UVLO2_(DRV8305RegisterBOOL::False,  "PVDD undervoltage 2 fault"),
	WD_FAULT_(DRV8305RegisterBOOL::False,  "Watchdog fault"),
	OTSD_(DRV8305RegisterBOOL::False,  "Overtemperature fault"),
	RSVD_(DRV8305RegisterBOOL::False,  "-"),
	VREG_UV_(DRV8305RegisterBOOL::False,  "VREG undervoltage fault"),
	AVDD_UVLO_(DRV8305RegisterBOOL::False,  "AVDD undervoltage fault"),
	VCP_LSD_UVLO2_(DRV8305RegisterBOOL::False,  "Low-side gate supply fault"),
	VCPH_UVLO2_(DRV8305RegisterBOOL::False,  "High-side charge pump undervoltage 2 fault"),
	VCPH_OVLO_(DRV8305RegisterBOOL::False,  "High-side charge pump overvoltage fault"),
	VCPH_OVLO_ABS_(DRV8305RegisterBOOL::False,  "High-side charge pump overvoltage ABS fault"){}

	DRV8305Register<DRV8305RegisterBOOL, 10, 1,  R,  PVDD_UVLO2> PVDD_UVLO2_;
	DRV8305Register<DRV8305RegisterBOOL, 9,  1,  R,  WD_FAULT> WD_FAULT_;
	DRV8305Register<DRV8305RegisterBOOL, 8,  1,  R,  OTSD> OTSD_;
	DRV8305Register<DRV8305RegisterBOOL, 7,  1,  R,  RSVD> RSVD_;
	DRV8305Register<DRV8305RegisterBOOL, 6,  1,  R,  VREG_UV> VREG_UV_;
	DRV8305Register<DRV8305RegisterBOOL, 5,  1,  R,  AVDD_UVLO> AVDD_UVLO_;
	DRV8305Register<DRV8305RegisterBOOL, 4,  1,  R,  VCP_LSD_UVLO2> VCP_LSD_UVLO2_;
	DRV8305Register<DRV8305RegisterBOOL, 2,  1,  R,  VCPH_UVLO2> VCPH_UVLO2_;
	DRV8305Register<DRV8305RegisterBOOL, 1,  1,  R,  VCPH_OVLO> VCPH_OVLO_;
	DRV8305Register<DRV8305RegisterBOOL, 0,  1,  R,  VCPH_OVLO_ABS> VCPH_OVLO_ABS_;
};

// 7.6.1.4 VGS Faults (Address = 0x4) 
// Table 12. Gate Driver VGS Faults Register Description 
// BIT  RW  NAME  DEFAULT  DESCRIPTION 

class GateDriverVGSFaults : public Register<0x04> 
{
public:
	GateDriverVGSFaults() :
	VGS_HA_(DRV8305RegisterBOOL::False,  "VGS gate drive fault for high-side MOSFET A"),
	VGS_LA_(DRV8305RegisterBOOL::False,  "VGS gate drive fault for low-side MOSFET A"),
	VGS_HB_(DRV8305RegisterBOOL::False,  "VGS gate drive fault for high-side MOSFET B"),
	VGS_LB_(DRV8305RegisterBOOL::False,  "VGS gate drive fault for low-side MOSFET B"),
	VGS_HC_(DRV8305RegisterBOOL::False,  "VGS gate drive fault for high-side MOSFET C"),
	VGS_LC_(DRV8305RegisterBOOL::False,  "VGS gate drive fault for low-side MOSFET C"),
	RSVD_(DRV8305RegisterBOOL::False,  "-"){}

	DRV8305Register<DRV8305RegisterBOOL, 10, 1,  R,  VGS_HA> VGS_HA_;
	DRV8305Register<DRV8305RegisterBOOL, 9,  1,  R,  VGS_LA> VGS_LA_;
	DRV8305Register<DRV8305RegisterBOOL, 8,  1,  R,  VGS_HB> VGS_HB_;
	DRV8305Register<DRV8305RegisterBOOL, 7,  1,  R,  VGS_LB> VGS_LB_;
	DRV8305Register<DRV8305RegisterBOOL, 6,  1,  R,  VGS_HC> VGS_HC_;
	DRV8305Register<DRV8305RegisterBOOL, 5,  1,  R,  VGS_LC> VGS_LC_;
	DRV8305Register<DRV8305RegisterBOOL, 0,  5,  R,  RSVD> RSVD_;
};
struct DRV8305RegisterDescription
{
    byte bitStart;
    byte bitcount;
    AccessMode mode;
    DRV8305RegisterName name;
    byte defaultValue;
    const char * description;
};






// 7.6.2 Control Registers 
// Control registers are used to set the device parameters for DRV8305-Q1. The default values are shown in bold. 
// • Control registers are read/write registers 
// • Do not clear on register read, CLR_FLTs, or EN_GATE resets 
// • Cleared to default values on power up 
// • Cleared to default values when the device enters SLEEP mode 
// 7.6.2.1  HS Gate Drive Control (Address = 0x5) 
// Table 13. HS Gate Driver Control Register Description 
//BIT 	RW 	NAME 	DEFAULT 	DESCRIPTION 	


DRV8305RegisterDescription HSGateControl_0x05[] = 
{
{10 , 1, RW, 	RSVD, 	0x0, 	"-"},
{8 	, 2, RW, 	TDRIVEN, 	0x3, 	"High-side gate driver peak source time"},
{4 	, 4, RW, 	IDRIVEN_HS, 	0x4, 	"High-side gate driver peak sink current"},
{0 	, 4, RW, 	IDRIVEP_HS, 	0x4, 	"High-side gate driver peak source current"},
};

// 7.6.2.2  LS Gate Drive Control (Address = 0x6) 
// Table 14. LS Gate Driver Control Register Description 
// BIT 	RW 	NAME 	DEFAULT 	DESCRIPTION 	

DRV8305RegisterDescription LSGateControl_0x06[] = 
{
{10, 1, RW, 	RSVD, 	0x0, 	"-"},
{8, 2, 	RW, 	TDRIVEP, 	0x3, 	"Low-side gate driver peak source time"},
{4, 4, 	RW, 	IDRIVEN_LS, 	0x4, 	"Low-side gate driver peak sink current"},
{0, 4, 	RW, 	IDRIVEP_LS, 	0x4, 	"Low-side gate driver peak source current"},
};



// 7.6.2.3  Gate Drive Control (Address = 0x7) 	
// Table 15. Gate Drive Control Register Description 	
// BIT 	RW 	NAME 	DEFAULT 	DESCRIPTION

DRV8305RegisterDescription GateDriveControl_0x07[] = 
{
{10, 1, 	RW, 	RSVD, 	0x0, 	"-"},
{9, 1, 	RW, 	COMM_OPTION, 	0x1, 	"Rectification control (PWM_MODE = b'10 only)\
				b'0 - diode freewheeling \
				b'1 - active freewheeling"},	
{8, 2, 	RW, 	PWM_MODE, 	0x0, 	"PWM Mode \
				b'00 - PWM with 6 independent inputs \
				b'01 - PWM with 3 independent inputs \	
				b'10 - PWM with one input \	
				b'11 - PWM with 6 independent inputs"}, 	
{5, 3, 	RW, 	DEAD_TIME, 	0x1, 	"Dead time \
				b'000 - 35 ns b'001 - 52 ns 	b'010 - 88 ns \
				b'011 - 440 ns b'100 - 880 ns 	b'101 - 1760 ns \ 
				b'110 - 3520 ns b'111 - 5280 ns"},	
{3, 2, 	RW, 	TBLANK, 	0x1, 	"VDS sense blanking \
				b'00 - 0 μs 	\
				b'01 - 1.75 μs 	\
				b'10 - 3.5 μs 	\
				b'11 - 7 μs"}, 	
{1, 2, 	RW, 	TVDS, 	0x2, 	"VDS sense deglitch \
				b'00 - 0 μs 	\
				b'01 - 1.75 μs 	\
				b'10 - 3.5 μs 	\
				b'11 - 7 μs"}, 	
};

// 7.6.2.4  IC Operation (Address = 0x9) 
// Table 16. IC Operation Register Description 
// BIT 	RW 	NAME 	DEFAULT 	DESCRIPTION 

DRV8305RegisterDescription ICOperation_0x09[] = 
{
{10, 1, RW, 	FLIP_OTSD, 	0x0, 	"Enable OTSD \
				b'0 - Disable OTSD \
				b'1 - Enable OTSD "},
{9, 1, 	RW, 	DIS_PVDD_UVLO2, 	0x0, 	"Disable PVDD_UVLO2 fault and reporting \
				b'0 - PVDD_UVLO2 enabled \
				b'1 - PVDD_UVLO2 disabled "},
{8, 1, 	RW, 	DIS_GDRV_FAULT, 	0x0, 	"Disable gate drive fault and reporting \
				b'0 - Gate driver fault enabled \
				b'1 - Gate driver fault disabled "},
{7, 1, 	RW, 	EN_SNS_CLAMP, 	0x0, 	"Enable sense amplifier clamp \
				b'0 - Sense amplifier clamp is not enabled \
				b'1 - Sense amplifier clamp is enabled, limiting output to ~3.3 V "},
{5, 2, 	RW, 	WD_DLY, 	0x1, 	"Watchdog delay \
				b'00 - 10 ms \
				b'01 - 20 ms \
				b'10 - 50 ms \
				b'11 - 100 ms "},
{4, 1, 	RW, 	DIS_SNS_OCP, 	0x0, 	"Disable SNS overcurrent protection fault and reporting \
				b'0 - SNS OCP enabled \
				b'1 - SNS OCP disabled "},
{3, 1, 	RW, 	WD_EN, 	0x0, 	"Watchdog enable \
				b'0 - Watch dog disabled \
				b'1 - Watch dog enabled "},
{2, 1, 	RW, 	SLEEP, 	0x0, 	"Put device into sleep mode \
				b'0 - Device awake \
				b'1 - Device asleep "},
{1, 1, 	RW, 	CLR_FLTS, 	0x0, 	"Clear faults \
				b'0 - Normal operation \
				b'1 - Clear faults "},
{0, 1, 	RW, 	SET_VCPH_UV, 	0x0, 	"Set charge pump undervoltage threshold level \
				b'0 - 4.9 V \
				b'1 - 4.6 V "},
};

// 7.6.2.5  Shunt Amplifier Control (Address = 0xA) 
// Table 17. Shunt Amplifier Control Register Description 
// BIT 	RW 	NAME 	DEFAULT 	DESCRIPTION 

DRV8305RegisterDescription ShuntAmplifierControl_0x0A[] = 
{
{10, 1, RW, 	DC_CAL_CH3, 	0x0, 	"DC calibration of CS amplifier 3 \
				b'0 - Normal operation \
				b'1 - DC calibration mode "},
{9, 1, 	RW, 	DC_CAL_CH2, 	0x0, 	"DC calibration of CS amplifier 2 \
				b'0 - Normal operation \
				b'1 - DC calibration mode "},
{8, 1, 	RW, 	DC_CAL_CH1, 	0x0, 	"DC calibration of CS amplifier 1 \
				b'0 - Normal operation \
				b'1 - DC calibration mode "},
{6, 1, 	RW, 	CS_BLANK, 	0x0, 	"Current shunt amplifier blanking time \
				b'00 - 0 ns \
				b'01 - 500 ns \
				b'10 - 2.5 μs \
				b'11 - 10 μs "},
{4, 1, 	RW, 	GAIN_CS3, 	0x0, 	"Gain of CS amplifier 3 \
				b'00 - 10 V/V \
				b'01 - 20 V/V \
				b'10 - 40 V/V \
				b'11 - 80 V/V "},
{2, 1, 	RW, 	GAIN_CS2, 	0x0, 	"Gain of CS amplifier 2 \
				b'00 - 10 V/V \
				b'01 - 20 V/V \
				b'10 - 40 V/V \
				b'11 - 80 V/V "},
{0, 1, 	RW, 	GAIN_CS1, 	0x0, 	"Gain of CS amplifier 1 \
				b'00 - 10 V/V \
				b'01 - 20 V/V \
				b'10 - 40 V/V \
				b'11 - 80 V/V "},
};


// 7.6.2.6  Voltage Regulator Control (Address = 0xB) 
// Table 18. Voltage Regulator Control Register Description 
// BIT 	RW 	NAME 	DEFAULT 	DESCRIPTION 

DRV8305RegisterDescription VoltageRegulatorControl_0x0B[] = 
{
{10, 1, RW, 	RSVD, 	0x0, 	"-"},
{6, 2, 	RW, 	VREF_SCALE, 	0x1, 	"VREF Scaling \
				b'00 - RSVD \
				b'01 - k = 2 \
				b'10 - k = 4 \
				b'11 - RSVD "},
{5, 1, 	RW, 	RSVD, 	0x0, 	"-"},
{3, 2, 	RW, 	SLEEP_DLY, 	0x1, 	"Delay to power down VREG after SLEEP \
				b'00 - 0 μs \
				b'01 - 10 μs \
				b'10 - 50 μs \
				b'11 - 1 ms"},
{2, 1, 	RW, 	DIS_VREG_PWRGD, 	0x0, 	"Disable VREG undervoltage fault and reporting \
				b'0 - VREG_UV enabled \
				b'1 - VREG_UV disabled"},
{0, 2, 	RW, 	VREG_UV_LEVEL, 	0x2, 	"VREG undervoltage set point \
				b'00 - VREG x 0.9 \
				b'01 - VREG x 0.8 \
				b'10 - VREG x 0.7 \
				b'11 - VREG x 0.7"},
};


//7.6.2.7  VDS Sense Control (Address = 0xC) 
//Table 19. VDS Sense Control Register Description 
//BIT 	RW 	NAME 	DEFAULT 	DESCRIPTION 

DRV8305RegisterDescription VDSSenseControl_0x0C[] = 
{
{8, 1, 	RW, 	RSVD, 	0x0, 	"-"},
{3, 5, 	RW, 	VDS_LEVEL, 	0x19, 	"VDS comparator threshold\
				b'00000  - 0.060  V b'00001 - 0.068 V b'00010  - 0.076 V b'00011  - 0.086  V \
				b'00100  - 0.097  V b'00101 - 0.109 V b'00110  - 0.123 V b'00111  - 0.138  V \
				b'01000  - 0.155  V b'01001 - 0.175 V b'01010  - 0.197V b'01011  - 0.222  V \
				b'01100  - 0.250  V b'01101 - 0.282 V b'01110  - 0.317 V b'01111  - 0.358  V \
				b'10000  - 0.403  V b'10001 - 0.454 V b'10010  - 0.511 V b'10011  - 0.576  V \
				b'10100  - 0.648  V b'10101 - 0.730 V b'10110  - 0.822 V b'10111  - 0.926  V \
				b'11000  - 1.043  V b'11001 - 1.175 V b'11010  - 1.324 V b'11011  - 1.491  V \
				b'11100  - 1.679  V b'11101 - 1.892 V b'11110  - 2.131 V b'11111  - 2.131  V"}, 
{0, 3, 	RW, 	VDS_MODE, 	0x0, 	"VDS mode \
				b'000 - Latched shut down when over-current detected \
				b'001 - Report only when over current detected \
				b'010 - VDS protection disabled (no overcurrent sensing or reporting)"},
};


struct Drv8305Register
{
    byte address;
    byte nEntries;
    DRV8305RegisterDescription * descriptions;
    const char * description;
};

Drv8305Register drvRegisters_[] = 
{
    // {0x01, 11, WarningAndWatchdog_0x01, "Warning and Watchdog Reset (Address = 0x1)"}, 
    // {0x02, 10, OVandVDSFaults_0x02, "OV/VDS Faults (Address = 0x2)"}, 
    // {0x03, 11, ICFaults_0x03, "IC Faults (Address = 0x3)"}, 
    // {0x04, 7,  GateDriverVGSFaults_0x04, "Gate Driver VGS Faults Register Description (Address = 0x4)"}, 
    {0x05, 4,  HSGateControl_0x05, "HS Gate Drive Control (Address = 0x5)"}, 
    {0x06, 4,  LSGateControl_0x06, "LS Gate Drive Control (Address = 0x6)"}, 
    {0x07, 6,  GateDriveControl_0x07, "Gate Drive Control (Address = 0x7)"}, 
    {0x09, 10, ICOperation_0x09, "IC Operation (Address = 0x9)"}, 
    {0x0A, 7,  ShuntAmplifierControl_0x0A, "Shunt Amplifier Control (Address = 0xA)"}, 
    {0x0B, 6,  VoltageRegulatorControl_0x0B, "Voltage Regulator Control (Address = 0xB)"}, 
    {0x0C, 3,  VDSSenseControl_0x0C, "VDS Sense Control (Address = 0xC)"}, 
};