#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int wheelCount, spinCount;
    int arrow = 0;
    bool isTrue = true;
    
    cin >> wheelCount >> spinCount;
    
    vector<char> wheel(wheelCount);
    
    for(int i=0; i<wheelCount; i++){
        wheel[i] = '?';
    }
    
    
    int spin;
    char letter;
    
    for(int i=0; i<spinCount; i++){
        cin >> spin >> letter;
        arrow = (arrow + spin) % wheelCount;
        if(wheel[arrow]=='?' || wheel[arrow]==letter){
            wheel[arrow] = letter;
            for(int j=0; j<wheelCount; j++){
                if(wheel[arrow]==wheel[j] && arrow!=j){
                    isTrue = false; 
                    break;
                }
            }
        }
        else {
            isTrue = false; 
            break;
        }
    }
    
    if(isTrue){
        for(int i=wheelCount; i>0; i--){
            cout << wheel[(arrow+i) % wheelCount];
        }
    }
    else{
        cout << "!";
    }
    
}