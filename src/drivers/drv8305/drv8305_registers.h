#pragma once
#include <Arduino.h>

// inspired from Terence M. 
// https://stackoverflow.com/questions/9907160/how-to-convert-enum-names-to-string-in-c

#define GENERATE_ENUM_VALUE(ENUM, VALUE) ENUM=(VALUE),

#define GENERATE_STRING_VALUE(STRING, VALUE) case STRING: return F(#STRING); break;

#define GENERATE_ENUM_AND_STRINGS(NAME, FOREACH) \
enum DRV8305Register##NAME { \
    FOREACH(GENERATE_ENUM_VALUE) \
}; \
class DRV8305Register##NAME##ToString \
{ \
public: \
	static const __FlashStringHelper * toString(DRV8305Register##NAME enumValue) { \
		switch(enumValue)\
		{ \
			FOREACH(GENERATE_STRING_VALUE) \
			default: return F("Unkown enum value"); \
		} \
	}\
};


#define FOREACH_Name(GEN) \
/*0x1*/ \
GEN(FAULT,      0x1A) \
GEN(RSVD,       0x19) \
GEN(TEMP_FLAG4, 0x18) \
GEN(PVDD_UVFL,  0x17) \
GEN(PVDD_OVFL,  0x16) \
GEN(VDS_STATUS, 0x15) \
GEN(VCHP_UVFL, 	0x14) \
GEN(TEMP_FLAG1, 0x13) \
GEN(TEMP_FLAG2, 0x12) \
GEN(TEMP_FLAG3, 0x11) \
GEN(OTW, 		0x10) \
/*0x2*/ \
GEN(VDS_HA   , 0x2A) \
GEN(VDS_LA   , 0x29) \
GEN(VDS_HB   , 0x28) \
GEN(VDS_LB   , 0x27) \
GEN(VDS_HC   , 0x26) \
GEN(VDS_LC   , 0x25) \
GEN(SNS_C_OCP, 0x22) \
GEN(SNS_B_OCP, 0x21) \
GEN(SNS_A_OCP, 0x20) \
/*0x3*/ \
GEN(PVDD_UVLO2,    0x3A) \
GEN(WD_FAULT,      0x39) \
GEN(OTSD,          0x38) \
GEN(VREG_UV,       0x36) \
GEN(AVDD_UVLO,     0x35) \
GEN(VCP_LSD_UVLO2, 0x34) \
GEN(VCPH_UVLO2,    0x32) \
GEN(VCPH_OVLO,     0x31) \
GEN(VCPH_OVLO_ABS, 0x30) \
/*0x4*/ \
GEN(VGS_HA, 0x4A) \
GEN(VGS_LA, 0x49) \
GEN(VGS_HB, 0x48) \
GEN(VGS_LB, 0x47) \
GEN(VGS_HC, 0x46) \
GEN(VGS_LC, 0x45) \
/*0x5*/ \
GEN(TDRIVEN   , 0x58) \
GEN(IDRIVEN_HS, 0x54) \
GEN(IDRIVEP_HS, 0x50) \
/*0x6*/ \
GEN(TDRIVEP   , 0x68) \
GEN(IDRIVEN_LS, 0x64) \
GEN(IDRIVEP_LS, 0x60) \
/*0x7*/ \
GEN(COMM_OPTION, 0x79) \
GEN(PWM_MODE   , 0x78) \
GEN(DEAD_TIME  , 0x75) \
GEN(TBLANK     , 0x73) \
GEN(TVDS       , 0x71) \
/*0x9*/ \
GEN(FLIP_OTSD     , 0x9A) \
GEN(DIS_PVDD_UVLO2, 0x99) \
GEN(DIS_GDRV_FAULT, 0x98) \
GEN(EN_SNS_CLAMP  , 0x97) \
GEN(WD_DLY        , 0x95) \
GEN(DIS_SNS_OCP   , 0x94) \
GEN(WD_EN         , 0x93) \
GEN(SLEEP         , 0x92) \
GEN(CLR_FLTS      , 0x91) \
GEN(SET_VCPH_UV   , 0x90) \
/*0xA*/ \
GEN(DC_CAL_CH3, 0xAA) \
GEN(DC_CAL_CH2, 0xA9) \
GEN(DC_CAL_CH1, 0xA8) \
GEN(CS_BLANK  , 0xA6) \
GEN(GAIN_CS3  , 0xA4) \
GEN(GAIN_CS2  , 0xA2) \
GEN(GAIN_CS1  , 0xA0) \
/*0xB*/ \
GEN(VREF_SCALE    , 0xB8) \
GEN(SLEEP_DLY     , 0xB3) \
GEN(DIS_VREG_PWRGD, 0xB2) \
GEN(VREG_UV_LEVEL , 0xB0) \
/*0xC*/ \
GEN(VDS_LEVEL, 0xC3) \
GEN(VDS_MODE , 0xC0) 


GENERATE_ENUM_AND_STRINGS(Name, FOREACH_Name);


#define FOREACH_BOOL(GEN) \
GEN(False, 0b00) \
GEN(True, 0b01)

GENERATE_ENUM_AND_STRINGS(BOOL, FOREACH_BOOL);


#define FOREACH_TDRIVE(GEN) \
GEN(TDRIVEN_220_ns, 0b00) 	\
GEN(TDRIVEN_440_ns, 0b01) 	\
GEN(TDRIVEN_880_ns, 0b10) 	\
GEN(TDRIVEN_1780_ns, 0b11)    

GENERATE_ENUM_AND_STRINGS(TDRIVE, FOREACH_TDRIVE);

#define FOREACH_IDRIVEN(GEN) \
GEN(IDRIVEN_20_mA, 0b0000) \
GEN(IDRIVEN_60_mA, 0b0100) \  
GEN(IDRIVEN_0_50_A, 0b1000) \ 
GEN(IDRIVEN_60_mA_a, 0b1100) \  
GEN(IDRIVEN_30_mA, 0b0001) \  
GEN(IDRIVEN_70_mA, 0b0101) \  
GEN(IDRIVEN_0_75_A, 0b1001) \ 
GEN(IDRIVEN_60_mA_b, 0b1101) \  
GEN(IDRIVEN_40_mA, 0b0010) \ 	
GEN(IDRIVEN_80_mA, 0b0110) \ 	
GEN(IDRIVEN_1_00_A, 0b1010) \ 	
GEN(IDRIVEN_60_mA_c, 0b1110) \ 	
GEN(IDRIVEN_50_mA, 0b0011) \
GEN(IDRIVEN_0_25_A, 0b0111) \
GEN(IDRIVEN_1_25_A, 0b1011) \
GEN(IDRIVEN_60_mA_d, 0b1111) \


