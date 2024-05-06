#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> arr; //기존의 수열
vector<int> new_arr; //중복 원소 없앤 수열
vector<int> print_arr; //출력할 배열

vector<int> dedupe(vector<int> cur){ //중복 원소를 없앤 새로운 배열 리턴
    sort(cur.begin(), cur.end());
    vector<int> nodup;
    int tmp = cur[0];
    nodup.push_back(tmp);

    for(int i=1; i<cur.size(); i++){
        if(cur[i]!=tmp){
            tmp = cur[i];
            nodup.push_back(tmp);
        }
    }
    return nodup;
}

void printArr(vector<int> print){
    for(int i=0; i<print.size(); i++){
        cout << print[i] << " ";
    }
    cout << "\n";
}

void backtracking(int cnt){
    if(cnt>=M){
        printArr(print_arr);
    }
    else{
        for(int i=0; i<new_arr.size(); i++){
            if(cnt<M){
                print_arr[cnt] = new_arr[i];
                backtracking(cnt+1);
            }
        }
    }
    
}

int main(){
    cin >> N >> M;
    arr.assign(N, 0);

    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    
    new_arr = dedupe(arr);
    print_arr.assign(M, 0);
    backtracking(0);
}