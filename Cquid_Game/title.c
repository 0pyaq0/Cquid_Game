/* title.c */

#include "title.h"
#include "modules.h"


// Ÿ��Ʋ ȭ�� ��
void main_title() {

	system("cls");

	setColor1(MINT);
	for (int i = 0; i < titleHei; i++) {
		gotoxy1(SCREEN_WIDTH / 2 - titleWid / 2, 4 + i);
		puts(rhythm_title[i]);
	}

	print_by_name("������");

	/*setColor1(yellow1);
	const wchar_t title[] = L"Developed by ������";
	gotoxy1((SCREEN_WIDTH - (int)wcslen(title)) / 2, 4 + titleHei + 1);
	wprintf(L"%s", title);*/

	setColor(white1);
	int x = 5;
	int y = 13;
	print_auto_y(&x, &y, "    ��_��");
	print_auto_y(&x, &y, "	���� �ˣߥ�");
	print_auto_y(&x, &y, "	  ��(������)    ��ĩ");
	print_auto_y(&x, &y, "	      > ��`");
	print_auto_y(&x, &y, "	      / �ء�");
	print_auto_y(&x, &y, "	     /��/����");
	print_auto_y(&x, &y, "	     /  �Ρ���_��");
	print_auto_y(&x, &y, "	    /  /");
	print_auto_y(&x, &y, "��ĩ     /��/|");
	print_auto_y(&x, &y, "	  (   (`");
	print_auto_y(&x, &y, "	  | |����");
	print_auto_y(&x, &y, "	  | | �� ��)");
	print_auto_y(&x, &y, "	  | |����) /");
	print_auto_y(&x, &y, "	 �� )����L/");
	print_auto_y(&x, &y, "      (___/     ��ĩ");

	setColor(RED);
	x = 28;
	y = 15;
	print_auto_y(&x, &y, " ����������������������������������������������������������������");
	print_auto_y(&x, &y, "|������ �߻�!������������������������������������ ��[��][Ϣ][��] |");
	print_auto_y(&x, &y, "|����������������������������������������������������������������|");
	print_auto_y(&x, &y, "|�����󿡼� ���� ����� ��������� �����ϼ̽��ϴ�! ������        |");
	print_auto_y(&x, &y, "|�������ΰ���?������������������������������������������������ ��|");
	print_auto_y(&x, &y, "|���������ߣߣߣߣߡ��������ߣߣߣߣߣߡ��������ߣߣߣߣߡ�����  |");
	print_auto_y(&x, &y, "| ��������������   |���������Ƹ���?������ �� ��|���� �� |��  ��  |");
	print_auto_y(&x, &y, "|��������������������������������������������������������������  |");
	print_auto_y(&x, &y, "����������������������������������������������������������������");
	
	setColor(YELLOW);
	x = 43;
	y = 25;
	print_auto_y(&x, &y, "[ �����Ϸ��� �ƹ� Ű�� �����ʽÿ� ]");


	setColor(WHITE);
	x = 100;
	y = 15;
	print_auto_y(&x, &y, " ��,,�� !!!!");
	print_auto_y(&x, &y, "( '��' )��");
	print_auto_y(&x, &y, "��m9  �� ");
	print_auto_y(&x, &y, "�� ���� �� ");
	print_auto_y(&x, &y, "�� ��) ) ��");
	print_auto_y(&x, &y, "��  ������ ��");
	print_auto_y(&x, &y, "�� (�ߣ� (��)");


	gotoxy1(SCREEN_WIDTH / 2, 4 + titleHei + 5);
	setCursor(UNDERBAR);
	clearBuffer();

	int _ = _getch();
}
