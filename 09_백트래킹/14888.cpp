#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9; // 무한대 값
const int MAX_N = 11; // 수열의 최대 길이
const int ADD = 0, SUB = 1, MUL = 2, DIV = 3; // 연산자 상수
const int EXP_NUM = 4; // 연산자 개수

int n; // 수열의 길이
int nums[MAX_N]; // 입력된 수열
int expression[EXP_NUM]; // 각 연산자의 개수
int max_val = -INF, min_val = INF; // 최댓값과 최솟값

/**
 * 모든 연산자의 조합을 생성하기 위한 백트래킹 함수.
 * 
 * @param cnt: 지금까지 선택된 연산자의 개수
 * @param cur_val: 현재까지의 연산 결과
 */
void backtrack(int cnt, int cur_val) {
    if (cnt == n - 1) { // 모든 연산자를 선택한 경우, 최댓값과 최솟값 갱신
        max_val = max(max_val, cur_val);
        min_val = min(min_val, cur_val);
        return;
    }

    for (int i = 0; i < EXP_NUM; i++) { // 각 연산자에 대해 반복
        if (expression[i] == 0) { // 해당 연산자의 개수가 0이면 스킵
            continue;
        }

        expression[i]--; // 연산자 개수 감소
        switch(i) { // 연산 수행 후 재귀 호출
            case ADD:
                backtrack(cnt + 1, cur_val + nums[cnt + 1]);
                break;
            case SUB:
                backtrack(cnt + 1, cur_val - nums[cnt + 1]);
                break;
            case MUL:
                backtrack(cnt + 1, cur_val * nums[cnt + 1]);
                break;
            case DIV:
                backtrack(cnt + 1, cur_val / nums[cnt + 1]);
                break;
        }

        expression[i]++; // 백트래킹 후 연산자 개수 복구
    }
}

int main() {
    // 입력
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    for (int i = 0; i < EXP_NUM; i++) {
        cin >> expression[i];
    }

    // 백트래킹 수행하여 최댓값과 최솟값 계산
    backtrack(0, nums[0]);

    // 출력
    cout << max_val << '\n' << min_val;

    return 0;
}
