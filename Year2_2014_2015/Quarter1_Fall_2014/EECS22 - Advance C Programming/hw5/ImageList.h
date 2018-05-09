/*********************************************************************/
/*    ImageList.h                                                    */
/*    Jack Melcher 67574625                                          */
/*********************************************************************/

#ifndef IMAGELIST_H
#define IMAGELIST_H

/*include necessary libraries*/
#include "Image.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>


typedef struct ImageList ILIST;
typedef struct ImageEntry IENTRY;

struct ImageList
{
	unsigned int Length; /* Length of the list */
	IENTRY *First; /* pointer to the first entry, or NULL */
	IENTRY *Last; /* pointer to the last entry, or NULL */
};

struct ImageEntry
{
	ILIST *List; /* pointer to the list which this entry belongs to */
	IENTRY *Next; /* pointer to the next entry, or NULL */
	IENTRY *Prev; /* pointer to the previous entry, or NULL */
	IMAGE *Image; /* pointer to the struct for the image */
};

/* allocate a new image list */
ILIST *NewImageList(void);
/* delete a image list (and all entries) */
void DeleteImageList(ILIST *ilist);
/* insert a frame into a list at the end*/
void AppendImage(ILIST *ilist, IMAGE *image);
/* reverse an image list */
void ReverseImageList(ILIST *ilist);
/*Crop frames from the list starting from SFrame to EFrame*/
unsigned int CropImageList(ILIST *ilist, unsigned int SFrame, unsigned int EFrame);
/*Resize the images in the list*/
void ResizeImageList(ILIST *ilist, unsigned int percentage);
/*Fast forward the video*/
unsigned int FastImageList(ILIST *ilist, unsigned int ff_factor);

#endif