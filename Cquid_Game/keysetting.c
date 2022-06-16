/* keysetting.c */

#include "keysetting.h"


// Ű�� �����ϴ� ��
void main_keysetting() {

	const int klp = 51; // keysetting left padding
	const int ktp = 10; // keysetting top padding
	const int gap = 5; // Ű ���� ������ ���� (+1)
	const int boxWid = LINE * gap - 1; // Ű���� UI ���� ����
	memset(key, 0, sizeof(key));

	setCursor(BLOCK);
	setColor1(white1);
	gotoxy1(klp + (boxWid - 7) / 2 - 1, ktp);
	puts("Ű ����");
	for (int i = 0; i < LINE; i++) {
		gotoxy1(klp + i * gap, ktp + 2); wprintf(L"��");
	}

	// Ű �Է�
	for (int i = 0; i < LINE; i++) {
		gotoxy1(klp + i * gap, ktp + 6); wprintf(L"��");

		int k = 0;
		for (;;) {
			gotoxy1(klp + i * gap, ktp + 4);
			setCursor(BLOCK);
			k = _getch();

			BOOL able = TRUE;
			if (k == 0xE0 || k == 0) { k = _getch(); able = FALSE; } // Ư��Ű(Ȯ��Ű) �Ұ���
			else if (k == 27) able = FALSE; // Esc �Ұ���
			else if (strchr("`-=[]\\;',./", k)) able = FALSE; // ��Ÿ ����
			for (int j = 0; j < i; j++) if (k == key[j]) { able = FALSE; break; } // �ߺ��� Ű �Ұ���

			if (able)
				break;
		}
		setCursor(HIDE);

		if ('a' <= k && k <= 'z')
			k -= 'a' - 'A'; // ��ҹ��� ����

		switch (k) {
		case BACKSPACE:
			wcscpy_s(keyName[i], sizeof(keyName[i]) / sizeof(wchar_t), L"Bksp"); break;
		case enter:
			wcscpy_s(keyName[i], sizeof(keyName[i]) / sizeof(wchar_t), L"Entr"); break;
		case SPACE:
			wcscpy_s(keyName[i], sizeof(keyName[i]) / sizeof(wchar_t), L"Spce"); break;
		case TAB:
			wcscpy_s(keyName[i], sizeof(keyName[i]) / sizeof(wchar_t), L"Tab"); break;
		default:
			swprintf(keyName[i], sizeof(keyName[i]) / sizeof(wchar_t), L" %c ", k + 0xFEE0); break;
		}

		gotoxy1(klp + i * gap - 1, ktp + 4);
		setColor1(SKYBLUE);
		wprintf(L"%s", keyName[i]);
		setColor1(white1);

		key[i] = k;

		gotoxy1(klp + i * gap, ktp + 2); wprintf(L"��");
		gotoxy1(klp + i * gap, ktp + 6); wprintf(L"��");
	}

	// ��������
	Sleep(180);
	for (int r = 0; r < 2; r++) {
		setColor1(white1);
		for (int i = 0; i < LINE; i++) {
			gotoxy1(klp + i * gap - 1, ktp + 4); wprintf(L" �� ");
		}
		Sleep(110);

		setColor1(SKYBLUE);
		for (int i = 0; i < LINE; i++) {
			gotoxy1(klp + i * gap - 1, ktp + 4); wprintf(L"%s", keyName[i]);
		}
		Sleep(110);
	}
	Sleep(400);

	// Ŭ����
	for (int i = 0; i < 6; i++) {
		gotoxy1(klp - 1, ktp + i);
		for (int j = 0; j < boxWid; j++) {
			_putch(' ');
		}
	}
}
