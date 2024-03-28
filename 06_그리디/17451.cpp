#include <iostream>
#include <vector>
using namespace std; 

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int planet_count;
    cin >> planet_count;

    vector<long long> planet;
    for(int i=0; i<planet_count; i++){
        long long tmp;
        cin >> tmp;
        planet.push_back(tmp);
    }

    long long max_speed = planet[planet.size()-1];

    for(int i = planet.size()-2; i >= 0; i--){
        if(planet[i] >= max_speed){
            max_speed = planet[i];
        }
        else if(planet[i] < max_speed){
            if(max_speed % planet[i] != 0){
                max_speed = (max_speed / planet[i] + 1) * planet[i];
            }
            else{
                continue;
            }
        }
        else{
            continue;
        }
    }

    cout << max_speed;
}