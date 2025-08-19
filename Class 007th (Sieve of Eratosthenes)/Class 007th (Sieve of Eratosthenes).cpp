#include <iostream>
#include <vector>

using namespace std;

void Sieve_Of_Eratosthenes(int n)
{
	int* prime = new int[n + 1];

	for (int i = 0; i <= n; i++)
	{
		prime[i] = i;
	}

	prime[0] = 0;
	prime[1] = 0;

	// 제곱근까지만 반복
	for (int i = 2; i * i <= n; i++)
	{
		if (prime[i] != 0)
		{
			// 배수만큼만 반복, 시작도 i제곱부터(그전 숫자들은 모두 판별이 완료되었으므로)
			for (int j = i * i; j <= n; j += i)
			{
				prime[j] = 0;
			}
		}
	}

	for (int i = 0; i <= n; i++)
	{
		if (prime[i] != 0)
		{
			cout << prime[i] << "  ";
		}
	}

	delete[] prime;

}

void sieve(int n)
{
	int* container = new int[n + 1];

	for (int i = 0; i < n; i++)
	{
		container[i] = i;
	}

	for (int i = 2; i <= sqrt(n); i++)
	{
		if (container[i] == 0)
		{
			continue;
		}

		for (int j = i * 2; j <= n; j += i)
		{
			container[j] = 0;
		}
	}

	for (int i = 2; i <= n; i++)
	{
		if (container[i] != 0)
		{
			cout << container[i] << "  ";
		}
	}

	delete[] container;


}


int main()
{
#pragma region 에라토스테네스의 체
	// 소수 : 1과 자기자신외에 나누어 떨어지지 않는 수

	// n을 입력했을 때 2 ~ n까지의 소수를 모두 출력하는 알고리즘
	// 시간복잡도 : O(n log log N) -- O(n)과 유사한 시간 복잡도

#pragma region 브루트 포스 방식으로 소수 판별
	//	int j = 0;
	//	int n = 0;
	//	
	//	std::cin >> n;
	//	
	//	for (int i = 2; i < n; i++)
	//	{
	//		for (j = 2; j <= n; j++)
	//		{
	//			if (i % j == 0)
	//			{
	//				break;
	//			}
	//		}
	//	
	//		if (i == j)
	//		{
	//			cout << i << " ";
	//		}
	//	}
#pragma endregion

	// Sieve_Of_Eratosthenes(100);
	sieve(100);


#pragma endregion


	return 0;
}