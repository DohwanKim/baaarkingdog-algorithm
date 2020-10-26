#include <iostream>
#include <deque>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);
    
    int size, getCount, workCount = 0;
    deque<int> de;
    
    cin >> size >> getCount;
    
    for (int i = 0; i < size; i++) {
        de.push_back(i+1);
    }
    
    while (getCount) {
        int findNum;
        int index;
        cin >> findNum;
        
        for(int i=0; i < de.size(); i++) {
            if(de[i] == findNum) {
                index = i;
                break;
            }
        }
        
        //왼쪽에 근접 -> 2번 작업 수행
        if (index < de.size() - index) {
            while (1) {
                if(de.front() == findNum) {
                    de.pop_front();
                    break;
                }
                workCount++;
                de.push_back(de.front());
                de.pop_front();
            }
        } else { //오른쪽에 근접 -> 3번 작업 수행
            while (1) {
                if(de.front() == findNum) {
                    de.pop_front();
                    break;
                }
                workCount++;
                de.push_front(de.back());
                de.pop_back();
            }
        }
        
        getCount--;
    }
    cout << workCount << '\n';
    
    return 0;
}
