
#include <iostream>
#include <graphics.h>
#include <time.h>
#include <conio.h>

using namespace std;

int main() {

	initgraph(800, 850);

	for (int row = 0; row <= 40;  row++) {
		for (int col = 0; col <= 40; col++) {
			line(0, row * 20, 800, row * 20);
			line(col * 20, 0, col * 20, 800);
		}
	}

	int life[40][40] = { 0 }; 





    rectangle(360, 810, 440, 840);












	ExMessage msg;
	while (1) {
        if (peekmessage(&msg, EM_MOUSE))//有鼠标消息返回真，没有返回假
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
            default:
                break;
            }
        }



	}







	_getch();

	closegraph();
	return 0;

}