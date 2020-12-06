#include <iostream>
#include "../include/utils.hpp"

using namespace std;

void read_img(Img& img)
{
	int temp;
	for(int i = 0; i < img.width; i++)
	{
		for( int j = 0; j < img.height; j++)
		{
			cin >> temp;
			img.matrix[i][j] = temp;
		}
	}
}

void copy_img(Img img_in, Img& img_out)
{
	img_out.width = img_in.width;
	img_out.height = img_in.height;
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
