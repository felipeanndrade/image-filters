#ifndef _H_UTILS_
#define _H_UTILS_
#define MAX 512

struct Img{
	char header[2];
	int width;
	int height;
	int max;
	int matrix[MAX][MAX];
};

/*!
 * Read a image in a matrix ixj of the struct Img
 *
 * @param file_path Path to the file image. 
 * @param img Struct corresponding the pixels, width and height
 * of the image.
 */
void read_image(char file_path[], Img& img);

/*!
 * Save a output image after some editing
 *
 * @param file_name Name of the file that will be saved.
 * @param img Image struct corresponding the actual image after editing. 
 */
bool save_image(char file_name[], Img img);

void copy_img(Img img_in, Img& img_out);

#endif
