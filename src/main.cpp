#include <iostream>
#include <fstream>
#include <cstdlib>
#include "../include/image_processing.hpp"
#include "../include/utils.hpp"

#define MAX_PATH_SIZE 100
#define MAX_STRING 50

using namespace std;

void render_menu()
{
	char title[] = "         LIP Digital Image Processing / Editor       \n"
				   "=======================================================";

	char subtitle[] = " -  Function                            Option number                       \n"
		              "=======================================================";


	char function_list[] = " *  Binarization                              0\n"
						   " *  Negative                                  1\n" 
						   " *  Solarization                              2\n" 
						   " *  Rotate 90 degrees anti-clockwise          3\n" 
						   " *  Flip image                                4\n"
						   " *  Crop image                                5\n"
						   " *  Erosion filtering                         6\n"
						   " *  Increase image size by interpolation      7\n"
		              "=======================================================\n";

	char option[] = " * Type a option number to select a function *\n";
	char exit_condition[] = " or Press CTRL + C to exit...";

	bool running = true;

	char image_path[MAX_PATH_SIZE];

	Img in, out;

	int limiar;

	while(running)
	{
		int function = -1;

		cout << title << endl;
		cout << subtitle << endl;
		cout << function_list << endl;
		cout << option << endl;
		cout << exit_condition << endl;

		cin >> function;

		switch(function){
			case 0:
				cout << "Type the path of the image: " << endl;
				cin >> image_path;

				cout << "Type the limiar for the binarization" << endl;
				cin >> limiar;

				read_image(image_path, in);
				check_header(in);
				binarization(in, out, limiar);
				save_image("output.pgm", out);	
				break;
			case 1:
				cout << "Type the path of the image: " << endl;
				cin >> image_path;

				read_image(image_path, in);
				check_header(in);
				compute_negative(in, out);
				save_image("output.pgm", out);	
				break;
			case 2:
				cout << "Type the path of the image: " << endl;
				cin >> image_path;
				cout << "Type the limiar for the solarization" << endl;
				cin >> limiar;

				read_image(image_path, in);
				check_header(in);
				solarization(in, out, limiar);
				save_image("output.pgm", out);	
				break;
			case 3:
				cout << "Type the path of the image: " << endl;
				cin >> image_path;

				read_image(image_path, in);
				check_header(in);
				rotate_anti_h(in, out);
				save_image("output.pgm", out);	
				break;
			case 4:
				cout << "Type the path of the image: " << endl;
				cin >> image_path;

				read_image(image_path, in);
				check_header(in);
				flip(in, out);
				save_image("output.pgm", out);	
				break;
			case 5:
				cout << "Type the path of the image: " << endl;
				cin >> image_path;

				int initial_row, initial_column;
				int final_row, final_column;

				cout << "Type the initial row: " << endl;
				cin >> initial_row;
				cout << "Type the initial column: " << endl;
				cin >> initial_column;
				cout << "Type the final row: " << endl;
				cin >> final_row;
				cout << "Type the final column: " << endl;
				cin >> final_column;

				read_image(image_path, in);
				check_header(in);

				if(initial_row  > in.width || initial_column > in.height 
			    || final_row > in.width || final_column > in.height)
				{
					cout << "Dimensions out of the boundaries" << endl;
					exit(0);
				}

				crop(in, out, initial_row, initial_column, final_row, final_column);
				save_image("output.pgm", out);	
				break;

			case 6:
				cout << "Type the path of the image: " << endl;
				cin >> image_path;

				read_image(image_path, in);
				check_header(in);
				erode(in, out);
				save_image("output.pgm", out);
				break;

			case 7:
				cout << "Type the path of the image: " << endl;
				cin >> image_path;

				read_image(image_path, in);
				check_header(in);
				increase(in, out);
				save_image("output.pgm", out);
				break;
		}
	}
}

int main()
{
	render_menu();
	return 0;
}

