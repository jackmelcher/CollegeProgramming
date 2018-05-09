/*board is numbered from 0 to 63 starting from a1,a2,a3,a4...b1,b2...to h8*/

/*Rules*/
void rules(/*string that contains coordinate A and coordinate B*/)
{
	/*translate coordinate A into a number*/
	/*translate coordinate B into a number*/

	/*Aquire piece type from number*/
	/*board pointer points to a piece structure based on coordinate A*/

	if (/*white pawn*/)
	{
		/*moving forward*/
		if (/*coor B - coor A == 8*/)
		{
			/*Check if coor B is empty*/
			if (/*space is null*/)
			{
				/*move*/
			}
			if (/*space isn't null*/)
			{
				/*cannot move, reset player's turn*/
			}

		}
		/*moving 2 spaces*/
		if (/*first move of pawn && coor A - coor B == 16*/)
		{
			/*Check if coor B is empty*/
			if (/*space is null*/)
			{
				/*move*/
				/*set en passant rule on coor B - 8*/
			}
			if (/*space isn't null*/)
			{
				/*cannot move, reset player's turn*/
			}
		}
		/*moving up-diagonal-right*/
		if (/*coor B - coor A == 9*/)
		{
			if (/*space is not empty*/)
			{
				if (/*space has white piece*/)
				{
					/*cannot move, reset white's turn*/
				}
				if (/*space has black piece*/)
				{
					/*capture*/
				}
			}
		}
		/*moving up-diagonal-left*/
		if (/*coor B - coor A == 7*/)
		{
			if (/*space is not empty*/)
			{
				if (/*space has white piece*/)
				{
					/*cannot move, reset white's turn*/
				}
				if (/*space has black piece*/)
				{
					/*capture*/
				}
			}
		}
		if (/*coor B >= 56*/)
		{
			/*Promotion: change piece type to Queen*/
		}
	}

	if (/*black pawn*/)
	{
		/*moving forward*/
		if (/*coor B - coor A == -8*/)
		{
			/*Check if coor B is empty*/
			if (/*space is null*/)
			{
				/*move*/
			}
			if (/*space isn't null*/)
			{
				/*cannot move, reset player's turn*/
			}

		}
		/*moving 2 spaces*/
		if (/*first move of pawn && coor A - coor B == -16*/)
		{
			/*Check if coor B is empty*/
			if (/*space is null*/)
			{
				/*move*/
				/*set en passant rule on coor B + 8*/
			}
			if (/*space isn't null*/)
			{
				/*cannot move, reset player's turn*/
			}
		}
		/*moving down-diagonal-right*/
		if (/*coor B - coor A == -7*/)
		{
			if (/*space is not empty*/)
			{
				if (/*space has black piece*/)
				{
					/*capture*/
				}
				if (/*space has white piece*/)
				{
					/*cannot move, reset player's turn*/
				}
				
			}
		}
		/*moving down-diagonal-left*/
		if (/*coor B - coor A == -9*/)
		{
			if (/*space is not empty*/)
			{
				if (/*space has black piece*/)
				{
					/*capture*/
				}
				if (/*space has white piece*/)
				{
					/*cannot move, reset player's turn*/
				}
			}
		}
		if (/*coor B <= 7*/)
		{
			/*Promotion: change piece type to Queen*/
		}
	}

	if (/*Rook*/)
	{
		/*moving right or left*/
		if (/*coor B - coor A == -8*/)
		{
			/*Check if coor B is empty*/
			if (/*space is null*/)
			{
				/*move*/
			}
			if (/*space isn't null*/)
			{
				/*cannot move, reset player's turn*/
			}
		}
		/*moving down or up*/
		if (/*coor B - coor A == -8*/)
		{
			/*Check if coor B is empty*/
			if (/*space is null*/)
			{
				/*move*/
			}
			if (/*space isn't null*/)
			{
				/*cannot move, reset player's turn*/
			}

		}
	}
	if (/*Knight*/)
	{

	}
	if (/*Bishop*/)
	{

	}
	if (/*Queen*/)
	{

	}
	if (/*King*/)
	{

	}
}