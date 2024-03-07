#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//에라토스테네스의 체를 활용하여 1부터 n까지 수의 소수 여부 구하기
vector<bool> getPrimes(int n){
    vector<bool> is_prime(n+1, true); //n+1개의 값에 대해 소수 여부 구하기 (true로 초기화)
    is_prime[0] = is_prime[1] = false; //0과 1은 소수가 아니다. 

    for(int i=2; i*i<=n; i++){//2부터 루트n까지의 숫자 확인
        if(!is_prime[i]){//해당 숫자가 소수가 아니라면 패스
            continue;
        }
        for(int j = i*i; j<=n; j+=i){ //i의 제곱부터 n까지의 i의 배수를 모두 확인
            is_prime[j] = false;//i의 배수이므로 체에서 거르기!
        }
    }
    return is_prime; //결과값 반환
}

//input된 값 n에 대해 n = a+b의 a값을 반환
int goldbach(int n, vector<bool> &is_prime) {//&을 붙이는 이유: vector의 값을 수정하지 않도록 복사해서 쓰기 위해
    for(int a=3; a<=n/2; a+=2){ //확인하는 수는 6부터 시작..
        // 2보다 큰 짝수 소수는 존재하지 않으므로
        // a = 3부터 탐색해도 a와 b 모두 홀수여야 한다는 조건 만족
        if(is_prime[a] && is_prime[n - a]){ //둘 다 소수라면
            return a; //반환!
        }
    }
    //없을 경우
    return 0;
}

int main(){
    vector<int> arr;
    int input;
    while(1) {//입력된 숫자 받아오기
        cin >> input;
        if (input == 0) {//0이면 input 완료
            break;
        }
        arr.push_back(input);//input을 배열에 넣어주기
    }

    int max_num = *max_element(arr.begin(), arr.end()); //입력받은 숫자 중 최댓값. 에라토스테네스 체 연산 한번만 하도록..
    vector<bool> is_prime = getPrimes(max_num);//체 만들기

    for(int i=0; i<arr.size(); i++){//입력받은 모든 수에 대해
        int a = goldbach(arr[i], is_prime);//골드바흐 숫자 확인
        
        if(a!=0){//공백 포함!! 규칙에 맞게 출력
            cout << arr[i] << " = " << a << " + " << arr[i]-a << "\n";
        }
        else{//a==0이라면 출력값이 없음.. 골드바흐의 추측은 틀렸다.
            cout << "Goldbach's conjecture is wrong.\n";
        }
    }
}