GENERATE_ENUM_AND_STRINGS(IDRIVEN, FOREACH_IDRIVEN);

#define FOREACH_IDRIVEP(GEN) \
GEN(IDRIVEP_10_mA, 0b0000) \  
GEN(IDRIVEP_50_mA, 0b0100) \  
GEN(IDRIVEP_0_25_A, 0b1000) \ 
GEN(IDRIVEP_50_mA_a, 0b1100) \  
GEN(IDRIVEP_20_mA, 0b0001) \  
GEN(IDRIVEP_60_mA, 0b0101) \  
GEN(IDRIVEP_0_50_A, 0b1001) \ 
GEN(IDRIVEP_50_mA_b, 0b1101) \  
GEN(IDRIVEP_30_mA, 0b0010) \ 	
GEN(IDRIVEP_70_mA, 0b0110) \ 	
GEN(IDRIVEP_0_75_A, 0b1010) \ 	
GEN(IDRIVEP_50_mA_c, 0b1110) \ 	
GEN(IDRIVEP_40_mA, 0b0011) \
GEN(IDRIVEP_0_125_A, 0b0111) \ 
GEN(IDRIVEP_1_00_A, 0b1011) \
GEN(IDRIVEP_50_mA_d, 0b1111)

GENERATE_ENUM_AND_STRINGS(IDRIVEP, FOREACH_IDRIVEP);

#define FOREACH_COMM_OPTION(GEN) \
GEN(COMM_OPTION_diode_freewheeling, 0b0) \  
GEN(COMM_OPTION_active_freewheeling, 0b1)

GENERATE_ENUM_AND_STRINGS(COMM_OPTION, FOREACH_COMM_OPTION);

#define FOREACH_PWM_MODE(GEN) \
GEN(PWM_MODE_PWM_with_6_independent_inputs, 0b00) \
GEN(PWM_MODE_PWM_with_3_independent_inputs, 0b01) \	
GEN(PWM_MODE_PWM_with_one_input, 0b10) \	
GEN(PWM_MODE_PWM_with_6_independent_inputs_b, 0b11) 	

GENERATE_ENUM_AND_STRINGS(PWM_MODE, FOREACH_PWM_MODE);

#define FOREACH_DEAD_TIME(GEN) \
GEN(DEAD_TIME_35_ns, 0b000) \   
GEN(DEAD_TIME_440_ns, 0b011) \  
GEN(DEAD_TIME_3520_ns, 0b110) \ 
GEN(DEAD_TIME_52_ns, 0b001) \ 	
GEN(DEAD_TIME_880_ns, 0b100) \ 	
GEN(DEAD_TIME_5280_ns, 0b111) \
GEN(DEAD_TIME_88_ns, 0b010) \
GEN(DEAD_TIME_1760_ns, 0b101) 

GENERATE_ENUM_AND_STRINGS(DEAD_TIME, FOREACH_DEAD_TIME);


#define FOREACH_TBLANK(GEN) \
GEN(TBLANK_0_us, 0b00) \
GEN(TBLANK_1_75_us, 0b01)	\
GEN(TBLANK_3_5_us, 0b10) \
GEN(TBLANK_7_us, 0b11)

GENERATE_ENUM_AND_STRINGS(TBLANK, FOREACH_TBLANK);

#define FOREACH_TVDS(GEN) \
GEN(TVDS_0_us, 0b000) 	\
GEN(TVDS_1_75_us, 0b001) 	\
GEN(TVDS_3_5_us, 0b010) 	\
GEN(TVDS_7_us, 0b011)

GENERATE_ENUM_AND_STRINGS(TVDS, FOREACH_TVDS);


#define FOREACH_FLIP_OTSD(GEN) \
GEN(FLIP_OTSD_Disable_OTSD, 0b00)\
GEN(FLIP_OTSD_Enable_OTSD, 0b01)

GENERATE_ENUM_AND_STRINGS(FLIP_OTSD, FOREACH_FLIP_OTSD);

#define FOREACH_DIS_PVDD_UVLO2(GEN) \
GEN(DIS_PVDD_UVLO2_enabled, 0b00)\
GEN(DIS_PVDD_UVLO2_disabled, 0b01)

GENERATE_ENUM_AND_STRINGS(DIS_PVDD_UVLO2, FOREACH_DIS_PVDD_UVLO2);

#define FOREACH_DIS_GDRV_FAULT(GEN) \
GEN(DIS_GDRV_FAULT_Gate_driver_fault_enabled, 0b00)\
GEN(DIS_GDRV_FAULT_Gate_driver_fault_disabled, 0b01)

GENERATE_ENUM_AND_STRINGS(DIS_GDRV_FAULT, FOREACH_DIS_GDRV_FAULT);

#define FOREACH_EN_SNS_CLAMP(GEN) \
GEN(EN_SNS_CLAMP_Sense_amplifier_clamp_is_not_enabled, 0b00)\
GEN(EN_SNS_CLAMP_Sense_amplifier_clamp_is_enabled_limiting_output_to_approx_3_3_V, 0b01)

GENERATE_ENUM_AND_STRINGS(EN_SNS_CLAMP, FOREACH_EN_SNS_CLAMP);

#define FOREACH_WD_DLY(GEN) \
GEN(WD_DLY_10_ms, 0b00) \
GEN(WD_DLY_20_ms, 0b01) \
GEN(WD_DLY_50_ms, 0b10) \
GEN(WD_DLY_100_ms, 0b11)

GENERATE_ENUM_AND_STRINGS(WD_DLY, FOREACH_WD_DLY);

#define FOREACH_DIS_SNS_OCP(GEN) \
GEN(DIS_SNS_OCP_SNS_OCP_enabled, 0b00)\
GEN(DIS_SNS_OCP_SNS_OCP_disabled, 0b01)

