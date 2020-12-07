#include <iostream>
#include <cstdlib>
#include <cstring>
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
		cout << "Erro: nao foi possivel abrir o arquivo" << endl;
		exit(0);
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
		cout << "Erro: nao foi possivel abrir o arquivo" << endl;
		exit(0);
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

	return true;
}
