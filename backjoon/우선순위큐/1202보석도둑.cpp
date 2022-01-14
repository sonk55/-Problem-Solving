#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct node {
	int w;
	int v;
};

bool operator<(node a, node b) {
	return b.w < a.w;
}

int main() {
	int n, k;
	cin >> n >> k;

	priority_queue<node> jewelry;
	priority_queue<int> capable;
	vector<int> bag;

	for (int i = 0; i < n; i++)
	{
		int w, v;
		cin >> w >> v;
		jewelry.push({ w,v });
	}

	for (int i = 0; i < k; i++)
	{
		int size;
		cin >> size;
		bag.push_back(size);
	}
	long long answer = 0;

	sort(bag.begin(), bag.end());

	for (int i = 0; i < bag.size(); i++)
	{
		while (!jewelry.empty()) {
			node now = jewelry.top();
			jewelry.pop();

			if (bag[i] >= now.w) {
				capable.push(now.v);
			}
			else {
				jewelry.push(now);
				break;
			}
		}
		if (!capable.empty()) {
			answer += capable.top();
			capable.pop();
		}

	}

	cout << answer;

}