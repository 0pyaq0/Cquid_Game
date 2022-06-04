#include "rhythm.h"

// ��Ʈ ���� ���� �ɼ� (0/1)
int note_interval = 1;

// Ű �Է� ����
char key_down[4] = { 0 };
char key_state[4] = { 0 };

// ���� ���۸�
char front_buffer[SCR_HEIGHT][4] = { 0 };
char back_buffer[SCR_HEIGHT][4] = { 0 };

// �뷡 ����
char title[NUM_SONG][25] = { "������ - ���� ��", "��Ȱ - �׹��������丮", "Maroon 5 - Payphone" };
char file[NUM_SONG][35] = { "./sound/rhythm/GoodDay.txt" ,"./sound/rhythm/NeverEndingStory.txt","./sound/rhythm/Payphone.txt" };
int bpm[NUM_SONG] = { 128, 61, 110 };
char level[NUM_SONG][10] = { "NORMAL","EASY","HARD" };
char genre[NUM_SONG][10] = { "��", "�߶��", "POP" };
int end[NUM_SONG] = { 1500, 1550, 2160 };
int delay[NUM_SONG] = { 144, 156, 105 };

// ���� �ɼ�
int gamemode = 0; // 0 : ������� / 1 : ��Ʈ ����
int debug = 0; // ����� ��� (������ ǥ��)

// ���� �޴� �ƽ�Ű��Ʈ
char RhythmGame[19][200] = {
		"          88888888ba   88                                 88                                             ",
		"          88      \"8b  88                          ,d     88                                            ",
		"          88      ,8P  88                          88     88                                             ",
		"          88aaaaaa8P\'  88,dPPYba,   8b       d8  MM88MMM  88,dPPYba,   88,dPYba,,adPYba,                ",
		"          88\"\"\"\"88\'    88P\'    \"8a  `8b     d8\'    88     88P\'    \"8a  88P\'   \"88\"    \"8a  ",
		"          88    `8b    88       88   `8b   d8\'     88     88       88  88      88      88               ",
		"          88     `8b   88       88    `8b,d8\'      88,    88       88  88      88      88               ",
		"          88      `8b  88       88      Y88\'       \"Y888  88       88  88      88      88              ",
		"                                        d8\'                                                             ",
		"                                       d8\'                                                              ",
		"                                                                                                         ",
		"                       ,ad8888ba,                                                                        ",
		"                      d8\"\'    `\"8b                                                                    ",
		"                     d8\'                                                                                ",
		"                     88             ,adPPYYba,  88,dPYba,,adPYba,    ,adPPYba,                           ",
		"                     88      88888  \"\"     `Y8  88P\'   \"88\"    \"8a  a8P     `8b                    ",
		"                     Y8,        88  ,adPPPPP88  88      88      88  8PP8888888P                          ",
		"                      Y8a.    .a88  88,    ,88  88      88      88  \"8b,    ,aa                         ",
		"                       `\"Y88888P\"   `\"8bbdP\"Y8  88      88      88   `\"Ybbd88\"\'                   " };

// ���� ���ϴ� ��ġ�� Ŀ�� �̵�
/*void gotoxy(int x, int y)
{
	COORD pos; // Windows.h �� ����
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}*/

// Ŀ�� �Ⱥ��̰�
void removeCursor(void)
{
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}

// ���� ����
void cls(int text_color, int bg_color)
{
	char cmd[100];
	system("cls");
	sprintf(cmd, "COLOR %x%x", bg_color, text_color);
	system(cmd);
}

// �ؽ�Ʈ ����
void textcolor(int fg_color, int bg_color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), fg_color | bg_color << 4);
}

// Ű �Է� ����
void Dkey_press()
{
	while (1)
	{
		if (GetAsyncKeyState(0x44) & 0x8000) // DŰ
		{
			back_buffer[37][0] = '1';
			back_buffer[38][0] = '1';
			key_down[0] = '1'; // Ű�� ���� ����
		}
		else
		{
			key_down[0] = '\0';
			key_state[0] = '1'; // �� ������ ����
		}
		Sleep(1);
	}
}

