/*********************************************************************/
/* MovieLab.c: homework assignment #5, for EECS 22,	Fall 2011		 */
/*																	 */
/* History:															 */
/* 10/30/11 Weiwei Chen	updated for EECS22 assignment5 FAll2011		 */
/* 10/30/11 Weiwei Chen	: initial template version					 */
/*                                                                   */
/* Jack Melcher 67574625                                             */
/*********************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "DIPs.h"
#include "Image.h"
#include "Movie.h"
#include "ImageList.h"

/*save the movie frames to the output file */
int SaveMovie(const char *fname, MOVIE *movie);

/*read one frame from the movie */
IMAGE* ReadOneFrame(const char* fname, int nFrame, unsigned int W, unsigned H);

/*read the movie frames from the input file */
int ReadMovie(const char *fname, int nFrame, unsigned int W, unsigned H, MOVIE *movie);

/* Print the command line parameter usage of the program*/
void PrintUsage();

/* type define the function pointer to the DIP function	*/
typedef void MOP_F(IMAGE *image);

/* the function for perform DIP operations on the movie*/
void Movie_DIP_Operation(MOVIE *movie, MOP_F *MovieOP);


int main(int argc, char *argv[])
{
	int x = 0;
	char *fin = NULL, *fout = NULL;
	/*Movie parameters*/
	unsigned int Width = 0, Height = 0, NumFrames = 0;
	MOVIE *movie;
	/*booleans*/
	int bw = 0, vflip = 0, hmirror = 0, edge = 0, poster = 0, cut = 0, resize = 0, fast = 0, reverse = 0;
	/*pointer to function*/
	MOP_F *DIPs_ptr = NULL;
	/*parameters for ImageList functions*/
	unsigned int SFrame, EFrame, percentage, ff_factor;

 /*entering while loop to check options entered*/
	while(x < argc)
	{
		/*-i specify input video*/
		if(0 == strcmp(&argv[x][0], "-i")) 
		{
			if(x < argc - 1)
			{
				fin = (char *)malloc(sizeof(char) * (strlen(&argv[x + 1][0]) + strlen(".yuv") + 1));
				strcpy(fin, argv[x + 1]);
				strcat( fin, ".yuv");
			}/*fi*/
			else
			{
				printf("Missing argument for input name!\n");
				free(fin);
				free(fout);
				return 5;
			}/*esle*/
			x += 2;
			continue;
		}/*fi*/

		/*-o specify output video*/
		if(0 == strcmp(&argv[x][0], "-o")) 
		{
			if(x < argc - 1)
			{
				fout = (char *)malloc(sizeof(char) * (strlen(&argv[x + 1][0]) + strlen(".yuv") + 1));
				strcpy(fout, argv[x + 1]);
				strcat( fout, ".yuv");
			}/*fi*/
			else
			{
				printf("Missing argument for output name!\n");
				free(fin);
				free(fout);
				return 5;
			}/*esle*/
			x += 2;
			continue;
		}/*fi*/

		/*"-f [no_frames]    to determine how many frames desired in the input stream\n"*/
		if (0 == strcmp(&argv[x][0], "-f"))
		{
			/*move to input value*/
			x++;
			/*check if input is valid*/
			if (sscanf(argv[x], "%d", &NumFrames) == 1)
			{
				/* input is correct */
				/* NumFrames stored*/
			}
			else
			{
				printf("Missing argument for Number of Frames!\n");
				PrintUsage();
				free(fin);
				free(fout);
				return 5;
			}/*esle*/
			x++;
			continue;
		}

		/*"-s [WidthxHeight] to set resolution of the input stream (widthxheight)\n"*/
		if (0 == strcmp(&argv[x][0], "-s"))
		{
			/*move to input value*/
			x++;
			/*check if input is valid*/
			if (sscanf(argv[x], "%dx%d", &Width, &Height) == 2)
			{
				/* input is correct */
				/* Width is stored */
				/* Height is stored */
			}
			else
			{
				printf("Missing argument for image resolution!\n");
				PrintUsage();
				free(fin);
				free(fout);
				return 5;
			}
			x++;
			continue;
		}

		/*"-bw to activate the conversion to black and white\n"*/
		if (0 == strcmp(&argv[x][0], "-bw"))
		{
			bw = 1;
			x++;
			continue;
		}

		/*"-vflip to activate vertical flip\n"*/
		if (0 == strcmp(&argv[x][0], "-vflip"))
		{
			vflip = 1;
			x++;
			continue;
		}

		/*"-hmirror to activate horizontal mirror\n"*/
		if (0 == strcmp(&argv[x][0], "-hmirror"))
		{
			hmirror = 1;
			x++;
			continue;
		}

		/*"-edge to activate edge filter\n"*/
		if (0 == strcmp(&argv[x][0], "-edge"))
		{
			edge = 1;
			x++;
			continue;
		}

		/*"-poster to activate posterize filter\n"*/
		if (0 == strcmp(&argv[x][0], "-poster"))
		{
			poster = 1;
			x++;
			continue;
		}

		/*"-cut [Start-End]  to crop the frame from the video from frame Start to frame End\n"  */
		if (0 == strcmp(&argv[x][0], "-cut"))
		{
			/*move to input value*/
			x++;
			/*check if input is valid*/
			if (sscanf(argv[x], "%d-%d", &SFrame, &EFrame) == 2)
			{
				/* input is correct */
				/* SFrame stored */
				/* EFrame stored */
				cut = 1;
			}
			else
			{
				printf("Missing argument for Start Frame and End Frame\n");
				PrintUsage();
				free(fin);
				free(fout);
				return 5;
			}
			x++;
			continue;
		}

		/*"-resize [factor]  to resize the video with the provided factor [1-100]\n"*/
		if (0 == strcmp(&argv[x][0], "-resize"))
		{
			/*move to input value*/
			x++;
			/*check if input is valid*/
			if (sscanf(argv[x], "%d", &percentage) == 1)
			{
				/* input is correct */
				/* percentage is stored*/
				resize = 1;
			}
			else
			{
				printf("Missing argument for Resize Factor!\n");
				PrintUsage();
				free(fin);
				free(fout);
				return 5;
			}
			x++;
			continue;
		}

		/*"-fast   [factor]  to fast forward the video with the provided factor [1+]\n"*/
		if (0 == strcmp(&argv[x][0], "-fast"))
		{
			/*move to input value*/
			x++;
			/*check if input is valid*/
			if (sscanf(argv[x], "%d", &ff_factor) == 1)
			{
				/* input is correct */
				/* ff_factor is stored*/
				fast = 1;
			}
			else
			{
				printf("Missing argument for Fast Forward Factor!\n");
				PrintUsage();
				free(fin);
				free(fout);
				return 5;
			}
			x++;
			continue;
		}

		/*"-rvs to reverse the frame order of the input stream\n"*/
		if (0 == strcmp(&argv[x][0], "-rvs"))
		{
			reverse = 1;
			x++;
			continue;
		}

		/*-h help option*/
		if(0 == strcmp(&argv[x][0], "-h")) 
		{ 
			PrintUsage();
			free(fin);
			free(fout);
			return 0;
		}/*fi*/

		x++;

	}/*elihw*/

	/*Error checks*/
	if(!fin){
		printf("Missing argument for input name!\n");
		PrintUsage();
		free(fin);
		free(fout);
		return 5;
	}

	if(!fout){
		printf("Missing argument for output name!\n");
		PrintUsage();
		free(fin);
		free(fout);
		return 5;
	}

	if (Width <= 0 || Height <= 0)
	{
		printf("Invalid argument for Image Resolution!\n");
		PrintUsage();
		free(fin);
		free(fout);
		return 5;
	}

	if (NumFrames <= 0)
	{
		printf("Invalid argument for Number of Frames!\n");
		PrintUsage();
		free(fin);
		free(fout);
		return 5;
	}

	if (fast == 1 && ff_factor <= 0)
	{
		printf("Invalid argument for Fast Forward Operation!\n");
		PrintUsage();
		free(fin);
		free(fout);
		return 5;
	}

	if ((resize == 1) && (percentage < 1 || percentage > 100))
	{
		printf("Invalid argument for Resize Operation!\n");
		PrintUsage();
		free(fin);
		free(fout);
		return 5;
	}

	if ((cut == 1) && (SFrame > EFrame || SFrame > NumFrames))
	{
		printf("Invalid argument for Frame Cropping Operation!!\n");
		PrintUsage();
		free(fin);
		free(fout);
		return 5;
	}

	if (cut == 1 && EFrame > NumFrames)
	{
		printf("Invalid argument for Frame Cropping Operation!\n");
		PrintUsage();
		free(fin);
		free(fout);
		return 5;
	}

	/*Create the movie*/
	movie = CreateMovie(NumFrames, Width, Height);

	/*Read Movie*/
	ReadMovie(fin, NumFrames, Width, Height, movie);
	
	/*DIP Operations version 2*/
	if (bw == 1)
	{
		DIPs_ptr = &BlackNWhite;
		Movie_DIP_Operation(movie, DIPs_ptr);
		printf("Operation BlackNWhite is done!\n");
	}
	if (vflip == 1)
	{
		DIPs_ptr = &VFlip;
		Movie_DIP_Operation(movie, DIPs_ptr);
		printf("Operation VFlip is done!\n");
	}
	if (hmirror == 1)
	{
		DIPs_ptr = &HMirror;
		Movie_DIP_Operation(movie, DIPs_ptr);
		printf("Operation HMirror is done!\n");
	}
	if (edge == 1)
	{
		DIPs_ptr = &Edge;
		Movie_DIP_Operation(movie, DIPs_ptr);
		printf("Operation Edge is done!\n");
	}
	if (poster == 1)
	{
		DIPs_ptr = &Posterize;
		Movie_DIP_Operation(movie, DIPs_ptr);
		printf("Operation Posterize is done!\n");
	}
	if (cut == 1)
	{
		movie->NumFrames = CropImageList(movie->Frames, SFrame, EFrame);
		printf("Operation Frame Cropping is done!\n");
	}
	if (resize == 1)
	{
		ResizeImageList(movie->Frames, percentage);
		movie->Width = Width * percentage / 100;
		movie->Height = Height * percentage / 100;
		printf("Operation Resize is done! New Width/Height = %dx%d\n", movie->Width, movie->Height);
	}
	if (fast == 1)
	{
		movie->NumFrames = FastImageList(movie->Frames, ff_factor);
		printf("Operation Fast Forward is done! Number of frames = %d\n", movie->NumFrames);
	}
	if (reverse == 1)
	{
		ReverseImageList(movie->Frames);
		printf("Operation Reverse is done!\n");
	}

	/*Save the movie to a .yuv file*/
	SaveMovie(fout, movie);

	/*Free memory*/
	DeleteMovie(movie);
	movie = NULL;

	free(fin);
	free(fout);
	fin = NULL;
	fout = NULL;

	return 0;
}

