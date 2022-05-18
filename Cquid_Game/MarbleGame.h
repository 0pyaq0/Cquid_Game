#include <stdio.h>
#include <windows.h>
#include <time.h>

#ifndef KEY_CODE
#define KEY_CODE

/*�Լ� ����*/



void CursorView();
void gotoxy(int, int);
void setBackColor(int, int);
void gLoop(int);
void move(int*, int*, int, int, int*, int*);
int keyControl(int, int, int);
int menuDraw();
int maplistDraw();
void drawMap(int*, int*);
void drawUI(int*, int*, int*);
void drawTime(double, double);
int drawlevel();
void endDraw();
void failDraw();

//Ű���� ��
#define ESC 27
#define ENTER 13
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

#endif

#ifndef __COLOR_LIST_
#define __COLOR_LIST_

enum {
	black,
	blue,
	green,
	cyan,
	red,
	purple,
	brown,
	lightgray,
	darkgray,
	lightblue,
	lightgreen,
	lightcyan,
	lightred,
	lightpurple,
	yellow,
	white
};

#endif