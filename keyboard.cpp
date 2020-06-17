#pragma once
#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<iostream>
#include"declaration.h"
//全局变量；
short key = -1, old_key = -1, new_key = -1, last_key = -1;
//监听键盘线程；
DWORD WINAPI keyboard(LPVOID lpParamter) {
	//printf("keyboard pass\n");

	while (1) {
		old_key=_getch();
		if (old_key == 224)//判断输入是否为上下左右键，如果是则相加缓冲区；得到上为296，下为304，左为299，右为301；
			old_key = old_key + _getch();
		key = old_key;
		last_key = new_key;//为了保存上一个key；
		
		new_key = _getch();
		if (new_key == 224)
			new_key = new_key + _getch();
		P();
		key = new_key;
		last_key = old_key;
		V();
	}
	return 0;
}