#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

template <typename T>
class Graph
{
private:
	unordered_set<T> visited; // 해시 테이블 내부 구조(삽입, 삭제, 탐색의 시간복잡도 O(1))
	unordered_map<T, vector<T>> adjacencyList;
public:
	Graph()
	{

	}
	void insert(const T& i, const T& j)
	{
		adjacencyList[i].push_back(j);
		adjacencyList[j].push_back(i);
	}
	void search(const T& start)
	{
		if (visited.find(start) == visited.end())
		{
			visited.insert(start);

			for (const auto& element : adjacencyList[start])
			{
				search(element);
			}
		}
		else
		{
			return;
		}
	}
	void search(const T& start, bool check)
	{
		if (visited.count(start))
		{
			return;
		}

		visited.insert(start);

		cout << start << "  ";

		for (const T& element : adjacencyList[start])
		{
			if (visited.count(element) == false)
			{
				search(element);
			}
		}
	}
	void print()
	{
		for (const auto& element : visited)
		{
			cout << element << "  ";
		}
	}
	void reset_visited()
	{
		visited.clear();
	}

};

int main()
{
#pragma region 깊이 우선 탐색 (Depth First Search)
	// 그래프에서 한 방향으로 갈 수 있을 만큼 깊이 들어갔다가, 더 이상
	// 갈 수 없으면 다시 돌아와서 다른 경로를 탐색하는 방법입니다.

	// 자료형은 stack 사용 + 방문 체크용 벡터<bool> 생성
	// 

	Graph<char> graph;

	graph.insert('A', 'B');
	graph.insert('A', 'C');

	graph.insert('B', 'D');
	graph.insert('B', 'E');

	graph.insert('C', 'F');

	graph.insert('F', 'G');

	graph.search('A');
	graph.print();

	graph.search('A', true);

#pragma endregion




	return 0;
}