#include <iostream>
#include <vector>

using namespace std;

/*
* 주어진 막대 과자들을 조카들에게 나눠줄 때, 최대한 긴 길이로 나눠주는 알고리즘을 이분 탐색을 이용하여 구현한다.
* 이분 탐색을 통해 나눠줄 수 있는 최대한 긴 과자의 길이를 찾아낸다.
*/

#define MAX_COOKIE 1000000000 // 과자의 최대 길이

// m명의 조카들에게 과자를 나눠줄 때, 최대한 긴 길이로 나눠주는 함수
int binary_search(int m, vector<int> &cookie) {
    int right = MAX_COOKIE; // 과자의 최대 길이
    int left = 1; // 과자의 최소 길이
    int result = 0; // 최종 결과: 나눠줄 수 있는 최대한 긴 과자의 길이

    // 이분 탐색
    while (left <= right) {
        int mid = (left + right) / 2; // 중간 길이
        int cnt = 0; // 조카들에게 나눠줄 수 있는 과자의 수

        // mid 길이만큼씩 나눠주면 몇 명에게 나눠줄 수 있는지 계산
        for (int i = 0; i < cookie.size(); i++) {
            cnt += cookie[i] / mid;
        }

        // 조카들에게 나눠줄 수 있는 과자의 수가 m 이상인 경우
        if (cnt >= m) {
            left = mid + 1; // left를 mid+1로 이동하여 더 큰 길이 탐색
            result = mid; // 결과 갱신
        } else {
            right = mid - 1; // right를 mid-1로 이동하여 더 작은 길이 탐색
        }
    }

    return result; // 최대한 긴 길이 반환
}

// 메인 함수
int main() {
    int m, n; // 조카 수, 과자 수
    cin >> m >> n; // 조카 수, 과자 수 입력
    vector<int> cookie(n); // 과자들의 길이를 저장할 벡터

    // 과자들의 길이 입력
    for (int i = 0; i < n; i++) {
        cin >> cookie[i];
    }

    // 최대한 긴 길이로 과자를 나눠주고, 결과 출력
    cout << binary_search(m, cookie);

    return 0;
}
