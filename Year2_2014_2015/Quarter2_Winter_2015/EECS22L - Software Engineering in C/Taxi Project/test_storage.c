/* This is unfinished and will not compile */
/* Data Storgae test of Taxi and Client info */
/* Jack Melcher		67574625  		3/5/2015 */

#include <stdio.h>
#include <math.h>


int main()
{
	/* number of ppl, fee, pickup position X, pickup position Y,
		dropoff position X, dropoff position Y, taxi sent(0 or 1), 
		pickup confirm(0 or 1), dropoff confirm(0 or 1)*/
	/*list lengths*/
	const int taxi_list_length = 120;
	const int client_list_length = 100;

	float client_info[client_list_length][9];
	
	/* client# to pick up, Max Occupancy, 
		number of blocks traveled, Current X, Current Y*/
	int taxi info[taxi_list_length][5];

	int temp_x, temp_y;
	float fee;

	float expenses = 0, income = 0, profit = 0;
	/*counter variable*/
	int i = 0, j, k;
	int total_client_entries = 0;
	int simulate = 1;

	/*Reset Client info*/
	for (i = 0; i < client_list_length; i++)
	{
		client[i][6] = 0;
		client[i][7] = 0;
		client[i][8] = 0;
	}
	
	/*Reset Taxi info*/
	for (i = 0; i < taxi_list_length; i++)
	{
		taxi[i][0] = 100;
		taxi[i][2] = 0;
		/*taxi spawn location*/
		if (j == 0)
		{
			taxi[i][3] = 7;
			taxi[i][4] = 3;
		}
		else if (j == 1)
		{
			taxi[i][3] = 7;
			taxi[i][4] = 18;
		}
		else if (j == 2)
		{
			taxi[i][3] = 35;
			taxi[i][4] = 23;
		}
		/*taxi capacity*/
		if (k == 0)
		{
			taxi[i][1] = 3;
		}
		else if (k == 1)
		{
			taxi[i][1] = 6;
		}

		j++;
		if (j == 3)
		{
			j = 0;
			k++;
		}
		if (k == 2)
		{
			k = 0;
		}
	}

	printf("Enter Client information");
	/* Enter Client info*/
	while (i < client_list_length)
	{
		switch (select)
		{
			case 1:
			{
				printf("Number of People (Max 6): ");
				scanf("%d", client[i][0]);
				printf("Pickup Coordinate X");
				scanf("%d", client[i][2]);
				printf("Pickup Coordinate Y");
				scanf("%d", client[i][3]);
				printf("Dropoff Coordinate X");
				scanf("%d", client[i][4]);
				printf("Dropoff Coordinate Y");
				scanf("%d", client[i][5]);
				
				/*Calculate Manhatan Distance Fee*/
				/*X*/
				temp_x = abs(client[i][2] - client[i][4]);
				/*Y*/
				temp_y = abs(client[i][3] - client[i][5]);

				fee = 3.75 + temp_x*0.50 + temp_y*0.50;
				client[i][1] = fee;

				printf("Your fee is %f", client[i][1]);

				i++;
				total_client_entries++;
				break;
			}
			case 2:
			{	
				i = client_list_length;
				break;
			}
			default:
				break;
		}	
	}

	/*Setup clients with taxi*/
	for (i = 0; i < total_client_entries; i++)
	{
		/*Client is closest to taxi Stand A (7,3)*/
		if (abs(client[i][2] - 7) <= abs(client[i][2] - 7) && abs(client[i][2] - 7) <= abs(client[i][2] - 35)
			&& abs(client[i][3] - 3) <= abs(client[i][3] - 18) && abs(client[i][3] - 3) <= abs(client[i][3] - 23))
		{
			/*Assign Taxi*/
			for (j = 0; j < taxi_list_length; j += 3)
			{
				if (client[i][0] <= taxi[j][1] && taxi[j][0] == 100)
				{
					taxi[j][0] = i;
					client[i][6] = 1;
					break;
				}
			}
		}
		/*Client is closest to taxi Stand B (7,18)*/
		else if (abs(client[i][2] - 7) <= abs(client[i][2] - 7) && abs(client[i][2] - 7) <= abs(client[i][2] - 35) 
			&& abs(client[i][3] - 18) <= abs(client[i][3] - 3) && abs(client[i][3] - 18) <= abs(client[i][3] - 23))
		{
			/*Assign Taxi*/
			for (j = 1; j < taxi_list_length; j += 3)
			{
				if (client[i][0] <= taxi[j][1] && taxi[j][0] == 100)
				{
					taxi[j][0] = i;
					client[i][6] = 1;
					break;
				}
			}
		}
		/*Client is closest to taxi Stand C (35,23)*/
		else if (abs(client[i][2] - 35) <= abs(client[i][2] - 7) && abs(client[i][2] - 35) <= abs(client[i][2] - 7)
			&& abs(client[i][3] - 23) <= abs(client[i][3] - 3) && abs(client[i][3] - 23) <= abs(client[i][3] - 18))
		{
			/*Assign Taxi*/
			for (j = 2; j < taxi_list_length; j += 3)
			{
				if (client[i][0] <= taxi[j][1] && taxi[j][0] == 100)
				{
					taxi[j][0] = i;
					client[i][6] = 1;
					break;
				}
			}
		}
	}

	/*Simulation Section*/
	printf("Starting Simulations");
	
	/* number of ppl, fee, pickup position X, pickup position Y,
	dropoff position X, dropoff position Y, taxi sent(0 or 1),
	pickup confirm(0 or 1), dropoff confirm(0 or 1)*/
	
	/* client# to pick up, Max Occupancy,
	number of blocks traveled, Current X, Current Y*/
	
	while (simulate == 1)
	{
		for (i = 0; i <= total_client_entries)
		{
			/* Taxi moves to pickup location*/
			if (client[taxi[i][0]][7] != 1)
			{
				/*Move X Direction*/
				if (taxi[i][3] < client[taxi[i][0]][2] || taxi[i][3] > client[taxi[i][0]][2])
				{
					if (taxi[i][3] < client[taxi[i][0]][2])
					{
						taxi[i][3]++;
					}
					else if (taxi[i][3] > client[taxi[i][0]][2])
						taxi[i][3]++;
				}
				/*Move Y Direction*/
				else if (taxi[i][4] < client[taxi[i][0]][3] || taxi[i][4] > client[taxi[i][0]][3])
				{
					if (taxi[i][4] < client[taxi[i][0]][3])
					{
						taxi[i][4]++;
					}
					else if (taxi[i][4] > client[taxi[i][0]][3])
					{
						taxi--;
					}
				}
			}
			/* Taxi moves to dropoff location*/
			if (client[taxi[i][0]][7] == 1 & client[taxi[i][0]][8] != 1)
			{
				/*Move X Direction*/
				if (taxi[i][3] < client[taxi[i][0]][4] || taxi[i][3] > client[taxi[i][0]][4])
				{
					if (taxi[i][3] < client[taxi[i][0]][4])
					{
						taxi[i][3]++;
					}
					else if (taxi[i][3] > client[taxi[i][0]][4])
						taxi[i][3]++;
				}
				/*Move Y Direction*/
				else if (taxi[i][4] < client[taxi[i][0]][5] || taxi[i][4] > client[taxi[i][0]][5])
				{
					if (taxi[i][4] < client[taxi[i][0]][5])
					{
						taxi[i][4]++;
					}
					else if (taxi[i][4] > client[taxi[i][0]][5])
					{
						taxi--;
					}
				}
			}
			/*Return to a Taxi Stand(Not Done)*/
			/*Client is closest to taxi Stand A (7,3)*/
			if (abs(taxi[i][3] - 7) <= abs(taxi[i][3] - 7) && abs(taxi[i][3] - 7) <= abs(taxi[i][3] - 35)
				&& abs(taxi[i][4] - 3) <= abs(taxi[i][4] - 18) && abs(taxi[i][4] - 3) <= abs(taxi[i][4] - 23))
			{
				if (taxi[i][4] < 7)
				{
					taxi[i][4]++;
				}
				else if (taxi[i][4] > client[taxi[i][0]][5])
				{
					taxi--;
				}
			}
			/*Client is closest to taxi Stand B (7,18)*/
			else if (abs(taxi[i][3] - 7) <= abs(taxi[i][3] - 7) && abs(taxi[i][3] - 7) <= abs(taxi[i][3] - 35)
				&& abs(client[i][3] - 18) <= abs(client[i][3] - 3) && abs(client[i][3] - 18) <= abs(client[i][3] - 23))
			{
				
			}
			/*Client is closest to taxi Stand C (35,23)*/
			else if (abs(client[i][2] - 35) <= abs(client[i][2] - 7) && abs(client[i][2] - 35) <= abs(client[i][2] - 7)
				&& abs(client[i][3] - 23) <= abs(client[i][3] - 3) && abs(client[i][3] - 23) <= abs(client[i][3] - 18))
			{
				
			}


			/* Pickup Confirm */
			if (taxi[i][3] == client[taxi[i][0]][2] && taxi[i][4] == client[taxi[i][0]][3])
			{
				client[taxi[i][0]][7] = 1;
			}
			/* Dropoff Confirm */
			if (taxi[i][3] == client[taxi[i][0]][4] && taxi[i][4] == client[taxi[i][0]][5])
			{
				client[taxi[i][0]][8] = 1;
			}
		}


		printf("Continue Simulations");
		scanf("%d", &simulate);
	}
	/*Calculate Profit*/
	for (i = 0; i < 120; i++)
	{
		expenses += taxi[i][3] * 0.20;
	}
	profit = income - expenses;
	printf("Current Income: %f", income);
	printf("Current Expenses: %f", expenses);
	printf("Current Profit: %f", profit);

	return 0;
}