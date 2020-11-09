#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int board[302][302];
int l;
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

void BFS() {
    queue<pair<int, int>> q;
    pair<int, int> start;
    pair<int, int> end;
    
    for(int i=0; i<l; i++) fill(board[i], board[i]+l, -1);
    
    cin >> start.second >> start.first;
    cin >> end.second >> end.first;
    
    if(start.second == end.second && start.first == end.first) {
        cout << 0 << '\n';
    } else {
        q.push({start.first, start.second});
        board[start.first][start.second] = 0;
        
        while (!q.empty()) {
            pair<int, int> cur = q.front(); q.pop();
            
            for(int dir=0; dir<8; dir++) {
                int nx = cur.second + dx[dir];
                int ny = cur.first + dy[dir];
                
                if(nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
                if(board[ny][nx] >= 0) continue;
                
                board[ny][nx] = board[cur.first][cur.second] + 1;
                
                if((ny == end.first) && (nx == end.second)) {
                    cout << board[ny][nx] << '\n';
                    break;
                }
                
                q.push({ny, nx});
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);
    
    int T;
    cin >> T;
    
    while (T--) {
        cin >> l;
        BFS();
    }
    
    return 0;
}
