/*********************************************************/
/* FileIO.h: header file for I/O module */
/*Jack Melcher 67574625*/
/*********************************************************/

#ifndef FILE_IO_H
#define FILE_IO_H

#include "Constants.h"

/* read image from a file */
int	ReadImage(char fname[SLEN], unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT]);

/* save a processed image */
int	SaveImage(char fname[SLEN], unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT]);

#endif /* FILE_IO_H */
/* EOF FileIO.h */