//In this exercise, you will be measuring the analog voltage
//emitted by the potentiometer and displaying that value
//on the terminal screen.

//Because the Raspberry Pi lacks an internal ADC, we will use
//the Adafruit ADS1015 12 Bit ADC.

//The ADS1015 communicates with the Raspberry Pi through
//I2C communication protocol.

//Complete the given function and use it to measure the
//voltage emitted by the potentiometer.

//Reference the lab supplement ads1015.pdf and I2CProtocol.pdf
//for more details on the Adafruit ADS1015 12 Bit converter
//and I2C protocol.


//Use g++ -std=c++11 -o <Filename> <Filename.cpp> -lwiringPi

#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <signal.h>
#include <stdlib.h>
using namespace std;

int adcVal();
int adc;
void stop(int);

int main(){
	//Initialize the wiringPi Library.
	wiringPiSetup();

	while(true){
		signal(SIGINT, stop);
		//Read value from ADC

		//Print value to screen.

		//Convert data to milliVolts.

		//Slow the script speed down to gain better measurements.
		usleep(20000);
	}
}

int adcVal(){
	//Open connection to ADC.
	adc = wiringPiI2CSetup((uint8_t)/*Address of ADS1015(HEX)*/);
	//Send start byte (7 bit device address followed by a 0).
	wiringPiI2CWrite(adc,  (uint8_t)/*Device Address followed by a 0(HEX)*/);
	//Write to the configuration register.
	//Details in lab supplement <ads1015.pdf>.
	wiringPiI2CWriteReg16(adc, (uint8_t)/*Configuration Register(HEX)*/, (uint8_t)0xC183);
	//Close connection to ADC.
	close(adc);

	//Wait for ADC conversion to complete.
	usleep(1000);

	//Open connection to ADC.
	adc = wiringPiI2CSetup((uint8_t)/*Device Address of ADS1015(HEX)*/);
	//Send start byte(7 bit device address followed by a 0).
	wiringPiI2CWrite(adc,  (uint8_t)/*Device Address followed by a 0(HEX)*/);
	//Write to conversion register.
	wiringPiI2CWrite(adc,  (uint8_t)/*Conversion Register(HEX)*/);
	//Close connection to ADC.
	close(adc);

	//Open connection to ADC.
	adc = wiringPiI2CSetup((uint8_t)/*Device Address of ADS1015(HEX)*/);
	//Send start byte (7 bit device address followed by a 1).
	wiringPiI2CWrite(adc,  (uint8_t)/*Device Address followed by a 1(HEX)*/);
	//Read two bytes of data from the conversion register.
	uint16_t data = wiringPiI2CReadReg16(adc, (uint8_t)/*Conversion Register(HEX)*/);
	int  low, high, value;
    low = (data & 0xFF00) >> 8;
    high = (data & 0x00FF) << 8;
    data = high | low;
    if(value>>15 == 1){
		cout<< data<<endl;
        data = 0;
    }
    else
        data = data >> 4;
	//Close connection to ADC.
	close(adc);

	return data;
}

void stop(int sig){exit(1);}