#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int board[1002][1002];
int dis[1002][1002][2];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;

void input() {
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        string sin;
        cin >> sin;
        for(int j=0; j<m; j++) {
            board[i][j] = (int)sin[j]-'0';
        }
    }
}

int BFS() {
    queue<pair<pair<int, int>, int>> q;
    
    dis[0][0][1] = 1;
    q.push({{0, 0}, 1});
    
    while (!q.empty()) {
        pair<int, int> cur = q.front().first;
        int canDelete = q.front().second; q.pop();
        
        if (cur.first == n-1 && cur.second == m-1) {
            return dis[cur.first][cur.second][canDelete];
        }
        
        for(int dir=0; dir<4; dir++) {
            int nx = cur.second + dx[dir];
            int ny = cur.first + dy[dir];
            
            if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if(board[ny][nx] == 1 && canDelete) {
                dis[ny][nx][0] = dis[cur.first][cur.second][canDelete] + 1;
                q.push({{ny, nx}, 0});
            }
            if(board[ny][nx] == 0 && dis[ny][nx][canDelete] == 0) {
                dis[ny][nx][canDelete] = dis[cur.first][cur.second][canDelete] + 1;
                q.push({{ny, nx}, canDelete});
            }
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);
    
    input();
    cout << BFS() << '\n';
    
    return 0;
}
