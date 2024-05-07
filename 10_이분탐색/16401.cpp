#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m, n;
vector<int> cookie;

int main(){
    cin >> m >> n;
    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        cookie.push_back(tmp);
    }
    sort(cookie.begin(), cookie.end());

}