#include "Rhythm.h"

// Ŀ��
void gotoxy(int x, int y)
{
    COORD Pos;
    Pos.X = 2 * x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

// ����, �ܼ� ũ��
void SetConsoleView()
{
    // ��üȭ�� ���
    SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
    system("title GGANBU");
}

//Ŀ�� �����
void CursorView()
{
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

// ���� ȭ��
void DrawReadyGame()
{
    system("cls");
    int x = 27, y = 15;

    gotoxy(x, y++);
    printf(" ::::::::      ::::::::         :::        ::::    :::    :::::::::     :::    ::: ");
    gotoxy(x, y++);
    printf(":+:    :+:    :+:    :+:      :+: :+:      :+:+:   :+:    :+:    :+:    :+:    :+: ");
    gotoxy(x, y++);
    printf("+:+           +:+            +:+   +:+     :+:+:+  +:+    +:+    +:+    +:+    +:+ ");
    gotoxy(x, y++);
    printf(":#:           :#:           +#++:++#++:    +#+ +:+ +#+    +#++:++#+     +#+    +:+ ");
    gotoxy(x, y++);
    printf("+#+   +#+#    +#+   +#+#    +#+     +#+    +#+  +#+#+#    +#+    +#+    +#+    +#+ ");
    gotoxy(x, y++);
    printf("#+#    #+#    #+#    #+#    #+#     #+#    #+#   #+#+#    #+#    #+#    #+#    #+# ");
    gotoxy(x, y++);
    printf(" ########      ########     ###     ###    ###    ####    #########      ########  ");


    gotoxy(44, 35);
    cout << "GameStart";
    gotoxy(44, 36);
    cout << "GameInfo";
    gotoxy(44, 37);
    cout << "Quit" << endl;

}

void DrawInfoGame()
{
    system("cls");

    gotoxy(7, 3);
    for (int i = 0; i < 80; i++) {
        printf("��");
    }

    gotoxy(7, 9);
    printf("�� Developer - ������ ( Sim Lee Jin )");

    gotoxy(7, 50);
    for (int i = 0; i < 80; i++) {
        printf("��");
    }
}

void DrawStartGame(const int life, const int score, const string questionStr, const string answerStr)
{
    system("cls");
    // ���� ȭ�� Ʋ
    gotoxy(4, 3);
    for (int i = 0; i < 130; i++) {
        printf("��");
    }
    gotoxy(0, 4);
    for (int i = 0; i < 46; i++) {
        printf("       ��\n");
    }
    gotoxy(0, 4);
    for (int i = 0; i < 46; i++) {
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  ��\n");
    }
    gotoxy(4, 50);
    for (int i = 0; i < 130; i++) {
        printf("��");
    }
    //--------------------

    gotoxy(80, 10);
    cout << "Life �� : " << life << " / " << LIFE;
    gotoxy(82, 15);
    cout << "Score : " << score;

    gotoxy(10, 10);
    cout << questionStr;
}

//���� ����
void DrawGameOver(const int playTime)
{
    gotoxy(8, 8);
    cout << "-------------------";
    gotoxy(8, 9);
    cout << "| G A M E O V E R |";
    gotoxy(8, 10);
    cout << " " << playTime << " sec";
    gotoxy(8, 11);
    cout << "-------------------";
    system("pause>null");
}

//����Ŀ��
void DrawUserCursor(int& y)
{
    if (y <= 0)
    {
        y = 0;
    }
    else if (y >= 2)
    {
        y = 2;
    }

    gotoxy(42, 35 + y);
    cout << "��";
}

MENU ReadyGame()
{
    int y = 0;
    int input = 0;
    while (true)
    {
        DrawReadyGame();
        DrawUserCursor(y);
        input = _getch();
        //�����
        if (input == MAGIC_KEY)
        {
            switch (_getch())
            {
            case UP:
                --y;
                break;
            case DOWN:
                ++y;
                break;
            }
        }
        else if (input == SPACE)
        {
            switch (y)
            {
            case 0:
                return GAMESTART;
            case 1:
                return INFO;
            case 2:
                return QUIT;
            }
        }
    }
}

void InfoGame()
{
    DrawInfoGame();
    system("pause>null");
}

void SetQuestion(vector<int>& questionVec, int level)
{
    if (level > MAX_LEVEL)
    {
        level = MAX_LEVEL;
    }

    int num = 0;
    srand((unsigned int)time(NULL));
    for (int i = 0; i < level; ++i)    //ȭ��ǥ�� ���� (���� ���̵�)
    {
        num = rand() % KEY_NUM;    //ȭ��ǥ ����.
        switch (num)
        {
        case 0:
            questionVec.push_back(UP);
            break;
        case 1:
            questionVec.push_back(RIGHT);
            break;
        case 2:
            questionVec.push_back(LEFT);
            break;
        case 3:
            questionVec.push_back(DOWN);
            break;
        }
    }
}

void VectorToString(const vector<int> v, string& str)
{
    for (int i = 0; i < static_cast<int>(v.size()); ++i)
    {
        switch (v[i])
        {
        case UP:
            str += "�� ";
            break;
        case DOWN:
            str += "�� ";
            break;
        case LEFT:
            str += "�� ";
            break;
        case RIGHT:
            str += "�� ";
            break;
        }
    }
}

bool CheckAnswer(const vector<int> questionVec, const vector<int> answerVec)
{
    //������ �迭�� ����.
    //���� üũ
    if (questionVec.size() != answerVec.size())
    {
        //���� �ٸ���
        return false;
    }

    //���빰 üũ
    for (int i = 0; i < static_cast<int>(questionVec.size()); ++i)
    {
        if (questionVec[i] != answerVec[i])
        {
            //�ٸ��� �ֳ�.
            return false;
        }
    }
    return true;
}

void StartGame()
{
    //PlaySound("HYP-Hit.wav", NULL, SND_NODEFAULT | SND_ASYNC | SND_LOOP);
    int life = LIFE;
    int score = 0;
    //��������� ����ð�.
    clock_t startTime, endTime;
    startTime = clock();

    //�����, d a w s
    //����
    vector<int> questionVec;
    string questionStr = "";
    //�����
    vector<int> answerVec;
    string answerStr = "";

    int firstInput = 0;
    int secondInput = 0;
    while (true)
    {
        int level = (score / 30) + 1;

        //������ ����
        SetQuestion(questionVec, level);
        //������ �����ֱ�.
        VectorToString(questionVec, questionStr);
        while (true)
        {
            //1������ ������ ������ Ǭ��.
            DrawStartGame(life, score, questionStr, answerStr);

            if (life == 0)
            {
                //���� �����϶� ����ð�
                endTime = clock();
                int playTime = static_cast<int>((endTime - startTime) / CLOCKS_PER_SEC);

                DrawGameOver(playTime);
                PlaySound(NULL, NULL, 0);
                return;
            }

            //���� �ϳ��� �Է�.
            firstInput = _getch();
            if (firstInput == MAGIC_KEY)
            {
                secondInput = _getch();
                answerVec.push_back(secondInput);
                switch (secondInput)
                {
                case UP:
                    answerStr += "�� ";
                    break;
                case DOWN:
                    answerStr += "�� ";
                    break;
                case LEFT:
                    answerStr += "�� ";
                    break;
                case RIGHT:
                    answerStr += "�� ";
                    break;
                }
            }
            else if (firstInput == SPACE)
            {
                //��� ����
                //��� Ȯ��
                if (CheckAnswer(questionVec, answerVec))
                {
                    score += 10;
                }
                else
                {
                    //Ʋ�ȴ�.
                    --life;
                    score -= 5;
                    if (score < 0)
                    {
                        score = 0;
                    }
                }

                questionVec.clear();
                questionStr = "";
                answerVec.clear();
                answerStr = "";
                break;
            }
        }
    }
}

int main(void)
{
    SetConsoleView();
    CursorView();
    while (true)
    {
        switch (ReadyGame())
        {
        case GAMESTART:
            StartGame();
            break;
        case INFO:
            InfoGame();
            break;
        case QUIT:
            return 0;
        }
    }
    return 0;
}