/*Server storage of information*/

#include <stdio.h>

int main(void)
{
	/*counter variables*/
	int i;

	/*client info array*/
	/*client active, fee, pickup: NS, EW, dropoff: NS, EW*/
	int client[100][6];


	/*taxi info array*/
	/*taxi active, client#, blocks traveled (salary), position: NS, EW*/
	int taxi[100][5];

	/*money earned from fees*/
	int earnings;
	/* earnings minus the sum of the taxi cab salary*/
	int profit;

	/*taxi stand coordinates*/
	int standa_x = 7;
	int standa_y = 18;
	int standb_x = 7;
	int standb_y = 3;
	int standc_x = 35;
	int standc_y = 23;

	/*Initialize taxi locations*/
	for (i = 0; i < 100; i++)
	{
		if (j = 1)
		{
			taxi[i][3] = standa_x;
			taxi[i][4] = standa_y;
		}
		if (j = 2)
		{
			taxi[i][3] = standb_x;
			taxi[i][4] = standb_y;
		}
		if (j = 3)
		{
			taxi[i][3] = standc_x;
			taxi[i][4] = standc_y;
		}
		j++;
		if (j == 4)
			j = 1;
	}

	/* client input test*/
	for (i = 0; i < 100; i++)
	{
		if (client[i][0] != 1)
			break;
	}
	printf("Client Slot that is inactive: %d\n", i);

	/*client number i is now active*/
	client[i][0] = 1;
	printf("Enter a pickup X coordinate (0 to 41): ");
	scanf("%d", &client[i][2]);
	printf("Enter a pickup Y coordinate (0 to 25): ");
	scanf("%d", &client[i][3]);

	printf("Enter a dropoff X coordinate (0 to 41): ");
	scanf("%d", &client[i][4]);
	printf("Enter a dropoff Y coordinate (0 to 25): ");
	scanf("%d", &client[i][5]);

	/*taxi response test*/
	/*find active client*/
	for (i = 0; i < 100; i++)
	{
		if (client[i][0] == 1)
			break;
	}
	printf("Active Client Slot found: %d\n", i);

	/*find inactive taxi and activate it*/
	for (j = 0; j < 100; j++)
	{
		if (taxi[j][0] != 1)
			break;
	}
	/*set client to taxi*/
	taxi[j][1] = i;
	printf("Activing taxi %d for client %d\n",j, i);

	/*routing algorithm*/


	return 0;
}