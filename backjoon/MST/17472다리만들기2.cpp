#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;
struct point {
	int x, y;
};
struct node {
	int y, x;
	int level;
};
struct node2 {
	int s, e;
	int w;
};


vector<vector<int>> map;
vector<vector<int>> visit;
vector<node2>alist;
vector<int> table(10,-1);
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
int n, m;
vector<vector<node>> land(1);

int findBoss(int a) {
	if (table[a] == -1) return a;
	return table[a] = findBoss(table[a]);
}

int setUnion(int a, int b) {
	int aBoss = findBoss(a);
	int bBoss = findBoss(b);
	if (aBoss == bBoss) return false;
	 
	table[bBoss] = aBoss;

	return true;
}


void bfs(node start, int num) {
	queue<node>q;
	q.push(start);

	while (!q.empty()) {
		node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (visit[ny][nx]) continue;
			if (map[ny][nx] == 0) continue;
			visit[ny][nx] = 1;
			map[ny][nx] = num;
			land[num].push_back({ ny,nx });
			q.push({ ny,nx,now.level + 1});
		}
	}

}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	
	map.assign(n, vector<int>(m,0));
	visit.assign(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> map[i][j];
		}
	}
	int num = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (visit[i][j]) continue;
			if (map[i][j]) {
				num++;
				visit[i][j] = 1;
				map[i][j] = num;
				land.push_back({ {i,j} });
				bfs({ i,j,0 }, num);
			}
		}
	}

	for (int i = 1; i < land.size(); i++)
	{
		queue<node> q;
		visit.assign(n, vector<int>(m, 0));
		for (int j = 0; j < land[i].size(); j++){
			q.push(land[i][j]);
			visit[land[i][j].y][land[i][j].x] = 1;
		}

		while (!q.empty()) {
			node now = q.front();
			q.pop();

			for (int j = 0; j < 4; j++)
			{
				int w = 0;
				while (++w) {
					int ny = now.y + dy[j]*w;
					int nx = now.x + dx[j]*w;
					if (ny < 0 || nx < 0 || ny >= n || nx >= m) break;
					if (map[ny][nx] == i) break;
					if (map[ny][nx] != 0) {
						if (w >= 3) {
							alist.push_back({ i,map[ny][nx],w - 1 });
						}
						break;
					}
				}
			}
		}
	}

	sort(alist.begin(), alist.end(), [](node2 a, node2 b) {
		return a.w < b.w;
		});

	int answer = 0;
	for (int i = 0; i < alist.size(); i++)
	{
		node2 now = alist[i];

		if (setUnion(now.s, now.e)) {
			answer += now.w;
		}
	}

	int cnt = 0;
	for (int i = 1; i <= num; i++)
	{
		if (table[i] == -1)cnt++;
	}

	if (cnt > 1)
		cout << -1;
	else
		cout << answer;

}