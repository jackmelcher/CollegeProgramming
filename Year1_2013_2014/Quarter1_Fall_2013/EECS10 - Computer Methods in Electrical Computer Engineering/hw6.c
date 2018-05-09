//i did not understand global arrays, i could not understand using arrays with user created function, 
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	float polygon[2][100];//polygon array, x[0][j] y[1][j]

	int n = 0;//number of vertices in polygon
	int j = 0;//counter for vertex in array
	int k = 1;//counter for which vertex coordinates are being inputed

	char selection;//switch case variable, choice characters are c, r, i, a, e

	float Xc;//x-coordinate of centroid
	float Yc;//y-coordinate of centroid

	float alpha = 1;//scaling variable

	printf("Enter the number of vertices of a polygon(n<=100):");
	scanf("%d", &n);

	while (j < n)//loop for the number of vertices
	{
		//assume user enters vertices to create a convex shape
		printf("x-coordinate of vertex%d: ", k);
		scanf("%f", &polygon[0][j]);
		printf("y-coordinate of vertex%d: c", k);
		scanf("%f", &polygon[1][j]);
		printf("Vertex%d=(%f,%f)\n", k, polygon[0][j], polygon[1][j]);
		printf("\n");

		j = j + 1;
		k = k + 1;
	}

	while (1)
	{
		printf("Enter c to find the centroid of the polygon.\n");
		printf("Enter r to resize the polygon.\n");
		printf("Enter i to check if the polygon is inscribed.\n");
		printf("Enter a to find the area of the polygon.\n");
		printf("Enter e to exit.\n");
		printf("\n");
		scanf(" %c", &selection);

		switch (selection)
		{
			case'c':
				//finds centroid of shape
				for (j = 0; j < n; j++)
				{
					Xc = Xc + polygon[0][j];
				}
				Xc = Xc / n;

				for (j = 0; j < n; j++)
				{
					Yc = Yc + polygon[1][j];
				}
				Yc = Yc / n;
				printf("The centroid of the polygon is:(%f,%f)\n", Xc, Yc);
				printf("\n");
				break;

			case'r':
				//resizes the vertices
				printf("Enter scaling factor(alpha>0):");
				scanf("%f", &alpha);
				
				if (alpha > 0)
				{
					printf("Coordinates of the vertices for the resized polygon\n");
					for (j = 0; j < n; j++)
					{
						polygon[0][j] = polygon[0][j] * alpha;
						polygon[1][j] = polygon[1][j] * alpha;
						printf("(%f,%f)\n", polygon[0][j], polygon[1][j]);
					}
					printf("\n");
					break;
				}
				else
				{
					printf("Invalid alpha.\n");
					printf("\n");
					break;
				}
					

			case'i':
				//determines if shape is inscribed
				//finding angles of shape
				//check to see if shape is inscribed
				//if yes, print that it is inscribed
				//if no, print that it is not inscribed

				break;

			case'a':
				//find angles of shapes
				//use shapes to find area of separate triangles
				//add triangles together to get total area
				
			case'e':
				exit(0);
				break;

			default:
				printf("\n");
				break;
		}
	}
	
	return 0;
}