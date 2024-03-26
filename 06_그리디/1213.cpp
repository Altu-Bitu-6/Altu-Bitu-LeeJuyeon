#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int alphabet_count = 26;

vector<int> countAlphabet(string s){
    vector<int> arr;
    arr.assign(alphabet_count, 0); //알파벳 개수만큼
    for(int i=0; i<s.length(); i++){
        arr[s[i]-'A']++;
    }
    return arr;
}

int checkPalindrome(vector<int> arr){
    int odd_count = 0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] % 2 != 0){
            odd_count++;
            if(odd_count > 1){
                return 0; //0: 만들 수 없음
            }
        }
    }

    if(odd_count > 0){
        return 1; //1: 홀수짜리의 팰린드롬
    }
    else{
        return 2; //2: 짝수짜리의 팰린드롬
    }
}

string makePalindrome(vector<int> arr, int type){
    string result;
    stack<int> s;
    int odd_letter;
    int odd_count;

    for(int i=0; i<arr.size(); i++){
        if(arr[i] % 2 == 0 && arr[i] != 0){ //해당 알파벳이 짝수 개수가 있는 경우
            for(int j=0; j<arr[i]/2; j++){
                result += (char) i+'A';
                s.push(i);
            }
        }
        else if(arr[i] % 2 != 0){
            for(int j=0; j<arr[i]/2; j++){
                result += (char) i+'A';
                s.push(i);
            }
            odd_letter = i;
        }
    }

    if(type==1){ //홀수만큼 합해주기
        result += (char) odd_letter+'A';  
    }

    while(!s.empty()){
        result += (char) s.top()+'A';
        s.pop();
    }

    return result;
}

int main(){
    string eng_name;
    cin >> eng_name;

    vector<int> arr = countAlphabet(eng_name);
    int type = checkPalindrome(arr);
    
    if(type==0){
        cout << "I'm Sorry Hansoo";
    }
    else{
        string result;
        cout << makePalindrome(arr, type);
    }

}