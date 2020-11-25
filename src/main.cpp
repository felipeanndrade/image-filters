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
			cout << img.matrix[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;
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

int main()
{
	Img in, out;

	cin >> in.width >> in.height;

	read_img(in);
	reflection(in, out);
	print_img(out);

	return 0;
}

