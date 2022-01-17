#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;

struct node {
	int s, e, w;
};

vector<int> table;
vector<node> alist;

int findBoss(int a) {
	if (table[a] == -1) return a;
	return table[a] = findBoss(table[a]);
}

int setUnion(int a, int b) {
	int aBoss = findBoss(a);
	int bBoss = findBoss(b);
	if (aBoss != bBoss) {
		table[aBoss] = bBoss;
		return true;
	}
	return false;
}


int main() {
	int n, m;
	cin >> n >> m;

	table.assign(n + 1, -1);

	for (int i = 0; i < m; i++)
	{
		int s, e, w;
		cin >> s >> e >> w;
		alist.push_back({ s,e,w });
	}

	sort(alist.begin(), alist.end(), [](node a, node b) {
		return a.w < b.w;
	});

	long long answer = 0;
	
	for (int i = 0; i < alist.size(); i++)
	{
		node now = alist[i];

		if (setUnion(now.s, now.e)) {
			answer += now.w;
		}
	}
	cout << answer;
}