void Fkey_press()
{
	while (1)
	{
		if (GetAsyncKeyState(0x46) & 0x8000)
		{
			back_buffer[37][1] = '1';
			back_buffer[38][1] = '1';
			key_down[1] = '1';
		}
		else
		{
			key_down[1] = '\0';
			key_state[1] = '1';
		}
		Sleep(1);
	}
}

void Jkey_press()
{
	while (1)
	{
		if (GetAsyncKeyState(0x4A) & 0x8000)
		{
			back_buffer[37][2] = '1';
			back_buffer[38][2] = '1';
			key_down[2] = '1';
		}
		else
		{
			key_down[2] = '\0';
			key_state[2] = '1';
		}
		Sleep(1);
	}
}

void Kkey_press()
{
	while (1)
	{
		if (GetAsyncKeyState(0x4B) & 0x8000)
		{
			back_buffer[37][3] = '1';
			back_buffer[38][3] = '1';
			key_down[3] = '1';
		}
		else
		{
			key_down[3] = '\0';
			key_state[3] = '1';
		}
		Sleep(1);
	}
}

// ����ۿ� �ִ� ���� �������ϱ�
void render()
{
	int x, y;
	for (y = 2; y < SCR_HEIGHT; y++) // �� �ȿ��� ������
		for (x = 0; x < 4; x++)
			if (back_buffer[y][x] != front_buffer[y][x])
			{
				if (y == 36) continue;
				gotoxy(x * 12 + 27, y);
				if (back_buffer[y][x] == '\0')
				{
					textcolor(WHITE, BLACK);
					printf("          ");
				}
				else
				{
					if (x == 0) textcolor(WHITE, RED1);
					else if (x == 1) textcolor(WHITE, BLUE1);
					else if (x == 2) textcolor(WHITE, GREEN1);
					else if (x == 3) textcolor(WHITE, YELLOW1);
					printf("          ");
				}
			}
	// ����ۿ� �ִ� ������ ����Ʈ���ۿ� ����
	for (y = 2; y < SCR_HEIGHT; y++)
		for (x = 0; x < 4; x++)
		{
			front_buffer[y][x] = back_buffer[y][x];
			back_buffer[y][x] = '\0';
		}
}

// �޴��� Ŀ���� ��Ÿ���� �ڽ��� �׸���
void draw_box(int x1, int y1, int x2, int y2)
{
	int x, y;
	for (x = x1; x <= x2; x += 2)
	{
		gotoxy(x, y1);
		printf("��");
		gotoxy(x, y2);
		printf("��");
	}
	for (y = y1; y <= y2; y++)
	{
		gotoxy(x1, y);
		printf("��");
		gotoxy(x2, y);
		printf("��");
	}
	gotoxy(x1, y1);
	printf("��");
	gotoxy(x2, y1);
	printf("��");
	gotoxy(x1, y2);
	printf("��");
	gotoxy(x2, y2);
	printf("��");
}

// �޴��� Ŀ���� ��Ÿ���� �ڽ��� �����
void remove_box(int x1, int y1, int x2, int y2)
{
	int x, y;
	for (x = x1; x <= x2; x += 2)
	{
		gotoxy(x, y1);
		printf("  "); // �������� ������
		gotoxy(x, y2);
		printf("  ");
	}
	for (y = y1; y <= y2; y++)
	{
		gotoxy(x1, y);
		printf("  ");
		gotoxy(x2, y);
		printf("  ");
	}
}

// ���� �޴��� �׸���
void draw_main_menu()
{
	int j;
	for (j = 0; j < 19; j++)
	{
		gotoxy(0, j + 2);
		printf("%s", RhythmGame[j]);
	}
	gotoxy(46, 24);
	printf("����\n");
	gotoxy(46, 27);
	printf("����\n");
	gotoxy(45, 30);
	printf("����\n");
	gotoxy(45, 33);
	printf("������\n");
	draw_box(30, 23, 64, 25);
}

// �� �׸���
void draw_map(n)
{
	gotoxy(2, 1);
	printf("%s\n\n  ����(BPM) : %d\n\n  ���̵� : %s", title[n], bpm[n], level[n]);
	textcolor(WHITE, BLACK);
	draw_box(24, 0, 74, 39);
	gotoxy(24, 36);
	printf("����������������������������������������������������");
	gotoxy(32, 38);
	printf("D           F           J           K");
}

