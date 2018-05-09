/*********************************************************/
/* PhotoLab.c v3: main program file */
/*Jack Melcher 67574625*/
/*********************************************************/
#include "Constants.h"
#include "FileIO.h"
#include "DIPs.h"
#include "Image.h"

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
	int menu = 0;

	char fileName[SLEN]; /*Used to store name of the image being checked*/

	/*Variables for Color Filter. Capitalized names to show difference*/
	int target_R, target_G, target_B;
	int Threshold;
	int replace_R, replace_G, replace_B;

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
/*For PhotoLab executable*/
#ifndef DEBUG
		/*Prints the Menu*/
		PrintMenu();
		/*Allows user to make Menu selection*/
		scanf("%d", &selection);
#endif
/*For PhotoLabTest executable*/
#ifdef DEBUG
		selection = 15;/*whatever the autotest case is*/
#endif	

		switch (selection)
		{
		/*ReadImage*/
		case 1:
			printf("Please input the file name to load: ");
			scanf("%s", fileName);
			ReadImage(fileName, image);
			break;
		/*SaveImage*/
		case 2:
			printf("Please input the file name to save: ");
			scanf("%s", fileName);
			SaveImage(fileName, image);
			break;
		/*BlackNWhite*/
		case 3:
			BlackNWhite(image);
			printf("Black & White operation is done!\n");
			break;
		/*VFlip*/
		case 4:
			VFlip(image);
			printf("Vertical Flip operation is done!\n");
			break;
		/*HMirror*/
		case 5:
			HMirror(image);
			printf("Horizontal Mirror operation is done!\n");
			break;
		/*ColorFilter*/
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
			ColorFilter(image, target_R, target_G, target_B, Threshold, replace_R, replace_G, replace_B);
			printf("Color Filter operation is done!\n");
			break;
		/*Edge*/
		case 7:
			Edge(image);
			printf("Edge operation is done!\n");
			break;
		/*Shuffle*/
		case 8:
			Shuffle(image);
			printf("Shuffle operation is done!\n");
			break;
		/*Posterize*/
		case 9:
			printf("Enter the number of posterization bits (1 to 8): ");
			scanf("%d", &Pbits);
			Posterize(image, Pbits);
			printf("Posterize operation is done!\n");
			break;
		/*FillLight*/
		case 10:
			printf("Please input number of lights: ");
			scanf("%d", &Number);
			printf("Please input the width of each light: ");
			scanf("%d", &LightWidth);
			FillLight(image, Number, LightWidth);
			printf("FillLight operation is done!\n");
			break;
		/*Overlay*/
		case 11:
			printf("Please input the file name for the second image: ");
			scanf("%s", overlayName);
			printf("Please input x coordinate of the overlay image: ");
			scanf("%d", &X_offset);
			printf("Please input y coordinate of the overlay image: ");
			scanf("%d", &Y_offset);
			Overlay(overlayName, image, X_offset, Y_offset);
			printf("Image Overlay operation is done!\n");
			break;
		/*Resize*/
		case 12:
			
			break;
		/*Rotate 90 degrees*/
		case 13:
			
			break;
			
		/*AutoTest*/
		case 14:
			AutoTest(image);
			printf("Auto Test Complete.\n");
			if (debugPhotoLab == 1)
			{
				menu = menu + 1;
			}
		/*Exit*/
		case 15:
			menu = menu + 1;
		/*Invalid Selection*/
		default:
			printf("Invalid Input.\n");
			break;
		}
	}


	return 0;
	/*  end of replacing*/
}
/* end of main */

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
	printf("9:  Add Border to an image\n");
	printf("10: Posterize the image\n");
	printf("11: Fill Lights to an image\n");
	printf("12: Overlay an image\n");
	printf("13: Test all functions\n");
	printf("14: Exit\n");
	printf("Please make your choice: ");
}

