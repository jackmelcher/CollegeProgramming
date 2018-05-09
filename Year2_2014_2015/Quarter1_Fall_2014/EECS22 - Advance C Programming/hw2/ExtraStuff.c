
printf("\n");
scanf(" ", );

char selection;
int menu = 0
char fname[SLEN]

int main()
{

	char fileName[SLEN];
	char saveName[SLEN];

	/*Variables for Color Filter. Capitalized names to show difference*/
	int target_R, target_G, target_B;
	int Threshold;
	int replace_R, replace_G, replace_B;

	/*Variables for making a border*/
	char Color[SLEN];
	int border_Width;

	while (menu < 1)
	{
		printf("----------------------------\n");
		printf("1: Load a PPM image\n");
		printf("2: Save an image in PPM and JPEG format\n");
		printf("3: Change a color image to Black & White\n");
		printf("4: Flip an image vertically\n");
		printf("5: Mirror an image horizontally\n");
		printf("6: Color filter an image\n");
		printf("7: Sketch the edge of an image\n");
		printf("8: Shuffle an image\n");
		printf("10: Test all functions\n");
		printf("11: Exit\n");
		printf("Please make your choice: ");
		scanf("%d", &selection);

		switch (selection)
		{
			case 1:
				printf("Please input the file name to load: ");
				scanf("%s", fileName);
				ReadImage(fname, R, G, B);
				break;

			case 2:
				printf("Please input the file name to save: ");
				scanf("%s", saveName);
				SaveImage(saveName, R, G, B);
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
				printf("Enter Red component for the target color: ");
				scanf("%d", &target_R);
				printf("Enter Green component for the target color: ");
				scanf("%d", &target_G);
				printf("Enter Blue component for the target color: ");
				scanf("%d", &target_B);
				printf("Enter threshold for the color difference: ");
				scanf("%d", &Threshold);
				printf("Enter value for Red component in the target color: ");
				scanf("%d", &replace_R);
				printf("Enter value for Green component in the target color: ");
				scanf("%d", &replace_G);
				printf("Enter value for Blue component in the target color: ");
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
				AutoTest(R, G, B);
				break;

			case 11:
				menu = menu + 1;
				break;

			default:
				printf("Invalid Input.\n");
				break;
		}
	}

	return 0;
}

/* change color image to black & white */
void	BlackNWhite(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
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

	printf("Black & White operation is done!\n");
}

