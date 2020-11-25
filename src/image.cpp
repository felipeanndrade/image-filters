#include <iostream>
#define MAX 20

struct Img{
	int width;
	int height;
	int matrix[MAX][MAX];
};

/*!
 * Read a image in a matrix ixj of the struct Img
 *
 * @param Img Struct corresponding the pixels, width and height
 * of the image.
 */
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

/*!
 * Copy a Img struct to another Img struct
 *
 * @param img_in Input image struct;
 * @param img_out Output image struct.
 */
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

/*!
 * Prints out in the console the Img struct width, height and the matrix of pixels.
 *
 * @param img Image struct to be printed out.
 */
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

/*!
 * Given a limiar, transform the matrix in a binary matrix with
 * 0 for values below the limiar, and 255 for values equal or above the limiar.
 *
 * @param img_in Input image struct.
 * @param img_out Output image struct.
 * @param limiar Limiar delimiter of the function.
 */
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

/*!
 * Given a limiar, transfor the matrix in a solorized matrix
 * values below the limiar are negativated becoming 255 - actual value.
 *
 * @param img_int Input image struct.
 * @param img_out Output image struct.
 * @param limiar Limiar delimiter of the function.
 */
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

/*!
 * Computes the negative of an imagem, being the negative a pixel value by 255 - the actual values.
 *
 * @param img_in Input image struct.
 * @param img_out Output image struct.
 */
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


/*!
 * Rotates a image counterclockwise in 90 degrees. 
 *
 * @param img_in Input image struct;
 * @param img_out Output image struct;
 */
void rotate_anti_h(Img img_in, Img& img_out)
{
	// Just to get the values of width and height.
	copy_img(img_in, img_out);
	for(int i = 0; i < img_in.width; i++)
	{
		for(int j = 0; j < img_in.height; j++)
		{
			img_out.matrix[j][i] = img_in.matrix[i][j];
		}
	}

	int aux[MAX];
	int lenght = img_out.height;
	for(int i = 0; i < img_out.height/2 + 1; i++)
	{
		for(int j = 0; j < img_out.width; j++)
		{

		}
		img_out.matrix[0][i] = img_out.matrix[0][lenght];
		lenght--;
	}
}

/*!
 * Flip a image in the x axis
 *
 * @param img_in Input image struct.
 * @param img_out Outpu image struct.
 */
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


/*!
 * Reflects vertically a image by the y axis.
 *
 * @param img_int Input image struct.
 * @param img_out Output image struct.
 */
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
