#include <iostream>
#include <vector>
using namespace std; 

int melon_count;
vector<pair<int, int>> dir_len(6, {0, 0});
vector<int> dir_count(4, 0); //해당 방향을 가리키는 변이 1개씩인가?? 2개씩인가??
int big_square = 1;
int small_square = 1;

int main(){
    cin >> melon_count;
    for(int i=0; i<6; i++){
        cin >> dir_len[i].first >> dir_len[i].second;
        dir_count[dir_len[i].first - 1]++;
    }

    for(int i=0; i<6; i++){
        if(dir_count[dir_len[i].first - 1] > 1){
            if(dir_len[(i+1)%6].first == dir_len[(i+5)%6].first){
                small_square *= dir_len[i].second;
            }
        }
        else{
            big_square *= dir_len[i].second;
        }
    }

    cout << (big_square - small_square) * melon_count;
}