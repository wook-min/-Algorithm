#include <iostream>

using namespace std;

int Find(int list[], int left, int right)
{
	if (left == right)
	{
		return list[left];
	}

	int count = (right + left) / 2;

	int leftMax = Find(list, left, count );
	int rightMax = Find(list, count + 1, right);

	return (leftMax > rightMax) ? leftMax : rightMax;
}

int main()
{
#pragma region 분할 정복(Divide & Conquer)
	// 주어진 2개 이상의 부분으로 문제를 나눈 뒤 각 부분 문제에 대한 답을
	// 재귀로 호출하여 계산한 다음, 그 답으로부터 전체 문제의 답을
	// 계산해내는 알고리즘입니다.

	// 분할 (Divide) : 주어진 문제를 두 개 혹은 그 이상의 형식으로 나눈다.
	
	// 정복 (Conquer) : 나누어진 문제를 재귀적으로 해결해서 나누어진 문제를
	// 더 이상 나누어서 문제가 필요없을때까지 계속 분할합니다.

	// 통합 (Combine) : 나누어서 해결한 문제들을 통합해서 원래 문제의 해답을 생성합니다.

	// 문제를 푸는 알고리즘이기 때문에, 문제의 종류에 따라 시간복잡도가 다르게 잡힘.
	// 궁금하면 마스터 정렬 찾아보기.

	int list[] = { 20, 15, 99, 1, 7, 100, 55, 109 };

	cout << "Max Value of List : " << Find(list, 0, 7) << endl;

#pragma endregion
	


	return 0;
}