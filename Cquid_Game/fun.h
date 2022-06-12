/* fun.h */
#pragma once

#include <Windows.h>
#include <conio.h>


// HIDE: Ŀ�� �����, UNDERBAR: _ Ŀ�� ���̱�, BLOCK: ��� Ŀ�� ���̱�
enum CURSOR_TYPE { HIDE, UNDERBAR, BLOCK };
// �ܼ� â ���� ����(setColor)�� �� ���� �����ڵ�
enum color {
	black1,
	DARK_BLUE,
	DARK_GREEN,
	DARK_SKYBLUE,
	DARK_RED,
	DARK_VIOLET,
	DARK_YELLOW,
	gray1,
	DARK_GRAY,
	blue1,
	green1,
	SKYBLUE,
	red1,
	VIOLET,
	yellow1,
	white1
};


void gotoxy1(int x, int y);
void movexy(int x, int y);
void setCursor(enum CURSOR_TYPE curType);
int curX();
int curY();
void clearBuffer();
void setColor1(enum color color);
