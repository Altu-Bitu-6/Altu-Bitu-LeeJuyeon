#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 
const int CNT = 9;

void select(vector<int> &arr){
    int sum;
    for(int i=0; i<CNT; i++){
        sum += arr[i];
    }
    for(int i=0; i<CNT-1; i++){
        for(int j=i+1; j<CNT; j++){
            if(sum - arr[i] - arr[j]==100) {//둘을 제외한 합이 100인가? 
                arr.erase(arr.begin() + j);
                arr.erase(arr.begin() + i);
                return;
            }
        }
    }
}

int main() {
    
    //입력
    vector<int> arr(CNT);
    for(int i=0; i<CNT; i++){
        cin >> arr[i];
    }

    //연산
    select(arr);
    sort(arr.begin(), arr.end());

    //출력
    for(auto it: arr){
        cout << it << "\n";
    }

    return 0;
}