/*********************************************************/
/* PhotoLab.c v3: main program file */
/*Jack Melcher 67574625*/
/*********************************************************/
#include "Constants.h"
#include "FileIO.h"
#include "Image.h"
#include "DIPs.h"
#include "Advanced.h"

/*Print a menu*/
void PrintMenu();

int	main()
{
	/*  R, G, B now stored in the IMAGE structure*/

	/*Menu variable*/
	int menu = 0;
	
	/*Used to store name of the image being checked*/
	char fileName[SLEN]; 

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

	/*Variable for Resize. Capitalized names to show difference*/
	unsigned int Percentage;

	IMAGE *image = NULL;

	while (menu < 1)
	{

/*For PhotoLabTest executable*/
#ifdef DEBUG
		selection = 15;/*whatever the autotest case is*/

/*For PhotoLab executable*/
#else
		/*Prints the Menu*/
		PrintMenu();
		/*Allows user to make Menu selection*/
		scanf("%d", &selection);
#endif	

		switch (selection)
		{
		/*ReadImage*/
		case 1:
			printf("Please input the file name to load: ");
			scanf("%s", fileName);
			if (image)
			{
				DeleteImage(image);
			}
			image = ReadImage(fileName);
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
			printf("Please input the resizing percentage (integer 1 to 500): ");
			scanf("%d", &Percentage);
			if (Percentage >= 1 && Percentage <= 500)
			{
				image = Resize(Percentage, image);
				printf("Resize operation is done!\n");
			}
			else
			{
				printf("Invalid Percentage!\n");
			}
			break;
		/*Rotate 90 degrees*/
		case 13:
			Rotate(image);
			printf("Rotate 90 Degrees Clockwise operation is done!\n");
			break;
		/*Add Outer Border*/
		case 14:
			break;
			
		/*AutoTest*/
		case 15:
			AutoTest(image);
			printf("Auto Test Complete.\n");
#ifdef DEBUG
			menu = menu + 1;
#endif
			break;
		/*Exit*/
		case 16:
			menu = menu + 1;
			break;
		/*Invalid Selection*/
		default:
			printf("Invalid Input.\n");
			break;
		}
	}

	if (image)
	{
		DeleteImage(image);
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
	printf("9:  Posterize the image\n");
	printf("10: Fill Lights to an image\n");
	printf("11: Overlay an image\n");
	printf("12: Resize image\n");
	printf("13: Rotate image 90 degrees clockwise\n");
	printf("14: BONUS: Add Outer Border to an image\n");
	printf("15: Test all functions\n");
	printf("16: Exit\n");
	printf("Please make your choice: ");
}

/*AutoTest Function*/
void AutoTest(IMAGE *image)
{
	char fname[SLEN] = "RingMall";
	char sname[SLEN];

	/*Clears image incase it was being used by user before starting AutoTest*/
	if (image)
	{
		DeleteImage(image);
	}

	/* auto test Black and White*/
	image = ReadImage(fname);
	BlackNWhite(image);
	strcpy(sname, "bw");
	SaveImage(sname, image);
	DeleteImage(image);
	/*For PhotoLabTest executable*/
#ifdef DEBUG
	printf("Black & White tested!\n\n");
#endif

	/* auto test VFlip*/
	image = ReadImage(fname);
	VFlip(image);
	strcpy(sname, "vflip");
	SaveImage(sname, image);
	DeleteImage(image);
#ifdef DEBUG
	printf("VFlip tested!\n\n");
#endif

	/* auto test HMirror*/
	image = ReadImage(fname);
	HMirror(image);
	strcpy(sname, "hmirror");
	SaveImage(sname, image);
	DeleteImage(image);
#ifdef DEBUG
	printf("HMirror tested!\n\n");
#endif

	/* auto test Color Filter*/
	image = ReadImage(fname);
	ColorFilter(image, 180, 180, 50, 70, 0, 255, 0);
	strcpy(sname, "colorfilter");
	SaveImage(sname, image);
	DeleteImage(image);
#ifdef DEBUG
	printf("Color Filter tested!\n\n");
#endif

	/* auto test Edge Detection*/
	image = ReadImage(fname);
	Edge(image);
	strcpy(sname, "edge");
	SaveImage(sname, image);
	DeleteImage(image);
#ifdef DEBUG
	printf("Edge Detection tested!\n\n");
#endif

	/* auto test Shuffle*/
	image = ReadImage(fname);
	Shuffle(image);
	strcpy(sname, "shuffle");
	SaveImage(sname, image);
	DeleteImage(image);
#ifdef DEBUG
	printf("Shuffle tested!\n\n");
#endif

	/* auto test Posterization*/
	image = ReadImage(fname);
	Posterize(image, 7);
	strcpy(sname, "poster");
	SaveImage(sname, image);
	DeleteImage(image);
#ifdef DEBUG
	printf("Posterization tested!\n\n");
#endif	

	/* auto test Fill Light*/
	image = ReadImage(fname);
	FillLight(image, 200, 20);
	strcpy(sname, "light");
	SaveImage(sname, image);
	DeleteImage(image);
#ifdef DEBUG
	printf("Fill Light tested!\n\n");
#endif

	/* auto test Overlay Peter*/
	image = ReadImage(fname);
	Overlay("Peter", image, 350, 300);
	strcpy(sname, "overlay_peter");
	SaveImage(sname, image);
	DeleteImage(image);
#ifdef DEBUG
	printf("Overlay Peter tested!\n\n");
#endif

	/* auto test Overlay Spider*/
	image = ReadImage(fname);
	Overlay("Spider", image, 90, -10);
	strcpy(sname, "overlay_spider");
	SaveImage(sname, image);
	DeleteImage(image);
#ifdef DEBUG
	printf("Overlay Spider tested!\n\n");
#endif
	
	/* auto test Big Resize*/
	image = ReadImage(fname);
	image = Resize(175, image);
	strcpy(sname, "bigresize");
	SaveImage(sname, image);
	DeleteImage(image);
#ifdef DEBUG
	printf("Big Resize tested!\n\n");
#endif

	/* auto test Small Resize*/
	image = ReadImage(fname);
	image = Resize(60, image);
	strcpy(sname, "smallresize");
	SaveImage(sname, image);
	DeleteImage(image);
#ifdef DEBUG
	printf("Small Resize tested!\n\n");
#endif

	/* auto test Rotate*/
	image = ReadImage(fname);
	Rotate(image);
	strcpy(sname, "rotate");
	SaveImage(sname, image);
	DeleteImage(image);
#ifdef DEBUG
	printf("Rotate 90 Degrees Clockwise tested!\n\n");
#endif
}

/* EOF PhotoLab.c */