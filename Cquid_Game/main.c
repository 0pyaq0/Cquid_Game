#include "modules.h"
#include "MarbleGame.h"
#include "Jingumdari.h"
#include "pushpull.h"
#include"dalgona.h"
#include "Mugunghwa.h"

//Ÿ��Ʋ ���
void title() {
	gotoxy(60, 4); printf(" _____ ____  __    __ _____ _____   ");
	gotoxy(60, 5); printf("/ ____/ __ ��| |  | ||_   _|  __ �� ");
	gotoxy(60, 6); printf("| |   | |  | | |  | |  | | | |  | |");
	gotoxy(60, 7); printf("| |   | |  | | |  | |  | | | |  | | ");
	gotoxy(60, 8); printf("| |___| |__| | |__| | _| |_| |__| | ");
	gotoxy(60, 9); printf("��____��___����____/ |_____|_____/  ");

	gotoxy(60, 10); printf("   _____          __    __ ______ ");
	gotoxy(60, 11); printf("  / ____|   /��   |  ��/  |  ____|");
	gotoxy(60, 12); printf(" | |  __   /  ��  | ��  / | |__ ");
	gotoxy(60, 13); printf(" | | |_ | / /���� | |��/| |  __|");
	gotoxy(60, 14); printf(" | |__| |/ ____ ��| |   | | |____ ");
	gotoxy(60, 15); printf("  ��____/_/   ��_��_|   |_|______|");
}

//���� ��Ŀ��
void focus() {




	/*gotoxy(11, 20);
	printf("��������������������������������������\n");
	gotoxy(11, 21);
	printf("��                 ��\n");
	gotoxy(11, 22);
	printf("��                 ��\n");
	gotoxy(11, 23);
	printf("��                 ��\n");
	gotoxy(11, 24);
	printf("��������������������������������������\n");*/

	gotoxy(13, 22); printf("�� ����ȭ ��\n");
	gotoxy(26, 22);  printf("�� �ް��̱�");
	gotoxy(39, 22);  printf("�� �ٴٸ���");
	gotoxy(13, 26);  printf("�� ����ġ��");
	gotoxy(26, 26);  printf("�� ¡�˴ٸ�");
	gotoxy(39, 26);  printf("�� �������");
}



int main() {


	while (1) {
		title();
		focus();
		PlaySound(NULL, 0, 0);
		int chk = 0;
		gotoxy(13, 18); printf("���� ���� : \n");
		gotoxy(20, 18); scanf_s("%d", &chk);

		switch (chk)
		{
		case 1: main_mugunghwa(); break;
		case 2: main_dalgona();  break;
		case 3: main_pushpull(); break;
		case 4: main_marble(); break;
		case 5: main_jingumdari(); break;
		case 6: break;

		}
	}

	

		system("cls");
	return 0;
}