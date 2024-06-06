#include <iostream>
#include <vector>
using namespace std;

// 변수 선언
int n, r, q; // n: 노드의 개수, r: 루트 노드, q: 쿼리의 개수
vector<vector<int>> tree; // 트리의 인접 리스트 표현
vector<int> subtree_size; // 서브트리의 크기를 저장하는 배열

// 트리를 만드는 함수
void makeTree(int curNode, int parent) {
    subtree_size[curNode] = 1; // 현재 노드를 포함한 서브트리의 크기를 1로 초기화
    for (int i = 0; i < tree[curNode].size(); i++) { // 현재 노드의 모든 이웃을 탐색
        int neighbor = tree[curNode][i]; // 이웃 노드
        if (neighbor != parent) { // 부모 노드로 돌아가는 것을 방지
            makeTree(neighbor, curNode); // 재귀적으로 서브트리를 만듦
            subtree_size[curNode] += subtree_size[neighbor]; // 서브트리의 크기를 합산
        }
    }
}

int main() {
    ios::sync_with_stdio(false); // 입출력 속도를 빠르게 하기 위해 사용
    cin.tie(NULL); // cin과 cout의 묶음을 풀어줌으로써 성능을 최적화
    cout.tie(NULL); // cout과 묶음을 풀어줌

    cin >> n >> r >> q; // 입력받음: n(노드 개수), r(루트 노드), q(쿼리 개수)
    tree.resize(n); // 트리의 크기를 n으로 조정
    subtree_size.assign(n, 0); // 서브트리 크기를 저장할 배열을 0으로 초기화

    for (int i = 0; i < n - 1; i++) { // n-1개의 간선을 입력받음
        int u, v;
        cin >> u >> v; // 두 노드 u와 v를 입력받음
        tree[u - 1].push_back(v - 1); // u-1 노드에 v-1을 연결
        tree[v - 1].push_back(u - 1); // v-1 노드에 u-1을 연결
    }

    makeTree(r - 1, -1); // 루트 노드에서 트리를 만듦, 부모는 -1로 설정

    for (int i = 0; i < q; i++) { // q개의 쿼리를 처리
        int tmp;
        cin >> tmp; // 쿼리 노드 입력받음
        cout << subtree_size[tmp - 1] << "\n"; // 해당 노드의 서브트리 크기를 출력
    }

    return 0; // 프로그램 종료
}
