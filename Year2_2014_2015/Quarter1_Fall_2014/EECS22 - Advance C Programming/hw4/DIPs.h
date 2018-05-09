/*********************************************************/
/* DIPs.h: header file for PhotoLab operation */
/*Jack Melcher 67574625*/
/*********************************************************/
#ifndef DIPS_H
#define DIPS_H

/*** header files ***/
#include "Constants.h"
#include "Image.h"

/*** function declarations ***/

/* change color image to black & white */
IMAGE *BlackNWhite(IMAGE *image);

/* flip image vertically */
IMAGE *VFlip(IMAGE *image);

/* mirror image horizontally */
IMAGE *HMirror(IMAGE *image);

/* color filter */
IMAGE *ColorFilter(IMAGE *image, int target_r, int target_g, int target_b, int threshold, int replace_r, int replace_g, int replace_b);

/* edge detection */
IMAGE *Edge(IMAGE *image);

/* shuffle the image */
IMAGE *Shuffle(IMAGE *image);

/* Test all functions */
void AutoTest(IMAGE *image);

#endif /* DIPS_H */

/* EOF DIPs.h */