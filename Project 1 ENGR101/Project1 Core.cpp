#include <iostream>
#include <math.h>
#include "wav.hpp"

int main(){
	WavSound sound1; //helper
	int sampleRate = 44100;
	cout<<"sampleRate = "<<sampleRate<<endl;
	int duration = 20;
	double dt = 1.0/44100;
	int nSamples = duration * sampleRate;
	int frequency = 5000;
	int* waveform = new int[nSamples];
	
	for (int iSample = 0; iSample < nSamples ; iSample++){
		double time = iSample *dt;
		double v = 5000 * sin(2*M_PI * frequency * time);
		waveform[iSample]=v;
		}
		
	sound1.MakeWavFromInt("tone1.wav", sampleRate, waveform, nSamples);
	delete(waveform);
	return 0;
}
