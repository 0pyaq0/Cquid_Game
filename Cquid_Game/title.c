/* title.c */

#include "title.h"


// Ÿ��Ʋ ȭ�� ��
void main_title() {

	system("cls");

	setColor1(VIOLET);
	for (int i = 0; i < titleHei; i++) {
		gotoxy1(SCREEN_WIDTH / 2 - titleWid / 2, 4 + i);
		puts(beatc[i]);
	}

	setColor1(yellow1);
	const wchar_t title[] = L"Developed by ������";
	gotoxy1((SCREEN_WIDTH - (int)wcslen(title) * 2) / 2, 4 + titleHei + 1);
	wprintf(L"%s", title);

	setColor1(gray1);
	const char anykey[] = "�����Ϸ��� �ƹ� Ű�� ��������";
	gotoxy1(SCREEN_WIDTH / 2 - (int)strlen(anykey) / 2, 4 + titleHei + 4);
	puts(anykey);

	gotoxy1(SCREEN_WIDTH / 2, 4 + titleHei + 5);
	setCursor(UNDERBAR);
	clearBuffer();

	int _ = _getch();
}
