#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;
struct point {
	double y, x;
};
struct node {
	int s, e;
	double w;
};

vector<int> table;

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

	int n;
	cin >> n;

	vector<point> pos(n);
	table.assign(n,-1);

	vector<node> alist;

	for (int i = 0; i < n; i++)
	{
		double y, x;
		cin >> y >> x;
		pos[i] = { y,x };
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (j == i) continue;
			int diffy = pos[i].y - pos[j].y;
			int diffx = pos[i].x - pos[j].x;
			alist.push_back({i,j, sqrt(diffx * diffx + diffy * diffy) });
		}
	}

	sort(alist.begin(), alist.end(), [](node a, node b) {
		return a.w < b.w;
		});

	double answer = 0.0;
	for (int i = 0; i < alist.size(); i++)
	{
		node now = alist[i];

		if (setUnion(now.s, now.e) == true) {
			answer += now.w;
		}
	}

	printf("%lf", answer);
	
}