GENERATE_ENUM_AND_STRINGS(DIS_SNS_OCP, FOREACH_DIS_SNS_OCP);

#define FOREACH_WD_EN(GEN) \
GEN(WD_EN_Watch_dog_enabled, 0b00)\
GEN(WD_EN_Watch_dog_disabled, 0b01)

GENERATE_ENUM_AND_STRINGS(WD_EN, FOREACH_WD_EN);

#define FOREACH_SLEEP(GEN) \
GEN(SLEEP_Device_awake, 0b00)\
GEN(SLEEP_Device_asleep, 0b01)

GENERATE_ENUM_AND_STRINGS(SLEEP, FOREACH_SLEEP);

#define FOREACH_CLR_FLTS(GEN) \
GEN(CLR_FLTS_Normal_operation, 0b00)\
GEN(CLR_FLTS_Clear_faults, 0b01)

GENERATE_ENUM_AND_STRINGS(CLR_FLTS, FOREACH_CLR_FLTS);

#define FOREACH_SET_VCPH_UV(GEN) \
GEN(SET_VCPH_UV_4_9_V, 0b00)\
GEN(SET_VCPH_UV_4_6_V, 0b01)

GENERATE_ENUM_AND_STRINGS(SET_VCPH_UV, FOREACH_SET_VCPH_UV);



#define FOREACH_DC_CAL(GEN) \
GEN(DC_CAL_Normal_operation, 0b00)\
GEN(DC_CAL_DC_calibration_mode, 0b01)

GENERATE_ENUM_AND_STRINGS(DC_CAL, FOREACH_DC_CAL);

#define FOREACH_CS_BLANK(GEN) \
GEN(CS_BLANK_0_ns, 0b00) \
GEN(CS_BLANK_500_ns, 0b01) \
GEN(CS_BLANK_2_5_us, 0b10) \
GEN(CS_BLANK_10_us, 0b11) 

GENERATE_ENUM_AND_STRINGS(CS_BLANK, FOREACH_CS_BLANK);


#define FOREACH_GAIN_CS(GEN) \
GEN(GAIN_CS_10_VperV, 0b00) \
GEN(GAIN_CS_20_VperV, 0b01) \
GEN(GAIN_CS_40_VperV, 0b10) \
GEN(GAIN_CS_80_VperV, 0b11) 

GENERATE_ENUM_AND_STRINGS(GAIN_CS, FOREACH_GAIN_CS);

#define FOREACH_VREF_SCALE(GEN) \
GEN(VREF_SCALE_RSVD, 0b00) \
GEN(VREF_SCALE_k_2, 0b01) \
GEN(VREF_SCALE_k_4, 0b10) \
GEN(VREF_SCALE_RSVD_b, 0b11) 

GENERATE_ENUM_AND_STRINGS(VREF_SCALE, FOREACH_VREF_SCALE);

#define FOREACH_SLEEP_DLY(GEN) \
GEN(SLEEP_DLY_0_us, 0b00) \
GEN(SLEEP_DLY_10_us, 0b01) \
GEN(SLEEP_DLY_50_us, 0b10) \
GEN(SLEEP_DLY_1_ms, 0b11) 

GENERATE_ENUM_AND_STRINGS(SLEEP_DLY, FOREACH_SLEEP_DLY);


#define FOREACH_DIS_VREG_PWRGD(GEN) \
GEN(DIS_VREG_PWRGD_VREG_UV_enabled, 0b00)\
GEN(DIS_VREG_PWRGD_VREG_UV_disabled, 0b01)

GENERATE_ENUM_AND_STRINGS(DIS_VREG_PWRGD, FOREACH_DIS_VREG_PWRGD);

#define FOREACH_VREG_UV_LEVEL(GEN) \
GEN(VREG_UV_LEVEL_VREGx0_9, 0b00) \
GEN(VREG_UV_LEVEL_VREGx0_8, 0b01) \
GEN(VREG_UV_LEVEL_VREGx0_7, 0b10) \
GEN(VREG_UV_LEVEL_VREGx0_7_b, 0b11) 

GENERATE_ENUM_AND_STRINGS(VREG_UV_LEVEL, FOREACH_VREG_UV_LEVEL);


#define FOREACH_VDS_LEVEL(GEN) \
GEN(VDS_LEVEL_0_060_V ,  0b000000) \
GEN(VDS_LEVEL_0_097_V ,  0b000100) \
GEN(VDS_LEVEL_0_155_V ,  0b001000) \
GEN(VDS_LEVEL_0_250_V ,  0b001100) \
GEN(VDS_LEVEL_0_403_V ,  0b010000) \
GEN(VDS_LEVEL_0_648_V ,  0b010100) \
GEN(VDS_LEVEL_1_043_V ,  0b011000) \
GEN(VDS_LEVEL_1_679_V ,  0b011100) \
GEN(VDS_LEVEL_0_068_V ,  0b00001) \
GEN(VDS_LEVEL_0_109_V ,  0b00101) \
GEN(VDS_LEVEL_0_175_V ,  0b01001) \
GEN(VDS_LEVEL_0_282_V ,  0b01101) \
GEN(VDS_LEVEL_0_454_V ,  0b10001) \
GEN(VDS_LEVEL_0_730_V ,  0b10101) \
GEN(VDS_LEVEL_1_175_V ,  0b11001) \
GEN(VDS_LEVEL_1_892_V ,  0b11101) \
GEN(VDS_LEVEL_0_076_V ,  0b00010) \
GEN(VDS_LEVEL_0_123_V ,  0b00110) \
GEN(VDS_LEVEL_0_197_V  ,  0b01010) \
GEN(VDS_LEVEL_0_317_V ,  0b01110) \
GEN(VDS_LEVEL_0_511_V ,  0b10010) \
GEN(VDS_LEVEL_0_822_V ,  0b10110) \
GEN(VDS_LEVEL_1_324_V ,  0b11010) \
GEN(VDS_LEVEL_2_131_V ,  0b11110) \
GEN(VDS_LEVEL_0_086_V,  0b00011) \
GEN(VDS_LEVEL_0_138_V,  0b00111) \
GEN(VDS_LEVEL_0_222_V,  0b01011) \
GEN(VDS_LEVEL_0_358_V,  0b01111) \
GEN(VDS_LEVEL_0_576_V,  0b10011) \
GEN(VDS_LEVEL_0_926_V,  0b10111) \
GEN(VDS_LEVEL_1_491_V,  0b11011) \
GEN(VDS_LEVEL_2_131_V_b,  0b11111)

