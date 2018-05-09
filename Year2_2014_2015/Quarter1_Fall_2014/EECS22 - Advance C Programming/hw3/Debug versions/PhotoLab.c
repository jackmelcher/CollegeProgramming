/*********************************************************/
/* PhotoLab2.c: main program file */
/*Jack Melcher 67574625*/
/*********************************************************/
#include "Constants.h"
#include "FileIO.h"
#include "DIPs.h"

/*Debug stuff*/
#ifdef DEBUG
int debugPhotoLab = 1;
#else
int debugPhotoLab = 0;
#endif


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
		if (debugPhotoLab == 0)
		{
			/*Prints the Menu*/
			PrintMenu();
			/*Allows user to make Menu selection*/
			scanf("%d", &selection);
		}
		if (debugPhotoLab == 1)
		{
			selection = 13;
		}

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
			printf("Black & White operation is done!\n");
			break;

		case 4:
			VFlip(R, G, B);
			printf("Vertical Flip operation is done!\n");
			break;

		case 5:
			HMirror(R, G, B);
			printf("Horizontal Mirror operation is done!\n");
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
			printf("Color Filter operation is done!\n");
			break;

		case 7:
			Edge(R, G, B);
			printf("Edge operation is done!\n");
			break;

		case 8:
			Shuffle(R, G, B);
			printf("Shuffle operation is done!\n");
			break;

		case 9:
			printf("Enter border width: ");
			scanf("%d", &border_Width);
			printf("Available border colors : black, white, red, green, blue, yellow, cyan, pink, orange\n");
			printf("Select border color from the options: ");
			scanf("%s", Color);
			AddBorder(R, G, B, Color, border_Width);
			printf("Border operation is done!\n");
			break;

		case 10:
			printf("Enter the number of posterization bits (1 to 8): ");
			scanf("%d", &Pbits);
			Posterize(R, G, B, Pbits);
			printf("Posterize operation is done!\n");
			break;

		case 11:
			printf("Please input number of lights: ");
			scanf("%d", &Number);
			printf("Please input the width of each light: ");
			scanf("%d", &LightWidth);
			FillLight(Number, LightWidth, R, G, B);
			printf("FillLight operation is done!\n");
			break;

		case 12:
			printf("Please input the file name for the second image: ");
			scanf("%s", overlayName);
			printf("Please input x coordinate of the overlay image: ");
			scanf("%d", &X_offset);
			printf("Please input y coordinate of the overlay image: ");
			scanf("%d", &Y_offset);
			Overlay(overlayName, R, G, B, X_offset, Y_offset);
			printf("Image Overlay operation is done!\n");
			break;

		case 13:
			AutoTest(R, G, B);
			printf("Auto Test Complete.\n");
			if (debugPhotoLab == 1)
			{
				menu = menu + 1;
			}
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

/* auto test*/
void AutoTest(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
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
	ReadImage(fname, R, G, B);
	BlackNWhite(R, G, B);
	strcpy(sname, "bw");/*string copy function to prepare the file name to be saved*/
	SaveImage(sname, R, G, B);
	if (debugPhotoLab == 1)
		printf("Black & White tested!\n\n");

	/* auto test VFlip*/
	ReadImage(fname, R, G, B);
	VFlip(R, G, B);
	strcpy(sname, "vflip");
	SaveImage(sname, R, G, B);
	if (debugPhotoLab == 1)
		printf("VFlip tested!\n\n");

	/* auto test HMirror*/
	ReadImage(fname, R, G, B);
	HMirror(R, G, B);
	strcpy(sname, "hmirror");
	SaveImage(sname, R, G, B);
	if (debugPhotoLab == 1)
		printf("HMirror tested!\n\n");

	/* auto test Color Filter*/
	ReadImage(fname, R, G, B);
	ColorFilter(R, G, B, target_R, target_G, target_B, Threshold, replace_R, replace_G, replace_B);
	strcpy(sname, "colorfilter");
	SaveImage(sname, R, G, B);
	if (debugPhotoLab == 1)
		printf("Color Filter tested!\n\n");

	/* auto test Shuffle*/
	ReadImage(fname, R, G, B);
	Shuffle(R, G, B);
	strcpy(sname, "shuffle");
	SaveImage(sname, R, G, B);
	if (debugPhotoLab == 1)
		printf("Shuffle tested!\n\n");

	/* auto test Edge Detection*/
	ReadImage(fname, R, G, B);
	Edge(R, G, B);
	strcpy(sname, "edge");
	SaveImage(sname, R, G, B);
	if (debugPhotoLab == 1)
		printf("Edge Detection tested!\n\n");

	/* auto test Border*/
	ReadImage(fname, R, G, B);
	AddBorder(R, G, B, Color, border_Width);
	strcpy(sname, "border");
	SaveImage(sname, R, G, B);
	if (debugPhotoLab == 1)
		printf("Add Border tested!\n\n");

	/* auto test Posterization*/
	ReadImage(fname, R, G, B);
	Posterize(R, G, B, 7);
	strcpy(sname, "poster");
	SaveImage(sname, R, G, B);
	if (debugPhotoLab == 1)
		printf("Posterization tested!\n\n");
	
	/* auto test Fill Light*/
	ReadImage(fname, R, G, B);
	FillLight(200, 20, R, G, B);
	strcpy(sname, "light");
	SaveImage(sname, R, G, B);
	if (debugPhotoLab == 1)
		printf("Fill Light tested!\n\n");

	/* auto test Overlay Peter*/
	ReadImage(fname, R, G, B);
	Overlay("Peter", R, G, B, 0, 0);
	strcpy(sname, "overlay_peter");
	SaveImage(sname, R, G, B);
	if (debugPhotoLab == 1)
		printf("Overlay Peter tested!\n\n");

	/* auto test Overlay Spider*/
	ReadImage(fname, R, G, B);
	Overlay("Spider", R, G, B, 90, -10);
	strcpy(sname, "overlay_spider");
	SaveImage(sname, R, G, B);
	if (debugPhotoLab == 1)
		printf("Overlay Spider tested!\n\n");
}
/* EOF PhotoLab.c */