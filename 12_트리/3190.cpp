#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int n, k, l;
vector<vector<int>> board;
vector<int> x = {0, 1, 0, -1}; // 우->하->좌->상
vector<int> y = {1, 0, -1, 0}; // 우->하->좌->상
vector<pair<int, char>> dir;
int cur_dir = 0; // 최초 방향은 오른쪽
int cur_time = 0; // 현재 시간
int cur_index = 0; // 현재 방향바꾸는 순서
deque<pair<int, int>> snake;
bool isGameOver = false;

bool isCollide(int x, int y){
    if(x < 0 || y < 0 || x >= n || y >= n){ // 벽을 넘어가면
        return true;
    }
    for(int i = 0; i < snake.size(); i++){
        if(snake[i].first == x && snake[i].second == y){ // 몸에 부딪히면
            return true;
        }
    }
    return false;
}

void checkDirectionChange(){
    if(cur_time == dir[cur_index].first){
        if(dir[cur_index].second == 'L'){
            cur_dir = (cur_dir + 3) % 4;
        } else if(dir[cur_index].second == 'D'){
            cur_dir = (cur_dir + 1) % 4;
        }
        cur_index++;
    }
}

void moveSnake(){
    pair<int, int> head = snake.front();
    int new_x = head.first + x[cur_dir];
    int new_y = head.second + y[cur_dir];

    if(isCollide(new_x, new_y)){
        isGameOver = true;
        return;
    }

    snake.push_front(make_pair(new_x, new_y));

    if(board[new_x][new_y] == 0){ // 사과가 없으면
        snake.pop_back();
    } else {
        board[new_x][new_y] = 0; // 사과를 먹으면 사과를 없애기
    }
}

int main(){
    cin >> n >> k;
    board.resize(n, vector<int>(n, 0)); 

    for(int i = 0; i < k; i++){
        int a, b;
        cin >> a >> b;
        board[a-1][b-1] = 1; // 사과의 위치를 1로 표시
    }

    cin >> l;
    for(int i = 0; i < l; i++){
        int x;
        char c;
        cin >> x >> c;
        dir.push_back(make_pair(x, c));
    }

    snake.push_front(make_pair(0, 0));

    while(true){
        cur_time++;
        moveSnake();
        if(isGameOver) break;
        
        if (cur_index < l) {
            checkDirectionChange();
        }
    }

    cout << cur_time;
}
