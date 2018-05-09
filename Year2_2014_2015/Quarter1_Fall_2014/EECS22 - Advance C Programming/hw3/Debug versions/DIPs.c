/*********************************************************/
/* DIPs.c: program file for PhotoLab operation */
/*Jack Melcher 67574625*/
/*********************************************************/

#include "DIPs.h"

/*** functions ***/

/* change color image to black & white */
void BlackNWhite(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
{
	int x, y;

	for (y = 0; y < HEIGHT; y++)
	{
		for (x = 0; x < WIDTH; x++)
		{
			R[x][y] = (R[x][y] + G[x][y] + B[x][y]) / 3;
			G[x][y] = (R[x][y]);
			B[x][y] = (R[x][y]);
		}
	}
}

/* flip image vertically */
void	VFlip(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
{
	int x, y;

	/*Arrays to store value of pixels in the original image*/
	unsigned char tempR[WIDTH][HEIGHT];
	unsigned char tempG[WIDTH][HEIGHT];
	unsigned char tempB[WIDTH][HEIGHT];

	for (y = 0; y < HEIGHT / 2; y++)
	{
		for (x = 0; x < WIDTH; x++)
		{
			/*Store original pixel color*/
			tempR[x][y] = R[x][y];
			tempG[x][y] = G[x][y];
			tempB[x][y] = B[x][y];
			/*Change pixel with the pixel for VFlip*/
			R[x][y] = R[x][HEIGHT - 1 - y];
			G[x][y] = G[x][HEIGHT - 1 - y];
			B[x][y] = B[x][HEIGHT - 1 - y];
			/*Replace stored pixel color at other VFlip location*/
			R[x][HEIGHT - 1 - y] = tempR[x][y];
			G[x][HEIGHT - 1 - y] = tempG[x][y];
			B[x][HEIGHT - 1 - y] = tempB[x][y];
		}
	}
}

/* mirror image horizontally */
void	HMirror(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
{
	int x, y;

	for (y = 0; y < HEIGHT; y++)
	{
		for (x = 0; x < WIDTH / 2; x++)
		{
			R[x][y] = R[WIDTH - 1 - x][y];
			G[x][y] = G[WIDTH - 1 - x][y];
			B[x][y] = B[WIDTH - 1 - x][y];
		}
	}
}

/* color filter */
void 	ColorFilter(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT], int target_r, int target_g, int target_b, int threshold, int replace_r, int replace_g, int replace_b)
{
	int x, y;
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
			/*Checks whether the given pixel meets the requirements for its color to be replaced*/
			if (R[x][y] >= Rmin && R[x][y] <= Rmax && G[x][y] >= Gmin && G[x][y] <= Gmax && B[x][y] >= Bmin && B[x][y] <= Bmax)
			{
				R[x][y] = replace_r;
				/*Check to see if correct color intensity is within range and correct if necessary*/
				if (R[x][y] > 255)
				{
					R[x][y] = 255;
				}
				if (R[x][y] < 0)
				{
					R[x][y] = 0;
				}

				G[x][y] = replace_g;
				/*Check to see if correct color intensity is within range and correct if necessary*/
				if (G[x][y] > 255)
				{
					G[x][y] = 255;
				}
				if (G[x][y] < 0)
				{
					G[x][y] = 0;
				}

				B[x][y] = replace_b;
				/*Check to see if correct color intensity is within range and correct if necessary*/
				if (B[x][y] > 255)
				{
					B[x][y] = 255;
				}
				if (B[x][y] < 0)
				{
					B[x][y] = 0;
				}
			}
		}
	}
}