// ���ھ� ���
void print_score(int score, int score_p, int score_g, int score_m)
{
	int i, j, percent[3];
	percent[0] = (double)score_p / ((double)score_p + score_g + score_m) * 100;
	percent[1] = (double)score_g / ((double)score_p + score_g + score_m) * 100;
	percent[2] = (double)score_m / ((double)score_p + score_g + score_m) * 100;
	gotoxy(0, 5);
	if (percent[0] + percent[1] > 90)
	{
		printf("                              d8888      8888888b.                    888\n                             d88888      888   Y88b                   888\n                            d88P888      888    888                   888\n                           d88P 888      888   d88P  8888b.  88888b.  888  888\n                          d88P  888      8888888P\"      \"88b 888 \"88b 888 .88P\n                         d88P   888      888 T88b   .d888888 888  888 888888K\n                        d8888888888      888  T88b  888  888 888  888 888 \"88b\n                       d88P     888      888   T88b \"Y888888 888  888 888  888");
		gotoxy(23, 20);
		printf("Rank : A");
	}
	else if (percent[0] + percent[1] > 70)
	{
		printf("                       888888b.        8888888b.                    888\n                       888  \"88b       888   Y88b                   888\n                       888  .88P       888    888                   888\n                       8888888K.       888   d88P  8888b.  88888b.  888  888\n                       888  \"Y88b      8888888P\"      \"88b 888 \"88b 888 .88P\n                       888    888      888 T88b   .d888888 888  888 888888K\n                       888   d88P      888  T88b  888  888 888  888 888 \"88b\n                       8888888P\"       888   T88b \"Y888888 888  888 888  888");
		gotoxy(23, 20);
		printf("Rank : B");
	}
	else if (percent[0] + percent[1] > 50)
	{
		printf("                        .d8888b.       8888888b.                    888\n                       d88P  Y88b      888   Y88b                   888\n                       888    888      888    888                   888\n                       888             888   d88P  8888b.  88888b.  888  888\n                       888             8888888P\"      \"88b 888 \"88b 888 .88P\n                       888    888      888 T88b   .d888888 888  888 888888K\n                       Y88b  d88P      888  T88b  888  888 888  888 888 \"88b\n                        \"Y8888P\"       888   T88b \"Y888888 888  888 888  888");
		gotoxy(23, 20);
		printf("Rank : C");
	}
	else
	{
		printf("                       8888888b.       8888888b.                    888\n                       888  \"Y88b      888   Y88b                   888\n                       888    888      888    888                   888\n                       888    888      888   d88P  8888b.  88888b.  888  888\n                       888    888      8888888P\"      \"88b 888 \"88b 888 .88P \n                       888    888      888 T88b.   d888888 888  888 888888K\n                       888.  d88P      888  T88b  888  888 888  888 888 \"88b \n                       8888888P\"       888   T88b \"Y888888 888  888 888  888");
		gotoxy(23, 20);
		printf("Rank : D");
	}
	Sleep(100);
	for (i = 0; i <= score; i += 2)
	{
		gotoxy(23, 22);
		printf("SCORE : %d", i);
	}
	Sleep(100);
	for (i = 0; i <= score_p; i++)
	{
		gotoxy(23, 24);
		printf("Perfect : %d", i);
		Sleep(1);
	}
	Sleep(100);
	for (i = 0; i <= score_g; i++)
	{
		gotoxy(23, 26);
		printf("Good : %d", i);
		Sleep(1);
	}
	Sleep(100);
	for (i = 0; i <= score_m; i++)
	{
		gotoxy(23, 28);
		printf("Miss : %d", i);
		Sleep(2);
	}
	Sleep(300);
	gotoxy(53, 28);
	printf("Perfect    Good    Miss");
	for (i = 0; i < 3; i++)
		for (j = 0; j <= percent[i] / 10; j++)
		{
			gotoxy(55 + 9 * i + i % 2, 26 - j);
			printf("��");
			Sleep(400);
		}
	Sleep(10000);
}

