#include <iostream>
using namespace std;

const int INFINITY = 9999999;
const int MAX_SIZE = 502;
int numStudents, numComparisons;
int heightMap[MAX_SIZE][MAX_SIZE];

void floydWarshall() {
    for (int k = 1; k <= numStudents; k++) {
        for (int i = 1; i <= numStudents; i++) {
            for (int j = 1; j <= numStudents; j++) {
                if (heightMap[i][j] > heightMap[i][k] + heightMap[k][j]) {
                    heightMap[i][j] = heightMap[i][k] + heightMap[k][j];
                }
            }
        }
    }
}

int main() {
    cin >> numStudents >> numComparisons;

    for (int i = 1; i <= numStudents; i++) {
        for (int j = 1; j <= numStudents; j++) {
            heightMap[i][j] = INFINITY;
        }
    }

    for (int i = 0; i < numComparisons; i++) {
        int taller, shorter;
        cin >> taller >> shorter;
        heightMap[taller][shorter] = 1;
    }

    floydWarshall();

    int count = 0;
    for (int i = 1; i <= numStudents; i++) {
        int knownRelations = 0;
        for (int j = 1; j <= numStudents; j++) {
            if (heightMap[i][j] != INFINITY || heightMap[j][i] != INFINITY) {
                knownRelations++;
            }
        }
        if (knownRelations == numStudents - 1) {
            count++;
        }
    }
    cout << count << endl;

    return 0;
}
