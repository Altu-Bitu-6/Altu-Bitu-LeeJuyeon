#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> x;

int isValid(int height){
    int result = 0;

    for(int i=0; i<=x.size(); i++){
        int left, right;

        if(i==0) left = 0;
        else left = x[i-1];
        
        if(i==x.size()) right = n;
        else right = x[i];

        if(right - left > height) result++;
    }

    if(result==0) return 1;
    else return 0;
}


int binaryCheck() {
    int left = 1; 
    int right = n;
    int mid;
    
    while (left <= right) {
        mid = (left + right) / 2;  // 중간값 계산
        // isValid 함수 호출하여 모든 위치를 밝힐 수 있는지 확인
        if (isValid(mid)) {
            // 설치할 수 있다면 더 작은 높이에서 시도해봄
            right = mid - 1;
        } else {
            // 설치할 수 없다면 더 큰 높이에서 시도해봄
            left = mid + 1;
        }
    }
    return mid;  // 최적의 높이 반환
}


int main(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int tmp;
        cin >> tmp;
        x.push_back(tmp);
    }

    cout << binaryCheck();
}