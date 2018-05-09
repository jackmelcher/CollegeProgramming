/*********************************************************/
/* readmap.h: header file for read map function          */
/*Jack Melcher 67574625                                  */
/*3/1/2015											     */
/*********************************************************/

#ifndef READMAP_H
#define READMAP_H

/*Libraries*/
#include<stdio.h>
#include<string.h>

/*Function Declaration*/
int readmap(char ew_list[100][50], char ns_list[100][50], char landmark_names[100][100],
	int landmark_entrance_coordinates[100][2], int landmark_boundary_coordinates[100][4],
	int taxi_stand_coordinates[10][2], int size[2]);

#endif