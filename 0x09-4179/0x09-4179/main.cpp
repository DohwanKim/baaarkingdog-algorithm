#include <iostream>
#include <queue>
using namespace std;

string mage[1002];
int dist[1002][1002];
int fire[1002][1002];
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);
    
    cin >> n >> m;
    
    for(int i=0; i<n; i++) {
        fill(dist[i], dist[i]+m, -1);
        fill(fire[i], fire[i]+m, -1);
    }
    
    for(int i=0; i<n; i++) {
        cin >> mage[i];
    }
    
    queue<pair<int, int>> q1;
    queue<pair<int, int>> q2;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(mage[i][j] == 'F') {
                q1.push({i, j});
                fire[i][j] = 0;
            }
            if (mage[i][j] == 'J') {
                q2.push({i, j});
                dist[i][j] = 0;
            }
        }
    }
    
    while (!q1.empty()) {
        pair<int, int> cur = q1.front(); q1.pop();
        for(int dir=0; dir<4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(fire[nx][ny] >= 0 || mage[nx][ny] == '#') continue;
            fire[nx][ny] = fire[cur.first][cur.second] + 1;
            q1.push({nx, ny});
        }
    }
    
    while (!q2.empty()) {
        pair<int, int> cur = q2.front(); q2.pop();
        for(int dir=0; dir<4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                cout <<  dist[cur.first][cur.second] + 1;
                return 0;
            }
            if(dist[nx][ny] >= 0 || mage[nx][ny] == '#') continue;
            if(fire[nx][ny] != -1 && fire[nx][ny] <= dist[cur.first][cur.second]+1) continue;
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            q2.push({nx, ny});
        }
    }
    cout << "IMPOSSIBLE" << '\n';
    
    return 0;
}
