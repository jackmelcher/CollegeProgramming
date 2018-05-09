/*******************************************/
/*Image.c program file*/
/*Jack Melcher 67574625*/
/*******************************************/

#include "Image.h"
#include "Constants.h"

/* Get the color intensity of the Red channel of pixel (x, y) in image */
unsigned char GetPixelR(IMAGE *image, unsigned int x, unsigned int y)
{
	assert(image);
	assert(image->R);
	
	return image->R[x + (y * (image->Width))];
}

/* Get the color intensity of the Green channel of pixel (x, y) in image */
unsigned char GetPixelG(IMAGE *image, unsigned int x, unsigned int y)
{
	assert(image);
	assert(image->G);
	
	return image->G[x + (y * (image->Width))];
}

/* Get the color intensity of the Blue channel of pixel (x, y) in image */
unsigned char GetPixelB(IMAGE *image, unsigned int x, unsigned int y)
{
	assert(image);
	assert(image->B);
	
	return image->B[x + (y * (image->Width))];
}

/* Set the color intensity of the Red channel of pixel (x, y) in image with value r */
void SetPixelR(IMAGE *image, unsigned int x, unsigned int y, unsigned char r)
{
	assert(image);
	assert(image->R);
	
	image->R[x + (y * (image->Width))] = r;
}

/* Set the color intensity of the Green channel of pixel (x, y) in image with value g */
void SetPixelG(IMAGE *image, unsigned int x, unsigned int y, unsigned char g)
{
	assert(image);
	assert(image->G);
	
	image->G[x + (y * (image->Width))] = g;
}

/* Set the color intensity of the Blue channel of pixel (x, y) in image with value b */
void SetPixelB(IMAGE *image, unsigned int x, unsigned int y, unsigned char b)
{
	assert(image);
	assert(image->B);
	
	image->B[x + (y * (image->Width))] = b;
}

/* allocate the memory space for the image structure         */
/* and the memory spaces for the color intensity values.     */
/* return the pointer to the image, or NULL in case of error */
IMAGE *CreateImage(unsigned int Width, unsigned int Height)
{
	IMAGE *image;
	
	image = (IMAGE*)malloc(sizeof(IMAGE));
	
	image->R = NULL;
	image->G = NULL;
	image->B = NULL;

	image->Width = Width;
	image->Height = Height;
	
	image->R = (unsigned char*)malloc(Width * Height * sizeof(unsigned char));
	image->G = (unsigned char*)malloc(Width * Height * sizeof(unsigned char));
	image->B = (unsigned char*)malloc(Width * Height * sizeof(unsigned char));

	return image;
}

/* release the memory spaces for the pixel color intensity values */
/* deallocate all the memory spaces for the image                 */
void DeleteImage(IMAGE *image)
{
	assert(image);
	assert(image->R);
	assert(image->G);
	assert(image->B);

	free(image->R);
	free(image->G);
	free(image->B);

	image->R = NULL;
	image->G = NULL;
	image->B = NULL;
	
	free(image);
}