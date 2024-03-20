    #include <iostream>
    #include <vector>
    #include <string>
    #include <algorithm>
    using namespace std;
    typedef pair<int, int> pos;

    bool isOutOfBoard(pos pos){
        if(pos.first < 1 || pos.first > 8 || pos.second < 1 || pos.second > 8){
            return true;
        }
        else {
            return false;
        }
    }

    vector<int> moveKing(string move, pos king, pos rock){
        pos my_king = king;
        pos my_rock = rock;

        // move: 8개의 이동 종류 중 몇 번째의 이동인지
        
        vector<int> dx = {1, -1, 0, 0, 1, -1, 1, -1};
        vector<int> dy = {0, 0, -1, 1, 1, 1, -1, -1};
        vector<string> moves = {"R", "L", "B", "T", "RT", "LT", "RB", "LB"};

        int i = 0;
        for(int k=0; k<moves.size(); k++){
            if(move == moves[k]){
                i = k;
            }
        }
        
        pos tmp_king = {my_king.first + dx[i], my_king.second + dy[i]};
        pos tmp_rock = my_rock;
        
        if(tmp_king==my_rock){
            tmp_rock = {my_rock.first + dx[i], my_rock.second + dy[i]};
        }
        
        if(!isOutOfBoard(tmp_king) && !isOutOfBoard(tmp_rock)){
            my_king = tmp_king;
            my_rock = tmp_rock;
        }
        return {my_king.first, my_king.second, my_rock.first, my_rock.second};
        
    }

    int main(){
        string king_pos, rock_pos;
        int move_cnt;
        cin >> king_pos >> rock_pos >> move_cnt;
        vector<char> col = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

        int king_x = 1;
        int rock_x = 1;
        for(int i=0; i<col.size(); i++){
            if(king_pos[0] == col[i]){
                king_x = i + 1;
            }
            if(rock_pos[0] == col[i]){
                rock_x = i + 1;
            }
        }

        pos my_king = {king_x, king_pos[1]-'0'}; // king 위치 int값으로 조정
        pos my_rock = {rock_x, rock_pos[1]-'0'}; // rock 위치 int값으로 조정

        for(int i=0; i<move_cnt; i++){
            string cur_move;
            cin >> cur_move;
            vector<int> cur_pos = moveKing(cur_move, my_king, my_rock);
            my_king = {cur_pos[0], cur_pos[1]};
            my_rock = {cur_pos[2], cur_pos[3]};
        }

        cout << col[my_king.first-1] << my_king.second << "\n" << col[my_rock.first-1] << my_rock.second;
    }