#include <iostream>
using namespace std;

char board[1026][1026];
int N;

void func(int x, int y, int size) {
    if(size == 1) {
        board[x][y] = '*';
        return;
    }
    
    size /= 2;
    
    func(x, y, size);
    func(x+size, y, size);
    func(x, y+size, size);
}

void init() {
    int length = 1<<N;
    
    for(int i=0; i<length; i++) {
        for(int j=0; j<length-i; j++) {
            board[i][j] = ' ';
        }
    }
}

void print() {
    int length = 1<<N;
    
    for(int i=0; i<length; i++) {
        for(int j=0; j<length-i; j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);
    
    cin >> N;
    init();
    func(0, 0, 1<<N);
    print();
    
    return 0;
}
