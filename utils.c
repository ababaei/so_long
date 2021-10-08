#include "so_long.h"

void get_pos(t_parse *data)
{
	int row;
	int col;

	row = 0;
	while (data->map[row])
	{
		col = 0;
		while (data->map[row][col])
		{
			if (data->map[row][col] == 'P') 
			{
				data->player_pos[0] = col;
				data->player_pos[0] = row;
			}	
			col++;	
		}
		row++;
	}
}
