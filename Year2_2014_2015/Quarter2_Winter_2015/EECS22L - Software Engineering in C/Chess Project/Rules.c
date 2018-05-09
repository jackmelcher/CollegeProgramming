/************************************/
/*Project 1: Chess                  */
/*Module: Rules.c                   */
/*                                  */
/*EECS 22L, 1/20/2015               */
/*DP Studios, Version v1.0          */
/*                                  */
/*Version History:                  */
/*  v1.1, 1/22/2015 (Kyle/Elliot)   */
/*  v1.2, 1/23/2015 (Kyle/Elliot)   */
/*  v1.3, 1/27/2015 (Kyle/Elliot)   */
/************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Pieces.h"
#include "Rules.h"

int CheckRules(PIECE *Board[100], int initial, int end)
{
	int initialtype, initialcolor, initialmovestate, endtype, endcolor, endmovestate;

	initialtype = Board[initial]->type;
	initialcolor = Board[initial]->color;
	initialmovestate = Board[initial]->moved;

	if (Board[end] != NULL)
	{
		endtype = Board[end]->type;
		endcolor = Board[end]->color;
		endmovestate = Board[end]->moved;
	}

	int i;
	int valid = 0;

	/*First switch to check for valid move assuming nothing in the way*/
	switch (initialtype)
	{
		/*Pawn*/
	case Pawn:
		/*if moved piece color is white*/
		if (initialcolor == White)
		{
			/*Hasn't moved yet*/
			if (initialmovestate == 0)
			{
				/*One space*/
				if (end - initial == 10)
				{
					if (Board[end] == NULL)
					{
						valid = 1;
					}
				}
				/*Two spaces*/
				else if (end - initial == 20)
				{
					if (Board[initial + 10] == NULL && Board[end] == NULL)
					{
						valid = 1;
					}
				}
				/*Check for kill*/
				else if (end - initial == 9 || end - initial == 11)
				{
					if (Board[end] != NULL && initialcolor != endcolor)
					{
						valid = 1;
					}
				}
			}
			/*Moved already*/
			else if (initialmovestate >= 1)
			{
				/*One space only*/
				if (end - initial == 10)
				{
					if (Board[end] == NULL)
					{
						valid = 1;
					}
				}
				/*Check for kill on left*/
				else if (end - initial == 9)
				{
					/*En passant*/
					if (initial >= 51 && initial <= 58 && Board[initial - 1]->type == Pawn && Board[initial - 1]->color == Black && Board[initial - 1]->moved == 1)
					{
						if (Board[end] == NULL)
						{
							/*Successful En passant*/
							Board[initial - 1] = NULL;
							valid = 1;
						}
					}
					else if (Board[end] != NULL && initialcolor != endcolor)
					{
						valid = 1;
					}
				}
				/*Check for kill on right*/
				else if (end - initial == 11)
				{
					/*En passant*/
					if (initial >= 51 && initial <= 58 && Board[initial + 1]->type == Pawn && Board[initial + 1]->color == Black && Board[initial + 1]->moved == 1)
					{
						if (Board[end] == NULL)
						{
							/*Successful En passant*/
							Board[initial + 1] = NULL;
							valid = 1;
						}
					}
					else if (Board[end] != NULL && initialcolor != endcolor)
					{
						valid = 1;
					}
				}
			}
		}

		/*if moved piece color is black*/
		else if (initialcolor == Black)
		{
			/*Hasn't moved yet*/
			if (initialmovestate == 0)
			{
				/*One space*/
				if (initial - end == 10)
				{
					if (Board[end] == NULL)
					{
						valid = 1;
					}
				}
				/*Two spaces*/
				else if (initial - end == 20)
				{
					if (Board[initial - 10] == NULL && Board[end] == NULL)
					{
						valid = 1;
					}
				}
				/*Check for kill*/
				else if (initial - end == 9 || initial - end == 11)
				{
					if (Board[end] != NULL && initialcolor != endcolor)
					{
						valid = 1;
					}
				}
			}
			/*Moved already*/
			else if (initialmovestate >= 1)
			{
				/*One space only*/
				if (initial - end == 10)
				{
					if (Board[end] == NULL)
					{
						valid = 1;
					}
				}
				/*Check for kill on left*/
				else if (initial - end == 9)
				{
					/*En passant*/
					if (initial >= 41 && initial <= 48 && Board[initial - 1]->type == Pawn && Board[initial - 1]->color == White && Board[initial - 1]->moved == 1)
					{
						if (Board[end] == NULL)
						{
							/*Successful En passant*/
							Board[initial - 1] = NULL;
							valid = 1;
						}
					}
					else if (Board[end] != NULL && initialcolor != endcolor)
					{
						valid = 1;
					}
				}
				/*Check for kill on right*/
				else if (initial - end == 11)
				{
					/*En passant*/
					if (initial >= 41 && initial <= 48 && Board[initial + 1]->type == Pawn && Board[initial + 1]->color == White && Board[initial + 1]->moved == 1)
					{
						if (Board[end] == NULL)
						{
							/*Successful En passant*/
							Board[initial + 1] = NULL;
							valid = 1;
						}
					}
					else if (Board[end] != NULL && initialcolor != endcolor)
					{
						valid = 1;
					}
				}
			}
		}
		break;
		/*Rook*/
	case Rook:
		if (abs(end - initial) % 10 == 0)
		{
			if (initial < end)
			{
				for (i = initial + 10; i <= end; i += 10)
				{
					if (Board[i] == NULL)
					{
						valid = 1;
					}
					else if (Board[i] == Board[end])
					{
						if (Board[i] != NULL)
						{
							valid = 1;
						}
					}
					else
					{
						valid = 0;
						break;
					}
				}
			}

			else if (initial > end)
			{
				for (i = initial - 10; i >= end; i -= 10)
				{
					if (Board[i] == NULL)
					{
						valid = 1;
					}
					else if (Board[i] == Board[end])
					{
						if (Board[i] != NULL)
						{
							valid = 1;
						}
					}
					else
					{
						valid = 0;
						break;
					}
				}
			}
			if (endcolor == initialcolor)
			{
				valid = 0;
			}
		}
		else if (abs(end - initial) / 10 == 0)
		{
			if (initial < end)
			{
				for (i = initial + 1; i <= end; i += 1)
				{
					if (Board[i] == NULL)
					{
						valid = 1;
					}
					else if (Board[i] == Board[end])
					{
						if (Board[i] != NULL)
						{
							valid = 1;
						}
					}
					else
					{
						valid = 0;
						break;
					}
				}
			}
			else if (initial > end)
			{
				for (i = initial - 1; i >= end; i -= 1)
				{
					if (Board[i] == NULL)
					{
						valid = 1;
					}
					else if (Board[i] == Board[end])
					{
						if (Board[i] != NULL)
						{
							valid = 1;
						}
					}
					else
					{
						valid = 0;
						break;
					}
				}
			}
			if (endcolor == initialcolor)
			{
				valid = 0;
			}
		}
		break;
		/*Knight*/
	case Knight:
		if ((abs(end - initial) == 21) || (abs(end - initial) == 19) || (abs(end - initial) == 12) || (abs(end - initial) == 8))
		{
			if (endcolor != initialcolor || Board[end] == NULL)
			{
				valid = 1;
			}
		}
		break;
		/*Bishop*/
	case Bishop:
		if (abs(end - initial) % 9 == 0)
		{
			if (initial < end)
			{
				for (i = initial + 9; i <= end; i += 9)
				{
					if (Board[i] == NULL)
					{
						valid = 1;
					}
					else if (Board[i] == Board[end])
					{
						if (Board[i] != NULL)
						{
							valid = 1;
						}
					}
					else
					{
						valid = 0;
						break;
					}
				}
			}
			else if (initial > end)
			{
				for (i = initial - 9; i >= end; i -= 9)
				{
					if (Board[i] == NULL)
					{
						valid = 1;
					}
					else if (Board[i] == Board[end])
					{
						if (Board[i] != NULL)
						{
							valid = 1;
						}
					}
					else
					{
						valid = 0;
						break;
					}
				}
			}
			if (endcolor == initialcolor)
			{
				valid = 0;
			}
		}
		else if (abs(end - initial) % 11 == 0)
		{
			if (initial < end)
			{
				for (i = initial + 11; i <= end; i += 11)
				{
					if (Board[i] == NULL)
					{
						valid = 1;
					}
					else if (Board[i] == Board[end])
					{
						if (Board[i] != NULL)
						{
							valid = 1;
						}
					}
					else
					{
						valid = 0;
						break;
					}
				}
			}
			else if (initial > end)
			{
				for (i = initial - 11; i >= end; i -= 11)
				{
					if (Board[i] == NULL)
					{
						valid = 1;
					}
					else if (Board[i] == Board[end])
					{
						if (Board[i] != NULL)
						{
							valid = 1;
						}
					}
					else
					{
						valid = 0;
						break;
					}
				}
			}
			if (endcolor == initialcolor)
			{
				valid = 0;
			}
		}
		break;
		/*Queen*/
	case Queen:
		if (abs(end - initial) % 10 == 0)
		{
			if (initial < end)
			{
				for (i = initial + 10; i <= end; i += 10)
				{
					if (Board[i] == NULL)
					{
						valid = 1;
					}
					else if (Board[i] == Board[end])
					{
						if (Board[i] != NULL)
						{
							valid = 1;
						}
					}
					else
					{
						valid = 0;
						break;
					}
				}
			}
			else if (initial > end)
			{
				for (i = initial - 10; i >= end; i -= 10)
				{
					if (Board[i] == NULL)
					{
						valid = 1;
					}
					else if (Board[i] == Board[end])
					{
						if (Board[i] != NULL)
						{
							valid = 1;
						}
					}
					else
					{
						valid = 0;
						break;
					}
				}
			}
			if (endcolor == initialcolor)
			{
				valid = 0;
			}
		}
		else if (abs(end - initial) / 10 == 0)
		{
			if (initial < end)
			{
				for (i = initial + 1; i <= end; i += 1)
				{
					if (Board[i] == NULL)
					{
						valid = 1;
					}
					else if (Board[i] == Board[end])
					{
						if (Board[i] != NULL)
						{
							valid = 1;
						}
					}
					else
					{
						valid = 0;
						break;
					}
				}
			}
			else if (initial > end)
			{
				for (i = initial - 1; i >= end; i -= 1)
				{
					if (Board[i] == NULL)
					{
						valid = 1;
					}
					else if (Board[i] == Board[end])
					{
						if (Board[i] != NULL)
						{
							valid = 1;
						}
					}
					else
					{
						valid = 0;
						break;
					}
				}
				if (endcolor == initialcolor)
				{
					valid = 0;
				}
			}
		}
		else if (abs(end - initial) % 9 == 0)
		{
			if (initial < end)
			{
				for (i = initial + 9; i <= end; i += 9)
				{
					if (Board[i] == NULL)
					{
						valid = 1;
					}
					else if (Board[i] == Board[end])
					{
						if (Board[i] != NULL)
						{
							valid = 1;
						}
					}
					else
					{
						valid = 0;
						break;
					}
				}
			}
			else if (initial > end)
			{
				for (i = initial - 9; i >= end; i -= 9)
				{
					if (Board[i] == NULL)
					{
						valid = 1;
					}
					else if (Board[i] == Board[end])
					{
						if (Board[i] != NULL)
						{
							valid = 1;
						}
					}
					else
					{
						valid = 0;
						break;
					}
				}
				if (endcolor == initialcolor)
				{
					valid = 0;
				}
			}
		}
		else if (abs(end - initial) % 11 == 0)
		{
			if (initial < end)
			{
				for (i = initial + 11; i <= end; i += 11)
				{
					if (Board[i] == NULL)
					{
						valid = 1;
					}
					else if (Board[i] == Board[end])
					{
						if (Board[i] != NULL)
						{
							valid = 1;
						}
					}
					else
					{
						valid = 0;
						break;
					}
				}
			}
			else if (initial > end)
			{
				for (i = initial - 11; i >= end; i -= 11)
				{
					if (Board[i] == NULL)
					{
						valid = 1;
					}
					else if (Board[i] == Board[end])
					{
						if (Board[i] != NULL)
						{
							valid = 1;
						}
					}
					else
					{
						valid = 0;
						break;
					}
				}
				if (endcolor == initialcolor)
				{
					valid = 0;
				}
			}
		}
		break;
		/*King*/
	case King:
		if ((abs(end - initial) == 9) || (abs(end - initial) == 11))
		{
			if (initialcolor != endcolor || Board[end] == NULL)
			{
				valid = 1;
			}
		}
		else if ((abs(end - initial) == 10) || (abs(end - initial) == 1))
		{
			if (initialcolor != endcolor || Board[end] == NULL)
			{
				valid = 1;
			}
		}
		break;
		/*default case*/
	default:
		valid = 0;
		break;

	}
	/*returns valid as 0 or 1 depending on whether move was valid (1) or not (0)*/
	return valid;
}