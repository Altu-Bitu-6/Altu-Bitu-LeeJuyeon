#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> family_tree; //가족관계도
vector<bool> visited; //방문한 노드 표시
int people_count; 
int person1, person2;
int relation_count;
int answer = 0;

//깊이우선탐색
void dfs(int index, int moves){
    visited[index] = true; //방문 확인
    if(index == person2-1){ //도달 지점이 원하던 사람이라면
        answer = moves; //직전까지 움직인 횟수를 정답에 넣어줌
        return;
    }
    for(int i=0; i<people_count; i++){
        if(family_tree[index][i]==1 && !visited[i]){ //인접한 노드 중 방문하지 않았던 노드들 확인
            dfs(i, moves+1);
        }
    }
}

int main(){
    cin >> people_count;
    cin >> person1 >> person2;
    cin >> relation_count;

    family_tree.assign(people_count, vector<int>(people_count, 0));
    visited.assign(people_count, false);

    for(int i=0; i<relation_count; i++){
        int parent, child;
        cin >> parent >> child;
        family_tree[parent-1][child-1] = 1;
        family_tree[child-1][parent-1] = 1;
    }

    dfs(person1-1, 0);

    if(answer <= 0){
        cout << -1;
    }
    else{
        cout << answer;
    }

    return 0; 
}