/* auto test, this whole thing needs to be changed*/
void AutoTest(IMAGE *image)
{
	char fname[SLEN] = "RingMall";
	char sname[SLEN];

	/*Variables for Color Filter. Capitalized names to show difference. Given fixed values*/
	int target_R = 180, target_G = 180, target_B = 50;
	int Threshold = 70;
	int replace_R = 0, replace_G = 255, replace_B = 0;

	/*Variables for making a border. Given fixed values*/
	char Color[SLEN] = "red";
	int border_Width = 10;

	/* auto test Black and White*/
	image = ReadImage(fname);
	BlackNWhite(image);
	strcpy(sname, "bw");
	SaveImage(sname, image);
	printf("Black & White tested!\n\n");
	DeleteImage(image);
	/*For PhotoLabTest executable*/
#ifdef DEBUG
	printf("Black & White tested!\n\n");	
#endif	


	/* auto test VFlip*/
	ReadImage(fname, R, G, B);
	VFlip(R, G, B);
	strcpy(sname, "vflip");
	SaveImage(sname, R, G, B);
#ifdef DEBUG
	printf("VFlip tested!\n\n");
#endif	


	/* auto test HMirror*/
	ReadImage(fname, R, G, B);
	HMirror(R, G, B);
	strcpy(sname, "hmirror");
	SaveImage(sname, R, G, B);
#ifdef DEBUG
		printf("HMirror tested!\n\n");
#endif	


	/* auto test Color Filter*/
	ReadImage(fname, R, G, B);
	ColorFilter(R, G, B, target_R, target_G, target_B, Threshold, replace_R, replace_G, replace_B);
	strcpy(sname, "colorfilter");
	SaveImage(sname, R, G, B);
#ifdef DEBUG
	printf("Color Filter tested!\n\n");
#endif	


	/* auto test Shuffle*/
	ReadImage(fname, R, G, B);
	Shuffle(R, G, B);
	strcpy(sname, "shuffle");
	SaveImage(sname, R, G, B);
#ifdef DEBUG
	printf("Shuffle tested!\n\n");
#endif	


	/* auto test Edge Detection*/
	ReadImage(fname, R, G, B);
	Edge(R, G, B);
	strcpy(sname, "edge");
	SaveImage(sname, R, G, B);
#ifdef DEBUG
	printf("Edge Detection tested!\n\n");
#endif	


	/* auto test Posterization*/
	ReadImage(fname, R, G, B);
	Posterize(R, G, B, 7);
	strcpy(sname, "poster");
	SaveImage(sname, R, G, B);
#ifdef DEBUG
	printf("Posterization tested!\n\n");
#endif	
	
	
	/* auto test Fill Light*/
	ReadImage(fname, R, G, B);
	FillLight(200, 20, R, G, B);
	strcpy(sname, "light");
	SaveImage(sname, R, G, B);
#ifdef DEBUG
	printf("Fill Light tested!\n\n");
#endif	
		

	/* auto test Overlay Peter*/
	ReadImage(fname, R, G, B);
	Overlay("Peter", R, G, B, 0, 0);
	strcpy(sname, "overlay_peter");
	SaveImage(sname, R, G, B);
#ifdef DEBUG
	printf("Overlay Peter tested!\n\n");
#endif	
		

	/* auto test Overlay Spider*/
	ReadImage(fname, R, G, B);
	Overlay("Spider", R, G, B, 90, -10);
	strcpy(sname, "overlay_spider");
	SaveImage(sname, R, G, B);
#ifdef DEBUG
	printf("Overlay Spider tested!\n\n");
#endif	
		
}
/* EOF PhotoLab.c */

/*reference for coding*/
unsigned char GetPixelR(IMAGE *image, unsigned int x, unsigned int y)
unsigned char GetPixelG(IMAGE *image, unsigned int x, unsigned int y)
unsigned char GetPixelB(IMAGE *image, unsigned int x, unsigned int y)
void SetPixelR(IMAGE *image, unsigned int x, unsigned int y, unsigned char r)
void SetPixelG(IMAGE *image, unsigned int x, unsigned int y, unsigned char g)
void SetPixelB(IMAGE *image, unsigned int x, unsigned int y, unsigned char b)
/*quick copy and paste functions*/
GetPixelR(image, x, y);
GetPixelG(image, x, y);
GetPixelB(image, x, y);
SetPixelR(image, x, y, r);
SetPixelG(image, x, y, g);
SetPixelB(image, x, y, b);




