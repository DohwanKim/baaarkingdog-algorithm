#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    string a, b;
    int changeCount = 0;
    cin >> a >> b;
    
    for(int i=0; i < a.length(); i++) {
        for(int j=0; j < b.length(); j++) {
            if(b[j] == '0') {
                continue;
            }
            
            if(a[i] == b[j]) {
                a[i] = '0';
                b[j] = '0';
            }
        }
    }
    
    for(char c: a) {
        if(!(c == '0')) {
            changeCount++;
        }
    }
    
    for(char c: b) {
        if(!(c == '0')) {
            changeCount++;
        }
    }
    
    cout << changeCount << '\n';
}

