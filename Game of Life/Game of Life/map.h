#pragma once

class map
{
public:
	static const int cell_size = 8;
	static const int window_size = 120;
	int data[window_size][window_size];
public:
	map();
	void update();
	void draw();
	void life(int x, int y,int temp[window_size][window_size]);

};