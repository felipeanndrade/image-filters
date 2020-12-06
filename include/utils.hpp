#ifndef _H_UTILS_
#define _H_UTILS_
#define MAX 512

struct Img{
	char header[2];
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
void read_img(Img& img);

/*!
 * Copy a Img struct to another Img struct
 *
 * @param img_in Input image struct;
 * @param img_out Output image struct.
 */
void copy_img(Img img_in, Img& img_out);

/*!
 * Prints out in the console the Img struct width, height and the matrix of pixels.
 *
 * @param img Image struct to be printed out.
 */
void print_img(Img img);

/*!
 * Given a limiar, transform the matrix in a binary matrix with
 * 0 for values below the limiar, and 255 for values equal or above the limiar.
 *
 * @param img_in Input image struct.
 * @param img_out Output image struct.
 * @param limiar Limiar delimiter of the function.
 */

#endif