GENERATE_ENUM_AND_STRINGS(VDS_LEVEL, FOREACH_VDS_LEVEL);

#define FOREACH_VDS_MODE(GEN) \
GEN(VDS_MODE_Latched_shut_down_when_over_current_detected, 0b00)\
GEN(VDS_MODE_Report_only_when_over_current_detected, 0b01)\
GEN(VDS_MODE_VDS_protection_disabled_no_overcurrent_sensing_or_reporting, 0b10)

GENERATE_ENUM_AND_STRINGS(VDS_MODE, FOREACH_VDS_MODE);


enum AccessMode: byte
{
    R,
    RW
};

class DRV8305RegisterSectionBase
{
	public:
		virtual void report(Stream & stream) = 0;
};

class RegisterBase
{
public:

	RegisterBase(uint8_t address) : address(address){}

	virtual void setConfig(int index, DRV8305RegisterSectionBase * config) = 0;

	void init(SPIClass * spi, SPISettings * settings, uint8_t cs)
	{
		// TODO make SPI speed configurable
		this->spi = spi;
		this->cs = cs;
		this->settings = settings;
	}


	uint16_t getValue(bool refresh = true)
	{
		if(refresh)
			this->poll();
		
		return this->value;
	}

	// returns old value
	uint16_t setValue(uint16_t newValue)
	{
		this->value = newValue;
		return commit();
	}

/*
Programming (continued) 

The SPI input data (SDI) control word is 16 bits long and consists of the following format: 

• 1 read or write bit W [15] 
• 4 address bits A [14:11] 
• 11 data bits D [10:0] 

The SPI output data (SDO) word response word is 11 bits long (first 5 bits are don't cares)
content of the register being accessed.


The MSB of the SDI word (W0) is the read/write bit. When W0 = 0, the input data is a write com
= 1, the input data is a read command. 

For a write command: The response word is the data currently in the register being written to. 
For a read command: The response word is the data currently in the register being read.

Table 6. SPI Input Data Control Word Format 

R/W  ADDRESS  DATA 
Word Bit  B15  B14  B13  B12  B11  B10  B9  B8  B7  B6  B5  B4  B3  B2  B1  B0 
Command   W0   A3   A2   A1   A0   D10  D9  D8  D7  D6  D5  D4  D3  D2  D1  D0 


DATA 
Word Bit  B15  B14  B13  B12  B11  B10  B9  B8  B7  B6  B5  B4  B3  B2  B1  B0 
Command   X    X    X    X    X    D10  D9  D8  D7  D6  D5  D4  D3  D2  D1  D0 
*/
//                                        0bFEDCBA9876543210
	static const uint16_t W0_read_bit   = 0b1000000000000000;
	static const uint16_t W0_write_mask = 0b0111111111111111;
	static const uint16_t data_mask     = 0b0000011111111111;

	void poll() 
	{
		if(spi == nullptr)
			return;

		digitalWrite(cs, LOW);
		spi->beginTransaction(*settings);
		uint16_t data = (address << 11) | W0_read_bit;
		value = spi->transfer16(data);
		spi->endTransaction();
		digitalWrite(cs, HIGH);
	}


	uint16_t commit() 
	{
		if(spi == nullptr)
			return 0xFFFF;

		digitalWrite(cs, LOW);
		spi->beginTransaction(*settings);
		uint16_t data = ((address<<11) | (value & data_mask)) & W0_write_mask;
		uint16_t oldData = spi->transfer16(data) & data_mask;
		spi->endTransaction();
		digitalWrite(cs, HIGH);
		return oldData;
	}
	SPIClass* spi = nullptr;
    SPISettings * settings;
	uint8_t cs;
	const uint8_t address;
	uint16_t value;
};

template<int Count>
class Register : public RegisterBase
{
public:
	Register(uint8_t address) : RegisterBase(address){}

	void report(Stream & stream, bool refresh = true)
	{
		if(spi == nullptr)
		{
			stream.print(F("Error: spi not initialized, please call init()"));
			return;
		}
		if(refresh)
			this->poll();

		stream.print(F("Report for register: "));
		stream.println(address, HEX);

		for(int i =- 0; i < Count; i++)
		{
			configs[i]->report(stream);
		}
	}

	void setConfig(int index, DRV8305RegisterSectionBase * config) override
	{
		if(index < Count)
			configs[index] = config;
	}

	DRV8305RegisterSectionBase * configs[Count];
};


template <typename ValueType
, int id
, byte BitStart
, byte BitMaskZero
, AccessMode Mode
, DRV8305RegisterName Name
, typename ToString>
class DRV8305RegisterSection : public DRV8305RegisterSectionBase
{
public:
    static const byte bitStart = BitStart;
    static const byte bitMask = BitMaskZero << BitStart;
    static const AccessMode mode = Mode;
    static const DRV8305RegisterName name = Name;

	RegisterBase * reg;
	DRV8305RegisterSection(ValueType defaultValue, const __FlashStringHelper * description, RegisterBase * reg) 
	: reg(reg), defaultValue(defaultValue), description(description)
	{
		reg->setConfig(id, this);
	}
    ValueType defaultValue;
	ValueType value(bool refresh = false)
	{
		return (ValueType)((reg->getValue(refresh) & bitMask) >> BitStart);
	}
	void setValue(ValueType value)
	{
		reg->setValue((reg->value(false) & ~bitMask) | (value << BitStart)); 
	}

	void report(Stream & stream) override
	{
		ValueType v = value();
		stream.print(DRV8305RegisterNameToString::toString(name));
		stream.print(" (");
		stream.print(description);
		stream.print("): ");
		stream.print(ToString::toString(v));
		stream.print(" (0b");
		stream.print(v, BIN);
		stream.println("): ");
	}
    const __FlashStringHelper * description;
};



