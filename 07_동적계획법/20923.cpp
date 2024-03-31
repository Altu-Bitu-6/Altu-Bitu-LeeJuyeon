#include <iostream>
#include <deque>
using namespace std;

deque<int> do_deck;
deque<int> su_deck;

deque<int> do_ground;
deque<int> su_ground;

void drawCard(int n){
    if(n==1){ //do's turn
        do_ground.push_front(do_deck.front());
        do_deck.pop_front();
    }
    else if(n==2){ //su's turn
        su_ground.push_front(su_deck.front());
        su_deck.pop_front();
    }
}

void ringBell(int n){
    if(n==1){ //do's turn
        for(int i=0; i<su_ground.size(); i++){
            do_deck.push_back(su_ground.back());
            su_ground.pop_back();
        }
        for(int i=0; i<do_ground.size(); i++){
            do_deck.push_back(do_ground.back());
            do_ground.pop_back();
        }
    }
    else if(n==2){ //su's turn
        for(int i=0; i<do_ground.size(); i++){
            su_deck.push_back(do_ground.back());
            do_ground.pop_back();
        }
        for(int i=0; i<su_ground.size(); i++){
            su_deck.push_back(su_ground.back());
            su_ground.pop_back();
        }
    }
    
}

int isGameOver(){
    if(do_deck.empty()){
        return 2; // su가 이김
    }
    else if(su_deck.empty()){
        return 1; // do가 이김
    }
    else{ // 아직 게임오버 아님
        return 0;
    }
}

void checkForBell(){
    int do_check = do_ground.front();
    int su_check = su_ground.front();
    if(do_check + su_check == 5 && !do_ground.empty() && !su_ground.empty()){ //합이 5라면
        ringBell(2);
    }
    else if(do_check == 5 || su_check == 5){
        ringBell(1);
    }
}

int hostGame(int count){
    for(int i=0; i<count; i++){
        if(i%2==0){ //do's turn
            drawCard(1);
        }
        else{ //su's turn
            drawCard(2);
        }
        int tmp = isGameOver();
        if(tmp==1){
            return 1;
        }
        else if(tmp==2){
            return 2;
        }
        checkForBell();
    }

    if(do_deck.size() > su_deck.size()){
        return 1; //do가 이김
    }
    else if(do_deck.size() < su_deck.size()){
        return 2; //su가 이김
    }
    else{
        return 3;
    }
}

int main(){
    int card_count, turn_count;
    cin >> card_count >> turn_count;

    for(int i=0; i<card_count; i++){
        int do_tmp, su_tmp;
        cin >> do_tmp >> su_tmp;
        do_deck.push_front(do_tmp);
        su_deck.push_front(su_tmp);
    }

    int result = hostGame(turn_count);

    if(result == 1){
        cout << "do";
    }
    else if(result == 2){
        cout << "su";
    }
    else{
        cout << "dosu";
    }

}