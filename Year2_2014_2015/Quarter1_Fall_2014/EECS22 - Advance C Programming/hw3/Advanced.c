/*********************************************************/
/* Advanced.c: program file for PhotoLab operation */
/*********************************************************/

#include "Advanced.h"

/*** Advanced Functions ***/

/* Posterize the image */
void Posterize(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT], unsigned int pbits)
{
	unsigned char max_value = 255;
	unsigned char posterization_value = 0;

	unsigned char temp_R[WIDTH][HEIGHT];
	unsigned char temp_G[WIDTH][HEIGHT];
	unsigned char temp_B[WIDTH][HEIGHT];
	/*foor loop counters*/
	int x, y;

	for (y = 0; y < HEIGHT; y++)
	{
		for (x = 0; x < WIDTH; x++)
		{
			/*Store original values of RGB of pixel in temporary variables*/
			temp_R[x][y] = R[x][y];
			temp_G[x][y] = G[x][y];
			temp_B[x][y] = B[x][y];

			/*Using bitwise operators to obtain desired output*/
			/*default pixel value to 255*/
			R[x][y] = R[x][y] | max_value;
			G[x][y] = G[x][y] | max_value;
			B[x][y] = B[x][y] | max_value;

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
			R[x][y] = R[x][y] & posterization_value;
			G[x][y] = G[x][y] & posterization_value;
			B[x][y] = B[x][y] & posterization_value;

			/*Shift original value to accomodate for the pbits choice. Shift causes 1's and 0's to drop off*/
			temp_R[x][y] = temp_R[x][y] >> pbits;
			temp_G[x][y] = temp_G[x][y] >> pbits;
			temp_B[x][y] = temp_B[x][y] >> pbits;

			/*Shift back and end up with a new number*/
			temp_R[x][y] = temp_R[x][y] << pbits;
			temp_G[x][y] = temp_G[x][y] << pbits;
			temp_B[x][y] = temp_B[x][y] << pbits;

			/*Posterize value is obtained*/
			R[x][y] = R[x][y] | temp_R[x][y];
			G[x][y] = G[x][y] | temp_G[x][y];
			B[x][y] = B[x][y] | temp_B[x][y];
		}
	}
}

