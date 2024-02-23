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

    stack<int> s_a;
    stack<int> s_b;

    for(int i=0; i<a.length(); i++){ s_a.push(a[i]-'0'); }
    for(int i=0; i<b.length(); i++){ s_b.push(b[i]-'0'); }

    stack<int> answer;

    while(!s_a.empty() || !s_b.empty())
    {
        int sum = s_a.top() + s_b.top(); 
        answer.push(sum % 10);
        int carry = sum/10;
        
        s_a.pop();
        s_b.pop();
        
        if(s_a.empty() && carry > 0)
        {
            answer.push(carry);
        }
        else
        {
            int temp = s_a.top();
            s_a.pop();
            s_a.push(temp+carry);
        }
    }

    for(int i=0; i<answer.size(); i++)
    {
        cout << answer.top();
        answer.pop();
    }
}