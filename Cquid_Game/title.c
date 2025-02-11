/* title.c */

#include "title.h"
#include "modules.h"


// 타이틀 화면 씬
void main_title() {

	system("cls");

	setColor1(MINT);
	for (int i = 0; i < titleHei; i++) {
		gotoxy1(SCREEN_WIDTH / 2 - titleWid / 2, 4 + i);
		puts(rhythm_title[i]);
	}

	print_by_name("심이진");

	/*setColor1(yellow1);
	const wchar_t title[] = L"Developed by 심이진";
	gotoxy1((SCREEN_WIDTH - (int)wcslen(title)) / 2, 4 + titleHei + 1);
	wprintf(L"%s", title);*/

	setColor(white1);
	int x = 5;
	int y = 13;
	print_auto_y(&x, &y, "    ⊂_＼");
	print_auto_y(&x, &y, "	＼＼ Λ＿Λ");
	print_auto_y(&x, &y, "	  ＼(ˇωˇ)    둠칫");
	print_auto_y(&x, &y, "	      > ⌒`");
	print_auto_y(&x, &y, "	      / へ＼");
	print_auto_y(&x, &y, "	     /　/＼＼");
	print_auto_y(&x, &y, "	     /  ノ　＼_つ");
	print_auto_y(&x, &y, "	    /  /");
	print_auto_y(&x, &y, "둠칫     /　/|");
	print_auto_y(&x, &y, "	  (   (`");
	print_auto_y(&x, &y, "	  | |、＼");
	print_auto_y(&x, &y, "	  | | ＼ ⌒)");
	print_auto_y(&x, &y, "	  | |　　) /");
	print_auto_y(&x, &y, "	 ノ )　　L/");
	print_auto_y(&x, &y, "      (___/     둠칫");

	setColor(RED);
	x = 28;
	y = 15;
	print_auto_y(&x, &y, " ￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣");
	print_auto_y(&x, &y, "|　게임 발생!　　　　　　　　　　　　　　　　　　 　[－][口][×] |");
	print_auto_y(&x, &y, "|￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣|");
	print_auto_y(&x, &y, "|　세상에서 정말 어려운 리듬게임을 실행하셨습니다! 　　　        |");
	print_auto_y(&x, &y, "|　정말인가요?　　　　　　　　　　　　　　　　　　　　　　　　 　|");
	print_auto_y(&x, &y, "|　　　　＿＿＿＿＿　　　　＿＿＿＿＿＿　　　　＿＿＿＿＿　　　  |");
	print_auto_y(&x, &y, "| 　　　｜예　　   |　　　｜아마도?　　｜ 　 　|예　 　 |　  　  |");
	print_auto_y(&x, &y, "|　　　　￣￣￣￣￣　　　　￣￣￣￣￣￣　　　　￣￣￣￣￣　　　  |");
	print_auto_y(&x, &y, "￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣");
	
	setColor(YELLOW);
	x = 43;
	y = 25;
	print_auto_y(&x, &y, "[ 시작하려면 아무 키를 누르십시오 ]");


	setColor(WHITE);
	x = 100;
	y = 15;
	print_auto_y(&x, &y, " ∧,,∧ !!!!");
	print_auto_y(&x, &y, "( 'ω' )つ");
	print_auto_y(&x, &y, "（m9  ＼ ");
	print_auto_y(&x, &y, "　 ＼　 ＼ ");
	print_auto_y(&x, &y, "　 　) ) ＼");
	print_auto_y(&x, &y, "　  ／／＼ ＼");
	print_auto_y(&x, &y, "　 (＿） (＿)");


	gotoxy1(SCREEN_WIDTH / 2, 4 + titleHei + 5);
	setCursor(UNDERBAR);
	clearBuffer();

	int _ = _getch();
}