/* Fill christmas lights to image */
void FillLight(int number, int lightWidth, unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
{
	/*Initialize the random number generator with the current time*/
	srand(time(NULL));

	/*A random number for choosing the block to be shuffled with*/
	int random_height;
	int random_width;
	/*Varibale for color of random  light*/
	int random_color;
	int light_colorR, light_colorG, light_colorB;
	/*for loop counter variables*/
	int x, y, d;
	int light_count;

	for (light_count = 0; light_count < number; light_count++)
	{
		/*Provides a position for the center of the light*/
		/*random height 0 to 499, random width 0 to 639*/
		random_height = rand() % HEIGHT;
		random_width = rand() % WIDTH;
		
		/*Check to see if there is enough room for the light to be created, pick new position if there isn't*/
		while (random_height <= (lightWidth/2) || random_height >= (HEIGHT - lightWidth/2))
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
		R[random_width][random_height] = light_colorR;
		G[random_width][random_height] = light_colorG;
		B[random_width][random_height] = light_colorB;

		/*Up and Down*/
		for (y = 1; y <= lightWidth / 2; y++)
		{
			/*Up*/
			R[random_width][random_height - y] = light_colorR;
			G[random_width][random_height - y] = light_colorG;
			B[random_width][random_height - y] = light_colorB;
			/*Down*/
			R[random_width][random_height + y] = light_colorR;
			G[random_width][random_height + y] = light_colorG;
			B[random_width][random_height + y] = light_colorB;
		}
		
		/*Left and Right*/
		for (x = 1; x <= lightWidth / 2; x++)
		{
			/*Right*/
			R[random_width + x][random_height] = light_colorR;
			G[random_width + x][random_height] = light_colorG;
			B[random_width + x][random_height] = light_colorB;
			/*Left*/
			R[random_width - x][random_height] = light_colorR;
			G[random_width - x][random_height] = light_colorG;
			B[random_width - x][random_height] = light_colorB;
		}
		
		/*Diagonals*/
		for (d = 1; d <= lightWidth / 2; d++)
		{
			/*Diagonal Up Right*/
			R[random_width + d][random_height - d] = light_colorR;
			G[random_width + d][random_height - d] = light_colorG;
			B[random_width + d][random_height - d] = light_colorB;
			/*Diagonal Up Left*/
			R[random_width - d][random_height - d] = light_colorR;
			G[random_width - d][random_height - d] = light_colorG;
			B[random_width - d][random_height - d] = light_colorB;
			/*Diagonal Down Right*/
			R[random_width + d][random_height + d] = light_colorR;
			G[random_width + d][random_height + d] = light_colorG;
			B[random_width + d][random_height + d] = light_colorB;
			/*Diagonal Down Left*/
			R[random_width - d][random_height + d] = light_colorR;
			G[random_width - d][random_height + d] = light_colorG;
			B[random_width - d][random_height + d] = light_colorB;
		}
	}
}

/*Overaly an image onto the original image*/
void Overlay(char fname[SLEN], unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT], int x_offset, int y_offset)
{
	/*Allow Original image to be stored temporarily*/
	unsigned char original_R[WIDTH][HEIGHT];
	unsigned char original_G[WIDTH][HEIGHT];
	unsigned char original_B[WIDTH][HEIGHT];
	/*Allow Overlay image to be stored temporarily*/
	unsigned char overlay_R[WIDTH][HEIGHT];
	unsigned char overlay_G[WIDTH][HEIGHT];
	unsigned char overlay_B[WIDTH][HEIGHT];
	/*for loop counter variables*/
	int a, b;

	/*Store Original image into temp array*/
	for (b = 0; b < HEIGHT; b++)
	{
		for (a = 0; a < WIDTH; a++)
		{
			original_R[a][b] = R[a][b];
			original_G[a][b] = G[a][b];
			original_B[a][b] = B[a][b];
		}
	}

	/*Load Overlay image*/
	ReadImage(fname, R, G, B);

	/*Store Overlay image into temp array*/
	for (b = 0; b < HEIGHT; b++)
	{
		for (a = 0; a < WIDTH; a++)
		{
			overlay_R[a][b] = R[a][b];
			overlay_G[a][b] = G[a][b];
			overlay_B[a][b] = B[a][b];
		}
	}

	/*Make the entire image white*/
	for (b = 0; b < HEIGHT; b++)
	{
		for (a = 0; a < WIDTH; a++)
		{
			R[a][b] = 255;
			G[a][b] = 255;
			B[a][b] = 255;
		}
	}

	/*Set Overlay image to appropriate offset position*/
	/*x and y are the offset values*/
	for (b = 0; b < HEIGHT; b++)
	{
		for (a = 0; a < WIDTH; a++)
		{
			/*Check to see if image offset is within boundary of image size*/
			/*If it is, replace pixel with that of the Overlay image*/
			if ((a + x_offset) >= 0 && (a + x_offset) < WIDTH && (b + y_offset) >= 0 && (b + y_offset) < HEIGHT)
			{
				R[a + x_offset][b + y_offset] = overlay_R[a][b];
				G[a + x_offset][b + y_offset] = overlay_G[a][b];
				B[a + x_offset][b + y_offset] = overlay_B[a][b];
			}
		}
	}

	/*Any pixel that is white, replace with pixel from Original image*/
	for (b = 0; b < HEIGHT; b++)
	{
		for (a = 0; a < WIDTH; a++)
		{
			if (R[a][b] >= 245 && G[a][b] >= 245 && B[a][b] >= 245)
			{
				R[a][b] = original_R[a][b];
				G[a][b] = original_G[a][b];
				B[a][b] = original_B[a][b];
			}
		}
	}
}