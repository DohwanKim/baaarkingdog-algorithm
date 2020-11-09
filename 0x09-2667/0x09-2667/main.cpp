#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int board[27][27];
int n;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void input() {
    cin >> n;
    
    for(int i=0; i<n; i++) {
        string data;
        cin >> data;
        for(int j=0; j<data.size(); j++) board[i][j] = (int)data[j]-'0';
    }
}

int BFS(int y, int x) {
    queue<pair<int, int>> q;
    int count = 1;
    
    board[y][x] = 2;
    q.push({y, x});
    
    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        
        for(int dir=0; dir<4; dir++) {
            int nx = cur.second + dx[dir];
            int ny = cur.first + dy[dir];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(board[ny][nx] == 0 || board[ny][nx] == 2) continue;
            
            board[ny][nx] = 2;
            q.push({ny, nx});
            count++;
        }
    }
    
    return count;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);
    vector<int> v;
    
    input();
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if(board[i][j] == 0 || board[i][j] == 2) continue;
            v.push_back(BFS(i, j));
        }
    }
    
    sort(v.begin(), v.end());
    cout << v.size() << '\n';
    for (int i=0; i<v.size(); i++) cout << v[i] << '\n';
    
    return 0;
}
