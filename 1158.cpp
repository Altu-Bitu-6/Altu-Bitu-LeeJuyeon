#include <iostream>
#include <queue>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	
	queue<int> q;
    //큐 초기화
	for (int i = 1; i <= n; i++) q.push(i);

	cout << "<";

	while (q.size() > 1) {
		for (int i = 1; i < k; i++) 
        { //k-1번 동안 앞에서 빼서 뒤로 넣기
			int temp = q.front();
			q.pop(); 
			q.push(temp); 
		}
		cout << q.front();
		cout << ", ";
		q.pop();
	}
    //마지막 남은 원소
	cout << q.front();
	cout << ">\n";
}