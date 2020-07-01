//Same code as my original assignment but this is where I tested it to see if it was working or not.
#include <iostream>
#include <math.h>
#include "wav.hpp"


int main(){
	WavSound sound1;//helper 
	int sampleRate = 44100;
	cout<<"sampleRate = "<<sampleRate<<endl;
	double dt = 1.0/((double) sampleRate);
	cout<<" sampling interval ="<<dt<<endl;
	double duration = 0.55;//tone duration//
	int repeats = 20;
	int toneSamples = (int)(duration / dt);
	cout<<"toneSamples="<<toneSamples<<endl;
	const int nSamples = sampleRate * duration * repeats;
	cout<<"nSamples="<<nSamples<<endl;
	double frequency1 = 0.0; 
	int* waveform1 = new int[nSamples];
	int count = 0;
		
	for (int i_repeats = 0; i_repeats < repeats ; i_repeats++)
	{
		for (int i = 0; i < toneSamples ; i++)
		{
			double time1 =((double)dt)*count;
			//frequency1 = i_repeats%5 == 0 ? 750.0 : 950 ;
			if(i_repeats%2==0){
				frequency1=750.0;
			}else{
			frequency1=950.0;}
			
			waveform1[count] = 5000 * sin(2*M_PI * frequency1 * time1);
			count++;
	}
	}
	
	sound1.MakeWavFromInt("firetest.wav",sampleRate, waveform1, nSamples);
	delete (waveform1);
	return 0;
}
