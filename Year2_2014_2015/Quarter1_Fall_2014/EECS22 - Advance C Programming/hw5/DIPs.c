/*********************************************************/
/* DIPs.c: program file for MovieLab operation           */
/*Jack Melcher 67574625                                  */
/*********************************************************/

#include "DIPs.h"

/*** functions ***/
/*All the functions need to be rewritten to accomodate new method*/

/* change color image to black & white */
void BlackNWhite(IMAGE *image)
{
	unsigned int x, y;
	unsigned char tempR = 0, tempG = 0, tempB = 0;

	unsigned int WIDTH;
	unsigned int HEIGHT;
	assert(image);
	WIDTH = image->Width;
	HEIGHT = image->Height;

	for (y = 0; y < HEIGHT; y++)
	{
		for (x = 0; x < WIDTH; x++)
		{
			/*Obtain and adjust pixel values at given pixel*/
			tempR = (GetPixelR(image, x, y) + GetPixelG(image, x, y) + GetPixelB(image, x, y)) / 3;
			tempG = tempR;
			tempB = tempR;
			/*Set the new color values of pixel*/
			SetPixelR(image, x, y, tempR);
			SetPixelG(image, x, y, tempG);
			SetPixelB(image, x, y, tempB);
		}
	}
}

/* flip image vertically */
void VFlip(IMAGE *image)
{
	unsigned int x, y;

	unsigned int z; /*new variable to help provide VFlip pixels values*/

	unsigned int WIDTH;
	unsigned int HEIGHT;
	assert(image);
	WIDTH = image->Width;
	HEIGHT = image->Height;

	/* to store value of pixels in the original image*/
	unsigned char temp1R = 0, temp1G = 0, temp1B = 0;
	unsigned char temp2R = 0, temp2G = 0, temp2B = 0;

	for (y = 0; y < HEIGHT / 2; y++)
	{
		for (x = 0; x < WIDTH; x++)
		{
			/*Store original pixel value*/
			temp1R = GetPixelR(image, x, y);
			temp1G = GetPixelG(image, x, y);
			temp1B = GetPixelB(image, x, y);

			/*Change pixel with the pixel for VFlip*/
			z = HEIGHT - 1 - y;

			temp2R = GetPixelR(image, x, z);
			temp2G = GetPixelG(image, x, z);
			temp2B = GetPixelB(image, x, z);

			SetPixelR(image, x, y, temp2R);
			SetPixelG(image, x, y, temp2G);
			SetPixelB(image, x, y, temp2B);

			/*Replace stored pixel color at other VFlip location*/
			SetPixelR(image, x, z, temp1R);
			SetPixelG(image, x, z, temp1G);
			SetPixelB(image, x, z, temp1B);
		}
	}
}

/* mirror image horizontally */
void HMirror(IMAGE *image)
{
	unsigned int x, y;

	unsigned int z; /*new variable to help provide HMirror pixels values*/

	unsigned int WIDTH;
	unsigned int HEIGHT;
	assert(image);
	WIDTH = image->Width;
	HEIGHT = image->Height;

	unsigned char tempR = 0, tempG = 0, tempB = 0;

	for (y = 0; y < HEIGHT; y++)
	{
		for (x = 0; x < WIDTH / 2; x++)
		{
			z = WIDTH - 1 - x;

			tempR = GetPixelR(image, z, y);
			tempG = GetPixelG(image, z, y);
			tempB = GetPixelB(image, z, y);

			SetPixelR(image, x, y, tempR);
			SetPixelG(image, x, y, tempG);
			SetPixelB(image, x, y, tempB);
		}
	}
}

