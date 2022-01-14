#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct node {
	int x;
	int level;
};

bool operator<(node a, node b) {
	return b.level < a.level;
}

void print(priority_queue<node> q) {
	while (!q.empty()) {
		cout << q.top().x << " " << q.top().level << endl;
		q.pop();
	}
	cout << "--------------------------------------" << endl;
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> visit(100001, -1);

	visit[n] = 0;

	priority_queue<node>q;

	q.push({ n,0 });

	while (!q.empty()) {
		node now = q.top();
		q.pop();
		// cout << now.x << " " << now.level << endl;
		if (visit[now.x] < now.level) continue;
		if (now.x == k) {
			cout << now.level;
			break;
		}

		// +
		if (now.x + 1 <= 100000) {
			if (visit[now.x + 1] == -1 || visit[now.x + 1] > now.level + 1) {
				visit[now.x + 1] = now.level + 1;
				q.push({ now.x + 1,now.level + 1 });
			}
		}
		// -
		if (now.x - 1 >= 0) {
			if (visit[now.x - 1] == -1 || visit[now.x - 1] > now.level + 1) {
				visit[now.x - 1] = now.level + 1;
				q.push({ now.x - 1,now.level + 1 });
			}
		}
		// *2
		if (2 * now.x <= 100000) {
			if (visit[now.x * 2] == -1 || visit[now.x*2] > now.level) {
				visit[now.x * 2] = now.level;
				q.push({ now.x * 2 ,now.level});
			}
		}
		//print(q);
		
	}

}