#include <iostream>
#include <vector>
using namespace std; 

int n, d, k, c;
vector<int> sushi;
vector<int> eaten_sushi; //종류별 초밥 몇개씩 먹었는지

void initializeDish(){
    eaten_sushi.assign(d, 0);
}

int findMostSushi(){
    int max = 0;

    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=0; j<k; j++){
            int cur_sushi_type = sushi[(i+j)%n];
            if(eaten_sushi[cur_sushi_type-1]==0){
                sum++;
            }
            eaten_sushi[cur_sushi_type-1]++;
        }
        if(eaten_sushi[c-1]==0){
            sum++;
        }
        if(sum > max){
            max = sum;
        }
        initializeDish();
    }

    return max;
}

int main(){
    cin >> n >> d >> k >> c;
    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        sushi.push_back(tmp);
    }

    initializeDish();
    cout << findMostSushi();
}