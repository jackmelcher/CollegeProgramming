/*********************************************************************/
/*    ImageList.c                                                    */
/*    Jack Melcher 67574625                                          */
/*********************************************************************/

/*include necessary libraries*/
#include "ImageList.h"
#include "Movie.h"
#include "DIPs.h"

/* allocate a new image list */
ILIST *NewImageList(void)
{
	ILIST *ilist;
	ilist = (ILIST*)malloc(sizeof(ILIST));
	/*check to see if there is enough memory that can be allocated*/
	if (!ilist)
	{
		perror("Out of memory. Aborting...");
		exit(10);
	}
	
	ilist->Length = 0;
	ilist->First = NULL;
	ilist->Last = NULL;
	
	return ilist;
}

/* delete a image list (and all entries) */
void DeleteImageList(ILIST *ilist)
{
	IENTRY *ientry, *n;

	assert(ilist);

	ientry = ilist->First;

	while (ientry)
	{
		/*Store where ientry->Next points in a tmp pointer n*/
		n = ientry->Next;

		/*Delete IMAGE*/
		DeleteImage(ientry->Image);
		ientry->Image = NULL;

		/*Delete IENTRY*/
		assert(ientry);
		free(ientry);

		/*Move to next entry*/
		ientry = n;
	}
	/*Delete ILIST*/
	free(ilist);
}

/* insert a frame into a list at the end*/
void AppendImage(ILIST *ilist, IMAGE *image)
{
	IENTRY *ientry;

	assert(ilist);
	assert(image);
	
	/*create image entry*/
	ientry = (IENTRY*)malloc(sizeof(IENTRY));
	
	/*check to see if there is enough memory that can be allocated*/
	if (!ientry)
	{
		perror("Out of memory. Aborting...");
		exit(10);
	}
	
	ientry->List = NULL;
	ientry->Next = NULL;
	ientry->Prev = NULL;
	ientry->Image = image;

	/*For when the entry is not the first entry*/
	if (ilist->Last)
	{
		ientry->List = ilist;
		ientry->Next = NULL;
		ientry->Prev = ilist->Last;
		ilist->Last->Next = ientry;
		ilist->Last = ientry;
	}
	else /*when it is the first entry*/
	{
		ientry->List = ilist;
		ientry->Next = NULL;
		ientry->Prev = NULL;
		ilist->First = ientry;
		ilist->Last = ientry;
	}
	ilist->Length++;
}

/* reverse an image list */
void ReverseImageList(ILIST *ilist)
{
	IENTRY *pCurrent, *pNext, *pPrev;

	assert(ilist);

	pPrev = ilist->First->Prev;
	pCurrent = ilist->First;
	pNext = ilist->First->Next;

	while (pNext)
	{
		/*Change the Prev and Next*/
		pCurrent->Next = pPrev;
		pCurrent->Prev = pNext;

		/*Move to next IENTRY*/
		pPrev = pCurrent;
		pCurrent = pNext;
		pNext = pNext->Next;
	}
	/*Final Frame: Change the Prev and Next*/
	pCurrent->Prev = NULL;
	pCurrent->Next = pPrev;

	/*Make the last IENTRY the first frame and first IENTRY the last frame*/
	ilist->Last = ilist->First;
	ilist->First = pCurrent;
}

/*Crop frames from the list starting from SFrame to EFrame*/
unsigned int CropImageList(ILIST *ilist, unsigned int SFrame, unsigned int EFrame)
{	
	IENTRY *pCurrent, *pPrev, *pNext;
	
	/*counter*/
	unsigned int x;

	assert(ilist);

	/*Go to End of movie*/
	pCurrent = ilist->Last;
	pPrev = ilist->Last->Prev;
	/*Delete entries and images after start frame*/
	for (x = ilist->Length; x > EFrame; x--)
	{
		/*Delete IMAGE*/
		DeleteImage(pCurrent->Image);

		/*Delete IENTRY*/
		assert(pCurrent);
		free(pCurrent);

		/*move to next entry*/
		pCurrent = pPrev;
		pCurrent->Next = NULL;
		pPrev = pPrev->Prev;

		/*Decrement Length*/
		ilist->Length--;
	}
	/*Set last to the desired EFrame*/
	ilist->Last = pCurrent;


	/*Go to Start of Movie*/
	pCurrent = ilist->First;
	pNext = ilist->First->Next;

	/*Delete entries and images before start frame*/
	for (x = 1; x < SFrame; x++)
	{
		/*Delete IMAGE*/
		DeleteImage(pCurrent->Image);

		/*Delete IENTRY*/
		assert(pCurrent);
		free(pCurrent);

		/*move to next entry*/
		pCurrent = pNext;
		pCurrent->Prev = NULL;
		pNext = pNext->Next;

		/*Decrement Length*/
		ilist->Length--;		
	}
	/*Set first to the desired SFrame*/
	ilist->First = pCurrent;

	

	/*Return new length to update the NumFrames in movie*/
	return ilist->Length;
}

/*Resize the images in the list*/
void ResizeImageList(ILIST *ilist, unsigned int percentage)
{
	IENTRY *ientry;

	assert(ilist);
	ientry = ilist->First;

	/*Go through entire movie and resize image*/
	while (ientry)
	{
		/*Convert YUV to RGB*/
		YUV2RGBImage(ientry->Image);
		/*Resize the Image*/
		ientry->Image = Resize(percentage, ientry->Image);
		/*Convert RGB to YUV*/
		RGB2YUVImage(ientry->Image);
		/*move to next image entry*/
		ientry = ientry->Next;
	}
}

/*Fast forward the video*/
unsigned int FastImageList(ILIST *ilist, unsigned int ff_factor)
{
	IENTRY *pCurrent, *pPrev, *pNext;

	/*counter*/
	unsigned int x = 1;

	assert(ilist);
	pPrev = ilist->First;
	pCurrent = ilist->First->Next;
	pNext = pCurrent->Next;

	/*Go through entire movie and cut images out*/
	while (pNext)
	{
		/*cut image out*/
		if ((x % ff_factor) != 0)
		{
			/*Delete IMAGE*/
			DeleteImage(pCurrent->Image);
			pCurrent->Image = NULL;
			/*Prev and Next changes*/
			pPrev->Next = pCurrent->Next;
			pNext->Prev = pCurrent->Prev;
			/*Delete IENTRY*/
			assert(pCurrent);
			free(pCurrent);

			/*Move to next IENTRY*/
			pCurrent = pNext;
			pNext = pNext->Next;

			/*Decrement Length*/
			ilist->Length--;
		}
		else
		{
			pPrev = pCurrent;
			pCurrent = pNext;
			pNext = pNext->Next;
		}
		/*Increment Counter*/
		x++;
	}
	/*Final Frame to Delete*/
	DeleteImage(pCurrent->Image);
	pCurrent->Image = NULL;
	/*Final Next changes*/
	pPrev->Next = pCurrent->Next;
	/*Decrement Length*/
	ilist->Length--;
	/*Delete IENTRY*/
	assert(pCurrent);
	free(pCurrent);
	/*Change Last*/
	ilist->Last = pPrev;

	/*Return new length to update the NumFrames in movie*/
	return ilist->Length;
}