// 7.6.1.1 Warning and Watchdog Reset (Address = 0x1) 
// Table 9. Warning and Watchdog Reset Register Description 
// BIT  RW  NAME  DEFAULT  DESCRIPTION 

class WarningAndWatchdog : public Register<10>
{

public:
	WarningAndWatchdog(): Register(0x01),
	FAULT_(False,  		F("Fault indication"), this),
	TEMP_FLAG4_(False,  F("Temperature flag setting for approximately 175°C"), this),
	PVDD_UVFL_(False,   F("PVDD undervoltage flag warning"), this),
	PVDD_OVFL_(False,   F("PVDD overvoltage flag warning"), this),
	VDS_STATUS_(False,  F("Real time OR of all VDS overcurrent monitors"), this),
	VCHP_UVFL_(False,   F("Charge pump undervoltage flag warning"), this),
	TEMP_FLAG1_(False,  F("Temperature flag setting for approximately 105°C"), this),
	TEMP_FLAG2_(False,  F("Temperature flag setting for approximately 125°C"), this),
	TEMP_FLAG3_(False,  F("Temperature flag setting for approximately 135°C"), this),
	OTW_(False,  		F("Overtemperature warning"), this){}

	DRV8305RegisterSection<DRV8305RegisterBOOL, 0, 10,  0b1, R,  FAULT, DRV8305RegisterBOOLToString> FAULT_;
	DRV8305RegisterSection<DRV8305RegisterBOOL, 1, 8,   0b1, R,  TEMP_FLAG4, DRV8305RegisterBOOLToString> TEMP_FLAG4_;
	DRV8305RegisterSection<DRV8305RegisterBOOL, 2, 7,   0b1, R,  PVDD_UVFL, DRV8305RegisterBOOLToString> PVDD_UVFL_;
	DRV8305RegisterSection<DRV8305RegisterBOOL, 3, 6,   0b1, R,  PVDD_OVFL, DRV8305RegisterBOOLToString> PVDD_OVFL_;
	DRV8305RegisterSection<DRV8305RegisterBOOL, 4, 5,   0b1, R,  VDS_STATUS, DRV8305RegisterBOOLToString> VDS_STATUS_;
	DRV8305RegisterSection<DRV8305RegisterBOOL, 5, 4,   0b1, R,  VCHP_UVFL, DRV8305RegisterBOOLToString> VCHP_UVFL_;
	DRV8305RegisterSection<DRV8305RegisterBOOL, 6, 3,   0b1, R,  TEMP_FLAG1, DRV8305RegisterBOOLToString> TEMP_FLAG1_;
	DRV8305RegisterSection<DRV8305RegisterBOOL, 7, 2,   0b1, R,  TEMP_FLAG2, DRV8305RegisterBOOLToString> TEMP_FLAG2_;
	DRV8305RegisterSection<DRV8305RegisterBOOL, 8, 1,   0b1, R,  TEMP_FLAG3, DRV8305RegisterBOOLToString> TEMP_FLAG3_;
	DRV8305RegisterSection<DRV8305RegisterBOOL, 9, 0,   0b1, R,  OTW, DRV8305RegisterBOOLToString> OTW_;
};
// 7.6.1.2 OV/VDS Faults (Address = 0x2) 
// Table 10. OV/VDS Faults Register Description 
// BIT 	RW 	NAME  DEFAULT  DESCRIPTION
class OVandVDSFaults : public Register<9>
{

public: 
	OVandVDSFaults(): Register(0x02),
	VDS_HA_(False,  	F("VDS overcurrent fault for high-side MOSFET A"), this),
	VDS_LA_(False,  	F("VDS overcurrent fault for low-side MOSFET A"), this),
	VDS_HB_(False,  	F("VDS overcurrent fault for high-side MOSFET B"), this),
	VDS_LB_(False,  	F("VDS overcurrent fault for low-side MOSFET B"), this),
	VDS_HC_(False,  	F("VDS overcurrent fault for high-side MOSFET C"), this),
	VDS_LC_(False,  	F("VDS overcurrent fault for low-side MOSFET C"), this),
	SNS_C_OCP_(False,  	F("Sense C overcurrent fault"), this),
	SNS_B_OCP_(False,  	F("Sense B overcurrent fault"), this),
	SNS_A_OCP_(False,  	F("Sense A overcurrent fault"), this){}

	
	
	DRV8305RegisterSection<DRV8305RegisterBOOL, 0, 10, 0b1, 	R, 	VDS_HA, DRV8305RegisterBOOLToString> VDS_HA_;
	DRV8305RegisterSection<DRV8305RegisterBOOL, 1, 9,  0b1, 	R, 	VDS_LA, DRV8305RegisterBOOLToString> VDS_LA_;
	DRV8305RegisterSection<DRV8305RegisterBOOL, 2, 8,  0b1, 	R, 	VDS_HB, DRV8305RegisterBOOLToString> VDS_HB_;
	DRV8305RegisterSection<DRV8305RegisterBOOL, 3, 7,  0b1, 	R, 	VDS_LB, DRV8305RegisterBOOLToString> VDS_LB_;
	DRV8305RegisterSection<DRV8305RegisterBOOL, 4, 6,  0b1, 	R, 	VDS_HC, DRV8305RegisterBOOLToString> VDS_HC_;
	DRV8305RegisterSection<DRV8305RegisterBOOL, 5, 5,  0b1, 	R, 	VDS_LC, DRV8305RegisterBOOLToString> VDS_LC_;
	DRV8305RegisterSection<DRV8305RegisterBOOL, 6, 2,  0b1, 	R, 	SNS_C_OCP, DRV8305RegisterBOOLToString> SNS_C_OCP_;
	DRV8305RegisterSection<DRV8305RegisterBOOL, 7, 1,  0b1, 	R, 	SNS_B_OCP, DRV8305RegisterBOOLToString> SNS_B_OCP_;
	DRV8305RegisterSection<DRV8305RegisterBOOL, 8, 0,  0b1, 	R, 	SNS_A_OCP, DRV8305RegisterBOOLToString> SNS_A_OCP_;
};

// 7.6.1.3 IC Faults (Address = 0x3) 
// Table 11. IC Faults Register Description 
// BIT  RW  NAME  DEFAULT  DESCRIPTION 

