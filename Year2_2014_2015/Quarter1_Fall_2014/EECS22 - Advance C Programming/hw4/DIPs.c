/*********************************************************/
/* DIPs.c: program file for PhotoLab operation */
/*Jack Melcher 67574625*/
/*********************************************************/

#include "DIPs.h"
#include "Image.h"

/*** functions ***/
/*All the functions need to be rewritten to accomodate new method*/

/* change color image to black & white */
IMAGE *BlackNWhite(IMAGE *image)
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

	return image;
}

/* flip image vertically */
IMAGE *VFlip(IMAGE *image)
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

	return image;
}

/* mirror image horizontally */
IMAGE *HMirror(IMAGE *image)
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

	return image;
}

/* color filter */
IMAGE *ColorFilter(IMAGE *image, int target_r, int target_g, int target_b, int threshold, int replace_r, int replace_g, int replace_b)
{
	unsigned int x, y;
	unsigned char tempR = 0, tempG = 0, tempB = 0;

	unsigned int WIDTH;
	unsigned int HEIGHT;
	assert(image);
	WIDTH = image->Width;
	HEIGHT = image->Height;

	/*Store range values for the color threshold check*/
	int Rmin, Rmax, Gmin, Gmax, Bmin, Bmax;

	Rmin = target_r - threshold;
	Rmax = target_r + threshold;
	Gmin = target_g - threshold;
	Gmax = target_g + threshold;
	Bmin = target_b - threshold;
	Bmax = target_b + threshold;

	for (y = 0; y < HEIGHT; y++)
	{
		for (x = 0; x < WIDTH; x++)
		{
			tempR = GetPixelR(image, x, y);
			tempG = GetPixelG(image, x, y);
			tempB = GetPixelB(image, x, y);

			/*Checks whether the given pixel meets the requirements for its color to be replaced*/
			if (tempR >= Rmin && tempR <= Rmax && tempG >= Gmin && tempG <= Gmax && tempB >= Bmin && tempB <= Bmax)
			{
				/*Check to see if correct color intensity is outside unsigned char range*/
				if (replace_r > 255)
				{
					replace_r = 255;
				}
				if (replace_r < 0)
				{
					replace_r = 0;
				}
				/*Replace color value*/
				SetPixelR(image, x, y, replace_r);

				/*Check to see if correct color intensity is outside unsigned char range*/
				if (replace_g > 255)
				{
					replace_g = 255;
				}
				if (replace_g < 0)
				{
					replace_g = 0;
				}
				/*Replace color value*/
				SetPixelG(image, x, y, replace_g);

				/*Check to see if correct color intensity is outside unsigned char range*/
				if (replace_b > 255)
				{
					replace_b = 255;
				}
				if (replace_b < 0)
				{
					replace_b = 0;
				}
				/*Replace color value*/
				SetPixelB(image, x, y, replace_b);
			}
		}
	}

	return image;
}

/* edge detection */
/*I chose to not edge detect the broders and corners of the image.*/
IMAGE *Edge(IMAGE *image)
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

	return image;
}

