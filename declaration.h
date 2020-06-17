#pragma once
//计分类型；
constexpr auto t_s = 1;
constexpr auto t_l = 2;
constexpr auto p_s = 3;
constexpr auto p_b = 4;
constexpr auto p_l = 5;
//全局变量及函数；
extern short map[48][48];//游戏地图矩阵；
extern short key, last_key;//键盘输入信息；
void egg();
void P(short = 0);//上锁；
void V(short = 0);//解锁;
short state(short, short, short type = -1);
short draw(short x, short y, short f_color = 112, short c = 48);//绘制函数；
short message(const char* ch, short color = 122, short delayed = 0, bool clear = 0);//消息提示；
void tank_start();//坦克大战主函数；
void plane_start();//空军七号主函数；
short scoring(short type, short score);//计分函数；
void game_over();//游戏结束函数；

//链表结构体，用于存储不定长坐标；
typedef struct coordinates{
	short X;
	short Y;
	short extend;//墙体链表表示被击中的x坐标/子弹发射方向；
	coordinates* next;
}coordinates;