class ICFaults: public Register<9>
{

public:
	ICFaults(): Register(0x03),
	PVDD_UVLO2_(False,  	F("PVDD undervoltage 2 fault"), this),
	WD_FAULT_(False,  		F("Watchdog fault"), this),
	OTSD_(False,  			F("Overtemperature fault"), this),
	VREG_UV_(False,  		F("VREG undervoltage fault"), this),
	AVDD_UVLO_(False,  		F("AVDD undervoltage fault"), this),
	VCP_LSD_UVLO2_(False,  	F("Low-side gate supply fault"), this),
	VCPH_UVLO2_(False,  	F("High-side charge pump undervoltage 2 fault"), this),
	VCPH_OVLO_(False,  		F("High-side charge pump overvoltage fault"), this),
	VCPH_OVLO_ABS_(False,  	F("High-side charge pump overvoltage ABS fault"), this){}

	DRV8305RegisterSection<DRV8305RegisterBOOL, 0, 10, 0b1,  R,  PVDD_UVLO2, DRV8305RegisterBOOLToString> PVDD_UVLO2_;
	DRV8305RegisterSection<DRV8305RegisterBOOL, 1, 9,  0b1,  R,  WD_FAULT, DRV8305RegisterBOOLToString> WD_FAULT_;
	DRV8305RegisterSection<DRV8305RegisterBOOL, 2, 8,  0b1,  R,  OTSD, DRV8305RegisterBOOLToString> OTSD_;
	DRV8305RegisterSection<DRV8305RegisterBOOL, 3, 6,  0b1,  R,  VREG_UV, DRV8305RegisterBOOLToString> VREG_UV_;
	DRV8305RegisterSection<DRV8305RegisterBOOL, 4, 5,  0b1,  R,  AVDD_UVLO, DRV8305RegisterBOOLToString> AVDD_UVLO_;
	DRV8305RegisterSection<DRV8305RegisterBOOL, 5, 4,  0b1,  R,  VCP_LSD_UVLO2, DRV8305RegisterBOOLToString> VCP_LSD_UVLO2_;
	DRV8305RegisterSection<DRV8305RegisterBOOL, 6, 2,  0b1,  R,  VCPH_UVLO2, DRV8305RegisterBOOLToString> VCPH_UVLO2_;
	DRV8305RegisterSection<DRV8305RegisterBOOL, 7, 1,  0b1,  R,  VCPH_OVLO, DRV8305RegisterBOOLToString> VCPH_OVLO_;
	DRV8305RegisterSection<DRV8305RegisterBOOL, 8, 0,  0b1,  R,  VCPH_OVLO_ABS, DRV8305RegisterBOOLToString> VCPH_OVLO_ABS_;
};

// 7.6.1.4 VGS Faults (Address = 0x4) 
// Table 12. Gate Driver VGS Faults Register Description 
// BIT  RW  NAME  DEFAULT  DESCRIPTION 

class GateDriverVGSFaults : public Register<6>
{
public:
	GateDriverVGSFaults(): Register(0x04),
	VGS_HA_(False,  F("VGS gate drive fault for high-side MOSFET A"), this),
	VGS_LA_(False,  F("VGS gate drive fault for low-side MOSFET A"), this),
	VGS_HB_(False,  F("VGS gate drive fault for high-side MOSFET B"), this),
	VGS_LB_(False,  F("VGS gate drive fault for low-side MOSFET B"), this),
	VGS_HC_(False,  F("VGS gate drive fault for high-side MOSFET C"), this),
	VGS_LC_(False,  F("VGS gate drive fault for low-side MOSFET C"), this){}

	
	
	
	
	DRV8305RegisterSection<DRV8305RegisterBOOL, 0, 10, 0b1,  R,  VGS_HA, DRV8305RegisterBOOLToString> VGS_HA_;
	DRV8305RegisterSection<DRV8305RegisterBOOL, 1, 9,  0b1,  R,  VGS_LA, DRV8305RegisterBOOLToString> VGS_LA_;
	DRV8305RegisterSection<DRV8305RegisterBOOL, 2, 8,  0b1,  R,  VGS_HB, DRV8305RegisterBOOLToString> VGS_HB_;
	DRV8305RegisterSection<DRV8305RegisterBOOL, 3, 7,  0b1,  R,  VGS_LB, DRV8305RegisterBOOLToString> VGS_LB_;
	DRV8305RegisterSection<DRV8305RegisterBOOL, 4, 6,  0b1,  R,  VGS_HC, DRV8305RegisterBOOLToString> VGS_HC_;
	DRV8305RegisterSection<DRV8305RegisterBOOL, 5, 5,  0b1,  R,  VGS_LC, DRV8305RegisterBOOLToString> VGS_LC_;
};

// 7.6.2 Control Registers 
// Control registers are used to set the device parameters for DRV8305-Q1. The default values are shown in bold. 
// • Control registers are read/write registers 
// • Do not clear on register read, CLR_FLTs, or EN_GATE resets 
// • Cleared to default values on power up 
// • Cleared to default values when the device enters SLEEP mode 
// 7.6.2.1  HS Gate Drive Control (Address = 0x5) 
// Table 13. HS Gate Driver Control Register Description 

class HSGateControl : public Register<3>
{
public: 
	HSGateControl(): Register(0x05),
	TDRIVEN_(TDRIVEN_1780_ns, 	F("High-side gate driver peak source time"), this),
	IDRIVEN_HS_(IDRIVEN_60_mA, 	F("High-side gate driver peak sink current"), this),
	IDRIVEP_HS_(IDRIVEP_0_25_A, F("High-side gate driver peak source current"), this){}
	
	DRV8305RegisterSection<DRV8305RegisterTDRIVE,  0, 8 	, 0b11,   RW, 	TDRIVEN, DRV8305RegisterTDRIVEToString>    TDRIVEN_;
	DRV8305RegisterSection<DRV8305RegisterIDRIVEN, 1, 4 	, 0b1111, RW, 	IDRIVEN_HS, DRV8305RegisterIDRIVENToString> IDRIVEN_HS_;
	DRV8305RegisterSection<DRV8305RegisterIDRIVEP, 2, 0 	, 0b1111, RW, 	IDRIVEP_HS, DRV8305RegisterIDRIVEPToString> IDRIVEP_HS_;
};
// 7.6.2.2  LS Gate Drive Control (Address = 0x6) 
// Table 14. LS Gate Driver Control Register Description 	

