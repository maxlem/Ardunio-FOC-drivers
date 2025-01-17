# SimpleFOC Driver and Support Library

This library contains an assortment of drivers and supporting code for SimpleFOC.

The intent is to keep the core of SimpleFOC clean, and thus easy to maintain, understand and port to different platforms. In addition to this core, there are various drivers and supporting code which has grown around SimpleFOC, and which we would like to make available to the community.

## What's contained

What's here? See the sections below. Each driver or function should come with its own more detailed README.

### Motor/Gate driver ICs

[DRV8316 driver](src/drivers/drv8316/) - SPI driver for TI's DRV8316 motor driver IC.

### Encoders

[AS5048A SPI driver](src/encoders/as5048a/) - SPI driver for the AMS AS5048A absolute position magnetic rotary encoder IC.



## How to use

#### Arduino Library Manager 
The simplest way to get hold of the library is directly by using Arduino IDE and its integrated Library Manager. 
- Open Arduino IDE and start Arduino Library Manager by clicking: `Tools > Manage Libraries...`.
- Search for `Simple FOC drivers` library and install the latest version.
- Reopen Arduino IDE and you should have the library examples in `File > Examples > Simple FOC drivers`.

#### Using Github website 
- Go to the [github repository](https://github.com/simplefoc/Arduino-FOC-drivers)
- Click first on `Clone or Download > Download ZIP`. 
- Unzip it and place it in `Arduino Libraries` folder. Windows: `Documents > Arduino > libraries`.  
- Reopen Arduino IDE and you should have the library examples in `File > Examples > Simple FOC drivers`.

#### Using parts

You can copy parts of the library, for example to minimize your code size, or make it easier to add adaptations of your own.
If you do so, please be sure to adhere to and include the [LICENSE](https://github.com/simplefoc/Arduino-FOC-drivers/LICENSE).


## Further Documentation

Find out more information about the Arduino SimpleFOC project on the [docs website](https://docs.simplefoc.com/) 
