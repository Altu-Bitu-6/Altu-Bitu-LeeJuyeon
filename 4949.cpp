#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool checkBalance(stack<char>& s, char a){
    if(a=='(' || a=='['){//여는 괄호일 경우
        s.push(a);
    }
    else if(a==')'){//닫는 괄호일 경우 1
        if(!s.empty() && s.top()=='(') {
            s.pop(); 
        } 
        else { 
            //yes_or_no = false; break; 
            return false;
        } 
    }
    else if(a==']'){//닫는 괄호일 경우 2
        if(!s.empty() && s.top()=='[') { 
            s.pop(); 
        } 
        else { 
            //yes_or_no = false; break; 
            return false;
        } 
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while(true)
    {
        stack<char> s;
        string my_string;

        getline(cin, my_string);
        if(my_string==".") break;

        bool yes_or_no = true;
        for (int i=0; i < my_string.length()-1; i++){//배열의 크기만큼 반복 확인
            char a = my_string[i];
            if(!checkBalance(s, a)){
                yes_or_no = false;
            }
        }
        
        if(yes_or_no && s.empty()) { cout << "yes\n"; }
        else { cout <<"no\n"; }
    }
   
}