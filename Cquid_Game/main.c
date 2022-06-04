#include "modules.h"
#include "MarbleGame.h"
#include "Jingumdari.h"
#include "pushpull.h"
#include"dalgona.h"
#include "Mugunghwa.h"



//���� �׸���
void drawSolider(int x) {
	setColor(RED);
	gotoxy(x, 3); printf("       �����");
	gotoxy(x, 4); printf("     ��        ��");
	gotoxy(x, 5); printf("   ��            ��");
	gotoxy(x, 6); printf("  ��              ��");
	gotoxy(x, 7); printf("  ��              ��");
	gotoxy(x, 8); printf("  ��              ��");
	gotoxy(x, 9); printf("  ��              ��");
	gotoxy(x, 10); printf("    ��          ��");
	gotoxy(x, 11); printf("      ��      ��");
	gotoxy(x, 12); printf("        ����");
	gotoxy(x, 13); printf("      ������");
	gotoxy(x, 14); printf("   ���������");
	gotoxy(x, 15); printf("  ����������");
}

//Ÿ��Ʋ ���
void title() {
	drawSolider(15);

	setColor(yellow);
	int x = 42;
	gotoxy(x, 4); printf(" _____ ____  __    __ _____ _____   ");
	gotoxy(x, 5); printf("/ ____/ __ ��| |  | ||_   _|  __ �� ");
	gotoxy(x, 6); printf("| |   | |  | | |  | |  | | | |  | |");
	gotoxy(x, 7); printf("| |   | |  | | |  | |  | | | |  | | ");
	gotoxy(x, 8); printf("| |___| |__| | |__| | _| |_| |__| | ");
	gotoxy(x, 9); printf("��____��___����____/ |_____|_____/  ");

	gotoxy(x, 10); printf("   _____          __    __ ______ ");
	gotoxy(x, 11); printf("  / ____|   /��   |  ��/  |  ____|");
	gotoxy(x, 12); printf(" | |  __   /  ��  | ��  / | |__ ");
	gotoxy(x, 13); printf(" | | |_ | / /���� | |��/| |  __|");
	gotoxy(x, 14); printf(" | |__| |/ ____ ��| |   | | |____ ");
	gotoxy(x, 15); printf("  ��____/_/   ��_��_|   |_|______|");

	drawSolider(80);

	setColor(WHITE);
	gotoxy(86, 5); printf("������");
	gotoxy(86, 6); printf("��      ��");
	gotoxy(86, 7); printf("��      ��");
	gotoxy(86, 8); printf("������");

	setColor(WHITE);
	gotoxy(21, 5); printf("  �ܡܡ�");
	gotoxy(21, 6); printf("��      ��");
	gotoxy(21, 7); printf("��      ��");
	gotoxy(21, 8); printf("  �ܡܡ�");




}

//���� ��Ŀ��
void focus() {


	setColor(WHITE);
	gotoxy(30, 25); printf("�� ����ȭ ��\n");
	gotoxy(54, 25);  printf("�� �ް��̱�");
	gotoxy(78, 25);  printf("�� �ٴٸ���");

	gotoxy(30, 29);  printf("�� ����ġ��");
	gotoxy(54, 29);  printf("�� ¡�˴ٸ�");
	gotoxy(78, 29);  printf("�� �������");
}



int main() {

	PlaySound(TEXT("./sound/mainback.wav"), NULL, SND_ASYNC | SND_LOOP);
	title();
	focus();
	gotoxy(48, 20); printf("���� ���� �� ���� : \n");

	while (1) {

		int select = 0;
		gotoxy(69, 20); scanf_s("%d", &select);


		switch (select)
		{
		case 1: main_mugunghwa(); break;
		case 2: main_dalgona();  break;
		case 3: main_pushpull(); break;
		case 4: main_marble(); break;
		case 5: main_jingumdari(); break;
		case 6: break;
		default: 	gotoxy(69, 20); printf(" "); 	break;

		}

	}



	system("cls");
	return 0;
}