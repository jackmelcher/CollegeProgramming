// Jack Melcher
// 67574625
// EECS 101
// HW4

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS		(int)480
#define COLUMNS		(int)640

void clear( unsigned char image[][COLUMNS] );
void header( int row, int col, unsigned char head[32] );

int main( int argc, char **argv )
{

	int				i, j, k, threshold[3], max[3], x, y, s;
	FILE			*fp;
	unsigned char	image[ROWS][COLUMNS], ximage[ROWS][COLUMNS], yimage[ROWS][COLUMNS], simage[ROWS][COLUMNS], bimage[ROWS][COLUMNS], head[32];
	char			filename[6][50], ifilename[50], ch;

	float tempf = 0;
	float fximage[ROWS][COLUMNS], fyimage[ROWS][COLUMNS], fsimage[ROWS][COLUMNS];

	//Choosing thresholds for binary image
	threshold[0] = 45;
	threshold[1] = 5;
	threshold[2] = 15;


	strcpy( filename[0], "image1" );
	strcpy( filename[1], "image2" );
	strcpy( filename[2], "image3" );
	header ( ROWS, COLUMNS, head );

	printf( "Maximum of Gx, Gy, SGM\n" );
	for ( k = 0; k < 3; k ++)
	{
		clear( ximage );
		clear( yimage );

		/* Read in the image */
		strcpy( ifilename, filename[k] );
		if (( fp = fopen( strcat(ifilename, ".raw"), "rb" )) == NULL )
		{
		  fprintf( stderr, "error: couldn't open %s\n", ifilename );
		  exit( 1 );
		}			
		for ( i = 0; i < ROWS ; i++ )
		  if ( fread( image[i], sizeof(char), COLUMNS, fp ) != COLUMNS )
		  {
			fprintf( stderr, "error: couldn't read enough stuff\n" );
			exit( 1 );
		  }
		fclose( fp );

		max[0] = 0; //maximum of Gx
		max[1] = 0; //maximum of Gy
		max[2] = 0; //maximum of SGM

		/* Compute Gx, Gy, SGM, find out the maximum and normalize*/
		
		//printf("Calculating Gx\n");
		//Determine max value for Gx
		for (i = 1; i < ROWS - 1; i++) {
			for (j = 1; j < COLUMNS - 1; j++) {
				tempf = -1* (float)image[i - 1][j - 1] - 2* (float)image[i][j - 1] - (float)image[i + 1][j - 1] + (float)image[i - 1][j + 1] + 2* (float)image[i][j + 1] + (float)image[i + 1][j + 1];
				if (tempf < 0) {
					tempf = -1 * tempf;
				}
				if (tempf > max[0]) {
					max[0] = tempf;
				}
				fximage[i][j] = tempf;
			}
		}
		
		//printf("max[0] = %d\n", max[0]);
		tempf = (float)255 / (float)max[0];
		//printf("tempf = %f\n", tempf);

		//Make Gx image
		for (i = 1; i < ROWS - 1; i++) {
			for (j = 1; j < COLUMNS - 1; j++) {
				x = fximage[i][j] * tempf;
				if (x > 255) {
					ximage[i][j] = 255;
				}
				else {
					ximage[i][j] = x;
				}
			}
		}

		//printf("Calculating Gy\n");
		//Determine max value for Gy
		for (i = 1; i < ROWS - 1; i++) {
			for (j = 1; j < COLUMNS - 1; j++) {
				tempf = -1 * (float)image[i - 1][j - 1] - 2 * (float)image[i - 1][j] - (float)image[i - 1][j + 1] + (float)image[i + 1][j - 1] + 2* (float)image[i + 1][j] + (float)image[i + 1][j + 1];
				if (tempf < 0) {
					tempf = -1 * tempf;
				}

				if (tempf > max[1]) {
					max[1] = tempf;
				}
				fyimage[i][j] = tempf;
			}
		}

		//printf("max[1] = %d\n", max[1]);
		tempf = (float)255 / (float)max[1];
		//printf("tempf = %f\n", tempf);

		//Make Gy image
		for (i = 1; i < ROWS - 1; i++) {
			for (j = 1; j < COLUMNS - 1; j++) {
				y = fyimage[i][j] * tempf;
				if (y > 255) {
					yimage[i][j] = 255;
				}
				else {
					yimage[i][j] = y;
				}
			}
		}

		//printf("Calculating SGM\n");
		//Determine max value for SGM
		for (i = 1; i < ROWS - 1; i++) {
			for (j = 1; j < COLUMNS - 1; j++) {
				tempf = (fximage[i][j] * fximage[i][j]) + (fyimage[i][j] * fyimage[i][j]);

				if (tempf > max[2]) {
					max[2] = tempf;
				}

				fsimage[i][j] = tempf;
			}
		}

		//printf("max[2] = %d\n", max[2]);
		tempf = (float)255 / (float)max[2];
		//printf("tempf = %f\n", tempf);

		//Make SGM image
		for (i = 1; i < ROWS - 1; i++) {
			for (j = 1; j < COLUMNS - 1; j++) {
				s = fsimage[i][j] * tempf;
				if (s > 255) {
					simage[i][j] = 255;
				}
				else {
					simage[i][j] = s;
				}
			}
		}

		//printf("Saving Images\n");

		/* Write Gx to a new image*/
		strcpy( ifilename, filename[k] );
		if (!( fp = fopen( strcat( ifilename, "-x.ras" ), "wb" ) ))
		{
		  fprintf( stderr, "error: could not open %s\n", ifilename );
		  exit( 1 );
		}
		fwrite( head, 4, 8, fp );		

		for (i = 0; i < ROWS; i++) fwrite(ximage[i], 1, COLUMNS, fp);
	
		fclose( fp );
					
		/* Write Gy to a new image */
		strcpy( ifilename, filename[k] );
		if (!( fp = fopen( strcat( ifilename, "-y.ras" ), "wb" ) ))
		{
		  fprintf( stderr, "error: could not open %s\n", ifilename );
		  exit( 1 );
		}
		fwrite( head, 4, 8, fp );
		
		for (i = 0; i < ROWS; i++) fwrite(yimage[i], 1, COLUMNS, fp);
		
		fclose( fp );

		

		/* Write SGM to a new image */
		strcpy( ifilename, filename[k] );
		if (!( fp = fopen( strcat( ifilename, "-s.ras" ), "wb" ) ))
		{
		  fprintf( stderr, "error: could not open %s\n", ifilename );
		  exit( 1 );
		}
		fwrite( head, 4, 8, fp );
		
		for (i = 0; i < ROWS; i++) fwrite(simage[i], 1, COLUMNS, fp);
		
		fclose( fp );
		
		//printf("Calculating binary image\n");
		/* Compute the binary image */
		for (i = 1; i < ROWS - 1; i++) {
			for (j = 1; j < COLUMNS - 1; j++) {
				
				if (simage[i][j] > threshold[k]) {
					bimage[i][j] = 255;
				}
				else {
					bimage[i][j] = 0;
				}
			}
		}



		/* Write the binary image to a new image */
		strcpy( ifilename, filename[k] );
		if (!( fp = fopen( strcat( ifilename, "-b.ras" ), "wb" ) ))
		{
		  fprintf( stderr, "error: could not open %s\n", ifilename );
		  exit( 1 );
		}
		fwrite( head, 4, 8, fp );
		
		for (i = 0; i < ROWS; i++) fwrite(bimage[i], 1, COLUMNS, fp);
		
		fclose( fp );
	
		printf("max[0] = %d, max[1] = %d, max[2] = %d\n", max[0], max[1], max[2]);
	}


	printf( "Press any key to exit: " );
	gets( &ch );
	return 0;
}

