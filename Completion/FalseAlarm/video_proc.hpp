
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;
//image stored as structure
struct ImagePPM{
	int width, height;
	int n_bytes;
	char* data; // actual image
};

struct Pixel{
   unsigned char red,green,blue;
};
//variable declared of this type
ImagePPM image;

// returns color component (color==0 -red,color==1-green,color==2-blue
// color == 3 - luminocity
// for pixel located at (row,column)
unsigned char get_pixel(int row,int col, int color)
{
    // calculate address in 1D array of pixels
    int address = image.width*row*3 + col*3;  // standard ppm
    //int address = image.width*row*4 + col*4;
    if ((row < 0 ) || (row > image.height) )  {
        printf("row is out of range\n");
        return -1;
    }
    if ( (col< 0) || (col > image.width))    {
        printf("column is out of range\n");
        return -1;
    }
    unsigned char r = image.data[address];
    unsigned char g = image.data[address+1];
    unsigned char b = image.data[address+2];
//std::cout<<"GP "<<(int)r<<" "<<(int)g<<" "<<(int)b<<std::endl;		          
    if (color==0) { return r;}
    if (color==1) { return g;}
    if (color==2) { return b;}
    if (color==3)    {
		int yi = r+g+b;
        unsigned char y = yi/3;
//std::cout<<"GP y="<<(int)y<<std::endl;		          
        
        return y;
    }
    printf("Color encoding wrong: 0-red, 1-green,2-blue,3 - luminosity\n");
    return -2; //error
    
}


Pixel get_pixel(int row,int col)
{
	Pixel pix;
    pix.red = 0;
    pix.green = 0;
    pix.blue = 0;
    // calculate address in 1D array of pixels
    int address = image.width*row*3 + col*3;  // standard ppm
    //int address = image.width*row*4 + col*4;
    if ((row < 0 ) || (row > image.height) )  {
        printf("row is out of range\n");
        return pix;
    }
    if ( (col< 0) || (col > image.width))    {
        printf("column is out of range\n");
        return pix;
    }
    pix.red = image.data[address];
    pix.green = image.data[address+1];
    pix.blue = image.data[address+2];
    return pix;    
}


int set_pixel(int row, int col, char red, char green,char blue)
{
    //int address = image.width*row*4 + col*4; // RPI
    int address = image.width*row*3 + col*3;  // standard ppm
    if ((address < 0) || (address>image.width*image.height*3))
    {
        printf("SetPixel(): wrong x,y coordinates\n");
        return -1;
    }
    image.data[address] = red;
    image.data[address+1] = green;
    image.data[address+2] = blue;
    return 0;
}

int SavePPMFile(string filename){
	std::ofstream fout;
	fout.open(filename);
	if (!fout.is_open()){ std::cout<<"no file"; return -1;}
	fout<<"P6"<<std::endl;
	fout<<(int)image.width<<" "<<(int)image.height<<" 255"<<std::endl;
	fout.write(image.data,image.width*image.height*3);
	fout.close();
	return 0;
	
}


int OpenPPMFile(string filename){
	//std::cout<<"Opening single ppm file"<<std::endl;
	
	std::ifstream fin;
	fin.open(filename);
	if (!fin.is_open()){ std::cout<<"no file"; return -1;}
    // get first line - contains P6
    std::string fd1;
    getline(fin,fd1);
    //std::cout<<fd1<<std::endl; 
    // get secondline
    getline(fin,fd1);
    //std::cout<<fd1<<std::endl; 
    int depth;
    sscanf( fd1.c_str(),"%d %d %d\n",&image.width ,&image.height,&depth );
    // size of the image
    // parse string
    //std::cout<<"image.height = "<<image.height;
    //std::cout<<" image.width = "<<image.width<<std::endl;
    
    image.n_bytes =  image.width*image.height*3;
    delete(image.data);  // remove whatever was there
    image.data = new char[image.n_bytes];
    fin.read(image.data, image.n_bytes);
    fin.close();
    return 0;
	
	
}
