#include <iostream>
#include <vector>

using namespace std;

#define INFINITY 10000000

template<typename T>
class Dijkstra
{
private:
	vector<T> visited;	// 방문 체크용 행렬
	vector<int> distance; // 시작점에서부터 각 노드까지 가는데에 필요한 가중치 값
	vector<vector<T>> adjacencyMatrix; // 인접행렬
	void resize(int node)
	{
		int newSize = node + 1;

		if (adjacencyMatrix.size() < newSize)
		{
			int size = distance.size();

			adjacencyMatrix.resize(newSize);
			for (auto& element : adjacencyMatrix)
			{
				element.resize(newSize);
			}

			visited.resize(newSize);
			distance.resize(newSize, INFINITY); 
			// resize 오버로드 함수로, 확장하는 인덱스만 뒤의 값으로 초기화시킴

			for (int i = 0; i < adjacencyMatrix.size(); i++)
			{
				adjacencyMatrix[i][i] = 0;
			}
		}
	}
public:
	void insert(const T& i, const T& j, int weight)
	{
		i > j ? resize(i) : resize(j);

		adjacencyMatrix[i][j] = weight;
		adjacencyMatrix[j][i] = weight;
	}
};

int main()
{
#pragma region 다익스트라 알고리즘(Dijkstra Algorithm)
	// 시작점으로부터 모든 노드까지의 최소 거리를 구해주는 알고리즘입니다.
	// 시간복잡도 (기본 : n^2, 우선순위큐로 커스터마이징해서 줄일 수 있음)

	// 1. 거리 배열에서 weight[시작 노드]의 값들로 초기화합니다.

	// 2. 시작점을 방문 처리합니다.

	// 3. 거리 배열에서 최소 비용 노드를 찾고 방문 처리합니다.

	// 4. 최소 비용 노드를 거쳐갈 지 고민해서 거리 배열을 갱신합니다.
	//	  단, 이미 방문한 노드는 제외합니다.

	// 5. 모든 노드를 방문할때까지 3 ~ 4번을 반복합니다.
	
	// 방문하지 않은 노드 중에서 가장 작은 거리를 가진 노드를 방문하고,
	// 그 노드와 연결된 다른 노드까지의 거리를 계산합니다.

	Dijkstra<int> dijkstra;

	dijkstra.insert(1, 2, 2);
	dijkstra.insert(1, 3, 5);
	dijkstra.insert(1, 4, 1);

	dijkstra.insert(2, 3, 3);
	dijkstra.insert(2, 4, 2);

	dijkstra.insert(3, 4, 3);
	dijkstra.insert(3, 5, 1);
	dijkstra.insert(3, 6, 5);

	dijkstra.insert(4, 5, 1);

	dijkstra.insert(5, 6, 2);


#pragma endregion


	return 0;
}