/*Overaly an image onto the original image*/
IMAGE *Overlay(char fname[SLEN], IMAGE *image, int x_offset, int y_offset)
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

	return image;
}

/*EOF Advanced.c*/

/*Variable for Resize. Capitalized names to show difference*/
unsigned int Percentage;

/*Resize*/
printf("Please input the resizing percentage (integer 1 to 500): ");
scanf("%d", &Percentage);
Resize(Percentage, image);
printf("Resize operation is done!\n");

/*Resize Image*/
IMAGE *Resize(unsigned int percentage, IMAGE *image);

/*Resize Image*/
IMAGE *Resize(unsigned int percentage, IMAGE *image)
{
	/*for loop counter variables*/
	unsigned int x, y;
	/*Resizing variables*/
	unsigned int x1, x2, y1, y2;

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

	/*Change the width and height*/
	image->Width = (percentage / 100) * image->Width;
	image->Height = (percentage / 100) * image->Height;

	/*Resize bigger image*/
	if (percentage > 100)
	{
		for (y = 0; y < image->Height; y++)
		{
			for (x = 0; x < image->Width; x++)
			{
				x1 = x / (percentage / 100);
				x2 = (x + 1) / (percentage / 100);
				y1 = y / (percentage / 100);
				y2 = (y + 1) / (percentage / 100);

				SetPixelR(image, x, y, GetPixelR(image_tmp, x1, y1));
				SetPixelG(image, x, y, GetPixelG(image_tmp, x1, y1));
				SetPixelB(image, x, y, GetPixelB(image_tmp, x1, y1));
			}
		}
	}

	/*Resize smaller image*/
	if (percentage < 100)
	{

	}

	/*Delete image_tmp*/
	DeleteImage(image_tmp);

	return image;
}


/*Variables for making an outer border*/
char Color[SLEN];
int border_Width;

/* Add outer border */
IMAGE *AddOuterBorder(IMAGE *image, char color[SLEN], int border_width);

/* Add outer border */
printf("Enter border width: ");
scanf("%d", &border_Width);
printf("Available border colors : black, white, red, green, blue, yellow, cyan, pink, orange\n");
printf("Select border color from the options: ");
scanf("%s", Color);
AddOuterBorder(image, Color, border_Width);

