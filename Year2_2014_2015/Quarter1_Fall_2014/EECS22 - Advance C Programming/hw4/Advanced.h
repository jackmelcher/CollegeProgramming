/*********************************************************/
/* Advanced.h: header file for PhotoLab operation */
/*Jack Melcher 67574625*/
/*********************************************************/
#ifndef ADVANCED_H
#define ADVANCED_H

/*** header files ***/
#include "Constants.h"
#include "FileIO.h"
#include "Image.h"

/*** function declarations ***/

/*Posterize Image*/
IMAGE *Posterize(IMAGE *image, unsigned int pbits);

/* FillLight to image */
IMAGE *FillLight(IMAGE *image, int number, int lightWidth);

/* Overlay with another image */
IMAGE *Overlay(char fname[SLEN], IMAGE *image, int x_offset, int y_offset);

/*Resize Image*/
IMAGE *Resize(unsigned int percentage, IMAGE *image);

/*Rotate 90 degrees clockwise*/
IMAGE *Rotate(IMAGE *image);

#endif /* DIPS_H */

/* EOF DIPs.h */