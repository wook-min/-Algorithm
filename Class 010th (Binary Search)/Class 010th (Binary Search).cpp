#include <iostream>

using namespace std;

void search(int list[], int key, int size)
{
	int left = 0;
	int right = size - 1;
	bool check = false;

	while (left <= right)
	{
		int pivot = (left + right) / 2;

		if (list[pivot] == key)
		{
			cout << "The Key index is " << pivot;
			check = true;
			break;
		}
		else
		{
			if (list[pivot] > key)
			{
				right = pivot - 1;
			}
			else
			{
				left = pivot + 1;
			}
		}
	}

	if (!check)
	{
		cout << "Key not found in List" << endl;
	}

}

int main()
{
#pragma region 이분 탐색(Two Pointer Algorithm)
	// 탐색 범위를 반으로 나누어 찾는 값을 포함하는 범위를
	// 좁혀나가는 방식으로 동작하는 알고리즘입니다.

	// 여기서 two pointer란 해당하는 변수의 index를 가리키는 것.
	// left, right로 배열의 각 index를 가리키며, left는 오른쪽으로 right는 왼쪽으로 이동
	// 이때 right가 left보다 작아질 때 이를 '엇갈림'이라 표현하며, 이때 탐색을 종료한다.

	// 탐색 시간복잡도 O(log n)

	// 1 2 15 19 33 45 60

	int list[] = { 5, 6, 11, 13, 27, 55, 66, 92 };

	int size = sizeof(list) / sizeof(list[0]);

	search(list, 66, size);

#pragma endregion

	return 0;
}