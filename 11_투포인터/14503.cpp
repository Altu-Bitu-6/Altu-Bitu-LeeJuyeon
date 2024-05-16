#include <iostream>

using namespace std;

const int SIZE = 50;
const int CLEAN = 2; // 청소 완료 표시

int n, m, cnt = 0; // 세로 크기, 가로 크기, 청소한 칸 개수

int board[SIZE][SIZE]; // 보드 상태 저장 배열 (0: 빈 칸, 1: 벽, 2: 청소 완료)
int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0}; // 방향에 따른 x, y 이동

// 깊이 우선 탐색 함수
void dfs(int row, int col, int dir) {
    // 1. 현재 위치 청소
    if (board[row][col] != CLEAN) { // 아직 청소되지 않은 경우
        cnt++; // 청소 카운트 증가
    }
    board[row][col] = CLEAN; // 청소 완료 표시

    // 현재 칸의 주변 4방향 중 청소되지 않은 공간이 있는지 확인
    for (int i = 0; i < 4; i++) {
        // 현재 방향 기준 왼쪽 방향부터 탐색
        int new_dir = (dir - i + 3) % 4; // 왼쪽으로 회전한 방향
        int new_row = row + dy[new_dir], new_col = col + dx[new_dir]; // 새로운 위치 계산

        // 청소할 공간이 있는 경우
        if (board[new_row][new_col] == 0) {
            dfs(new_row, new_col, new_dir); // 해당 방향으로 이동하여 탐색 재개
            return; // 현재 탐색 중단 후 종료
        }
    }

    // 모든 방향이 청소되어 있거나 벽인 경우
    int back_dir = (dir + 2) % 4; // 현재 방향에서 반대 방향
    int back_row = row + dy[back_dir], back_col = col + dx[back_dir]; // 후진할 위치

    // 뒤쪽이 벽인지 확인
    if (board[back_row][back_col] == 1) {
        return; // 후진 불가능하면 종료
    }
    // 후진 가능하면 해당 위치로 이동하여 재귀 호출
    dfs(back_row, back_col, dir);
    return; // 종료
}

int main() {
    int r, c, d; // 로봇 청소기의 초기 위치와 방향

    // 입력
    cin >> n >> m; // 보드의 세로, 가로 크기 입력
    cin >> r >> c >> d; // 로봇 청소기의 초기 위치와 방향 입력

    // 보드 상태 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    // 로봇 청소기 작동
    dfs(r, c, d);

    // 출력
    cout << cnt; // 청소한 칸 개수 출력

    return 0; // 프로그램 종료
}
