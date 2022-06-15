/* main.c */

#include "rhythm_main.h"
#include "modules.h"


rhy_main() {
	system("cls");
	PlaySound(TEXT("./sound/rhythm.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
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