// ������� ����
void start_rhythmgame(int song)
{
	unsigned score = 0;
	int i = 0, j, k, combo = 0, miss = 0, m = 0;
	int score_p = 0, score_g = 0, score_m = 0;
	int tmp[4] = { 0 };
	char buf1[2200]; // ��Ʈ ���� ����
	char buf2[2200];
	char buf3[2200];
	char buf4[2200];
	DWORD real_delay;
	clock_t now, now2;
	FILE* fp;
	if ((fp = fopen(file[song], "r")) == NULL) // ������ �о����
	{
		printf("�������� �� �� �����ϴ�.\n");
		return;
	}
	// ��Ʈ ���� �о����
	fgets(buf1, sizeof(buf1), fp);
	fgets(buf2, sizeof(buf2), fp);
	fgets(buf3, sizeof(buf3), fp);
	fgets(buf4, sizeof(buf4), fp);
	fclose(fp);
	// Ű �Է� ������ ����
	_beginthreadex(NULL, 0, (_beginthreadex_proc_type)Dkey_press, NULL, 0, NULL);
	_beginthreadex(NULL, 0, (_beginthreadex_proc_type)Fkey_press, NULL, 0, NULL);
	_beginthreadex(NULL, 0, (_beginthreadex_proc_type)Jkey_press, NULL, 0, NULL);
	_beginthreadex(NULL, 0, (_beginthreadex_proc_type)Kkey_press, NULL, 0, NULL);
	draw_map(song);
	// �뷡 ���
	if (song == 0) PlaySound(TEXT("./sound/rhythm/GoodDay.wav"), NULL, SND_ASYNC);
	else if (song == 1) PlaySound(TEXT("./sound/rhythm/NeverEndingStory.wav"), NULL, SND_ASYNC);
	else PlaySound(TEXT("./sound/rhythm/Payphone.wav"), NULL, SND_ASYNC);
	now = clock();
	while (1)
	{
		if (m > 0)
		{
			m++;
			if (m > 5)
			{
				m = 0;
				gotoxy(78, 5);
				printf("          ");
			}
		}
		// ��Ʈ �׸��� (���� ���۸�)
		for (j = i; j >= 0; j--)
		{
			if (j >= 36) j = 36;
			if (buf1[i - j] == '1')
				back_buffer[j][0] = '1';
			if (buf2[i - j] == '1')
				back_buffer[j][1] = '1';
			if (buf3[i - j] == '1')
				back_buffer[j][2] = '1';
			if (buf4[i - j] == '1')
				back_buffer[j][3] = '1';
		}
		for (j = 0; j < 4; j++)
			if (tmp[j] == 1) // �̸� ��Ʈ�� �������� �����
			{
				back_buffer[36][j] = '\0';
				front_buffer[36][j] = '\0';
				tmp[j] = 0;
			}
		render();
		miss = 0;
		textcolor(WHITE, BLACK);
		// Ű ���� & ���� ���
		for (k = 0; k < 4; k++)
		{
			if (front_buffer[36][k] == '1') miss++;
			if (key_down[k] == '1')
			{
				if (key_state[k] == '1')
				{
					// ��Ʈ�� ���� �� ���� ���
					if (front_buffer[35][k] == '\0' && front_buffer[36][k] == '\0')
						key_state[k] = '\0';
					// �ճ�Ʈ�� ������ ���� ���
					else if (front_buffer[34][k] == '1' && front_buffer[35][k] == '1')
					{
						combo++;
						miss--;
						score_g++;
						score += (combo / 10 + 1) * 50; // ��������
						tmp[k] = 1; // ���� ��Ʈ�� ����
						m = 1;
						gotoxy(78, 5);
						printf("GOOD!     ");
					}
					// �ճ�Ʈ�� ���� ���
					else if (front_buffer[35][k] == '1' && front_buffer[36][k] == '1')
					{
						combo++;
						miss--;
						score_p++;
						score += (combo / 10 + 1) * 100;
						m = 1;
						gotoxy(78, 5);
						printf("EXCELLENT!");
					}
					// ���� ������ ���� ���
					else if (front_buffer[35][k] == '1' && front_buffer[36][k] == '\0')
					{
						combo++;
						score_g++;
						score += (combo / 10 + 1) * 50;
						key_state[k] = '\0';
						tmp[k] = 1; // ���� ��Ʈ�� ����
						m = 1;
						gotoxy(78, 5);
						printf("GOOD!     ");
					}
					// ��Ȯ�� ���� ���
					else if (front_buffer[36][k] == '1')
					{
						combo++;
						miss--;
						score_p++;
						score = score + (combo / 10 + 1) * 100;
						key_state[k] = '\0';
						m = 1;
						gotoxy(78, 5);
						printf("EXCELLENT!");
					}
				}
				key_down[k] = '\0';
			}
		}
		if (miss > 0)
		{
			score_m++;
			combo = 0;
		}
		if (combo)
		{
			gotoxy(78, 3);
			printf("COMBO! x %d            ", combo);
		}
		else
		{
			gotoxy(78, 3);
			printf("                    "); // �����
		}
		gotoxy(78, 1);
		printf("SCORE : %d            ", score);
		i++;
		if (i > end[song]) break;
		// �����̰� �׻� �����ϵ��� ����
		now2 = clock();
		real_delay = delay[song] - (now2 - now);
		if (debug)
		{
			gotoxy(78, 5);
			printf("DELAY : %d / %d", real_delay, delay[song]);
		}
		Sleep(real_delay);
		now = clock();
	}
	// ����
	PlaySound(NULL, 0, 0);
	textcolor(WHITE, BLACK);
	system("cls");
	print_score(score, score_p, score_g, score_m);
	system("cls");
}

