#pragma once
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include"declaration.h"

constexpr auto up = 296;
constexpr auto down = 304;
constexpr auto left = 299;
constexpr auto right = 301;

bool game_logic();
void ai();
void reset_foe(short);

clock_t foe_create_start, foe_create_over, foe_move_start, foe_move_over;
short t_score = 0, t_life = 3;
bool die[5] = {};
bool gameover = 0;
short t_window[][3] = {
1,1,153,
2,1,153,
3,1,153,
4,1,153,
5,1,153,
6,1,153,
7,1,153,
8,1,153,
9,1,153,
10,1,153,
11,1,153,
12,1,153,
13,1,153,
14,1,153,
15,1,153,
16,1,153,
17,1,153,
18,1,153,
19,1,153,
20,1,153,
21,1,153,
22,1,153,
23,1,153,
24,1,153,
25,1,153,
26,1,153,
27,1,153,
28,1,153,
29,1,153,
30,1,153,
31,1,153,
32,1,153,
33,1,153,
34,1,153,
35,1,153,
36,1,153,
37,1,153,
38,1,153,
39,1,153,
40,1,153,
41,1,153,
42,1,153,
43,1,153,
44,1,153,
45,1,153,
46,1,153,
47,1,153,
48,1,153,
49,1,153,
50,1,17,
51,1,17,
52,1,17,
53,1,17,
54,1,17,
55,1,17,
56,1,17,
57,1,17,
58,1,17,
59,1,17,
60,1,17,
61,1,17,
62,1,17,
63,1,17,
64,1,17,
65,1,17,
66,1,17,
67,1,17,
68,1,17,
69,1,17,
70,1,17,
71,1,17,
72,1,17,
73,1,17,
74,1,17,
75,1,17,
76,1,17,
77,1,17,
78,1,17,
79,1,17,
80,1,17,
81,1,17,
82,1,17,
83,1,17,
84,1,17,
85,1,17,
86,1,17,
87,1,17,
88,1,17,
89,1,17,
90,1,17,
1,2,153,
50,2,153,
90,2,17,
1,3,153,
50,3,153,
90,3,17,
1,4,153,
50,4,153,
90,4,17,
1,5,153,
50,5,153,
90,5,17,
1,6,153,
50,6,153,
90,6,17,
1,7,153,
50,7,153,
90,7,17,
1,8,153,
50,8,153,
55,8,255,
56,8,51,
57,8,51,
58,8,51,
59,8,51,
60,8,51,
61,8,51,
69,8,238,
70,8,238,
71,8,238,
72,8,238,
73,8,238,
76,8,238,
77,8,238,
78,8,238,
79,8,238,
80,8,238,
83,8,238,
84,8,238,
85,8,238,
86,8,238,
87,8,238,
90,8,17,
1,9,153,
50,9,153,
55,9,51,
56,9,255,
57,9,255,
58,9,255,
59,9,255,
60,9,255,
61,9,51,
69,9,238,
73,9,238,
76,9,238,
80,9,238,
83,9,238,
87,9,238,
90,9,17,
1,10,153,
50,10,153,
55,10,51,
56,10,255,
57,10,51,
58,10,51,
59,10,255,
60,10,255,
61,10,51,
65,10,136,
66,10,136,
69,10,238,
73,10,238,
76,10,238,
80,10,238,
83,10,238,
87,10,238,
90,10,17,
1,11,153,
50,11,153,
55,11,51,
56,11,255,
57,11,255,
58,11,255,
59,11,255,
60,11,255,
61,11,51,
65,11,136,
66,11,136,
69,11,238,
73,11,238,
76,11,238,
80,11,238,
83,11,238,
87,11,238,
90,11,17,
1,12,153,
50,12,153,
55,12,51,
56,12,255,
57,12,51,
58,12,255,
59,12,51,
60,12,255,
61,12,51,
69,12,238,
70,12,238,
71,12,238,
72,12,238,
73,12,238,
76,12,238,
77,12,238,
78,12,238,
79,12,238,
80,12,238,
83,12,238,
84,12,238,
85,12,238,
86,12,238,
87,12,238,
90,12,17,
1,13,153,
50,13,153,
55,13,51,
56,13,255,
57,13,255,
58,13,255,
59,13,255,
60,13,255,
61,13,51,
69,13,238,
73,13,238,
76,13,238,
80,13,238,
83,13,238,
87,13,238,
90,13,17,
1,14,153,
50,14,153,
55,14,51,
56,14,255,
57,14,51,
58,14,51,
59,14,51,
60,14,255,
61,14,51,
69,14,238,
73,14,238,
76,14,238,
80,14,238,
83,14,238,
87,14,238,
90,14,17,
1,15,153,
50,15,153,
55,15,51,
56,15,255,
57,15,255,
58,15,255,
59,15,255,
60,15,255,
61,15,51,
65,15,136,
66,15,136,
69,15,238,
73,15,238,
76,15,238,
80,15,238,
83,15,238,
87,15,238,
90,15,17,
1,16,153,
50,16,153,
55,16,51,
56,16,255,
57,16,255,
58,16,255,
59,16,255,
60,16,255,
61,16,51,
65,16,136,
66,16,136,
69,16,238,
73,16,238,
76,16,238,
80,16,238,
83,16,238,
87,16,238,
90,16,17,
1,17,153,
50,17,153,
55,17,51,
56,17,51,
57,17,51,
58,17,51,
59,17,51,
60,17,51,
61,17,51,
69,17,238,
70,17,238,
71,17,238,
72,17,238,
73,17,238,
76,17,238,
77,17,238,
78,17,238,
79,17,238,
80,17,238,
83,17,238,
84,17,238,
85,17,238,
86,17,238,
87,17,238,
90,17,17,
1,18,153,
50,18,153,
90,18,17,
1,19,153,
50,19,153,
90,19,17,
1,20,153,
50,20,153,
90,20,17,
1,21,153,
50,21,153,
90,21,17,
1,22,153,
50,22,153,
90,22,17,
1,23,153,
50,23,153,
90,23,17,
1,24,153,
50,24,153,
90,24,17,
1,25,153,
50,25,153,
90,25,17,
1,26,153,
50,26,153,
90,26,17,
1,27,153,
50,27,153,
54,27,204,
55,27,204,
60,27,204,
61,27,204,
69,27,238,
70,27,238,
71,27,238,
72,27,238,
73,27,238,
76,27,238,
77,27,238,
78,27,238,
79,27,238,
80,27,238,
83,27,238,
84,27,238,
85,27,238,
86,27,238,
87,27,238,
90,27,17,
1,28,153,
50,28,153,
53,28,204,
54,28,204,
55,28,204,
56,28,204,
59,28,204,
60,28,204,
61,28,204,
62,28,204,
69,28,238,
73,28,238,
76,28,238,
80,28,238,
83,28,238,
87,28,238,
90,28,17,
1,29,153,
50,29,153,
53,29,204,
54,29,204,
55,29,204,
56,29,204,
57,29,204,
58,29,204,
59,29,204,
60,29,204,
61,29,204,
62,29,204,
65,29,136,
66,29,136,
69,29,238,
73,29,238,
76,29,238,
80,29,238,
83,29,238,
87,29,238,
90,29,17,
1,30,153,
50,30,153,
53,30,204,
54,30,255,
55,30,255,
56,30,204,
57,30,204,
58,30,204,
59,30,204,
60,30,204,
61,30,204,
62,30,204,
65,30,136,
66,30,136,
69,30,238,
73,30,238,
76,30,238,
80,30,238,
83,30,238,
87,30,238,
90,30,17,
1,31,153,
50,31,153,
53,31,204,
54,31,204,
55,31,255,
56,31,204,
57,31,204,
58,31,204,
59,31,204,
60,31,204,
61,31,204,
62,31,204,
69,31,238,
70,31,238,
71,31,238,
72,31,238,
73,31,238,
76,31,238,
77,31,238,
78,31,238,
79,31,238,
80,31,238,
83,31,238,
84,31,238,
85,31,238,
86,31,238,
87,31,238,
90,31,17,
1,32,153,
50,32,153,
53,32,204,
54,32,204,
55,32,204,
56,32,204,
57,32,204,
58,32,204,
59,32,204,
60,32,204,
61,32,204,
62,32,204,
69,32,238,
73,32,238,
76,32,238,
80,32,238,
83,32,238,
87,32,238,
90,32,17,
1,33,153,
50,33,153,
54,33,204,
55,33,204,
56,33,204,
57,33,204,
58,33,204,
59,33,204,
60,33,204,
61,33,204,
69,33,238,
73,33,238,
76,33,238,
80,33,238,
83,33,238,
87,33,238,
90,33,17,
1,34,153,
50,34,153,
55,34,204,
56,34,204,
57,34,204,
58,34,204,
59,34,204,
60,34,204,
65,34,136,
66,34,136,
69,34,238,
73,34,238,
76,34,238,
80,34,238,
83,34,238,
87,34,238,
90,34,17,
1,35,153,
50,35,153,
56,35,204,
57,35,204,
58,35,204,
59,35,204,
65,35,136,
66,35,136,
69,35,238,
73,35,238,
76,35,238,
80,35,238,
83,35,238,
87,35,238,
90,35,17,
1,36,153,
50,36,153,
57,36,204,
58,36,204,
69,36,238,
70,36,238,
71,36,238,
72,36,238,
73,36,238,
76,36,238,
77,36,238,
78,36,238,
79,36,238,
80,36,238,
83,36,238,
84,36,238,
85,36,238,
86,36,238,
87,36,238,
90,36,17,
1,37,153,
50,37,153,
90,37,17,
1,38,153,
50,38,153,
90,38,17,
1,39,153,
50,39,153,
90,39,17,
1,40,153,
50,40,153,
90,40,17,
1,41,153,
50,41,153,
90,41,17,
1,42,153,
50,42,153,
90,42,17,
1,43,153,
50,43,153,
52,43,170,
53,43,170,
54,43,170,
55,43,170,
56,43,170,
57,43,170,
58,43,170,
59,43,170,
60,43,170,
61,43,170,
61,43,170,
62,43,170,
63,43,170,
64,43,170,
65,43,170,
66,43,170,
67,43,170,
68,43,170,
69,43,170,
70,43,170,
71,43,170,
72,43,170,
73,43,170,
74,43,170,
75,43,170,
76,43,170,
77,43,170,
78,43,170,
79,43,170,
80,43,170,
81,43,170,
82,43,170,
83,43,170,
84,43,170,
85,43,170,
86,43,170,
87,43,170,
88,43,170,
90,43,17,
1,44,153,
50,44,153,
52,44,170,
88,44,170,
90,44,17,
1,45,153,
50,45,153,
52,45,170,
88,45,170,
90,45,17,
1,46,153,
50,46,153,
52,46,170,
88,46,170,
90,46,17,
1,47,153,
50,47,153,
52,47,170,
88,47,170,
90,47,17,
1,48,153,
50,48,153,
52,48,170,
53,48,170,
54,48,170,
55,48,170,
56,48,170,
57,48,170,
58,48,170,
59,48,170,
60,48,170,
61,48,170,
61,48,170,
62,48,170,
63,48,170,
64,48,170,
65,48,170,
66,48,170,
67,48,170,
68,48,170,
69,48,170,
70,48,170,
71,48,170,
72,48,170,
73,48,170,
74,48,170,
75,48,170,
76,48,170,
77,48,170,
78,48,170,
79,48,170,
80,48,170,
81,48,170,
82,48,170,
83,48,170,
84,48,170,
85,48,170,
86,48,170,
87,48,170,
88,48,170,
90,48,17,
1,49,153,
50,49,153,
90,49,17,
1,50,153,
2,50,153,
3,50,153,
4,50,153,
5,50,153,
6,50,153,
7,50,153,
8,50,153,
9,50,153,
10,50,153,
11,50,153,
12,50,153,
13,50,153,
14,50,153,
15,50,153,
16,50,153,
17,50,153,
18,50,153,
19,50,153,
20,50,153,
21,50,153,
22,50,153,
23,50,153,
24,50,153,
25,50,153,
26,50,153,
27,50,153,
28,50,153,
29,50,153,
30,50,153,
31,50,153,
32,50,153,
33,50,153,
34,50,153,
35,50,153,
36,50,153,
37,50,153,
38,50,153,
39,50,153,
40,50,153,
41,50,153,
42,50,153,
43,50,153,
44,50,153,
45,50,153,
46,50,153,
47,50,153,
48,50,153,
49,50,153,
50,50,17,
51,50,17,
52,50,17,
53,50,17,
54,50,17,
55,50,17,
56,50,17,
57,50,17,
58,50,17,
59,50,17,
60,50,17,
61,50,17,
62,50,17,
63,50,17,
64,50,17,
65,50,17,
66,50,17,
67,50,17,
68,50,17,
69,50,17,
70,50,17,
71,50,17,
72,50,17,
73,50,17,
74,50,17,
75,50,17,
76,50,17,
77,50,17,
78,50,17,
79,50,17,
80,50,17,
81,50,17,
82,50,17,
83,50,17,
84,50,17,
85,50,17,
86,50,17,
87,50,17,
88,50,17,
89,50,17,
90,50,17,
0,0,0,
};
short tank_xy[][3] = {
	3,1,17,
	2,2,17,
	3,2,187,
	4,2,17,
	1,3,17,
	2,3,187,
	3,3,187,
	4,3,187,
	5,3,17,
	1,4,17,
	2,4,187,
	3,4,17,
	4,4,187,
	5,4,17,
	1,5,17,
	2,5,17,
	4,5,17,
	5,5,17,
	1,1,119,
	2,1,119,
	4,1,119,
	5,1,119,
	1,2,119,
	5,2,119,
	3,5,119,
	0,0,0,
};
short tank_temp[][3] = {
	3,1,17,
	2,2,17,
	3,2,187,
	4,2,17,
	1,3,17,
	2,3,187,
	3,3,187,
	4,3,187,
	5,3,17,
	1,4,17,
	2,4,187,
	3,4,17,
	4,4,187,
	5,4,17,
	1,5,17,
	2,5,17,
	4,5,17,
	5,5,17,
	0,0,0,
};;

