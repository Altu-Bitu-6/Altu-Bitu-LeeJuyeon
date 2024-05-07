#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, tmp;
vector<int> my_num;

int binarySearch(int n, int key, vector<int>& nums) {
    int left = 0; 
    int right = n - 1;
    int mid;
    
    while (left <= right) {
        mid = (left + right) / 2;
        if (nums[mid] == key) {  
            return 1;
        }
        else if (nums[mid] > key) { 
            right = mid - 1;
        }
        else {  
            left = mid + 1;
        }
    }
    return 0;
}

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(NULL);

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> tmp;
        my_num.push_back(tmp);
    }
    sort(my_num.begin(), my_num.end());

    cin >> m; 
    for(int i=0; i<m; i++){
        cin >> tmp;
        cout << binarySearch(n, tmp, my_num) << " ";
    }

    return 0;
}