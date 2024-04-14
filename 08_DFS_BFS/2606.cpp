#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int>> network;
vector<int> virus;
vector<bool> visited;
stack<int> dfs_s;

void dfs(int start, int count){
    dfs_s.push(start); // 시작 노드를 스택에 넣음
    while (!dfs_s.empty()) {
        int index = dfs_s.top();
        dfs_s.pop();
        visited[index] = true; // 방문한 노드 표시
        for(int i = 0; i < count; i++){
            if(network[index][i] == 1 && !visited[i]){
                dfs_s.push(i);
                virus[i] = 1; // 바이러스에 감염된 노드 표시
            }
        }
    }
}

int main(){
    int computer_count;
    int pair_count;
    cin >> computer_count >> pair_count;

    vector<int> tmp;
    tmp.assign(computer_count, 0);
    network.assign(computer_count, tmp);
    virus.assign(computer_count, 0);
    visited.assign(computer_count, false);

    for(int i=0; i<pair_count; i++){
        int n1, n2;
        cin >> n1 >> n2; 
        network[n1-1][n2-1] = 1;
        network[n2-1][n1-1] = 1;
    }

    dfs(0, computer_count); // 1번 컴퓨터부터 탐색 시작

    int answer = 0;
    for(int i = 1; i < computer_count; i++){ // 1번 컴퓨터는 이미 감염되었으므로 제외
        if(virus[i] == 1){
            answer++;
        }
    }
    cout << answer;
}
