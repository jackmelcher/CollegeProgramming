/* shuffle image*/
void	Shuffle(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
{
	int x, y;

	/*Initialize the random number generator with the current time*/
	srand(time(NULL));

	/*Array to check if block was swapped*/
	int tempA[4][4];

	/*Check which block of the picture the shuffler is at*/
	int current_height_block = 1;/*1 through 4*/
	int current_width_block = 1;/*1 through 4*/

	/*A random number for choosing the block to be shuffled with*/
	int random_height_block;
	int random_width_block;

	/*temporarily store the image blocks*/
	int temp1_R[WIDTH / SHUFF_WIDTH_DIV][HEIGHT / SHUFF_HEIGHT_DIV], temp1_G[WIDTH / SHUFF_WIDTH_DIV][HEIGHT / SHUFF_HEIGHT_DIV], temp1_B[WIDTH / SHUFF_WIDTH_DIV][HEIGHT / SHUFF_HEIGHT_DIV];

	/* SHUFF_HEIGHT_DIV and SHUFF_WIDTH_DIV for shuffling is equal to 4 */

	while (tempA[0][0] <= 1 && tempA[0][1] <= 1 && tempA[0][2] <= 1 && tempA[0][3] <= 1 && tempA[1][0] <= 1 && tempA[1][1] <= 1 && tempA[1][2] <= 1 && tempA[1][3] <= 1 && tempA[2][0] <= 1 && tempA[2][1] <= 1 && tempA[2][2] <= 1 && tempA[2][3] <= 1 && tempA[3][0] <= 1 && tempA[3][1] <= 1 && tempA[3][2] <= 1 && tempA[3][3] <= 1)
	{
		while (current_height_block < 5)
		{
			while (current_width_block < 5)
			{
				/*Provides a random block*/
				random_height_block = rand() % 4 + 1;
				random_width_block = rand() % 4 + 1;

				while (random_height_block == current_height_block && random_width_block == current_width_block)
				{
					random_height_block = rand() % 4 + 1;
					random_width_block = rand() % 4 + 1;
				}

				/*After blocks are shuffled*/
				tempA[current_width_block][current_height_block] += 1;
				tempA[random_width_block][random_height_block] += 1;

				for (y = 0; y < (HEIGHT / SHUFF_HEIGHT_DIV); y++)
				{
					for (x = 0; x < (WIDTH / SHUFF_WIDTH_DIV); x++)
					{
						/*Store current image block in tempArray image block*/
						temp1_R[x][y] = R[(current_width_block - 1) * (WIDTH / SHUFF_WIDTH_DIV) + x][(current_height_block - 1) * (HEIGHT / SHUFF_HEIGHT_DIV) + y];
						temp1_G[x][y] = G[(current_width_block - 1) * (WIDTH / SHUFF_WIDTH_DIV) + x][(current_height_block - 1) * (HEIGHT / SHUFF_HEIGHT_DIV) + y];
						temp1_B[x][y] = B[(current_width_block - 1) * (WIDTH / SHUFF_WIDTH_DIV) + x][(current_height_block - 1) * (HEIGHT / SHUFF_HEIGHT_DIV) + y];
					}
				}

				for (y = ((current_height_block - 1) * HEIGHT / SHUFF_HEIGHT_DIV); y < (current_height_block * HEIGHT / SHUFF_HEIGHT_DIV); y++)
				{
					for (x = ((current_width_block - 1) * WIDTH / SHUFF_WIDTH_DIV); x < (current_width_block * WIDTH / SHUFF_WIDTH_DIV); x++)
					{
						/*Replace current image block with random image block*/
						R[x][y] = R[(random_width_block - 1) * (WIDTH / SHUFF_WIDTH_DIV) + (x - (current_width_block - 1) * (WIDTH / SHUFF_WIDTH_DIV))][(random_height_block - 1) * (HEIGHT / SHUFF_HEIGHT_DIV) + (y - (current_height_block - 1) * (HEIGHT / SHUFF_HEIGHT_DIV))];
						G[x][y] = G[(random_width_block - 1) * (WIDTH / SHUFF_WIDTH_DIV) + (x - (current_width_block - 1) * (WIDTH / SHUFF_WIDTH_DIV))][(random_height_block - 1) * (HEIGHT / SHUFF_HEIGHT_DIV) + (y - (current_height_block - 1) * (HEIGHT / SHUFF_HEIGHT_DIV))];
						B[x][y] = B[(random_width_block - 1) * (WIDTH / SHUFF_WIDTH_DIV) + (x - (current_width_block - 1) * (WIDTH / SHUFF_WIDTH_DIV))][(random_height_block - 1) * (HEIGHT / SHUFF_HEIGHT_DIV) + (y - (current_height_block - 1) * (HEIGHT / SHUFF_HEIGHT_DIV))];
					}

				}

				for (y = ((random_height_block - 1) * HEIGHT / SHUFF_HEIGHT_DIV); y < (random_height_block * HEIGHT / SHUFF_HEIGHT_DIV); y++)
				{
					for (x = ((random_width_block - 1) * WIDTH / SHUFF_WIDTH_DIV); x < (random_width_block * WIDTH / SHUFF_WIDTH_DIV); x++)
					{
						/*Replace random image block with the temp image block*/
						R[x][y] = temp1_R[x - ((random_width_block - 1) * WIDTH / SHUFF_WIDTH_DIV)][y - ((random_height_block - 1) * HEIGHT / SHUFF_HEIGHT_DIV)];
						G[x][y] = temp1_G[x - ((random_width_block - 1) * WIDTH / SHUFF_WIDTH_DIV)][y - ((random_height_block - 1) * HEIGHT / SHUFF_HEIGHT_DIV)];
						B[x][y] = temp1_B[x - ((random_width_block - 1) * WIDTH / SHUFF_WIDTH_DIV)][y - ((random_height_block - 1) * HEIGHT / SHUFF_HEIGHT_DIV)];
					}
				}

				/*After swapping blocks, move to next block on the right*/
				current_width_block = current_width_block + 1;
			}
			/*After swapping all the blocks in a row, move down to the next row.*/
			current_height_block = current_height_block + 1;
		}
	}

	printf("Shuffle operation is done!\n");
}