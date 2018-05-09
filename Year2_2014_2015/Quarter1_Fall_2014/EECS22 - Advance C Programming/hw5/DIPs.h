/*********************************************************/
/* DIPs.h: header file for MovieLab operation            */
/*Jack Melcher 67574625                                  */
/*********************************************************/
#ifndef DIPS_H
#define DIPS_H

/*** header files ***/
#include "Image.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>

/*** function declarations ***/

/* change color image to black & white */
void BlackNWhite(IMAGE *image);

/* flip image vertically */
void VFlip(IMAGE *image);

/* mirror image horizontally */
void HMirror(IMAGE *image);

/* edge detection */
void Edge(IMAGE *image);

/*Posterize Image*/
void Posterize(IMAGE *image);

/*Resize Image*/
IMAGE *Resize(unsigned int percentage, IMAGE *image);

#endif /* DIPS_H */

/* EOF DIPs.h */