/*********************************************************************/
/* PhotoLab.c: homework assignment #2, for EECS 22,  Fall 2014       */
/*                                                                   */
/* History:                                                          */
/* 10/07/14 Manjunath MV  updated for EECS22 assignment2 Fall2014    */
/* 10/03/13 Che-Wei Chang  updated for EECS22 assignment2 Fall2013   */
/* 10/02/12 Weiwei Chen  updated for EECS22 assignment2 Fall2012     */
/* 09/27/11 Weiwei Chen  updated for EECS22 assignment2 Fall2011     */
/* 11/11/04 Rainer Doemer:   update for EECS 10 formatting style     */
/* 11/10/04 Rustam Sengupta: initial template version                */
/*********************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*** global definitions ***/
#define WIDTH  640		/* Image width */
#define HEIGHT 500		/* image height */
#define SLEN    80		/* maximum length of file names and string*/
#define SHUFF_HEIGHT_DIV 4      /* Height division for shuffling */
#define SHUFF_WIDTH_DIV 4       /* Width division for shuffling */
/*** function declarations ***/

/* print a menu */
void	PrintMenu();

/* read image from a file */
int	ReadImage(char fname[SLEN], unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT]);

/* save a processed image */
int	SaveImage(char fname[SLEN], unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT]);

/* change color image to black & white */
void	BlackNWhite(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT]);

/* flip image vertically */
void	VFlip(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT]);

/* mirror image horizontally */
void	HMirror(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT]);

/* color filter */
void 	ColorFilter(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT], 
		int target_r, int target_g, int target_b, int threshold, int replace_r, int replace_g, int replace_b) ; 

/* sharpen the image */
void	Shuffle(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT]);

/* edge detection */
void	Edge(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT]);

/* add border */
void	AddBorder(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT], 
		char color[SLEN], int border_width);

/* Test all functions */
void	AutoTest(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT]);

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

	AutoTest(R, G, B);
	/*  end of replacing*/
}

int
ReadImage(char fname[SLEN], unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
{
	FILE           *File;
	char            Type[SLEN];
	int             Width, Height, MaxValue;
	int             x, y;
	char            ftype[] = ".ppm";
  	char            fname_tmp[SLEN];  /*avoid to modify on the original pointer, 11/10/10, X.Han*/

  	strcpy(fname_tmp, fname);
	strcat(fname_tmp, ftype);

	File = fopen(fname_tmp, "r");
	if (!File) {
		printf("Cannot open file \"%s\" for reading!\n", fname);
		return 1;
	}
	fscanf(File, "%79s", Type);
	if (Type[0] != 'P' || Type[1] != '6' || Type[2] != 0) {
		printf("\nUnsupported file format!\n");
		return 2;
	}
	fscanf(File, "%d", &Width);
	if (Width != WIDTH) {
		printf("\nUnsupported image width %d!\n", Width);
		return 3;
	}
	fscanf(File, "%d", &Height);
	if (Height != HEIGHT) {
		printf("\nUnsupported image height %d!\n", Height);
		return 4;
	}
	fscanf(File, "%d", &MaxValue);
	if (MaxValue != 255) {
		printf("\nUnsupported image maximum value %d!\n", MaxValue);
		return 5;
	}
	if ('\n' != fgetc(File)) {
		printf("\nCarriage return expected!\n");
		return 6;
	}
	for (y = 0; y < HEIGHT; y++)
		for (x = 0; x < WIDTH; x++) {
			R[x][y] = fgetc(File);
			G[x][y] = fgetc(File);
			B[x][y] = fgetc(File);
		}
	if (ferror(File)) {
		printf("\nFile error while reading from file!\n");
		return 7;
	}
	printf("%s was read successfully!\n", fname_tmp);
	fclose(File);
	return 0;
}

int
SaveImage(char fname[SLEN], unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
{
	FILE	*File;
	int	x, y;
	char	SysCmd[SLEN * 5];

	char	ftype[] = ".ppm";
	char	fname_tmp[SLEN];  /*avoid to modify on the original pointer, 11/10/10, X.Han*/
  	char	fname_tmp2[SLEN];

	strcpy(fname_tmp, fname);
	strcpy(fname_tmp2, fname);
	strcat(fname_tmp2, ftype);

	File = fopen(fname_tmp2, "w");
	if (!File) {
		printf("Cannot open file \"%s\" for writing!\n", fname);
		return 1;
	}
	fprintf(File, "P6\n");
	fprintf(File, "%d %d\n", WIDTH, HEIGHT);
	fprintf(File, "255\n");

	for (y = 0; y < HEIGHT; y++)
		for (x = 0; x < WIDTH; x++) {
			fputc(R[x][y], File);
			fputc(G[x][y], File);
			fputc(B[x][y], File);
		}

	if (ferror(File)) {
		printf("\nFile error while writing to file!\n");
		return 2;
	}
	fclose(File);
	printf("%s was saved successfully. \n", fname_tmp2);

	/*
	 * rename file to image.ppm, convert it to ~/public_html/<fname>.jpg
	 * and make it world readable
	 */
	sprintf(SysCmd, "/users/grad2/doemer/eecs22/bin/pnmtojpeg_hw2.tcsh %s", fname_tmp2);
	if (system(SysCmd) != 0) {
		printf("\nError while converting to JPG:\nCommand \"%s\" failed!\n", SysCmd);
		return 3;
	}
	printf("%s.jpg was stored for viewing. \n", fname_tmp);

	return (0);
}


/* age the image to make it look like old picture */
void
Aging(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
{
  int x, y;

  for( y = 0; y < HEIGHT; y++ )
    for( x = 0; x < WIDTH; x++ ) {
      B[x][y] = ( R[x][y]+G[x][y]+B[x][y] )/5;
      R[x][y] = (unsigned char) (B[x][y]*1.6);
      G[x][y] = (unsigned char) (B[x][y]*1.6);
  }
}

/* auto test*/
void
AutoTest(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
{
	char fname[SLEN] = "RingMall";
  	char sname[SLEN];

	ReadImage(fname, R, G, B);
	Aging(R, G, B);
  	strcpy(sname, "aging");
	SaveImage(sname, R, G, B);
	printf("Aging tested!\n\n");

	/*
 	*	 	
 	* Filling this part with the call to your DIP functions
 	*/				
}
