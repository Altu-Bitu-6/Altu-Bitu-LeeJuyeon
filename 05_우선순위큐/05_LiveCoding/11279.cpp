#include <iostream>
#include <vector>
using namespace std; 

bool isEmpty(vector<int>& heap){
    return heap.size() == 1;
}

void push(int x, vector<int>& heap){
    int idx = heap.size();

    heap.push_back(x);

    while(idx > 1, && heap[idx] > heap[idx/2]){ // heap[idx/2]가 자식노드
        swap(heap[idx], heap[idx/2]);
        idx / =2;
    }
    return;
}

int pop(vector<int>& heap){
    int item = heap[1];

    heap[1] = heap[heap.size()-1];
    heap.pop_back();

    int size = heap.size();
    int parent = 1; child = 2;

    while(child < size){
        if(child + 1 < size && heap[child+1]> heap[child]){
            child++;
        }

        if(heap[parent] < heap[child]){
            swap(heap[parent], heap[child]);

            parent = child;
            child = parent * 2;
        }
        else{
            break;
        }
    }

    return item;
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, x;
    vector<int> heap_vec;
    heap_vec.push_back(0);

    cin >> n;

    while(n--){
        cin >> x;
        if(x==0){ //0이라면
            if(isEmpty(heap_vec)){ //비어있을 때
                cout << "0\n";
            }
            else{
                cout << pop(heap_vec) << "\n";
            }
        }
        else{ //자연수라면
            push(x, heap_vec);
        }
    }
}