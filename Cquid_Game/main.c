#include "main.h"
#include "MarbleGame.h"



//Ÿ��Ʋ ���
void title() {
	gotoxy(35, 4); printf(" _____ ____  __    __ _____ _____   ");
	gotoxy(35, 5); printf("/ ____/ __ ��| |  | ||_   _|  __ �� ");
	gotoxy(35, 6); printf("| |   | |  | | |  | |  | | | |  | |");
	gotoxy(35, 7); printf("| |   | |  | | |  | |  | | | |  | | ");
	gotoxy(35, 8); printf("| |___| |__| | |__| | _| |_| |__| | ");
	gotoxy(35, 9); printf("��____��___����____/ |_____|_____/  ");

	gotoxy(35, 10); printf("   _____          __    __ ______ ");
	gotoxy(35, 11); printf("  / ____|   /��   |  ��/  |  ____|");
	gotoxy(35, 12); printf(" | |  __   /  ��  | ��  / | |__ ");
	gotoxy(35, 13); printf(" | | |_ | / /���� | |��/| |  __|");
	gotoxy(35, 14); printf(" | |__| |/ ____ ��| |   | | |____ ");
	gotoxy(35, 15); printf("  ��____/_/   ��_��_|   |_|______|");
}

//���� ��Ŀ��
void focus() {




	gotoxy(11, 20);
	printf("��������������������������������������\n");
	gotoxy(11, 21);
	printf("��                 ��\n");
	gotoxy(11, 22);
	printf("��                 ��\n");
	gotoxy(11, 23);
	printf("��                 ��\n");
	gotoxy(11, 24);
	printf("��������������������������������������\n");

	gotoxy(13, 22); printf("�� ����ȭ ��\n");
	gotoxy(26, 22);  printf("�� �ް��̱�");
	gotoxy(39, 22);  printf("�� �ٴٸ���");
	gotoxy(13, 26);  printf("�� ����ġ��");
	gotoxy(26, 26);  printf("�� ¡�˴ٸ�");
	gotoxy(39, 26);  printf("�� �������");
}




int main() {
	title();
	focus();

	while (1) {


		int chk = 0;
		gotoxy(13, 18); printf("���� ���� : \n");
		gotoxy(20, 18); scanf_s("%d", &chk);

		switch (chk)
		{
		case 1: break;
		case 2: break;
		case 3: break;
		case 4: main_marble(); break;
		case 5: break;
		case 6: break;

		}
	}




	return 0;
}