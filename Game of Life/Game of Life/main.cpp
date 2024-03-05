#include <iostream>
#include <graphics.h>
#include <time.h>
#include <conio.h>
#include <ctime>
#include <windows.h>
using namespace std;

int main() {
	initgraph(800, 850); // ��������

	// ���ƽ���
	for (int row = 0; row <= 40; row++) {
		for (int col = 0; col <= 40; col++) {
			line(0, row * 20, 800, row * 20);
			line(col * 20, 0, col * 20, 800);
		}
	}

	int life[40][40] = { 0 }; // ������ά��������ʾ����״̬
	int count[40][40] = { 0 };
	int key = 0; // �ж�Start״��
	ExMessage msg;

	while (1) {
		if (key == 0) {
			rectangle(360, 810, 440, 840);
			outtextxy(378, 818, _T("START"));
		}
		else {
			setlinecolor(RED);
			rectangle(360, 810, 440, 840);
			break;
		}

		if (peekmessage(&msg, EM_MOUSE)) // �������Ϣ�����棬û�з��ؼ�
		{
			switch (msg.message) {
			case WM_LBUTTONDOWN:
				if (msg.x >= 0 && msg.x <= 800 && msg.y >= 0 && msg.y <= 800) {
					cout << "�ߺ�,����������" << endl;
					int temp_x = msg.x / 20;
					int temp_y = msg.y / 20;
					life[temp_x][temp_y] = 1;

					setfillcolor(WHITE);
					setlinecolor(0);
					fillrectangle(temp_x * 20, temp_y * 20, (temp_x + 1) * 20, (temp_y + 1) * 20);
				}
				else if (msg.x >= 360 && msg.x <= 810 && msg.y >= 440 && msg.y <= 840) {
					key += 1;
					key %= 2;
				}
				break;
			case WM_RBUTTONDOWN:
				if (msg.x >= 0 && msg.x <= 800 && msg.y >= 0 && msg.y <= 800) {
					cout << "�ߺ�,���Ҽ������" << endl;
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

	while (1) {
		// ������Χ��ϸ������
		for (int row = 0; row < 40; row++) {
			for (int col = 0; col < 40; col++) {
				int alive_neighbors = 0;
				for (int i = -1; i <= 1; i++) {
					for (int j = -1; j <= 1; j++) {
						if (i == 0 && j == 0) continue; // �ų�����
						int neighbor_x = row + i;
						int neighbor_y = col + j;
						if (neighbor_x >= 0 && neighbor_x < 40 && neighbor_y >= 0 && neighbor_y < 40) {
							alive_neighbors += life[neighbor_x][neighbor_y];
						}
					}
				}
				count[row][col] = alive_neighbors;
			}
		}

		// ���ݹ����������״̬
		for (int row = 0; row < 40; row++) {
			for (int col = 0; col < 40; col++) {
				if (life[row][col] == 1) {
					if (count[row][col] < 2 || count[row][col] > 3) {
						life[row][col] = 0; // ���������ӵ��������
					}
				}
				else {
					if (count[row][col] == 3) {
						life[row][col] = 1; // ���������ھӣ�����
					}
				}
			}
		}

		// ������ƴ���
		cleardevice();

		// ��������״̬
		for (int row = 0; row < 40; row++) {
			for (int col = 0; col < 40; col++) {
				if (life[row][col] == 1) {
					setfillcolor(WHITE);
				}
				else {
					setfillcolor(0);
				}
				setlinecolor(WHITE);
				fillrectangle(row * 20, col * 20, (row + 1) * 20, (col + 1) * 20);
			}
		}

		Sleep(2000); // ��ͣһ����
	}

	getchar();
	closegraph();
	return 0;
}