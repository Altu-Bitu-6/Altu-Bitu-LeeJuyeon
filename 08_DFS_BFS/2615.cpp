#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std; 

vector<vector<int>> badukpan;
vector<vector<int>> visited;
stack<pair<int, int>> s;

vector<int> dx = {1, -1,0, 0, 1, -1, -1, 1};
vector<int> dy = {0, 0, 1, -1, 1, -1, 1, -1};

int ans_winner=0;
pair<int, int> ans_start;

vector<pair<int, int>> five_line;

bool isInsideBoard(int x, int y){
    if(x>=0 && y>=0 && x<19 &&y<19){
        return true;
    }
    return false;
}

// 점 (x,y)로부터 5개 맞나 확인
bool isWin(int x, int y, int dx, int dy){
    int first_stone = badukpan[x][y];
    if(first_stone==0){
        return false;
    }
    for(int i=0; i<5; i++){
        five_line.push_back({x+(i*dx), y+(i*dy)});
        if(first_stone != badukpan[x+(i*dx)][y+(i*dy)]){
            five_line.clear();
            return false;
        }
    }
    return true;
}

pair<int, int> findLeftofFive(vector<pair<int, int>> five){
    int index = 0;
    int min = five[index].first + five[index].second;
    bool isRightSideways = false;
    for(int i=1; i<5; i++){
        if(five[i].first + five[i].second < min){
            index = i;
        }
        else if(five[i].first + five[i].second == min){
            isRightSideways = true;
            break;
        }
    }

    if(isRightSideways){
        int min_y = five[0].second;
        for(int i=0; i<5; i++){
            if(five[i].second < min_y){
                index = i;
            }
        }
    }

    return five[index];
}

void dfs(pair<int, int> start){
    s.push(start);
    while(!s.empty()){
        pair<int, int> index = s.top();
        s.pop();
        visited[index.first][index.second] = true;
        int cur_stone = badukpan[index.first][index.second];
        for(int i=0; i<8; i++){
            int next_x = index.first + dx[i];
            int next_y = index.second + dy[i];

            if(isInsideBoard(next_x, next_y) && !visited[next_x][next_y]){
                int next_stone = badukpan[next_x][next_y];
                s.push({next_x, next_y});
                if(cur_stone==next_stone && cur_stone!=0 && isInsideBoard(index.first + dx[i]*4, index.second + dy[i]*4)){
                    if(isWin(index.first, index.second, dx[i], dy[i])){
                        ans_winner = badukpan[index.first][index.second];
                        ans_start = findLeftofFive(five_line);
                        break;
                    }
                }
            }
            
        }
    }
}

int main(){
    vector<int> tmp;
    tmp.assign(19, 0);
    badukpan.assign(19, tmp);
    visited.assign(19, tmp);

    for(int i=0; i<19; i++){
        for(int j=0; j<19; j++){
            cin >> badukpan[i][j];
        }
    }

    dfs({0, 0});
    
    cout << ans_winner << "\n";
    if(ans_winner!=0){
        cout << ans_start.first + 1<< " " << ans_start.second + 1;
    }   
}