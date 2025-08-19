#include <iostream>

using namespace std;


int main()
{
#pragma region 계수 정렬
	// 데이터의 값을 비교하지 않고, 각 원소에 데이터가 몇 개 있는지
	// 개수를 세어 저장한 다음 정렬하는 알고리즘입니다.

	// 시간복잡도 O(n + k) : n >> 정렬한 요소의 개수 k >> 정수 데이터 중 최댓값

#pragma region 내가 한 방법
	int container[] = { 1, 1, 3, 1, 2, 3, 4, 4, 2, 5 };

	int size = sizeof(container) / sizeof(container[0]);

	int count = 0;

	for (int i = 0; i < size; i++)
	{
		if (container[i] > count)
		{
			count = container[i];
		}
	}

	int* list = new int[count];

	for (int i = 0; i < count; i++)
	{
		list[i] = 0;
	}

	for (int j = 0; j < size; j++)
	{
		list[container[j] - 1]++;
	}

	for (int i = 0; i < count; i++)
	{
		if (list[i] != 0)
		{
			for (int j = 0; j < list[i]; j++)
			{
				cout << i + 1 << " ";
			}
		}
	}

#pragma endregion

	//	int list[] = { 1, 1, 3, 1, 2, 3, 4, 4, 2, 5 };
	//	
	//	int size = sizeof(list) / sizeof(list[0]);
	//	
	//	int count[5] = { 0, };
	//	
	//	for (int i = 0; i < size; i++)
	//	{
	//		count[list[i] - 1]++;
	//	}
	//	
	//	for (int i = 0; i < 5; i++)
	//	{
	//		if (list[i] != 0)
	//		{
	//			for (int j = 0; j < count[i]; j++)
	//			{
	//				cout << i + 1 << "  ";
	//			}
	//		}
	//	}

#pragma endregion



	return 0;
}