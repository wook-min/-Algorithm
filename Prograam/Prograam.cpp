#include <iostream>

using namespace std;


void insert_Sort(int list[], int start, int size, int gap)
{
	int key = 0;
	int j = 0;

	for (int i = start + gap; i < size; i += gap)
	{
		key = list[i];
		j = i - gap;

		while (j >= start && list[j] > key)
		{
			list[j + gap] = list[j];
			j -= gap;
		}

		list[j + gap] = key;
	}
	// 4
	// 0 
}

int main()
{
#pragma region 쉘 정렬()
	// 리스트를 일정한 간격에 따라 나누고, 각 부분 리스트를 삽입 정렬을 통해
	// 정렬하는 방법입니다.

	// 삽입 정렬을 개선한 정렬
	
	// 시간복잡도 : O(n 1.25)

	// 1. 초기 시작 간격(gap)을 설정합니다.

	// 2. 간격 단위로 그룹을 묶어서 리스트를 나눕니다.

	// 3. 각 그룹의 n번째 원소들끼리 삽입 정렬을 수행합니다.

	// 4. 간격의 크기를 반으로 줄입니다.

	// 5. 간격이 1이 될 때까지 2 ~ 4번을 반복합니다.

	// 14 57 21 8 36 25 32 19
	// 초기 간격 : 배열 크기 / 2

	int list[] = {14, 57, 21, 8, 36, 25, 32, 19};
	
	int size = sizeof(list) / sizeof(list[0]);

	for (int gap = size / 2; gap > 0; gap /= 2)
	{
		for (int i = 0; i < gap; i++)  // 그룹별 삽입 정렬
		{
			insert_Sort(list, i, size, gap);
		}
	}

	// 0 8 4

	for (const auto& element : list)
	{
		cout << element << "  ";
	}
#pragma endregion



	return 0;
}