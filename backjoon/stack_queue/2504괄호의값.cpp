#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;
struct node {
	int status;
	int value;
};

int main() {
	string str;
	cin >> str;
	stack<node> mem;
	int error = false;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(' || str[i] == '[') {
			mem.push({ 0,str[i] });
		}
		else if(str[i] == ')' || str[i] == ']') {
			char end;
			int sum = 0;
			if (str[i] == ')') end = '(';
			else if (str[i] == ']') end = '[';

			while (!mem.empty()) {
				if (mem.top().status == 0 && mem.top().value == end) break;
				else if (mem.top().status == 0 && mem.top().value != end) {
					error = true;
					break;
				}
				else {
					sum += mem.top().value;
					mem.pop();
				}
			}
			if (mem.empty()) {
				error = true;
				break;
			}
			else {
				mem.pop();
				if (str[i] == ')') mem.push({ 1,sum == 0 ? 2 : 2 * sum });
				if (str[i] == ']') mem.push({ 1,sum == 0 ? 3 : 3 * sum });
			}

		}
	}

	int sum = 0;
	while (!mem.empty()) {
		if (mem.top().status == 0 && (mem.top().value == '(' || mem.top().value == '[')) {
			error = true;
			break;
		}
		sum += mem.top().value;
		mem.pop();
	}

	if (!error) cout << sum;
	else cout << 0;
}