// ��Ʈ ���� ���
void write_note(int song)
{
	int i = 0;
	char buf1[2200];// ��Ʈ ���� ����
	char buf2[2200];
	char buf3[2200];
	char buf4[2200];
	DWORD real_delay;
	clock_t now, now2;
	FILE* fp;
	if ((fp = fopen("./sound/rhythm/note.txt", "w")) == NULL) // ������ �о����
	{
		printf("�������� �� �� �����ϴ�.\n");
		return;
	}
	// Ű �Է� ������ ����
	_beginthreadex(NULL, 0, (_beginthreadex_proc_type)Dkey_press, NULL, 0, NULL);
	_beginthreadex(NULL, 0, (_beginthreadex_proc_type)Fkey_press, NULL, 0, NULL);
	_beginthreadex(NULL, 0, (_beginthreadex_proc_type)Jkey_press, NULL, 0, NULL);
	_beginthreadex(NULL, 0, (_beginthreadex_proc_type)Kkey_press, NULL, 0, NULL);
	draw_map(song);
	// �뷡 ���
	if (song == 0) PlaySound(TEXT("./sound/rhythm/GoodDay.wav"), NULL, SND_ASYNC);
	else if (song == 1) PlaySound(TEXT("./sound/rhythm/NeverEndingStory.wav"), NULL, SND_ASYNC);
	else PlaySound(TEXT("./sound/rhythm/Payphone.wav"), NULL, SND_ASYNC);
	while (1)
	{
		now = clock();
		// ��Ʈ �׸��� (���� ���۸�)
		render();
		// Ű ���� & ���� ���
		if (key_down[0] == '1')
		{
			buf1[i] = '1';
			key_down[0] = '\0';
		}
		else
			buf1[i] = '0';
		if (key_down[1] == '1')
		{
			buf2[i] = '1';
			key_down[1] = '\0';
		}
		else
			buf2[i] = '0';
		if (key_down[2] == '1')
		{
			buf3[i] = '1';
			key_down[2] = '\0';
		}
		else
			buf3[i] = '0';
		if (key_down[3] == '1')
		{
			buf4[i] = '1';
			key_down[3] = '\0';
		}
		else
			buf4[i] = '0';
		if (i > end[song]) break;
		i++;
		// �����̰� �׻� �����ϵ��� ����
		now2 = clock();
		real_delay = delay[song] - (now2 - now);
		if (debug)
		{
			textcolor(WHITE, BLACK);
			gotoxy(78, 5);
			printf("DELAY : %d / %d", real_delay, delay[song]);
		}
		Sleep(real_delay);
	}
	fputs(buf1, fp);
	fputs("\n", fp);
	fputs(buf2, fp);
	fputs("\n", fp);
	fputs(buf3, fp);
	fputs("\n", fp);
	fputs(buf4, fp);
	fclose(fp);
	// ����
	PlaySound(NULL, 0, 0);
	textcolor(WHITE, BLACK);
	system("cls");
	gotoxy(35, 10);
	printf("��Ʈ�� ����Ǿ����ϴ�.");
	Sleep(4000);
	return;
}

