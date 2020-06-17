#pragma once
#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<iostream>
#include<time.h>
#include"declaration.h"
//全局变量；
HANDLE gotoH = GetStdHandle(STD_OUTPUT_HANDLE);//获取句柄；
COORD position;
HANDLE mutex_temp, mutex_draw, mutex_esc, mutex_map, mutex_scoring;
//游戏地图；
short map[48][48] = {};//map地址是实际地址xy减1；
unsigned timestamp = 0, delay = 0;
//检测地图状态；
short state(short TS_x, short TS_y, short TS_type) {
	short x, y, type;
	x = TS_x;
	y = TS_y;
	type = TS_type;
	//接收真实值；
	//记录检测，返回指定值；
	if (x > 0 && x < 49 && y > 0 && y < 49) {
		if (type != -1) {//all => 0表空，1表墙；plane => 2表生命，3表弹药，4表飞机；
			map[y - 1][x - 1] = type;
		}
		else {
			return map[y - 1][x - 1];
		}
	}
	return -1;
}
//绘制像素；
short draw(short x, short y, short f_color, short c) {

	SetConsoleTextAttribute(gotoH, f_color);
	//定位
	position.X = x * 2;
	position.Y = y;
	SetConsoleCursorPosition(gotoH, position);//定位函数；
	//绘制
	switch (c) {
	case 48:printf("□"); break;
	case 49:printf("■"); break;
	case 50:printf("囧"); break;
	default:printf("%c%c", c, c);
	}

	return 0;
}
//消息；
short message(const char* ch, short color, short delayed, bool clear) {
	if (delay > time(0) - timestamp && clear == 0)
		return 0;
	delay = delayed;
	short length = 0;
	P(1);
	for (int j = 0; j < 2; j++)
		for (int i = 0; i < 35; i++)
			draw(52 + i, 44 + j, 119);
	V(1);

	P(1);
	SetConsoleTextAttribute(gotoH,color);
	for (int j = 0; j < 2; j++) {
		for (int i = 0; i < 35; i++) {
			position.X = 52 * 2 + i * 2;
			position.Y = 44 + j;
			SetConsoleCursorPosition(gotoH, position);//定位函数；
			if (ch[length] == '\0') {
				V(1);
				timestamp = time(0);
				return 0;
			}
			printf("%c", ch[length]);
			length++;
		}
	}
	V(1);
}
//记分器；
short scoring(short type, short score) {
	short x = 68, y = 0, count = 0, color = 170;
	//判断是否符合标准；
	switch (type) {
	case 1:y = 7; break;
	case 2:y = 26; break;
	case 3:y = 4; break;
	case 4:y = 17; break;
	case 5:y = 30; break;
	default:return -1;
	}
	if (score > 999 || score < 0)
		return -2;

	//阿拉伯数字像素坐标；
	short null[][3] = {
1,1,119,
2,1,119,
3,1,119,
4,1,238,
5,1,119,
1,2,119,
5,2,119,
1,3,119,
5,3,119,
1,4,238,
5,4,119,
1,5,119,
2,5,119,
3,5,119,
4,5,238,
5,5,119,
1,6,119,
5,6,119,
1,7,119,
5,7,119,
1,8,119,
5,8,119,
1,9,238,
5,9,119,
1,10,119,
2,10,119,
3,10,119,
4,10,119,
5,10,119,
0,0,0,
	};
	short zero[][2] = {
		1,1,2,1,3,1,4,1,5,1,1,2,5,2,1,3,5,3,1,4,5,4,1,5,5,5,1,6,5,6,1,7,5,7,1,8,5,8,1,9,5,9,1,10,2,10,3,10,4,10,5,10,0,0, };
	short one[][2] = {
		4,1,5,1,5,2,5,3,5,4,5,5,5,6,5,7,5,8,5,9,5,10,0,0, };
	short two[][2] = {
		1,1,2,1,3,1,4,1,5,1,5,2,5,3,5,4,1,5,2,5,3,5,4,5,5,5,1,6,1,7,1,8,1,9,1,10,2,10,3,10,4,10,5,10,0,0, };
	short three[][2] = {
		1,1,2,1,3,1,4,1,5,1,5,2,5,3,5,4,1,5,2,5,3,5,4,5,5,5,5,6,5,7,5,8,5,9,1,10,2,10,3,10,4,10,5,10,0,0, };
	short four[][2] = {
		1,1,5,1,1,2,5,2,1,3,5,3,1,4,5,4,1,5,2,5,3,5,4,5,5,5,5,6,5,7,5,8,5,9,5,10,0,0, };
	short five[][2] = {
		1,1,2,1,3,1,4,1,5,1,1,2,1,3,1,4,1,5,2,5,3,5,4,5,5,5,5,6,5,7,5,8,5,9,1,10,2,10,3,10,4,10,5,10,0,0, };
	short six[][2] = {
		1,1,2,1,3,1,4,1,5,1,1,2,1,3,1,4,1,5,2,5,3,5,4,5,5,5,1,6,5,6,1,7,5,7,1,8,5,8,1,9,5,9,1,10,2,10,3,10,4,10,5,10,0,0, };
	short seven[][2] = {
		1,1,2,1,3,1,4,1,5,1,5,2,5,3,5,4,5,5,5,6,5,7,5,8,5,9,5,10,0,0, };
	short eight[][2] = {
		1,1,2,1,3,1,4,1,5,1,1,2,5,2,1,3,5,3,1,4,5,4,1,5,2,5,3,5,4,5,5,5,1,6,5,6,1,7,5,7,1,8,5,8,1,9,5,9,1,10,2,10,3,10,4,10,5,10,0,0, };
	short nine[][2] = {
		1,1,2,1,3,1,4,1,5,1,1,2,5,2,1,3,5,3,1,4,5,4,1,5,2,5,3,5,4,5,5,5,5,6,5,7,5,8,5,9,1,10,2,10,3,10,4,10,5,10,0,0, };
	P(1);
	//置空；
	for (int i = 0; null[i][0] != 0; i++) {
		draw(null[i][0] + x, null[i][1] + y, null[i][2]);
		draw(null[i][0] + x + 7, null[i][1] + y, null[i][2]);
		draw(null[i][0] + x + 14, null[i][1] + y, null[i][2]);
	}

	//hundred;
	bool on_off = 0;
	count = score / 100;
	switch (count) {
	case 0:break;
	case 1:for (int i = 0; one[i][0] != 0; i++) draw(one[i][0] + x, one[i][1] + y, color); on_off = 1; break;
	case 2:for (int i = 0; two[i][0] != 0; i++) draw(two[i][0] + x, two[i][1] + y, color); on_off = 1; break;
	case 3:for (int i = 0; three[i][0] != 0; i++) draw(three[i][0] + x, three[i][1] + y, color); on_off = 1; break;
	case 4:for (int i = 0; four[i][0] != 0; i++) draw(four[i][0] + x, four[i][1] + y, color); on_off = 1; break;
	case 5:for (int i = 0; five[i][0] != 0; i++) draw(five[i][0] + x, five[i][1] + y, color); on_off = 1; break;
	case 6:for (int i = 0; six[i][0] != 0; i++) draw(six[i][0] + x, six[i][1] + y, color); on_off = 1; break;
	case 7:for (int i = 0; seven[i][0] != 0; i++) draw(seven[i][0] + x, seven[i][1] + y, color); on_off = 1; break;
	case 8:for (int i = 0; eight[i][0] != 0; i++) draw(eight[i][0] + x, eight[i][1] + y, color); on_off = 1; break;
	case 9:for (int i = 0; nine[i][0] != 0; i++) draw(nine[i][0] + x, nine[i][1] + y, color); on_off = 1; break;
	}
	//ten;
	if (on_off == 1)
		score = score % 100;

	count = score / 10;
	x = x + 7;
	switch (count) {
	case 0:if (on_off == 1) { for (int i = 0; zero[i][0] != 0; i++) draw(zero[i][0] + x, zero[i][1] + y, color); } break;
	case 1:for (int i = 0; one[i][0] != 0; i++) draw(one[i][0] + x, one[i][1] + y, color); on_off = 1; break;
	case 2:for (int i = 0; two[i][0] != 0; i++) draw(two[i][0] + x, two[i][1] + y, color); on_off = 1; break;
	case 3:for (int i = 0; three[i][0] != 0; i++) draw(three[i][0] + x, three[i][1] + y, color); on_off = 1; break;
	case 4:for (int i = 0; four[i][0] != 0; i++) draw(four[i][0] + x, four[i][1] + y, color); on_off = 1; break;
	case 5:for (int i = 0; five[i][0] != 0; i++) draw(five[i][0] + x, five[i][1] + y, color); on_off = 1; break;
	case 6:for (int i = 0; six[i][0] != 0; i++) draw(six[i][0] + x, six[i][1] + y, color); on_off = 1; break;
	case 7:for (int i = 0; seven[i][0] != 0; i++) draw(seven[i][0] + x, seven[i][1] + y, color); on_off = 1; break;
	case 8:for (int i = 0; eight[i][0] != 0; i++) draw(eight[i][0] + x, eight[i][1] + y, color); on_off = 1; break;
	case 9:for (int i = 0; nine[i][0] != 0; i++) draw(nine[i][0] + x, nine[i][1] + y, color); on_off = 1; break;
	}
	//one;
	if (on_off == 1) {
		score = score % 10;
		on_off = 0;
	}
	count = score / 1;
	x = x + 7;
	switch (count) {
	case 0:for (int i = 0; zero[i][0] != 0; i++) draw(zero[i][0] + x, zero[i][1] + y, color); break;
	case 1:for (int i = 0; one[i][0] != 0; i++) draw(one[i][0] + x, one[i][1] + y, color); break;
	case 2:for (int i = 0; two[i][0] != 0; i++) draw(two[i][0] + x, two[i][1] + y, color); break;
	case 3:for (int i = 0; three[i][0] != 0; i++) draw(three[i][0] + x, three[i][1] + y, color); break;
	case 4:for (int i = 0; four[i][0] != 0; i++) draw(four[i][0] + x, four[i][1] + y, color); break;
	case 5:for (int i = 0; five[i][0] != 0; i++) draw(five[i][0] + x, five[i][1] + y, color); break;
	case 6:for (int i = 0; six[i][0] != 0; i++) draw(six[i][0] + x, six[i][1] + y, color); break;
	case 7:for (int i = 0; seven[i][0] != 0; i++) draw(seven[i][0] + x, seven[i][1] + y, color); break;
	case 8:for (int i = 0; eight[i][0] != 0; i++) draw(eight[i][0] + x, eight[i][1] + y, color); break;
	case 9:for (int i = 0; nine[i][0] != 0; i++) draw(nine[i][0] + x, nine[i][1] + y, color); break;
	}
	V(1);
	return 0;
}
//互斥操作；
void P(short i) {
	if (i == 0)
		WaitForSingleObject(mutex_temp, INFINITE);
	if (i == 1)
		WaitForSingleObject(mutex_draw, INFINITE);//绘制互斥；
	if (i == 2)
		WaitForSingleObject(mutex_esc, INFINITE);//esc键暂停游戏；
	if (i == 3)
		WaitForSingleObject(mutex_map, INFINITE);//读写map以及相关；
	if (i == 4)
		WaitForSingleObject(mutex_scoring, INFINITE);//计分互斥；
}
void V(short i) {
	if (i == 0)
		ReleaseMutex(mutex_temp);
	if (i == 1)
		ReleaseMutex(mutex_draw);
	if (i == 2)
		ReleaseMutex(mutex_esc);
	if (i == 3)
		ReleaseMutex(mutex_map);
	if (i == 4)
		ReleaseMutex(mutex_scoring);
}
//游戏结束；
void game_over() {
	//游戏结束地图；
	short gameover[][2] = {
	2,1,
	3,1,
	4,1,
	5,1,
	10,1,
	16,1,
	17,1,
	18,1,
	23,1,
	24,1,
	25,1,
	1,2,
	9,2,
	11,2,
	15,2,
	17,2,
	19,2,
	22,2,
	26,2,
	1,3,
	3,3,
	4,3,
	5,3,
	5,4,
	8,3,
	12,3,
	15,3,
	17,3,
	19,3,
	22,3,
	23,3,
	24,3,
	25,3,
	1,4,
	8,4,
	9,4,
	10,4,
	11,4,
	12,4,
	15,4,
	17,4,
	19,4,
	22,4,
	2,5,
	3,5,
	4,5,
	5,5,
	8,5,
	12,5,
	15,5,
	17,5,
	19,5,
	23,5,
	24,5,
	25,5,
	26,5,
	2,8,
	3,8,
	4,8,
	8,8,
	12,8,
	16,8,
	17,8,
	18,8,
	23,8,
	24,8,
	25,8,
	26,8,
	1,9,
	5,9,
	8,9,
	12,9,
	15,9,
	19,9,
	22,9,
	1,10,
	5,10,
	8,10,
	12,10,
	15,10,
	16,10,
	17,10,
	18,10,
	22,10,
	1,11,
	5,11,
	9,11,
	11,11,
	15,11,
	22,11,
	2,12,
	3,12,
	4,12,
	10,12,
	16,12,
	17,12,
	18,12,
	19,12,
	22,12,
	0,0, };
	short x = 10, y = 50;
	while (y > 10) {
		for (int i = 0; gameover[i][0] != 0; i++) {
			if (gameover[i][1] + y > 48)
				continue;
			if (state(gameover[i][0] + x, gameover[i][1] + y) == 0) {
					P(1);
					draw(gameover[i][0] + x, gameover[i][1] + y, 136);
					V(1);
			}

			if (gameover[i][1] + y + 1 > 48)
				continue;
			if (state(gameover[i][0] + x, gameover[i][1] + y + 1) == 0) {
					P(1);
					draw(gameover[i][0] + x, gameover[i][1] + y + 1, 119);
					V(1);
			}
		}
		y--;
		Sleep(10);
	}
	for (int i = 0; gameover[i][0] != 0; i++)
		draw(gameover[i][0] + 10, gameover[i][1] + 11, 136);

	message(" ESC退出	回车键继续", 115, 0, 1);
	key = -1;
	while (!((key != 13) ^ (key != 27)));
}