#include <iostream>

using namespace std;

long GCD(long a, long b)  
{
    if (b == 0) {
        return a;
    }
    return GCD(b, a%b);
}

int main()
{
    long a1, a2, b1, b2, ans1, ans2;
    cin >> a1 >> a2 >> b1 >> b2;
    
    ans2 = a2 * b2 / GCD(a2, b2);
    ans1 = a1*(ans2/a2) + b1*(ans2/b2);
    
    cout << ans1/GCD(ans1, ans2) << " " << ans2/GCD(ans1, ans2);
}