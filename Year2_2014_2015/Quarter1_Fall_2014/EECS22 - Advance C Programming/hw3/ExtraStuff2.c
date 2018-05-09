

int	main()
{
	/*
	* Two dimensional arrays to hold the current image data. One array
	* for each color component
	* */

	unsigned char   R[WIDTH][HEIGHT];
	unsigned char   G[WIDTH][HEIGHT];
	unsigned char   B[WIDTH][HEIGHT];

	/*  Please replace the following code with proper menu  */
	/*	with function calls for DIP operations		*/
	int selection;
	int menu = 0;

	char fileName[SLEN]; /*Used to store name of the image to be read*/

	/*Variables for Color Filter. Capitalized names to show difference*/
	int target_R, target_G, target_B;
	int Threshold;
	int replace_R, replace_G, replace_B;
	
	/*Variables for making a border*/
	char Color[SLEN];
	int border_Width;
	
	/*Variables for Posterization. Capitalized names to show difference*/
	unsigned int Pbits;

	/*Variables for FillLight. Capitalized names to show difference*/
	int Number;
	int LightWidth;

	/*Variables for Overlay. Capitalized names to show difference*/
	char overlayName[SLEN];
	int X_offset;
	int Y_offset;

	while (menu < 1)
	{
		/*Prints the Menu*/
		PrintMenu();
		/*Allows user to make Menu selection*/
		scanf("%d", &selection);

		switch (selection)
		{
		case 1:
			printf("Please input the file name to load: ");
			scanf("%s", fileName);
			ReadImage(fileName, R, G, B);
			break;

		case 2:
			printf("Please input the file name to save: ");
			scanf("%s", fileName);
			SaveImage(fileName, R, G, B);
			break;

		case 3:
			BlackNWhite(R, G, B);
			break;

		case 4:
			VFlip(R, G, B);
			break;

		case 5:
			HMirror(R, G, B);
			break;

		case 6:
			printf("Enter Red	component for the target color: ");
			scanf("%d", &target_R);
			printf("Enter Green component for the target color: ");
			scanf("%d", &target_G);
			printf("Enter Blue	component for the target color: ");
			scanf("%d", &target_B);
			printf("Enter threshold for the color difference: ");
			scanf("%d", &Threshold);
			printf("Enter value for Red	  component in the target color: ");
			scanf("%d", &replace_R);
			printf("Enter value for Green component in the target color: ");
			scanf("%d", &replace_G);
			printf("Enter value for Blue  component in the target color: ");
			scanf("%d", &replace_B);
			ColorFilter(R, G, B, target_R, target_G, target_B, Threshold, replace_R, replace_G, replace_B);
			break;

		case 7:
			Edge(R, G, B);
			break;

		case 8:
			Shuffle(R, G, B);
			break;

		case 9:
			printf("Enter border width: ");
			scanf("%d", &border_Width);
			printf("Available border colors : black, white, red, green, blue, yellow, cyan, pink, orange\n");
			printf("Select border color from the options: ");
			scanf("%s", Color);
			AddBorder(R, G, B, Color, border_Width);
			break;

		case 10:
			printf("Enter the number of posterization bits (1 to 8): ");
			scanf("%d", &Pbits);
			Posterize(R, G, B, Pbits);

		case 11:
			printf("Please input number of lights: ");
			scanf("%d", &Number);
			printf("Please input the width of each light: ");
			scanf("%d", &LightWidth);
			FillLight(Number, LightWidth, R, G, B);

		case 12:
			printf("Please input the file name for the second image: ");
			scanf("%s", overlayName);
			printf("Please input x coordinate of the overlay image: ");
			scanf("%d", &X_offset);
			printf("Please input y coordinate of the overlay image: ");
			scanf("%d", &Y_offset);
			Overlay(overlayName, R, G, B, X_offset, Y_offset);
		
		case 13:
			AutoTest(R, G, B);
			break;

		case 14:
			menu = menu + 1;
			break;

		default:
			printf("Invalid Input.\n");
			break;
		}
	}

	return 0;
	/*  end of replacing*/
}

/* print a menu */
void PrintMenu()
{
	printf("------------------------------\n");
	printf("1:  Load a PPM image\n");
	printf("2:  Save an image in PPM and JPEG format\n");
	printf("3:  Change a color image to Black & White\n");
	printf("4:  Flip an image vertically\n");
	printf("5:  Mirror an image horizontally\n");
	printf("6:  Color filter an image\n");
	printf("7:  Sketch the edge of an image\n");
	printf("8:  Shuffle an image\n");
	printf("9:  BONUS: Add Border to an image\n");
	printf("10: Posterize the image\n");
	printf("11: Fill Lights to an image\n");
	printf("12: Overlay an image\n");
	printf("13: Test all functions\n");
	printf("14: Exit\n");
	printf("Please make your choice: ");
}


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
	int i;

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

			for (i = 1; i < pbits; i++)
			{
				posterization_value = posterization_value + pow(2, pbits - i);
			}

			/*Set posterization based on pbits chosen*/
			R[x][y] = R[x][y] & posterization_value;
			G[x][y] = G[x][y] & posterization_value;
			B[x][y] = B[x][y] & posterization_value;

			/*Shift original value to accomodate for the pbits choice. Shift causes 1's and 0's to drop off*/
			temp_R = temp_R[x][y] >> pbits;
			temp_G = temp_G[x][y] >> pbits;
			temp_B = temp_B[x][y] >> pbits;

			/*Shift back and end up with a new number*/
			temp_R = temp_R[x][y] << pbits;
			temp_G = temp_G[x][y] << pbits;
			temp_B = temp_B[x][y] << pbits;

			/*Posterize value is obtained*/
			R[x][y] = R[x][y] | temp_R[x][y];
			G[x][y] = G[x][y] | temp_G[x][y];
			B[x][y] = B[x][y] | temp_B[x][y];
		}
	}
	printf("Posterize operation is done!\n");
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
		while (random_height <= (lightWidth / 2) || random_height >= (HEIGHT - lightWidth / 2))
		{
			random_height = rand() % HEIGHT;
		}
		while (random_width <= (lightWidth / 2) || random_width >= (WIDTH - lightWidth / 2))
		{
			random_width = rand() % WIDTH;
		}

		/*Randomly choose color of light. 1 = red, 2 = green, 3 = blue*/
		int random_color = rand() % 3 + 1;
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

	printf("FillLight operation is done!\n");
}

/*Advanced Functions*/

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
			if ((a + x) >= 0 && (a + x) < WIDTH && (b + y) >= 0 && (b + y) < HEIGHT)
			{
				R[a + x][b + y] = overlay_R[a][b];
				G[a + x][b + y] = overlay_G[a][b];
				B[a + x][b + y] = overlay_B[a][b];
			}
		}
	}

	/*Any pixel that is white, replace with pixel from Original image*/
	for (b = 0; b < HEIGHT; b++)
	{
		for (a = 0; a < WIDTH; a++)
		{
			if (R[a][b] = 255 && G[a][b] = 255 && B[a][b] = 255)
			{
				R[a][b] = original_R[a][b];
				G[a][b] = original_G[a][b];
				B[a][b] = original_B[a][b];
			}
		}
	}


	printf("Image Overlay operation is done!\n");
}