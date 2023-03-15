#include <graphics.h>
#include <conio.h>
#include<iostream>
#include<windows.h>
#include"map.h"
#include"time.h"

using namespace std;
long long time::update_ms = 0;

int main()
{
	srand((unsigned)time(NULL));//根据系统时间改变的随机种子
	//窗口大小：120*120
	map m;
	initgraph(map::window_size*map::cell_size, map::window_size*map::cell_size);
	while (true)
	{
		long long current = time::current_time();
		if (current - time::update_ms < time::frame_ms)
		{
			continue;
		}
		time::update_ms = current;
		
		BeginBatchDraw();

		setfillcolor(WHITE);
		solidrectangle(0, 0, map::window_size * map::cell_size, map::window_size * map::cell_size);
		m.draw();
		m.update();

		EndBatchDraw();
	}
	system("pause");
	return 0;
}