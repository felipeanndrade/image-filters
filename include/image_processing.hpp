#ifndef _H_IMAGE_PROCESSING_
#define _H_IMAGE_PROCESSING_

#include <iostream>
#include "utils.hpp"

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
