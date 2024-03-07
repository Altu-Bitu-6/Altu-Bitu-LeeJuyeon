#include <iostream>
#include <queue>
using namespace std;

//큐 초기화
queue<int> initQueue(int n, queue<int> q){
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	return q;
}

queue<int> movePeople(int k, queue<int> q){
	for (int i = 1; i < k; i++) 
	{ //k-1번 동안 앞에서 빼서 뒤로 넣기
		int temp = q.front();
		q.pop(); 
		q.push(temp); 
	}
	return q;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	
	queue<int> q;
	q = initQueue(n, q);

	cout << "<";

	while (q.size() > 1) {
		q = movePeople(k, q);
		cout << q.front();
		cout << ", ";
		q.pop();
	}
    //마지막 남은 원소
	cout << q.front();
	cout << ">\n";
}