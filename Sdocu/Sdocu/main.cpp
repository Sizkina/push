/* �߰��� �� 
���Ϸ� �ʱ�ȭ
���Ϸ� ������ ����
����
�ҷ�����
Ű����� ȭ�� �����̰� �Է��ϱ�+Ű����� ����Ȯ��*/

//��ǥ
// ó�� ���� ���� ������ϰ� �����o
// ���� �Է±��o
//sys clso
//�ϼ��� �˻���o
//���� ���
//���� Ȯ�� ��� 1)������ �Է��ϰ� �����ִ� ��

//���ľ� �� ����
//���� ���� ��ǥ 1~9�� ���� �����ϸ� ȭ���� �ȶ� & ���� ������� ������ �� => �ٽ� �Է��ϸ� ����
//���� ���� ��ǥ 1~9�� ������ ������ 1~9���� ���� ������� ������ �ݺ� ����

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
						std::cout << "1~9 ������ ���� �Է��ϼ���:";
						std::cin >> num;
				system("cls");
					} while (!(num < 10 && num>0));
					map->putN(map->Ny,map->Nx , num);
					map->pastNumber = num;
				}
				if (ismove == direction::right)
				{
					correct=map->checkup();
				
				//�ڸ�1
				}
				while (_kbhit==0)
				{
					Sleep;
				}
				system("cls");
				if (correct == 0)//�ڸ�2
					std::cout << "wrong";//
		} while (correct == 0);
		map->Creater();
		std::cout << "����\n";
	
		return 0;
}