/* shuffle image*/
/*My shuffle function doesn't contain a check to see which blocks were shuffled. It does indeed create a random image with each run.*/
IMAGE *Shuffle(IMAGE *image)
{
	unsigned int x, y;
	unsigned char tempR = 0, tempG = 0, tempB = 0;

	unsigned int WIDTH;
	unsigned int HEIGHT;
	assert(image);
	WIDTH = image->Width;
	HEIGHT = image->Height;

	/*Initialize the random number generator with the current time*/
	srand(time(NULL));

	/*Check which block of the picture the shuffler is at*/
	int current_HEIGHT_block = 1;/*1 through 4*/
	int current_WIDTH_block = 1;/*1 through 4*/

	/*A random number for choosing the block to be shuffled with*/
	int random_HEIGHT_block;
	int random_WIDTH_block;

	/*temporarily store the image blocks*/
	unsigned char temp1_R[WIDTH / SHUFF_WIDTH_DIV][HEIGHT / SHUFF_HEIGHT_DIV], temp1_G[WIDTH / SHUFF_WIDTH_DIV][HEIGHT / SHUFF_HEIGHT_DIV], temp1_B[WIDTH / SHUFF_WIDTH_DIV][HEIGHT / SHUFF_HEIGHT_DIV];

	/* SHUFF_HEIGHT_DIV and SHUFF_WIDTH_DIV for shuffling is equal to 4 */


	while (current_HEIGHT_block < 5)
	{
		for (current_WIDTH_block = 1; current_WIDTH_block < 5; current_WIDTH_block++)
		{
			/*Provides a random block*/
			random_HEIGHT_block = rand() % 4 + 1;
			random_WIDTH_block = rand() % 4 + 1;

			while (random_HEIGHT_block == current_HEIGHT_block && random_WIDTH_block == current_WIDTH_block)
			{
				random_HEIGHT_block = rand() % 4 + 1;
				random_WIDTH_block = rand() % 4 + 1;
			}

			for (y = 0; y < (HEIGHT / SHUFF_HEIGHT_DIV); y++)
			{
				for (x = 0; x < (WIDTH / SHUFF_WIDTH_DIV); x++)
				{
					/*Store current image block in tempArray image block*/
					temp1_R[x][y] = GetPixelR(image, (current_WIDTH_block - 1) * (WIDTH / SHUFF_WIDTH_DIV) + x, (current_HEIGHT_block - 1) * (HEIGHT / SHUFF_HEIGHT_DIV) + y);
					temp1_G[x][y] = GetPixelG(image, (current_WIDTH_block - 1) * (WIDTH / SHUFF_WIDTH_DIV) + x, (current_HEIGHT_block - 1) * (HEIGHT / SHUFF_HEIGHT_DIV) + y);
					temp1_B[x][y] = GetPixelB(image, (current_WIDTH_block - 1) * (WIDTH / SHUFF_WIDTH_DIV) + x, (current_HEIGHT_block - 1) * (HEIGHT / SHUFF_HEIGHT_DIV) + y);
				}
			}

			for (y = ((current_HEIGHT_block - 1) * HEIGHT / SHUFF_HEIGHT_DIV); y < (current_HEIGHT_block * HEIGHT / SHUFF_HEIGHT_DIV); y++)
			{
				for (x = ((current_WIDTH_block - 1) * WIDTH / SHUFF_WIDTH_DIV); x < (current_WIDTH_block * WIDTH / SHUFF_WIDTH_DIV); x++)
				{
					/*Replace current image block with random image block*/
					tempR = GetPixelR(image, (random_WIDTH_block - 1) * (WIDTH / SHUFF_WIDTH_DIV) + (x - (current_WIDTH_block - 1) * (WIDTH / SHUFF_WIDTH_DIV)), (random_HEIGHT_block - 1) * (HEIGHT / SHUFF_HEIGHT_DIV) + (y - (current_HEIGHT_block - 1) * (HEIGHT / SHUFF_HEIGHT_DIV)));
					tempG = GetPixelG(image, (random_WIDTH_block - 1) * (WIDTH / SHUFF_WIDTH_DIV) + (x - (current_WIDTH_block - 1) * (WIDTH / SHUFF_WIDTH_DIV)), (random_HEIGHT_block - 1) * (HEIGHT / SHUFF_HEIGHT_DIV) + (y - (current_HEIGHT_block - 1) * (HEIGHT / SHUFF_HEIGHT_DIV)));
					tempB = GetPixelB(image, (random_WIDTH_block - 1) * (WIDTH / SHUFF_WIDTH_DIV) + (x - (current_WIDTH_block - 1) * (WIDTH / SHUFF_WIDTH_DIV)), (random_HEIGHT_block - 1) * (HEIGHT / SHUFF_HEIGHT_DIV) + (y - (current_HEIGHT_block - 1) * (HEIGHT / SHUFF_HEIGHT_DIV)));

					SetPixelR(image, x, y, tempR);
					SetPixelG(image, x, y, tempG);
					SetPixelB(image, x, y, tempB);
				}
			}

			for (y = ((random_HEIGHT_block - 1) * HEIGHT / SHUFF_HEIGHT_DIV); y < (random_HEIGHT_block * HEIGHT / SHUFF_HEIGHT_DIV); y++)
			{
				for (x = ((random_WIDTH_block - 1) * WIDTH / SHUFF_WIDTH_DIV); x < (random_WIDTH_block * WIDTH / SHUFF_WIDTH_DIV); x++)
				{
					/*Replace random image block with the temp image block*/
					SetPixelR(image, x, y, temp1_R[x - ((random_WIDTH_block - 1) * WIDTH / SHUFF_WIDTH_DIV)][y - ((random_HEIGHT_block - 1) * HEIGHT / SHUFF_HEIGHT_DIV)]);
					SetPixelG(image, x, y, temp1_G[x - ((random_WIDTH_block - 1) * WIDTH / SHUFF_WIDTH_DIV)][y - ((random_HEIGHT_block - 1) * HEIGHT / SHUFF_HEIGHT_DIV)]);
					SetPixelB(image, x, y, temp1_B[x - ((random_WIDTH_block - 1) * WIDTH / SHUFF_WIDTH_DIV)][y - ((random_HEIGHT_block - 1) * HEIGHT / SHUFF_HEIGHT_DIV)]);
				}
			}

			/*After swapping blocks, move to next block on the right*/
		}
		/*After swapping all the blocks in a row, move down to the next row.*/
		current_HEIGHT_block = current_HEIGHT_block + 1;
	}

	return image;
}


/* EOF DIPs.c */