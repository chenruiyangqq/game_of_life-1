
#include <iostream>
#include <graphics.h>
#include <time.h>
#include <conio.h>
#include <ctime>
#include <windows.h>
using namespace std;




int main() {

	initgraph(800, 850);        //创建窗口


	//绘制界面
	for (int row = 0; row <= 40; row++)
	{
		for (int col = 0; col <= 40; col++)
		{
			line(0, row * 20, 800, row * 20);
			line(col * 20, 0, col * 20, 800);
		}
	}

	int life[40][40] = { 0 };       //声明二维数组来表示生命状态
	int count[40][40] = { 0 };


	int key = 0;        //判断Start状况





	ExMessage msg;

	while (1) {

	A:
		if (key == 0)
		{
			rectangle(360, 810, 440, 840);
			outtextxy(378, 818, _T("START"));
		}
		else
		{
			setlinecolor(RED);
			rectangle(360, 810, 440, 840);
			break;
		}



		if (peekmessage(&msg, EM_MOUSE))        //有鼠标消息返回真，没有返回假
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= 0 && msg.x <= 800 && msg.y >= 0 && msg.y <= 800)
				{
					cout << "哼哼,被左键点击了" << endl;
					int temp_x = msg.x / 20;
					int temp_y = msg.y / 20;
					life[temp_x][temp_y] = 1;

					setfillcolor(WHITE);
					setlinecolor(0);
					fillrectangle(temp_x * 20, temp_y * 20, (temp_x + 1) * 20, (temp_y + 1) * 20);

				}
				else if (msg.x >= 360 && msg.x <= 810 && msg.y >= 440 && msg.y <= 840)
				{
					key += 1;
					key %= 2;
					//cout << key;
				}
				break;
			case WM_RBUTTONDOWN:
				if (msg.x >= 0 && msg.x <= 800 && msg.y >= 0 && msg.y <= 800)
				{

					cout << "哼哼,被右键点击了" << endl;
					int temp_x = msg.x / 20;
					int temp_y = msg.y / 20;
					life[temp_x][temp_y] = 0;

					setfillcolor(0);
					setlinecolor(WHITE);
					fillrectangle(temp_x * 20, temp_y * 20, (temp_x + 1) * 20, (temp_y + 1) * 20);

				}
				break;

				if (msg.x >= 360 && msg.x <= 810 && msg.y >= 440 && msg.y <= 840)
				{
					setlinecolor(WHITE);
					fillrectangle(360, 810, 440, 840);
				}
			default:
				break;
			}
		}
	}



	while (1)
	{

		for (int row = 0; row < +40; row++)
		{
			for (int col = 0; col <= 40; col++)
			{
				if (life[row][col] == 1)
				{
					for (int i = -1; i <= 1; i++)
					{
						for (int j = -1; j <= 1; j++)
						{
							if (life[row + i][col + j] == 1)
							{
								count[row][col]++;
							}
						}
					}
					count[row][col]--;
				}
				else if (life[row][col] == 1)
				{
					for (int i = -1; i <= 1; i++)
					{
						for (int j = -1; j <= 1; j++)
						{
							if (life[row + i][col + j] == 1)
							{
								count[row][col]++;
							}
						}
					}
				}

			}
		}


		for (int row = 0; row <= 40; row++)
		{
			for (int col = 0; col <= 40; col++)
			{
				if (life[row][col] == 1)
				{
					if (count[row][col] > 3 || count[row][col] < 2)
					{
						life[row][col] == 0;
					}
					else if (count[row][col] == 2 || count[row][col] == 3)
					{
						life[row][col] == 1;
					}
					else
					{
						life[row][col] == 0;
					}
				}
				else if (life[row][col] == 0)
				{
					if (count[row][col] == 3)
					{
						life[row][col] == 1;
					}
				}
			}
		}



		cleardevice();

		for (int row = 0; row <= 40; row++)
		{
			for (int col = 0; col <= 40; col++)
			{
				if (life[row][col] == 1)
				{
					setfillcolor(WHITE);
					setlinecolor(0);
					fillrectangle(row * 20, col * 20, (row + 1) * 20, (col + 1) * 20);

				}
				else if (life[row][col] == 0)
				{
					setfillcolor(0);
					setlinecolor(WHITE);
					fillrectangle(row * 20, col * 20, (row + 1) * 20, (col + 1) * 20);

				}
			}
		}


		Sleep(1000);

	}







	getchar();

	closegraph();
	return 0;


}