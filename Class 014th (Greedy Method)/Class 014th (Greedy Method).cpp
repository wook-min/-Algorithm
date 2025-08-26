#include <iostream>
#include <vector>

using namespace std;

// 내가 풀어본것
void Change_Cash(int cost)
{
	std::vector<int> changeList = { 0,0,0,0,0 };

	if (cost >= 1000)
	{
		while (cost >= 1000)
		{
			cost -= 1000;
			changeList[0]++;
		}
	}

	if (cost >= 500)
	{
		while (cost >= 500)
		{
			cost -= 500;
			changeList[1]++;
		}
	}

	if (cost >= 100)
	{
		while (cost >= 100)
		{
			cost -= 100;
			changeList[2]++;
		}
	}

	if (cost >= 50)
	{
		while (cost >= 50)
		{
			cost -= 50;
			changeList[3]++;
		}
	}

	if (cost >= 10)
	{
		while (cost != 0)
		{
			cost -= 10;
			changeList[4]++;
		}
	}

	int total = 0;
	for (const auto& element : changeList)
	{
		total += element;
	}

	if (changeList[0] != 0)
	{
		cout << "1000원 : " << changeList[0] << "개" << endl;
	}

	if (changeList[1] != 0)
	{
		cout << "500원 : " << changeList[1] << "개" << endl;
	}

	if (changeList[2] != 0)
	{
		cout << "100원 : " << changeList[2] << "개" << endl;
	}

	if (changeList[3] != 0)
	{
		cout << "50원 : " << changeList[3] << "개" << endl;
	}

	if (changeList[4] != 0)
	{
		cout << "10원 : " << changeList[4] << "개" << endl;
	}

	cout << "총 거스름돈 갯수 : " << total << "개" << endl;
}

int main()
{
#pragma region 탐욕법
	// 최적의 해를 구하는 데에 사용되는 근사적인 방법으로, 여러 경우 중
	// 하나를 검색해야 할 때마다 그 순간에 최적이라고 생각되는 것을 선택해
	// 나가는 방식으로 진행하여 최종적인 해답을 구하는 알고리즘입니다.

	// 1. 탐욕 선택 속성
	// 각 단계에서 '최적의 선택'을 했을 때 전체 문제에 대한
	// 최적의 해를 구할 수 있는 경우입니다.

	// 2. 최적 부분 구조
	// 전체 문제의 최적의 해가 '부분 문제의 최적의 해로 구성'될 수 있는 경우입니다.

	// ------------------------------------------------------------------
	// 탐욕 알고리즘으로 문제를 해결하는 방법

	// 1. 선택 절차 (Selection Procedure)
	// 현재 상태에서의 최적의 해답을 선택합니다.

	// 2. 적절성 검사 (Feasiblity Check)
	// 선택된 해가 문제의 조건을 만족하는 지 검사합니다.

	// 3. 해답 검사 (Solution Check)
	// 원래의 문제가 해결되었는지 검사하고, 해결되지 않았다면
	// 선택 절차로 돌아가 위의 과정을 반복합니다.

	// ex) 거스름돈 문제
	// 1000원, 500원, 100원, 50원, 10원만 있다고 생각합니다.
	// 
	// 이 문제가 탐욕법인 이유
	// 1. 선택 절차 : 가장 큰 액수의 동전을 선택합니다.
	// 2. 적절성 검사 : 거스름돈의 총액이 거슬러주어야 할 액수를 넘지 않는다면, 
	// 방금 고른 동전을 거스름돈에 추가합니다.
	// 3. 해답 검사 : 거스름돈의 총액이 거슬러주어야 할 액수와 같은지 검사합니다.
	// 만약 같지 않다면, 선택 절차로 돌아가 이 작업을 반복합니다.

	int n = 1370;
	int count = 0;

	while (n >= 10)
	{
		if (n >= 1000)
		{
			n -= 1000;
		}
		else if (n >= 500)
		{
			n -= 500;
		}
		else if (n >= 100)
		{
			n -= 100;
		}
		else if (n >= 50)
		{
			n -= 50;
		}
		else if (n >= 10)
		{
			n -= 10;
		}

		count++;
	}

	cout << "Count : " << count << endl;

	// Change_Cash(1370);

#pragma endregion




	return 0;
}