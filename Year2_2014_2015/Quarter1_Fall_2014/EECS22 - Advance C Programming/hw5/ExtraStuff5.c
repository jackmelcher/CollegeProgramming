/*Fast forward the video*/
unsigned int FastImageList(ILIST *ilist, unsigned int ff_factor);

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
			pPrev = pCurrent;
			pCurrent = pNext;
			pNext = pNext->Next;

			/*Decrement Length*/
			ilist->Length--;
		}
		/*Increment Counter*/
		x++;
	}
	/*Return new length to update the NumFrames in movie*/
	return ilist->Length;
}

/*Fast forward the video*/
ILIST *FastImageList(ILIST *ilist, unsigned int ff_factor);

/*Fast forward the video*/
ILIST *FastImageList(ILIST *ilist, unsigned int ff_factor)
{
	ILIST *ilist_tmp;
	IENTRY *pCurrent;

	/*counter*/
	unsigned int x = 0;

	assert(ilist);
	pCurrent = ilist->First;

	/*temporary list*/
	ilist_tmp = NewImageList();


	/*Go through entire movie and cut images out*/
	while (pCurrent)
	{
		/*cut image out*/
		if ((x % ff_factor) == 0)
		{
			AppendImage(ilist_tmp, pCurrent->Image);
			/*Move to next IENTRY*/
			pCurrent = pCurrent->Next;
		}
		/*Increment Counter*/
		x++;
	}
	/*Delete original list*/
	DeleteImageList(ilist);

	/*Return new list*/
	return ilist_tmp;
}


/*Go to End of movie*/
pCurrent = ilist->Last;
pPrev = ilist->First->Prev;
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

}
/*Set last to the desired EFrame*/
ilist->Last = pPrev;