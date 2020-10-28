#include <iostream>
#include <queue>
using namespace std;

int rack[1002][1002];
int dist[1002][1002];
int n, m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; // 상하좌우 네 방향을 의미

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);

    queue<pair<int, int>> Q;
    cin >> m >> n;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> rack[i][j];
            
            if(rack[i][j] == 1) Q.push({i, j});
            if(rack[i][j] == 0) dist[i][j] = -1;
        }
    }
    
    while (!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        
        for(int dir=0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(dist[nx][ny] >= 0) continue;
            
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            Q.push({nx, ny});
        }
    }
    
    int ans = 0;
    for(int i=0; i < n; i++) {
        for(int j=0; j < m; j++) {
            if(dist[i][j] == -1) {
                cout << -1 << '\n';
                return 0;
            }
            
            if(dist[i][j] > ans) ans = dist[i][j];
        }
    }
    cout << ans << '\n';
    
    return 0;
}
