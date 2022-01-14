#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 1000000000
using namespace std;

struct node {
	int point;
	int value;//가중치
};

bool operator<(node a, node b) {
	return b.value < a.value;
}

int main() {
	int V, E;
	cin >> V >> E;

	int start;
	cin >> start;

	//인접리스트
	vector<vector<node>> alist(V + 1);
	
	//시작점에서 해당 지점까지의 최단거리 가중치가 저장될 배열
	vector<int> DP(V + 1, INF);
	vector<int> path(V + 1, 0);


	for (int i = 0; i < E; i++)
	{
		int s, e, v;//시작, 도착, 가중치
		cin >> s >> e >> v;
		alist[s].push_back({ e,v });
	}

	priority_queue<node> q;
	//시작지점 넣고
	q.push({ start,0 });
	//시작지점에서 시작지점까지는 가중치가 없다 0이다
	DP[start] = 0;

	while (!q.empty()) {
		node now = q.top();
		q.pop();

		for (int i = 0; i < alist[now.point].size(); i++)
		{
			node next = alist[now.point][i];

			// 조건 
			//시작점에서 다음 좌표까지의 거리가 시작점에서 현재좌표 까지의 거리 + 현재좌표에서 다음 좌표까지의 거리보다
			//크다면 시작 좌표에서 다음 좌표까지의 거리 업데이트
			if (DP[next.point] > now.value + next.value) {
				DP[next.point] = now.value + next.value;
				path[next.point] = now.point;
				q.push({ next.point, DP[next.point] });
			}
		}
	}

	for (int i = 1; i <= V; i++)
	{
		if (DP[i] == INF) {
			cout << "INF" << "\n";
		}
		else {
			cout << DP[i]<<"\n";
		}
	}
}