// ����â���� �޴��� �����Ѵ�
int select_main_menu()
{
	int n = 0;
	unsigned char ch = 0;
	while (1)
	{
		if (_kbhit() == 1) // Ű���尡 ������ ������
		{
			ch = _getch();
			if (ch == SPECIAL1 || ch == SPECIAL2) // ���� Ư��Ű
			{ // ���� ��� UP key�� ��� 0xe0 0x48 �ΰ��� ���ڰ� ���´�.
				ch = _getch();
				remove_box(30, 23 + n % 4 * 3, 64, 25 + n % 4 * 3);
				if (ch == UP) n += 3; // ��ĭ ����
				else if (ch == DOWN) n += 1; // ��ĭ �Ʒ���
				draw_box(30, 23 + n % 4 * 3, 64, 25 + n % 4 * 3);
			}
			else if (ch == ENTER)
			{
				textcolor(WHITE, BLACK);
				system("cls");
				return n % 4;  // ����Ű �Է��ϸ� ��ġ�� ����
			}
		}
	}
}

// �뷡 ���� â
void select_song()
{
	// �ִϸ��̼� ȿ��
	int i, j, n = 0;
	unsigned char ch = 0;
	for (i = 0; i < 19; i++)
	{
		for (j = 0; j < 19 - i; j++)
		{
			gotoxy(0, j + 3);
			printf("                                                                                             ");
			gotoxy(0, j + 2);
			printf("%s", RhythmGame[j + i]);
		}
		Sleep(50);
	}
	gotoxy(0, 2);
	printf("                                                                                             ");
	Sleep(300);
	gotoxy(39, 5);
	printf("�뷡�� ������ �ּ���");
	gotoxy(44, 30);
	printf("�ڷΰ���");
	for (i = 0; i < 3; i++)
		for (j = 5; j > 0; j--)
		{
			gotoxy(i * 31, 14);
			gotoxy(8 + i * 30 + i / 2 * 3 - j, 14);
			printf("  %s", title[i]);
			gotoxy(8 + i * 30 + i / 2 * 3 - j, 16);
			printf("  ���̵� : %s", level[i]);
			gotoxy(8 + i * 30 + i / 2 * 3 - j, 18);
			printf("  ����(BPM) : %d", bpm[i]);
			gotoxy(8 + i * 30 + i / 2 * 3 - j, 20);
			printf("  �帣 : %s", genre[i]);
			Sleep(70);
		}
	draw_box(3, 13, 29, 21);
	i = 1;
	while (1)
	{
		if (_kbhit() == 1) // Ű���尡 ������ ������
		{
			ch = _getch();
			if (ch == SPECIAL1 || ch == SPECIAL2) // ���� Ư��Ű
			{ // ���� ��� UP key�� ��� 0xe0 0x48 �ΰ��� ���ڰ� ���´�.
				ch = _getch();
				if (i) remove_box(3 + n * 32, 13, 29 + n * 32, 21);
				else remove_box(30, 29, 64, 31);
				if (ch == LEFT) n += 2; // �������� ��ĭ �̵�
				else if (ch == RIGHT) n += 1; // ���������� ��ĭ �̵�
				else if (ch == UP) i = 1; // Ŀ���� �Ʒ��� ������ 1
				else if (ch == DOWN) i = 0; // �ؿ� ������ 0
				n %= 3;
				if (i) draw_box(3 + n * 32, 13, 29 + n * 32, 21);
				else draw_box(30, 29, 64, 31);
			}
			else if (ch == ENTER)
			{
				textcolor(WHITE, BLACK);
				system("cls");
				if (i == 0) return;
				else
				{
					if (gamemode) write_note(n % 3);
					else start_game(n % 3);
				}
				ch = _getch();
				return;
			}
		}
	}
}

