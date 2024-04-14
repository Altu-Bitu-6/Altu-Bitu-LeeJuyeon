  #include <iostream>
#include <vector>
using namespace std;

int num_count;
vector<int> num_arr;
vector<int> operator_arr;
int min_value = 1000000000;
int max_value = -1000000000;
int calculated_value = 0;
vector<bool> visited;

int calculator(int cur, int next, int op){
    int result = cur;
    if(op==0){//+
        result += next;
    }
    else if(op==1){//-
        result -= next;
    }
    else if(op==2){//*
        result *= next;
    }
    else if(op==3){///
        result /= next;
    }
    return result;
}

void backtracking(int count){
    if(count == operator_arr.size()){
        if(calculated_value > max_value){
            max_value = calculated_value;
            //cout << "max 갱신!!: " <<max_value<<"\n";
        }
        if(calculated_value < min_value){
            min_value = calculated_value;
            //cout << "min 갱신!!: " <<min_value<<"\n";
        }
        calculated_value = num_arr[0];
    }
    for(int i=0; i<operator_arr.size(); i++){
        if(!visited[i]){
            visited[i] = true;
            calculated_value = calculator(calculated_value, num_arr[count+1], operator_arr[i]);
            backtracking(count+1);
            visited[i] = false;
        }
    }
}

int main(){
    cin >> num_count;
    num_arr.assign(num_count, 0);

    for(int i=0; i<num_count; i++){
        cin >> num_arr[i];
    }

    for(int i=0; i<4; i++){
        int tmp;
        cin >> tmp;
        for(int j=0; j<tmp; j++){
            operator_arr.push_back(i);
        }
    }

    visited.assign(operator_arr.size(), false);
    calculated_value = num_arr[0];
    backtracking(0);

    cout << max_value << "\n" << min_value;
}