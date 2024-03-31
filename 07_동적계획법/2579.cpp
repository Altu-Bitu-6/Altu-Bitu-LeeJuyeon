#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> stairs;
vector<int> score;

int dp(int n){
    if(n==0){
        return score[0] = stairs[0];
    }
    if(n==1){
        return score[1] = stairs[0] + stairs[1];
    }
    if(n==2){
        return score[2] = max(stairs[0], stairs[1]) + stairs[2];
    }
    if(score[n]!=0){
        return score[n];
    }
    return score[n] = max(dp(n-3) + stairs[n-1], dp(n-2)) + stairs[n];
}

int main(){
    int stair_count;
    cin >> stair_count;
    for(int i=0; i<stair_count; i++){
        int tmp; 
        cin >> tmp;
        stairs.push_back(tmp);
    }
    score.assign(stair_count, 0);
    int result = dp(stair_count - 1);
    cout << result; 
}