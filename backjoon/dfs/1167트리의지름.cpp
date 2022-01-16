#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;
struct node {
	int v, w;
};
int n;
int maxlevel;
int maxidx;
vector<vector<node>> alist;
vector<int> visit;
void dfs(int level, int now, int sum = 0) {
	if (maxlevel < sum) {
		maxlevel = sum;
		maxidx = now;
	}
	for (int i = 0; i < alist[now].size(); i++)
	{
		node next = alist[now][i];
		if (visit[next.v]) continue;
		visit[next.v] = 1;
		dfs(level + 1, next.v, sum+next.w);
		visit[next.v] =0;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	alist.assign(n+1, {});
	visit.assign(n + 1, 0);

	for (int i = 0; i < n; i++)
	{
		int idx;
		cin >> idx;

		while (1) {
			int v, w;
			cin >> v;
			if (v == -1) break;
			cin >> w;
			alist[idx].push_back({ v,w });
		}
	}
	visit[1] = 1;
	dfs(0, 1, 0);
	visit[1] = 0;
	visit[maxidx] = 1;
	dfs(0, maxidx, 0);
	cout << maxlevel;
}