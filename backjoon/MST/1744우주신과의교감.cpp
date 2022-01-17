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
	int s, e;
	double w;
};

vector<node>alist;
vector<int> table;

int n, m;


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




int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	table.assign(n + 1, -1);
	vector<point> pos;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		pos.push_back({ x,y });
	}

	for (int i = 0; i < pos.size(); i++)
	{
		for (int j = i+1; j < pos.size(); j++)
		{
			long long dx = pos[i].x - pos[j].x;
			long long dy = pos[i].y - pos[j].y;

			double diff = sqrt(dx * dx + dy * dy);
			alist.push_back({ i + 1,j + 1,diff });
		}
	}
	sort(alist.begin(), alist.end(), [](node a, node b) {
		return a.w < b.w;
		});

	for (int i = 0; i < m; i++)
	{
		int s, e;
		cin >> s >> e;
		setUnion(s, e);
	}

	double answer = 0;
	for (int i = 0; i < alist.size(); i++)
	{
		node now = alist[i];
		if (setUnion(now.s, now.e)) {
			answer += now.w;
		}
	}
	answer = round(answer * 100) / 100;
	printf("%.2lf", answer);
}