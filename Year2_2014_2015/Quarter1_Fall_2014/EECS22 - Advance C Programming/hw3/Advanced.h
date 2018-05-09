/*********************************************************/
/* Advanced.h: header file for PhotoLab operation */
/*********************************************************/
#ifndef ADVANCED_H
#define ADVANCED_H

/*** header files ***/
#include "Constants.h"
#include "FileIO.h"

/*** function declarations ***/

/* Posterize the image */
void Posterize(unsigned char R[WIDTH][HEIGHT],
	unsigned char G[WIDTH][HEIGHT],
	unsigned char B[WIDTH][HEIGHT],
	unsigned int pbits);

/* Fill christmas lights to image */
void FillLight(int number, int lightWidth,
	unsigned char R[WIDTH][HEIGHT],
	unsigned char G[WIDTH][HEIGHT],
	unsigned char B[WIDTH][HEIGHT]);

/*Overaly an image onto the original image*/
void Overlay(char fname[SLEN],
	unsigned char R[WIDTH][HEIGHT],
	unsigned char G[WIDTH][HEIGHT],
	unsigned char B[WIDTH][HEIGHT],
	int x_offset, int y_offset);


#endif /* DIPS_H */

/* EOF DIPs.h */