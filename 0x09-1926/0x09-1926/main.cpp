#include <iostream>
#include <queue>
using namespace std;

#define X first;
#define Y second;

int board[502][502] = {0};
bool vis[502][502];
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void getInput() {
    cin >> n >> m;
    
    for(int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> board[i][j];
        }
    }
}

void printPicture() {
    for(int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);
    
    int maxSize = 0;
    int pictureCount = 0;
    queue<pair<int, int>> Q;
    
    getInput();
    
    for(int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if(board[i][j] == 1 && vis[i][j] == 0) {
                pictureCount++;
                int size = 0;
                vis[i][j] = 1;
                Q.push({i, j});
                
                while (!Q.empty()) {
                    pair<int, int> cur = Q.front(); Q.pop();
                    size++;
                    
                    for(int dir=0; dir < 4; dir++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        
                        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if(vis[nx][ny] || board[nx][ny] != 1) continue;
                        vis[nx][ny] = 1;
                        Q.push({nx, ny});
                    }
                }
                if(size > maxSize) maxSize = size;
            }
        }
    }
    
    cout << pictureCount << '\n' << maxSize << '\n';
    
    return 0;
}
