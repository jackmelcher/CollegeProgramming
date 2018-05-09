/*********************************************************/
/* Advanced.c: program file for PhotoLab operation */
/*Jack Melcher 67574625*/
/*********************************************************/

#include "Advanced.h"

/*** Advanced Functions ***/
/*All the functions need to be rewritten to accomodate new method*/

/* Posterize the image */
IMAGE *Posterize(IMAGE *image, unsigned int pbits)
{
	unsigned int x, y;
	unsigned char tempR = 0, tempG = 0, tempB = 0;

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

	return image;
}

/* Fill christmas lights to image */
IMAGE *FillLight(IMAGE *image, int number, int lightWidth)
{
	unsigned int x, y;

	unsigned int WIDTH;
	unsigned int HEIGHT;
	assert(image);
	WIDTH = image->Width;
	HEIGHT = image->Height;

	/*Another counter variable*/
	unsigned int d;
	
	/*Initialize the random number generator with the current time*/
	srand(time(NULL));

	/*A random number for choosing the block to be shuffled with*/
	int random_height;
	int random_width;
	/*Varibale for color of random  light*/
	int random_color;
	int light_colorR, light_colorG, light_colorB;
	
	/*Counter variable for number of lights*/
	int light_count;

	for (light_count = 0; light_count < number; light_count++)
	{
		/*Provides a position for the center of the light*/
		/*random height 0 to HEIGHT-1, random width 0 to WIDTH-1*/
		random_height = rand() % HEIGHT;
		random_width = rand() % WIDTH;

		/*Check to see if there is enough room for the light to be created, pick new position if there isn't*/
		while (random_height <= (lightWidth / 2) || random_height >= (HEIGHT - lightWidth / 2))
		{
			random_height = rand() % HEIGHT;
		}
		while (random_width <= (lightWidth / 2) || random_width >= (WIDTH - lightWidth / 2))
		{
			random_width = rand() % WIDTH;
		}

		/*Randomly choose color of light. 1 = red, 2 = green, 3 = blue*/
		random_color = rand() % 3 + 1;
		if (random_color == 1)
		{
			light_colorR = 255;
			light_colorG = 0;
			light_colorB = 0;
		}
		if (random_color == 2)
		{
			light_colorR = 0;
			light_colorG = 255;
			light_colorB = 0;
		}
		if (random_color == 3)
		{
			light_colorR = 0;
			light_colorG = 0;
			light_colorB = 255;
		}

		/*Center Pixel*/
		SetPixelR(image, random_width, random_height, light_colorR);
		SetPixelG(image, random_width, random_height, light_colorG);
		SetPixelB(image, random_width, random_height, light_colorB);

		/*Up and Down*/
		for (y = 1; y <= lightWidth / 2; y++)
		{
			/*Up*/
			SetPixelR(image, random_width, random_height - y, light_colorR);
			SetPixelG(image, random_width, random_height - y, light_colorG);
			SetPixelB(image, random_width, random_height - y, light_colorB);

			/*Down*/
			SetPixelR(image, random_width, random_height + y, light_colorR);
			SetPixelG(image, random_width, random_height + y, light_colorG);
			SetPixelB(image, random_width, random_height + y, light_colorB);
		}

		/*Left and Right*/
		for (x = 1; x <= lightWidth / 2; x++)
		{
			/*Right*/
			SetPixelR(image, random_width + x, random_height, light_colorR);
			SetPixelG(image, random_width + x, random_height, light_colorG);
			SetPixelB(image, random_width + x, random_height, light_colorB);

			/*Left*/
			SetPixelR(image, random_width - x, random_height, light_colorR);
			SetPixelG(image, random_width - x, random_height, light_colorG);
			SetPixelB(image, random_width - x, random_height, light_colorB);
		}

		/*Diagonals*/
		for (d = 1; d <= lightWidth / 2; d++)
		{
			/*Diagonal Up Right*/
			SetPixelR(image, random_width + d, random_height - d, light_colorR);
			SetPixelG(image, random_width + d, random_height - d, light_colorG);
			SetPixelB(image, random_width + d, random_height - d, light_colorB);

			/*Diagonal Up Left*/
			SetPixelR(image, random_width - d, random_height - d, light_colorR);
			SetPixelG(image, random_width - d, random_height - d, light_colorG);
			SetPixelB(image, random_width - d, random_height - d, light_colorB);

			/*Diagonal Down Right*/
			SetPixelR(image, random_width + d, random_height + d, light_colorR);
			SetPixelG(image, random_width + d, random_height + d, light_colorG);
			SetPixelB(image, random_width + d, random_height + d, light_colorB);

			/*Diagonal Down Left*/
			SetPixelR(image, random_width - d, random_height + d, light_colorR);
			SetPixelG(image, random_width - d, random_height + d, light_colorG);
			SetPixelB(image, random_width - d, random_height + d, light_colorB);
		}
	}

	return image;
}

