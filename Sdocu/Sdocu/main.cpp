/* 추가할 것 
파일로 초기화
파일로 스도쿠 생성
저장
불러오기
키보드로 화면 움직이고 입력하기+키보드로 정답확인*/

//목표
// 처음 생성 숫자 변경못하게 만들기o
// 숫자 입력기능o
//sys clso
//완성시 검사기능o
//저장 기능
//정답 확인 기능 1)정답을 입력하고 보여주는 것

//고쳐야 될 문제
//세로 가로 좌표 1~9에 값을 오버하면 화면이 안뜸 & 숫자 넣으라는 문장이 뜸 => 다시 입력하면 루프
//세로 가로 좌표 1~9에 영문자 넣으면 1~9사이 숫자 넣으라는 문장이 반복 실행

#define _CRT_SECURE_NO_WARNINGS
#include "map.h"
#include <iostream>
#include <vector>
#include <memory>
#include <conio.h>
#include <Windows.h>
int main()
{
	int hi{ 0 }, ro{ 0 };
	int num = 0;
	//bool go = 0;
	auto ismove = direction::stop;
	bool correct = 0;
	auto map = std::make_unique<Map>();
	do
	{
		
		
		map->Creater();
		
				ismove=map->move();
				
				if (ismove == direction::input)
				{
					do {
						std::cout << "1~9 사이의 수를 입력하세요:";
						std::cin >> num;
				system("cls");
					} while (!(num < 10 && num>0));
					map->putN(map->Ny,map->Nx , num);
					map->pastNumber = num;
				}
				if (ismove == direction::right)
				{
					correct=map->checkup();
				
				//자리1
				}
				while (_kbhit==0)
				{
					Sleep;
				}
				system("cls");
				if (correct == 0)//자리2
					std::cout << "wrong";//
		} while (correct == 0);
		map->Creater();
		std::cout << "정답\n";
	
		return 0;
}