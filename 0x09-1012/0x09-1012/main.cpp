#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int board[52][52];
bool vis[52][52];
int m, n, k;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void input() {
    cin >> m >> n >> k;
    for(int i=0; i<k; i++) {
        int x, y;
        cin >> x >> y;
        board[y][x] = 1;
    }
}

void DFS(int x, int y) {
    stack<pair<int, int>> S;
    
    vis[x][y] = true;
    S.push({x, y});
    
    while (!S.empty()) {
        pair<int, int> cur = S.top(); S.pop();
        
        for(int dir=0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(vis[nx][ny] || board[nx][ny] != 1) continue;
            
            vis[nx][ny] = true;
            S.push({nx, ny});
        }
    }
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    
    cin >> T;
    
    while (T--) {
        int bugs = 0;
        
        memset(board, 0, sizeof(board));
        memset(vis, false, sizeof(vis));
        input();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 1 && vis[i][j] == false) {
                    DFS(i, j);
                    bugs++;
                }
            }
        }
        cout << bugs << '\n';
    }
    
    return 0;
}
