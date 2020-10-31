#include <iostream>
using namespace std;

long long power(int a, int b, int m) {
    long long x = 1;
    while (b--) {
        x = x * a % m;
    }
    return x;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);
    cout << power(3, 5, 7) << '\n';
    return 0;
}
