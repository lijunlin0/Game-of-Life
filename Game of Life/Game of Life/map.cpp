#include"map.h"
#include <graphics.h>

map::map()
{
	int num = 0;
	for (int i = 0; i < window_size; i++)
	{
		for (int j = 0; j < window_size; j++)
		{
			num = rand() % 2;
			data[i][j] = num;
		}
	}
	data[20][20] = 1;
	data[21][21] = 1;
	data[22][21] = 1;
	data[22][20] = 1;
	data[22][19] = 1;

	data[10][10] = 1;
	data[10][13] = 1;
	data[11][14] = 1;
	data[12][14] = 1;
	data[13][14] = 1;
	data[13][13] = 1;
	data[13][12] = 1;
	data[13][11] = 1;
	data[12][10] = 1;
}

void map::life(int x, int y,int temp[window_size][window_size])
{
	int num = 0;
	for (int i = y - 1; i <= y + 1; i++)
	{
		for (int j = x - 1; j <= x + 1; j++)
		{
			if (i == y && j == x)
			{
				continue;
			}
			else if (j<0 || j>window_size || i<0 || i>window_size)
			{
				continue;
			}
			else if (temp[i][j] == 1)
			{
				num++;
			}
		}
	}
	//��λ��Ϊ��ϸ��ʱ
	if (temp[y][x] == 1)
	{
		//�µ�����
		if(num <= 1)
		{
			data[y][x] = 0;
		}
		//ӵ������
		else if (num > 3)
		{
			data[y][x] = 0;
		}
	}
	//��λ��Ϊ��ϸ��ʱ
	else
	{
		//����
		if (num == 3)
		{
			data[y][x] = 1;
		}
	}
}

void map::update()
{
	int temp[window_size][window_size];
	for (int i = 0; i < window_size; i++)
	{
		for (int j = 0; j < window_size; j++)
		{
			temp[i][j] = data[i][j];
		}
	}
	for (int i = 0; i < window_size; i++)
	{
		for (int j = 0; j < window_size; j++)
		{
			life(j, i, temp);
		}
	}
}

void map::draw()
{
	for (int i = 0; i < window_size; i++)
	{
		for (int j = 0; j < window_size; j++)
		{
			if (data[i][j] == 1)
			{
				setfillcolor(BLACK);
				solidrectangle(j * cell_size, i * cell_size, j * cell_size + cell_size - 1, i * (cell_size)+cell_size - 1);
			}
		}
	}
}
