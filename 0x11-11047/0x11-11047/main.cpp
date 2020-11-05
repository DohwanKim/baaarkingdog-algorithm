#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);
    
    int arr[12], N, K, num = 0;
    
    cin >> N >> K;
    
    for (int i=0; i < N; i++) {
        cin >> arr[i];
    }
    
    for (int i=N-1; i >= 0; i--) {
        int t = K / arr[i];
        num += t;
        K -= t*arr[i];
    }
    
    cout << num << '\n';
    
    return 0;
}
