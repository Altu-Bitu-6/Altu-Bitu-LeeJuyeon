#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int tooth = 8; // 톱니바퀴의 이빨 개수

// 두 톱니바퀴가 맞닿는 부분의 값을 비교하여 회전 가능한지 판별하는 함수
bool isGearsMatch(const string& left_gear, const string& right_gear, int left_pointer, int right_pointer) {
    if (left_gear[(left_pointer + 2) % tooth] == right_gear[(right_pointer + 6) % tooth]) {
        return false; // 맞닿는 부분의 값이 같으면 회전 불가
    }
    return true; // 맞닿는 부분의 값이 다르면 회전 가능
}

// 톱니바퀴를 회전시키는 함수
vector<int> turnGears(vector<string>& gears, vector<int>& gear_pointer, int index, int direction) {
    vector<int> cur_gear = gear_pointer; // 현재 톱니바퀴 포인터 상태를 복사
    vector<pair<bool, int>> isGearTurn;
    isGearTurn.assign(gears.size(), {false, 0}); // 톱니바퀴가 회전하는지 여부를 저장하는 벡터 초기화
    isGearTurn[index] = {true, direction}; // 현재 톱니바퀴에 회전 연산 적용

    // 왼쪽으로 톱니바퀴를 회전시킬지 결정
    for (int i = index; i < gears.size() - 1; i++) {
        if (isGearsMatch(gears[i], gears[i + 1], gear_pointer[i], gear_pointer[i + 1]) && isGearTurn[i].first) {
            if (isGearTurn[i].second == 1) {
                isGearTurn[i + 1] = {true, -1}; // 왼쪽 톱니바퀴를 시계 반대 방향으로 회전
            } else {
                isGearTurn[i + 1] = {true, 1}; // 왼쪽 톱니바퀴를 시계 방향으로 회전
            }
        }
    }

    // 오른쪽으로 톱니바퀴를 회전시킬지 결정
    for (int i = index; i > 0; i--) {
        if (isGearsMatch(gears[i - 1], gears[i], gear_pointer[i - 1], gear_pointer[i]) && isGearTurn[i].first) {
            if (isGearTurn[i].second == 1) {
                isGearTurn[i - 1] = {true, -1}; // 오른쪽 톱니바퀴를 시계 반대 방향으로 회전
            } else {
                isGearTurn[i - 1] = {true, 1}; // 오른쪽 톱니바퀴를 시계 방향으로 회전
            }
        }
    }

    // 회전 방향에 따라 톱니바퀴 포인터를 이동
    for (int i = 0; i < gears.size(); i++) {
        if (isGearTurn[i].first) {
            if (isGearTurn[i].second == 1) {
                cur_gear[i] = (gear_pointer[i] + (tooth - 1)) % tooth; // 시계 방향 회전
            } else if (isGearTurn[i].second == -1) {
                cur_gear[i] = (gear_pointer[i] + 1) % tooth; // 반시계 방향 회전
            }
        }
    }
    return cur_gear; // 업데이트된 톱니바퀴 포인터 반환
}

// 톱니바퀴의 상태를 검사하여 12시 방향이 1인 개수를 세는 함수
int countGears(vector<string>& gears, vector<int>& gear_pointer) {
    int count = 0;
    for (int i = 0; i < gears.size(); i++) {
        if (gears[i][gear_pointer[i]] == '1') {
            count++;
        }
    }
    return count;
}

int main() {
    int gear_count;
    cin >> gear_count;

    vector<string> gears(gear_count); // 톱니바퀴 상태를 저장하는 벡터
    vector<int> gear_pointer(gear_count, 0); // 각 톱니바퀴의 포인터 위치를 저장하는 벡터

    // 톱니바퀴 상태를 입력받음
    for (int i = 0; i < gear_count; i++) {
        cin >> gears[i];
    }
    
    int turn_count;
    cin >> turn_count;

    // 톱니바퀴를 회전시킴
    for (int i = 0; i < turn_count; i++) {
        int tmp_index, tmp_dir;
        cin >> tmp_index >> tmp_dir;
        gear_pointer = turnGears(gears, gear_pointer, tmp_index - 1, tmp_dir);
    }

    // 12시 방향이 1인 톱니바퀴의 개수를 출력
    int answer = countGears(gears, gear_pointer);
    cout << answer;

    return 0;
}
