#include <iostream>

using namespace std;

int main()
{
#pragma region 라이브러리
	// 정적 라이브러리 vs 동적 라이브러리

	// 정적 라이브러리 : .lib
	// 소스 파일과 연동되어(붙어서) 가져오는 처리가 빠름.
	// 아예 변하지 않을 경우는 정적이 더 유리(입출력 같은 것)

	// 동적 라이브러리 : .dll(Dynamic Library Link)
	// 외부에서 데이터를 받아서 옴.
	// 장점 : 실행파일의 크기가 커지지 않음
	// 단점 : 소스 파일의 버전과 호환이 안될 경우 링킹 시 에러 발생(x86 x64같은 경우도 포함)
#pragma endregion

#pragma region 거품 정렬
	// 서로 인접한 두 원소를 비교하여 정렬하는 알고리즘입니다.

	// 5 3 1 2 4
	// 오름차순 정렬.

	double list[] = { 3,5,6,1,2,7,4 };

	int size = sizeof(list) / sizeof(list[0]);

	for (int j = 0; j < size - 1; j++)
	{
		for (int i = 0; i < (size - j) - 1; i++)
		{
			if (list[i] > list[i + 1])
			{
				swap(list[i], list[i + 1]);
			}
		}
	}




	for (const auto& element : list)
	{
		cout << element << "  ";
	}






#pragma endregion


	return 0;
}