/*Overaly an image onto the original image*/
IMAGE *Overlay(char fname[SLEN], IMAGE *image, int x_offset, int y_offset)
{
	/*for loop counter variables*/
	unsigned int x, y;

	unsigned int WIDTH;
	unsigned int HEIGHT;
	assert(image);
	WIDTH = image->Width;
	HEIGHT = image->Height;
	
	/*Create temp image file to hold original image*/
	IMAGE *image_tmp = NULL;
	/*Create temp image file to hold overlay image*/
	IMAGE *image_overlay = NULL;
	
	/*Load temp image*/
	image_tmp = ReadImage("RingMall");
	unsigned int WIDTH_tmp;
	unsigned int HEIGHT_tmp;
	assert(image_tmp);
	WIDTH_tmp = image_tmp->Width;
	HEIGHT_tmp = image_tmp->Height;

	/*Load overlay image*/
	image_overlay = ReadImage(fname);
	unsigned int WIDTH_overlay;
	unsigned int HEIGHT_overlay;
	assert(image_overlay);
	WIDTH_overlay = image_overlay->Width;
	HEIGHT_overlay = image_overlay->Height;

	/*Make the entire image white*/
	for (y = 0; y < HEIGHT; y++)
	{
		for (x = 0; x < WIDTH; x++)
		{
			SetPixelR(image, x, y, 255);
			SetPixelG(image, x, y, 255);
			SetPixelB(image, x, y, 255);
		}
	}

	/*Set Overlay image to appropriate offset position*/
	/*x and y are the offset values*/
	for (y = 0; y < HEIGHT_overlay; y++)
	{
		for (x = 0; x < WIDTH_overlay; x++)
		{
			/*Check to see if image offset is within boundary of image size*/
			/*If it is, replace pixel with that of the Overlay image*/
			if ((x + x_offset) >= 0 && (x + x_offset) < WIDTH && (y + y_offset) >= 0 && (y + y_offset) < HEIGHT)
			{
				SetPixelR(image, x + x_offset, y + y_offset, GetPixelR(image_overlay, x, y));
				SetPixelG(image, x + x_offset, y + y_offset, GetPixelG(image_overlay, x, y));
				SetPixelB(image, x + x_offset, y + y_offset, GetPixelB(image_overlay, x, y));
			}
		}
	}

	/*Any pixel that is white, replace with pixel from Original image*/
	for (y = 0; y < HEIGHT; y++)
	{
		for (x = 0; x < WIDTH; x++)
		{
			if (GetPixelR(image, x, y) >= 248 && GetPixelG(image, x, y) >= 248 && GetPixelB(image, x, y) >= 248)
			{
				SetPixelR(image, x, y, GetPixelR(image_tmp, x, y));
				SetPixelG(image, x, y, GetPixelG(image_tmp, x, y));
				SetPixelB(image, x, y, GetPixelB(image_tmp, x, y));
			}
		}
	}

	/*Delete temp image and overlay image*/
	DeleteImage(image_tmp);
	DeleteImage(image_overlay);

	return image;
}

