#include <iostream>
#include <vector>
using namespace std;

int n, r, q;
vector<vector<int>> tree;
vector<int> subtree_size;

void makeTree(int curNode, int parent) {
    subtree_size[curNode] = 1; // 자기 자신을 포함한 서브트리의 크기
    for (int i = 0; i < tree[curNode].size(); i++) {
        int neighbor = tree[curNode][i];
        if (neighbor != parent) { // 부모로 다시 돌아가는 것을 방지
            makeTree(neighbor, curNode);
            subtree_size[curNode] += subtree_size[neighbor]; // 서브트리의 크기를 합산
        }
    }
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 

    cin >> n >> r >> q;
    tree.resize(n);
    subtree_size.assign(n, 0);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u - 1].push_back(v - 1);
        tree[v - 1].push_back(u - 1);
    }

    makeTree(r - 1, -1);

    for (int i = 0; i < q; i++) {
        int tmp;
        cin >> tmp;
        cout << subtree_size[tmp - 1] << endl;
    }

    return 0;
}
