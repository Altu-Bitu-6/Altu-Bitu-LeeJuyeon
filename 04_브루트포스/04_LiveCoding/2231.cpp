#include <iostream>
using namespace std; 
int bruteforce(int n){ //다 해보는 방법!!
    for(int i=0; i<n; i++){
        int tmp = i;
        int sum = i;
        while (tmp){
            sum += tmp%10;
            tmp /= 10;
        }
        if(sum==n){
            return i;
        }
    }
    return 0;
}

int main(){
    int n;
    cin >> n;
    cout << bruteforce(n);
    return 0;
}