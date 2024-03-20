#include <iostream>
using namespace std;

/**[백준 11723] 집합
/* - vector나 map으로 각 원소의 유무를 판단할 경우 시간초과 발생!
/*   => 총 원소의 개수는 20. 32비트 크기 int의 각 bit에 원소의 유무를 저장
/* - value의 i번째 bit가 1이면: 현재 집합에 i 존재 O
/* - value의 i번째 bit가 1이면: 현재 집합에 i 존재 X
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // m : 수행할 연산의 수
    // x : 다루는 값 (이 값을 추가하거나 빼거나...)
    // value : 관리하고 있는 집합, 각 비트로 표현했을 때 1이면 존재, 0이면 존재x
    // op : 입력받는 명령어 string
    int m, x, value = 0;
    string op;
    cin >> m;
    while (m--) { // m번 반복
        cin >> op;

		// x 피연산자가 입력되지 않는 연산자: all, empty
        if (op == "all") { //
            for (int i = 1; i <= 20; i++) {
                value = value | (1 << i); // 1~20의 모든 값을 집어넣어준다. 2진법으로 1111....11(20개)
            }
        }
        else if (op == "empty") {
            value = 0; // 비우기
        }

		// x 피연산자가 입력되는 연산자: add, remove, check, toggle
        else {
            cin >> x;
            if (op == "add") {
                value = value | (1 << x); // x번째의 비트를 1로 변환해주기 (있는 값)
            }
            else if (op == "remove") {
                value = value & ~(1 << x); // x번째의 비트를 0으로 변환해주기 (없는 값)
            }
            else if (op == "check") {
                if (value & (1 << x)) { // x번째의 비트가 1인가? 
                    cout << "1\n";
                } else {
                    cout << "0\n";
                }
            }
            else if (op == "toggle") { // x번째의 비트에 대해 존재 여부를 반대로 바꾸어주기
                value = value ^ (1 << x);
            }
        }   
    }
    return 0;
}