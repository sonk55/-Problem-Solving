#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
int n, m, k;

struct node {
	int y, x;
};
string str;
vector<vector<char>> map;
vector<vector<vector<int>>> dp;

int cnt = 0;
int dfs(node now, int level, int end) {
	dp[now.y][now.x][level] = 0;
	if (level == end-1) {
		dp[now.y][now.x][level] = 1;
		return 1;
	}
	for (int i = 1; i <= k; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int ny = now.y + i * dy[j];
			int nx = now.x + i * dx[j];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (map[ny][nx] == str[level+1]) {
				if (dp[ny][nx][level + 1] == -1) {
					dp[now.y][now.x][level] += dfs({ ny,nx }, level+1, end);
				}
				else {
					dp[now.y][now.x][level] += dp[ny][nx][level + 1];
				}
			}
		}
	}

	return dp[now.y][now.x][level];

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	map.assign(n, vector<char>(m));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{

			cin >> map[i][j];
		}
	}

	cin >> str;
	dp.assign(n, vector<vector<int>>(m, vector<int>(str.size(), -1)));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == str[0]) {
				cnt += dfs({ i,j }, 0, str.size());
			}
		}
	}

	cout << cnt;


}