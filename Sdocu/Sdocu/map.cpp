#define _CRT_SECURE_NO_WARNINGS
#include "map.h"
#include <iostream>
#include <Windows.h>
#include <vector>
#include <conio.h>


Map::Map()
{
	for (int i = 0; i < 9; ++i)
	{
		for (int u = 0; u < 9; ++u)
			if (this->getN(i,u) != 0)
				con[i][u] = 2;
	}
/*	for (auto height = 0; height < down; ++height)
	{

		for (auto width = 0; width < right; ++width)
		{
			if (Create_num[height][width] == 0)
			{
				if (Number[i][u] == 0)
					std::cout << "-";
				if (Number[i][u] != 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
					
					std::cout << Number[i][u];
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				}
				++u;
				if (u > 8)
				{
					u = 0; ++i;
				}
			}
			else if (Create_num[height][width] == 11)
				std::cout << "|";
			else if (Create_num[height][width] == 12)
				std::cout << " ";
			else if (Create_num[height][width] == 13)
				std::cout << "=";
			else
				std::cout << Create_num[height][width];
		}
		std::cout << std::endl << "  ";
	}*/
}

int Map::getN(int& col, int& row)
{
	return Number[col][row];
}


void Map::Creater()
{
	int i = 0;
	int u = 0;
	std::cout << std::endl<<"  ";
	for (auto height = 0; height < down; ++height)
	{
		
		for (auto width = 0; width < right; ++width)
		{
			//스도쿠 숫자 입력 부분
			if (Create_num[height][width] == 0)
			{
				if (Number[i][u] == 0)
					std::cout << "-";
				else if (Number[i][u] > 10 && Number[i][u] < 20)
				{
					//////////////////////////주어진 수의 색을 녹색으로 바꿔준다.
					if (con[i][u] == 2)
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);

						std::cout << Number[i][u] - 10;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					}
				}
				////////////////////////////////////////////////////// 입력한 숫자를 판에 나타내는 코드
				else if (Number[i][u] > 0 && Number[i][u] < 10)
				{
					std::cout << Number[i][u];

				}
				else if (Number[i][u] == 22)
				{
					std::cout << "o";
				}

				++u;
				if (u > 8)
				{
					u = 0; ++i;
				}
			}
			//// 스도쿠 맵을 만드는 부분
			else if (Create_num[height][width] == 11)
				std::cout << "|";
			else if (Create_num[height][width] == 12)
				std::cout << " ";
			else if (Create_num[height][width] == 13)
				std::cout << "=";
			else
				std::cout << Create_num[height][width];

				//
		}
		std::cout << std::endl<<"  ";
	}
	if (this->ios == direction::error)
	{
		std::cout << "처음 정해져 있던 값은 바꿀수 없습니다.\n";
	}
}
	//bool SCchanger();
	bool putSC();
	bool getSC();

	void Map::putN(int& col, int& row,int& input)
	{
		Number[col][row] = input;
	}

	
	
	direction Map::move()//이 함수 안에서 o(22)와 x,y좌표(Nx,Ny)가 정해져야 됨, 처음 한번만
	{
		
		direction ios = direction::stop;
		char temp{ 0 };
		if (firstMove == 1)
		{
			firstMove = 0;
			pastNumber = Number[0][0];
					putN(Ny, Nx, o);
					
					
				
			
			
		}
		while(_kbhit() == 0)
		{
			Sleep;
		}
		
			temp=_getch();
			if (temp =='w' )
			{
				if (Ny > 0)
				{
					
					putN(Ny, Nx, pastNumber);
					pastNumber = getN(--Ny, Nx);
					putN(Ny, Nx, o);
					
				}
				return ios;
			}
			else if (temp =='s' )
			{
				if (Ny < 8)
				{
					putN(Ny, Nx, pastNumber);
					pastNumber = getN(++Ny, Nx);
					putN(Ny, Nx, o);
					//++Ny;
				}
				return ios;
			}
			else if (temp == 'a')
			{
				if (Nx > 0)
				{
					putN(Ny, Nx, pastNumber);
					pastNumber = getN(Ny, --Nx);
					putN(Ny, Nx, o);
					//--Nx;
				}
				return ios;
			}
			else if (temp == 'd')
			{
				if (Nx < 8)
				{
					putN(Ny, Nx, pastNumber);
					pastNumber = getN(Ny, ++Nx);
					putN(Ny, Nx, o);
					//++Nx;
				}
				return ios;
			}
			else if (temp == 'l')//숫자 변경
			{
				if (pastNumber > 10 && pastNumber<20)
				{
					ios = direction::error;
					return ios;
				}
				else
				{
					
					ios = direction::input;
					return ios;
				}
			}
			////////////해답 + 정답인지 확인
			else if (temp == 'n')//해답
			{
				ios = direction::answer;
				return ios;
			}
			else if (temp == 'm')//다 맞췄을 때 정답확인
			{
				putN(Ny, Nx, pastNumber);
				ios = direction::right;
				return ios;
			}
			/*else if (temp == '.')
			{

			}*/
			else
				return ios;
	}
		

	/*
				
				===================================
				|| -  2  3 || 1  1  2 || 1  2  3 ||
				|| -  2  3 || 1  1  2 || 1  2  3 ||
				|| -  2  3 || 1  1  2 || 1  2  3 ||
				===================================
				|| -  2  3 || 1  1  2 || 1  2  3 ||
				|| -  2  3 || 1  1  2 || 1  2  3 ||
                || -  2  3 || 1  1  2 || 1  2  3 ||
				===================================
				|| -  2  3 || 1  1  2 || 1  2  3 ||
				|| -  2  3 || 1  1  2 || 1  2  3 ||
				|| -  2  3 || 1  1  2 || 1  2  3 ||
				===================================



	
	*/

	bool Map::checkup()//정답확인
	{
		////////////////////////////////// 가로 확인
		std::vector<int> wid(9, 0);
		for (int i = 0; i < 9; i++)
		{
			for (int u = 0; u < 9; ++u)
			{
				if (Number[i][u] == 1|| Number[i][u] == 11)
					++wid[0];

				else if (Number[i][u] == 2|| Number[i][u] == 12)
					++wid[1];

				else if (Number[i][u] == 3|| Number[i][u] == 13)
					++wid[2];

				else if (Number[i][u] == 4|| Number[i][u] == 14)
					++wid[3];

				else if (Number[i][u] == 5|| Number[i][u] == 15)
					++wid[4];

				else if (Number[i][u] == 6|| Number[i][u] == 16)
					++wid[5];

				else if (Number[i][u] == 7|| Number[i][u] == 17)
					++wid[6];

				else if (Number[i][u] == 8|| Number[i][u] == 18)
					++wid[7];

				else if (Number[i][u] == 9|| Number[i][u] == 19)
					++wid[8];

				if (Number[i][u] == 22)
				{
					if(pastNumber>10)
						++wid[pastNumber-10];
					else if(pastNumber<10&&pastNumber>0)
						++wid[pastNumber-1];
				}
			}

				for (int i = 0; i < 9; ++i)
				{
					if (wid[i] != 1)
					{
						wid.assign(wid.size(), 0);
						return 0;
					}
				}
				wid.assign(wid.size(),0);
		}
		////////////////////////////////////// 세로 확인

		for (int i = 0; i < 9; i++)
		{
			for (int u = 0; u < 9; ++u)
			{
				if (Number[u][i] == 1 || Number[u][i] == 11)
					++wid[0];

				else if (Number[u][i] == 2 || Number[u][i] == 12)
					++wid[1];

				else if (Number[u][i] == 3 || Number[u][i] == 13)
					++wid[2];

				else if (Number[u][i] == 4 || Number[u][i] == 14)
					++wid[3];

				else if (Number[u][i] == 5 || Number[u][i] == 15)
					++wid[4];

				else if (Number[u][i] == 6 || Number[u][i] == 16)
					++wid[5];

				else if (Number[u][i] == 7 || Number[u][i] == 17)
					++wid[6];

				else if (Number[u][i] == 8 || Number[u][i] == 18)
					++wid[7];

				else if (Number[u][i] == 9 || Number[u][i] == 19)
					++wid[8];

				if (Number[u][i] == 22)
				{
					if (pastNumber > 10)
						++wid[pastNumber - 10];
					else if (pastNumber < 10 && pastNumber>0)
						++wid[pastNumber - 1];
				}
			}
				for (int i = 0; i < 9; ++i)
				{
					if (wid[i] != 1)
					{
						wid.assign(wid.size(), 0);
						return 0;
					}
				}
				wid.assign(wid.size(), 0);
		}

			//////////////////////////////////   ㄴ대각 확인

/*
			int* cross1 = new int[9];
			for (int i = 0; i < 9; i++)
			{

				if (Number[i][i] == 1)
					++*cross1;

				else if (Number[i][i] == 2)
					++*(cross1 + 1);

				else if (Number[i][i] == 3)
					++*(cross1 + 2);

				else if (Number[i][i] == 4)
					++*(cross1 + 3);

				else if (Number[i][i] == 5)
					++*(cross1 + 4);

				else if (Number[i][i] == 6)
					++*(cross1 + 5);

				else if (Number[i][i] == 7)
					++*(cross1 + 6);

				else if (Number[i][i] == 8)
					++*(cross1 + 7);

				else if (Number[i][i] == 9)
					++*(cross1 + 8);


				for (int i = 0; i < 9; ++i)
				{
					if (++*(cross1 + i) > 1)
						return 0;
					delete[] cross1;
				}
			}
			////////////////////////////////////////////////    /대각 확인
			int* cross2 = new int[9];
			int temp = 8;
			for (int i = 0; i < 9; i++)
			{

				if (Number[temp--][i] == 1)
					++*cross2;

				else if (Number[temp--][i] == 2)
					++*(cross2 + 1);

				else if (Number[temp--][i] == 3)
					++*(cross2 + 2);

				else if (Number[temp--][i] == 4)
					++*(cross2 + 3);

				else if (Number[temp--][i] == 5)
					++*(cross2 + 4);

				else if (Number[temp--][i] == 6)
					++*(cross2 + 5);

				else if (Number[temp--][i] == 7)
					++*(cross2 + 6);

				else if (Number[temp--][i] == 8)
					++*(cross2 + 7);

				else if (Number[temp--][i] == 9)
					++*(cross2 + 8);

				for (int i = 0; i < 9; ++i)
				{
					if (++*(cross2 + i) > 1)
						return 0;
					delete[] cross2;
				}
			}
			*/
			//////////////////////////////////    3x3행렬 확인
			for (int p = 0; p < 9; p += 3)
			{
				for (int k = 0; k < 9; k += 3)
				{
					for (int i = 0 + p; i < 3 + p; ++i)
					{
						for (int u = 0 + k; u < 3 + k; ++u)
						{
							if (Number[i][u] == 1|| Number[i][u] == 11)
								++wid[0];

							else if (Number[i][u] == 2|| Number[i][u] == 12)
								++wid[1];

							else if (Number[i][u] == 3|| Number[i][u] == 13)
								++wid[2];

							else if (Number[i][u] == 4|| Number[i][u] == 14)
								++wid[3];

							else if (Number[i][u] == 5|| Number[i][u] == 15)
								++wid[4];

							else if (Number[i][u] == 6|| Number[i][u] == 16)
								++wid[5];

							else if (Number[i][u] == 7|| Number[i][u] == 17)
								++wid[6];

							else if (Number[i][u] == 8|| Number[i][u] == 18)
								++wid[7];

							else if (Number[i][u] == 9|| Number[i][u] == 19)
								++wid[8];

							if (Number[i][u] == 22)
							{
								if (pastNumber>10)
									++wid[pastNumber - 10];
								else if (pastNumber<10 && pastNumber>0)
									++wid[pastNumber - 1];
							}

						}
					}
							for (int i = 0; i < 9; ++i)
							{
								if (wid[i] != 1)
								{
									wid.assign(wid.size(), 0);
									return 0;
								}
							}
							wid.assign(wid.size(), 0);
				}
			}
		
			return 1; //// 정답일 때
	}