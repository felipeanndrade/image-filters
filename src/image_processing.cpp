#include <iostream>
#include "../include/image_processing.hpp"

using namespace std;

void binarization(Img img_in, Img& img_out, int limiar)
{
	copy_img(img_in, img_out);
	for(int i = 0; i < img_out.width; i++)
	{
		for( int j = 0; j < img_out.height; j++)
		{
			if(img_out.matrix[i][j] >= limiar)
			{
				img_out.matrix[i][j] = 255;
			}
			else
				img_out.matrix[i][j] = 0;
		}
	}
}

void solarization(Img img_in, Img& img_out, int limiar)
{
	copy_img(img_in, img_out);
	for(int i = 0; i < img_out.width; i++)
	{
		for( int j = 0; j < img_out.height; j++)
		{
			if(img_out.matrix[i][j] < limiar)
			{
				img_out.matrix[i][j] = 255 - img_out.matrix[i][j];
			}
		}
	}
}

void compute_negative(Img img_in, Img& img_out)
{
	copy_img(img_in, img_out);
	for(int i = 0; i < img_out.width; i++)
	{
		for(int j = 0; j < img_out.height; j++)
		{
			img_out.matrix[i][j] = 255 - img_out.matrix[i][j];
		}
	}
}

void rotate_anti_h(Img img_in, Img& img_out)
{
	copy_img(img_in, img_out);
	int mid_width;
	int aux[MAX];
	int m_end = img_out.width - 1;

	if(img_out.width % 2 == 0)
		mid_width = img_out.width/2;
	else
		mid_width = (img_out.width/2) + 1;


	for(int i = 0; i < img_in.width; i++)
	{
		for(int j = 0; j < img_in.height; j++)
		{
			img_out.matrix[j][i] = img_in.matrix[i][j];
		}
	}
	
	for(int i = 0; i < mid_width; i++)
	{
		for(int j = 0; j < img_out.height; j++)
			aux[j] = img_out.matrix[i][j];

		for(int j = 0; j < img_out.height; j++)
			img_out.matrix[i][j] = img_out.matrix[m_end][j];

		for(int j = 0; j < img_out.height; j++)
			img_out.matrix[m_end][j] = aux[j];

		m_end--;
	}
}

void flip(Img img_in, Img& img_out)
{
	copy_img(img_in, img_out);
	int mid_height;
	int aux[MAX];
	int m_end = img_out.height - 1;

	if(img_out.height % 2 == 0)
		mid_height = img_out.height/2;
	else
		mid_height = (img_out.height/2) + 1;

	for(int i = 0; i < mid_height; i++)
	{
		for(int j = 0; j < img_out.width; j++)
			aux[j] = img_out.matrix[i][j];

		for(int j = 0; j < img_out.width; j++)
			img_out.matrix[i][j] = img_out.matrix[m_end][j];

		for(int j = 0; j < img_out.width; j++)
			img_out.matrix[m_end][j] = aux[j];

		m_end--;
	}
}

void reflection(Img img_in, Img& img_out)
{
	copy_img(img_in, img_out);
	int mid_width; 
	int m_end = img_out.width - 1;

	if(img_out.width % 2 == 0)
		mid_width = img_out.width/2;
	else
		mid_width = (img_out.width/2) + 1;

	for(int i = 0; i < img_out.height; i++)
	{
		for(int j = 0; j < mid_width; j++)
		{
			img_out.matrix[i][j] = img_out.matrix[i][m_end];
			m_end--;
		}
		m_end = img_out.width - 1;
	}
}