/*Resize Image*/
IMAGE *Resize(unsigned int percentage, IMAGE *image)
{
	/*Resize function from PhotoLab v4*/
	/*for loop counter variables*/
	unsigned int x, y;
	
	/*Resizing variables*/
	unsigned int x1, y1, x2, y2;
	/*Variables to assist in the small resize*/
	unsigned int i, j, tmpR = 0, tmpG = 0, tmpB = 0;
	
	unsigned int WIDTH;
	unsigned int HEIGHT;

	/*Store the changed width and height*/
	unsigned int new_Width, new_Height;

	IMAGE *image_tmp = NULL;

	assert(image);
	WIDTH = image->Width;
	HEIGHT = image->Height;

	/*Create new image with new width and height*/
	new_Width = WIDTH * percentage / 100;
	new_Height = HEIGHT * percentage / 100;
	image_tmp = CreateImage(new_Width, new_Height);

	/*Big Resize*/
	if (percentage > 100)
	{
		for (x = 0; x < new_Width; x++)
		{
			for (y = 0; y < new_Height; y++)
			{
				/*Couldnt figure out how to do it with set of equations given*/
				/*Decided to use the equations in the small resize section*/
				x1 = (x / (percentage / 100.00));
				y1 = (y / (percentage / 100.00));

				SetPixelR(image_tmp, x, y, GetPixelR(image, x1, y1));
				SetPixelG(image_tmp, x, y, GetPixelG(image, x1, y1));
				SetPixelB(image_tmp, x, y, GetPixelB(image, x1, y1));
			}
		}
	}
	
	/*Small Resize*/
	if (percentage < 100)
	{
		for (x = 0; x < new_Width; x++)
		{
			for (y = 0; y < new_Height; y++)
			{
				x1 = (x / (percentage / 100.00));
				y1 = (y / (percentage / 100.00));
				x2 = ((x + 1) / (percentage / 100.00));
				y2 = ((y + 1) / (percentage / 100.00));
				/*Reset tmp values*/
				tmpR = 0, tmpG = 0, tmpB = 0;

				/*Gather color values*/
				for (i = x1; i < x2; i++)
				{
					for (j = y1; j < y2; j++)
					{
						tmpR = tmpR + GetPixelR(image, i, j);
						tmpG = tmpG + GetPixelG(image, i, j);
						tmpB = tmpB + GetPixelB(image, i, j);
					}
				}
				/*Divide the color value by the number of pixels in the block, then implement it into new image*/
				SetPixelR(image_tmp, x, y, tmpR / ((x2 - x1) * (y2 - y1)));
				SetPixelG(image_tmp, x, y, tmpG / ((x2 - x1) * (y2 - y1)));
				SetPixelB(image_tmp, x, y, tmpB / ((x2 - x1) * (y2 - y1)));
			}
		}
	}
		
	DeleteImage(image);

	return image_tmp;
	*/
}

/*Rotate 90 degrees clockwise*/
IMAGE *Rotate(IMAGE *image)
{
	/*for loop counter variables*/
	unsigned int x, y;

	/*Create image_tmp to hold original image*/
	IMAGE *image_tmp = NULL;
	image_tmp = CreateImage(image->Width, image->Height);

	/*Store original pixel values into image_tmp*/
	for (y = 0; y < image->Height; y++)
	{
		for (x = 0; x < image->Width; x++)
		{
			SetPixelR(image_tmp, x, y, GetPixelR(image, x, y));
			SetPixelG(image_tmp, x, y, GetPixelG(image, x, y));
			SetPixelB(image_tmp, x, y, GetPixelB(image, x, y));
		}
	}

	/*Adjust image Width and Height size*/
	assert(image);
	assert(image_tmp);
	image->Width = image_tmp->Height;
	image->Height = image_tmp->Width;

	/*SetPixels in image in a rotated fashion by taking them from image_tmp*/
	for (y = 0; y < image->Height; y++)
	{
		for (x = 0; x < image->Width; x++)
		{
			/*x and y are swapped in GetPixel so the correct pixels are chosen*/
			SetPixelR(image, x, y, GetPixelR(image_tmp, y, image->Width - 1 - x));
			SetPixelG(image, x, y, GetPixelG(image_tmp, y, image->Width - 1 - x));
			SetPixelB(image, x, y, GetPixelB(image_tmp, y, image->Width - 1 - x));
		}
	}

	/*Delete image_tmp*/
	DeleteImage(image_tmp);

	return image;
}

/*EOF Advanced.c*/