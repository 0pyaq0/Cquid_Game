/* selectmap.c */

#include "selectmap.h"
#include "modules.h"

// ���� �����ϴ� ��
char* main_selectmap() {
	setCursor(HIDE);
	system("cls");

	mapCount = 0;
	if (loadMaps() == -1) return NULL;

	if (mapCount == 0 || showMapList() == -1) {
		system("cls");
		setColor1(gray1);
		gotoxy1(slp, stp); puts(":( ���� ���׿�..");
		gotoxy1(slp, stp + 3); puts("�� ���۹��� ��_���۹�.md ������ �����ϼ���.");
		gotoxy1(slp, stp + 4); setCursor(UNDERBAR);

		while (1);
	}

	else {

	}

	int pointer = selecting(mapCount);
	blink(pointer);
	return mapList[pointer];
}


// �� ����Ʈ �ҷ��ͼ� maps�� �ֱ�
int loadMaps() {

	mapFolder = "maps";

	// �� ��� ���� ("maps/*")
	static char* dir = NULL;
	if (dir == NULL) {
		dir = malloc(strlen(mapFolder) + 2 + 1);
		if (dir == NULL) return -1;
		sprintf_s(dir, strlen(mapFolder) + 2 + 1, "%s/*", mapFolder);
	}

	// finddata ����
	struct _finddata_t fd;
	intptr_t handle = _findfirst(dir, &fd);
	if (handle == -1) {
		mapCount = 0;
		return 0;
	}

	// �� ���� ���ϱ�
	while (_findnext(handle, &fd) != -1) {
		if (!strcmp(fd.name, "..") || !(fd.attrib & _A_SUBDIR)) // .. �Ǵ� ������ �ƴϸ�
			continue;
		mapCount++;
	}

	// �� ����Ʈ ����
	mapList = malloc(mapCount * sizeof(char*));
	if (mapList == NULL) return -1;

	handle = _findfirst(dir, &fd);
	for (int i = 0; i <= mapCount; i++) {
		if (_findnext(handle, &fd) == -1)
			break;
		if (!strcmp(fd.name, ".") || !strcmp(fd.name, "..") || !(fd.attrib & _A_SUBDIR)) { // . �Ǵ� .. �Ǵ� ������ �ƴϸ�
			i--; continue;
		}

		mapList[i] = malloc(strlen(fd.name) + 1);
		if (mapList[i] == NULL) return -1;
		strcpy_s(mapList[i], strlen(fd.name) + 1, fd.name);
	}

	_findclose(handle);

	return 0;
}

