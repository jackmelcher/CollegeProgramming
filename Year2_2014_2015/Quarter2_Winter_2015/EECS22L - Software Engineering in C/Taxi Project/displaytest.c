

int i,j;

X1 = 1, X2 = 8, Y1 = 1, Y2 = 8;

for(i = X1 + 1; i < X2; i++)
{
	for(j = Y1 + 1; j < Y2; i++)
	{
		Board[i][j] = MIDDLE_LAND_BLANK;
	}
}

	for(i = 0; i < size[1]; i ++)
		for(j = 0; j < size[0]; j ++)
		{
			if(i == 0 && j == 0) Board[i][j] = TOP_LEFT_BLANK;
			if(i == size[1] - 1 && j == 0) Board[i][j] = TOP_RIGHT_BLANK;
		}
	
	TOP_LAND_BLANK = 20,
	BOT_LAND_BLANK,
	RIGHT_LAND_BLANK,
	LEFT_LAND_BLANK,
	MIDDLE_LAND_BLANK,