class LSGateControl : public Register<3>
{
public: 
	LSGateControl(): Register(0x06),
	TDRIVEN_(TDRIVEN_1780_ns, 	F("Low-side gate driver peak source time"), this),
	IDRIVEN_LS_(IDRIVEN_60_mA, 	F("Low-side gate driver peak sink current"), this),
	IDRIVEP_LS_(IDRIVEP_0_25_A, F("Low-side gate driver peak source current"), this){}
	
	DRV8305RegisterSection<DRV8305RegisterTDRIVE,  0, 8 	, 0b11,   RW, 	TDRIVEN, DRV8305RegisterTDRIVEToString>    TDRIVEN_;
	DRV8305RegisterSection<DRV8305RegisterIDRIVEN, 1, 4 	, 0b1111, RW, 	IDRIVEN_LS, DRV8305RegisterIDRIVENToString> IDRIVEN_LS_;
	DRV8305RegisterSection<DRV8305RegisterIDRIVEP, 2, 0 	, 0b1111, RW, 	IDRIVEP_LS, DRV8305RegisterIDRIVEPToString> IDRIVEP_LS_;
};


// 7.6.2.3  Gate Drive Control (Address = 0x7) 	
// Table 15. Gate Drive Control Register Description 	
class GateDriveControl : public Register<5>
{

public:
	GateDriveControl(): Register(0x07),
	COMM_OPTION_(COMM_OPTION_active_freewheeling, 		F("Rectification control (PWM_MODE = b'10 only"), this),
	PWM_MODE_(PWM_MODE_PWM_with_6_independent_inputs, 	F("PWM Mode"), this),
	DEAD_TIME_(DEAD_TIME_52_ns, 						F("Dead time"), this),
	TBLANK_(TBLANK_1_75_us, 							F("VDS sense blanking"), this),
	TVDS_(TVDS_3_5_us, 									F("VDS sense deglitch"), this)
	{}

	DRV8305RegisterSection<DRV8305RegisterCOMM_OPTION, 0, 9,  0b1, 	RW, 	COMM_OPTION, DRV8305RegisterCOMM_OPTIONToString> COMM_OPTION_;
	DRV8305RegisterSection<DRV8305RegisterPWM_MODE,    1, 8,  0b11, 	RW, 	PWM_MODE, DRV8305RegisterPWM_MODEToString> PWM_MODE_;
	DRV8305RegisterSection<DRV8305RegisterDEAD_TIME,   2, 5,  0b111, 	RW, 	DEAD_TIME, DRV8305RegisterDEAD_TIMEToString> DEAD_TIME_;
	DRV8305RegisterSection<DRV8305RegisterTBLANK,      3, 3,  0b11, 	RW, 	TBLANK, DRV8305RegisterTBLANKToString> TBLANK_;
	DRV8305RegisterSection<DRV8305RegisterTVDS,        4, 1,  0b11, 	RW, 	TVDS, DRV8305RegisterTVDSToString> TVDS_;
};

// 7.6.2.4  IC Operation (Address = 0x9) 
// Table 16. IC Operation Register Description 

class ICOperation : public Register<10>
{

public:
	ICOperation(): Register(0x09),
	FLIP_OTSD_(FLIP_OTSD_Disable_OTSD, 								F("Enable OTSD"), this),
	DIS_PVDD_UVLO2_(DIS_PVDD_UVLO2_enabled, 						F("Disable PVDD_UVLO2 fault and reporting"), this),
	DIS_GDRV_FAULT_(DIS_GDRV_FAULT_Gate_driver_fault_enabled, 		F("Disable gate drive fault and reporting"), this),
	EN_SNS_CLAMP_(EN_SNS_CLAMP_Sense_amplifier_clamp_is_not_enabled,F("Enable sense amplifier clamp"), this),
	WD_DLY_(WD_DLY_20_ms, 											F("Watchdog delay"), this),
	DIS_SNS_OCP_(DIS_SNS_OCP_SNS_OCP_enabled, 						F("Disable SNS overcurrent protection fault and reporting"), this),
	WD_EN_(WD_EN_Watch_dog_enabled, 								F("Watchdog enable"), this),
	SLEEP_(SLEEP_Device_awake, 										F("Put device into sleep mode"), this),
	CLR_FLTS_(CLR_FLTS_Normal_operation, 							F("Clear faults"), this),
	SET_VCPH_UV_(SET_VCPH_UV_4_9_V, 								F("Set charge pump undervoltage threshold level"), this)
	{}
	
	
	
	
	DRV8305RegisterSection<DRV8305RegisterFLIP_OTSD, 		0, 10, 0b1,    RW, 	FLIP_OTSD, DRV8305RegisterFLIP_OTSDToString> FLIP_OTSD_;
	DRV8305RegisterSection<DRV8305RegisterDIS_PVDD_UVLO2, 	1, 9,  0b1, 	RW, 	DIS_PVDD_UVLO2, DRV8305RegisterDIS_PVDD_UVLO2ToString> DIS_PVDD_UVLO2_;
	DRV8305RegisterSection<DRV8305RegisterDIS_GDRV_FAULT, 	2, 8,  0b1, 	RW, 	DIS_GDRV_FAULT, DRV8305RegisterDIS_GDRV_FAULTToString> DIS_GDRV_FAULT_;
	DRV8305RegisterSection<DRV8305RegisterEN_SNS_CLAMP, 	3, 7,  0b1, 	RW, 	EN_SNS_CLAMP, DRV8305RegisterEN_SNS_CLAMPToString> EN_SNS_CLAMP_;
	DRV8305RegisterSection<DRV8305RegisterWD_DLY, 			4, 5,  0b11, 	RW, 	WD_DLY, DRV8305RegisterWD_DLYToString> WD_DLY_;
	DRV8305RegisterSection<DRV8305RegisterDIS_SNS_OCP, 	5, 4,  0b1, 	RW, 	DIS_SNS_OCP, DRV8305RegisterDIS_SNS_OCPToString> DIS_SNS_OCP_;
	DRV8305RegisterSection<DRV8305RegisterWD_EN, 			6, 3,  0b1, 	RW, 	WD_EN, DRV8305RegisterWD_ENToString> WD_EN_;
	DRV8305RegisterSection<DRV8305RegisterSLEEP, 			7, 2,  0b1, 	RW, 	SLEEP, DRV8305RegisterSLEEPToString> SLEEP_;
	DRV8305RegisterSection<DRV8305RegisterCLR_FLTS, 		8, 1,  0b1, 	RW, 	CLR_FLTS, DRV8305RegisterCLR_FLTSToString> CLR_FLTS_;
	DRV8305RegisterSection<DRV8305RegisterSET_VCPH_UV, 	9, 0,  0b1, 	RW, 	SET_VCPH_UV, DRV8305RegisterSET_VCPH_UVToString> SET_VCPH_UV_;
};