/* add outer border */
IMAGE *AddOuterBorder(IMAGE *image, char color[SLEN], int border_width)
{
	/*for loop counter variables*/
	unsigned int x, y;

	char black[SLEN] = "black";
	char white[SLEN] = "white";
	char red[SLEN] = "red";
	char green[SLEN] = "green";
	char blue[SLEN] = "blue";
	char yellow[SLEN] = "yellow";
	char cyan[SLEN] = "cyan";
	char pink[SLEN] = "pink";
	char orange[SLEN] = "orange";

	unsigned char temp1_R, temp1_G, temp1_B;

	/*Create image_tmp to hold original image*/
	IMAGE *image_tmp = NULL;
	image_tmp = CreateImage(image->Width, image->Height);

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

	/*Change the width and height*/
	image->Width = image->Width + border_width;
	image->Height = image->Height + border_width;

	/*Insert the border*/
	/*Top Border*/
	for (y = 0; y < border_width; y++)
	{
		for (x = 0; x < image->Width; x++)
		{
			SetPixelR(image, x, y, temp1_R);
			SetPixelG(image, x, y, temp1_G);
			SetPixelB(image, x, y, temp1_B);
		}
	}
	/*Bottom Border*/
	for (y = (image->Height - border_width); y < image->Height; y++)
	{
		for (x = 0; x < image->Width; x++)
		{
			SetPixelR(image, x, y, temp1_R);
			SetPixelG(image, x, y, temp1_G);
			SetPixelB(image, x, y, temp1_B);
		}
	}
	/*Left Border*/
	for (y = 0; y < image->Height; y++)
	{
		for (x = 0; x < border_width; x++)
		{
			SetPixelR(image, x, y, temp1_R);
			SetPixelG(image, x, y, temp1_G);
			SetPixelB(image, x, y, temp1_B);
		}
	}
	/*Right Border*/
	for (y = 0; y < image->Height; y++)
	{
		for (x = (image->Width - border_width); x < image->Width; x++)
		{
			SetPixelR(image, x, y, temp1_R);
			SetPixelG(image, x, y, temp1_G);
			SetPixelB(image, x, y, temp1_B);
		}
	}

	/*Re-insert the image inside the border*/
	for (y = border_width; y < (image->Height - border_width); y++)
	{
		for (x = border_width; x < (image->Width - border_width); x++)
		{
			SetPixelR(image, x, y, GetPixelR(image_tmp, x - border_width, y - border_width));
			SetPixelG(image, x, y, GetPixelG(image_tmp, x - border_width, y - border_width));
			SetPixelB(image, x, y, GetPixelB(image_tmp, x - border_width, y - border_width));
		}
	}

	/*Delete image_tmp*/
	DeleteImage(image_tmp);

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
				tempArray_R[x][y] = (8 * GetPixelR(image, x, y) - GetPixelR(image, x - 1, y - 1) - GetPixelR(image, x, y - 1) - GetPixelR(image, x + 1, y - 1) - GetPixelR(image, x - 1, y) - GetPixelR(image, x + 1, y) - GetPixelR(image, x - 1, y + 1) - GetPixelR(image, x, y + 1) - GetPixelR(image, x + 1, y + 1));
				/*Check to see if correct color intensity is within range and correct if necessary*/
				if (tempArray_R[x][y] > 255)
				{
					tempArray_R[x][y] = 255;
				}
				if (tempArray_R[x][y] < 0)
				{
					tempArray_R[x][y] = 0;
				}

				tempArray_G[x][y] = (8 * GetPixelG(image, x, y) - GetPixelG(image, x - 1, y - 1) - GetPixelG(image, x, y - 1) - GetPixelG(image, x + 1, y - 1) - GetPixelG(image, x - 1, y) - GetPixelG(image, x + 1, y) - GetPixelG(image, x - 1, y + 1) - GetPixelG(image, x, y + 1) - GetPixelG(image, x + 1, y + 1));
				/*Check to see if correct color intensity is within range and correct if necessary*/
				if (tempArray_G[x][y] > 255)
				{
					tempArray_G[x][y] = 255;
				}
				if (tempArray_G[x][y] < 0)
				{
					tempArray_G[x][y] = 0;
				}

				tempArray_B[x][y] = (8 * GetPixelB(image, x, y) - GetPixelB(image, x - 1, y - 1) - GetPixelB(image, x, y - 1) - GetPixelB(image, x + 1, y - 1) - GetPixelB(image, x - 1, y) - GetPixelB(image, x + 1, y) - GetPixelB(image, x - 1, y + 1) - GetPixelB(image, x, y + 1) - GetPixelB(image, x + 1, y + 1));
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
			tempR = tempArray_R[x][y];
			tempG = tempArray_G[x][y];
			tempB = tempArray_B[x][y];

			SetPixelR(image, x, y, tempR);
			SetPixelG(image, x, y, tempG);
			SetPixelB(image, x, y, tempB);
		}
	}

	return image;
}

/*Big Resize*/
if (percentage > 100)
{
	for (x = 0; x < new_Width; x++)
	{
		for (y = 0; y < new_Height; y++)
		{
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
			/*average color value then implement it into new image*/
			SetPixelR(image_tmp, x, y, tmpR / ((x2 - x1) * (y2 - y1)));
			SetPixelG(image_tmp, x, y, tmpG / ((x2 - x1) * (y2 - y1)));
			SetPixelB(image_tmp, x, y, tmpB / ((x2 - x1) * (y2 - y1)));
		}
	}
}