/*********************************************************************/
/*          Movie.c                                                  */
/*    Jack Melcher 67574625                                          */
/*********************************************************************/


/*include necessary libraries*/
#include "Movie.h"
#include "Image.h"

/* allocate the memory space for the movie */
/* and the memory space for the frame list. */
/* return the pointer to the movie */
MOVIE *CreateMovie(unsigned int nFrames, unsigned int W, unsigned int H)
{
	MOVIE *movie;
	movie = (MOVIE*)malloc(sizeof(MOVIE));
	movie->Width = W;
	movie->Height = H;
	movie->NumFrames = nFrames;
	movie->Frames = NewImageList();

	return movie;
}

/*release the memory space for the frames and the frame list. */
/*release the memory space for the movie. */
void DeleteMovie(MOVIE *movie)
{
	assert(movie);
	DeleteImageList(movie->Frames);
	free(movie);
}

/* convert a YUV image into a RGB image */
void YUV2RGBImage(IMAGE *image)
{
	/*initialize variables*/
	int x, y;
	int R = 0, G = 0, B = 0;
	int Y = 0, U = 0, V = 0;
	int C = 0, D = 0, E = 0;
	
	assert(image);

	for (y = 0; y < image->Height; y++)
	{
		for (x = 0; x < image->Width; x++)
		{
			Y = GetPixelY(image, x, y);
			U = GetPixelU(image, x, y);
			V = GetPixelV(image, x, y);

			C = Y - 16;
			D = U - 128;
			E = V - 128;
			R = clip((298 * C + 409 * E + 128) >> 8);
			G = clip((298 * C - 100 * D - 208 * E + 128) >> 8);
			B = clip((298 * C + 516 * D + 128) >> 8);

			SetPixelR(image, x, y, R);
			SetPixelG(image, x, y, G);
			SetPixelB(image, x, y, B);
		}
	}
}

/* convert a RGB image into a YUV image */
void RGB2YUVImage(IMAGE *image)
{
	/*initialize variables*/
	int x, y;
	int R = 0, G = 0, B = 0;
	int Y = 0, U = 0, V = 0;

	assert(image);

	for (y = 0; y < image->Height; y++)
	{
		for (x = 0; x < image->Width; x++)
		{
			R = GetPixelR(image, x, y);
			G = GetPixelG(image, x, y);
			B = GetPixelB(image, x, y);

			Y = clip(((66 * R + 129 * G + 25 * B + 128) >> 8) + 16);
			U = clip(((-38 * R - 74 * G + 112 * B + 128) >> 8) + 128);
			V = clip(((112 * R - 94 * G - 18 * B + 128) >> 8) + 128);

			SetPixelY(image, x, y, Y);
			SetPixelU(image, x, y, U);
			SetPixelV(image, x, y, V);
		}
	}
}

/*check to see if values are within 0 and 255*/
int clip(int x)
{
	if(x >= 0 && x <= 255)
	{
		x = x;
	}
	if(x < 0)
	{
		x = 0;
	}
	if(x > 255)
	{
		x = 255;
	}
	return x;
}

