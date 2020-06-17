/*
团队：八阿哥团队
队员：郭秃子
*/
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<iostream>
//全局变量声明
#include"declaration.h"
//需要在属性加入/FORCE，避免多文件使用同一个头文件报错；
#include"keyboard.cpp"
#include"tool.cpp"
#include"start.cpp"
#include"tank.cpp"
#include"plane.cpp"
#include"egg.cpp"
//函数声明；
void window();
//程序入口；
int main() {
	window();
	mutex_temp = CreateMutex(NULL, FALSE, NULL);
	mutex_draw = CreateMutex(NULL, FALSE, NULL);//绘制锁初始化；
	mutex_esc = CreateMutex(NULL, FALSE, NULL);//esc锁初始化；
	mutex_map = CreateMutex(NULL, FALSE, NULL);//map锁初始化；
	mutex_scoring = CreateMutex(NULL, FALSE, NULL);//计分锁初始化；

	DWORD th_kb;
	CloseHandle(CreateThread(NULL, 0, keyboard, NULL, 0, &th_kb));//键盘线程，使之一直监听；

	start();

	Sleep(600000);
	return 0;
}
//窗口绘制；
void window() {
	system("cls");
	system("color 70");
	system("title 童年像素");

	HWND window = GetForegroundWindow();//获取当前窗口对象句柄；
	HANDLE window_io = GetStdHandle(STD_OUTPUT_HANDLE);//获取标准输出句柄；

//	LPCTSTR title = "童年像素";//定义标题，需设置项目属性字符集为‘未设置’；
//	SetWindowText(window, title);//设置标题；

	SetWindowPos(window, HWND_TOP, 0, 50, 0, 0, 0);//设置窗口位置及大小；
	system("mode con cols=180 lines=50");

//	CONSOLE_SCREEN_BUFFER_INFO info;//申明窗口信息类型；
//	GetConsoleScreenBufferInfo(window_io, &info);//获取窗口信息；
//	SMALL_RECT rect = info.srWindow;//声明缓冲区显示大小和位置；
//	COORD size = { rect.Right + 1, rect.Bottom + 1 };//定义缓冲区大小；
//	SetConsoleScreenBufferSize(window_io, size);//设置窗口缓冲区大小，实现无滚动条；
	
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };//定义光标信息；
	SetConsoleCursorInfo(window_io, &cursor_info);//设置光标信息；
}