#include <iostream>
#include <fstream>
#include <cstdlib>
#include "../include/image_processing.hpp"
#include "../include/utils.hpp"

#define MAX_STRING 50

using namespace std;

int main()
{
	Img in;

	char path[MAX_STRING];

	cin.getline(path, MAX_STRING);

	read_image(path, in);

	save_image("save.pgm", in);

	return 0;
}

