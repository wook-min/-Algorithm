#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

template <typename T>
class Graph
{
private:
	unordered_map<T, vector<T>> adjacencyList;
public:
	Graph() {}
	void insert(const T& i, const T& j)
	{
		adjacencyList[i].push_back(j);
		adjacencyList[j].push_back(i);
	}
	void sort(const T& start)
	{
		queue<T> queue;
		unordered_set<T> visited;

		queue.push(start);
		visited.insert(start);

		while (queue.size() != 0) // 또는 queue.empty() == false
		{
			T temp = queue.front();
			queue.pop();

			for (const auto& element : adjacencyList[temp])
			{
				if (visited.find(element) == visited.end()) // 또는 visited.count(element) == false
				{
					queue.push(element);
					visited.insert(element);
				}
			}
		}

		for (const auto& element : visited)
		{
			cout << element << "  ";
		}
	}
};

int main()
{
#pragma region 너비 우선 탐색(BFS:Breath First Search)
	// 하나의 시작 정점을 방문한 후, 시작 정점에 인접한 모든 정점들을 
	// 우선적으로 방문하는 탐색입니다.

	// 자료구조 Queue 사용

	Graph<char> graph;

	graph.insert('A', 'B');
	graph.insert('A', 'C');

	graph.insert('B', 'D');
	graph.insert('B', 'E');

	graph.insert('C', 'F');
	graph.insert('C', 'G');

	graph.sort('A');

#pragma endregion


	return 0;
}