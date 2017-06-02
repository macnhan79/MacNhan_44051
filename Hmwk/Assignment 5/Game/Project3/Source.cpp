#include <iostream>
#include <string>
#include <Windows.h>
#include <ctime>
using namespace std;

char map[50][50]; // M?ng 2 chi?u c�c k� t?.


// H�m thay ??i k�ch c? c?a khung cmd.
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, 

height, TRUE);
}

// H�m t� m�u.
void textcolor(int x)
{
	HANDLE mau;
	mau=GetStdHandle

(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}

// H�m d?ch chuy?n con tr? ??n t?a ?? x, y.
void gotoxy(int x,int y)
{    
	HANDLE hConsoleOutput;    
	COORD Cursor_an_Pos = {x-1,y-1};   
	hConsoleOutput = GetStdHandle

(STD_OUTPUT_HANDLE);    
	SetConsoleCursorPosition(hConsoleOutput , 

Cursor_an_Pos);
}

// H�m x�a m�n h�nh.
void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle

(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

void VeDuongDua_1()
{
	// D�i 30, r?ng 30.
	for(int i = 0; i < 30; i++)
	{
		map[i][0] = '|';
		map[i][29] = '|';
		if(i % 2 == 0)
		{
			map[i][14] = '|';
		}

		for(int j = 1; j < 29 && j != 14; j++)
		{
			map[i][j] = ' ';
		}
	}
}

void VeDuongDua_2()
{
	// D�i 30, r?ng 30.
	for(int i = 0; i < 30; i++)
	{
		map[i][0] = '|';
		map[i][29] = '|';
		if(i % 2 != 0)
		{
			map[i][14] = '|';
		}

		for(int j = 1; j < 29 && j != 14; j++)
		{
			map[i][j] = ' ';
		}
	}
}

void InDuongDua()
{
	// D�i 30, r?ng 30.
	for(int i = 0; i < 30; i++)
	{
		cout << "\t\t\t";
		for(int j = 0; j < 30; j++)
		{
			/* ============ In ???ng ?ua ========== */
			if(j == 0 || j == 29)
			{
				textcolor(191);
				map[i][j] = ' ';
				cout << map[i][j];
				textcolor(7);
			}
			else if(j == 14)
			{
				textcolor(15);
				cout << map[i][j];
				textcolor(7);

				map[i][j] = ' '; // X�a l?n ?i.
			}
			
			/* ================================= */

			/* IN XE PLAYER */
			else if(map[i][j] == 'X' || map[i][j] == '@' || map[i][j] == '#')
			{
				textcolor(14); // M�u v�ng.
				cout << map[i][j];
				textcolor(7); // Tr? l?i m�u b�nh th??ng.
			}

			/* IN XE COMPUTER */
			else if(map[i][j] == '!')
			{
				//map[i][j] = ' '; // B? ?i k� t? '!'
				textcolor(200);
				cout << map[i][j];
				textcolor(7);
			}

			// Nh?ng k� t? kh�ng ph?i l� xe.
			else
			{
				cout << map[i][j];
			}
		}
		cout << endl;
	}
}

void VeXePlayer(int x, int y)
{
	map[x][y] = 'X'; // Th�n xe.
	map[x][y - 1] = '#'; // B�n tr�i th�n xe.
	map[x][y + 1] = '#'; // B�n ph?i th�n xe.
	map[x - 1][y - 1] = '@'; // B�nh xe tr�n b�n tr�i.
	map[x + 1][y - 1] = '@'; // B�nh xe d??i b�n tr�i.
	map[x - 1][y + 1] = '@'; // B�nh xe tr�n b�n ph?i.
	map[x + 1][y + 1] = '@'; // B�nh xe d??i b�n ph?i.
}

void VeXeChuongNgaiVat(int x, int y)
{
	map[x][y] = '!'; // Th�n xe.
	map[x][y - 1] = '!'; // B�n tr�i th�n xe.
	map[x][y + 1] = '!'; // B�n ph?i th�n xe.
	map[x - 1][y - 1] = '!'; // B�nh xe tr�n b�n tr�i.
	map[x + 1][y - 1] = '!'; // B�nh xe d??i b�n tr�i.
	map[x - 1][y + 1] = '!'; // B�nh xe tr�n b�n ph?i.
	map[x + 1][y + 1] = '!'; // B�nh xe d??i b�n ph?i.
}

void XoaXeChuongNgai(int x, int y)
{
	map[x][y] = ' '; // Th�n xe.
	map[x][y - 1] = ' '; // B�n tr�i th�n xe.
	map[x][y + 1] = ' '; // B�n ph?i th�n xe.
	map[x - 1][y - 1] = ' '; // B�nh xe tr�n b�n tr�i.
	map[x + 1][y - 1] = ' '; // B�nh xe d??i b�n tr�i.
	map[x - 1][y + 1] = ' '; // B�nh xe tr�n b�n ph?i.
	map[x + 1][y + 1] = ' '; // B�nh xe d??i b�n ph?i.
}

void DiChuyenXe(int &x, int &y) // x, y l� t?a ?? hi?n t?i c?a xe.
{
	/* 
		
		Tr�i Tr�n c�ng: 1, 2
		Tr�i d??i c�ng: 28, 2
		ph?i tr�n c�ng: 1, 27
		ph?i d??i c�ng: 28, 27
		*/

	// qua tr�i.
	if(GetAsyncKeyState(VK_LEFT))
	{
		if(y > 2)
		{
			// ?ang so s�nh xem c� b? tr�ng v?i xe t?nh & xe ??ng hay kh�ng ?
			if(map[x][y] == '!' || map[x][y - 1] == '!' || map[x][y + 1] == '!' || map[x - 1][y - 1] == '!' || map[x + 1][y - 1] == '!' || map[x - 1][y + 1] == '!' || map[x + 1][y + 1] == '!')
			{
				// printf("\a"); // Ti?ng beep.
				exit(0); // K?t th�c.
			}

			// X�a xe ?i.
			map[x][y] = ' '; // Th�n xe.
			map[x][y - 1] = ' '; // B�n tr�i th�n xe.
			map[x][y + 1] = ' '; // B�n ph?i th�n xe.
			map[x - 1][y - 1] = ' '; // B�nh xe tr�n b�n tr�i.
			map[x + 1][y - 1] = ' '; // B�nh xe d??i b�n tr�i.
			map[x - 1][y + 1] = ' '; // B�nh xe tr�n b�n ph?i.
			map[x + 1][y + 1] = ' '; // B�nh xe d??i b�n ph?i.

			y--; // Gi?m c?t xu?ng.
			VeXePlayer(x, y); // V? l?i xe.

			
		}
		
	}

	// qua ph?i.
	else if(GetAsyncKeyState(VK_RIGHT))
	{
		if(y <= 26)
		{
			// ?ang so s�nh xem c� b? tr�ng v?i xe t?nh & xe ??ng hay kh�ng ?
			if(map[x][y] == '!' || map[x][y - 1] == '!' || map[x][y + 1] == '!' || map[x - 1][y - 1] == '!' || map[x + 1][y - 1] == '!' || map[x - 1][y + 1] == '!' || map[x + 1][y + 1] == '!')
			{
				// printf("\a"); // Ti?ng beep.
				exit(0); // K?t th�c.
			}

			// X�a xe ?i.
			map[x][y] = ' '; // Th�n xe.
			map[x][y - 1] = ' '; // B�n tr�i th�n xe.
			map[x][y + 1] = ' '; // B�n ph?i th�n xe.
			map[x - 1][y - 1] = ' '; // B�nh xe tr�n b�n tr�i.
			map[x + 1][y - 1] = ' '; // B�nh xe d??i b�n tr�i.
			map[x - 1][y + 1] = ' '; // B�nh xe tr�n b�n ph?i.
			map[x + 1][y + 1] = ' '; // B�nh xe d??i b�n ph?i.

			y++; // T?ng c?t l�n.
			VeXePlayer(x, y); // V? l?i xe.

			
		}
	}

	// ?i l�n.
	else if(GetAsyncKeyState(VK_UP))
	{
		if(x > 1)
		{
			// ?ang so s�nh xem c� b? tr�ng v?i xe t?nh & xe ??ng hay kh�ng ?
			if(map[x][y] == '!' || map[x][y - 1] == '!' || map[x][y + 1] == '!' || map[x - 1][y - 1] == '!' || map[x + 1][y - 1] == '!' || map[x - 1][y + 1] == '!' || map[x + 1][y + 1] == '!')
			{
				// printf("\a"); // Ti?ng beep.
				exit(0); // K?t th�c.
			}

			// X�a xe ?i.
			map[x][y] = ' '; // Th�n xe.
			map[x][y - 1] = ' '; // B�n tr�i th�n xe.
			map[x][y + 1] = ' '; // B�n ph?i th�n xe.
			map[x - 1][y - 1] = ' '; // B�nh xe tr�n b�n tr�i.
			map[x + 1][y - 1] = ' '; // B�nh xe d??i b�n tr�i.
			map[x - 1][y + 1] = ' '; // B�nh xe tr�n b�n ph?i.
			map[x + 1][y + 1] = ' '; // B�nh xe d??i b�n ph?i.

			x--; // Gi?m s? d�ng.
			VeXePlayer(x, y); // V? l?i xe.
		}
	}

	// ?i xu?ng
	else if(GetAsyncKeyState(VK_DOWN))
	{
		if(x <= 27)
		{
			// ?ang so s�nh xem c� b? tr�ng v?i xe t?nh & xe ??ng hay kh�ng ?
			if(map[x][y] == '!' || map[x][y - 1] == '!' || map[x][y + 1] == '!' || map[x - 1][y - 1] == '!' || map[x + 1][y - 1] == '!' || map[x - 1][y + 1] == '!' || map[x + 1][y + 1] == '!')
			{
				// printf("\a"); // Ti?ng beep.
				exit(0); // K?t th�c.
			}

			// X�a xe ?i.-
			map[x][y] = ' '; // Th�n xe.
			map[x][y - 1] = ' '; // B�n tr�i th�n xe.
			map[x][y + 1] = ' '; // B�n ph?i th�n xe.
			map[x - 1][y - 1] = ' '; // B�nh xe tr�n b�n tr�i.
			map[x + 1][y - 1] = ' '; // B�nh xe d??i b�n tr�i.
			map[x - 1][y + 1] = ' '; // B�nh xe tr�n b�n ph?i.
			map[x + 1][y + 1] = ' '; // B�nh xe d??i b�n ph?i.

			x++; // T?ng s? d�ng.
			VeXePlayer(x, y); // V? l?i xe.
		}
	}
}



int main()
{
	
	resizeConsole(800, 600);

	int x = 20, y = 15; // T?a ?? c?a xe Player.
	int x1 = 2, y1; // T?a ?? xe ch??ng ng?i v?t ??ng.
	int x2 = 5, y2 = 10; // T?a ?? xe ch??ng ng?i v?t t?nh.

	int a = 0;
	while(true)
	{
		a++;
		if(a % 2 != 0)
		{
			VeDuongDua_1();
		}
		else
		{
			VeDuongDua_2();
		}

		// Random tung ?? cho xe computer.
		/* 
		Mu?n random 1 s? nguy�n trong ?o?n [a, b]:
		srand(time(0)); // Reset th?i gian
		int x = a + rand() % (b - a + 1); // C�ng th?c
		*/

		srand(time(0)); // Reset th?i gian
		y1 = 2 + rand() % 26; // [2, 27]

		VeXePlayer(x, y);
		VeXeChuongNgaiVat(x1, y1); // Xe ??ng.
		VeXeChuongNgaiVat(x2, y2); // Xe t?nh.

		XoaManHinh();
	
		InDuongDua();

		DiChuyenXe(x, y);

		Sleep(0);

		if(a >= 30)
		{
			a = 0;
		}

		// Ki?m tra ??ng ?? gi?a xe player v� xe t?nh
		//map[x][y] = ' '; // Th�n xe.
		//map[x][y - 1] = ' '; // B�n tr�i th�n xe.
		//map[x][y + 1] = ' '; // B�n ph?i th�n xe.
		//map[x - 1][y - 1] = ' '; // B�nh xe tr�n b�n tr�i.
		//map[x + 1][y - 1] = ' '; // B�nh xe d??i b�n tr�i.
		//map[x - 1][y + 1] = ' '; // B�nh xe tr�n b�n ph?i.
		//map[x + 1][y + 1] = ' '; // B�nh xe d??i b�n ph?i.

		// ?ang so s�nh xem c� b? tr�ng v?i xe t?nh & xe ??ng hay kh�ng ?
		if(map[x][y] == '!' || map[x][y - 1] == '!' || map[x][y + 1] == '!' || map[x - 1][y - 1] == '!' || map[x + 1][y - 1] == '!' || map[x - 1][y + 1] == '!' || map[x + 1][y + 1] == '!')
		{
			// printf("\a"); // Ti?ng beep.
			return 0; // K?t th�c.
		}

		XoaXeChuongNgai(x1, y1);
		x1++; // T?ng d�ng l�n, t?o hi?u ?ng di chuy?n.
		if(x1 == 31)
		{
			x1 = 2;
		}

		XoaXeChuongNgai(x2, y2);
		x2++;
		if(x2 == 31)
		{
			x2 = 5;
			y2 = 2 + rand() % 26; // [2, 27]
		}
	}
	
	/*for(int i = 0; i <= 200; i++)
	{
		textcolor(i);
		cout << "\n=> i = " << i;
	}*/

	system("pause");
	return 0;
}