/* edge detection */
/*I chose to not edge detect the broders and corners of the image.*/
void Edge(IMAGE *image)
{
	unsigned int x, y;
	unsigned char tempR = 0, tempG = 0, tempB = 0;

	unsigned int WIDTH;
	unsigned int HEIGHT;
	assert(image);
	WIDTH = image->Width;
	HEIGHT = image->Height;
	
	/*Variable to help calculate edge detection values*/
	int r = 0, g = 0, b = 0;

	/*Create image_tmp to store the new values of the pixels*/
	IMAGE *image_tmp = NULL;
	image_tmp = CreateImage(WIDTH, HEIGHT);

	/*First for loop stores calculated pixel values in separate array*/
	for (y = 0; y < HEIGHT; y++)
	{
		for (x = 0; x < WIDTH; x++)
		{
			/*Edge Detection applies to all pixels within the borders of the image*/
			if (x > 0 && x < WIDTH - 1 && y > 0 && y < HEIGHT - 1)
			{
				r = (8 * GetPixelR(image, x, y) - GetPixelR(image, x - 1, y - 1) - GetPixelR(image, x, y - 1) - GetPixelR(image, x + 1, y - 1) - GetPixelR(image, x - 1, y) - GetPixelR(image, x + 1, y) - GetPixelR(image, x - 1, y + 1) - GetPixelR(image, x, y + 1) - GetPixelR(image, x + 1, y + 1));
				/*Check to see if correct color intensity is within range and correct if necessary*/
				if (r > 255)
				{
					r = 255;
				}
				if (r < 0)
				{
					r = 0;
				}
				tempR = r;
				SetPixelR(image_tmp, x, y, tempR);

				g = (8 * GetPixelG(image, x, y) - GetPixelG(image, x - 1, y - 1) - GetPixelG(image, x, y - 1) - GetPixelG(image, x + 1, y - 1) - GetPixelG(image, x - 1, y) - GetPixelG(image, x + 1, y) - GetPixelG(image, x - 1, y + 1) - GetPixelG(image, x, y + 1) - GetPixelG(image, x + 1, y + 1));
				/*Check to see if correct color intensity is within range and correct if necessary*/
				if (g > 255)
				{
					g = 255;
				}
				if (g < 0)
				{
					g = 0;
				}
				tempG = g;
				SetPixelG(image_tmp, x, y, tempG);

				b = (8 * GetPixelB(image, x, y) - GetPixelB(image, x - 1, y - 1) - GetPixelB(image, x, y - 1) - GetPixelB(image, x + 1, y - 1) - GetPixelB(image, x - 1, y) - GetPixelB(image, x + 1, y) - GetPixelB(image, x - 1, y + 1) - GetPixelB(image, x, y + 1) - GetPixelB(image, x + 1, y + 1));
				/*Check to see if correct color intensity is within range and correct if necessary*/
				if (b > 255)
				{
					b = 255;
				}
				if (b < 0)
				{
					b = 0;
				}
				tempB = b;
				SetPixelB(image_tmp, x, y, tempB);
			}
		}

	}
	/*Second double for loop to then replace all the RGB in the original image with those of the calculated values*/
	for (y = 1; y < HEIGHT - 1; y++)
	{
		for (x = 1; x < WIDTH - 1; x++)
		{
			SetPixelR(image, x, y, GetPixelR(image_tmp, x, y));
			SetPixelG(image, x, y, GetPixelG(image_tmp, x, y));
			SetPixelB(image, x, y, GetPixelB(image_tmp, x, y));
		}
	}

	/*Delete image_tmp*/
	DeleteImage(image_tmp);
}