void PrintUsage()
{
	printf("\nFormat on command line is:\n"
	"MovieLab [option]\n"
	"-i [file_name]    to provide the input file name\n"
	"-o [file_name]    to provide the	output file name\n"
	"-f [no_frames]    to determine how many frames desired in the input stream\n"
	"-s [WidthxHeight] to set resolution of the input stream (widthxheight)\n"
	"-bw               to activate the conversion to black and white\n"
	"-vflip            to activate vertical flip\n"
	"-hmirror          to activate horizontal flip\n"
	"-edge             to activate edge filter\n"
	"-poster           to activate posterize filter\n"
	"-cut [Start-End]  to crop the frame from the video from frame Start to frame End\n"  
	"-resize [factor]  to resize the video with the provided factor [1-100]\n"
	"-fast   [factor]  to fast forward the video with the provided factor [1+]\n"
	"-rvs              to reverse the frame order of the input stream\n"
	"-h                to show this usage information\n"
	);
}

IMAGE* ReadOneFrame(const char *fname, int nFrame, unsigned int W, unsigned H)
{
        /*defining local variables*/
        FILE *file;

        unsigned int x, y;
        unsigned char ch;
        IMAGE* image ;

        /*checking error*/
        assert(fname);
        assert(nFrame >= 0);

        image = CreateImage(W, H) ;
        assert(image) ;

        /*opening file stream*/
        file = fopen(fname, "r");
        assert(file) ;

        /*find desired frame*/
        fseek(file, 1.5 * nFrame * W * H, SEEK_SET);

        for(y = 0; y < H; y ++){
                for(x = 0; x < W; x ++){
                        ch = fgetc(file);
                        SetPixelY(image, x, y, ch);
                }/*rof*/
        }

        for(y = 0; y < H ; y += 2){
                for(x = 0; x < W ; x += 2){
                        ch = fgetc(file);
                        SetPixelU(image, x, y, ch);
                        SetPixelU(image, x + 1, y, ch);
                        SetPixelU(image, x, y + 1, ch);
                        SetPixelU(image, x + 1, y + 1, ch);
                }
        }

        for(y = 0; y < H ; y += 2){
                for(x = 0; x < W ; x += 2){
                        ch = fgetc(file);
                        SetPixelV(image, x, y, ch);
                        SetPixelV(image, x + 1, y, ch);
                        SetPixelV(image, x, y + 1, ch);
                        SetPixelV(image, x + 1, y + 1, ch);
                }
        }

        /*checking for error*/

        assert(ferror(file) == 0) ;

        /*closing stream and terminating*/
        fclose(file);
        file = NULL;
        return image;
}