void clear( unsigned char image[][COLUMNS] )
{
	int	i,j;
	for ( i = 0 ; i < ROWS ; i++ )
		for ( j = 0 ; j < COLUMNS ; j++ ) image[i][j] = 0;
}

void header( int row, int col, unsigned char head[32] )
{
	int *p = (int *)head;
	char *ch;
	int num = row * col;

	/* Choose little-endian or big-endian header depending on the machine. Don't modify this */
	/* Little-endian for PC */
	
	*p = 0x956aa659;
	*(p + 3) = 0x08000000;
	*(p + 5) = 0x01000000;
	*(p + 6) = 0x0;
	*(p + 7) = 0xf8000000;

	ch = (char*)&col;
	head[7] = *ch;
	ch ++; 
	head[6] = *ch;
	ch ++;
	head[5] = *ch;
	ch ++;
	head[4] = *ch;

	ch = (char*)&row;
	head[11] = *ch;
	ch ++; 
	head[10] = *ch;
	ch ++;
	head[9] = *ch;
	ch ++;
	head[8] = *ch;
	
	ch = (char*)&num;
	head[19] = *ch;
	ch ++; 
	head[18] = *ch;
	ch ++;
	head[17] = *ch;
	ch ++;
	head[16] = *ch;
	

	/* Big-endian for unix */
	/*
	*p = 0x59a66a95;
	*(p + 1) = col;
	*(p + 2) = row;
	*(p + 3) = 0x8;
	*(p + 4) = num;
	*(p + 5) = 0x1;
	*(p + 6) = 0x0;
	*(p + 7) = 0xf8;
*/
}
