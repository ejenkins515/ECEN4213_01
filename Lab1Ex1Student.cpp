//In this exercise, you will make an LED counter which will
//Count in binary from 0 to 15, or from 0000 to 1111.

//Use the digital I/O pins on the Raspberry Pi to send
//power to the LED. Complete the circuit as listed in
//the lab document.

//Thoroughly comment your code and demonstrate to the lab inststructor.


//Use g++ -std=c++11 -o <Filename> <Filename.cpp> -lwiringPi

#include <iostream>
#include <unistd.h>
#include <wiringPi.h>
#include <signal.h>
#include <stdlib.h>
using namespace std;

void stop(int);

int main(){
	//Initialize the wiringPi library.
	signal(SIGINT, stop);
	wiringPiSetup();

	//Set digital pins to output.
	//Use pinMode(PIN, MODE);

	//Create each sequence and count from 0 to 15.
	//Use digitalWrite(PIN, MODE);

	//Create a 1 second delay after each sequence.
	//Use usleep(us) for the delay.
}

void stop(int sig){exit(1);}
