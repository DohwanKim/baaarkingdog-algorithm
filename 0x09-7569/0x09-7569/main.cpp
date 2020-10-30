#include <iostream>
#include <queue>
using namespace std;

int rack[102][102][102];
int dist[102][102][102];
int n, m, h;
int dx[6] = {0, 0, -1, 1, 0, 0};
int dy[6] = {-1, 1, 0, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);
    
    queue<pair<int, pair<int, int>>> Q;
    cin >> m >> n >> h;
    
    for(int i=0; i<h; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<m; k++) {
                cin >> rack[i][j][k];
                
                if(rack[i][j][k] == 1) Q.push({i, {j, k}});
                if(rack[i][j][k] == 0) dist[i][j][k] = -1;
            }
        }
    }
    
    while (!Q.empty()) {
        pair<int, pair<int, int>> cur = Q.front(); Q.pop();
        
        for(int dir=0; dir < 6; dir++) {
            int nx = cur.second.first + dx[dir];
            int ny = cur.second.second + dy[dir];
            int nz = cur.first + dz[dir];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
            if(dist[nz][nx][ny] >= 0) continue;
            
            dist[nz][nx][ny] = dist[cur.first][cur.second.first][cur.second.second] + 1;
            Q.push({nz, {nx, ny}});
        }
    }
    
    int ans = 0;
    for(int i=0; i<h; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<m; k++) {
                if(dist[i][j][k] == -1) {
                    cout << -1 << '\n';
                    return 0;
                }
                if(dist[i][j][k] > ans) ans = dist[i][j][k];
            }
        }
    }
    cout << ans << '\n';
    
    return 0;
}