// 7.6.2.5  Shunt Amplifier Control (Address = 0xA) 
// Table 17. Shunt Amplifier Control Register Description 

class ShuntAmplifierControl: public Register<7>
{
public: 
	ShuntAmplifierControl(): Register(0x0A),
	DC_CAL_CH3_(DC_CAL_Normal_operation, 	F("DC calibration of CS amplifier 3"), this),
	DC_CAL_CH2_(DC_CAL_Normal_operation, 	F("DC calibration of CS amplifier 2"), this),
	DC_CAL_CH1_(DC_CAL_Normal_operation, 	F("DC calibration of CS amplifier 1"), this),
	CS_BLANK_(CS_BLANK_0_ns, 				F("Current shunt amplifier blanking time"), this),
	GAIN_CS3_(GAIN_CS_10_VperV, 			F("Gain of CS amplifier 3"), this),
	GAIN_CS2_(GAIN_CS_10_VperV, 			F("Gain of CS amplifier 2"), this),
	GAIN_CS1_(GAIN_CS_10_VperV, 			F("Gain of CS amplifier 1"), this)
	{}
	
	
	
	DRV8305RegisterSection<DRV8305RegisterDC_CAL,   0, 10, 0b1,    RW, 	DC_CAL_CH3, DRV8305RegisterDC_CALToString> DC_CAL_CH3_;
	DRV8305RegisterSection<DRV8305RegisterDC_CAL,   1, 9,  0b1, 	RW, 	DC_CAL_CH2, DRV8305RegisterDC_CALToString> DC_CAL_CH2_;
	DRV8305RegisterSection<DRV8305RegisterDC_CAL,   2, 8,  0b1, 	RW, 	DC_CAL_CH1, DRV8305RegisterDC_CALToString> DC_CAL_CH1_;
	DRV8305RegisterSection<DRV8305RegisterCS_BLANK, 3, 6,  0b11, 	RW, 	CS_BLANK, DRV8305RegisterCS_BLANKToString> CS_BLANK_;
	DRV8305RegisterSection<DRV8305RegisterGAIN_CS,  4, 4,  0b11, 	RW, 	GAIN_CS3, DRV8305RegisterGAIN_CSToString> GAIN_CS3_;
	DRV8305RegisterSection<DRV8305RegisterGAIN_CS,  5, 2,  0b11, 	RW, 	GAIN_CS2, DRV8305RegisterGAIN_CSToString> GAIN_CS2_;
	DRV8305RegisterSection<DRV8305RegisterGAIN_CS,  6, 0,  0b11, 	RW, 	GAIN_CS1, DRV8305RegisterGAIN_CSToString> GAIN_CS1_;
};


// 7.6.2.6  Voltage Regulator Control (Address = 0xB) 
// Table 18. Voltage Regulator Control Register Description 

class VoltageRegulatorControl : public Register<4>
{
public:
	VoltageRegulatorControl(): Register(0x0B),
	VREF_SCALE_(VREF_SCALE_k_2, 					F("VREF Scaling"), this),
	SLEEP_DLY_(SLEEP_DLY_10_us, 					F("Delay to power down VREG after SLEEP"), this),
	DIS_VREG_PWRGD_(DIS_VREG_PWRGD_VREG_UV_enabled, F("Disable VREG undervoltage fault and reporting"), this),
	VREG_UV_LEVEL_(VREG_UV_LEVEL_VREGx0_7, 			F("VREG undervoltage set point"), this){}

	DRV8305RegisterSection<DRV8305RegisterVREF_SCALE, 		0, 8,  0b11, 	RW, 	VREF_SCALE, DRV8305RegisterVREF_SCALEToString> VREF_SCALE_;
	DRV8305RegisterSection<DRV8305RegisterSLEEP_DLY, 		1, 3,  0b11, 	RW, 	SLEEP_DLY, DRV8305RegisterSLEEP_DLYToString> SLEEP_DLY_;
	DRV8305RegisterSection<DRV8305RegisterDIS_VREG_PWRGD, 	2, 2,  0b1, 	RW, 	DIS_VREG_PWRGD, DRV8305RegisterDIS_VREG_PWRGDToString> DIS_VREG_PWRGD_;
	DRV8305RegisterSection<DRV8305RegisterVREG_UV_LEVEL, 	3, 0,  0b11, 	RW, 	VREG_UV_LEVEL, DRV8305RegisterVREG_UV_LEVELToString> VREG_UV_LEVEL_;
};


//7.6.2.7  VDS Sense Control (Address = 0xC) 
//Table 19. VDS Sense Control Register Description 
class VDSSenseControl : public Register<2>
{
	public:
	VDSSenseControl(): Register(0x0C),
	VDS_LEVEL_(VDS_LEVEL_0_576_V, 										F("VDS comparator threshold"), this), 
	VDS_MODE_(VDS_MODE_Latched_shut_down_when_over_current_detected, 	F("VDS mode"), this){}

	DRV8305RegisterSection<DRV8305RegisterVDS_LEVEL, 0, 3, 0b11111, 	RW, 	VDS_LEVEL, DRV8305RegisterVDS_LEVELToString> VDS_LEVEL_;
	DRV8305RegisterSection<DRV8305RegisterVDS_MODE,  1, 0, 0b111, 	RW, 	VDS_MODE, DRV8305RegisterVDS_MODEToString> VDS_MODE_;
};
