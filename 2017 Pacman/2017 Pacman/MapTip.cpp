#include<Windows.h>
#include<stdio.h>

#define WIDTH	640
#define	HEIGHT	780

#define MAP_HEIGHT 17
#define MAP_WIDTH  18

static int map[MAP_HEIGHT][MAP_WIDTH];

void MapLoad(const char* mapdata)
{
	FILE*  fp;
	fopen_s(&fp, mapdata, "r");

	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			fscanf_s(fp, "%d,", &map[i][j], _countof(map));
		}
	}
	fclose(fp);
}