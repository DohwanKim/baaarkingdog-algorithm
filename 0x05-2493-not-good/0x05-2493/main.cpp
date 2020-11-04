#include <iostream>
#include <stack>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);
    
    int N;
    cin >> N;
    stack<pair<int, int>> towerHeights; //높이, 인덱스
    stack<int> answer; //높이, 인덱스
    
    for (int i=0; i < N; i++) {
        int height;
        cin >> height;
        towerHeights.push({height, i});
    }
    
    while (!towerHeights.empty()) {
        pair<int, int> towerInfo = towerHeights.top(); towerHeights.pop(); //맨 끝 타워 정보를 가져옴.
        stack<pair<int, int>> dummy; // 비교 조건에 만족 못한 스택 데이터들 모아둘 더미
        bool check = true; // 데이터가 조건에 안걸릴때 0 추가를 위한 불룬
//        cout << "비교할 타겟: " << towerInfo.first << '\n';
        
        while(!towerHeights.empty()) {
//            cout << "빼서 비교하는 녀석의 값: " << towerHeights.top().first << '\n';
            dummy.push(towerHeights.top()); towerHeights.pop(); //기존 스택에서 하나를 빼와서 넣음.
     
            if(dummy.top().first > towerInfo.first) { // 조건에 부합하면 답에 해당 타워의 인덱스를 넣어줌.
//                cout << "-> " << dummy.top().second << '\n';
                answer.push(dummy.top().second+1);
                check = false;
                
                while (!dummy.empty()) {
                    towerHeights.push(dummy.top()); dummy.pop();
                }
                
                break;
            }
        }
        
        if(check) {
            while (!dummy.empty()) {
                towerHeights.push(dummy.top()); dummy.pop();
            }
            answer.push(0);
        }
    }
    
    while (!answer.empty()) {
        cout << answer.top() << ' ';
        answer.pop();
    }
    
    cout << '\n';
    
    return 0;
}
