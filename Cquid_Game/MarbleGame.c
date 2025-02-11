#include "MarbleGame.h"

char tempMap[18][100];	//맵 임시저장할 배열

char map1[18][100] = {
	{"0"},
	{"0"},
	{"0"},
	{"0"},
	{"0000000000000000011111111111111111111111111111111111111111111111111111111"},
	{"0000000000000000010000000100000000000000000000000000000000000000000000001"},
	{"0000000000000000010000000100000000000000000000000000000000000000000000001"}, // 0 : 빈 공간 
	{"0000000000000000010001000100000000000000000000000000000000000000000000001"}, // 1 : 벽 
	{"0000000000000000010001000100000000000000000000000000000000000000000000001"}, // k : 열쇠 
	{"0000000000000000010001000100000000000000000000000000000000000000000000001"}, // l : 잠긴 문 
	{"0000000000000000010001000111111000000000000000000000000000000000000000001"}, // q : 탈출구  
	{"0000000000000000010001000000001000000000000000000000000000000000000000001"},
	{"0000000000000000010001000100001000000000000000000000000000000000000000001"},
	{"0000000000000000010001000100k01000000000000000000000000000000000011111111"},
	{"0000000000000000010001000100001000000000000000000000000000000000010000001"},
	{"0000000000000000010s010001111111111111111111111111111111111111111100q0001"},
	{"0000000000000000010001000l00000000000000k0000000000000000000000l000000001"},
	{"0000000000000000011111111111111111111111111111111111111111111111111111111"}
};

char map2[18][100] = {
	{"0"},
	{"0"},
	{"0"},
	{"0000000000000000011111111111111111111111111111111111111111111111111111111"},
	{"0000000000000000010s00100000000000l000k000000000000l0k1000000000000000001"},
	{"0000000000000000010000100111100000111111110001110011011000000000000000001"},
	{"0000000000000000011110111100000000l00000010001010001011111111111111100001"},
	{"000000000000000001k01000010001111110001l111111011111001000000000000100001"},
	{"000000000000000001001000010k010000111110000000000100001111100000000100001"},
	{"0000000000000000010010000100000000100000111110111100001000000100000100001"},
	{"0000000000000000010011100111111111111111100000100000001000000100000000001"},
	{"0000000000000000010000000100000000100000100000111001111111111111111111111"},
	{"0000000000000000011111100111000000l001000000111000000l0000000000000000001"},
	{"000000000000000001000k1l1100011111100111100010100000010111000101111111001"},
	{"0000000000000000010111100101110000001100110010100000010001111100001q01001"},
	{"0000000000000000010000000000k1001k100100000010000000010100000000001000001"},
	{"0000000000000000011111111111111111111111111111111111111111111111111111111"}
};

char map3[18][100] = {
	{"0"},
	{"0"},
	{"0"},
	{"0000000000000000011111111111111111111111111111111111111111111111111111111"},
	{"00000000000000000100000100010001k0001000000000010001000001000101000100001"},
	{"0000000000000000010000010101010111101011111011010101011101010101010001001"},
	{"000000000000000001000101010001000k10101000101k01010101k101010001111111001"},
	{"0000000000000000010001000101111111101010101011110001000101011111000000001"},
	{"00000000000000000100011111l1000000001010101000000011101101010001010111101"},
	{"0000000000000000010001000001011111111010101110111000000100010100010100001"},
	{"0000000000000000010001011111010000000010100000001110110101000101000100001"},
	{"0000000000000000010001010000010000001010110111100000000101010101010001l11"},
	{"0000000000000000010001010111010000001000000000101011110101010101011111l11"},
	{"00000000000000000100010101k0010000001111011110001000010101010100010000001"},
	{"0000000000000000010s010101111111110110010100001011110100010111110100q0001"},
	{"000000000000000001000100000l000l00010001000111100000010101000000010000001"},
	{"0000000000000000011111111111111111111111111111111111111111111111111111111"}
};


void drawMap(int* x, int* y) {
	system("cls");
	int h, w; //세로, 가로
	for (h = 0; h < 18; h++) {
		for (w = 0; w < 100; w++) {
			char temp = tempMap[h][w];	//현재의 맴 데이터
			if (temp == '0') {	//빈 공간(공백)
				setBackColor(black, black);
				printf(" ");
			}
			else if (temp == '1') {	//벽(#)
				setBackColor(white, white);
				printf("#");
			}
			else if (temp == 's') {	//플레이어(@)
				*x = w;	//플레이어 좌표값 저장
				*y = h;
				setBackColor(cyan, black);
				printf("@");
			}
			else if (temp == 'q') {	//목적지(O)
				setBackColor(lightgreen, black);
				printf("O");
			}
			else if (temp == 'k') {	//열쇠(*)
				setBackColor(yellow, black);
				printf("*");
			}
			else if (temp == 'l') {	//잠긴 문 
				setBackColor(brown, black);
				printf("+");
			}
		}
		printf("\n");
	}
	setBackColor(white, black);
}

