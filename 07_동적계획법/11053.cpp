#include <iostream>
#include <vector>
using namespace std; 

vector<int> arr;

int findMaxLen(int n){ //n항부터 시작했을 때의 부분수열 길이 최댓값
    if(n>=arr.size()-1){
        return 1;
    }

    int max_size = 1; 
    for(int i=n+1; i<arr.size(); i++){
        if(arr[n] < arr[i]){
            max_size++;
        }
        else{
            break;
        }
        
    }
    return max_size;
}

int main(){
    int arr_count; 
    cin >> arr_count;
    for(int i=0; i<arr_count; i++){
        int tmp;
        cin >> tmp; 
        arr.push_back(tmp);
    }

    int result = 1;
    for(int i=0; i<arr_count; i++){
        int tmp2 = findMaxLen(i);
        if(tmp2 > result){
            result = tmp2;
        }
    }

    cout << result;
}