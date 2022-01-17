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
	long long w;
};

vector<node>alist;
vector<int> table(200001, -1);

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
	while (1) {
		int n, m;
		cin >> n >> m;
		if (n == 0 && m == 0)break;
		table.assign(n, -1);
		alist.clear();
		long long maxcost = 0;

		int idx = 0;
		for (int i = 0; i < m; i++)
		{
			int s, e, w;
			cin >> s >> e;
			cin >> w;
			maxcost += w;
			alist.push_back({ s,e,w });
		}

		sort(alist.begin(), alist.end(), [](node a, node b) {
			return a.w < b.w;
			});

		long long answer = 0;
		for (int i = 0; i < alist.size(); i++)
		{
			if (setUnion(alist[i].s, alist[i].e)) {
				answer += alist[i].w;
			}
		}
		cout << maxcost - answer <<endl;
	}

}