//게임 루프
void gLoop(int mapCode) {
	time_t new_time, old_time;	//경과 시간
	int x, y;	// 플레이어 좌표 저장 변수선언(x,y)
	int key = 0;
	int playing = 1; //1이면 게임중, 0이면 게임 종료
	int DELAY = 0;
	int move_key;

	if (mapCode == 0) {
		memcpy(tempMap, map1, sizeof(tempMap)); DELAY = 10000;
	}
	else if (mapCode == 1) {
		memcpy(tempMap, map2, sizeof(tempMap));	DELAY = 30000;
	}
	else if (mapCode == 2) {
		memcpy(tempMap, map3, sizeof(tempMap));	DELAY = 40000;
	}

	switch (drawlevel()) {
	case 0:
		DELAY += 10000;
		break;
	case 1:
		DELAY += 5000;
		break;
	}

	drawMap(&x, &y);	//맵 설정 후 출력, 맵에 좌표 포인터를 전달
	old_time = clock();	//시작시간

	while (playing) {
		gamerule();
		drawUI(&x, &y, &key);
		move_key = getch();
		new_time = clock();
		// 시간차
		double diff = difftime(new_time, old_time);
		if (diff > DELAY) {
			failDraw();
			break;
		}
		drawTime(diff, DELAY);

		switch (move_key) {
		case UP:	//위로움직이기
			move(&x, &y, 0, -1, &key, &playing);
			break;

		case DOWN:	//아래로움직이기
			move(&x, &y, 0, 1, &key, &playing);
			break;

		case RIGHT:	//오른쪽으로움직이기
			move(&x, &y, 1, 0, &key, &playing);
			break;

		case LEFT:	//왼쪽으로움직이기
			move(&x, &y, -1, 0, &key, &playing);
			break;
			//x : 1이 증가하면 오른쪽으로 이동
			//y : 1이 증가하면 아래로 이동

		case ESC:
			setBackColor(white, black);
			playing = 0;	//0이 되면 반복 종료
		}
	}
	if (!playing) {
		endDraw();
	}
}

//원래 좌표(x, y), 증감할 좌표(_x, _y)
void move(int* x, int* y, int _x, int _y, int* key, int* playing) {
	//이동할 위치에 있는 맵 배열의 문자 임시저장
	char mapObject = tempMap[*y + _y][*x + _x];
	setBackColor(white, black);

	if (mapObject == '0') {
		gotoxy(*x, *y);
		printf(" ");	//지우기
		setBackColor(cyan, black); //색 설정
		gotoxy(*x + _x, *y + _y);	//증감한 위치로 이동 후 플레이어 출력
		printf("@");
		*x += _x;	//실제 좌표값 반영--
		*y += _y;
	}
	else if (mapObject == 'k') {//이동할 위치에 열쇠가 있으면 획득
		*key += 1;	//열쇠개수 1개 증가
		tempMap[*y + _y][*x + _x] = '0';	//획득했으면 기존에 있던 k를 0으로 설정
		gotoxy(*x + _x, *y + _y);	//열쇠가 있는 위치를 지움
		printf(" ");
	}
	else if (mapObject == 'l') {
		if (*key > 0) {
			*key -= 1;	//열쇠가 1개 이상있으면 1개 소모
			tempMap[*y + _y][*x + _x] = '0';	//뮨이 열렸으니 l데이터 0으로 설정
			setBackColor(white, black);	//색 기본 값
			gotoxy(*x + _x, *y + _y);
			printf(" ");
		}
	}
	else if (mapObject == 'q') {
		*playing = 0;	//1:게임 진행중, 0:게임종료
	}
}

int keyControl(int x, int y, int num)
{
	int input;
	int key = y;

	while (1) {
		input = _getch();
		switch (input) {
		case UP: {
			if (y > key) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, --y);
				printf(">");
			}
			break;
		}
		case DOWN: {
			if (y < key + num) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, ++y);
				printf(">");
			}
			break;
		}
		case ENTER: {
			return y - key;
		}
		case ESC: {
			return 1;
		}
		}
	}
	return 0;
}

