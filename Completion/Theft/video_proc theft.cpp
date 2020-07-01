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
	
	Pixel curPix;
	float black = 0;
	float white = 0;
	int redPixels = 0;
	
	for ( int row =0 ; row < image.height ; row++)
	{	
	for ( int column = 0; column < image.width ; column++)
	{
	curPix = get_pixel(row,column);
	//this if statment checks to see how many red pixels there are in each image
	if ((int)curPix.red > ((int)curPix.green+(int)curPix.blue)){
	redPixels++;
	}
	//this if statment checks to see how many black pixels there are in each image
	if(((int)curPix.red + (int)curPix.green + (int)curPix.blue)/3 < 85){
	black++;
	}  
	//this if statment checks to see how many white pixels there are in each image
	if(((int)curPix.red + (int)curPix.green + (int)curPix.blue)/3 > 170){
	white++;
	}
	}
	}
	//prints out the total amounts of pixels there are in each image
	cout<<"Total red ="<<redPixels<<endl;
	cout<<"Total Black ="<<black<<endl;
	cout<<"Total White ="<<white<<endl;
	//if statment to check if the ruby has been stolen or it is still present in each image
	if(redPixels == 0){
	printf("\nRuby has been stolen\n\n");
	}
	else { 
	printf("\nRuby is present\n\n");
	}
	}
	
	return 0; 
	}
	
