	#include "video_proc.hpp"
	
	
	int main(){
	
	int nFrames = 20;
	for ( int iFrame = 0; iFrame < nFrames ; iFrame++){
	// produce file name of "X.ppm" type where X goes from 0 to number of images
	std::string fileName;
	std::ostringstream stringStream;
	stringStream <<iFrame<<".ppm";
	fileName = stringStream.str();
	std::cout<<"\n File::"<<fileName<<std::endl;
	// open image file
	OpenPPMFile(fileName);
	
	int totred = 0;
	int totint = 0;
	float redness = 0;
	Pixel curPix;
	for ( int row =0 ; row < image.height ; row++)
	{	
	for ( int column = 0; column < image.width ; column++)
	{
	curPix = get_pixel(row,column);
	redness = (float)totred/(3.0*(float)totint);
	totred = totred + (int)get_pixel(row,column,0);
	totint = totint + (int)get_pixel(row,column,3);
	}	  
	}
	//prints out the total amounts of pixels there are in each image
	cout<<"Total red ="<<totred;
	cout<<"\nTotal int ="<< totint;
	cout<<"\nRedness ="<< redness;
	//if statment is used to check if the ruby is present in the image or not.
	if(redness < 0.340000){
	printf("\nRuby has been stolen\n\n");
	}
	else if(redness > 0.340000){ 
	printf("\nRuby is present\n\n");
	}						
	}
	return 0; 
	}
	
