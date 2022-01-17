#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include <map>
#include <unordered_map>
using namespace std;

struct node {
	string name;
	int count;
};

unordered_map<string, node> table;

string findBoss(string a) {
	if (table[a].name == "") return a;
	return table[a].name = findBoss(table[a].name);
}

int setUnion(string a, string b) {
	string aBoss = findBoss(a);
	string bBoss = findBoss(b);

	if (aBoss != bBoss) {
		table[bBoss].name = aBoss;
		table[aBoss].count += table[bBoss].count;
	}

	return table[aBoss].count;
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;

	for (int T = 0; T < t; T++)
	{

		int n;
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			string friend1, friend2;

			cin >> friend1 >> friend2;

			// 등록이 안되어 있다면 등록
			if (table.find(friend1) == table.end()) table[friend1] = { "" , 1 };
			if (table.find(friend2) == table.end()) table[friend2] = { "" , 1 };


			cout << setUnion(friend1, friend2) << "\n";
		}
		table.clear();
	}

}