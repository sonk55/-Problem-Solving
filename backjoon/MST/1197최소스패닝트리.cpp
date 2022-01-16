#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
//#include<Windows.h>
#define INF 100000000

using namespace std;


struct node {
	int s, e, v;
};

struct use {
	int status;
	int cnt;
};

typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;
typedef vector<int> vi;
typedef vector<node> vn;
typedef vector<char> vc;
typedef vector<string> vs;

int n, m;

vi group(10011, -1);

int findBoss(int a) {
	if (group[a] == -1) {
		return a;
	}
	return group[a] = findBoss(group[a]);
}

int setUnion(int a, int b) {
	int aboss, bboss;
	aboss = findBoss(a);
	bboss = findBoss(b);
	if (aboss == bboss) return false;
	group[max(bboss, aboss)] = min(aboss, bboss);
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	vn alist(m);
	for (int i = 0; i < m; i++)
	{
		cin >> alist[i].s >> alist[i].e >> alist[i].v;
	}
	sort(alist.begin(), alist.end(), [](node a, node b) {return a.v < b.v; });
	long long sum = 0;
	for (int i = 0; i < m; i++)
	{
		if (setUnion(alist[i].s, alist[i].e)) {
			sum += alist[i].v;
		}
	}
	cout << sum;
}