// �ɼ� �޴�
void go_option()
{
	int n = 0;
	unsigned char ch = 0;
	system("cls");
	gotoxy(48, 10);
	printf("�ɼ�");
	gotoxy(40, 21);
	printf("      �ڷΰ���");
	draw_box(37, 14, 61, 16);
	if (gamemode)
	{
		gotoxy(40, 15);
		printf("��Ʈ ��� ���   ON ");
	}
	else
	{
		gotoxy(40, 15);
		printf("��Ʈ ��� ���   OFF");
	}
	if (debug)
	{
		gotoxy(40, 18);
		printf("   ����� ���   ON ");
	}
	else
	{
		gotoxy(40, 18);
		printf("   ����� ���   OFF");
	}
	while (1)
	{

		if (_kbhit() == 1) // Ű���尡 ������ ������
		{
			ch = _getch();
			if (ch == SPECIAL1 || ch == SPECIAL2) // ���� Ư��Ű
			{ // ���� ��� UP key�� ��� 0xe0 0x48 �ΰ��� ���ڰ� ���´�.
				ch = _getch();
				remove_box(37, 14 + n % 3 * 3, 61, 16 + n % 3 * 3);
				if (ch == UP) n += 2; // ��ĭ ����
				else if (ch == DOWN) n += 1; // ��ĭ �Ʒ���
				draw_box(37, 14 + n % 3 * 3, 61, 16 + n % 3 * 3);
			}
			else if (ch == ENTER)
			{
				textcolor(WHITE, BLACK);
				if (n % 3 == 0)
				{
					gamemode = (gamemode + 1) % 2;
					if (gamemode)
					{
						gotoxy(40, 15);
						printf("��Ʈ ��� ���   ON ");
					}
					else
					{
						gotoxy(40, 15);
						printf("��Ʈ ��� ���   OFF");
					}
				}
				else if (n % 3 == 1)
				{
					debug = (debug + 1) % 2;
					if (debug)
					{
						gotoxy(40, 18);
						printf("   ����� ���   ON ");
					}
					else
					{
						gotoxy(40, 18);
						printf("   ����� ���   OFF");
					}
				}
				else
				{
					system("cls");
					return;
				}
			}
		}
	}
	system("cls");
}

// ���� �޴� (�̿ϼ�)
void draw_help()
{
	char ch;
	system("cls");
	gotoxy(15, 10);
	printf("��Ʈ�� �������� ������ �� D, F, J, K Ű�� �̿��ؼ� ��Ʈ�� ������ �˴ϴ�.");
	gotoxy(15, 13);
	printf("����� ��� : ���� �����̸� �����ݴϴ�.");
	gotoxy(15, 16);
	printf("��Ʈ ��� ��� : ��Ʈ�� ��� ����Դϴ�. \"note.txt\" ���Ͽ� ����˴ϴ�.");
	gotoxy(15, 18);
	printf("��Ʈ�� �������� �ʰ�, �뷡�� ����˴ϴ�.");
	gotoxy(15, 20);
	printf("���� ������ ���� �� �뷡 ���Ͽ� �����ֱ��� ��, ���� Ÿ�̹��� �����ָ� �˴ϴ�.");
	gotoxy(15, 23);
	printf("Developed by ������");
	ch = _getch();
	system("cls");
	draw_box(24, 0, 74, 39);
	gotoxy(24, 36);
	printf("����������������������������������������������������");
	gotoxy(32, 38);
	printf("D           F           J           K");
	gotoxy(76, 36);
	printf("�� ���Ⱑ �������Դϴ�.");
	ch = _getch();
	system("cls");
}

// ���� �Լ�
void rhythm_main()
{
	// ���� �޴� ����
	removeCursor();
	while (1)
	{
		draw_main_menu();
		switch (select_main_menu())
		{
		case 0:
			select_song(); break;
		case 1:
			go_option(); break;
		case 2:
			draw_help(); break;
		case 3:
			printf("\n"); return; // ����
		}
	}
}