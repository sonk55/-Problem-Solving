#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		vector<string> q;
		for (int j = 0; j < n; j++)
		{
			string s;
			cin >> s;
			q.push_back(s);
		}
		sort(q.begin(), q.end(), [](string a, string b) {if (a.size() == b.size()) return a < b; else return a.size() < b.size(); });
		q.erase(unique(q.begin(), q.end()),q.end());
		cout << "#" << i + 1<<"\n";
		for (int i = 0; i < q.size(); i++)
		{
			cout << q[i] << "\n";
		}

	}

}