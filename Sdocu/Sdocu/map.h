#pragma once
#include <array>
const int right =37;
const int down = 14;

enum class direction { stop, error, input, right, answer,delete_o };
class Map
{
	//array에서 0은 숫자, 입력 자리,  10 = - ,11 = |,  12 = " ",  13 = =
private:
	int Create_num[down][right] =
	{{ 12, 12, 12, 12, 12,  1, 12, 12,  2, 12, 12,  3, 12, 12, 12, 12,  4, 12, 12,  5, 12, 12,  6, 12, 12, 12, 12,  7, 12, 12,  8, 12, 12,  9, 12, 12, 12},
	 { 12, 12, 12, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13 } ,
	 {  1, 12, 11, 11, 12,  0, 12, 12,  0, 12, 12,  0, 12, 11, 11, 12,  0, 12, 12,  0, 12, 12,  0, 12, 11, 11, 12,  0, 12, 12,  0, 12, 12,  0, 12, 11, 11 } ,
	 {  2, 12, 11, 11, 12,  0, 12, 12,  0, 12, 12,  0, 12, 11, 11, 12,  0, 12, 12,  0, 12, 12,  0, 12, 11, 11, 12,  0, 12, 12,  0, 12, 12,  0, 12, 11, 11 } ,
	 {  3, 12, 11, 11, 12,  0, 12, 12,  0, 12, 12,  0, 12, 11, 11, 12,  0, 12, 12,  0, 12, 12,  0, 12, 11, 11, 12,  0, 12, 12,  0, 12, 12,  0, 12, 11, 11 } ,
	 { 12, 12, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13 } ,
	 {  4, 12, 11, 11, 12,  0, 12, 12,  0, 12, 12,  0, 12, 11, 11, 12,  0, 12, 12,  0, 12, 12,  0, 12, 11, 11, 12,  0, 12, 12,  0, 12, 12,  0, 12, 11, 11 } ,
	 {  5, 12, 11, 11, 12,  0, 12, 12,  0, 12, 12,  0, 12, 11, 11, 12,  0, 12, 12,  0, 12, 12,  0, 12, 11, 11, 12,  0, 12, 12,  0, 12, 12,  0, 12, 11, 11 } ,
	 {  6, 12, 11, 11, 12,  0, 12, 12,  0, 12, 12,  0, 12, 11, 11, 12,  0, 12, 12,  0, 12, 12,  0, 12, 11, 11, 12,  0, 12, 12,  0, 12, 12,  0, 12, 11, 11 } ,
	 { 12, 12, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13 } ,
	 {  7, 12, 11, 11, 12,  0, 12, 12,  0, 12, 12,  0, 12, 11, 11, 12,  0, 12, 12,  0, 12, 12,  0, 12, 11, 11, 12,  0, 12, 12,  0, 12, 12,  0, 12, 11, 11 } ,
	 {  8, 12, 11, 11, 12,  0, 12, 12,  0, 12, 12,  0, 12, 11, 11, 12,  0, 12, 12,  0, 12, 12,  0, 12, 11, 11, 12,  0, 12, 12,  0, 12, 12,  0, 12, 11, 11 } ,
	 {  9, 12, 11, 11, 12,  0, 12, 12,  0, 12, 12,  0, 12, 11, 11, 12,  0, 12, 12,  0, 12, 12,  0, 12, 11, 11, 12,  0, 12, 12,  0, 12, 12,  0, 12, 11, 11 } ,
	 { 12, 12, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13 }};
	
	///////////////////////// 키보드로 입력한 수가 변경하는 배열(핵심 ) 
	// 22는 화면에서 o로 보임
	int Number[9][9] =  
	/*{{  9,  3,  2, 14,  1,  6, 15,  7, 18 },
	  { 8,  4,  7,  5,  3, 19, 16, 11,  2 },
	 { 11,  6, 15,  8, 12,  7,  4, 13,  9 },
	 {  2,  5, 13,  6, 17, 11,  9,  8, 14 },
	  { 6, 11, 14,  3,  9,  8, 12, 15,  7 },
	 { 17,  9,  8, 12, 14,  5, 13,  6,  1 },
	  { 3, 12,  1,  7, 15,  4, 18,  9, 16 },
	  { 5, 18, 19, 11,  6,  2,  7,  4, 13 },
	 { 14,  7, 16,  9,  8, 13,  1,  2,  5 } };*/

	{	{ 16, 17,  0, 12, 14, 13,  0, 18, 11 },
		{  0,  0,  0,  0,  0,  0,  0,  0,  0 }, 
		{ 11,  0,  0,  0, 18,  0,  0,  0, 17 }, 
		{ 18,  0, 16, 17,  0, 11, 14,  0, 15 }, 
		{  0,  0,  0,  0, 12,  0,  0,  0,  0 }, 
		{ 17,  0, 11, 14,  0, 19, 16,  0, 18 }, 
		{ 19,  0,  0,  0, 17,  0,  0,  0, 14 }, 
		{  0,  0,  0,  0,  0,  0,  0,  0,  0 }, 
		{ 12, 18,  0, 15, 11, 16,  0, 19, 13 }};
	/////////////
public:
	int con[9][9] = {false}; //0 == 빈칸||== 플레이어가 입력한 수,  2 == 주어진 수  //주어진 수 못 지우게 함
	int Nx = 0;// coordinate of Number
	int Ny = 0;//
	int Numstore{0};
	int pastNumber{0};//처음 putN(Ny, Nx, pastNumber)을 썼을 때 Number배열에 past변수 값이 들어가게 되는 문제 해결 필요
	int o = 22;
	bool firstMove{ 1 };
	direction ios = direction::stop;
	//int nine[9] = { 0 };
	
	
	Map();

	direction move();
	
	void Creater();
	//bool SCchanger();//▒ ━ ┃ ┏ ┓ ┛ ┗ ┣ ┳ ┫ ┻ ╋   □ ■ △ ▲ ▽ ▼ 
	bool putSC();
	bool getSC();

	void putN(int& col, int& row, int& input);
	int getN(int& col, int& row);

	bool checkup();//맞았을 때 1 틀렸을 때 0 리턴
};
//