//게임 하단에 좌표 및 아이템 정보 출력
void drawUI(int* x, int* y, int* key) {
	setBackColor(white, black);
	gotoxy(79, 24);
	printf("--------------------");
	gotoxy(80, 25);
	printf("위치 : %02d, %02d", *y, *x);
	gotoxy(79, 26);
	printf("--------------------");
	setBackColor(yellow, black);
	gotoxy(49, 24);
	printf("---------------");
	gotoxy(50, 25);
	printf("열쇠 : %d개", *key);
	gotoxy(49, 26);
	printf("---------------");
}

void drawTime(double time, double stime)
{
	setBackColor(lightcyan, black);
	gotoxy(19, 24);
	printf("--------------------");
	gotoxy(20, 25);
	printf("제한 시간 : %.0f 초 ", (stime - time) / 1000);
	gotoxy(19, 26);
	printf("--------------------");
}

int drawlevel()
{
	system("cls");
	int x = 58, y = 6;
	int level_n;
	setBackColor(white, black);
	printf("\n\n");
	printf("\t\t\t\t\t\t\t[레벨 선택]\n\n");
	gotoxy(x - 2, y);
	printf("> 하단계");
	gotoxy(x, y + 1);
	printf("중단계");
	gotoxy(x, y + 2);
	printf("상단계");

	return keyControl(x, y, 2);
}

void titleDraw() {
	setBackColor(lightgreen, black);
	printf("\n\n\t\t\t  __  __            _     _        _____ \n");
	printf("\t\t\t |  \\/  |          | |   | |      / ____| \n");
	printf("\t\t\t | \\  / | __ _ _ __| |__ | | ___  | |  __  __ _ _ __ ___   ___ \n");
	printf("\t\t\t | |\\/| |/ _` | '__| '_ \\| |/ _ \\ | | |_ |/ _` | '_ ` _ \\ / _ \\ \n");
	printf("\t\t\t | |  | | (_| | |  | |_) | |  __/ | |__| | (_| | | | | | |  __/ \n");
	printf("\t\t\t |_|  |_|\\__,_|_|  |_.__/|_|\\___|  \\_____|\\__,_|_| |_| |_|\\___| \n");
	setBackColor(white, black);
	printf("\n\n");
	printf("          ○                        - - - - - ○ △ □ 구슬 치기 ○ △ □ - - - - -                      △ \n\n");
	printf("                 △                |      구슬을 쳐서 미로를 탈출하십시오          |        ○\n\n");
	printf("                                   |           벽에 닿아도 죽지 않습니다.          |\n\n");
	printf("                       □          |       위(↑), 아래(↓), 오(→), 왼(←)        |              □\n\n");
	printf("     △                            |       Enter (시작키) ESC (종료키)             |       ○\n\n");
	printf("                                   |         시간내에 탈출하면 통과입니다.         |                     △\n\n");
	printf("              □                    - - - - - - - - - - - - - - - - - - - - - - - -\n");
}

int menuDraw() {
	int x = 55, y = 25;
	int input;
	gotoxy(x - 2, y);
	printf("> 게임시작");
	gotoxy(x, y + 1);
	printf("게임종료");
	setBackColor(darkgray, black);

	//gotoxy(x - 15, y + 3);
	print_by_name("배서연, 하진, 이혜령");
	//printf("developed by 배서연, 하진, 이혜령");
	setBackColor(white, black);

	return keyControl(x, y, 1);
}

int maplistDraw() {
	int x = 58;
	int y = 14;
	int n;
	system("cls");
	printf("\n\n\t\t                         - - - - - - - - - - - - - - - - - - \n");
	printf("\t\t                        |                                    |\n");
	printf("\t\t                        |              [맵 선택]             |\n");
	printf("\t\t                        |                                    |\n");
	printf("\t\t                         - - - - - - - - - - - - - - - - - -");
	gotoxy(x - 2, y);
	printf("> Level 1");
	gotoxy(x, y + 1);
	printf("Level 2");
	gotoxy(x, y + 2);
	printf("Level 3");
	gotoxy(x, y + 3);
	printf("뒤로");
	printf("\n\n");
	printf("\t\t \t\t\t\t\t\t\t\t                     _ \n");
	printf("\t\t \t\t\t\t\t\t\t\t                    / ) \n");
	printf("\t\t \t\t\t\t\t\t\t\t                   ( ( \n");
	printf("\t\t \t\t\t\t\t\t\t\t     A.-.A  .-''-.  ) ) \n");
	printf("\t\t \t\t\t\t\t\t\t\t    / , , \\/      \\/ / \n");
	printf("\t\t \t\t\t\t\t\t\t\t    =\\  t  ;=    /  /\n");
	printf("\t\t \t\t\t\t\t\t\t\t     `--,'  . '' | / \n");
	printf("\t\t \t\t\t\t\t\t\t\t          || |  \\\\ \\ \n");
	printf("\t\t \t\t\t\t\t\t\t\t        ((,_|  ((,_\\ \n");
	printf("\t\t\t\t\t\t\t\t\t\t\t -----------------------");

	return keyControl(x, y, 3);
}