/* flip image vertically */
void	VFlip(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
{
	int x, y;

	unsigned char tempR[WIDTH][HEIGHT];
	unsigned char tempG[WIDTH][HEIGHT];
	unsigned char tempB[WIDTH][HEIGHT];

	for (y = 0; y < HEIGHT/2; y++)
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

	printf("Vertical Flip operation is done!\n");
}

/* mirror image horizontally */
void	HMirror(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
{
	int x, y;

	for (y = 0; y < HEIGHT; y++)
	{
		for (x = 0; x < WIDTH/2; x++)
		{
			R[x][y] = R[WIDTH - 1 - x][y];
			G[x][y] = G[WIDTH - 1 - x][y];
			B[x][y] = B[WIDTH - 1 - x][y];
		}
	}

	printf("Horizontal Mirror operation is done!\n");
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
			if (R[x][y] >= Rmin && R[x][y] <= Rmax && G[x][y] >= Gmin && G[x][y] <= Gmax && B[x][y] >= Bmin && B[x][y] <= Bmax)
			{
				R[x][y] = replace_r;
					if (R[x][y] > 255)
					{
						R[x][y] = 255;
					}
					if (R[x][y] < 0)
					{
						R[x][y] = 0;
					}
				
				G[x][y] = replace_g;
					if (G[x][y] > 255)
					{
						G[x][y] = 255;
					}
					if (G[x][y] < 0)
					{
						G[x][y] = 0;
					}
				
				B[x][y] = replace_b;
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

	printf("Color Filter operation is done!\n");
}

/* edge detection */
void	Edge(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
{
	int x, y;

	for (y = 0; y < HEIGHT; y++)
	{
		for (x = 0; x < WIDTH; x++)
		{
			/*if Top-Left Corner*/
			if (x = 0 && y = 0)
			{
				R[x][y] = (R[x][y]);
				G[x][y] = (G[x][y]);
				B[x][y] = (B[x][y]);
			}
			/*if Top-Right Corner*/
			if (x = WIDTH - 1 && y = 0)
			{
				R[x][y] = (R[x][y]);
				G[x][y] = (G[x][y]);
				B[x][y] = (B[x][y]);
			}
			/*if Bottom-Left Corner*/
			if (x = 0 && y = 639)
			{
				R[x][y] = (R[x][y]);
				G[x][y] = (G[x][y]);
				B[x][y] = (B[x][y]);
			}
			/*if Bottom-Right Corner*/
			if (x = WIDTH - 1 && y = 639)
			{
				R[x][y] = (R[x][y]);
				G[x][y] = (G[x][y]);
				B[x][y] = (B[x][y]);
			}
			/*if a Top Edge*/
			if (x > 0 && x < WIDTH - 1 && y = 0)
			{
				R[x][y] = (R[x][y]);
				G[x][y] = (G[x][y]);
				B[x][y] = (B[x][y]);
			}
			
			/*if a Bottom Edge*/
			if (x > 0 && x < WIDTH - 1 && y = HEIGHT - 1)
			{
				R[x][y] = (R[x][y]);
				G[x][y] = (G[x][y]);
				B[x][y] = (B[x][y]);
			}
			
			/*if a Left Edge*/
			if (x = 0 && y > 0 && y < HEIGHT - 1)
			{
				R[x][y] = (R[x][y]);
				G[x][y] = (G[x][y]);
				B[x][y] = (B[x][y]);
			}
			
			/*if a Right Edge*/
			if (x = WIDTH - 1 && y > 0 && y < HEIGHT - 1)
			{
				R[x][y] = (R[x][y]);
				G[x][y] = (G[x][y]);
				B[x][y] = (B[x][y]);
			}

			/*All other pixels*/
			if (x > 0 && x < WIDTH - 1 && y > 0 && y < HEIGHT - 1)
			{
				R[x][y] = (8 * R[x][y] - R[x - 1][y - 1] - R[x][y - 1] - R[x + 1][y - 1] - R[x - 1][y] - R[x + 1][y] - R[x - 1][y + 1] - R[x][y + 1] - R[x + 1][y + 1]);
				if (R[x][y] > 255)
				{
					R[x][y] = 255;
				}
				if (R[x][y] < 0)
				{
					R[x][y] = 0;
				}

				G[x][y] = (8 * G[x][y] - G[x - 1][y - 1] - G[x][y - 1] - G[x + 1][y - 1] - G[x - 1][y] - G[x + 1][y] - G[x - 1][y + 1] - G[x][y + 1] - G[x + 1][y + 1]);
				if (G[x][y] > 255)
				{
					G[x][y] = 255;
				}
				if (G[x][y] < 0)
				{
					G[x][y] = 0;
				}

				B[x][y] = (8 * B[x][y] - B[x - 1][y - 1] - B[x][y - 1] - B[x + 1][y - 1] - B[x - 1][y] - B[x + 1][y] - B[x - 1][y + 1] - B[x][y + 1] - B[x + 1][y + 1]);
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

	printf("Edge operation is done!\n");
}

/* add border */
void	AddBorder(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT], char color[SLEN], int border_width)
{
	int x, y;



	/*Top Border*/
	for (y = 0; y < HEIGHT; y++)
	{
		for (x = 0; x < WIDTH; x++)
		{
			R[x][y] = color;
			G[x][y] = color;
			B[x][y] = color;
		}
	}
	/*Bottom Border*/
	for (y = 0; y < HEIGHT; y++)
	{
		for (x = 0; x < WIDTH; x++)
		{
			R[x][y] = color;
			G[x][y] = color;
			B[x][y] = color;
		}
	}
	/*Left Border*/
	for (y = 0; y < HEIGHT; y++)
	{
		for (x = 0; x < WIDTH; x++)
		{
			R[x][y] = color;
			G[x][y] = color;
			B[x][y] = color;
		}
	}
	/*Right Border*/
	for (y = 0; y < HEIGHT; y++)
	{
		for (x = 0; x < WIDTH; x++)
		{
			R[x][y] = color;
			G[x][y] = color;
			B[x][y] = color;
		}
	}

	printf("Border operation is done!\n");
}

/* shuffle image*/
void	Shuffle(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
{
	int x, y;

	/*Array to check if block was swapped*/
	int tempArray[4][4];


	/*If current block was swapped already, move on*/
	if (tempArray[current_width_block - 1][current_height_block - 1] >= 1)
	{
		current_width_block = current_width_block * 0 + 1;
	}
	



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
			/*Check to see if current block was swapped*/
			if (tempArray[current_width_block - 1][current_height_block - 1] < 1)
			{
				/*Choose a random block*/
				random_height_block = rand() % 4 + 1;
				random_width_block = rand() % 4 + 1;
				/*Check to see if random block was swapped. Pic a new block if it was*/
				while ((tempArray[random_width_block - 1][random_height_block - 1] >= 1) || (random_height_block == current_height_block && random_width_block == current_width_block))
				{
					/*choose another random block*/
					random_height_block = rand() % 4 + 1;
					random_width_block = rand() % 4 + 1;
				}
				/*After blocks are shuffled*/
				tempArray[current_width_block][current_height_block] += 1;
				tempArray[random_width_block][random_height_block] += 1;

				/*Shuffle the blocks*/
				for (y = 0; y < (HEIGHT / SHUFF_HEIGHT_DIV); y++)
				{
					for (x = 0; x < (WIDTH / SHUFF_WIDTH_DIV); x++)
					{
						/*Store current image block in temp image block*/
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
			}
		}
		
	}

	printf("Shuffle operation is done!\n");
}
/* auto test*/
void AutoTest(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
{
	char fname[SLEN] = "RingMall";
	char sname[SLEN];

	/*Variables for Color Filter. Capitalized names to show difference. Given fixed values*/
	int target_R = 180, target_G = 180, target_B = 50;
	int Threshold = 70;
	int replace_R = 0, replace_G = 255, replace_B = 0;

	/* auto test Black and White*/
	ReadImage(fname, R, G, B);
	BlackNWhite(R, G, B);
	strcpy(sname, "bw");/*string copy function to prepare the file name to be saved*/
	SaveImage(sname, R, G, B);
	printf("Black & White tested!\n\n");

	/* auto test VFlip*/
	ReadImage(fname, R, G, B);
	VFlip(R, G, B);
	strcpy(sname, "vflip");
	SaveImage(sname, R, G, B);
	printf("VFlip tested!\n\n");

	/* auto test HMirror*/
	ReadImage(fname, R, G, B);
	HMirror(R, G, B);
	strcpy(sname, "hmirror");
	SaveImage(sname, R, G, B);
	printf("HMirror tested!\n\n");
	
	/* auto test Color Filter*/
	ReadImage(fname, R, G, B);
	ColorFilter(R, G, B);
	strcpy(sname, "colorfilter");
	SaveImage(sname, R, G, B, target_R, target_G, target_B, Threshold, replace_R, replace_G, replace_B);
	printf("Color Filter tested!\n\n");
	
	/* auto test Shuffle*/
	ReadImage(fname, R, G, B);
	Shuffle(R, G, B);
	strcpy(sname, "shuffle");
	SaveImage(sname, R, G, B);
	printf("Shuffle tested!\n\n");
	
	/* auto test Edge Detection*/
	ReadImage(fname, R, G, B);
	Edge(R, G, B);
	strcpy(sname, "edge");
	SaveImage(sname, R, G, B);
	printf("Edge Detection tested!\n\n");
}

/* auto test Add Border*/
ReadImage(fname, R, G, B);
AddBorder(R, G, B, color, border_width);
strcpy(sname, "border");
SaveImage(sname, R, G, B);
printf("Add Border tested!\n\n");



/*Check which block of the picture the shuffler is at*/
int current_height_block = 1;/*1 through 4*/
int current_width_block = 1;/*1 through 4*/

/*A random number for choosing the block to be shuffled with*/
int random_height_block;
int random_width_block;

int A = 0, B = 0, C = 0, D = 0, E = 0, F = 0, G = 0, H = 0, I = 0, J = 0, K = 0, L = 0, M = 0, N = 0, O = 0, P = 0;

if (current_height_block = 1 && current_width_block = 1 || random_height_block = 1 && random_width_block = 1)
	A = 1;
if (current_height_block = 1 && current_width_block = 2 || random_height_block = 1 && random_width_block = 2)
	B = 1;
if (A != 0 && B != 0)
	/*Perform the switch*/


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

	printf("Border operation is done!\n");
}