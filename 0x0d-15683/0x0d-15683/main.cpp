#include <iostream>
using namespace std;

int arr[10][10];
int cameraSpot[10][10];
int n, m;

void input() {
    cin >> n >> m;
    
    for(int i=0; i < n; i++) {
        for(int j=0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
}

void printArr() {
    cout << "-----------------" <<'\n';
    for(int i=0; i < n; i++) {
        for(int j=0; j < m; j++) {
            cout << cameraSpot[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "-----------------" <<'\n';
}

//상하좌우 4가지 경우
void camera1(int y, int x, int angle) {
    for(int i=x; i < n; i++) {
        if(arr[y][x] == 6) break;
        cameraSpot[y][i] = 1;
    }
}

void getBlindSpot() {
    for(int i=0; i < n; i++) {
        for(int j=0; j < m; j++) {
            if(arr[i][j] == 1) {
                camera1(i, j, 0);
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);
    
    input();
    getBlindSpot();
    printArr();
    
    return 0;
}
