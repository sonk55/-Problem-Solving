#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;


int main() {
	int n, m;
	cin >> n >> m;

	// 인접 리스트 배열
	vector<vector<int>> alist(n + 1, vector<int>(0));

	// 현재 남아있는 선행작업의 갯수를 저장할 배열 
	vector<int> table(n + 1, 0);

	//입력
	for (int i = 0; i < m; i++)
	{
		int s, e;
		cin >> s >> e;
		// e 작업을 수행하기 위해서는 s가 선행되어야 하므로
		// s의 인접리스트에 e를 추가
		alist[s].push_back(e);

		// e를 작업하기 위해 s가 선행되어야 하므로
		// e를 작업하기 위한 선행되어야 할 작업의 갯수 증가
		table[e]++;
	}
	//작업 테이블
	queue<int> q;

	// 현재 작업중 선행 작업없이 수행 가능한 작업 탐색
	for (int i = 1; i <= n; i++)
	{
		//선행작업이 없다
		if (table[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		// 현재 작업 종료
		int now = q.front();
		cout << now << " ";
		q.pop();

		// 현재 작업과 연결된 작업들 탐색
		for (int i = 0; i < alist[now].size(); i++)
		{
			int next = alist[now][i];
			table[next]--;

			// 다음 작업의 선행작업이 모두 완료되었다면
			if (table[next] == 0) {
				//작업 큐에 추가
				q.push(next);
			}
		}
	}
}