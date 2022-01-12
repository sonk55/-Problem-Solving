//#include<iostream>
//#include<vector>
//#include<queue>
//#include<string>
//using namespace std;
//struct node {
//    int id;
//    int y, x;
//    int level;
//};
//
//vector<int> table;
//
//int findBoss(int a) {
//    if (table[a] == -1) return a;
//    return table[a] = findBoss(table[a]);
//}
//
//void setUnion(int a, int b) {
//    int aBoss = findBoss(a);
//    int bBoss = findBoss(b);
//
//    if (aBoss != bBoss) {
//       table[bBoss] = aBoss;
//
//    }
//}
//int dy[] = { -1,1,0,0 };
//int dx[] = { 0,0,-1,1 };
//int main() {
//    int n, m, answer;
//    queue<node> q;
//    cin >> n >> m;
//    table.assign(m, -1);
//    vector<vector<node>> map(n, vector<node>(n, { -1,0,0,0 }));
//    for (int i = 0; i < m; i++)
//    {
//        int y, x;
//        cin >> y >> x;
//        y--;
//        x--;
//        map[y][x] = { i,y,x,0 };
//        q.push(map[y][x]);
//    }
//
//    while (!q.empty()) {
//        node now = q.front();
//        q.pop();
//
//        vector<node> vect;
//        for (int i = 0; i < 4; i++)
//        {
//            int ny = now.y + dy[i];
//            int nx = now.x + dx[i];
//            if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
//            if (map[ny][nx].id == now.id) continue;
//            if (map[ny][nx].id != -1 && findBoss(now.id) != findBoss(map[ny][nx].id)) {
//                int flag = false;
//                for (int j = 0; j < vect.size(); j++)
//                {
//                    if (vect[j].id == findBoss(map[ny][nx].id)) {
//                        vect[j].level = min(vect[j].level, map[ny][nx].level);
//                        flag = true;
//                        break;
//                    }
//                }
//                if (flag == false) {
//                    vect.push_back({ findBoss(map[ny][nx].id),ny,nx, map[ny][nx].level });
//                }
//                continue;
//            }
//            if (map[ny][nx].id == -1) {
//                map[ny][nx] = { now.id,ny,nx,now.level + 1 };
//                q.push(map[ny][nx]);
//            }
//        }
//        int count = 0;
//        for (int i = 0; i < vect.size(); i++)
//        {
//            count = max(now.level, vect[i].level);
//            answer = max(count, answer);
//            setUnion(now.id, vect[i].id);
//        }
//
//    }
//    cout << answer;
//}