// �� ����Ʈ ȭ�鿡 ����
int showMapList() {

	// �ȳ�
	setColor1(gray1);
	gotoxy1(slp, stp); puts(" :: ���� �����ϼ���.");
	gotoxy1(8, 13); printf("Ű�� �ٽ� �����Ϸ��� ");
	gotoxy1(8, 14); wprintf(L"  ��Ű�� ��������");

	int x = 85;
	int y = 5;
	setColor(RED);
	print_auto_y(&x, &y, "      �ָ�!");
	print_auto_y(&x, &y, "���� Ȯ���� �ּ���!");
	setColor(white1);
	print_auto_y(&x, &y, "���ϴ� ���̵��� �ǵ����");
	print_auto_y(&x, &y, "�ֽø� ���������� �ݿ��ϰڽ��ϴ�!");
	print_auto_y(&x, &y, "��̰� �÷������ּ���!");
	print_auto_y(&x, &y, "   �� ����");
	print_auto_y(&x, &y, "��    ����");
	print_auto_y(&x, &y, "      ����");
	print_auto_y(&x, &y, "��    ����");
	print_auto_y(&x, &y, "��    ����");
	print_auto_y(&x, &y, "��    ����");
	print_auto_y(&x, &y, "      ����");
	print_auto_y(&x, &y, "��    ����");
	print_auto_y(&x, &y, "��    ����");
	print_auto_y(&x, &y, "��    ����");
	print_auto_y(&x, &y, "��    ����");
	print_auto_y(&x, &y, "      ����");
	print_auto_y(&x, &y, "��    ����");
	print_auto_y(&x, &y, "��  ���� ��������");
	print_auto_y(&x, &y, "��  �� ����������");
	print_auto_y(&x, &y, "��  ���� ��������");
	print_auto_y(&x, &y, "��  ������������");
	print_auto_y(&x, &y, "��  ����������");



	// ���̽��ھ� ������ ���� (������ ����)
	const char* highScoreFileName = "stats.dat";
	const int hsfPathSize = (int)strlen(mapFolder) + 1 + (int)strlen(highScoreFileName) + 1;
	statsPath = malloc(hsfPathSize);
	if (statsPath == NULL) return -1;
	sprintf_s(statsPath, hsfPathSize, "%s/%s", mapFolder, highScoreFileName);

	JSON_Value* rootValue = json_parse_file(statsPath);
	if (rootValue == NULL) {
		rootValue = json_value_init_object();
		json_serialize_to_file_pretty(rootValue, statsPath);
	}
	JSON_Object* highScore = json_value_get_object(rootValue);

	// ����Ʈ & ���� ȭ�鿡 ����
	setColor1(gray1);
	gotoxy1(slp + 3, stp + 3); printf("��");
	gotoxy1(slp + 3 + 30, stp + 3); printf("���̽��ھ�");
	setColor1(DARK_GRAY);
	gotoxy1(slp + 2, stp + 4); wprintf(L"������������������������������������������������������������������������������������");

	for (int i = 0; i < mapCount; i++) {
		setColor1(yellow1);
		gotoxy1(slp + 3, stp + 5 + i); puts(mapList[i]);
		setColor1(green1);
		gotoxy1(slp + 3 + 30, stp + 5 + i); printf("%d", (int)json_object_get_number(highScore, mapList[i]));
	}

	return 0;
}


// �� ����Ʈ���� �� �����ϱ�
int selecting(int mapCount)
{
	int pointer = 0;
	setColor1(white1);
	gotoxy1(slp, stp + 5 + pointer); wprintf(L"��");

	// ������ ������ �־��� ����/�����̽��ٸ� �� ������ ���
	while (GetAsyncKeyState(VK_RETURN) || GetAsyncKeyState(VK_SPACE));
	clearBuffer();

	int key;
	BOOL selected = FALSE;
	while (!selected) {

		key = _getch();
		if (key == 0xE0 || key == 0)
			key = _getch();

		switch (key) {

		case 's':
			gotoxy1(slp, stp + 5 + pointer); wprintf(L"��");
			main_keysetting();
			setColor1(white1);
			gotoxy1(slp, stp + 5 + pointer); wprintf(L"��");
			break;

		case up:
			gotoxy1(slp, stp + 5 + pointer); wprintf(L"��");
			pointer--;
			if (pointer < 0)
				pointer = mapCount - 1;
			break;

		case down:
			gotoxy1(slp, stp + 5 + pointer); wprintf(L"��");
			pointer++;
			if (pointer >= mapCount)
				pointer = 0;
			break;

		case enter:
		case SPACE:
			gotoxy1(slp, stp + 5 + pointer); wprintf(L" ��");
			selected = TRUE;
			break;
		}

		if (!selected) {
			gotoxy1(slp, stp + 5 + pointer); wprintf(L"��");
		}
	}

	return pointer;
}

// �����ߴٸ� ������ �� �ؽ�Ʈ �����̱�
void blink(int pointer) {
	gotoxy1(slp + 3, stp + 5 + pointer);
	_putch(' ');

	for (int i = 0; i < 2; i++) {
		gotoxy1(slp + 4, stp + 5 + pointer);
		for (int j = 0; j < strlen(mapList[pointer]); j++)
			_putch(' ');
		Sleep(150);

		gotoxy1(slp + 4, stp + 5 + pointer);
		printf("%s", mapList[pointer]);
		Sleep(150);
	}

	Sleep(300);
}