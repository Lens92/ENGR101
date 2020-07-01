#include <iostream> 
#include <math.h> 
#include "wav.hpp" 
 
using namespace std; 
 
int main(){ 
   WavSound sound1; // helper 
   int sampleRate = 41400; // samples per second  
   // your code goes here 
   int duration = 20;
   double dt=1.0/sampleRate;
   int frequency = 4000;
   int nSamples = duration * sampleRate 
   int* waveform = new int[nSamples]; // creates the array
   double v; 
   // and here 
   for ( int iSample = 0; iSample < nSamples ; iSample++){  
	   double time = iSample < nSample ;iSample *dt;
	   v=(5000 * sin(2*M_PI) * frequency * time);
	   waveform[iSample]=v;
    // and here 
   } 
   // generates sound file from waveform array, writes n_samples numbers  
   // into sound wav file 
   // should know sample_rate for sound timing 
   sound1.MakeWavFromInt("tone1.wav",sample_rate, waveform, n_samples); 
   delete(waveform); 
   return 0; 
} 
