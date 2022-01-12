#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;
	int n;
	cin >> n;
	deque<char> front;
	deque<char> back;
	for (int i = 0; i < str.size(); i++)
	{
		front.push_back(str[i]);
	}
	for (int i = 0; i < n; i++)
	{
		char c;
		cin >> c;
		if (c == 'L') {
			if (!front.empty()) {
				back.push_front(front.back());
				front.pop_back();
			}
		}
		else if (c == 'D') {
			if (!back.empty()) {
				front.push_back(back.front());
				back.pop_front();
			}
		}
		else if (c == 'B') {
			if (!front.empty()) {
				front.pop_back();
			}
		}
		else if (c == 'P') {
			char word;
			cin >> word;
			front.push_back(word);
		}
	}
	while (!front.empty()) {
		cout << front.front();
		front.pop_front();
	}
	while (!back.empty()) {
		cout << back.front();
		back.pop_front();
	}
}