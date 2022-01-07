#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>



// Salam Mellim Indiden bu qeder uzun yazdigim ucun uzr isteyirem
// Kodun bezi yerlerinde Komentler yazmisam ozum ucun onlari silmedim Ozum Yazdigim belli olsun deye
// onsuzda Kohne versiyalarinida Atiram ev tapsiriqinda  bu proyekti pramoy bizim pacman oyununun ustune qurdum


using namespace std;

void mySetColor(int fg, int bg) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, fg | (bg << 4));
}

struct Point {
	int y;
	int x;
};

enum Direction { UP = 72, DOWN = 80, RIGHT = 77, LEFT = 75 };
int game[14][14] = {};
int gameSize = 16; // Divarlar daxil olmaqla oyunun umumi olcusu 
int playerX = 6; // figurlarin baslangic noqtesi
int playerY = 0;// figurlarin baslangic noqtesi
int Player = 5;   // Player == 5 Array icerisinde figurlarin oldugu yerler 5 Deye kecir 
int Score = 0;  // player in score u 
bool isTrue = false;  // rotate count Funksiyasi duzgun islesin deyedir
bool isTrue1 = false; // rotate count Funksiyasi duzgun islesin deyedir
bool isTrue2 = false; // rotate count Funksiyasi duzgun islesin deyedir
bool isTrue3 = false; // rotate count Funksiyasi duzgun islesin deyedir
bool isTrue4 = false; // rotate count Funksiyasi duzgun islesin deyedir
bool isTrue5 = false; // rotate count Funksiyasi duzgun islesin deyedir
char PlayAgain;  // oyuncudan Tezden oynamaq isteyib istemediyini sorusur 
int random = 1 + rand() % (7);  // bu random 1 Figurlardir 
int random2 = 1 + rand() % (7); // bu random 2 figurlar displayde ekrana cixsin deyedir 
bool isStoped = false;   // Figure En alt qatmana veya altinda figur olanda diyandigini belli olsun deye 
bool GameOver = false;  // oyunu uduzmaq 

bool isTrueBlock = false;  // yadda deyil? 
int IndexHolder = 0; // figurlar yan yana duzulende Onun Y Uzerindeki Kordinatini saxlayir
int blockCounter = 0; // Figurlarin yanyana olup olmadigini yoxlayir
int rotateCount = 0;  // figurun Rotate inin hansi formada oldugunu saxlayir 

void display() {
	for (int i = 0; i < gameSize; i++)
	{
		for (int k = 0; k < gameSize; k++)
		{
			if (k == 0)
			{

				cout << (char)254 << "";
			}
			else if (i == 0 || i == gameSize - 1 || k == gameSize - 1) {
				cout << (char)254 << " ";
			}
			else {
				if (game[i - 1][k - 1] == 0) {
					cout << "  ";
				}
				else if (game[i - 1][k - 1] == 5) {
					mySetColor(2, 0);
					cout << "[]" << "";
					mySetColor(7, 0);
				}

			}
			if (i == 3 && k == gameSize - 1)
			{
				mySetColor(4, 0);
				cout << "SCORE:" << Score;
				mySetColor(7, 0);
			}
			if (random2 == 1)
			{
				if (i == 5 && k == gameSize - 1) { cout << "Next Figure -> "; mySetColor(1, 0); cout << "[][][]"; mySetColor(7, 0); }
				else if (i == 6 && k == gameSize - 1) { mySetColor(1, 0); cout << "                 []"; mySetColor(7, 0); }
			}
			else if (random2 == 2)
			{
				if (i == 5 && k == gameSize - 1) { cout << "Next Figure -> "; mySetColor(1, 0); cout << "[][]"; mySetColor(7, 0); }
				else if (i == 6 && k == gameSize - 1) { mySetColor(1, 0); cout << "               [][]"; mySetColor(7, 0); }
			}
			else if (random2 == 3)
			{
				if (i == 5 && k == gameSize - 1) { cout << "Next Figure -> "; mySetColor(1, 0); cout << "[]"; mySetColor(7, 0); }
				else if (i == 6 && k == gameSize - 1) { mySetColor(1, 0); cout << "               []"; mySetColor(7, 0); }
				else if (i == 7 && k == gameSize - 1) { mySetColor(1, 0); cout << "               []"; mySetColor(7, 0); }
				else if (i == 8 && k == gameSize - 1) { mySetColor(1, 0); cout << "               []"; mySetColor(7, 0); }

			}
			else if (random2 == 4)
			{
				if (i == 5 && k == gameSize - 1) { cout << "Next Figure -> "; mySetColor(1, 0); cout << "[][]"; mySetColor(7, 0); }
				else if (i == 6 && k == gameSize - 1) { mySetColor(1, 0); cout << "                 [][]"; mySetColor(7, 0); }

			}
			else if (random2 == 5)
			{
				if (i == 5 && k == gameSize - 1) { cout << "Next Figure -> "; mySetColor(1, 0); cout << "  [][]"; mySetColor(7, 0); }
				else if (i == 6 && k == gameSize - 1) { mySetColor(1, 0); cout << "               [][]"; mySetColor(7, 0); }

			}
			else if (random2 == 6)
			{
				if (i == 5 && k == gameSize - 1) { cout << "Next Figure -> "; mySetColor(1, 0); cout << "[]"; mySetColor(7, 0); }
				else if (i == 6 && k == gameSize - 1) { mySetColor(1, 0); cout << "               []"; mySetColor(7, 0); }
				else if (i == 7 && k == gameSize - 1) { mySetColor(1, 0); cout << "             [][]"; mySetColor(7, 0); }

			}
			else if (random2 == 7)
			{
				if (i == 5 && k == gameSize - 1) { cout << "Next Figure -> "; mySetColor(1, 0); cout << "[]"; mySetColor(7, 0); }
				else if (i == 6 && k == gameSize - 1) { mySetColor(1, 0); cout << "               []"; mySetColor(7, 0); }
				else if (i == 7 && k == gameSize - 1) { mySetColor(1, 0); cout << "               [][]"; mySetColor(7, 0); }

			}


		}cout << endl;
	}
}


