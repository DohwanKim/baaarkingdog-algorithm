#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int board[102][102];
int copyBoard[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int N, maxHeightArea = 0, maxArea = 0;

void input() {
    cin >> N;
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> board[i][j];
            maxHeightArea = max(maxHeightArea, board[i][j]);
        }
    }
}

void BFS(int y, int x, int height) {
    queue<pair<int, int>> q;
    
    copyBoard[y][x] = -1;
    q.push({y, x});
    
    while (!q.empty()) {
        pair<int, int> cur = q.front();q.pop();
        
        for(int dir=0; dir<4; dir++) {
            int nx = cur.second + dx[dir];
            int ny = cur.first + dy[dir];
            
            if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if(copyBoard[ny][nx] == -1) continue;
            if(copyBoard[ny][nx] <= height) continue;
            
            copyBoard[ny][nx] = -1;
            q.push({ny, nx});
        }
    }
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);
    
    input();
    
    for(int i=0; i<=maxHeightArea; i++) {
        int maxAreaDummy = 0;
        
        if(i == 0) {
            maxArea = 1;
            continue;
        }
        
        memcpy(copyBoard, board, sizeof(board));
        
        for(int j=0; j<N; j++) {
            for(int k=0; k<N; k++) {
                if(copyBoard[j][k] <= i || copyBoard[j][k] == -1) continue;
                BFS(j, k, i);
                maxAreaDummy++;
            }
        }
        
        maxArea = max(maxArea, maxAreaDummy);
    }
    
    cout << maxArea << '\n';
    
    return 0;
}
