#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int board[102][102];
int m, n, k;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(int y, int x) {
    queue<pair<int, int>> q;
    int size = 0;
    
    board[y][x] = 1;
    q.push({y, x});
    
    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        
        for (int dir=0; dir < 4; dir++) {
            int nx = cur.second + dx[dir];
            int ny = cur.first + dy[dir];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(board[ny][nx] == -1 || board[ny][nx] == 1) continue;
            
            board[ny][nx] = 1;
            q.push({ny, nx});
        }
        size++;
    }
    
    return size;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);
    vector<int> sizeCollector;
    
    cin >> m >> n >> k;
    
    while (k--) {
        pair<int, int> vertex1;
        pair<int, int> vertex2;
        
        cin >> vertex1.first >> vertex1.second >> vertex2.first >> vertex2.second;
        
        for(int i=vertex1.second; i<vertex2.second; i++)
            for(int j=vertex1.first; j<vertex2.first; j++)
                board[i][j] = -1;
    }
    
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(board[i][j] == 1 || board[i][j] == -1) continue;
            sizeCollector.push_back(bfs(i, j));
        }
    }
    
    sort(sizeCollector.begin(), sizeCollector.end());
    cout << sizeCollector.size() << '\n';
    for(int i=0; i<sizeCollector.size(); i++) cout << sizeCollector[i] << ' ';
    cout << '\n';
    
    return 0;
}
