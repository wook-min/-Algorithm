#include <iostream>

using namespace std;

int main()
{
#pragma region 선택 정렬
	// 주어진 리스트 중에 최소값을 찾은 다음 특정한 위치에서
	// 결과를 교체하는 방식으로 정렬하는 알고리즘입니다.

	int list[] = { 8, 5, 10, 7, 1, 3, 2, 6, 4, 9 };

	int size = sizeof(list) / sizeof(list[0]);

	int index = 0;

	for (int i = 0; i < size; i++)
	{
		index = i;

		for (int j = i; j < size; j++)
		{
			if (list[index] > list[j])
			{
				index = j;
			}
		}

		if (index != i)
		{
			swap(list[i], list[index]);
		}
	}

	/*
	for (int i = 0; i < size - 1; i++)
	{
		int min = list[i];
		int index = i;
		for (int j = 0; j < size; j++)
		{
			if (min > list[j])
			{
				min = list[j];
				index = j;
			}
		}
		if (index != i)
		{
			swap(list[i], list[index]);
		}
	}
	*/


	for (const auto& element : list)
	{
		cout << element << "  ";
	}

#pragma endregion



	return 0;
}