/* Posterize the image */
void Posterize(IMAGE *image)
{
	unsigned int x, y;
	unsigned char tempR = 0, tempG = 0, tempB = 0;

	/*pbits default to 5*/
	unsigned int pbits = 5;

	unsigned int WIDTH;
	unsigned int HEIGHT;
	assert(image);
	WIDTH = image->Width;
	HEIGHT = image->Height;

	unsigned char max_value = 255;
	unsigned char posterization_value = 0;

	for (y = 0; y < HEIGHT; y++)
	{
		for (x = 0; x < WIDTH; x++)
		{
			/*Store original values of RGB of pixel in temporary variables*/
			tempR = GetPixelR(image, x, y);
			tempG = GetPixelG(image, x, y);
			tempB = GetPixelB(image, x, y);

			/*Using bitwise operators to obtain desired output*/
			/*default pixel value to 255*/
			SetPixelR(image, x, y, GetPixelR(image, x, y) | max_value);
			SetPixelG(image, x, y, GetPixelG(image, x, y) | max_value);
			SetPixelB(image, x, y, GetPixelB(image, x, y) | max_value);

			switch (pbits)
			{
			case 1:
				posterization_value = 0;
				break;
			case 2:
				posterization_value = 1;
				break;
			case 3:
				posterization_value = 3;
				break;
			case 4:
				posterization_value = 7;
				break;
			case 5:
				posterization_value = 15;
				break;
			case 6:
				posterization_value = 31;
				break;
			case 7:
				posterization_value = 63;
				break;
			case 8:
				posterization_value = 127;
				break;
			default:
				break;
			}

			/*Set posterization based on pbits chosen*/
			SetPixelR(image, x, y, GetPixelR(image, x, y) & posterization_value);
			SetPixelG(image, x, y, GetPixelG(image, x, y) & posterization_value);
			SetPixelB(image, x, y, GetPixelB(image, x, y) & posterization_value);

			/*Shift original value to accomodate for the pbits choice. Shift causes 1's and 0's to drop off*/
			tempR = tempR >> pbits;
			tempG = tempG >> pbits;
			tempB = tempB >> pbits;

			/*Shift back and end up with a new number*/
			tempR = tempR << pbits;
			tempG = tempG << pbits;
			tempB = tempB << pbits;

			/*Posterize value is obtained*/
			SetPixelR(image, x, y, GetPixelR(image, x, y) | tempR);
			SetPixelG(image, x, y, GetPixelG(image, x, y) | tempG);
			SetPixelB(image, x, y, GetPixelB(image, x, y) | tempB);
		}
	}
}

/*Resize Image: Taken from Assignment 4 Advanced.c Solution*/
IMAGE *Resize(unsigned int percentage, IMAGE *image)
{
	
	unsigned int    x, y, x1, y1, x2, y2, i, j, tmpR, tmpG, tmpB;
	unsigned int 	NEW_WIDTH, NEW_HEIGHT;
	unsigned int WIDTH;
	unsigned int HEIGHT;
	IMAGE *image_tmp;

	assert(image);
	WIDTH = image->Width;
	HEIGHT = image->Height;

	if (percentage <= 0 || percentage > 500){
		printf("Resizing percentage %d%% is out of the range, Sorry! \n", percentage);
		return image;
	}

	NEW_WIDTH = WIDTH * percentage / 100;
	NEW_HEIGHT = HEIGHT * percentage / 100;
	image_tmp = CreateImage(NEW_WIDTH, NEW_HEIGHT);

	for (x = 0; x < NEW_WIDTH; x++){
		for (y = 0; y < NEW_HEIGHT; y++){
			x1 = (unsigned int)(x / (percentage / 100.00));
			y1 = (unsigned int)(y / (percentage / 100.00));
			x2 = (unsigned int)((x + 1) / (percentage / 100.00));
			y2 = (unsigned int)((y + 1) / (percentage / 100.00));
			tmpR = tmpB = tmpG = 0;

			if (percentage < 100){
				for (i = x1; i < x2; i++){
					for (j = y1; j < y2; j++){
						tmpR += GetPixelR(image, i, j);
						tmpG += GetPixelG(image, i, j);
						tmpB += GetPixelB(image, i, j);
					}
				}
				SetPixelR(image_tmp, x, y, tmpR / ((x2 - x1) * (y2 - y1)));
				SetPixelG(image_tmp, x, y, tmpG / ((x2 - x1) * (y2 - y1)));
				SetPixelB(image_tmp, x, y, tmpB / ((x2 - x1) * (y2 - y1)));

			}
			else{
				SetPixelR(image_tmp, x, y, GetPixelR(image, x1, y1));
				SetPixelG(image_tmp, x, y, GetPixelG(image, x1, y1));
				SetPixelB(image_tmp, x, y, GetPixelB(image, x1, y1));
			}
		}
	}

	DeleteImage(image);
	image = NULL;
	return image_tmp;
}


/* EOF DIPs.c */