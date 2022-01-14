#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct node {
	int start;
	int end;
};

bool operator<(node a, node b) {
	//if(a.start != b.start) return a.start < b.start;
	if (a.end != b.end) return a.end < b.end;
	return a.start < b.start;
}

int main() {
	int n;
	cin >> n;
	vector<node> times;
	for (int i = 0; i < n; i++)
	{
		int s, e;
		cin >> s >> e;
		times.push_back({ s,e });
	}

	sort(times.begin(), times.end());

	int count = 1;
	int end = times[0].end;
	for (int i = 1; i < times.size(); i++)
	{
		if (end <= times[i].start) {
			end = times[i].end;
			count += 1;
		}
	}

	cout << count;

}