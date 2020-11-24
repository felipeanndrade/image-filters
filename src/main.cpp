#include <iostream>
#define MAX 20

using namespace std;

struct Img{
	int width;
	int height;
	int matrix[MAX][MAX];
};

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


int main()
{
	return 0;
}

