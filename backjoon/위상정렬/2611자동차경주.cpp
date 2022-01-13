#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;

struct node {
	int v;
	int t;
};



int main() {
	int n, m;
	cin >> n >> m;
	
	vector<vector<node>> alist(n + 1);
	vector<vector<node>> alist2(n + 1);
	vector<vector<int>> path(n + 1);
	vector<int> table(n + 1, 0);
	vector<int> dp(n + 1, 0);
	for (int i = 0; i < m; i++)
	{
		int s, e, t;
		cin >> s >> e >> t;
		alist[s].push_back({ e,t });
		alist2[e].push_back({ s,t });
		table[e]++;
	}
	queue<node> q;
	q.push({ 1,0 });
	path[1] = { 1 };
	while (!q.empty()) {
		node now = q.front();
		q.pop();

		if (now.v == 1 && table[1] == 0) {
			break;
		}

		for (int i = 0; i < alist[now.v].size(); i++)
		{
			node next = alist[now.v][i];
			table[next.v]--;
			if (table[next.v] == 0) {
				int maxidx = 0;
				for (int j = 0; j < alist2[next.v].size(); j++)
				{
					node pre = alist2[next.v][j];
					if (dp[next.v] < dp[pre.v] + pre.t) {
						maxidx = pre.v;
						dp[next.v] = dp[pre.v] + pre.t;
					}
				}
				path[next.v] = path[maxidx];
				path[next.v].push_back(next.v);

				q.push({ next.v,dp[next.v] });
			}
		}
	}

	cout << dp[1]<<endl;
	for (int i = 0; i < path[1].size(); i++)
	{
		cout << path[1][i] << " ";
	}

}
