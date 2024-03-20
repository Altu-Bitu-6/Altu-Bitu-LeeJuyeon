#include <iostream>
using namespace std; 
typedef long long ll;
const int MAX = 60;

pair<int, int> getPair(int m){
    int x, y;
    // m이 제곱수인 경우
    // x == y
    // m = 2^i -> x = y = i-1
    for(ll i=0; i<MAX; i++){
        if(m == ((ll)1 << i)){
            return{i-1, i-1};
        }
    }

    // m이 제곱수가 아닌 경우
    // m = 2^x + 2^y (x <= y)
    for(x=0; x<MAX; x++){ // m = 100010이면 x = 1, y = 5
        if(m & ((ll)1 << x)){
            m -= (ll) 1 << x;
            break;
        }
    }
    for(y = x+1; y<MAX; y++){
        if(m & ((ll)1 << y)){
            break;
        }
    }

    return {x, y};
}

int main(){
    int n;
    cin >> n;
    while(n--){
        int m;
        cin >> m;
        pair<int, int> ans = getPair(m);
        cout << ans.first << ' ' << ans.second << "\n";
    }
    return 0;
}