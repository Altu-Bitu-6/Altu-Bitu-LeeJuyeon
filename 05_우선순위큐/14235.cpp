#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, a, gift;
	priority_queue<int> pq; //산타가 가지고 있는 선물주머니 상태 반영

	//입력
	cin >> n;

	//연산 & 출력
	while (n--) {
		cin >> a;

		//아이들을 만난 경우
		if (a == 0) {
			//줄 선물이 없는 경우
			if (pq.empty()) { 
				cout << "-1\n"; 
			}
			//가치가 가장 큰 선물 주기
			else {
				cout << pq.top() << "\n"; //어떤 선물을 주었는지 출력
				pq.pop(); //준 선물은 삭제
			}
		}
		//선물 충전
		else { //충전소
			while (a--) { //선물 개수만큼 반복하여
				cin >> gift;
				pq.push(gift); //선물 충전
			}
		}
	}

	return 0;
}

/*
#include <iostream>
using namespace std; 

void meetChild(){

}

void pickupGift(){

}

int main(){
    int input_count;
    cin >> input_count;

    for(int i=0; i<input_count; i++){
        int tmp;
        cin >> tmp; 
        if(tmp == 0){
            meetChild();
        }
        else{
            while(true){
                
            }
        }
    }
}

*/