/*save the movie frames to the output file */
int SaveMovie(const char *fname, MOVIE *movie)
{
	int i ; 
	int x, y;
	FILE *file;
	IENTRY *currFrame;

	 /*opening file stream*/
	 if(!(file = fopen(fname, "w"))){
			return 1;
	 }
	 
	 i = 0 ; 
	 printf("start savemovie, total frame %d\n", movie->NumFrames) ; 
	 currFrame = movie->Frames->First;
	 while(currFrame){
		for(y = 0; y < movie->Height; y ++){ 
			for(x = 0; x < movie->Width; x ++){
				fputc(GetPixelY(currFrame->Image, x, y), file);
			}
		}
		for(y = 0; y < movie->Height; y += 2){ 
			for(x = 0; x < movie->Width; x += 2){
				fputc(GetPixelU(currFrame->Image, x, y), file);
			}
		}
		for(y = 0; y < movie->Height; y += 2){ 
			for(x = 0; x < movie->Width; x += 2){
				fputc(GetPixelV(currFrame->Image, x, y), file);
			}
		}
		currFrame = currFrame->Next;	 
		i++ ; 
	 }

	 fclose(file);
	 file = NULL;

	 printf("The movie file %s has been written successfully! \n", fname);
	 printf("%d frames are written to the file %s in total \n", i, fname); 
	 return 0;
}

/*Functions  have to define*/

/*read the movie frames from the input file */
int ReadMovie(const char *fname, int nFrame, unsigned int W, unsigned H, MOVIE *movie)
{
	/*counter*/
	int x;

	for (x = 0; x < nFrame; x++)
	{
		AppendImage(movie->Frames, ReadOneFrame(fname, x, W, H));
	}
	printf("The movie file %s has been read successfully!\n", fname);
	return 0;	
}

/* the function for perform DIP operations on the movie*/
void Movie_DIP_Operation(MOVIE *movie, MOP_F *MovieOP)
{
	IENTRY *ientry;

	ientry = movie->Frames->First;

	while (ientry)
	{		
		/*Convert yuv image to rgb so the DIPs can work*/
		YUV2RGBImage(ientry->Image);
		/*Perform DIPs on image*/
		MovieOP(ientry->Image);
		/*Convert rgb image back to yuv*/
		RGB2YUVImage(ientry->Image);

		/*Move to next image*/
		ientry = ientry->Next;
	}

}