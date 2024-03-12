    #include <iostream>
    #include <vector>
    #include <string>
    #include <algorithm>
    using namespace std;

    bool isOutOfBoard(pair<int, int> pos){
        if(pos.first < 1 || pos.first > 8 || pos.second < 1 || pos.second > 8){
            return false;
        }
        else {
            return true;
        }
    }

    void moveKing(string move, pair<int, int> &king, pair<int, int> &rock){
        // move: 8개의 이동 종류 중 몇 번째의 이동인지
        // king: 현재 king의 위치 받아와서 변경해주기
        // rock: 현재 rock의 위치 받아와서 변경해주기
        vector<int> dx = {1, -1, 0, 0, 1, -1, 1, -1};
        vector<int> dy = {0, 0, -1, 1, 1, 1, -1, -1};
        vector<string> moves = {"R", "L", "B", "T", "RT", "LT", "RB", "LB"};

        int i = 0;
        for(int k=0; k<moves.size(); k++){
            if(move == moves[k]){
                i = k;
            }
        }
        
        pair<int, int> tmp_king = {king.first + dx[i], king.second + dy[i]};
        pair<int, int> tmp_rock = {rock.first + dx[i], rock.second + dy[i]};
        if(!isOutOfBoard(tmp_king) && !isOutOfBoard(tmp_rock)){
            king = tmp_king;
            if(king==rock){
                rock = tmp_rock;
            }
        }
        else{
                cout << "이동x\n";
        }
        
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

        pair<int, int> my_king = {king_x, king_pos[1]-'0'}; // king 위치 int값으로 조정
        pair<int, int> my_rock = {rock_x, rock_pos[1]-'0'}; // rock 위치 int값으로 조정

        for(int i=0; i<move_cnt; i++){
            string cur_move;
            cin >> cur_move;
            moveKing(cur_move, my_king, my_rock);
        }

        //cout << col[my_king.first-1] << my_king.second << "\n" << col[my_rock.first-1] << my_rock.second;
        cout << my_king.first << my_king.second << "\n" << my_rock.first << my_rock.second;
    }