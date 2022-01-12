#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;

struct node {
	int h;
	int idx;
};

int main() {
	int n;
	cin >> n;
	vector<int> answer(n,0);
	vector<int> arr(n, 0);
	stack<node> top;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++)
	{
		while (!top.empty() && top.top().h <= arr[i]) {
			top.pop();
		}
		if (top.empty()) answer[i] = 0;
		else answer[i] = top.top().idx;
		top.push({ arr[i],i+1 });
	}

	for (int i = 0; i < n; i++)
	{
		cout << answer[i] << " ";
	}
}