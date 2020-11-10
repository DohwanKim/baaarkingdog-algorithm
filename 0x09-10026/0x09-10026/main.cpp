#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

string board[102];
bool vis[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int N, answer1 = 0, answer2 = 0;

void input() {
    cin >> N;
    for(int i=0; i<N; i++) {
        string sin;
        cin >> sin;
        board[i] = sin;
    }
}

void BFS(int y, int x, char c) {
    queue<pair<int, int>> q;
    
    q.push({y, x});
    vis[y][x] = true;
    
    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        
        for(int dir=0; dir<4; dir++) {
            int nx = cur.second + dx[dir];
            int ny = cur.first + dy[dir];
            
            if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if(board[ny][nx] != c || vis[ny][nx] == true) continue;
            
            vis[ny][nx] = true;
            q.push({ny, nx});
        }
    }
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);
    
    input();
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(vis[i][j] == true) continue;
            BFS(i, j, board[i][j]);
            answer1++;
        }
    }
    
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            if(board[i][j] == 'G') board[i][j] = 'R';
    
    
    memset(vis, false, sizeof(vis));
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(vis[i][j] == true) continue;
            BFS(i, j, board[i][j]);
            answer2++;
        }
    }
    
    cout << answer1 << ' ' << answer2 << '\n';
    
    return 0;
}
