#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define ROWS	480
#define COLS	640

#define sqr(x)	((x)*(x))

void clear( unsigned char image[][COLUMNS] );
void header( int row, int col, unsigned char head[32] );

int main( int argc, char** argv )
{
	int				i,j;
	int				dedx, dedy, sgm;
	int				sgm_threshold, hough_threshold, voting[180][400];
	FILE*			fp;
	unsigned char	image[ROWS][COLS];
	char			filename[50];
	
	strcpy ( filename, "image.raw" );
	memset ( voting, 0, sizeof(int) * 180 * 400 );


	if (!( fp = fopen( filename, "rb" ) ))
	{
		fprintf( stderr, "error: couldn't open %s\n", argv[1] );
		exit(1);
	}

	for ( i = 0 ; i < ROWS ; i++ )
		if (!( COLS == fread( image[i], sizeof(char), COLS, fp ) ))
		{
			fprintf( stderr, "error: couldn't read %s\n", argv[1] );
			exit(1);
		}
	fclose(fp);

	for ( i = ROWS-2 ; i > 0 ; i-- )
		for ( j = COLS-2 ; j > 0 ; j-- )
		{
			dedx =
					  -image[i-1][j-1] +   image[i-1][j+1] +
					-2*image[ i ][j-1] + 2*image[ i ][j+1] +
					  -image[i+1][j-1] +   image[i+1][j+1] ;

			dedy =
				-image[i-1][j-1] - 2*image[i-1][ j ] - image[i-1][j+1] +
				 image[i+1][j-1] + 2*image[i+1][ j ] + image[i+1][j+1] ;

			sgm = sqr(dedx) + sqr(dedy);

		}


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

