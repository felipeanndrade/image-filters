#ifndef _H_IMAGE_PROCESSING_
#define _H_IMAGE_PROCESSING_
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
void binarization(Img img_in, Img& img_out, int limiar);

/*!
 * Given a limiar, transfor the matrix in a solorized matrix
 * values below the limiar are negativated becoming 255 - actual value.
 *
 * @param img_int Input image struct.
 * @param img_out Output image struct.
 * @param limiar Limiar delimiter of the function.
 */
void solarization(Img img_in, Img& img_out, int limiar);

/*!
 * Computes the negative of an imagem, being the negative a pixel value by 255 - the actual values.
 *
 * @param img_in Input image struct.
 * @param img_out Output image struct.
 */
void compute_negative(Img img_in, Img& img_out);

/*!
 * Rotates a image counterclockwise in 90 degrees. 
 *
 * @param img_in Input image struct;
 * @param img_out Output image struct;
 */
void rotate_anti_h(Img img_in, Img& img_out);

/*!
 * Flip a image in the x axis
 *
 * @param img_in Input image struct.
 * @param img_out Outpu image struct.
 */
void flip(Img img_in, Img& img_out);

/*!
 * Reflects vertically a image by the y axis.
 *
 * @param img_int Input image struct.
 * @param img_out Output image struct.
 */
void reflection(Img img_in, Img& img_out);

#endif
