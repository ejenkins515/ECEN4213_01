//In this exercise, you will be measuring the analog
//voltages of a compounded circuit.

//Use your code from previous exercises to perform this.

//Print the values to the terminal screen.

//Thoroughly comment your code and demonstrate to the
//lab instructor.

//Use g++ -std=c++11 -o <Filename> <Filename.cpp> -lwiringPi

#include <iostream>
#include <unistd.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <signal.h>
#include <stdlib.h>
using namespace std;


int adc;
int ratio;
void stop(int);

int main(){
	//Initialize the wiringPi Library.
	signal(SIGINT, stop(){exit(1);}
	wiringPiSetup();

	//Set mode of digital pins.

	while(true){

		//Place the values for 0 - 15 here.
	}
}


double adcVal(){
	//Open connection to ADC.
	adc = wiringPiI2CSetup((uint8_t)/*Device Address of ADS1015(HEX)*/);
	//Send start byte (7 bit device address followed by a 0).
	wiringPiI2CWrite(adc,  (uint8_t)/*Device Address followed by a 0(HEX)*/);
	//Write to the configuration register.
	wiringPiI2CWriteReg16(adc, (uint8_t)/*Configuration Register(HEX)*/, (uint8_t)0xC383);
	//Close connection to ADC.
	close(adc);

	//Wait for ADC conversion to complete.
	usleep(1000);

	//Open connection to ADC.
	adc = wiringPiI2CSetup((uint8_t)/*Device Address of ADS1015(HEX)*/);
	//Send start byte (7 bit device address followed by a 0).
	wiringPiI2CWrite(adc,  (uint8_t)/*Device Address followed by a 0(HEX)*/);
	//Write to the conversion register.
	wiringPiI2CWrite(adc,  (uint8_t))/*Conversion Register(HEX)*/);
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

	//Return value of conversion
	return ((double)data / 2047  * 4.096);

}

void stop(int sig){exit(1);}