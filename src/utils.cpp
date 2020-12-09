#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include "../include/utils.hpp"

using namespace std;

// ex: ./assets/lake.pgm
//
void read_image(char file_path[], Img& img)
{
	ifstream file;

	file.open(file_path);
	if(!file.is_open())
	{
		cout << "!!! ---------------------------------------------------!!!" << endl;
		cout << "Error: Could not open the file !" << endl;
		cout << "!!! ---------------------------------------------------!!!" << endl;
	}
  
	file.getline(img.header, 3);
	file >> img.width >> img.height >> img.max;

	for(int i = 0; i < img.width; i++)
	{
		for(int j = 0; j < img.height; j++)
		{
			file >> img.matrix[i][j];
		}
	}

	file.close();
}

bool save_image(char file_name[], Img img) 
{
	ofstream file;

	file.open(file_name);

	if(!file.is_open())
	{
		cout << "!!! --------------------------------------------------!!!" << endl;
		cout << "Error: Could not open the file !" << endl;
		cout << "!!! --------------------------------------------------!!!" << endl;
	}

	file << img.header << endl;
	file << img.width << " " << img.height << endl;
	file << img.max << endl;;

	for(int i = 0; i < img.width; i++)
	{
		for(int j = 0; j < img.height; j++)
		{
			file << img.matrix[i][j] << " ";
		}
		file << endl;
	}

	file.close();

	cout << "Effect applied and saved in the file output.pgm" << endl;

	return true;
}

void copy_img(Img img_in, Img& img_out)
{
	for(int i=0; i < strlen(img_in.header); i++)
		img_out.header[i] = img_in.header[i];

	img_out.width = img_in.width;
	img_out.height = img_in.height;
	img_out.max = img_in.max;
	for(int i = 0; i < img_in.width; i++)
	{
		for(int j = 0; j < img_in.height; j++)
		{
			img_out.matrix[i][j] = img_in.matrix[i][j];
		}
	}
}

void print_img(Img img)
{
	cout << img.width <<  " " << img.height << endl;
	for(int i = 0; i < img.width; i++)
	{
	  for(int j = 0; j < img.height; j++)
	  {
		cout << img.matrix[i][j] << " ";
	  }
	  cout << endl;
	}
	cout << endl;
}

void check_header(Img img)
{
	if(!(img.header[0] == 'P' ) && !(img.header[1] == '2'))
	{
		cout << "Error: Image is not a BITMAP file of type P2/.pgm" << endl;
		cout << "Please insert a valid .pgm file" << endl;
		exit(0);
	}
}
