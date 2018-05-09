/*	graphics.c				*
 *	functions to display the board		*
 *	using gtk as the graphics base		*/

#include "graphics.h"

GtkWidget *window;
GtkWidget *fixed;
GtkWidget *taxi_icon;
GtkWidget *table;

/*enum array of board labeling all corners for graphics*/
/*enum MAP_OBJ Board[WIDTH][HEIGHT];
*/
/*Create a New Window*/
void NewWindow(int width, int height)
{
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_widget_set_size_request(window, width, height);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_title(GTK_WINDOW(window), "Map of New Irvine");
	gtk_window_set_resizeable(GTK_WINDOW(window), FALSE);

	g_signal_connect(window, "delete_event", G_CALLBACK(on_selete_event), NULL);

	table = gtk_table_new(width, height, TRUE);
	gtk_widget_set_size_request(table, width, height);
	DrawBoard(width, height);

	fixed = gtk_fixed_new();
	gtk_fixed_put(GTK_FIXED(fixed), table, 0, 0);
	gtk_container_add(GTK_CONTAINER(window), fixed);

	gtk_widget_show_all(window);
	gtk_main();
}

void DrawMap(int width, int height)
{
	int i, j;

	for(i = 0; i < width; i ++)
	{
		for(j = 0; j < height; j ++)
		{
			switch(Board[i][j])
			{
/*GRID & LANDMARK GRAPHICS*/
				case TOP_BLANK:
				case BOT_LAND_BLANK:
					taxi_icon = gtk_image_new_from_file("./taxi_pieces/blank_pieces/top_side.jpg");
					break;
				case TOP_RIGHT_BLANK:
					taxi_icon = gtk_image_new_from_file("./taxi_pieces/blank_pieces/top_right_corner.jpg");
					break;
				case TOP_LEFT_BLANK:
					taxi_icon = gtk_image_new_from_file("./taxi_pieces/blank_pieces/top_left_corner.jpg");
					break;
				case RIGHT_BLANK:
				case LEFT_LAND_BLANK:
					taxi_icon = gtk_image_new_from_file("./taxi_pieces/blank_pieces/right_side.jpg");
					break;
				case LEFT_BLANK:
				case RIGHT_LAND_BLANK:
					taxi_icon = gtk_image_new_from_file("./taxi_pieces/blank_pieces/left_side.jpg");
					break;
				case BOT_RIGHT_BLANK:
					taxi_icon = gtk_image_new_from_file("./taxi_pieces/blank_pieces/bot_right_corner.jpg");
					break;
				case BOT_LEFT_BLANK:
					taxi_icon = gtk_image_new_from_file("./taxi_pieces/blank_pieces/bot_left_corner.jpg");
					break;
				case BOT_BLANK:
				case TOP_LAND_BLANK:
					taxi_icon = gtk_image_new_from_file("./taxi_pieces/blank_pieces/bot_side.jpg");
					break;
				case MIDDLE_BLANK:
					taxi_icon = gtk_image_new_from_file("./taxi_pieces/blank_pieces/grid.jpg");
					break;
				case MIDDLE_LAND_BLANK:
					taxi_icon = gtk_image_new_from_file("./taxi_pieces/blank_pieces/blank.jpg");
					break;

				case TOP_TAXI:
					taxi_icon = gtk_image_new_from_file("./taxi_pieces/blank_taxi/taxi_top.jpg");
					break;
				case TOP_RIGHT_TAXI:
					taxi_icon = gtk_image_new_from_file("./taxi_pieces/blank_taxi/taxi_top_right.jpg");
					break;
				case TOP_LEFT_TAXI:
					taxi_icon = gtk_image_new_from_file("./taxi_pieces/blank_taxi/taxi_top_left.jpg");
					break;
				case RIGHT_TAXI:
					taxi_icon = gtk_image_new_from_file("./taxi_pieces/blank_taxi/taxi_right.jpg");
					break;
				case LEFT_TAXI:
					taxi_icon = gtk_image_new_from_file("./taxi_pieces/blank_taxi/taxi_left.jpg");
					break;
				case BOT_RIGHT_TAXI:
					taxi_icon = gtk_image_new_from_file("./taxi_pieces/blank_taxi/taxi_bot_right.jpg");
					break;
				case BOT_LEFT_TAXI:
					taxi_icon = gtk_image_new_from_file("./taxi_pieces/blank_taxi/taxi_bot_left.jpg");
					break;
				case BOT_TAXI:
					taxi_icon = gtk_image_new_from_file("./taxi_pieces/blank_taxi/taxi_bot.jpg");
					break;
				case MIDDLE_TAXI:
					taxi_icon = gtk_image_new_from_file("./taxi_pieces/blank_taxi/taxi_grid.jpg");
					break;
/*TAXI STANDS*/
				case BOT_STAND:
					taxi_icon = gtk_image_new_from_file("./taxi_pieces/taxi_stand_blank/top_stand_blank.jpg");
					break;
				case TOP_RIGHT_STAND:
					taxi_icon = gtk_image_new_from_file("./taxi_pieces/taxi_stand_blank/top_right_stand_blank.jpg");
					break;
				case TOP_LEFT_STAND:
					taxi_icon = gtk_image_new_from_file("./taxi_pieces/taxi_stand_blank/top_left_stand_blank.jpg");
					break;
				case LEFT_STAND:
					taxi_icon = gtk_image_new_from_file("./taxi_pieces/taxi_stand_blank/right_stand_blank.jpg");
					break;
				case RIGHT_STAND:
					taxi_icon = gtk_image_new_from_file("./taxi_pieces/taxi_stand_blank/left_stand_blank.jpg");
					break;
				case BOT_RIGHT_STAND:
					taxi_icon = gtk_image_new_from_file("./taxi_pieces/taxi_stand_blank/bot_right_stand_blank.jpg");
					break;
				case BOT_LEFT_STAND:
					taxi_icon = gtk_image_new_from_file("./taxi_pieces/taxi_stand_blank/bot_left_stand_blank.jpg");
					break;
				case TOP_STAND:
					taxi_icon = gtk_image_new_from_file("./taxi_pieces/taxi_stand_blank/bot_stand_blank.jpg");
					break;
				case MIDDLE_STAND:
					taxi_icon = gtk_image_new_from_file("./taxi_pieces/taxi_stand_blank/middle_stand_blank.jpg");
					break;
			}		
			
			/* added gtk_shrink which lets our widgets become smaller as well when the window resizes */
			gtk_table_attach(GTK_TABLE(table), taxi_icon, i, i + 1, j, j + 1, GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 0, 0);
		}
	}
}

void ResetMap()
{
	
}

/*
void MoveTheTaxi(int x1, int y1, int x2, int y2)
{
	assert(Board[x1][y1]); 
	
	assert(Board[x2][y2] == TOP_BLANK || Board[x2][y2] == TOP_RIGHT_BLANK || Board[x2][y2] == TOP_LEFT_BLANK || Board[x2][y2] == BOT_BLANK || Board[x2][y2] == BOT_RIGHT_BLANK || Board[x2][y2] == BOT_LEFT_BLANK || Board[x2][y2] == RIGHT_BLANK || Board[x2][y2] == LEFT_BLANK || Board[x2][y2] == MIDDLE_BLANK); 
	
	
}*/