//坦克类；
class tank {
private:
	unsigned short m_x, m_y;//初始位置；
	clock_t
		start_bullet, over_bullet,
		start_fire, over_fire,
		start_body, over_body;

	short draw_tank(short x, short y);//绘制坦克；
	void change_matrix(short orientation);//改变坐标；
public:
	bool error;
	short machine;//人机标记，-11己方，-1敌坦克，-2敌坦克，-3敌坦克，-4敌坦克，-5敌坦克；
	unsigned short orientation;//坦克当前方向；
	coordinates fire_head, * fire_end;//子弹链表；

	void fake_tank(short x, short y);
	void initial(short, short);
	short move(short orientation);//移动坦克；
	short fire(short bullet);//炮弹；
	short bullet_move();//子弹移动；
	short x();
	short y();
};
//伪构造函数；
void tank::fake_tank(short x = 23, short y = 23) {
	//炮弹链表初始化；
	reset_foe(machine);
	fire_head.X = -1;
	fire_head.Y = -1;
	fire_head.extend = -1;
	fire_head.next = NULL;
	fire_end = &fire_head;
	//方向初始化；
	//初始化坦克坐标；
	m_x = x;
	m_y = y;
	orientation = NULL;
	//
	start_bullet = clock();
	start_fire = clock();
	start_body = clock();
}
//初始坐标；
void tank::initial(short x, short y) {
	m_x = x;
	m_y = y;
}
//移动坦克；
short tank::move(short orientation) {
	if (orientation == up) {
		if (machine == -11)
			message("上");
		if (this->orientation == orientation) {
			m_y--;
		}
		change_matrix(orientation);
		if (draw_tank(m_x, m_y) == 1) 
			m_y++;

		this->orientation = up;
	}
	if (orientation == down) {
		if (machine == -11)
			message("下");
		if (this->orientation == orientation) {
			m_y++;
		}
		change_matrix(orientation);
		if (draw_tank(m_x, m_y) == 1)
			m_y--;

		this->orientation = down;
	}
	if (orientation == left) {
		if (machine == -11)
			message("左");
		if (this->orientation == orientation) {
			m_x--;
		}
		change_matrix(orientation);
		if (draw_tank(m_x, m_y) == 1)
			m_x++;

		this->orientation = left;
	}
	if (orientation == right) {
		if (machine == -11)
			message("右");
		if (this->orientation == orientation) {
			m_x++;
		}
		change_matrix(orientation);
		if (draw_tank(m_x, m_y) == 1)
			m_x--;

		this->orientation = right;
	}
	key = -1;
	return 0;
}
//坐标旋转算法；
void tank::change_matrix(short orientation) {
	if (orientation == up) {
		for (short i = 0; tank_xy[i][0] != 0; i++) {
			tank_temp[i][0] = tank_xy[i][0];//x <= X;
			tank_temp[i][1] = tank_xy[i][1];//y <= Y;
			tank_temp[i][2] = tank_xy[i][2];//color;
			tank_temp[i + 1][0] = 0;//结束标志；
		}
	}
	if (orientation == down) {
		for (short i = 0; tank_xy[i][0] != 0; i++) {
			tank_temp[i][0] = 6 - tank_xy[i][0];//x <= 6-X;
			tank_temp[i][1] = 6 - tank_xy[i][1];//y <= 6-Y;
			tank_temp[i][2] = tank_xy[i][2];//color;
			tank_temp[i + 1][0] = 0;
		}
	}
	if (orientation == left) {
		for (short i = 0; tank_xy[i][0] != 0; i++) {
			tank_temp[i][0] = tank_xy[i][1];//x <= Y;
			tank_temp[i][1] = 6 - tank_xy[i][0];//y <= 6-X;
			tank_temp[i][2] = tank_xy[i][2];//color;
			tank_temp[i + 1][0] = 0;
		}
	}
	if (orientation == right) {
		for (short i = 0; tank_xy[i][0] != 0; i++) {
			tank_temp[i][0] = 6 - tank_xy[i][1];//x <= 6-Y;
			tank_temp[i][1] = tank_xy[i][0];//y <= X;
			tank_temp[i][2] = tank_xy[i][2];//color;
			tank_temp[i + 1][0] = 0;
		}
	}
}
//绘制坦克函数；
short tank::draw_tank(short x, short y) {
	x -= 1;
	y -= 1;
	//障碍检测；
	if (x < 0 || x > 43 || y < 0 || y > 43) {
		error = 1;
		return 1;
	}
	for (short i = 0; tank_temp[i][0]; i++) {
		if (state(tank_temp[i][0] + x, tank_temp[i][1] + y) == 1) {
			error = 1;
			return 1;
		}
		if (state(tank_temp[i][0] + x, tank_temp[i][1] + y) != machine && state(tank_temp[i][0] + x, tank_temp[i][1] + y) != 0) {
			error = 1;
			return 1;
		}
	}
	

	for (int j = 0; j < 7; j++)
		for (int i = 0; i < 7; i++)
			if (state(x + i, y + j) == machine){
				draw(x + i, y + j, 119);
				state(x + i, y + j, 0);
			}

	for (short i = 0; tank_temp[i][0]; i++) {
		if (machine == -11)
			draw(tank_temp[i][0] + x, tank_temp[i][1] + y, tank_temp[i][2]);
		else {
			if (tank_temp[i][2] == 17)
				draw(tank_temp[i][0] + x, tank_temp[i][1] + y, 85);
			else
				draw(tank_temp[i][0] + x, tank_temp[i][1] + y, tank_temp[i][2]);
		}
		state(tank_temp[i][0] + x, tank_temp[i][1] + y, machine);
	}
	error = 0;
}
//发射炮弹；
short tank::fire(short bullet) {
	if (bullet != 32)
		return 0;
	over_fire = clock();
	if ((ULONG)(over_fire - start_fire) < 1000) {
		if (machine == -11)
			message("冷却中！", 125);
		return 0;
	}
	if (machine == 1)
		message("发射炮弹！");
	coordinates* node = NULL;
	node = (coordinates*)malloc(sizeof(coordinates));

	switch (orientation) {
	case up:
		node->X = (USHORT)(m_x + 2);
		node->Y = (USHORT)(m_y - 2);
		node->extend = up;
		break;
	case down:
		node->X = (USHORT)(m_x + 2);
		node->Y = (USHORT)(m_y + 6);
		node->extend = down;
		break;
	case left:
		node->X = (USHORT)(m_x - 2);
		node->Y = (USHORT)(m_y + 2);
		node->extend = left;
		break;
	case right:
		node->X = (USHORT)(m_x + 6);
		node->Y = (USHORT)(m_y + 2);
		node->extend = right;
		break;
	}

	node->next = NULL;
	fire_end->next = node;
	fire_end = node;

	start_fire = clock();
	key = -1;
	return 0;
}
//炮弹移动；
short tank::bullet_move() {
	over_bullet = clock();//炮弹延时终止；
	bool clear_sign = 0;
	if ((ULONG)(over_bullet - start_bullet) < 100)//如果延时小于100则不执行移动；
		return 1;

	coordinates* temp = NULL, *clear = NULL;//移动炮弹链表节点；
	temp = &fire_head;
	while (temp->next != NULL) {//遍历所有节点；
		//如果炮弹触碰到墙，或者出界则删除此节点，并消除滞留点；
		if (state(temp->next->X, temp->next->Y) == 1 ||temp->next->X < 1 || temp->next->X > 48 || temp->next->Y < 1 || temp->next->Y > 48) {

			switch (temp->next->extend) {//子弹移动方向；
			case up:
				if (state(temp->next->X, 1) != machine)
					draw(temp->next->X, (temp->next->Y + 1 == 0) ? 1 : (temp->next->Y + 1), 119);
				break;
				/*
				如果 第一行某列不等于坦克位置 则
					如果 节点越界 则
						清第一行某列
					否则 
						清当前行加一某列
				*/
			case down:
				if (state(temp->next->X, 48) != machine)
					draw(temp->next->X, (temp->next->Y - 1 == 49) ? 48 : (temp->next->Y - 1), 119);
				break;
			case left:
				if (state(1, temp->next->Y) != machine)
					draw((temp->next->X + 1 == 0) ? 1 : (temp->next->X + 1), temp->next->Y, 119);
				break;
			case right:
				if (state(48, temp->next->Y) != machine)
					draw((temp->next->X - 1 == 49) ? 48 : (temp->next->X - 1), temp->next->Y, 119);
				break;
			}
			//删除失效炮弹节点；
			clear = temp->next;
			temp->next = temp->next->next;
			if (temp->next == NULL)
				fire_end = temp;
			free(clear);
			continue;
		}
		//如果地图为空，则绘制；
		if (state(temp->next->X, temp->next->Y) == 0) {
			//依据己方敌方绘制不同颜色炮弹；
			if (machine == -11)
				draw(temp->next->X, temp->next->Y, 34);
			else
				draw(temp->next->X, temp->next->Y, 17);
		}
		
		if (machine == -11) {//如果是己方炮弹，触碰到敌方，会击毁敌方坦克；
			if (state(temp->next->X, temp->next->Y) == -2) {
				clear_sign = 1;
				die[0] = 0;
				reset_foe(-2);
			}
			if (state(temp->next->X, temp->next->Y) == -3) {
				clear_sign = 1;
				die[1] = 0;
				reset_foe(-3);
			}
			if (state(temp->next->X, temp->next->Y) == -4) {
				clear_sign = 1;
				die[2] = 0;
				reset_foe(-4);
			}
			if (state(temp->next->X, temp->next->Y) == -5) {
				clear_sign = 1;
				die[3] = 0;
				reset_foe(-5);
			}
			if (state(temp->next->X, temp->next->Y) == -6) {
				clear_sign = 1;
				die[4] = 0;
				reset_foe(-6);
			}
			//依据方向判断如何处理链表并消除上一个炮弹；
			switch (temp->next->extend) {
			case up:
				if (state(temp->next->X, temp->next->Y + 1) == 0)
					draw(temp->next->X, temp->next->Y + 1, 119);
				temp->next->Y--;
				break;
			case down:
				if (state(temp->next->X, temp->next->Y - 1) == 0)
					draw(temp->next->X, temp->next->Y - 1, 119);
				temp->next->Y++;
				break;
			case left:
				if (state(temp->next->X + 1, temp->next->Y) == 0)
					draw(temp->next->X + 1, temp->next->Y, 119);
				temp->next->X--;
				break;
			case right:
				if (state(temp->next->X - 1, temp->next->Y) == 0)
					draw(temp->next->X - 1, temp->next->Y, 119);
				temp->next->X++;
				break;
			}

			if (clear_sign == 1) {
				t_score++;
				scoring(t_s, t_score);
				if (t_score % 10 == 0) {
					t_life++;
					scoring(t_l, t_life);
				}

				clear = temp->next;
				temp->next = temp->next->next;
				if (temp->next == NULL)
					fire_end = temp;
				free(clear);
				clear_sign = 0;
				continue;
			}
		}
		else {//敌方坦克炮弹触碰到己方会损失生命；
			if (state(temp->next->X, temp->next->Y) == -11) {
				over_body = clock();
				if ((ULONG)(over_body - start_body) > 3000) {
					clear_sign = 1;
					message("受到攻击，请躲避！", 116, 3);
					start_body = clock();
				}
			}
			//依据方向判断如何处理链表并消除上一个炮弹；
			switch (temp->next->extend) {
			case up:
				if (state(temp->next->X, temp->next->Y + 1) == 0)
					draw(temp->next->X, temp->next->Y + 1, 119);
				temp->next->Y--;
				break;
			case down:
				if (state(temp->next->X, temp->next->Y - 1) == 0)
					draw(temp->next->X, temp->next->Y - 1, 119);
				temp->next->Y++;
				break;
			case left:
				if (state(temp->next->X + 1, temp->next->Y) == 0)
					draw(temp->next->X + 1, temp->next->Y, 119);
				temp->next->X--;
				break;
			case right:
				if (state(temp->next->X - 1, temp->next->Y) == 0)
					draw(temp->next->X - 1, temp->next->Y, 119);
				temp->next->X++;
				break;
			}

			if (clear_sign == 1) {
				clear = temp->next;
				temp->next = temp->next->next;
				if (temp->next == NULL)
					fire_end = temp;
				free(clear);
				t_life--;
				scoring(t_l, t_life);
				if (t_life <= 0)
					gameover = 0;
				clear_sign = 0;
				continue;
			}
		}
		temp = temp->next;
	}
	start_bullet = clock();//炮弹移动计时开始；
}
short tank::x() {
	return m_x;
}
short tank::y() {
	return m_y;
}
//创建对象；
tank oneself, foe[5];

