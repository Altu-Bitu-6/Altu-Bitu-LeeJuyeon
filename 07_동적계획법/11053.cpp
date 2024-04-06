#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int main(){
    int arr_count; // 입력받을 배열의 크기 입력
    cin >> arr_count; // 입력받은 크기만큼의 정수 배열
    vector<int> arr(arr_count);

    // 입력
    for(int i=0; i<arr_count; i++){
        cin >> arr[i]; 
    }

    // 각 위치에서 가장 긴 증가하는 부분 수열의 길이를 저장하는 배열
    vector<int> ans(arr_count, 1);

    for(int i=0; i<arr_count; i++){
        for(int j=0; j<i; j++){
            // 현재 위치의 숫자가 이전 위치의 숫자보다 크다면
            if(arr[i] > arr[j]){
                // 가장 긴 증가하는 부분 수열의 길이 갱신
                ans[i] = max(ans[i], ans[j]+1);
            }
        }
    }

    // 가장 긴 증가하는 부분 수열의 길이 중 최댓값
    cout << *max_element(ans.begin(), ans.end()) << endl;

    return 0;
}