/* edge detection */
/*I chose to not edge detect the broders and corners of the image.*/
void	Edge(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
{
	int x, y;
	/*Arrays to store the new values of the pixels*/
	int tempArray_R[WIDTH][HEIGHT], tempArray_G[WIDTH][HEIGHT], tempArray_B[WIDTH][HEIGHT];
	
	/*First for loop stores calculated pixel values in separate array*/
	for (y = 0; y < HEIGHT; y++)
	{
		for (x = 0; x < WIDTH; x++)
		{
			/*Edge Detection applies to all pixels within the borders of the image*/
			if (x > 0 && x < WIDTH - 1 && y > 0 && y < HEIGHT - 1)
			{
				tempArray_R[x][y] = (8 * R[x][y] - R[x - 1][y - 1] - R[x][y - 1] - R[x + 1][y - 1] - R[x - 1][y] - R[x + 1][y] - R[x - 1][y + 1] - R[x][y + 1] - R[x + 1][y + 1]);
				/*Check to see if correct color intensity is within range and correct if necessary*/
				if (tempArray_R[x][y] > 255)
				{
					tempArray_R[x][y] = 255;
				}
				if (tempArray_R[x][y] < 0)
				{
					tempArray_R[x][y] = 0;
				}

				tempArray_G[x][y] = (8 * G[x][y] - G[x - 1][y - 1] - G[x][y - 1] - G[x + 1][y - 1] - G[x - 1][y] - G[x + 1][y] - G[x - 1][y + 1] - G[x][y + 1] - G[x + 1][y + 1]);
				/*Check to see if correct color intensity is within range and correct if necessary*/
				if (tempArray_G[x][y] > 255)
				{
					tempArray_G[x][y] = 255;
				}
				if (tempArray_G[x][y] < 0)
				{
					tempArray_G[x][y] = 0;
				}

				tempArray_B[x][y] = (8 * B[x][y] - B[x - 1][y - 1] - B[x][y - 1] - B[x + 1][y - 1] - B[x - 1][y] - B[x + 1][y] - B[x - 1][y + 1] - B[x][y + 1] - B[x + 1][y + 1]);
				/*Check to see if correct color intensity is within range and correct if necessary*/
				if (tempArray_B[x][y] > 255)
				{
					tempArray_B[x][y] = 255;
				}
				if (tempArray_B[x][y] < 0)
				{
					tempArray_B[x][y] = 0;
				}
			}
		}
		
	}
	/*Second double for loop to then replace all the RGB in the original image with those of the calculated values*/
	for (y = 0; y < HEIGHT; y++)
	{
		for (x = 0; x < WIDTH; x++)
		{
			R[x][y] = tempArray_R[x][y];
			G[x][y] = tempArray_G[x][y];
			B[x][y] = tempArray_B[x][y];
		}
	}
}

/* shuffle image*/
/*My shuffle function doesn't contain a check to see which blocks were shuffled. It does indeed create a random image with each run.*/
void	Shuffle(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
{
	int x, y;

	/*Initialize the random number generator with the current time*/
	srand(time(NULL));

	/*Check which block of the picture the shuffler is at*/
	int current_height_block = 1;/*1 through 4*/
	int current_width_block = 1;/*1 through 4*/

	/*A random number for choosing the block to be shuffled with*/
	int random_height_block;
	int random_width_block;

	/*temporarily store the image blocks*/
	int temp1_R[WIDTH / SHUFF_WIDTH_DIV][HEIGHT / SHUFF_HEIGHT_DIV], temp1_G[WIDTH / SHUFF_WIDTH_DIV][HEIGHT / SHUFF_HEIGHT_DIV], temp1_B[WIDTH / SHUFF_WIDTH_DIV][HEIGHT / SHUFF_HEIGHT_DIV];

	/* SHUFF_HEIGHT_DIV and SHUFF_WIDTH_DIV for shuffling is equal to 4 */

	
	while (current_height_block < 5)
	{
		for (current_width_block = 1; current_width_block < 5; current_width_block++)
		{
			/*Provides a random block*/
			random_height_block = rand() % 4 + 1;
			random_width_block = rand() % 4 + 1;
			
			while (random_height_block == current_height_block && random_width_block == current_width_block)
			{
				random_height_block = rand() % 4 + 1;
				random_width_block = rand() % 4 + 1;
			}

			for (y = 0; y < (HEIGHT / SHUFF_HEIGHT_DIV); y++)
			{
				for (x = 0; x < (WIDTH / SHUFF_WIDTH_DIV); x++)
				{
					/*Store current image block in tempArray image block*/
					temp1_R[x][y] = R[(current_width_block - 1) * (WIDTH / SHUFF_WIDTH_DIV) + x][(current_height_block - 1) * (HEIGHT / SHUFF_HEIGHT_DIV) + y];
					temp1_G[x][y] = G[(current_width_block - 1) * (WIDTH / SHUFF_WIDTH_DIV) + x][(current_height_block - 1) * (HEIGHT / SHUFF_HEIGHT_DIV) + y];
					temp1_B[x][y] = B[(current_width_block - 1) * (WIDTH / SHUFF_WIDTH_DIV) + x][(current_height_block - 1) * (HEIGHT / SHUFF_HEIGHT_DIV) + y];
				}
			}

			for (y = ((current_height_block - 1) * HEIGHT / SHUFF_HEIGHT_DIV); y < (current_height_block * HEIGHT / SHUFF_HEIGHT_DIV); y++)
			{
				for (x = ((current_width_block - 1) * WIDTH / SHUFF_WIDTH_DIV); x < (current_width_block * WIDTH / SHUFF_WIDTH_DIV); x++)
				{
					/*Replace current image block with random image block*/
					R[x][y] = R[(random_width_block - 1) * (WIDTH / SHUFF_WIDTH_DIV) + (x - (current_width_block - 1) * (WIDTH / SHUFF_WIDTH_DIV))][(random_height_block - 1) * (HEIGHT / SHUFF_HEIGHT_DIV) + (y - (current_height_block - 1) * (HEIGHT / SHUFF_HEIGHT_DIV))];
					G[x][y] = G[(random_width_block - 1) * (WIDTH / SHUFF_WIDTH_DIV) + (x - (current_width_block - 1) * (WIDTH / SHUFF_WIDTH_DIV))][(random_height_block - 1) * (HEIGHT / SHUFF_HEIGHT_DIV) + (y - (current_height_block - 1) * (HEIGHT / SHUFF_HEIGHT_DIV))];
					B[x][y] = B[(random_width_block - 1) * (WIDTH / SHUFF_WIDTH_DIV) + (x - (current_width_block - 1) * (WIDTH / SHUFF_WIDTH_DIV))][(random_height_block - 1) * (HEIGHT / SHUFF_HEIGHT_DIV) + (y - (current_height_block - 1) * (HEIGHT / SHUFF_HEIGHT_DIV))];
				}

			}

			for (y = ((random_height_block - 1) * HEIGHT / SHUFF_HEIGHT_DIV); y < (random_height_block * HEIGHT / SHUFF_HEIGHT_DIV); y++)
			{
				for (x = ((random_width_block - 1) * WIDTH / SHUFF_WIDTH_DIV); x < (random_width_block * WIDTH / SHUFF_WIDTH_DIV); x++)
				{
					/*Replace random image block with the temp image block*/
					R[x][y] = temp1_R[x - ((random_width_block - 1) * WIDTH / SHUFF_WIDTH_DIV)][y - ((random_height_block - 1) * HEIGHT / SHUFF_HEIGHT_DIV)];
					G[x][y] = temp1_G[x - ((random_width_block - 1) * WIDTH / SHUFF_WIDTH_DIV)][y - ((random_height_block - 1) * HEIGHT / SHUFF_HEIGHT_DIV)];
					B[x][y] = temp1_B[x - ((random_width_block - 1) * WIDTH / SHUFF_WIDTH_DIV)][y - ((random_height_block - 1) * HEIGHT / SHUFF_HEIGHT_DIV)];
				}
			}

			/*After swapping blocks, move to next block on the right*/
		}
		/*After swapping all the blocks in a row, move down to the next row.*/
		current_height_block = current_height_block + 1;
	}
}

/* add border */
void	AddBorder(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT], char color[SLEN], int border_width)
{
	int x, y;

	char black[SLEN] = "black";
	char white[SLEN] = "white";
	char red[SLEN] = "red";
	char green[SLEN] = "green";
	char blue[SLEN] = "blue";
	char yellow[SLEN] = "yellow";
	char cyan[SLEN] = "cyan";
	char pink[SLEN] = "pink";
	char orange[SLEN] = "orange";

	int temp1_R, temp1_G, temp1_B;

	if (strcmp(black, color) == 0)
	{
		temp1_R = 0;
		temp1_G = 0;
		temp1_B = 0;
	}
	if (strcmp(white, color) == 0)
	{
		temp1_R = 255;
		temp1_G = 255;
		temp1_B = 255;
	}
	if (strcmp(red, color) == 0)
	{
		temp1_R = 255;
		temp1_G = 0;
		temp1_B = 0;
	}
	if (strcmp(green, color) == 0)
	{
		temp1_R = 0;
		temp1_G = 255;
		temp1_B = 0;
	}
	if (strcmp(blue, color) == 0)
	{
		temp1_R = 0;
		temp1_G = 0;
		temp1_B = 255;
	}
	if (strcmp(yellow, color) == 0)
	{
		temp1_R = 255;
		temp1_G = 255;
		temp1_B = 0;
	}
	if (strcmp(cyan, color) == 0)
	{
		temp1_R = 0;
		temp1_G = 255;
		temp1_B = 255;
	}
	if (strcmp(pink, color) == 0)
	{
		temp1_R = 255;
		temp1_G = 0;
		temp1_B = 255;
	}
	if (strcmp(orange, color) == 0)
	{
		temp1_R = 255;
		temp1_G = 100;
		temp1_B = 0;
	}

	/*Top Border*/
	for (y = 0; y < border_width; y++)
	{
		for (x = 0; x < WIDTH; x++)
		{
			R[x][y] = temp1_R;
			G[x][y] = temp1_G;
			B[x][y] = temp1_B;
		}
	}
	/*Bottom Border*/
	for (y = (HEIGHT - border_width); y < HEIGHT; y++)
	{
		for (x = 0; x < WIDTH; x++)
		{
			R[x][y] = temp1_R;
			G[x][y] = temp1_G;
			B[x][y] = temp1_B;
		}
	}
	/*Left Border*/
	for (y = 0; y < HEIGHT; y++)
	{
		for (x = 0; x < border_width; x++)
		{
			R[x][y] = temp1_R;
			G[x][y] = temp1_G;
			B[x][y] = temp1_B;
		}
	}
	/*Right Border*/
	for (y = 0; y < HEIGHT; y++)
	{
		for (x = (WIDTH - border_width); x < WIDTH; x++)
		{
			R[x][y] = temp1_R;
			G[x][y] = temp1_G;
			B[x][y] = temp1_B;
		}
	}
}
/* EOF DIPs.c */