//坦克大战模块主函数；
void tank_start() {
	system("cls");
	system("color 70");

	while (key != 27) {
		//变量重置；
		gameover = 1;
		t_life = 3;
		t_score = 0;
		for (short i = 0; i < 5; i++)
			die[i] = 0;
		oneself.machine = -11;
		foe[0].machine = -2;
		foe[1].machine = -3;
		foe[2].machine = -4;
		foe[3].machine = -5;
		foe[4].machine = -6;
		oneself.fake_tank();
		foe[0].fake_tank();
		foe[1].fake_tank();
		foe[2].fake_tank();
		foe[3].fake_tank();
		foe[4].fake_tank();
		//置空地图；
		for (int i = 0; i < 48; i++)
			for (int j = 0; j < 48; j++) {
				map[i][j] = 0;
				draw(i + 1, j + 1, 119);
			}
		key = -1;
		short t_map[][2] = {
10,10,
11,10,
12,10,
13,10,
14,10,
15,10,
16,10,
17,10,
18,10,
19,10,
20,10,
21,10,
22,10,
23,10,
24,10,
25,10,
26,10,
27,10,
28,10,
29,10,
30,10,
31,10,
32,10,
33,10,
34,10,
35,10,
36,10,
37,10,
38,10,
39,10,
40,10,
10,20,
10,21,
10,22,
10,23,
10,24,
10,25,
10,26,
10,27,
10,28,
10,29,
10,30,
20,20,
20,21,
20,22,
20,23,
20,24,
20,25,
20,26,
20,27,
20,28,
20,29,
20,30,
30,20,
30,21,
30,22,
30,23,
30,24,
30,25,
30,26,
30,27,
30,28,
30,29,
30,30,
40,20,
40,21,
40,22,
40,23,
40,24,
40,25,
40,26,
40,27,
40,28,
40,29,
40,30,
10,40,
11,40,
12,40,
13,40,
14,40,
15,40,
16,40,
17,40,
18,40,
19,40,
20,40,
21,40,
22,40,
23,40,
24,40,
25,40,
26,40,
27,40,
28,40,
29,40,
30,40,
31,40,
32,40,
33,40,
34,40,
35,40,
36,40,
37,40,
38,40,
39,40,
40,40,
0,0,
		};
		//界面绘制；
		for (int i = 0; t_window[i][0] != 0; i++)
			draw(t_window[i][0] - 1, t_window[i][1] - 1, t_window[i][2]);
		//地图绘制；
		for (int i = 0; t_map[i][0] != 0; i++) {
			draw(t_map[i][0], t_map[i][1], 79);
			state(t_map[i][0], t_map[i][1], 1);
		}
		scoring(t_l, t_life);
		scoring(t_s, t_score);
		game_logic();
		game_over();
	}
	system("cls");
}
//游戏逻辑；
bool game_logic() {
	key = -1;
	foe_create_start = clock();
	foe_move_start = clock();

	message("上下左右控制；空格发射炮弹！", 115, 3);
	oneself.move(up);
 	while (1) {
		//while (key != 296 && key != 304 && key != 299 && key != 301 && key != 32);
		P();
		oneself.fire(key);
		oneself.move(key);
		oneself.bullet_move();
		if (gameover == 0) {
			V();
			return 0;
		}
		V();
		ai();
	}
}
//AI;
void ai() {
	foe_move_over = clock();
	foe_create_over = clock();

	if ((ULONG)(foe_create_over - foe_create_start) > 5000) {
		for (short n = 0; n < 5; n++) {
			if (die[n] == 0) {
				die[n] = 1;
				while (1) {
					foe[n].initial(rand() % 48 + 1, rand() % 48 + 1);
					foe[n].move(up);
					if (foe[n].error != 1)
						break;
				}
				break;
			}
		}
		foe_create_start = clock();
	}

	for (int i = 0; i < 5; i++) {
		if (die[i] == 1) {
			//move;
			if ((ULONG)(foe_move_over - foe_move_start) > 200) {
				srand(rand());
				if (rand() % 4 > 0) {
					foe[i].move(foe[i].orientation);
				}
				else {
					srand(rand());
					switch (rand() % 4) {
					case 0:
						foe[i].move(up);
						break;
					case 1:
						foe[i].move(down);
						break;
					case 2:
						foe[i].move(left);
						break;
					case 3:
						foe[i].move(right);
						break;
					}
				}
				foe_move_start = clock();
			}
			//fire;
			srand(rand());
			if (rand() % 2 == 1)
				foe[i].fire(32);
			foe[i].bullet_move();
		}
	}
}
//reset_foe
void reset_foe(short number) {
	short sign = number;
	switch (number) {
	case -2:
		number = 0;
		break;
	case -3:
		number = 1;
		break;
	case -4:
		number = 2;
		break;
	case -5:
		number = 3;
		break;
	case -6:
		number = 4;
		break;
	}
	//
	coordinates* temp = &foe[number].fire_head;
	while (temp->next != NULL){
		switch (temp->next->extend) {
		case up:
			draw(temp->next->X, temp->next->Y + 1, 119);
			break;
		case down:
			draw(temp->next->X, temp->next->Y - 1, 119);
			break;
		case left:
			draw(temp->next->X + 1, temp->next->Y, 119);
			break;
		case right:
			draw(temp->next->X - 1, temp->next->Y, 119);
			break;
		}
		
		if (temp->next->next != NULL) {
			coordinates* clear = NULL;
			clear = temp->next;
			temp->next = temp->next->next;
			free(clear);
		}
		else {
			free(temp->next);
			temp->next = NULL;
			foe[number].fire_end = &foe[number].fire_head;
		}
	}
	//清残骸；
	for (short i = 0; i < 5; i++)
		for (short j = 0; j < 5; j++)
			if (state(foe[number].x() + i, foe[number].y() + j) == sign) {
				draw(foe[number].x() + i, foe[number].y() + j, 119);
				state(foe[number].x() + i, foe[number].y() + j, 0);
			}
}