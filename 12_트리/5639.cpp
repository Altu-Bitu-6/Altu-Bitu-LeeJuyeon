#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int> tree;

// 후위순회 출력 재귀함수
void printPostorder(int start, int end){
	if(start >= end) return; // 다 돌았다면 return
	if(start == end - 1){   // 다 돌았다면 return
		cout << tree[start] << '\n';
		return;
	}
	int index = start + 1;
	while(index < end){ // 자기보다 큰 값이 나오기 직전까지
		if(tree[start] < tree[index]) break;
		index++;
	}
	printPostorder(start + 1, index);
	printPostorder(index, end);
	cout << tree[start] << '\n'; //자기 자신 (root) 맨 마지막에 출력
	return;
}

int main() {
	while(cin >> n){
		tree.push_back(n);
	}
	printPostorder(0, tree.size());
}