void endDraw() {
	PlaySound(NULL, 0, 0);
	system("cls");
	int x = 40, y = 5;	int input;
	gotoxy(x, y);
	printf("   _____ _    _  _____ _____ ______  _____ _____");
	gotoxy(x, y + 1);
	printf("  / ____| |  | |/ ____/ ____|  ____|/ ____/ ____|");
	gotoxy(x, y + 2);
	printf(" | (___ | |  | | |   | |    | |__  | (___| (___");
	gotoxy(x, y + 3);
	printf("  \\___ \\| |  | | |   | |    |  __|  \\___ \\\\___ \\");
	gotoxy(x, y + 4);
	printf("  ____) | |__| | |___| |____| |____ ____) |___) |");
	gotoxy(x, y + 5);
	printf(" |_____/ \\____/ \\_____\\_____|______|_____/_____/");
	gotoxy(x + 20, y + 7);
	printf("성공하셨습니다!");
	gotoxy(60, 23);
	printf(">돌아가기<");
	gotoxy(50, 25);
	setBackColor(yellow, black);
	printf("개발자 : 배서연, 이혜령, 하진");

	while (1) {
		input = _getch();
		if (input == ENTER) {
			system("cls");
			break;
		}
	}
}

void failDraw()
{
	PlaySound(NULL, 0, 0);
	int n;
	int x = 30, y = 8;
	system("cls");
	setBackColor(white, black);
	gotoxy(x, y);
	printf("    ___   _   __  __ ___    _____   _____ ___\n");
	gotoxy(x, y++);
	printf("   / __| /_\\ |  \\/  | __|  / _ \\ \\ / / __| _ \\ \n");
	gotoxy(x, y++);
	printf("  | (_ |/ _ \\| |\\/| | _|  | (_) \\ V /| _||   / \n");
	gotoxy(x, y++);
	printf("   \\___/_/ \\_\\_|  |_|___|  \\___/ \\_/ |___|_|_\\ \n");
	y += 3;
	x -= 5;
	gotoxy(x, y++);
	printf("\t시간 내에 탈출하지 못해서 사망하셨습니다. 엔터를 눌러서 돌아가십시오.");

	while (1) {
		n = _getch();
		if (n == ENTER) break;
	}
}

void gamerule()
{
	// 게임 방법 코드
	int x = 79, y = 4;
	setBackColor(white, black);
	gotoxy(x, y++);
	printf(" ===== 게임 방법 =====");
	gotoxy(x, y++);
	printf("|                     |");
	gotoxy(x, y++);
	printf("|  화살표를 움직여서  |");
	gotoxy(x, y++);
	printf("|       → ←↑↓     |");
	gotoxy(x, y++);
	printf("|  구슬을 움직이세요  |");
	gotoxy(x, y++);
	printf("|                     |");
	gotoxy(x, y++);
	printf("|   키 (*)를 모아서   |");
	gotoxy(x, y++);
	printf("|    잠긴 문(+)을     |");
	gotoxy(x, y++);
	printf("|     해제하세요      |");
	gotoxy(x, y++);
	printf("|                     |");
	gotoxy(x, y++);
	printf("|      도착지는       |");
	gotoxy(x, y++);
	printf("|      ○ 입니다      |");
	gotoxy(x, y++);
	printf("|                     |");
	gotoxy(x, y++);
	printf(" =====================");

}

//메인
int main_marble() {
	PlaySound(TEXT("./sound/marble.wav"), NULL, SND_ASYNC | SND_LOOP);
	system("title 구슬치기 ");
	CursorView();
	int level_num;
	while (1) {
		system("cls");
		titleDraw();
		if (!menuDraw()) {
			level_num = maplistDraw();
			if (level_num == 0)	gLoop(0);
			else if (level_num == 1) gLoop(1);
			else if (level_num == 2) gLoop(2);
		}
		else {
			system("cls");
			main();
			break;
		}
	}
	return 0;
}