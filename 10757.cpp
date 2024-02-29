#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string a, b;
    cin >> a >> b;
    int lenA = a.length();
    int lenB = b.length();

    stack<int> s_a;
    stack<int> s_b;
    stack<int> answer;

    if (lenB > lenA) {
        swap(a, b);
        swap(lenA, lenB);
    }

    if (lenA != lenB){
        for (int i=0; i < (lenA - lenB); i++)
            s_b.push(0);
    }

    for(int i=0; i<a.length(); i++){ int tmp = a[i]-'0'; s_a.push(tmp); }
    for(int i=0; i<b.length(); i++){ int tmp = b[i]-'0'; s_b.push(tmp); }

    int carry = 0; 
    int sum; 
    
    for(int i=0; i < lenA; i++)
    {
        sum = s_a.top() + s_b.top();
        
        if(carry==1)
        {
            sum++;
            carry = 0;
        }
        if(sum > 9)
        {
            carry = 1;
        }

        answer.push(sum % 10);

        s_a.pop();
        s_b.pop();
    }

    if(carry==1) {answer.push(1);}
    
    while(!answer.empty())
    {
        cout << answer.top();
        answer.pop();
    }

}