void control() {
	if (isStoped == true)
	{
		random = random2;
		random2 = 1 + rand() % (7);


	}
	while (true)
	{
		if (isStoped == true) //oyunun uduzub uduzmadigini yoxlayir
		{
			for (int i = 0; i < gameSize - 2; i++)
			{
				if (game[1][i] == 5) {
					system("cls");
					display();
					GameOver = true;
					break;
				}
			}
			if (GameOver)
			{
				break;
			}


		}

		if (isStoped == true) // figurlarin yan yana olub olmadigini yoxlayir
		{


			for (int i = 0; i <= gameSize - 2; i++)
			{
				for (int j = 0; j < gameSize - 2; j++)
				{
					if (game[i][j] == 5) {
						blockCounter++;
						IndexHolder = i;
					}

				}
				if (blockCounter == gameSize - 2)
				{
					for (int g = 0; g < gameSize - 2; g++)
					{

						game[IndexHolder][g] = 0;
						Score += 5;


						system("cls");
						display();
					}
					for (int y = 0; y < gameSize - 2; y++)
					{
						for (int x = 0; x < gameSize - 2; x++)
						{
							game[IndexHolder - y][x] = game[IndexHolder - y - 1][x];

						}

					}
					system("cls");
					display();


				}
				blockCounter = 0;

			}
		}
		isStoped = false;


		int key = _getch();
		if (key == 82 || key == 114)
		{
			rotateCount += 1;
			if (rotateCount >= 4)
			{
				rotateCount = 0;

			}

		}
		if (random == 1)    // Figure T   [][][]
							//              []
		{

			if (rotateCount == 0)
			{
				if (game[playerY][playerX - 1] == 5 && isTrue1 == false || // burdaki -2 ni -1 edeceksen unutma YAPILDI
					playerX - 1 < 0 && isTrue1 == false)
				{
					rotateCount = 3;
					continue;
				}
				isTrue2 = false;
				if (isTrue1 == false)
				{
					game[playerY][playerX] = 0;
					game[playerY][playerX - 1] = 0;
					game[playerY + 1][playerX] = 0;
					game[playerY - 1][playerX] = 0;
					isTrue1 = true;
				}
				game[playerY][playerX] = Player;
				game[playerY][playerX + 1] = Player;
				game[playerY][playerX - 1] = Player;
				game[playerY + 1][playerX] = Player;


				system("cls");
				display();
				if (key != 224)
				{
					key = _getch();

				}


				if (key == 224) {

					game[playerY][playerX] = 0;
					game[playerY][playerX + 1] = 0;
					game[playerY][playerX - 1] = 0;
					game[playerY + 1][playerX] = 0;
					key = _getch();



					if (key == DOWN) {
						if (playerY + 2 == gameSize - 2) continue;
						playerY++;
					}
					else if (key == RIGHT) {
						if (playerX + 2 == gameSize - 2 || game[playerY][playerX + 2] == 5) continue;
						playerX++;
					}
					else if (key == LEFT) {
						if (playerX - 2 < 0 || game[playerY][playerX - 2] == 5) continue;
						playerX--;
					}

					game[playerY][playerX] = Player;
					game[playerY][playerX + 1] = Player;
					game[playerY][playerX - 1] = Player;
					game[playerY + 1][playerX] = Player;


					if (playerY + 2 == gameSize - 2 ||
						game[playerY + 2][playerX] == 5 ||
						game[playerY + 1][playerX - 1] == 5 ||
						game[playerY + 1][playerX + 1] == 5) {
						system("cls");
						display();
						key = _getch();
						if (key == 224) {
							game[playerY][playerX] = 0;
							game[playerY][playerX - 1] = 0;
							game[playerY + 1][playerX] = 0;
							game[playerY][playerX + 1] = 0;
							key = _getch();
							if (key == DOWN) {
								if (playerY + 2 == gameSize - 2 || game[playerY + 2][playerX] == 5 ||
									game[playerY + 1][playerX - 1] == 5 || game[playerY + 1][playerX + 1] == 5) {

									game[playerY][playerX] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY + 1][playerX] = Player;
									game[playerY][playerX + 1] = Player;
									isStoped = true;
									break;
								}
								playerY++;
							}
							else if (key == RIGHT) {
								if (playerX + 2 == gameSize - 2 || game[playerY][playerX + 2] == 5 ||
									game[playerY + 1][playerX + 1] == 5) {

									game[playerY][playerX] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY + 1][playerX] = Player;
									game[playerY][playerX + 1] = Player;
									isStoped = true;
									break;
								}
								playerX++;
							}
							else if (key == LEFT) {
								if (playerX - 2 < 0 || game[playerY][playerX - 2] == 5 ||
									game[playerY + 1][playerX - 1] == 5) {
									game[playerY][playerX] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY + 1][playerX] = Player;
									game[playerY][playerX + 1] = Player;
									isStoped = true;
									break;
								}
								playerX--;
							}

							game[playerY][playerX] = Player;
							game[playerY][playerX - 1] = Player;
							game[playerY + 1][playerX] = Player;
							game[playerY][playerX + 1] = Player;
							system("cls");
							display();
						}
						if (playerY + 2 == gameSize - 2 ||
							game[playerY + 2][playerX] == 5 ||
							game[playerY + 1][playerX - 1] == 5 ||
							game[playerY + 1][playerX + 1] == 5) {
							isStoped = true;
							break;
						}
					}

					game[playerY][playerX] = 0;
					game[playerY][playerX + 1] = 0;
					game[playerY][playerX - 1] = 0;
					game[playerY + 1][playerX] = 0;
					if (key != DOWN
						)
					{
						playerY += 1;

					}


					game[playerY][playerX] = Player;
					game[playerY][playerX + 1] = Player;
					game[playerY][playerX - 1] = Player;
					game[playerY + 1][playerX] = Player;
					if (playerY + 2 == gameSize - 2 ||
						game[playerY + 2][playerX] == 5 ||
						game[playerY + 1][playerX - 1] == 5 ||
						game[playerY + 1][playerX + 1] == 5) {
						system("cls");
						display();
						key = _getch();
						if (key == 224) {
							game[playerY][playerX] = 0;
							game[playerY][playerX - 1] = 0;
							game[playerY + 1][playerX] = 0;
							game[playerY][playerX + 1] = 0;
							key = _getch();
							if (key == DOWN) {
								if (playerY + 2 == gameSize - 2 || game[playerY + 2][playerX] == 5 ||
									game[playerY + 1][playerX - 1] == 5 || game[playerY + 1][playerX + 1] == 5) {

									game[playerY][playerX] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY + 1][playerX] = Player;
									game[playerY][playerX + 1] = Player;
									isStoped = true;
									break;
								}
								playerY++;
							}
							else if (key == RIGHT) {
								if (playerX + 2 == gameSize - 2 || game[playerY][playerX + 2] == 5 ||
									game[playerY + 1][playerX + 1] == 5) {

									game[playerY][playerX] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY + 1][playerX] = Player;
									game[playerY][playerX + 1] = Player;
									isStoped = true;
									break;
								}
								playerX++;
							}
							else if (key == LEFT) {
								if (playerX - 2 < 0 || game[playerY][playerX - 2] == 5 ||
									game[playerY + 1][playerX - 1] == 5) {
									game[playerY][playerX] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY + 1][playerX] = Player;
									game[playerY][playerX + 1] = Player;
									isStoped = true;
									break;
								}
								playerX--;
							}
							game[playerY][playerX] = Player;
							game[playerY][playerX - 1] = Player;
							game[playerY + 1][playerX] = Player;
							game[playerY][playerX + 1] = Player;
							system("cls");
							display();
						}
						if (playerY + 2 == gameSize - 2 ||
							game[playerY + 2][playerX] == 5 ||
							game[playerY + 1][playerX - 1] == 5 ||
							game[playerY + 1][playerX + 1] == 5) {
							isStoped = true;
							break;
						}
					}


				}


			}
			else if (rotateCount == 1)
			{
				if (game[playerY - 1][playerX] == 5 && isTrue2 == false)
				{
					rotateCount = 0;
					continue;
				}
				isTrue3 = false;
				if (isTrue2 == false)
				{


					game[playerY][playerX] = 0;
					game[playerY][playerX + 1] = 0;
					game[playerY][playerX - 1] = 0;
					game[playerY + 1][playerX] = 0;
					isTrue2 = true;
				}


				game[playerY][playerX] = Player;
				game[playerY][playerX - 1] = Player;
				game[playerY + 1][playerX] = Player;
				game[playerY - 1][playerX] = Player;
				system("cls");
				display();
				if (key != 224)
				{
					key = _getch();

				}


				if (key == 224) {

					game[playerY][playerX] = 0;
					game[playerY][playerX - 1] = 0;
					game[playerY + 1][playerX] = 0;
					game[playerY - 1][playerX] = 0;
					key = _getch();


					if (key == UP) {
						if (playerY - 2 < 0) continue;
						else playerY--;
					}
					else if (key == DOWN) {
						if (playerY + 2 == gameSize - 2) continue;
						playerY++;
					}
					else if (key == RIGHT) {
						if (playerX + 1 == gameSize - 2 || game[playerY][playerX + 1] == 5 ||
							game[playerY + 1][playerX + 1] == 5 || game[playerY - 1][playerX + 1] == 5) continue;
						playerX++;
					}
					else if (key == LEFT) {
						if (playerX - 2 < 0 || game[playerY][playerX - 2] == 5 ||
							game[playerY + 1][playerX - 1] == 5 || game[playerY - 1][playerX - 1] == 5) continue;
						playerX--;
					}

					game[playerY][playerX] = Player;
					game[playerY][playerX - 1] = Player;
					game[playerY + 1][playerX] = Player;
					game[playerY - 1][playerX] = Player;

					if (playerY + 2 == gameSize - 2 ||
						game[playerY + 2][playerX] == 5 ||
						game[playerY + 1][playerX - 1] == 5) {

						system("cls");
						display();
						key = _getch();
						if (key == 224) {
							game[playerY][playerX] = 0;
							game[playerY][playerX - 1] = 0;
							game[playerY + 1][playerX] = 0;
							game[playerY - 1][playerX] = 0;
							key = _getch();
							if (key == DOWN) {
								if (playerY + 2 == gameSize - 2 || game[playerY + 2][playerX] == 5 ||
									game[playerY + 1][playerX - 1] == 5) {
									game[playerY][playerX] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY + 1][playerX] = Player;
									game[playerY - 1][playerX] = Player;
									isStoped = true;
									break;
								}
								playerY++;
							}

							else if (key == RIGHT) {
								if (playerX + 1 == gameSize - 2 || game[playerY][playerX + 1] == 5 ||
									game[playerY + 1][playerX + 1] == 5 || game[playerY - 1][playerX + 1] == 5) {

									game[playerY][playerX] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY + 1][playerX] = Player;
									game[playerY - 1][playerX] = Player;
									isStoped = true;
									break;
								}
								playerX++;
							}
							else if (key == LEFT) {
								if (playerX - 2 < 0 || game[playerY][playerX - 2] == 5 ||
									game[playerY + 1][playerX - 1] == 5 || game[playerY - 1][playerX - 1] == 5) {

									game[playerY][playerX] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY + 1][playerX] = Player;
									game[playerY - 1][playerX] = Player;
									isStoped = true;
									break;
								}
								playerX--;
							}
							game[playerY][playerX] = Player;
							game[playerY][playerX - 1] = Player;
							game[playerY + 1][playerX] = Player;
							game[playerY - 1][playerX] = Player;
							system("cls");
							display();
						}
						if (playerY + 2 == gameSize - 2 ||
							game[playerY + 2][playerX] == 5 ||
							game[playerY + 1][playerX - 1] == 5) {
							isStoped = true;
							break;
						}
					}
					game[playerY][playerX] = 0;
					game[playerY][playerX - 1] = 0;
					game[playerY + 1][playerX] = 0;
					game[playerY - 1][playerX] = 0;
					if (key != DOWN
						)
					{
						playerY += 1;

					}
					game[playerY][playerX] = Player;
					game[playerY][playerX - 1] = Player;
					game[playerY + 1][playerX] = Player;
					game[playerY - 1][playerX] = Player;

					if (playerY + 2 == gameSize - 2 ||
						game[playerY + 2][playerX] == 5 ||
						game[playerY + 1][playerX - 1] == 5) {

						system("cls");
						display();
						key = _getch();
						if (key == 224) {
							game[playerY][playerX] = 0;
							game[playerY][playerX - 1] = 0;
							game[playerY + 1][playerX] = 0;
							game[playerY - 1][playerX] = 0;
							key = _getch();
							if (key == DOWN) {
								if (playerY + 2 == gameSize - 2 || game[playerY + 2][playerX] == 5 ||
									game[playerY + 1][playerX - 1] == 5) {
									game[playerY][playerX] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY + 1][playerX] = Player;
									game[playerY - 1][playerX] = Player;
									isStoped = true;
									break;
								}
								playerY++;
							}

							else if (key == RIGHT) {
								if (playerX + 1 == gameSize - 2 || game[playerY][playerX + 1] == 5 ||
									game[playerY + 1][playerX + 1] == 5 || game[playerY - 1][playerX + 1] == 5) {

									game[playerY][playerX] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY + 1][playerX] = Player;
									game[playerY - 1][playerX] = Player;
									isStoped = true;
									break;
								}
								playerX++;
							}
							else if (key == LEFT) {
								if (playerX - 2 < 0 || game[playerY][playerX - 2] == 5 ||
									game[playerY + 1][playerX - 1] == 5 || game[playerY - 1][playerX - 1] == 5) {

									game[playerY][playerX] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY + 1][playerX] = Player;
									game[playerY - 1][playerX] = Player;
									isStoped = true;
									break;
								}
								playerX--;
							}
							game[playerY][playerX] = Player;
							game[playerY][playerX - 1] = Player;
							game[playerY + 1][playerX] = Player;
							game[playerY - 1][playerX] = Player;
							system("cls");
							display();
						}
						if (playerY + 2 == gameSize - 2 ||
							game[playerY + 2][playerX] == 5 ||
							game[playerY + 1][playerX - 1] == 5) {
							isStoped = true;
							break;
						}
					}





				}
			}
			else if (rotateCount == 2)
			{
				if (game[playerY][playerX + 1] == 5 && isTrue3 == false ||
					playerX + 1 == gameSize - 2 && isTrue3 == false)
				{
					rotateCount--;
					continue;
				}
				isTrue4 = false;
				if (isTrue3 == false)
				{


					game[playerY][playerX] = 0;
					game[playerY][playerX - 1] = 0;
					game[playerY - 1][playerX] = 0;
					game[playerY + 1][playerX] = 0;
					isTrue3 = true;
				}


				game[playerY][playerX] = Player;
				game[playerY][playerX - 1] = Player;
				game[playerY - 1][playerX] = Player;
				game[playerY][playerX + 1] = Player;
				system("cls");
				display();
				if (key != 224)
				{
					key = _getch();

				}


				if (key == 224) {

					game[playerY][playerX] = 0;
					game[playerY][playerX - 1] = 0;
					game[playerY - 1][playerX] = 0;
					game[playerY][playerX + 1] = 0;
					key = _getch();



					if (key == DOWN) {
						if (playerY + 1 == gameSize - 2) continue;
						playerY++;
					}
					else if (key == RIGHT) {
						if (playerX + 2 == gameSize - 2 || game[playerY][playerX + 2] == 5) continue;
						playerX++;
					}
					else if (key == LEFT) {
						if (playerX - 2 < 0 || game[playerY][playerX - 2] == 5) continue;
						playerX--;
					}

					game[playerY][playerX] = Player;
					game[playerY][playerX - 1] = Player;
					game[playerY - 1][playerX] = Player;
					game[playerY][playerX + 1] = Player;

					if (playerY + 1 == gameSize - 2 ||
						game[playerY + 1][playerX] == 5 ||
						game[playerY + 1][playerX - 1] == 5 ||
						game[playerY + 1][playerX + 1] == 5) {
						system("cls");
						display();
						key = _getch();
						if (key == 224) {
							game[playerY][playerX] = 0;
							game[playerY][playerX - 1] = 0;
							game[playerY - 1][playerX] = 0;
							game[playerY][playerX + 1] = 0;
							key = _getch();
							if (key == DOWN) {
								if (playerY + 1 == gameSize - 2 || game[playerY + 1][playerX] == 5 || game[playerY + 1][playerX + 1] == 5 || game[playerY + 1][playerX - 1] == 5) {
									game[playerY][playerX] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY - 1][playerX] = Player;
									game[playerY][playerX + 1] = Player;
									isStoped = true;
									break;
								}
								playerY++;
							}
							else if (key == RIGHT) {
								if (playerX + 2 == gameSize - 2 || game[playerY][playerX + 2] == 5) {
									game[playerY][playerX] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY - 1][playerX] = Player;
									game[playerY][playerX + 1] = Player;
									isStoped = true;
									break;
								}
								playerX++;
							}
							else if (key == LEFT) {
								if (playerX - 2 < 0 || game[playerY][playerX - 2] == 5) {
									game[playerY][playerX] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY - 1][playerX] = Player;
									game[playerY][playerX + 1] = Player;
									isStoped = true;
									break;
								}
								playerX--;
							}
							game[playerY][playerX] = Player;
							game[playerY][playerX - 1] = Player;
							game[playerY - 1][playerX] = Player;
							game[playerY][playerX + 1] = Player;
						}
						if (playerY + 1 == gameSize - 2 ||
							game[playerY + 1][playerX] == 5 ||
							game[playerY + 1][playerX - 1] == 5 ||
							game[playerY + 1][playerX + 1] == 5) {
							isStoped = true;
							break;
						}
					}
					game[playerY][playerX] = 0;
					game[playerY][playerX - 1] = 0;
					game[playerY - 1][playerX] = 0;
					game[playerY][playerX + 1] = 0;
					if (key != DOWN
						)
					{
						playerY += 1;

					}


					game[playerY][playerX] = Player;
					game[playerY][playerX - 1] = Player;
					game[playerY - 1][playerX] = Player;
					game[playerY][playerX + 1] = Player;

					if (playerY + 1 == gameSize - 2 ||
						game[playerY + 1][playerX] == 5 ||
						game[playerY + 1][playerX - 1] == 5 ||
						game[playerY + 1][playerX + 1] == 5) {
						system("cls");
						display();
						key = _getch();
						if (key == 224) {
							game[playerY][playerX] = 0;
							game[playerY][playerX - 1] = 0;
							game[playerY - 1][playerX] = 0;
							game[playerY][playerX + 1] = 0;
							key = _getch();
							if (key == DOWN) {
								if (playerY + 1 == gameSize - 2 || game[playerY + 1][playerX] == 5 || game[playerY + 1][playerX + 1] == 5 || game[playerY + 1][playerX - 1] == 5) {
									game[playerY][playerX] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY - 1][playerX] = Player;
									game[playerY][playerX + 1] = Player;
									isStoped = true;
									break;
								}
								playerY++;
							}
							else if (key == RIGHT) {
								if (playerX + 2 == gameSize - 2 || game[playerY][playerX + 2] == 5) {
									game[playerY][playerX] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY - 1][playerX] = Player;
									game[playerY][playerX + 1] = Player;
									isStoped = true;
									break;
								}
								playerX++;
							}
							else if (key == LEFT) {
								if (playerX - 2 < 0 || game[playerY][playerX - 2] == 5) {
									game[playerY][playerX] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY - 1][playerX] = Player;
									game[playerY][playerX + 1] = Player;
									isStoped = true;
									break;
								}
								playerX--;
							}
							game[playerY][playerX] = Player;
							game[playerY][playerX - 1] = Player;
							game[playerY - 1][playerX] = Player;
							game[playerY][playerX + 1] = Player;
						}
						if (playerY + 1 == gameSize - 2 ||
							game[playerY + 1][playerX] == 5 ||
							game[playerY + 1][playerX - 1] == 5 ||
							game[playerY + 1][playerX + 1] == 5) {
							isStoped = true;
							break;
						}
					}


				}
			}
			else if (rotateCount == 3)
			{
				if (game[playerY + 1][playerX] == 5 && isTrue4 == false ||
					playerY + 1 == gameSize - 2 && isTrue4 == false)
				{
					rotateCount--;
					continue;
				}
				isTrue1 = false;
				if (isTrue4 == false)
				{


					game[playerY][playerX] = 0;
					game[playerY][playerX - 1] = 0;
					game[playerY - 1][playerX] = 0;
					game[playerY][playerX + 1] = 0;
					isTrue4 = true;
				}


				game[playerY][playerX] = Player;
				game[playerY - 1][playerX] = Player;
				game[playerY][playerX + 1] = Player;
				game[playerY + 1][playerX] = Player;
				system("cls");
				display();
				if (key != 224)
				{
					key = _getch();

				}


				if (key == 224) {

					game[playerY][playerX] = 0;
					game[playerY - 1][playerX] = 0;
					game[playerY][playerX + 1] = 0;
					game[playerY + 1][playerX] = 0;
					key = _getch();



					if (key == DOWN) {
						if (playerY + 2 == gameSize - 2) continue;
						playerY++;
					}
					else if (key == RIGHT) {
						if (playerX + 2 == gameSize - 2 || game[playerY][playerX + 2] == 5 ||
							game[playerY + 1][playerX + 1] == 5 || game[playerY - 1][playerX + 1] == 5) continue;
						playerX++;
					}
					else if (key == LEFT) {
						if (playerX - 1 < 0 || game[playerY][playerX - 1] == 5 ||
							game[playerY - 1][playerX - 1] == 5 || game[playerY + 1][playerX - 1] == 5) continue;
						playerX--;
					}

					game[playerY][playerX] = Player;
					game[playerY - 1][playerX] = Player;
					game[playerY][playerX + 1] = Player;
					game[playerY + 1][playerX] = Player;

					if (playerY + 2 == gameSize - 2 ||
						game[playerY + 2][playerX] == 5 ||
						game[playerY + 1][playerX + 1] == 5) {
						system("cls");
						display();
						key = _getch();
						if (key == 224) {
							game[playerY][playerX] = 0;
							game[playerY - 1][playerX] = 0;
							game[playerY][playerX + 1] = 0;
							game[playerY + 1][playerX] = 0;
							key = _getch();
							if (key == DOWN) {
								if (playerY + 2 == gameSize - 2 || game[playerY + 2][playerX] == 5 ||
									game[playerY + 1][playerX + 1] == 5) {

									game[playerY][playerX] = Player;
									game[playerY - 1][playerX] = Player;
									game[playerY][playerX + 1] = Player;
									game[playerY + 1][playerX] = Player;
									isStoped = true;
									break;
								}
								playerY++;
							}
							else if (key == RIGHT) {
								if (playerX + 2 == gameSize - 2 || game[playerY][playerX + 2] == 5 ||
									game[playerY + 1][playerX + 1] == 5 || game[playerY - 1][playerX + 1] == 5) {

									game[playerY][playerX] = Player;
									game[playerY - 1][playerX] = Player;
									game[playerY][playerX + 1] = Player;
									game[playerY + 1][playerX] = Player;
									isStoped = true;
									break;
								}
								playerX++;
							}
							else if (key == LEFT) {
								if (playerX - 1 < 0 || game[playerY][playerX - 1] == 5 ||
									game[playerY - 1][playerX - 1] == 5 || game[playerY + 1][playerX - 1] == 5) {

									game[playerY][playerX] = Player;
									game[playerY - 1][playerX] = Player;
									game[playerY][playerX + 1] = Player;
									game[playerY + 1][playerX] = Player;
									isStoped = true;
									break;
								}
								playerX--;
							}
							game[playerY][playerX] = Player;
							game[playerY - 1][playerX] = Player;
							game[playerY][playerX + 1] = Player;
							game[playerY + 1][playerX] = Player;
						}
						if (playerY + 2 == gameSize - 2 ||
							game[playerY + 2][playerX] == 5 ||
							game[playerY + 1][playerX + 1] == 5) {
							isStoped = true;
							break;
						}
					}
					game[playerY][playerX] = 0;
					game[playerY - 1][playerX] = 0;
					game[playerY][playerX + 1] = 0;
					game[playerY + 1][playerX] = 0;
					if (key != DOWN
						)
					{
						playerY += 1;

					}
					game[playerY][playerX] = Player;
					game[playerY - 1][playerX] = Player;
					game[playerY][playerX + 1] = Player;
					game[playerY + 1][playerX] = Player;

					if (playerY + 2 == gameSize - 2 ||
						game[playerY + 2][playerX] == 5 ||
						game[playerY + 1][playerX + 1] == 5) {
						system("cls");
						display();
						key = _getch();
						if (key == 224) {
							game[playerY][playerX] = 0;
							game[playerY - 1][playerX] = 0;
							game[playerY][playerX + 1] = 0;
							game[playerY + 1][playerX] = 0;
							key = _getch();
							if (key == DOWN) {
								if (playerY + 2 == gameSize - 2 || game[playerY + 2][playerX] == 5 ||
									game[playerY + 1][playerX + 1] == 5) {

									game[playerY][playerX] = Player;
									game[playerY - 1][playerX] = Player;
									game[playerY][playerX + 1] = Player;
									game[playerY + 1][playerX] = Player;
									isStoped = true;
									break;
								}
								playerY++;
							}
							else if (key == RIGHT) {
								if (playerX + 2 == gameSize - 2 || game[playerY][playerX + 2] == 5 ||
									game[playerY + 1][playerX + 1] == 5 || game[playerY - 1][playerX + 1] == 5) {

									game[playerY][playerX] = Player;
									game[playerY - 1][playerX] = Player;
									game[playerY][playerX + 1] = Player;
									game[playerY + 1][playerX] = Player;
									isStoped = true;
									break;
								}
								playerX++;
							}
							else if (key == LEFT) {
								if (playerX - 1 < 0 || game[playerY][playerX - 1] == 5 ||
									game[playerY - 1][playerX - 1] == 5 || game[playerY + 1][playerX - 1] == 5) {

									game[playerY][playerX] = Player;
									game[playerY - 1][playerX] = Player;
									game[playerY][playerX + 1] = Player;
									game[playerY + 1][playerX] = Player;
									isStoped = true;
									break;
								}
								playerX--;
							}
							game[playerY][playerX] = Player;
							game[playerY - 1][playerX] = Player;
							game[playerY][playerX + 1] = Player;
							game[playerY + 1][playerX] = Player;
						}
						if (playerY + 2 == gameSize - 2 ||
							game[playerY + 2][playerX] == 5 ||
							game[playerY + 1][playerX + 1] == 5) {
							isStoped = true;
							break;
						}
					}


				}
				system("cls");
				display();
			}
		}
		else if (random == 2) {   // Figure [][]
								 //         [][] 
			if (true) {
				game[playerY][playerX] = Player;
				game[playerY][playerX + 1] = Player;
				game[playerY + 1][playerX] = Player;
				game[playerY + 1][playerX + 1] = Player;
				system("cls");
				display();
				if (key != 224)
				{
					key = _getch();

				}


				if (key == 224) {

					game[playerY][playerX] = 0;
					game[playerY][playerX + 1] = 0;
					game[playerY + 1][playerX] = 0;
					game[playerY + 1][playerX + 1] = 0;
					key = _getch();

					if (key == DOWN) {
						if (playerY + 2 == gameSize - 2) continue;
						playerY++;
					}
					else if (key == RIGHT) {
						if (playerX + 2 == gameSize - 2 || game[playerY][playerX + 2] == 5 ||
							game[playerY + 1][playerX + 2] == 5) continue;
						playerX++;
					}
					else if (key == LEFT) {
						if (playerX - 1 < 0 || game[playerY][playerX - 1] == 5 ||
							game[playerY + 1][playerX - 1] == 5) continue;
						playerX--;
					}
					game[playerY][playerX] = Player;
					game[playerY][playerX + 1] = Player;
					game[playerY + 1][playerX] = Player;
					game[playerY + 1][playerX + 1] = Player;

					if (playerY + 2 == gameSize - 2 ||
						game[playerY + 2][playerX] == 5 ||
						game[playerY + 2][playerX + 1] == 5) {
						system("cls");
						display();
						key = _getch();
						if (key == 224) {
							game[playerY][playerX] = 0;
							game[playerY][playerX + 1] = 0;
							game[playerY + 1][playerX] = 0;
							game[playerY + 1][playerX + 1] = 0;
							key = _getch();

							if (key == DOWN) {
								if (playerY + 2 == gameSize - 2 || game[playerY + 2][playerX] == 5 || game[playerY + 2][playerX + 1] == 5)
								{
									game[playerY][playerX] = Player;
									game[playerY][playerX + 1] = Player;
									game[playerY + 1][playerX] = Player;
									game[playerY + 1][playerX + 1] = Player;
									isStoped = true;
									break;
								}
								playerY++;
							}
							else if (key == RIGHT) {
								if (playerX + 2 == gameSize - 2 || game[playerY][playerX + 2] == 5 ||
									game[playerY + 1][playerX + 2] == 5) {
									game[playerY][playerX] = Player;
									game[playerY][playerX + 1] = Player;
									game[playerY + 1][playerX] = Player;
									game[playerY + 1][playerX + 1] = Player;
									isStoped = true;
									break;

								}
								playerX++;
							}
							else if (key == LEFT) {
								if (playerX - 1 < 0 || game[playerY][playerX - 1] == 5 ||
									game[playerY + 1][playerX - 1] == 5) {
									game[playerY][playerX] = Player;
									game[playerY][playerX + 1] = Player;
									game[playerY + 1][playerX] = Player;
									game[playerY + 1][playerX + 1] = Player;
									isStoped = true;
									break;
								}
								playerX--;
							}
							game[playerY][playerX] = Player;
							game[playerY][playerX + 1] = Player;
							game[playerY + 1][playerX] = Player;
							game[playerY + 1][playerX + 1] = Player;
							if (playerY + 2 == gameSize - 2 ||
								game[playerY + 2][playerX] == 5 ||
								game[playerY + 2][playerX + 1] == 5)
							{
								game[playerY][playerX] = Player;
								game[playerY][playerX + 1] = Player;
								game[playerY + 1][playerX] = Player;
								game[playerY + 1][playerX + 1] = Player;
								isStoped = true;
								break;
							}

						}



					}
					game[playerY][playerX] = 0;
					game[playerY][playerX + 1] = 0;
					game[playerY + 1][playerX] = 0;
					game[playerY + 1][playerX + 1] = 0;
					if (key != DOWN)
					{
						playerY++;

					}
					game[playerY][playerX] = Player;
					game[playerY][playerX + 1] = Player;
					game[playerY + 1][playerX] = Player;
					game[playerY + 1][playerX + 1] = Player;

					if (playerY + 2 == gameSize - 2 ||
						game[playerY + 2][playerX] == 5 ||
						game[playerY + 2][playerX + 1] == 5) {
						system("cls");
						display();
						key = _getch();
						if (key == 224) {
							game[playerY][playerX] = 0;
							game[playerY][playerX + 1] = 0;
							game[playerY + 1][playerX] = 0;
							game[playerY + 1][playerX + 1] = 0;
							key = _getch();

							if (key == DOWN) {
								if (playerY + 2 == gameSize - 2 || game[playerY + 2][playerX] == 5 || game[playerY + 2][playerX + 1] == 5)
								{
									game[playerY][playerX] = Player;
									game[playerY][playerX + 1] = Player;
									game[playerY + 1][playerX] = Player;
									game[playerY + 1][playerX + 1] = Player;
									isStoped = true;
									break;
								}
								playerY++;
							}
							else if (key == RIGHT) {
								if (playerX + 2 == gameSize - 2 || game[playerY][playerX + 2] == 5 ||
									game[playerY + 1][playerX + 2] == 5) {
									game[playerY][playerX] = Player;
									game[playerY][playerX + 1] = Player;
									game[playerY + 1][playerX] = Player;
									game[playerY + 1][playerX + 1] = Player;
									isStoped = true;
									break;

								}
								playerX++;
							}
							else if (key == LEFT) {
								if (playerX - 1 < 0 || game[playerY][playerX - 1] == 5 ||
									game[playerY + 1][playerX - 1] == 5) {
									game[playerY][playerX] = Player;
									game[playerY][playerX + 1] = Player;
									game[playerY + 1][playerX] = Player;
									game[playerY + 1][playerX + 1] = Player;
									isStoped = true;
									break;
								}
								playerX--;
							}
							game[playerY][playerX] = Player;
							game[playerY][playerX + 1] = Player;
							game[playerY + 1][playerX] = Player;
							game[playerY + 1][playerX + 1] = Player;
							if (playerY + 2 == gameSize - 2 ||
								game[playerY + 2][playerX] == 5 ||
								game[playerY + 2][playerX + 1] == 5)
							{
								game[playerY][playerX] = Player;
								game[playerY][playerX + 1] = Player;
								game[playerY + 1][playerX] = Player;
								game[playerY + 1][playerX + 1] = Player;
								isStoped = true;
								break;
							}

						}
					}






				}
			}       //         [][]
		}
		else if (random == 3)  // Figure []
							  //         []
							 //          []
							//           []
		{
			if (rotateCount == 0 || rotateCount == 2)
			{


				if (game[playerY + 1][playerX] == 5 && isTrue1 == false ||
					game[playerY + 2][playerX] == 5 && isTrue1 == false ||
					game[playerY - 1][playerX] == 5 && isTrue1 == false ||
					playerY + 2 >= gameSize - 2 && isTrue1 == false
					)
				{
					rotateCount = 3;
					continue;
				}
				isTrue2 = false;
				if (isTrue1 == false)
				{


					game[playerY][playerX] = 0;
					game[playerY][playerX + 1] = 0;
					game[playerY][playerX + 2] = 0;
					game[playerY][playerX - 1] = 0;
					isTrue1 = true;
				}


				game[playerY][playerX] = Player;
				game[playerY + 1][playerX] = Player;
				game[playerY - 1][playerX] = Player;
				game[playerY + 2][playerX] = Player;
				system("cls");
				display();
				if (key != 224)
				{
					key = _getch();

				}


				if (key == 224) {

					game[playerY][playerX] = 0;
					game[playerY + 1][playerX] = 0;
					game[playerY - 1][playerX] = 0;
					game[playerY + 2][playerX] = 0;
					key = _getch();



					if (key == DOWN) {
						if (playerY + 3 == gameSize - 2) continue;
						playerY++;
					}
					else if (key == RIGHT) {
						if (playerX + 1 == gameSize - 2 ||
							game[playerY][playerX + 1] == 5 ||
							game[playerY + 1][playerX + 1] == 5 ||
							game[playerY + 2][playerX + 1] == 5 ||
							game[playerY - 1][playerX + 1] == 5) continue;
						playerX++;
					}
					else if (key == LEFT) {
						if (playerX - 1 < 0 ||
							game[playerY][playerX + 1] == 5 ||
							game[playerY + 1][playerX - 1] == 5 ||
							game[playerY + 2][playerX - 1] == 5 ||
							game[playerY - 1][playerX - 1] == 5) continue;
						playerX--;
					}

					game[playerY][playerX] = Player;
					game[playerY + 1][playerX] = Player;
					game[playerY - 1][playerX] = Player;
					game[playerY + 2][playerX] = Player;

					if (playerY + 3 == gameSize - 2 ||
						game[playerY + 3][playerX] == 5) {

						system("cls");
						display();
						key = _getch();
						if (key == 224) {
							game[playerY][playerX] = 0;
							game[playerY + 1][playerX] = 0;
							game[playerY - 1][playerX] = 0;
							game[playerY + 2][playerX] = 0;
							key = _getch();
							if (key == DOWN) {
								if (playerY + 3 == gameSize - 2 ||
									game[playerY + 3][playerX] == 5) {

									game[playerY][playerX] = Player;
									game[playerY + 1][playerX] = Player;
									game[playerY - 1][playerX] = Player;
									game[playerY + 2][playerX] = Player;
									isStoped = true;
									break;
								}
								playerY++;
							}

							else if (key == RIGHT) {
								if (playerX + 1 == gameSize - 2 ||
									game[playerY][playerX + 1] == 5 ||
									game[playerY + 1][playerX + 1] == 5 ||
									game[playerY + 2][playerX + 1] == 5 ||
									game[playerY - 1][playerX + 1] == 5) {

									game[playerY][playerX] = Player;
									game[playerY + 1][playerX] = Player;
									game[playerY - 1][playerX] = Player;
									game[playerY + 2][playerX] = Player;
									isStoped = true;
									break;
								}
								playerX++;
							}
							else if (key == LEFT) {
								if (playerX - 1 < 0 ||
									game[playerY][playerX - 1] == 5 ||
									game[playerY + 1][playerX - 1] == 5 ||
									game[playerY + 2][playerX - 1] == 5 ||
									game[playerY - 1][playerX - 1] == 5) {

									game[playerY][playerX] = Player;
									game[playerY + 1][playerX] = Player;
									game[playerY - 1][playerX] = Player;
									game[playerY + 2][playerX] = Player;
									isStoped = true;
									break;
								}
								playerX--;
							}
							game[playerY][playerX] = Player;
							game[playerY + 1][playerX] = Player;
							game[playerY - 1][playerX] = Player;
							game[playerY + 2][playerX] = Player;
							system("cls");
							display();
						}
						if (playerY + 3 == gameSize - 2 ||
							game[playerY + 3][playerX] == 5) {
							isStoped = true;
							break;
						}
					}
					game[playerY][playerX] = 0;
					game[playerY + 1][playerX] = 0;
					game[playerY - 1][playerX] = 0;
					game[playerY + 2][playerX] = 0;
					if (key != DOWN)
					{
						playerY++;
					}
					game[playerY][playerX] = Player;
					game[playerY + 1][playerX] = Player;
					game[playerY - 1][playerX] = Player;
					game[playerY + 2][playerX] = Player;
					if (playerY + 3 == gameSize - 2 ||
						game[playerY + 3][playerX] == 5) {

						system("cls");
						display();
						key = _getch();
						if (key == 224) {
							game[playerY][playerX] = 0;
							game[playerY + 1][playerX] = 0;
							game[playerY - 1][playerX] = 0;
							game[playerY + 2][playerX] = 0;
							key = _getch();
							if (key == DOWN) {
								if (playerY + 3 == gameSize - 2 ||
									game[playerY + 3][playerX] == 5) {

									game[playerY][playerX] = Player;
									game[playerY + 1][playerX] = Player;
									game[playerY - 1][playerX] = Player;
									game[playerY + 2][playerX] = Player;
									isStoped = true;
									break;
								}
								playerY++;
							}

							else if (key == RIGHT) {
								if (playerX + 1 == gameSize - 2 ||
									game[playerY][playerX + 1] == 5 ||
									game[playerY + 1][playerX + 1] == 5 ||
									game[playerY + 2][playerX + 1] == 5 ||
									game[playerY - 1][playerX + 1] == 5) {

									game[playerY][playerX] = Player;
									game[playerY + 1][playerX] = Player;
									game[playerY - 1][playerX] = Player;
									game[playerY + 2][playerX] = Player;
									isStoped = true;
									break;
								}
								playerX++;
							}
							else if (key == LEFT) {
								if (playerX - 1 < 0 ||
									game[playerY][playerX - 1] == 5 ||
									game[playerY + 1][playerX - 1] == 5 ||
									game[playerY + 2][playerX - 1] == 5 ||
									game[playerY - 1][playerX - 1] == 5) {

									game[playerY][playerX] = Player;
									game[playerY + 1][playerX] = Player;
									game[playerY - 1][playerX] = Player;
									game[playerY + 2][playerX] = Player;
									isStoped = true;
									break;
								}
								playerX--;
							}
							game[playerY][playerX] = Player;
							game[playerY + 1][playerX] = Player;
							game[playerY - 1][playerX] = Player;
							game[playerY + 2][playerX] = Player;
							system("cls");
							display();
						}
						if (playerY + 3 == gameSize - 2 ||
							game[playerY + 3][playerX] == 5) {
							isStoped = true;
							break;
						}
					}


				}//key 224 scope
			}//rotate scope
			if (rotateCount == 1 || rotateCount == 3)
			{


				if (game[playerY][playerX - 1] == 5 && isTrue2 == false ||
					game[playerY][playerX + 1] == 5 && isTrue2 == false ||
					game[playerY][playerX + 2] == 5 && isTrue2 == false ||
					playerX + 2 >= gameSize - 2 && isTrue2 == false ||
					playerX - 1 < 0 && isTrue2 == false
					)
				{
					rotateCount = 2;
					continue;
				}
				isTrue1 = false;
				if (isTrue2 == false)
				{


					game[playerY][playerX] = 0;
					game[playerY + 1][playerX] = 0;
					game[playerY - 1][playerX] = 0;
					game[playerY + 2][playerX] = 0;
					isTrue2 = true;
				}


				game[playerY][playerX] = Player;
				game[playerY][playerX + 1] = Player;
				game[playerY][playerX + 2] = Player;
				game[playerY][playerX - 1] = Player;
				system("cls");
				display();
				if (key != 224)
				{
					key = _getch();

				}


				if (key == 224) {

					game[playerY][playerX] = 0;
					game[playerY][playerX + 1] = 0;
					game[playerY][playerX + 2] = 0;
					game[playerY][playerX - 1] = 0;
					key = _getch();



					if (key == DOWN) {
						if (playerY + 1 == gameSize - 2) continue;
						playerY++;
					}
					else if (key == RIGHT) {
						if (playerX + 3 == gameSize - 2 ||
							game[playerY][playerX + 3] == 5) continue;
						playerX++;
					}
					else if (key == LEFT) {
						if (playerX - 2 < 0 ||
							game[playerY][playerX - 2] == 5) continue;
						playerX--;
					}

					game[playerY][playerX] = Player;
					game[playerY][playerX + 1] = Player;
					game[playerY][playerX + 2] = Player;
					game[playerY][playerX - 1] = Player;

					if (playerY + 1 == gameSize - 2 ||
						game[playerY + 1][playerX] == 5 ||
						game[playerY + 1][playerX + 1] == 5 ||
						game[playerY + 1][playerX + 2] == 5 ||
						game[playerY + 1][playerX - 1] == 5

						) {

						system("cls");
						display();
						key = _getch();
						if (key == 224) {
							game[playerY][playerX] = 0;
							game[playerY][playerX + 1] = 0;
							game[playerY][playerX + 2] = 0;
							game[playerY][playerX - 1] = 0;
							key = _getch();
							if (key == DOWN) {
								if (playerY + 1 == gameSize - 2 ||
									game[playerY + 1][playerX] == 5 ||
									game[playerY + 1][playerX + 1] == 5 ||
									game[playerY + 1][playerX + 2] == 5 ||
									game[playerY + 1][playerX - 1] == 5
									) {

									game[playerY][playerX] = Player;
									game[playerY][playerX + 1] = Player;
									game[playerY][playerX + 2] = Player;
									game[playerY][playerX - 1] = Player;
									isStoped = true;
									break;
								}
								playerY++;
							}

							else if (key == RIGHT) {
								if (playerX + 3 == gameSize - 2 ||
									game[playerY][playerX + 3] == 5) {

									game[playerY][playerX] = Player;
									game[playerY][playerX + 1] = Player;
									game[playerY][playerX + 2] = Player;
									game[playerY][playerX - 1] = Player;
									isStoped = true;
									break;
								}
								playerX++;
							}
							else if (key == LEFT) {
								if (playerX - 2 < 0 ||
									game[playerY][playerX - 2] == 5) {

									game[playerY][playerX] = Player;
									game[playerY][playerX + 1] = Player;
									game[playerY][playerX + 2] = Player;
									game[playerY][playerX - 1] = Player;
									isStoped = true;
									break;
								}
								playerX--;
							}
							game[playerY][playerX] = Player;
							game[playerY][playerX + 1] = Player;
							game[playerY][playerX + 2] = Player;
							game[playerY][playerX - 1] = Player;
							system("cls");
							display();
						}
						if (playerY + 1 == gameSize - 2 ||
							game[playerY + 1][playerX] == 5 ||
							game[playerY + 1][playerX + 1] == 5 ||
							game[playerY + 1][playerX + 2] == 5 ||
							game[playerY + 1][playerX - 1] == 5) {
							isStoped = true;
							break;
						}
					}
					game[playerY][playerX] = 0;
					game[playerY][playerX + 1] = 0;
					game[playerY][playerX + 2] = 0;
					game[playerY][playerX - 1] = 0;
					if (key != DOWN)
					{
						playerY++;
					}
					game[playerY][playerX] = Player;
					game[playerY][playerX + 1] = Player;
					game[playerY][playerX + 2] = Player;
					game[playerY][playerX - 1] = Player;
					if (playerY + 1 == gameSize - 2 ||
						game[playerY + 1][playerX] == 5 ||
						game[playerY + 1][playerX + 1] == 5 ||
						game[playerY + 1][playerX + 2] == 5 ||
						game[playerY + 1][playerX - 1] == 5

						) {

						system("cls");
						display();
						key = _getch();
						if (key == 224) {
							game[playerY][playerX] = 0;
							game[playerY][playerX + 1] = 0;
							game[playerY][playerX + 2] = 0;
							game[playerY][playerX - 1] = 0;
							key = _getch();
							if (key == DOWN) {
								if (playerY + 1 == gameSize - 2 ||
									game[playerY + 1][playerX] == 5 ||
									game[playerY + 1][playerX + 1] == 5 ||
									game[playerY + 1][playerX + 2] == 5 ||
									game[playerY + 1][playerX - 1] == 5
									) {

									game[playerY][playerX] = Player;
									game[playerY][playerX + 1] = Player;
									game[playerY][playerX + 2] = Player;
									game[playerY][playerX - 1] = Player;
									isStoped = true;
									break;
								}
								playerY++;
							}

							else if (key == RIGHT) {
								if (playerX + 3 == gameSize - 2 ||
									game[playerY][playerX + 3] == 5) {

									game[playerY][playerX] = Player;
									game[playerY][playerX + 1] = Player;
									game[playerY][playerX + 2] = Player;
									game[playerY][playerX - 1] = Player;
									isStoped = true;
									break;
								}
								playerX++;
							}
							else if (key == LEFT) {
								if (playerX - 2 < 0 ||
									game[playerY][playerX - 2] == 5) {

									game[playerY][playerX] = Player;
									game[playerY][playerX + 1] = Player;
									game[playerY][playerX + 2] = Player;
									game[playerY][playerX - 1] = Player;
									isStoped = true;
									break;
								}
								playerX--;
							}
							game[playerY][playerX] = Player;
							game[playerY][playerX + 1] = Player;
							game[playerY][playerX + 2] = Player;
							game[playerY][playerX - 1] = Player;
							system("cls");
							display();
						}
						if (playerY + 1 == gameSize - 2 ||
							game[playerY + 1][playerX] == 5 ||
							game[playerY + 1][playerX + 1] == 5 ||
							game[playerY + 1][playerX + 2] == 5 ||
							game[playerY + 1][playerX - 1] == 5) {
							isStoped = true;
							break;
						}
					}


				}//key 224 scope
			}//rotate scope

		} //random 3 scope
		else if (random == 4) // figure [][]
							  //          [][]
		{

			if (rotateCount == 0 || rotateCount == 2)
			{


				if (game[playerY + 1][playerX] == 5 && isTrue1 == false ||
					game[playerY + 1][playerX + 1] == 5 && isTrue1 == false ||
					playerX + 1 == gameSize - 2 && isTrue1 == false)
				{
					rotateCount = 3;
					continue;
				}
				isTrue2 = false;
				if (isTrue1 == false)
				{
					game[playerY][playerX] = 0;
					game[playerY][playerX - 1] = 0;
					game[playerY + 1][playerX - 1] = 0;
					game[playerY - 1][playerX] = 0;
					isTrue1 = true;
				}
				game[playerY][playerX] = Player;
				game[playerY][playerX - 1] = Player;
				game[playerY + 1][playerX] = Player;
				game[playerY + 1][playerX + 1] = Player;


				system("cls");
				display();
				if (key != 224)
				{
					key = _getch();

				}


				if (key == 224) {

					game[playerY][playerX] = 0;
					game[playerY][playerX - 1] = 0;
					game[playerY + 1][playerX] = 0;
					game[playerY + 1][playerX + 1] = 0;
					key = _getch();



					if (key == DOWN) {
						if (playerY + 2 == gameSize - 2) continue;
						playerY++;
					}
					else if (key == RIGHT) {
						if (playerX + 2 == gameSize - 2 || game[playerY][playerX + 1] == 5 ||
							game[playerY + 1][playerX + 2] == 5) continue;
						playerX++;
					}
					else if (key == LEFT) {
						if (playerX - 2 < 0 || game[playerY][playerX - 2] == 5 ||
							game[playerY + 1][playerX - 1] == 5) continue;
						playerX--;
					}

					game[playerY][playerX] = Player;
					game[playerY][playerX - 1] = Player;
					game[playerY + 1][playerX] = Player;
					game[playerY + 1][playerX + 1] = Player;

					if (playerY + 2 == gameSize - 2 ||
						game[playerY + 2][playerX] == 5 ||
						game[playerY + 1][playerX - 1] == 5 ||
						game[playerY + 2][playerX + 1] == 5) {
						system("cls");
						display();
						key = _getch();
						if (key == 224) {
							game[playerY][playerX] = 0;
							game[playerY][playerX - 1] = 0;
							game[playerY + 1][playerX] = 0;
							game[playerY + 1][playerX + 1] = 0;
							key = _getch();
							if (key == DOWN) {
								if (playerY + 2 == gameSize - 2 ||
									game[playerY + 2][playerX] == 5 ||
									game[playerY + 1][playerX - 1] == 5 ||
									game[playerY + 2][playerX + 1] == 5) {

									game[playerY][playerX] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY + 1][playerX] = Player;
									game[playerY + 1][playerX + 1] = Player;
									isStoped = true;
									break;
								}
								playerY++;
							}
							else if (key == RIGHT) {
								if (playerX + 2 == gameSize - 2 ||
									game[playerY][playerX + 1] == 5 ||
									game[playerY + 1][playerX + 2] == 5) {

									game[playerY][playerX] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY + 1][playerX] = Player;
									game[playerY + 1][playerX + 1] = Player;
									isStoped = true;
									break;
								}
								playerX++;
							}
							else if (key == LEFT) {
								if (playerX - 2 < 0 || game[playerY][playerX - 2] == 5 ||
									game[playerY + 1][playerX - 1] == 5) {


									game[playerY][playerX] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY + 1][playerX] = Player;
									game[playerY + 1][playerX + 1] = Player;
									isStoped = true;
									break;
								}
								playerX--;
							}
							game[playerY][playerX] = Player;
							game[playerY][playerX - 1] = Player;
							game[playerY + 1][playerX] = Player;
							game[playerY + 1][playerX + 1] = Player;
							system("cls");
							display();
						}
						if (playerY + 2 == gameSize - 2 ||
							game[playerY + 2][playerX] == 5 ||
							game[playerY + 1][playerX - 1] == 5 ||
							game[playerY + 2][playerX + 1] == 5) {
							isStoped = true;
							break;
						}
					}

					game[playerY][playerX] = 0;
					game[playerY][playerX - 1] = 0;
					game[playerY + 1][playerX] = 0;
					game[playerY + 1][playerX + 1] = 0;
					if (key != DOWN
						)
					{
						playerY += 1;

					}
					game[playerY][playerX] = Player;
					game[playerY][playerX - 1] = Player;
					game[playerY + 1][playerX] = Player;
					game[playerY + 1][playerX + 1] = Player;
					if (playerY + 2 == gameSize - 2 ||
						game[playerY + 2][playerX] == 5 ||
						game[playerY + 1][playerX - 1] == 5 ||
						game[playerY + 2][playerX + 1] == 5) {
						system("cls");
						display();
						key = _getch();
						if (key == 224) {
							game[playerY][playerX] = 0;
							game[playerY][playerX - 1] = 0;
							game[playerY + 1][playerX] = 0;
							game[playerY + 1][playerX + 1] = 0;
							key = _getch();
							if (key == DOWN) {
								if (playerY + 2 == gameSize - 2 ||
									game[playerY + 2][playerX] == 5 ||
									game[playerY + 1][playerX - 1] == 5 ||
									game[playerY + 2][playerX + 1] == 5) {

									game[playerY][playerX] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY + 1][playerX] = Player;
									game[playerY + 1][playerX + 1] = Player;
									isStoped = true;
									break;
								}
								playerY++;
							}
							else if (key == RIGHT) {
								if (playerX + 2 == gameSize - 2 ||
									game[playerY][playerX + 1] == 5 ||
									game[playerY + 1][playerX + 2] == 5) {

									game[playerY][playerX] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY + 1][playerX] = Player;
									game[playerY + 1][playerX + 1] = Player;
									isStoped = true;
									break;
								}
								playerX++;
							}
							else if (key == LEFT) {
								if (playerX - 2 < 0 || game[playerY][playerX - 2] == 5 ||
									game[playerY + 1][playerX - 1] == 5) {


									game[playerY][playerX] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY + 1][playerX] = Player;
									game[playerY + 1][playerX + 1] = Player;
									isStoped = true;
									break;
								}
								playerX--;
							}
							game[playerY][playerX] = Player;
							game[playerY][playerX - 1] = Player;
							game[playerY + 1][playerX] = Player;
							game[playerY + 1][playerX + 1] = Player;
							system("cls");
							display();
						}
						if (playerY + 2 == gameSize - 2 ||
							game[playerY + 2][playerX] == 5 ||
							game[playerY + 1][playerX - 1] == 5 ||
							game[playerY + 2][playerX + 1] == 5) {
							isStoped = true;
							break;
						}
					}

				}// key 224 scope
			}//rotate count 0 scope
			if (rotateCount == 1 || rotateCount == 3)
			{


				if (game[playerY - 1][playerX] == 5 && isTrue2 == false ||
					game[playerY + 1][playerX - 1] == 5 && isTrue2 == false) //sanki bi hata var buraya dikkat et sonra bak
				{
					rotateCount = 0;
					continue;
				}
				isTrue1 = false;
				if (isTrue2 == false)
				{


					game[playerY][playerX] = 0;
					game[playerY][playerX - 1] = 0;
					game[playerY + 1][playerX] = 0;
					game[playerY + 1][playerX + 1] = 0;
					isTrue2 = true;
				}
				game[playerY][playerX] = Player;
				game[playerY][playerX - 1] = Player;
				game[playerY + 1][playerX - 1] = Player;
				game[playerY - 1][playerX] = Player;


				system("cls");
				display();
				if (key != 224)
				{
					key = _getch();

				}


				if (key == 224) {

					game[playerY][playerX] = 0;
					game[playerY][playerX - 1] = 0;
					game[playerY + 1][playerX - 1] = 0;
					game[playerY - 1][playerX] = 0;
					key = _getch();



					if (key == DOWN) {
						if (playerY + 2 == gameSize - 2) continue;
						playerY++;
					}
					else if (key == RIGHT) {
						if (playerX + 1 == gameSize - 2 || game[playerY][playerX + 1] == 5 ||
							game[playerY + 1][playerX] == 5 || game[playerY - 1][playerX + 1] == 5) continue;
						playerX++;
					}
					else if (key == LEFT) {
						if (playerX - 2 < 0 || game[playerY][playerX - 2] == 5 ||
							game[playerY + 1][playerX - 2] == 5 || game[playerY - 1][playerX - 1] == 5) continue;
						playerX--;
					}
					game[playerY][playerX] = Player;
					game[playerY][playerX - 1] = Player;
					game[playerY + 1][playerX - 1] = Player;
					game[playerY - 1][playerX] = Player;

					if (playerY + 2 == gameSize - 2 ||
						game[playerY + 1][playerX] == 5 ||
						game[playerY + 2][playerX - 1] == 5) {
						system("cls");
						display();
						key = _getch();
						if (key == 224) {
							game[playerY][playerX] = 0;
							game[playerY][playerX - 1] = 0;
							game[playerY + 1][playerX - 1] = 0;
							game[playerY - 1][playerX] = 0;
							key = _getch();
							if (key == DOWN) {
								if (playerY + 2 == gameSize - 2 ||
									game[playerY + 1][playerX] == 5 ||
									game[playerY + 2][playerX - 1] == 5
									) {

									game[playerY][playerX] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY + 1][playerX - 1] = Player;
									game[playerY - 1][playerX] = Player;
									isStoped = true;
									break;
								}
								playerY++;
							}
							else if (key == RIGHT) {
								if (playerX + 1 == gameSize - 2 || game[playerY][playerX + 1] == 5 ||
									game[playerY + 1][playerX] == 5 || game[playerY - 1][playerX + 1] == 5) {

									game[playerY][playerX] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY + 1][playerX - 1] = Player;
									game[playerY - 1][playerX] = Player;
									isStoped = true;
									break;
								}
								playerX++;
							}
							else if (key == LEFT) {
								if (playerX - 2 < 0 || game[playerY][playerX - 2] == 5 ||
									game[playerY + 1][playerX - 2] == 5 || game[playerY - 1][playerX - 1] == 5) {


									game[playerY][playerX] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY + 1][playerX - 1] = Player;
									game[playerY - 1][playerX] = Player;
									isStoped = true;
									break;
								}
								playerX--;
							}
							game[playerY][playerX] = Player;
							game[playerY][playerX - 1] = Player;
							game[playerY + 1][playerX - 1] = Player;
							game[playerY - 1][playerX] = Player;
							system("cls");
							display();
						}
						if (playerY + 2 == gameSize - 2 ||
							game[playerY + 1][playerX] == 5 ||
							game[playerY + 2][playerX - 1] == 5) {
							isStoped = true;
							break;
						}
					}

					game[playerY][playerX] = 0;
					game[playerY][playerX - 1] = 0;
					game[playerY + 1][playerX - 1] = 0;
					game[playerY - 1][playerX] = 0;
					if (key != DOWN
						)
					{
						playerY += 1;

					}
					game[playerY][playerX] = Player;
					game[playerY][playerX - 1] = Player;
					game[playerY + 1][playerX - 1] = Player;
					game[playerY - 1][playerX] = Player;
					if (playerY + 2 == gameSize - 2 ||
						game[playerY + 1][playerX] == 5 ||
						game[playerY + 2][playerX - 1] == 5) {
						system("cls");
						display();
						key = _getch();
						if (key == 224) {
							game[playerY][playerX] = 0;
							game[playerY][playerX - 1] = 0;
							game[playerY + 1][playerX - 1] = 0;
							game[playerY - 1][playerX] = 0;
							key = _getch();
							if (key == DOWN) {
								if (playerY + 2 == gameSize - 2 ||
									game[playerY + 1][playerX] == 5 ||
									game[playerY + 2][playerX - 1] == 5
									) {

									game[playerY][playerX] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY + 1][playerX - 1] = Player;
									game[playerY - 1][playerX] = Player;
									isStoped = true;
									break;
								}
								playerY++;
							}
							else if (key == RIGHT) {
								if (playerX + 1 == gameSize - 2 || game[playerY][playerX + 1] == 5 ||
									game[playerY + 1][playerX] == 5 || game[playerY - 1][playerX + 1] == 5) {

									game[playerY][playerX] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY + 1][playerX - 1] = Player;
									game[playerY - 1][playerX] = Player;
									isStoped = true;
									break;
								}
								playerX++;
							}
							else if (key == LEFT) {
								if (playerX - 2 < 0 || game[playerY][playerX - 2] == 5 ||
									game[playerY + 1][playerX - 2] == 5 || game[playerY - 1][playerX - 1] == 5) {


									game[playerY][playerX] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY + 1][playerX - 1] = Player;
									game[playerY - 1][playerX] = Player;
									isStoped = true;
									break;
								}
								playerX--;
							}
							game[playerY][playerX] = Player;
							game[playerY][playerX - 1] = Player;
							game[playerY + 1][playerX - 1] = Player;
							game[playerY - 1][playerX] = Player;
							system("cls");
							display();
						}
						if (playerY + 2 == gameSize - 2 ||
							game[playerY + 1][playerX] == 5 ||
							game[playerY + 2][playerX - 1] == 5) {
							isStoped = true;
							break;
						}
					}

				}// key 224 scope
			}
		}//random 4 scope
		else if (random == 5)
		{

			if (rotateCount == 0 || rotateCount == 2)
			{


				if (game[playerY - 1][playerX] == 5 && isTrue1 == false ||
					game[playerY - 1][playerX + 1] == 5 && isTrue1 == false ||
					playerX + 1 == gameSize - 2 && isTrue1 == false)
				{
					rotateCount = 3;
					continue;
				}
				isTrue2 = false;
				if (isTrue1 == false)
				{
					game[playerY][playerX] = 0;
					game[playerY][playerX - 1] = 0;
					game[playerY + 1][playerX] = 0;
					game[playerY - 1][playerX - 1] = 0;
					isTrue1 = true;
				}
				game[playerY][playerX] = Player;
				game[playerY][playerX - 1] = Player;
				game[playerY - 1][playerX] = Player;
				game[playerY - 1][playerX + 1] = Player;


				system("cls");
				display();
				if (key != 224)
				{
					key = _getch();

				}


				if (key == 224) {

					game[playerY][playerX] = 0;
					game[playerY][playerX - 1] = 0;
					game[playerY - 1][playerX] = 0;
					game[playerY - 1][playerX + 1] = 0;
					key = _getch();



					if (key == DOWN) {
						if (playerY + 1 == gameSize - 2) continue;
						playerY++;
					}
					else if (key == RIGHT) {
						if (playerX + 2 == gameSize - 2 || game[playerY][playerX + 1] == 5 ||
							game[playerY - 1][playerX + 2] == 5) continue;
						playerX++;
					}
					else if (key == LEFT) {
						if (playerX - 2 < 0 || game[playerY][playerX - 2] == 5 ||
							game[playerY - 1][playerX - 1] == 5) continue;
						playerX--;
					}

					game[playerY][playerX] = Player;
					game[playerY][playerX - 1] = Player;
					game[playerY - 1][playerX] = Player;
					game[playerY - 1][playerX + 1] = Player;

					if (playerY + 1 == gameSize - 2 ||
						game[playerY + 1][playerX] == 5 ||
						game[playerY + 1][playerX - 1] == 5 ||
						game[playerY][playerX + 1] == 5) {
						system("cls");
						display();
						key = _getch();
						if (key == 224) {
							game[playerY][playerX] = 0;
							game[playerY][playerX - 1] = 0;
							game[playerY - 1][playerX] = 0;
							game[playerY - 1][playerX + 1] = 0;
							key = _getch();
							if (key == DOWN) {
								if (playerY + 1 == gameSize - 2 ||
									game[playerY + 1][playerX] == 5 ||
									game[playerY + 1][playerX - 1] == 5 ||
									game[playerY][playerX + 1] == 5) {

									game[playerY][playerX] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY - 1][playerX] = Player;
									game[playerY - 1][playerX + 1] = Player;
									isStoped = true;
									break;
								}
								playerY++;
							}
							else if (key == RIGHT) {
								if (playerX + 2 == gameSize - 2 || game[playerY][playerX + 1] == 5 ||
									game[playerY - 1][playerX + 2] == 5) {

									game[playerY][playerX] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY - 1][playerX] = Player;
									game[playerY - 1][playerX + 1] = Player;
									isStoped = true;
									break;
								}
								playerX++;
							}
							else if (key == LEFT) {
								if (playerX - 2 < 0 || game[playerY][playerX - 2] == 5 ||
									game[playerY - 1][playerX - 1] == 5) {


									game[playerY][playerX] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY - 1][playerX] = Player;
									game[playerY - 1][playerX + 1] = Player;
									isStoped = true;
									break;
								}
								playerX--;
							}
							game[playerY][playerX] = Player;
							game[playerY][playerX - 1] = Player;
							game[playerY - 1][playerX] = Player;
							game[playerY - 1][playerX + 1] = Player;
							system("cls");
							display();
						}
						if (playerY + 1 == gameSize - 2 ||
							game[playerY + 1][playerX] == 5 ||
							game[playerY + 1][playerX - 1] == 5 ||
							game[playerY][playerX + 1] == 5) {
							isStoped = true;
							break;
						}
					}

					game[playerY][playerX] = 0;
					game[playerY][playerX - 1] = 0;
					game[playerY - 1][playerX] = 0;
					game[playerY - 1][playerX + 1] = 0;
					if (key != DOWN
						)
					{
						playerY += 1;

					}
					game[playerY][playerX] = Player;
					game[playerY][playerX - 1] = Player;
					game[playerY - 1][playerX] = Player;
					game[playerY - 1][playerX + 1] = Player;
					if (playerY + 1 == gameSize - 2 ||
						game[playerY + 1][playerX] == 5 ||
						game[playerY + 1][playerX - 1] == 5 ||
						game[playerY][playerX + 1] == 5) {
						system("cls");
						display();
						key = _getch();
						if (key == 224) {
							game[playerY][playerX] = 0;
							game[playerY][playerX - 1] = 0;
							game[playerY - 1][playerX] = 0;
							game[playerY - 1][playerX + 1] = 0;
							key = _getch();
							if (key == DOWN) {
								if (playerY + 1 == gameSize - 2 ||
									game[playerY + 1][playerX] == 5 ||
									game[playerY + 1][playerX - 1] == 5 ||
									game[playerY][playerX + 1] == 5) {

									game[playerY][playerX] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY - 1][playerX] = Player;
									game[playerY - 1][playerX + 1] = Player;
									isStoped = true;
									break;
								}
								playerY++;
							}
							else if (key == RIGHT) {
								if (playerX + 2 == gameSize - 2 || game[playerY][playerX + 1] == 5 ||
									game[playerY - 1][playerX + 2] == 5) {

									game[playerY][playerX] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY - 1][playerX] = Player;
									game[playerY - 1][playerX + 1] = Player;
									isStoped = true;
									break;
								}
								playerX++;
							}
							else if (key == LEFT) {
								if (playerX - 2 < 0 || game[playerY][playerX - 2] == 5 ||
									game[playerY - 1][playerX - 1] == 5) {


									game[playerY][playerX] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY - 1][playerX] = Player;
									game[playerY - 1][playerX + 1] = Player;
									isStoped = true;
									break;
								}
								playerX--;
							}
							game[playerY][playerX] = Player;
							game[playerY][playerX - 1] = Player;
							game[playerY - 1][playerX] = Player;
							game[playerY - 1][playerX + 1] = Player;
							system("cls");
							display();
						}
						if (playerY + 1 == gameSize - 2 ||
							game[playerY + 1][playerX] == 5 ||
							game[playerY + 1][playerX - 1] == 5 ||
							game[playerY][playerX + 1] == 5) {
							isStoped = true;
							break;
						}
					}

				}// key 224 scope
			}//rotate count 0 scope

			if (rotateCount == 1 || rotateCount == 3)
			{


				if (game[playerY + 1][playerX] == 5 && isTrue2 == false ||
					game[playerY - 1][playerX - 1] == 5 && isTrue2 == false)
				{
					rotateCount = 3;
					continue;
				}
				isTrue1 = false;
				if (isTrue2 == false)
				{
					game[playerY][playerX] = 0;
					game[playerY][playerX - 1] = 0;
					game[playerY - 1][playerX] = 0;
					game[playerY - 1][playerX + 1] = 0;
					isTrue2 = true;
				}
				game[playerY][playerX] = Player;
				game[playerY][playerX - 1] = Player;
				game[playerY + 1][playerX] = Player;
				game[playerY - 1][playerX - 1] = Player;



				system("cls");
				display();
				if (key != 224)
				{
					key = _getch();

				}


				if (key == 224) {
					game[playerY][playerX] = 0;
					game[playerY][playerX - 1] = 0;
					game[playerY + 1][playerX] = 0;
					game[playerY - 1][playerX - 1] = 0;
					key = _getch();



					if (key == DOWN) {
						if (playerY + 2 == gameSize - 2) continue;
						playerY++;
					}
					else if (key == RIGHT) {
						if (playerX + 1 == gameSize - 2 || game[playerY][playerX + 1] == 5 ||
							game[playerY - 1][playerX] == 5 || game[playerY + 1][playerX + 1] == 5) continue;
						playerX++;
					}
					else if (key == LEFT) {
						if (playerX - 2 < 0 || game[playerY][playerX - 2] == 5 ||
							game[playerY - 1][playerX - 2] == 5 || game[playerY + 1][playerX - 1] == 5) continue;
						playerX--;
					}

					game[playerY][playerX] = Player;
					game[playerY][playerX - 1] = Player;
					game[playerY + 1][playerX] = Player;
					game[playerY - 1][playerX - 1] = Player;

					if (playerY + 2 == gameSize - 2 ||
						game[playerY + 2][playerX] == 5 ||
						game[playerY + 1][playerX - 1] == 5) {
						system("cls");
						display();
						key = _getch();
						if (key == 224) {
							game[playerY][playerX] = 0;
							game[playerY][playerX - 1] = 0;
							game[playerY + 1][playerX] = 0;
							game[playerY - 1][playerX - 1] = 0;
							key = _getch();
							if (key == DOWN) {
								if (playerY + 2 == gameSize - 2 ||
									game[playerY + 2][playerX] == 5 ||
									game[playerY + 1][playerX - 1] == 5

									) {

									game[playerY][playerX] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY + 1][playerX] = Player;
									game[playerY - 1][playerX - 1] = Player;
									isStoped = true;
									break;
								}
								playerY++;
							}
							else if (key == RIGHT) {
								if (playerX + 1 == gameSize - 2 || game[playerY][playerX + 1] == 5 ||
									game[playerY - 1][playerX] == 5 || game[playerY + 1][playerX + 1] == 5) {

									game[playerY][playerX] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY + 1][playerX] = Player;
									game[playerY - 1][playerX - 1] = Player;
									isStoped = true;
									break;
								}
								playerX++;
							}
							else if (key == LEFT) {
								if (playerX - 2 < 0 || game[playerY][playerX - 2] == 5 ||
									game[playerY - 1][playerX - 2] == 5 || game[playerY + 1][playerX - 1] == 5) {


									game[playerY][playerX] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY + 1][playerX] = Player;
									game[playerY - 1][playerX - 1] = Player;
									isStoped = true;
									break;
								}
								playerX--;
							}
							game[playerY][playerX] = Player;
							game[playerY][playerX - 1] = Player;
							game[playerY + 1][playerX] = Player;
							game[playerY - 1][playerX - 1] = Player;
							system("cls");
							display();
						}
						if (playerY + 2 == gameSize - 2 ||
							game[playerY + 2][playerX] == 5 ||
							game[playerY + 1][playerX - 1] == 5) {
							isStoped = true;
							break;
						}
					}

					game[playerY][playerX] = 0;
					game[playerY][playerX - 1] = 0;
					game[playerY + 1][playerX] = 0;
					game[playerY - 1][playerX - 1] = 0;
					if (key != DOWN
						)
					{
						playerY += 1;

					}
					game[playerY][playerX] = Player;
					game[playerY][playerX - 1] = Player;
					game[playerY + 1][playerX] = Player;
					game[playerY - 1][playerX - 1] = Player;
					if (playerY + 2 == gameSize - 2 ||
						game[playerY + 2][playerX] == 5 ||
						game[playerY + 1][playerX - 1] == 5) {
						system("cls");
						display();
						key = _getch();
						if (key == 224) {
							game[playerY][playerX] = 0;
							game[playerY][playerX - 1] = 0;
							game[playerY + 1][playerX] = 0;
							game[playerY - 1][playerX - 1] = 0;
							key = _getch();
							if (key == DOWN) {
								if (playerY + 2 == gameSize - 2 ||
									game[playerY + 2][playerX] == 5 ||
									game[playerY + 1][playerX - 1] == 5

									) {

									game[playerY][playerX] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY + 1][playerX] = Player;
									game[playerY - 1][playerX - 1] = Player;
									isStoped = true;
									break;
								}
								playerY++;
							}
							else if (key == RIGHT) {
								if (playerX + 1 == gameSize - 2 || game[playerY][playerX + 1] == 5 ||
									game[playerY - 1][playerX] == 5 || game[playerY + 1][playerX + 1] == 5) {

									game[playerY][playerX] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY + 1][playerX] = Player;
									game[playerY - 1][playerX - 1] = Player;
									isStoped = true;
									break;
								}
								playerX++;
							}
							else if (key == LEFT) {
								if (playerX - 2 < 0 || game[playerY][playerX - 2] == 5 ||
									game[playerY - 1][playerX - 2] == 5 || game[playerY + 1][playerX - 1] == 5) {


									game[playerY][playerX] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY + 1][playerX] = Player;
									game[playerY - 1][playerX - 1] = Player;
									isStoped = true;
									break;
								}
								playerX--;
							}
							game[playerY][playerX] = Player;
							game[playerY][playerX - 1] = Player;
							game[playerY + 1][playerX] = Player;
							game[playerY - 1][playerX - 1] = Player;
							system("cls");
							display();
						}
						if (playerY + 2 == gameSize - 2 ||
							game[playerY + 2][playerX] == 5 ||
							game[playerY + 1][playerX - 1] == 5) {
							isStoped = true;
							break;
						}
					}
				}// key 224 scope
			}//rotate count 0 scope
		}//RANDOM 5 SCOPE
		else if (random == 6) {
			if (rotateCount == 0)
			{
				if (
					game[playerY - 1][playerX] == 5 && isTrue1 == false ||
					game[playerY + 1][playerX] == 5 && isTrue1 == false ||
					game[playerY - 1][playerX] == 5 && isTrue1 == false ||
					game[playerY + 1][playerX - 1] == 5 && isTrue1 == false
					)
				{
					rotateCount = 3;
					continue;
				}
				isTrue2 = false;
				if (isTrue1 == false)
				{


					game[playerY][playerX] = 0;
					game[playerY][playerX + 1] = 0;
					game[playerY][playerX - 1] = 0;
					game[playerY + 1][playerX + 1] = 0;
					isTrue1 = true;
				}


				game[playerY][playerX] = Player;
				game[playerY - 1][playerX] = Player;
				game[playerY + 1][playerX] = Player;
				game[playerY + 1][playerX - 1] = Player;
				system("cls");
				display();
				if (key != 224)
				{
					key = _getch();

				}


				if (key == 224) {
					game[playerY][playerX] = 0;
					game[playerY - 1][playerX] = 0;
					game[playerY + 1][playerX] = 0;
					game[playerY + 1][playerX - 1] = 0;
					key = _getch();



					if (key == DOWN) {
						if (playerY + 2 == gameSize - 2) continue;
						playerY++;
					}
					else if (key == RIGHT) {
						if (playerX + 1 == gameSize - 2 || game[playerY][playerX + 1] == 5 ||
							game[playerY + 1][playerX + 1] == 5 || game[playerY - 1][playerX + 1] == 5) continue;
						playerX++;
					}
					else if (key == LEFT) {
						if (playerX - 2 < 0 || game[playerY][playerX - 1] == 5 ||
							game[playerY + 1][playerX - 2] == 5 || game[playerY - 1][playerX - 1] == 5) continue;
						playerX--;
					}

					game[playerY][playerX] = Player;
					game[playerY - 1][playerX] = Player;
					game[playerY + 1][playerX] = Player;
					game[playerY + 1][playerX - 1] = Player;

					if (playerY + 2 == gameSize - 2 || game[playerY + 2][playerX] == 5 ||
						game[playerY + 2][playerX - 1] == 5) {

						system("cls");
						display();
						key = _getch();
						if (key == 224) {
							game[playerY][playerX] = 0;
							game[playerY - 1][playerX] = 0;
							game[playerY + 1][playerX] = 0;
							game[playerY + 1][playerX - 1] = 0;
							key = _getch();
							if (key == DOWN) {
								if (playerY + 2 == gameSize - 2 || game[playerY + 2][playerX] == 5 ||
									game[playerY + 2][playerX - 1] == 5) {
									game[playerY][playerX] = Player;
									game[playerY - 1][playerX] = Player;
									game[playerY + 1][playerX] = Player;
									game[playerY + 1][playerX - 1] = Player;
									isStoped = true;
									break;
								}
								playerY++;
							}

							else if (key == RIGHT) {
								if (playerX + 1 == gameSize - 2 || game[playerY][playerX + 1] == 5 ||
									game[playerY + 1][playerX + 1] == 5 || game[playerY - 1][playerX + 1] == 5) {

									game[playerY][playerX] = Player;
									game[playerY - 1][playerX] = Player;
									game[playerY + 1][playerX] = Player;
									game[playerY + 1][playerX - 1] = Player;
									isStoped = true;
									break;
								}
								playerX++;
							}
							else if (key == LEFT) {
								if (playerX - 2 < 0 || game[playerY][playerX - 1] == 5 ||
									game[playerY + 1][playerX - 2] == 5 || game[playerY - 1][playerX - 1] == 5) {

									game[playerY][playerX] = Player;
									game[playerY - 1][playerX] = Player;
									game[playerY + 1][playerX] = Player;
									game[playerY + 1][playerX - 1] = Player;
									isStoped = true;
									break;
								}
								playerX--;
							}
							game[playerY][playerX] = Player;
							game[playerY - 1][playerX] = Player;
							game[playerY + 1][playerX] = Player;
							game[playerY + 1][playerX - 1] = Player;
							system("cls");
							display();
						}
						if (playerY + 2 == gameSize - 2 || game[playerY + 2][playerX] == 5 ||
							game[playerY + 2][playerX - 1] == 5) {
							isStoped = true;
							break;
						}
					}
					game[playerY][playerX] = 0;
					game[playerY - 1][playerX] = 0;
					game[playerY + 1][playerX] = 0;
					game[playerY + 1][playerX - 1] = 0;
					if (key != DOWN
						)
					{
						playerY += 1;

					}
					game[playerY][playerX] = Player;
					game[playerY - 1][playerX] = Player;
					game[playerY + 1][playerX] = Player;
					game[playerY + 1][playerX - 1] = Player;
					if (playerY + 2 == gameSize - 2 || game[playerY + 2][playerX] == 5 ||
						game[playerY + 2][playerX - 1] == 5) {

						system("cls");
						display();
						key = _getch();
						if (key == 224) {
							game[playerY][playerX] = 0;
							game[playerY - 1][playerX] = 0;
							game[playerY + 1][playerX] = 0;
							game[playerY + 1][playerX - 1] = 0;
							key = _getch();
							if (key == DOWN) {
								if (playerY + 2 == gameSize - 2 || game[playerY + 2][playerX] == 5 ||
									game[playerY + 2][playerX - 1] == 5) {
									game[playerY][playerX] = Player;
									game[playerY - 1][playerX] = Player;
									game[playerY + 1][playerX] = Player;
									game[playerY + 1][playerX - 1] = Player;
									isStoped = true;
									break;
								}
								playerY++;
							}

							else if (key == RIGHT) {
								if (playerX + 1 == gameSize - 2 || game[playerY][playerX + 1] == 5 ||
									game[playerY + 1][playerX + 1] == 5 || game[playerY - 1][playerX + 1] == 5) {

									game[playerY][playerX] = Player;
									game[playerY - 1][playerX] = Player;
									game[playerY + 1][playerX] = Player;
									game[playerY + 1][playerX - 1] = Player;
									isStoped = true;
									break;
								}
								playerX++;
							}
							else if (key == LEFT) {
								if (playerX - 2 < 0 || game[playerY][playerX - 1] == 5 ||
									game[playerY + 1][playerX - 2] == 5 || game[playerY - 1][playerX - 1] == 5) {

									game[playerY][playerX] = Player;
									game[playerY - 1][playerX] = Player;
									game[playerY + 1][playerX] = Player;
									game[playerY + 1][playerX - 1] = Player;
									isStoped = true;
									break;
								}
								playerX--;
							}
							game[playerY][playerX] = Player;
							game[playerY - 1][playerX] = Player;
							game[playerY + 1][playerX] = Player;
							game[playerY + 1][playerX - 1] = Player;
							system("cls");
							display();
						}
						if (playerY + 2 == gameSize - 2 || game[playerY + 2][playerX] == 5 ||
							game[playerY + 2][playerX - 1] == 5) {
							isStoped = true;
							break;
						}
					}

				}//key 224 scope
			}//rotate scope
			else if (rotateCount == 1)
			{
				if (
					game[playerY - 1][playerX - 1] == 5 && isTrue2 == false ||
					game[playerY][playerX + 1] == 5 && isTrue2 == false ||
					game[playerY][playerX - 1] == 5 && isTrue2 == false ||
					playerX + 1 == gameSize - 2 && isTrue2 == false
					)
				{
					rotateCount = 0;
					continue;
				}
				isTrue3 = false;
				if (isTrue2 == false)
				{


					game[playerY][playerX] = 0;
					game[playerY - 1][playerX] = 0;
					game[playerY + 1][playerX] = 0;
					game[playerY + 1][playerX - 1] = 0;
					isTrue2 = true;
				}


				game[playerY][playerX] = Player;
				game[playerY][playerX + 1] = Player;
				game[playerY][playerX - 1] = Player;
				game[playerY - 1][playerX - 1] = Player;
				system("cls");
				display();
				if (key != 224)
				{
					key = _getch();

				}


				if (key == 224) {
					game[playerY][playerX] = 0;
					game[playerY][playerX + 1] = 0;
					game[playerY][playerX - 1] = 0;
					game[playerY - 1][playerX - 1] = 0;
					key = _getch();



					if (key == DOWN) {
						if (playerY + 1 == gameSize - 2) continue;
						playerY++;
					}
					else if (key == RIGHT) {
						if (playerX + 2 == gameSize - 2 || game[playerY - 1][playerX] == 5) continue;
						playerX++;
					}
					else if (key == LEFT) {
						if (playerX - 2 < 0 || game[playerY][playerX - 2] == 5 ||
							game[playerY - 1][playerX - 2] == 5) continue;
						playerX--;
					}

					game[playerY][playerX] = Player;
					game[playerY][playerX + 1] = Player;
					game[playerY][playerX - 1] = Player;
					game[playerY - 1][playerX - 1] = Player;

					if (playerY + 1 == gameSize - 2 ||
						game[playerY + 1][playerX] == 5 ||
						game[playerY + 1][playerX - 1] == 5 ||
						game[playerY + 1][playerX + 1] == 5) {

						system("cls");
						display();
						key = _getch();
						if (key == 224) {
							game[playerY][playerX] = 0;
							game[playerY][playerX + 1] = 0;
							game[playerY][playerX - 1] = 0;
							game[playerY - 1][playerX - 1] = 0;
							key = _getch();
							if (key == DOWN) {
								if (playerY + 1 == gameSize - 2 ||
									game[playerY + 1][playerX] == 5 ||
									game[playerY + 1][playerX - 1] == 5 ||
									game[playerY + 1][playerX + 1] == 5
									) {
									game[playerY][playerX] = Player;
									game[playerY][playerX + 1] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY - 1][playerX - 1] = Player;
									isStoped = true;
									break;
								}
								playerY++;
							}

							else if (key == RIGHT) {
								if (playerX + 2 == gameSize - 2 || game[playerY][playerX + 2] == 5 ||
									game[playerY - 1][playerX] == 5) {

									game[playerY][playerX] = Player;
									game[playerY][playerX + 1] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY - 1][playerX - 1] = Player;
									isStoped = true;
									break;
								}
								playerX++;
							}
							else if (key == LEFT) {
								if (playerX - 2 < 0 || game[playerY][playerX - 2] == 5 ||
									game[playerY - 1][playerX - 2] == 5) {

									game[playerY][playerX] = Player;
									game[playerY][playerX + 1] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY - 1][playerX - 1] = Player;
									isStoped = true;
									break;
								}
								playerX--;
							}
							game[playerY][playerX] = Player;
							game[playerY][playerX + 1] = Player;
							game[playerY][playerX - 1] = Player;
							game[playerY - 1][playerX - 1] = Player;
							system("cls");
							display();
						}
						if (playerY + 1 == gameSize - 2 ||
							game[playerY + 1][playerX] == 5 ||
							game[playerY + 1][playerX - 1] == 5 ||
							game[playerY + 1][playerX + 1] == 5) {
							isStoped = true;
							break;
						}
					}
					game[playerY][playerX] = 0;
					game[playerY][playerX + 1] = 0;
					game[playerY][playerX - 1] = 0;
					game[playerY - 1][playerX - 1] = 0;
					if (key != DOWN
						)
					{
						playerY += 1;

					}
					game[playerY][playerX] = Player;
					game[playerY][playerX + 1] = Player;
					game[playerY][playerX - 1] = Player;
					game[playerY - 1][playerX - 1] = Player;
					if (playerY + 1 == gameSize - 2 ||
						game[playerY + 1][playerX] == 5 ||
						game[playerY + 1][playerX - 1] == 5 ||
						game[playerY + 1][playerX + 1] == 5) {

						system("cls");
						display();
						key = _getch();
						if (key == 224) {
							game[playerY][playerX] = 0;
							game[playerY][playerX + 1] = 0;
							game[playerY][playerX - 1] = 0;
							game[playerY - 1][playerX - 1] = 0;
							key = _getch();
							if (key == DOWN) {
								if (playerY + 1 == gameSize - 2 ||
									game[playerY + 1][playerX] == 5 ||
									game[playerY + 1][playerX - 1] == 5 ||
									game[playerY + 1][playerX + 1] == 5
									) {
									game[playerY][playerX] = Player;
									game[playerY][playerX + 1] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY - 1][playerX - 1] = Player;
									isStoped = true;
									break;
								}
								playerY++;
							}

							else if (key == RIGHT) {
								if (playerX + 2 == gameSize - 2 || game[playerY][playerX + 2] == 5) {

									game[playerY][playerX] = Player;
									game[playerY][playerX + 1] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY - 1][playerX - 1] = Player;
									isStoped = true;
									break;
								}
								playerX++;
							}
							else if (key == LEFT) {
								if (playerX - 2 < 0 || game[playerY][playerX - 2] == 5 ||
									game[playerY - 1][playerX - 2] == 5) {

									game[playerY][playerX] = Player;
									game[playerY][playerX + 1] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY - 1][playerX - 1] = Player;
									isStoped = true;
									break;
								}
								playerX--;
							}
							game[playerY][playerX] = Player;
							game[playerY][playerX + 1] = Player;
							game[playerY][playerX - 1] = Player;
							game[playerY - 1][playerX - 1] = Player;
							system("cls");
							display();
						}
						if (playerY + 1 == gameSize - 2 ||
							game[playerY + 1][playerX] == 5 ||
							game[playerY + 1][playerX - 1] == 5 ||
							game[playerY + 1][playerX + 1] == 5) {
							isStoped = true;
							break;
						}
					}

				}//key 224 scope
			}//rotate scope
			else if (rotateCount == 2)
			{
				if (
					game[playerY - 1][playerX + 1] == 5 && isTrue3 == false ||
					game[playerY - 1][playerX] == 5 && isTrue3 == false ||
					game[playerY + 1][playerX] == 5 && isTrue3 == false
					)
				{
					rotateCount = 1;
					continue;
				}
				isTrue4 = false;
				if (isTrue3 == false)
				{


					game[playerY][playerX] = 0;
					game[playerY][playerX + 1] = 0;
					game[playerY][playerX - 1] = 0;
					game[playerY - 1][playerX - 1] = 0;
					isTrue3 = true;
				}


				game[playerY][playerX] = Player;
				game[playerY + 1][playerX] = Player;
				game[playerY - 1][playerX] = Player;
				game[playerY - 1][playerX + 1] = Player;
				system("cls");
				display();
				if (key != 224)
				{
					key = _getch();

				}


				if (key == 224) {
					game[playerY][playerX] = 0;
					game[playerY + 1][playerX] = 0;
					game[playerY - 1][playerX] = 0;
					game[playerY - 1][playerX + 1] = 0;
					key = _getch();



					if (key == DOWN) {
						if (playerY + 2 == gameSize - 2) continue;
						playerY++;
					}
					else if (key == RIGHT) {
						if (playerX + 2 == gameSize - 2 || game[playerY + 1][playerX + 1] == 5 ||
							game[playerY - 1][playerX + 2] == 5 || game[playerY][playerX + 1] == 5) continue;
						playerX++;
					}
					else if (key == LEFT) {
						if (playerX - 1 < 0 || game[playerY][playerX - 1] == 5 ||
							game[playerY - 1][playerX - 1] == 5 || game[playerY + 1][playerX - 1] == 5) continue;
						playerX--;
					}

					game[playerY][playerX] = Player;
					game[playerY + 1][playerX] = Player;
					game[playerY - 1][playerX] = Player;
					game[playerY - 1][playerX + 1] = Player;

					if (playerY + 2 == gameSize - 2 ||
						game[playerY + 2][playerX] == 5 ||
						game[playerY][playerX + 1] == 5) {

						system("cls");
						display();
						key = _getch();
						if (key == 224) {
							game[playerY][playerX] = 0;
							game[playerY + 1][playerX] = 0;
							game[playerY - 1][playerX] = 0;
							game[playerY - 1][playerX + 1] = 0;
							key = _getch();
							if (key == DOWN) {
								if (playerY + 2 == gameSize - 2 ||
									game[playerY + 2][playerX] == 5 ||
									game[playerY][playerX + 1] == 5
									) {
									game[playerY][playerX] = Player;
									game[playerY + 1][playerX] = Player;
									game[playerY - 1][playerX] = Player;
									game[playerY - 1][playerX + 1] = Player;
									isStoped = true;
									break;
								}
								playerY++;
							}

							else if (key == RIGHT) {
								if (playerX + 2 == gameSize - 2 || game[playerY + 1][playerX + 1] == 5 ||
									game[playerY - 1][playerX + 2] == 5 || game[playerY][playerX + 1] == 5) {

									game[playerY][playerX] = Player;
									game[playerY + 1][playerX] = Player;
									game[playerY - 1][playerX] = Player;
									game[playerY - 1][playerX + 1] = Player;
									isStoped = true;
									break;
								}
								playerX++;
							}
							else if (key == LEFT) {
								if (playerX - 1 < 0 || game[playerY][playerX - 1] == 5 ||
									game[playerY - 1][playerX - 1] == 5 || game[playerY + 1][playerX - 1] == 5) {

									game[playerY][playerX] = Player;
									game[playerY + 1][playerX] = Player;
									game[playerY - 1][playerX] = Player;
									game[playerY - 1][playerX + 1] = Player;
									isStoped = true;
									break;
								}
								playerX--;
							}
							game[playerY][playerX] = Player;
							game[playerY + 1][playerX] = Player;
							game[playerY - 1][playerX] = Player;
							game[playerY - 1][playerX + 1] = Player;
							system("cls");
							display();
						}
						if (playerY + 2 == gameSize - 2 ||
							game[playerY + 2][playerX] == 5 ||
							game[playerY][playerX + 1] == 5) {
							isStoped = true;
							break;
						}
					}
					game[playerY][playerX] = 0;
					game[playerY + 1][playerX] = 0;
					game[playerY - 1][playerX] = 0;
					game[playerY - 1][playerX + 1] = 0;
					if (key != DOWN
						)
					{
						playerY += 1;

					}
					game[playerY][playerX] = Player;
					game[playerY + 1][playerX] = Player;
					game[playerY - 1][playerX] = Player;
					game[playerY - 1][playerX + 1] = Player;
					if (playerY + 2 == gameSize - 2 ||
						game[playerY + 2][playerX] == 5 ||
						game[playerY][playerX + 1] == 5) {

						system("cls");
						display();
						key = _getch();
						if (key == 224) {
							game[playerY][playerX] = 0;
							game[playerY + 1][playerX] = 0;
							game[playerY - 1][playerX] = 0;
							game[playerY - 1][playerX + 1] = 0;
							key = _getch();
							if (key == DOWN) {
								if (playerY + 2 == gameSize - 2 ||
									game[playerY + 2][playerX] == 5 ||
									game[playerY][playerX + 1] == 5
									) {
									game[playerY][playerX] = Player;
									game[playerY + 1][playerX] = Player;
									game[playerY - 1][playerX] = Player;
									game[playerY - 1][playerX + 1] = Player;
									isStoped = true;
									break;
								}
								playerY++;
							}

							else if (key == RIGHT) {
								if (playerX + 2 == gameSize - 2 || game[playerY + 1][playerX + 1] == 5 ||
									game[playerY - 1][playerX + 2] == 5 || game[playerY][playerX + 1] == 5) {

									game[playerY][playerX] = Player;
									game[playerY + 1][playerX] = Player;
									game[playerY - 1][playerX] = Player;
									game[playerY - 1][playerX + 1] = Player;
									isStoped = true;
									break;
								}
								playerX++;
							}
							else if (key == LEFT) {
								if (playerX - 1 < 0 || game[playerY][playerX - 1] == 5 ||
									game[playerY - 1][playerX - 1] == 5 || game[playerY + 1][playerX - 1] == 5) {

									game[playerY][playerX] = Player;
									game[playerY + 1][playerX] = Player;
									game[playerY - 1][playerX] = Player;
									game[playerY - 1][playerX + 1] = Player;
									isStoped = true;
									break;
								}
								playerX--;
							}
							game[playerY][playerX] = Player;
							game[playerY + 1][playerX] = Player;
							game[playerY - 1][playerX] = Player;
							game[playerY - 1][playerX + 1] = Player;
							system("cls");
							display();
						}
						if (playerY + 2 == gameSize - 2 ||
							game[playerY + 2][playerX] == 5 ||
							game[playerY][playerX + 1] == 5) {
							isStoped = true;
							break;
						}
					}

				}//key 224 scope
			}//rotate scope
			else if (rotateCount == 3)
			{
				if (
					game[playerY][playerX - 1] == 5 && isTrue4 == false ||
					game[playerY][playerX + 1] == 5 && isTrue4 == false ||
					game[playerY + 1][playerX + 1] == 5 && isTrue4 == false ||
					playerX - 1 < 0 && isTrue4 == false
					)
				{
					rotateCount = 2;
					continue;
				}
				isTrue1 = false;
				if (isTrue4 == false)
				{


					game[playerY][playerX] = 0;
					game[playerY + 1][playerX] = 0;
					game[playerY - 1][playerX] = 0;
					game[playerY - 1][playerX + 1] = 0;
					isTrue4 = true;
				}


				game[playerY][playerX] = Player;
				game[playerY][playerX + 1] = Player;
				game[playerY][playerX - 1] = Player;
				game[playerY + 1][playerX + 1] = Player;
				system("cls");
				display();
				if (key != 224)
				{
					key = _getch();

				}


				if (key == 224) {
					game[playerY][playerX] = 0;
					game[playerY][playerX + 1] = 0;
					game[playerY][playerX - 1] = 0;
					game[playerY + 1][playerX + 1] = 0;
					key = _getch();



					if (key == DOWN) {
						if (playerY + 2 == gameSize - 2) continue;
						playerY++;
					}
					else if (key == RIGHT) {
						if (playerX + 2 == gameSize - 2 || game[playerY][playerX + 2] == 5 ||
							game[playerY + 1][playerX + 2] == 5) continue;
						playerX++;
					}
					else if (key == LEFT) {
						if (playerX - 2 < 0 || game[playerY][playerX - 2] == 5 ||
							game[playerY + 1][playerX] == 5) continue;
						playerX--;
					}

					game[playerY][playerX] = Player;
					game[playerY][playerX + 1] = Player;
					game[playerY][playerX - 1] = Player;
					game[playerY + 1][playerX + 1] = Player;

					if (playerY + 2 == gameSize - 2 ||
						game[playerY + 2][playerX + 1] == 5 ||
						game[playerY + 1][playerX - 1] == 5 ||
						game[playerY + 1][playerX] == 5) {

						system("cls");
						display();
						key = _getch();
						if (key == 224) {
							game[playerY][playerX] = 0;
							game[playerY][playerX + 1] = 0;
							game[playerY][playerX - 1] = 0;
							game[playerY + 1][playerX + 1] = 0;
							key = _getch();
							if (key == DOWN) {
								if (playerY + 2 == gameSize - 2 ||
									game[playerY + 2][playerX + 1] == 5 ||
									game[playerY + 1][playerX - 1] == 5 ||
									game[playerY + 1][playerX] == 5
									) {
									game[playerY][playerX] = Player;
									game[playerY][playerX + 1] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY + 1][playerX + 1] = Player;
									isStoped = true;
									break;
								}
								playerY++;
							}

							else if (key == RIGHT) {
								if (playerX + 2 == gameSize - 2 || game[playerY][playerX + 2] == 5 ||
									game[playerY + 1][playerX + 2] == 5) {

									game[playerY][playerX] = Player;
									game[playerY][playerX + 1] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY + 1][playerX + 1] = Player;
									isStoped = true;
									break;
								}
								playerX++;
							}
							else if (key == LEFT) {
								if (playerX - 2 < 0 || game[playerY][playerX - 2] == 5 ||
									game[playerY + 1][playerX] == 5) {
									game[playerY][playerX] = Player;
									game[playerY][playerX + 1] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY + 1][playerX + 1] = Player;
									isStoped = true;
									break;
								}
								playerX--;
							}
							game[playerY][playerX] = Player;
							game[playerY][playerX + 1] = Player;
							game[playerY][playerX - 1] = Player;
							game[playerY + 1][playerX + 1] = Player;
							system("cls");
							display();
						}
						if (playerY + 2 == gameSize - 2 ||
							game[playerY + 2][playerX + 1] == 5 ||
							game[playerY + 1][playerX - 1] == 5 ||
							game[playerY + 1][playerX] == 5) {
							isStoped = true;
							break;
						}
					}
					game[playerY][playerX] = 0;
					game[playerY][playerX + 1] = 0;
					game[playerY][playerX - 1] = 0;
					game[playerY + 1][playerX + 1] = 0;
					if (key != DOWN
						)
					{
						playerY += 1;

					}
					game[playerY][playerX] = Player;
					game[playerY][playerX + 1] = Player;
					game[playerY][playerX - 1] = Player;
					game[playerY + 1][playerX + 1] = Player;
					if (playerY + 2 == gameSize - 2 ||
						game[playerY + 2][playerX + 1] == 5 ||
						game[playerY + 1][playerX - 1] == 5 ||
						game[playerY + 1][playerX] == 5) {

						system("cls");
						display();
						key = _getch();
						if (key == 224) {
							game[playerY][playerX] = 0;
							game[playerY][playerX + 1] = 0;
							game[playerY][playerX - 1] = 0;
							game[playerY + 1][playerX + 1] = 0;
							key = _getch();
							if (key == DOWN) {
								if (playerY + 2 == gameSize - 2 ||
									game[playerY + 2][playerX + 1] == 5 ||
									game[playerY + 1][playerX - 1] == 5 ||
									game[playerY + 1][playerX] == 5
									) {
									game[playerY][playerX] = Player;
									game[playerY][playerX + 1] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY + 1][playerX + 1] = Player;
									isStoped = true;
									break;
								}
								playerY++;
							}

							else if (key == RIGHT) {
								if (playerX + 2 == gameSize - 2 || game[playerY][playerX + 2] == 5 ||
									game[playerY + 1][playerX + 2] == 5) {

									game[playerY][playerX] = Player;
									game[playerY][playerX + 1] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY + 1][playerX + 1] = Player;
									isStoped = true;
									break;
								}
								playerX++;
							}
							else if (key == LEFT) {
								if (playerX - 2 < 0 || game[playerY][playerX - 2] == 5 ||
									game[playerY + 1][playerX] == 5) {
									game[playerY][playerX] = Player;
									game[playerY][playerX + 1] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY + 1][playerX + 1] = Player;
									isStoped = true;
									break;
								}
								playerX--;
							}
							game[playerY][playerX] = Player;
							game[playerY][playerX + 1] = Player;
							game[playerY][playerX - 1] = Player;
							game[playerY + 1][playerX + 1] = Player;
							system("cls");
							display();
						}
						if (playerY + 2 == gameSize - 2 ||
							game[playerY + 2][playerX + 1] == 5 ||
							game[playerY + 1][playerX - 1] == 5 ||
							game[playerY + 1][playerX] == 5) {
							isStoped = true;
							break;
						}
					}

				}//key 224 scope
			}//rotate scope
		}//random 6 scope
		else if (random == 7) {
			if (rotateCount == 0)
			{
				if (
					game[playerY - 1][playerX] == 5 && isTrue1 == false ||
					game[playerY + 1][playerX] == 5 && isTrue1 == false ||
					game[playerY - 1][playerX] == 5 && isTrue1 == false ||
					game[playerY + 1][playerX + 1] == 5 && isTrue1 == false
					)
				{
					rotateCount = 3;
					continue;
				}
				isTrue2 = false;
				if (isTrue1 == false)
				{


					game[playerY][playerX] = 0;
					game[playerY][playerX + 1] = 0;
					game[playerY][playerX - 1] = 0;
					game[playerY - 1][playerX + 1] = 0;
					isTrue1 = true;
				}


				game[playerY][playerX] = Player;
				game[playerY - 1][playerX] = Player;
				game[playerY + 1][playerX] = Player;
				game[playerY + 1][playerX + 1] = Player;
				system("cls");
				display();
				if (key != 224)
				{
					key = _getch();

				}


				if (key == 224) {
					game[playerY][playerX] = 0;
					game[playerY - 1][playerX] = 0;
					game[playerY + 1][playerX] = 0;
					game[playerY + 1][playerX + 1] = 0;
					key = _getch();



					if (key == DOWN) {
						if (playerY + 2 == gameSize - 2) continue;
						playerY++;
					}
					else if (key == RIGHT) {
						if (playerX + 2 == gameSize - 2 || game[playerY][playerX + 1] == 5 ||
							game[playerY + 1][playerX + 2] == 5 || game[playerY - 1][playerX + 1] == 5) continue;
						playerX++;
					}
					else if (key == LEFT) {
						if (playerX - 1 < 0 || game[playerY][playerX - 1] == 5 ||
							game[playerY + 1][playerX - 1] == 5 || game[playerY - 1][playerX - 1] == 5) continue;
						playerX--;
					}

					game[playerY][playerX] = Player;
					game[playerY - 1][playerX] = Player;
					game[playerY + 1][playerX] = Player;
					game[playerY + 1][playerX + 1] = Player;

					if (playerY + 2 == gameSize - 2 ||
						game[playerY + 2][playerX] == 5 ||
						game[playerY + 2][playerX + 1] == 5) {

						system("cls");
						display();
						key = _getch();
						if (key == 224) {
							game[playerY][playerX] = 0;
							game[playerY - 1][playerX] = 0;
							game[playerY + 1][playerX] = 0;
							game[playerY + 1][playerX + 1] = 0;
							key = _getch();
							if (key == DOWN) {
								if (playerY + 2 == gameSize - 2 ||
									game[playerY + 2][playerX] == 5 ||
									game[playerY + 2][playerX + 1] == 5) {

									game[playerY][playerX] = Player;
									game[playerY - 1][playerX] = Player;
									game[playerY + 1][playerX] = Player;
									game[playerY + 1][playerX + 1] = Player;
									isStoped = true;
									break;
								}
								playerY++;
							}

							else if (key == RIGHT) {
								if (playerX + 2 == gameSize - 2 || game[playerY][playerX + 1] == 5 ||
									game[playerY + 1][playerX + 2] == 5 || game[playerY - 1][playerX + 1] == 5) {

									game[playerY][playerX] = Player;
									game[playerY - 1][playerX] = Player;
									game[playerY + 1][playerX] = Player;
									game[playerY + 1][playerX + 1] = Player;
									isStoped = true;
									break;
								}
								playerX++;
							}
							else if (key == LEFT) {
								if (playerX - 1 < 0 || game[playerY][playerX - 1] == 5 ||
									game[playerY + 1][playerX - 1] == 5 || game[playerY - 1][playerX - 1] == 5) {

									game[playerY][playerX] = Player;
									game[playerY - 1][playerX] = Player;
									game[playerY + 1][playerX] = Player;
									game[playerY + 1][playerX + 1] = Player;
									isStoped = true;
									break;
								}
								playerX--;
							}
							game[playerY][playerX] = Player;
							game[playerY - 1][playerX] = Player;
							game[playerY + 1][playerX] = Player;
							game[playerY + 1][playerX + 1] = Player;
							system("cls");
							display();
						}
						if (playerY + 2 == gameSize - 2 ||
							game[playerY + 2][playerX] == 5 ||
							game[playerY + 2][playerX + 1] == 5) {
							isStoped = true;
							break;
						}
					}
					game[playerY][playerX] = 0;
					game[playerY - 1][playerX] = 0;
					game[playerY + 1][playerX] = 0;
					game[playerY + 1][playerX + 1] = 0;
					if (key != DOWN
						)
					{
						playerY += 1;

					}
					game[playerY][playerX] = Player;
					game[playerY - 1][playerX] = Player;
					game[playerY + 1][playerX] = Player;
					game[playerY + 1][playerX + 1] = Player;
					if (playerY + 2 == gameSize - 2 ||
						game[playerY + 2][playerX] == 5 ||
						game[playerY + 2][playerX + 1] == 5) {

						system("cls");
						display();
						key = _getch();
						if (key == 224) {
							game[playerY][playerX] = 0;
							game[playerY - 1][playerX] = 0;
							game[playerY + 1][playerX] = 0;
							game[playerY + 1][playerX + 1] = 0;
							key = _getch();
							if (key == DOWN) {
								if (playerY + 2 == gameSize - 2 ||
									game[playerY + 2][playerX] == 5 ||
									game[playerY + 2][playerX + 1] == 5) {

									game[playerY][playerX] = Player;
									game[playerY - 1][playerX] = Player;
									game[playerY + 1][playerX] = Player;
									game[playerY + 1][playerX + 1] = Player;
									isStoped = true;
									break;
								}
								playerY++;
							}

							else if (key == RIGHT) {
								if (playerX + 2 == gameSize - 2 || game[playerY][playerX + 1] == 5 ||
									game[playerY + 1][playerX + 2] == 5 || game[playerY - 1][playerX + 1] == 5) {

									game[playerY][playerX] = Player;
									game[playerY - 1][playerX] = Player;
									game[playerY + 1][playerX] = Player;
									game[playerY + 1][playerX + 1] = Player;
									isStoped = true;
									break;
								}
								playerX++;
							}
							else if (key == LEFT) {
								if (playerX - 1 < 0 || game[playerY][playerX - 1] == 5 ||
									game[playerY + 1][playerX - 1] == 5 || game[playerY - 1][playerX - 1] == 5) {

									game[playerY][playerX] = Player;
									game[playerY - 1][playerX] = Player;
									game[playerY + 1][playerX] = Player;
									game[playerY + 1][playerX + 1] = Player;
									isStoped = true;
									break;
								}
								playerX--;
							}
							game[playerY][playerX] = Player;
							game[playerY - 1][playerX] = Player;
							game[playerY + 1][playerX] = Player;
							game[playerY + 1][playerX + 1] = Player;
							system("cls");
							display();
						}
						if (playerY + 2 == gameSize - 2 ||
							game[playerY + 2][playerX] == 5 ||
							game[playerY + 2][playerX + 1] == 5) {
							isStoped = true;
							break;
						}
					}

				}//key 224 scope
			}//rotate scope
			else if (rotateCount == 1)
			{
				if (
					game[playerY + 1][playerX - 1] == 5 && isTrue2 == false ||
					game[playerY][playerX + 1] == 5 && isTrue2 == false ||
					game[playerY][playerX - 1] == 5 && isTrue2 == false ||
					playerX - 1 < 0 && isTrue2 == false
					)
				{
					rotateCount = 0;
					continue;
				}
				isTrue3 = false;
				if (isTrue2 == false)
				{


					game[playerY][playerX] = 0;
					game[playerY - 1][playerX] = 0;
					game[playerY + 1][playerX] = 0;
					game[playerY + 1][playerX + 1] = 0;
					isTrue2 = true;
				}


				game[playerY][playerX] = Player;
				game[playerY][playerX + 1] = Player;
				game[playerY][playerX - 1] = Player;
				game[playerY + 1][playerX - 1] = Player;
				system("cls");
				display();
				if (key != 224)
				{
					key = _getch();

				}


				if (key == 224) {
					game[playerY][playerX] = 0;
					game[playerY][playerX + 1] = 0;
					game[playerY][playerX - 1] = 0;
					game[playerY + 1][playerX - 1] = 0;
					key = _getch();



					if (key == DOWN) {
						if (playerY + 2 == gameSize - 2) continue;
						playerY++;
					}
					else if (key == RIGHT) {
						if (playerX + 2 == gameSize - 2 ||
							game[playerY][playerX + 2] == 5 ||
							game[playerY + 1][playerX] == 5) continue;
						playerX++;
					}
					else if (key == LEFT) {
						if (playerX - 2 < 0 || game[playerY][playerX - 2] == 5 ||
							game[playerY + 1][playerX - 2] == 5) continue;
						playerX--;
					}

					game[playerY][playerX] = Player;
					game[playerY][playerX + 1] = Player;
					game[playerY][playerX - 1] = Player;
					game[playerY + 1][playerX - 1] = Player;

					if (playerY + 2 == gameSize - 2 ||
						game[playerY + 1][playerX] == 5 ||
						game[playerY + 1][playerX + 1] == 5 ||
						game[playerY + 2][playerX - 1] == 5) {

						system("cls");
						display();
						key = _getch();
						if (key == 224) {
							game[playerY][playerX] = 0;
							game[playerY][playerX + 1] = 0;
							game[playerY][playerX - 1] = 0;
							game[playerY + 1][playerX - 1] = 0;
							key = _getch();
							if (key == DOWN) {
								if (playerY + 2 == gameSize - 2 ||
									game[playerY + 1][playerX] == 5 ||
									game[playerY + 1][playerX + 1] == 5 ||
									game[playerY + 2][playerX - 1] == 5
									) {
									game[playerY][playerX] = Player;
									game[playerY][playerX + 1] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY + 1][playerX - 1] = Player;
									isStoped = true;
									break;
								}
								playerY++;
							}

							else if (key == RIGHT) {
								if (playerX + 2 == gameSize - 2 ||
									game[playerY][playerX + 2] == 5 ||
									game[playerY + 1][playerX] == 5

									) {

									game[playerY][playerX] = Player;
									game[playerY][playerX + 1] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY + 1][playerX - 1] = Player;
									isStoped = true;
									break;
								}
								playerX++;
							}
							else if (key == LEFT) {
								if (playerX - 2 < 0 || game[playerY][playerX - 2] == 5 ||
									game[playerY + 1][playerX - 2] == 5) {

									game[playerY][playerX] = Player;
									game[playerY][playerX + 1] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY + 1][playerX - 1] = Player;
									isStoped = true;
									break;
								}
								playerX--;
							}
							game[playerY][playerX] = Player;
							game[playerY][playerX + 1] = Player;
							game[playerY][playerX - 1] = Player;
							game[playerY + 1][playerX - 1] = Player;
							system("cls");
							display();
						}
						if (playerY + 2 == gameSize - 2 ||
							game[playerY + 1][playerX] == 5 ||
							game[playerY + 1][playerX + 1] == 5 ||
							game[playerY + 2][playerX - 1] == 5) {
							isStoped = true;
							break;
						}
					}
					game[playerY][playerX] = 0;
					game[playerY][playerX + 1] = 0;
					game[playerY][playerX - 1] = 0;
					game[playerY + 1][playerX - 1] = 0;
					if (key != DOWN
						)
					{
						playerY += 1;

					}
					game[playerY][playerX] = Player;
					game[playerY][playerX + 1] = Player;
					game[playerY][playerX - 1] = Player;
					game[playerY + 1][playerX - 1] = Player;
					if (playerY + 2 == gameSize - 2 ||
						game[playerY + 1][playerX] == 5 ||
						game[playerY + 1][playerX + 1] == 5 ||
						game[playerY + 2][playerX - 1] == 5) {

						system("cls");
						display();
						key = _getch();
						if (key == 224) {
							game[playerY][playerX] = 0;
							game[playerY][playerX + 1] = 0;
							game[playerY][playerX - 1] = 0;
							game[playerY + 1][playerX - 1] = 0;
							key = _getch();
							if (key == DOWN) {
								if (playerY + 2 == gameSize - 2 ||
									game[playerY + 1][playerX] == 5 ||
									game[playerY + 1][playerX + 1] == 5 ||
									game[playerY + 2][playerX - 1] == 5
									) {
									game[playerY][playerX] = Player;
									game[playerY][playerX + 1] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY + 1][playerX - 1] = Player;
									isStoped = true;
									break;
								}
								playerY++;
							}

							else if (key == RIGHT) {
								if (playerX + 2 == gameSize - 2 || game[playerY][playerX + 2] == 5) {

									game[playerY][playerX] = Player;
									game[playerY][playerX + 1] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY + 1][playerX - 1] = Player;
									isStoped = true;
									break;
								}
								playerX++;
							}
							else if (key == LEFT) {
								if (playerX - 2 < 0 || game[playerY][playerX - 2] == 5 ||
									game[playerY + 1][playerX - 2] == 5) {

									game[playerY][playerX] = Player;
									game[playerY][playerX + 1] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY + 1][playerX - 1] = Player;
									isStoped = true;
									break;
								}
								playerX--;
							}
							game[playerY][playerX] = Player;
							game[playerY][playerX + 1] = Player;
							game[playerY][playerX - 1] = Player;
							game[playerY + 1][playerX - 1] = Player;
							system("cls");
							display();
						}
						if (playerY + 2 == gameSize - 2 ||
							game[playerY + 1][playerX] == 5 ||
							game[playerY + 1][playerX + 1] == 5 ||
							game[playerY + 2][playerX - 1] == 5) {
							isStoped = true;
							break;
						}
					}

				}//key 224 scope
			}//rotate scope
			else if (rotateCount == 2)
			{
				if (
					game[playerY - 1][playerX - 1] == 5 && isTrue3 == false ||
					game[playerY - 1][playerX] == 5 && isTrue3 == false ||
					game[playerY + 1][playerX] == 5 && isTrue3 == false
					)
				{
					rotateCount = 1;
					continue;
				}
				isTrue4 = false;
				if (isTrue3 == false)
				{


					game[playerY][playerX] = 0;
					game[playerY][playerX + 1] = 0;
					game[playerY][playerX - 1] = 0;
					game[playerY + 1][playerX - 1] = 0;
					isTrue3 = true;
				}


				game[playerY][playerX] = Player;
				game[playerY + 1][playerX] = Player;
				game[playerY - 1][playerX] = Player;
				game[playerY - 1][playerX - 1] = Player;
				system("cls");
				display();
				if (key != 224)
				{
					key = _getch();

				}


				if (key == 224) {
					game[playerY][playerX] = 0;
					game[playerY + 1][playerX] = 0;
					game[playerY - 1][playerX] = 0;
					game[playerY - 1][playerX - 1] = 0;
					key = _getch();



					if (key == DOWN) {
						if (playerY + 2 == gameSize - 2) continue;
						playerY++;
					}
					else if (key == RIGHT) {
						if (playerX + 1 == gameSize - 2 || game[playerY + 1][playerX + 1] == 5 ||
							game[playerY - 1][playerX + 1] == 5 || game[playerY][playerX + 1] == 5) continue;
						playerX++;
					}
					else if (key == LEFT) {
						if (playerX - 2 < 0 || game[playerY][playerX - 1] == 5 ||
							game[playerY - 1][playerX - 2] == 5 || game[playerY + 1][playerX - 1] == 5) continue;
						playerX--;
					}

					game[playerY][playerX] = Player;
					game[playerY + 1][playerX] = Player;
					game[playerY - 1][playerX] = Player;
					game[playerY - 1][playerX - 1] = Player;

					if (playerY + 2 == gameSize - 2 ||
						game[playerY + 2][playerX] == 5 ||
						game[playerY][playerX - 1] == 5) {

						system("cls");
						display();
						key = _getch();
						if (key == 224) {
							game[playerY][playerX] = 0;
							game[playerY + 1][playerX] = 0;
							game[playerY - 1][playerX] = 0;
							game[playerY - 1][playerX - 1] = 0;
							key = _getch();
							if (key == DOWN) {
								if (playerY + 2 == gameSize - 2 ||
									game[playerY + 2][playerX] == 5 ||
									game[playerY][playerX - 1] == 5
									) {
									game[playerY][playerX] = Player;
									game[playerY + 1][playerX] = Player;
									game[playerY - 1][playerX] = Player;
									game[playerY - 1][playerX - 1] = Player;
									isStoped = true;
									break;
								}
								playerY++;
							}

							else if (key == RIGHT) {
								if (playerX + 1 == gameSize - 2 || game[playerY + 1][playerX + 1] == 5 ||
									game[playerY - 1][playerX + 1] == 5 || game[playerY][playerX + 1] == 5) {

									game[playerY][playerX] = Player;
									game[playerY + 1][playerX] = Player;
									game[playerY - 1][playerX] = Player;
									game[playerY - 1][playerX - 1] = Player;
									isStoped = true;
									break;
								}
								playerX++;
							}
							else if (key == LEFT) {
								if (playerX - 2 < 0 || game[playerY][playerX - 1] == 5 ||
									game[playerY - 1][playerX - 2] == 5 || game[playerY + 1][playerX - 1] == 5) {

									game[playerY][playerX] = Player;
									game[playerY + 1][playerX] = Player;
									game[playerY - 1][playerX] = Player;
									game[playerY - 1][playerX - 1] = Player;
									isStoped = true;
									break;
								}
								playerX--;
							}
							game[playerY][playerX] = Player;
							game[playerY + 1][playerX] = Player;
							game[playerY - 1][playerX] = Player;
							game[playerY - 1][playerX - 1] = Player;
							system("cls");
							display();
						}
						if (playerY + 2 == gameSize - 2 ||
							game[playerY + 2][playerX] == 5 ||
							game[playerY][playerX + 1] == 5) {
							isStoped = true;
							break;
						}
					}
					game[playerY][playerX] = 0;
					game[playerY + 1][playerX] = 0;
					game[playerY - 1][playerX] = 0;
					game[playerY - 1][playerX - 1] = 0;
					if (key != DOWN
						)
					{
						playerY += 1;

					}
					game[playerY][playerX] = Player;
					game[playerY + 1][playerX] = Player;
					game[playerY - 1][playerX] = Player;
					game[playerY - 1][playerX - 1] = Player;

					if (playerY + 2 == gameSize - 2 ||
						game[playerY + 2][playerX] == 5 ||
						game[playerY][playerX - 1] == 5) {

						system("cls");
						display();
						key = _getch();
						if (key == 224) {
							game[playerY][playerX] = 0;
							game[playerY + 1][playerX] = 0;
							game[playerY - 1][playerX] = 0;
							game[playerY - 1][playerX - 1] = 0;
							key = _getch();
							if (key == DOWN) {
								if (playerY + 2 == gameSize - 2 ||
									game[playerY + 2][playerX] == 5 ||
									game[playerY][playerX - 1] == 5
									) {
									game[playerY][playerX] = Player;
									game[playerY + 1][playerX] = Player;
									game[playerY - 1][playerX] = Player;
									game[playerY - 1][playerX - 1] = Player;
									isStoped = true;
									break;
								}
								playerY++;
							}

							else if (key == RIGHT) {
								if (playerX + 1 == gameSize - 2 || game[playerY + 1][playerX + 1] == 5 ||
									game[playerY - 1][playerX + 1] == 5 || game[playerY][playerX + 1] == 5) {

									game[playerY][playerX] = Player;
									game[playerY + 1][playerX] = Player;
									game[playerY - 1][playerX] = Player;
									game[playerY - 1][playerX - 1] = Player;
									isStoped = true;
									break;
								}
								playerX++;
							}
							else if (key == LEFT) {
								if (playerX - 2 < 0 || game[playerY][playerX - 1] == 5 ||
									game[playerY - 1][playerX - 2] == 5 || game[playerY + 1][playerX - 1] == 5) {

									game[playerY][playerX] = Player;
									game[playerY + 1][playerX] = Player;
									game[playerY - 1][playerX] = Player;
									game[playerY - 1][playerX - 1] = Player;
									isStoped = true;
									break;
								}
								playerX--;
							}
							game[playerY][playerX] = Player;
							game[playerY + 1][playerX] = Player;
							game[playerY - 1][playerX] = Player;
							game[playerY - 1][playerX - 1] = Player;
							system("cls");
							display();
						}
						if (playerY + 2 == gameSize - 2 ||
							game[playerY + 2][playerX] == 5 ||
							game[playerY][playerX + 1] == 5) {
							isStoped = true;
							break;
						}
					}
				}//key 224 scope
			}//rotate scope
			else if (rotateCount == 3)
			{/*
			if (
				game[playerY][playerX - 1] == 5 && isTrue4 == false ||
				game[playerY][playerX + 1] == 5 && isTrue4 == false ||
				game[playerY + 1][playerX + 1] == 5 && isTrue4 == false ||
				playerX - 1 < 0 && isTrue4 == false
				)
			{
				rotateCount = 2;
				continue;
			}*/
				isTrue1 = false;
				if (isTrue4 == false)
				{


					game[playerY][playerX] = 0;
					game[playerY + 1][playerX] = 0;
					game[playerY - 1][playerX] = 0;
					game[playerY - 1][playerX - 1] = 0;
					isTrue4 = true;
				}


				game[playerY][playerX] = Player;
				game[playerY][playerX + 1] = Player;
				game[playerY][playerX - 1] = Player;
				game[playerY - 1][playerX + 1] = Player;
				system("cls");
				display();
				if (key != 224)
				{
					key = _getch();

				}


				if (key == 224) {
					game[playerY][playerX] = 0;
					game[playerY][playerX + 1] = 0;
					game[playerY][playerX - 1] = 0;
					game[playerY - 1][playerX + 1] = 0;
					key = _getch();



					if (key == DOWN) {
						if (playerY + 1 == gameSize - 2) continue;
						playerY++;
					}
					else if (key == RIGHT) {
						if (playerX + 2 == gameSize - 2 || game[playerY][playerX + 2] == 5 ||
							game[playerY - 1][playerX + 2] == 5) continue;
						playerX++;
					}
					else if (key == LEFT) {
						if (playerX - 2 < 0 || game[playerY][playerX - 2] == 5 ||
							game[playerY - 1][playerX] == 5) continue;
						playerX--;
					}

					game[playerY][playerX] = Player;
					game[playerY][playerX + 1] = Player;
					game[playerY][playerX - 1] = Player;
					game[playerY - 1][playerX + 1] = Player;

					if (playerY + 1 == gameSize - 2 ||
						game[playerY + 1][playerX + 1] == 5 ||
						game[playerY + 1][playerX - 1] == 5 ||
						game[playerY + 1][playerX] == 5) {

						system("cls");
						display();
						key = _getch();
						if (key == 224) {
							game[playerY][playerX] = 0;
							game[playerY][playerX + 1] = 0;
							game[playerY][playerX - 1] = 0;
							game[playerY - 1][playerX + 1] = 0;
							key = _getch();
							if (key == DOWN) {
								if (playerY + 1 == gameSize - 2 ||
									game[playerY + 1][playerX + 1] == 5 ||
									game[playerY + 1][playerX - 1] == 5 ||
									game[playerY + 1][playerX] == 5
									) {
									game[playerY][playerX] = Player;
									game[playerY][playerX + 1] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY - 1][playerX + 1] = Player;
									isStoped = true;
									break;
								}
								playerY++;
							}

							else if (key == RIGHT) {
								if (playerX + 2 == gameSize - 2 || game[playerY][playerX + 2] == 5 ||
									game[playerY - 1][playerX + 2] == 5) {

									game[playerY][playerX] = Player;
									game[playerY][playerX + 1] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY - 1][playerX + 1] = Player;
									isStoped = true;
									break;
								}
								playerX++;
							}
							else if (key == LEFT) {
								if (playerX - 2 < 0 || game[playerY][playerX - 2] == 5 ||
									game[playerY - 1][playerX] == 5) {

									game[playerY][playerX] = Player;
									game[playerY][playerX + 1] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY - 1][playerX + 1] = Player;
									isStoped = true;
									break;
								}
								playerX--;
							}
							game[playerY][playerX] = Player;
							game[playerY][playerX + 1] = Player;
							game[playerY][playerX - 1] = Player;
							game[playerY - 1][playerX + 1] = Player;
							system("cls");
							display();
						}
						if (playerY + 1 == gameSize - 2 ||
							game[playerY + 1][playerX + 1] == 5 ||
							game[playerY + 1][playerX - 1] == 5 ||
							game[playerY + 1][playerX] == 5) {
							isStoped = true;
							break;
						}
					}
					game[playerY][playerX] = 0;
					game[playerY][playerX + 1] = 0;
					game[playerY][playerX - 1] = 0;
					game[playerY - 1][playerX + 1] = 0;
					if (key != DOWN
						)
					{
						playerY += 1;

					}
					game[playerY][playerX] = Player;
					game[playerY][playerX + 1] = Player;
					game[playerY][playerX - 1] = Player;
					game[playerY - 1][playerX + 1] = Player;
					if (playerY + 1 == gameSize - 2 ||
						game[playerY + 1][playerX + 1] == 5 ||
						game[playerY + 1][playerX - 1] == 5 ||
						game[playerY + 1][playerX] == 5) {

						system("cls");
						display();
						key = _getch();
						if (key == 224) {
							game[playerY][playerX] = 0;
							game[playerY][playerX + 1] = 0;
							game[playerY][playerX - 1] = 0;
							game[playerY - 1][playerX + 1] = 0;
							key = _getch();
							if (key == DOWN) {
								if (playerY + 1 == gameSize - 2 ||
									game[playerY + 1][playerX + 1] == 5 ||
									game[playerY + 1][playerX - 1] == 5 ||
									game[playerY + 1][playerX] == 5
									) {
									game[playerY][playerX] = Player;
									game[playerY][playerX + 1] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY - 1][playerX + 1] = Player;
									isStoped = true;
									break;
								}
								playerY++;
							}

							else if (key == RIGHT) {
								if (playerX + 2 == gameSize - 2 || game[playerY][playerX + 2] == 5 ||
									game[playerY - 1][playerX + 2] == 5) {

									game[playerY][playerX] = Player;
									game[playerY][playerX + 1] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY - 1][playerX + 1] = Player;
									isStoped = true;
									break;
								}
								playerX++;
							}
							else if (key == LEFT) {
								if (playerX - 2 < 0 || game[playerY][playerX - 2] == 5 ||
									game[playerY - 1][playerX] == 5) {

									game[playerY][playerX] = Player;
									game[playerY][playerX + 1] = Player;
									game[playerY][playerX - 1] = Player;
									game[playerY - 1][playerX + 1] = Player;
									isStoped = true;
									break;
								}
								playerX--;
							}
							game[playerY][playerX] = Player;
							game[playerY][playerX + 1] = Player;
							game[playerY][playerX - 1] = Player;
							game[playerY - 1][playerX + 1] = Player;
							system("cls");
							display();
						}
						if (playerY + 1 == gameSize - 2 ||
							game[playerY + 1][playerX + 1] == 5 ||
							game[playerY + 1][playerX - 1] == 5 ||
							game[playerY + 1][playerX] == 5) {
							isStoped = true;
							break;
						}
					}
				}//key 224 scope
			}//rotate scope


		}//Random 7 scope

		system("cls");
		display();
	}//while scope
	playerY = 0;
	playerX = 6;
	if (!GameOver)
	{
		control();
	}
}// func scope


void main() {

	//game[playerY][playerX] = Player;
	//game[playerY][playerX + 1] = Player;
	//game[playerY + 1][playerX] = Player;
	//game[playerY][playerX - 1] = Player;
	srand(time(0));
	display();
	control();
	do
	{
		mySetColor(4, 0);
		cout << "GAME OVER" << endl;
		cout << "Your Score " << Score << endl;

		cout << "Play Again? (Y/N)";
		cin >> PlayAgain;
		if (PlayAgain == 'Y' || PlayAgain == 'y')
		{
			system("cls");

			for (int i = 0; i < gameSize; i++)
			{
				for (int k = 0; k < gameSize; k++)
				{
					game[i][k] = 0;
				}
			}
			GameOver = false;
			isStoped = true;
			random2 = 1 + rand() % (7);
			Score = 0;
			mySetColor(7, 0);
			display();
			control();

		}
	} while (true);


}