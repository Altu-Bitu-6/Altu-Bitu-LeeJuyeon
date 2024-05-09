#include <iostream>
#include <vector>

using namespace std;

int N, M; // 굴다리의 길이, 가로등의 개수
vector<int> light; // 가로등 위치 저장
int answer; // 결과값

// 굴다리 전체를 비추는지 확인하는 함수
bool check(int length) {
    if (light[0] > length) {  // 첫 번째 가로등 처리
        return false;
    }

    for (int i = 1; i < M; i++) {
        if (light[i] - light[i - 1] > 2 * length) {
            return false;
        }
    }

    if (N - light[M - 1] > length) {  // 마지막 가로등 처리
        return false;
    }

    return true;
}

// 이분 탐색 함수
void binary_search() {
    // 초기화
    int left = 0;
    int right = N;
    int mid = (left + right) / 2;

    // 이분 탐색
    while (left <= right) {
        // mid가 조건에 부합한다면
        if (check(mid)) {
            answer = mid; // 정답 처리
            // 더 짧은 길이로 다음 탐색
            right = mid - 1;
        } else {
            // 조건에 부합하지 않는다면, 더 긴 길이로 다음 탐색
            left = mid + 1;
        }

        mid = (left + right) / 2;
    }
}

int main() {
    // 입력
    cin >> N >> M;
    light.resize(M);
    for (int i = 0; i < M; i++) {
        cin >> light[i];
    }

    // 연산
    binary_search();

    // 출력
    cout << answer;

    return 0;
}
