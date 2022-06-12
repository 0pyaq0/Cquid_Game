/* main.c */

#include "rhythm_main.h"


rhy_main() {

	system("cls");
	setlocale(LC_ALL, "");
	SetConsoleTitle(L"Rhythm Game");
	setColor1(white1);

	main_keysetting();

	main_title();

	char* mapName;
	while (1) {

		mapName = main_selectmap();
		if (mapName == NULL) {
			system("cls");
			gotoxy1(1, 1);
			puts("�� ����Ʈ�� �ҷ����� �� �����Ͽ����ϴ�.");
			Sleep(2000);
			break;
		}

		main_gameplay(mapName);
		for (int i = 0; i < mapCount; i++) free(mapList[i]); free(mapList);
	}
}
