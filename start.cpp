#pragma once
#include<stdio.h>
#include <Windows.h>
#include"declaration.h"
//函数声明；
short choose(short left_right, short c = 49);
void writer();
void title();
void tank_plane();

bool here = 0;
bool start_map[50][90] = {};
//启动模块主函数；
void start() {
	key = -1;

	//while (1) {
		title();
	//	Sleep(2000);
	//	system("cls");
	//	system("color 70");
	//}
	
	writer();
	Sleep(3000);
	system("cls");
	system("color 70");
	key = -1;

	//tank_plane();
	short t_p = 0;
	while (1) {
		tank_plane();
		if (key == 67 || key == 99) {
			egg();
		}
		if (last_key == 55 & key == 48) {
			egg();
		}
			
		t_p = choose(key);
		if (t_p == -1) {
			tank_start();
			key = -1;
		}
		if (t_p == 1) {
			plane_start();
			key = -1;
		}
		Sleep(500);
		choose(0);
		Sleep(500);
	}
		
}
//作者信息模块；
void writer() {//作者信息；
	//字体布尔（像素）矩阵；
	short x, y;
	bool ba[10][10]{
0,0,0,1,1,0,0,0,0,0,
0,0,0,0,0,1,0,0,0,0,
0,0,0,1,0,1,0,0,0,0,
0,0,0,1,0,0,1,0,0,0,
0,0,1,0,0,0,1,0,0,0,
0,0,1,0,0,0,0,1,0,0,
0,1,0,0,0,0,0,1,0,0,
0,1,0,0,0,0,0,1,0,0,
1,0,0,0,0,0,0,0,1,0,
1,0,0,0,0,0,0,0,1,1,
	}, a[10][10]{
1,1,1,0,1,1,1,1,1,1,
1,0,1,0,0,0,0,0,1,0,
1,0,1,0,0,0,0,0,1,0,
1,1,0,0,1,1,1,0,1,0,
1,0,1,0,1,0,1,0,1,0,
1,0,1,0,1,0,1,0,1,0,
1,1,1,0,1,1,1,0,1,0,
1,0,0,0,0,0,0,0,1,0,
1,0,0,0,0,0,0,0,1,0,
1,0,0,0,0,1,1,1,1,0,
	}, ge[10][10]{
0,1,1,1,1,1,1,1,1,0,
0,0,0,0,0,0,1,0,0,0,
0,0,1,1,1,0,1,0,0,0,
0,0,1,0,1,0,1,0,0,0,
1,1,1,1,1,1,1,1,1,1,
0,0,0,0,0,0,1,0,0,0,
0,0,1,1,1,0,1,0,0,0,
0,0,1,0,1,0,1,0,0,0,
0,0,1,1,0,0,1,0,0,0,
0,0,0,0,1,1,1,0,0,0,
	};
	//使用链表存储转化后的布尔坐标；
	coordinates* ba_head = NULL, * node = NULL, * end = NULL;
	ba_head = (coordinates*)malloc(sizeof(coordinates));
	end = ba_head;
	for (x = 0; x < 10; x++)
		for(y = 0; y < 10; y++)
			if (ba[x][y] == 1) {
				node = (coordinates*)malloc(sizeof(coordinates));
				end->next = node;
				node->X = y;
				node->Y = x;
				node->next = NULL;
				end = node;
				//draw(y, x, 112, 49);
			}
	//↑八
	node = NULL; end = NULL;
	coordinates* a_head = NULL;
	a_head = (coordinates*)malloc(sizeof(coordinates));
	end = a_head;
	for (x = 0; x < 10; x++)
		for (y = 0; y < 10; y++)
			if (a[x][y] == 1) {
				node = (coordinates*)malloc(sizeof(coordinates));
				end->next = node;
				node->X = y;
				node->Y = x;
				node->next = NULL;
				end = node;
				//draw(y, x, 112, 49);
			}
	//↑阿
	node = NULL, end = NULL;
	coordinates* ge_head = NULL;
	ge_head = (coordinates*)malloc(sizeof(coordinates));
	end = ge_head;
	for (x = 0; x < 10; x++)
		for (y = 0; y < 10; y++)
			if (ge[x][y] == 1) {
				node = (coordinates*)malloc(sizeof(coordinates));
				end->next = node;
				node->X = y;
				node->Y = x;
				node->next = NULL;
				end = node;
				//draw(y, x, 112, 49);
			}
	//↑哥

	//用坐标绘制像素字；
	short xx = 54, yy = 38;
	//node = ba_head->next;
	//while (node != NULL) {
	//	draw(node->X + xx, node->Y + yy);
	//	node = node->next;
	//}
	//node = a_head->next;
	//while (node != NULL) {
	//	draw(node->X + 12 + xx, node->Y + yy);
	//	node = node->next;
	//}
	//node = ge_head->next;
	//while (node != NULL) {
	//	draw(node->X + 24 + xx, node->Y + yy);
	//	node = node->next;
	//}

	//Sleep(3000);

	//动效一；
	//for (int i = -12; i < 38; i++) {
	//	node = ba_head->next;
	//	while (node != NULL) {
	//		yy = node->Y + i;
	//		if(yy >= 0)
	//			draw(node->X + xx, yy, 112, 49);
	//		node = node->next;
	//	}
	//	Sleep(2);//50*2ms，一次动画时间；
	//	node = ba_head->next;
	//	while (node != NULL) {
	//		yy = node->Y + i;
	//		if (yy >= 0)
	//			draw(node->X + xx, yy, 112, 0);
	//		node = node->next;
	//	}
	//	//i = i + 3;
	//}
	//node = ba_head->next;
	//while (node != NULL) {
	//	draw(node->X + xx, node->Y + 38, 112, 49);
	//	node = node->next;
	//}

	//动效二；
	for (int n = 0; n < 3; n++) {
		if (n == 0) {
			xx = 54;
			node = ba_head->next;
		}
			
		if (n == 1) {
			xx = 66;
			node = a_head->next;
		}
		if (n == 2) {
			xx = 78;
			node = ge_head->next;
		}

		for (int i = 0; i < 48; i++) {
			for (int j = 0; j < 10; j++) {
				if (i - j < 0)
					break;
				if (i - j > 38) {
					continue;
				}
				if (start_map[i - j][xx + 5] != 1)
					draw(xx + 5, i - j, 136, 49);
				if (start_map[i - j][xx + 6] != 1)
					draw(xx + 6, i - j, 136, 49);
			}
			Sleep(1);
			for (int j = 0; j < 10; j++) {
				if (i - j < 0)
					break;
				if (i - j > 38)
					continue;
				if (start_map[i - j][xx + 5] != 1)
					draw(xx + 5, i - j, 119, 0);
				if (start_map[i - j][xx + 6] != 1)
					draw(xx + 6, i - j, 119, 0);
			}
		}
		
		while (node != NULL) {
			draw(node->X + xx, node->Y + 38, 136, 49);
			short m = node->Y;
			node = node->next;
			if (node != NULL)
				if (m != node->Y)
					Sleep(30);
		}
	}
	

}
//名称；
void title() {
	short title[][3] = { 9,1,204,
29,1,204,
50,1,204,
54,1,204,
76,1,204,
10,2,204,
29,2,204,
50,2,204,
54,2,204,
61,2,204,
70,2,204,
71,2,204,
72,2,204,
73,2,204,
74,2,204,
75,2,204,
76,2,204,
77,2,204,
78,2,204,
79,2,204,
80,2,204,
81,2,204,
82,2,204,
4,4,17,
5,4,17,
6,4,17,
7,4,17,
8,4,17,
9,4,17,
10,4,17,
11,4,17,
12,4,17,
13,4,17,
14,4,17,
15,4,17,
16,4,17,
11,4,17,
28,3,17,
49,3,17,
54,3,17,
55,3,17,
56,3,17,
57,3,17,
58,3,17,
59,3,17,
60,3,17,
61,3,17,
76,3,17,
27,4,17,
49,4,17,
53,4,17,
60,4,17,
72,4,17,
73,4,17,
74,4,17,
75,4,17,
76,4,17,
77,4,17,
78,4,17,
79,4,17,
80,4,17,
7,5,34,
14,5,34,
26,5,34,
28,5,34,
29,5,34,
30,5,34,
31,5,34,
32,5,34,
33,5,34,
34,5,34,
35,5,34,
36,5,34,
37,5,34,
38,5,34,
48,5,34,
52,5,34,
59,5,34,
76,5,34,
8,6,34,
13,6,34,
26,6,34,
32,6,34,
47,6,34,
68,6,34,
69,6,34,
70,6,34,
71,6,34,
72,6,34,
73,6,34,
74,6,34,
75,6,34,
76,6,34,
77,6,34,
78,6,34,
79,6,34,
80,6,34,
81,6,34,
82,6,34,
83,6,34,
84,6,34,
9,7,51,
12,7,51,
48,8,51,
48,7,51,
3,8,51,
4,8,51,
5,8,51,
6,8,51,
7,8,51,
8,8,51,
9,8,51,
10,8,51,
11,8,51,
12,8,51,
13,8,51,
14,8,51,
15,8,51,
16,8,51,
17,8,51,
11,8,51,
18,8,51,
24,7,51,
25,7,51,
32,7,51,
32,8,51,
46,8,51,
46,7,51,
48,9,51,
50,8,51,
51,7,51,
52,7,51,
53,7,51,
54,7,51,
55,7,51,
56,7,51,
57,7,51,
58,7,51,
59,7,51,
60,7,51,
61,7,51,
50,8,51,
56,8,51,
62,8,51,
75,7,51,
73,8,51,
74,8,51,
79,8,51,
5,10,68,
6,10,68,
7,10,68,
8,10,68,
9,10,68,
10,10,68,
11,10,68,
12,10,68,
13,10,68,
14,10,68,
15,10,68,
26,9,68,
27,9,68,
28,9,68,
29,9,68,
30,9,68,
31,9,68,
32,9,68,
33,9,68,
34,9,68,
35,9,68,
36,9,68,
37,9,68,
27,10,68,
32,10,68,
45,9,68,
48,9,68,
48,10,68,
50,9,68,
50,10,68,
52,9,68,
53,9,68,
54,9,68,
55,9,68,
56,9,68,
57,9,68,
58,9,68,
59,9,68,
60,9,68,
56,10,68,
62,9,68,
62,10,68,
72,9,68,
77,9,68,
78,9,68,
72,10,68,
73,10,68,
74,10,68,
75,10,68,
76,10,68,
77,10,68,
5,11,85,
5,12,85,
10,11,85,
15,11,85,
15,12,85,
7,12,85,
8,12,85,
9,12,85,
10,12,85,
11,12,85,
12,12,85,
13,12,85,
27,11,85,
27,12,85,
32,11,85,
32,12,85,
51,11,85,
52,11,85,
53,11,85,
54,11,85,
55,11,85,
56,11,85,
57,11,85,
58,11,85,
59,11,85,
60,11,85,
61,11,85,
48,11,85,
48,12,85,
54,12,85,
75,11,85,
71,12,85,
72,12,85,
73,12,85,
74,12,85,
5,13,102,
10,13,102,
15,13,102,
5,14,102,
6,14,102,
7,14,102,
8,14,102,
9,14,102,
10,14,102,
11,14,102,
12,14,102,
13,14,102,
14,14,102,
15,14,102,
27,13,102,
32,13,102,
24,14,102,
25,14,102,
26,14,102,
27,14,102,
28,14,102,
29,14,102,
30,14,102,
31,14,102,
32,14,102,
33,14,102,
51,14,102,
34,14,102,
35,14,102,
36,14,102,
37,14,102,
38,14,102,
39,14,102,
40,14,102,
48,13,102,
48,14,102,
53,13,102,
51,14,102,
52,14,102,
55,13,102,
56,13,102,
55,14,102,
57,14,102,
61,14,102,
70,13,102,
69,14,102,
70,14,102,
71,14,102,
72,14,102,
73,14,102,
74,14,102,
75,14,102,
76,14,102,
77,14,102,
78,14,102,
79,14,102,
80,14,102,
81,14,102,
82,14,102,
10,15,17,
10,16,17,
32,15,17,
32,16,17,
48,15,17,
48,16,17,
54,15,17,
56,15,17,
58,15,17,
60,15,17,
55,16,17,
76,16,17,
58,15,17,
58,16,17,
59,16,17,
74,16,17,
76,15,17,
77,16,17,
78,16,17,
5,17,170,
6,17,170,
7,17,170,
8,17,170,
9,17,170,
10,17,170,
11,17,170,
12,17,170,
13,17,170,
14,17,170,
15,17,170,
10,18,170,
32,17,170,
32,18,170,
48,17,170,
48,18,170,
54,17,170,
53,18,170,
58,17,170,
58,18,170,
60,17,170,
61,18,170,
62,18,170,
73,17,170,
71,18,170,
72,18,170,
76,17,170,
76,18,170,
76,19,187,
79,17,170,
80,18,170,
81,18,170,
82,18,170,
10,19,187,
2,20,187,
3,20,187,
4,20,187,
5,20,187,
6,20,187,
7,20,187,
8,20,187,
9,20,187,
10,20,187,
11,20,187,
12,20,187,
13,20,187,
14,20,187,
15,20,187,
16,20,187,
17,20,187,
18,20,187,
19,20,187,
32,19,187,
32,20,187,
48,19,187,
48,20,187,
52,19,187,
57,19,187,
55,20,187,
56,20,187,
74,20,187,
75,20,187,
76,20,187,
0,0,0, };
	
	for (short n = 0; n < 88; n++) {
		//system("cls");
		//system("color 70");
		
		for (short i = 0; title[i][0] != 0; i++) {
			if (title[i][0] - 88 + n >= 0)
				if (title[i][2] == 204 || title[i][2] == 34 || title[i][2] == 68 || title[i][2] == 102 || title[i][2] == 170) {
					draw(title[i][0] - 88 + n, title[i][1] + 4, 119);
					start_map[title[i][1] + 4][title[i][0] - 88 + n] = 0;
				}
			if (title[i][0] + 90 - n <= 89)
				if (title[i][2] == 17 || title[i][2] == 51 || title[i][2] == 85 || title[i][2] == 17 || title[i][2] == 187) {
					draw(title[i][0] + 90 - n, title[i][1] + 4, 119);
					start_map[title[i][1] + 4][title[i][0] + 90 - n] = 0;
				}
		}

		for (short i = 0; title[i][0] != 0; i++) {
			if (title[i][0] - 86 + n >= 0) {
				if (title[i][2] == 204 || title[i][2] == 34 || title[i][2] == 68 || title[i][2] == 102 || title[i][2] == 170) {
					draw(title[i][0] - 86 + n, title[i][1] + 4, title[i][2]);
					start_map[title[i][1] + 4][title[i][0] - 86 + n] = 1;
				}
			}
			if (title[i][0] + 88 - n <= 89) {
				if (title[i][2] == 17 || title[i][2] == 51 || title[i][2] == 85 || title[i][2] == 17 || title[i][2] == 187) {
					draw(title[i][0] + 88 - n, title[i][1] + 4, title[i][2]);
					start_map[title[i][1] + 4][title[i][0] + 88 - n] = 1;
				}
			}
		}
		Sleep(10);
	}
}
//选择界面；
short choose(short left_right, short c) {
	short color_l = 121;
	short color_r = 121;
	if (left_right == 299) {
		color_l = 170;
		color_r = 121;
	}
	else if(left_right == 301) {
		color_l = 121;
		color_r = 170;
	}
	else if (left_right == 13) {
		if (last_key == 299)
			return -1;
		if (last_key == 301)
			return 1;
	}

	short x = 0, y = 0;
	for(x; x<45; x++)
		draw(x, y, color_l, c);
	x = x - 1;
	for (y; y < 50; y++)
		draw(x, y, color_l, c);
	y = y - 1;
	for (x; x > 0; x--)
		draw(x, y, color_l, c);
	for (y; y > 0; y--)
		draw(x, y, color_l, c);

	x = 45, y = 0;
	for (x; x < 90; x++)
		draw(x, y, color_r, c);
	x = 90- 1;
	for (y; y < 50; y++)
		draw(x, y, color_r, c);
	y = y - 1;
	for (x; x > 45; x--)
		draw(x, y, color_r, c);
	for (y; y > 0; y--)
		draw(x, y, color_r, c);
	return 0;
}
//类别；
void tank_plane() {
	short _tank[][3] = {
8,7,68,32,7,68,8,8,68,12,8,68,13,8,68,14,8,68,15,8,68,16,8,68,17,8,68,18,8,68,27,8,68,28,8,68,29,8,68,30,8,68,31,8,68,32,8,68,33,8,68,34,8,68,35,8,68,36,8,68,37,8,68,8,9,68,12,9,68,18,9,68,32,9,68,8,10,68,12,10,68,18,10,68,28,10,68,29,10,68,30,10,68,31,10,68,32,10,68,33,10,68,34,10,68,35,10,68,36,10,68,5,11,68,6,11,68,7,11,68,8,11,68,9,11,68,10,11,68,12,11,68,13,11,68,14,11,68,15,11,68,16,11,68,17,11,68,18,11,68,28,11,68,36,11,68,8,12,68,12,12,68,18,12,68,28,12,68,36,12,68,8,13,68,12,13,68,18,13,68,28,13,68,29,13,68,30,13,68,31,13,68,32,13,68,33,13,68,34,13,68,35,13,68,36,13,68,8,14,68,12,14,68,13,14,68,14,14,68,15,14,68,16,14,68,17,14,68,18,14,68,30,14,68,34,14,68,8,15,68,30,15,68,34,15,68,8,16,68,10,16,68,29,16,68,35,16,68,7,17,68,8,17,68,9,17,68,11,17,68,12,17,68,13,17,68,14,17,68,15,17,68,16,17,68,17,17,68,18,17,68,19,17,68,28,17,68,35,17,68,38,17,68,6,18,68,26,18,68,27,18,68,35,18,68,36,18,68,37,18,68,38,18,68,12,27,68,28,27,68,34,27,68,36,27,68,12,28,68,28,28,68,34,28,68,37,28,68,7,29,68,8,29,68,9,29,68,10,29,68,11,29,68,12,29,68,13,29,68,14,29,68,15,29,68,16,29,68,17,29,68,28,29,68,29,29,68,30,29,68,32,29,68,33,29,68,34,29,68,35,29,68,36,29,68,37,29,68,12,30,68,28,30,68,34,30,68,12,31,68,28,31,68,34,31,68,11,32,68,26,32,68,27,32,68,28,32,68,29,32,68,30,32,68,34,32,68,37,32,68,11,33,68,26,33,68,30,33,68,35,33,68,36,33,68,10,34,68,13,34,68,26,34,68,30,34,68,34,34,68,35,34,68,9,35,68,14,35,68,26,35,68,30,35,68,33,35,68,35,35,68,8,36,68,15,36,68,26,36,68,27,36,68,28,36,68,29,36,68,30,36,68,32,36,68,36,36,68,38,36,68,7,37,68,16,37,68,17,37,68,26,37,68,30,37,68,37,37,68,22,42,17,21,43,17,22,43,187,23,43,17,20,44,17,21,44,187,22,44,187,23,44,187,24,44,17,20,45,17,21,45,187,22,45,17,23,45,187,24,45,17,20,46,17,21,46,17,23,46,17,24,46,17,0,0,0, };
	short _plane[][3] = {
11,6,68,27,6,68,38,6,68,7,7,68,12,7,68,18,7,68,27,7,68,28,7,68,29,7,68,30,7,68,31,7,68,32,7,68,33,7,68,34,7,68,35,7,68,36,7,68,37,7,68,38,7,68,7,8,68,8,8,68,9,8,68,10,8,68,11,8,68,12,8,68,13,8,68,14,8,68,15,8,68,16,8,68,17,8,68,18,8,68,27,8,68,38,8,68,7,9,68,18,9,68,26,9,68,31,9,68,37,9,68,6,10,68,10,10,68,14,10,68,17,10,68,28,10,68,29,10,68,30,10,68,31,10,68,32,10,68,33,10,68,34,10,68,35,10,68,36,10,68,9,11,68,15,11,68,30,11,68,8,12,68,16,12,68,29,12,68,32,12,68,6,13,68,17,13,68,18,13,68,28,13,68,29,13,68,30,13,68,31,13,68,32,13,68,33,13,68,34,13,68,35,13,68,36,13,68,9,14,68,10,14,68,11,14,68,12,14,68,13,14,68,14,14,68,15,14,68,32,14,68,12,15,68,32,15,68,12,16,68,27,16,68,28,16,68,29,16,68,30,16,68,31,16,68,32,16,68,33,16,68,34,16,68,35,16,68,36,16,68,37,16,68,12,17,68,32,17,68,7,18,68,8,18,68,9,18,68,10,18,68,11,18,68,12,18,68,13,18,68,14,18,68,15,18,68,16,18,68,17,18,68,32,18,68,10,27,68,28,27,68,29,27,68,30,27,68,31,27,68,32,27,68,33,27,68,34,27,68,35,27,68,10,28,68,28,28,68,35,28,68,10,29,68,15,29,68,28,29,68,35,29,68,10,30,68,14,30,68,28,30,68,29,30,68,30,30,68,31,30,68,32,30,68,33,30,68,34,30,68,35,30,68,10,31,68,12,31,68,13,31,68,9,32,68,10,32,68,11,32,68,27,32,68,28,32,68,29,32,68,30,32,68,31,32,68,32,32,68,33,32,68,34,32,68,35,32,68,36,32,68,7,33,68,8,33,68,10,33,68,29,33,68,10,34,68,28,34,68,29,34,68,30,34,68,31,34,68,32,34,68,33,34,68,34,34,68,35,34,68,10,35,68,35,35,68,10,36,68,16,36,68,34,36,68,10,37,68,11,37,68,12,37,68,13,37,68,14,37,68,15,37,68,32,37,68,33,37,68,34,37,68,22,40,17,21,41,17,22,41,187,23,41,17,21,42,17,22,42,187,23,42,17,20,43,17,21,43,187,22,43,187,23,43,187,24,43,17,20,44,17,21,44,187,22,44,17,23,44,187,24,44,17,20,45,17,21,45,17,23,45,17,24,45,17,20,46,17,24,46,17,0,0,0,
	};
	for (int i = 0; _tank[i][0] != 0; i++) {
		draw(_tank[i][0], _tank[i][1], _tank[i][2]);
		if (_tank[i][1] < 38)
			draw(_tank[i][0] + 1, _tank[i][1], _tank[i][2]);
	}
		
	for (int i = 0; _plane[i][0] != 0; i++) {
		draw(_plane[i][0] + 46, _plane[i][1], _plane[i][2]);
		if (_plane[i][1] < 38)
			draw(_plane[i][0] + 47, _plane[i][1], _plane[i][2]);
	}
}