#include <iostream>
#include <string>
using namespace std;

bool isSimilarWord(string w1, string w2){
    int w1_sum = 0;
    int w2_sum = 0;
    for(int i=0; i<w1.length(); i++){
        w1_sum += w1[i]-'A';
    }
    for(int j=0; j<w2.length(); j++){
        w2_sum += w2[j]-'A';
    }

    for(int i=0; i<w1.length(); i++){
        for(int j=0; j<w2.length(); j++){
            if(w1[i]==w2[j]){
                w1_sum -= w1[i]-'A';
                w2_sum -= w2[j]-'A';
            }
        }
    }
    if(w1_sum <= 0 || w2_sum <= 0){
        return true;
    }
    else{
        return false;
    }
}


int main(){
    int word_count;
    cin >> word_count;

    string first_word;
    cin >> first_word;

    int sim_word_count=0;
    for(int i=0; i<word_count-1; i++){
        string tmp;
        cin >> tmp;
        if(isSimilarWord(first_word, tmp)){
            sim_word_count++;
        }
    }

    cout << sim_word_count;
}