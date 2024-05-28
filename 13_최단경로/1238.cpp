#include <iostream>
#include <vector>
#include <queue>
#include <limits>

#define pii pair<int, int>

using namespace std;

int numNodes, numEdges, target;
const int INFINITY = numeric_limits<int>::max();
vector<pii> adjList[2][1001];
vector<int> shortestDist[2];
int combinedDist[1001];

void readInput() {
    int start, end, time;
    cin >> numNodes >> numEdges >> target;
    for (int i = 0; i < numEdges; ++i) {
        cin >> start >> end >> time;
        adjList[0][start].push_back(make_pair(time, end));
        adjList[1][end].push_back(make_pair(time, start));
    }
    shortestDist[0].resize(numNodes + 1, INFINITY);
    shortestDist[1].resize(numNodes + 1, INFINITY);
}

void dijkstra(int direction) {
    shortestDist[direction][target] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, target});

    while (!pq.empty()) {
        int currentCost = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();

        if (currentCost > shortestDist[direction][currentNode]) continue;

        for (auto &neighbor : adjList[direction][currentNode]) {
            int nextNode = neighbor.second;
            int nextCost = currentCost + neighbor.first;

            if (nextCost < shortestDist[direction][nextNode]) {
                shortestDist[direction][nextNode] = nextCost;
                pq.push({nextCost, nextNode});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    readInput();

    dijkstra(1);
    dijkstra(0);

    int maxDistance = 0;
    for (int i = 1; i <= numNodes; ++i) {
        maxDistance = max(maxDistance, shortestDist[0][i] + shortestDist[1][i]);
    }

    cout << maxDistance;

    return 0;
}
