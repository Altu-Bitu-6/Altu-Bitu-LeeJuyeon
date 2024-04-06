#include <iostream>
#include <vector>
#include <deque>
#include <string>

using namespace std;

typedef vector<deque<int>> cards;  // 도도와 수연의 카드 덱과 그라운드를 나타내는 타입 정의
const int DO = 0, SU = 1; // 인덱스 상수 정의

/** 승리자를 판단하는 함수 */
string judge(cards& deck) {
    int do_deck = deck[DO].size(), su_deck = deck[SU].size();
    if (do_deck > su_deck) {
        return "do";
    }
    else if (do_deck < su_deck) {
        return "su";
    }
    return "dosu";
}

/** 그라운드에서 덱으로 카드를 옮기는 함수 */
void groundToDeck(deque<int>& deck, deque<int>& ground) {
    while (!ground.empty()) {
        deck.push_back(ground.back());
        ground.pop_back();
    }
}

/** 종을 쳤을 때 수행되는 함수 */
void ringTheBell(int player, cards& deck, cards& ground) {
    groundToDeck(deck[player], ground[!player]); // 상대 그라운드의 카드를 가져옴
    groundToDeck(deck[player], ground[player]); // 자신의 그라운드의 카드를 가져옴
}

/** 종을 울릴 수 있는 플레이어를 판단하는 함수 */
int whoCanRingTheBell(cards& deck, cards& ground) {
    if (!ground[DO].empty() && ground[DO].front() == 5) { // 도도가 종을 울릴 수 있는지 확인
        return DO;
    }
    else if (!ground[SU].empty() && ground[SU].front() == 5) { // 수연이 종을 울릴 수 있는지 확인
        return SU;
    }
    else if (!ground[DO].empty() && !ground[SU].empty() && (ground[DO].front() + ground[SU].front() == 5)) { // 도도와 수연이 합쳐서 종을 울릴 수 있는지 확인
        return SU;
    }
    return -1; // 종을 울릴 수 없을 때
}

/** 게임을 진행하는 함수 */
string game(int m, cards& deck, cards& ground) {
    bool turn = DO; // 도도부터 시작
    while (m--) {
        ground[turn].push_front(deck[turn].front()); // 덱에서 카드를 그라운드로 이동
        deck[turn].pop_front(); // 덱에서 카드를 제거
        if (deck[turn].empty()) {
            break; // 덱이 비어있으면 게임 종료
        }

        int bell = whoCanRingTheBell(deck, ground); // 종을 울릴 수 있는 플레이어 확인
        if (bell != -1) { // 종을 울릴 수 있는 경우
            ringTheBell(bell, deck, ground); // 종을 치고 카드를 가져옴
        }
        turn = !turn; // 턴 변경
    }
    return judge(deck); // 승자 판단 후 반환
}

int main() {
    int n, m, card1, card2;
    cards deck(2), ground(2); // 도도와 수연의 덱과 그라운드

    // 입력
    cin >> n >> m; // 카드 수와 게임 진행 횟수 입력
    while (n--) {
        cin >> card1 >> card2; // 카드 입력
        deck[DO].push_front(card1); // 도도의 카드 덱에 삽입
        deck[SU].push_front(card2); // 수연의 카드 덱에 삽입
    }

    // 출력 & 연산
    cout << game(m, deck, ground); // 게임 진행 후 결과 출력

    return 0;
}


// #include <iostream>
// #include <deque>
// using namespace std;

// deque<int> do_deck;
// deque<int> su_deck;

// deque<int> do_ground;
// deque<int> su_ground;

// void drawCard(int n){
//     if(n==1){ //do's turn
//         do_ground.push_front(do_deck.front());
//         do_deck.pop_front();
//     }
//     else if(n==2){ //su's turn
//         su_ground.push_front(su_deck.front());
//         su_deck.pop_front();
//     }
// }

// void ringBell(int n){
//     if(n==1){ //do's turn
//         for(int i=0; i<su_ground.size(); i++){
//             do_deck.push_back(su_ground.back());
//             su_ground.pop_back();
//         }
//         for(int i=0; i<do_ground.size(); i++){
//             do_deck.push_back(do_ground.back());
//             do_ground.pop_back();
//         }
//     }
//     else if(n==2){ //su's turn
//         for(int i=0; i<do_ground.size(); i++){
//             su_deck.push_back(do_ground.back());
//             do_ground.pop_back();
//         }
//         for(int i=0; i<su_ground.size(); i++){
//             su_deck.push_back(su_ground.back());
//             su_ground.pop_back();
//         }
//     }
    
// }

// int isGameOver(){
//     if(do_deck.empty()){
//         return 2; // su가 이김
//     }
//     else if(su_deck.empty()){
//         return 1; // do가 이김
//     }
//     else{ // 아직 게임오버 아님
//         return 0;
//     }
// }

// void checkForBell(){
//     int do_check = do_ground.front();
//     int su_check = su_ground.front();
//     if(do_check + su_check == 5 && !do_ground.empty() && !su_ground.empty()){ //합이 5라면
//         ringBell(2);
//     }
//     else if(do_check == 5 || su_check == 5){
//         ringBell(1);
//     }
// }

// int hostGame(int count){
//     for(int i=0; i<count; i++){
//         if(i%2==0){ //do's turn
//             drawCard(1);
//         }
//         else{ //su's turn
//             drawCard(2);
//         }
//         int tmp = isGameOver();
//         if(tmp==1){
//             return 1;
//         }
//         else if(tmp==2){
//             return 2;
//         }
//         checkForBell();
//     }

//     if(do_deck.size() > su_deck.size()){
//         return 1; //do가 이김
//     }
//     else if(do_deck.size() < su_deck.size()){
//         return 2; //su가 이김
//     }
//     else{
//         return 3;
//     }
// }

// int main(){
//     int card_count, turn_count;
//     cin >> card_count >> turn_count;

//     for(int i=0; i<card_count; i++){
//         int do_tmp, su_tmp;
//         cin >> do_tmp >> su_tmp;
//         do_deck.push_front(do_tmp);
//         su_deck.push_front(su_tmp);
//     }

//     int result = hostGame(turn_count);

//     if(result == 1){
//         cout << "do";
//     }
//     else if(result == 2){
//         cout << "su";
//     }
//     else{
//         cout << "dosu";
//     }

// }
