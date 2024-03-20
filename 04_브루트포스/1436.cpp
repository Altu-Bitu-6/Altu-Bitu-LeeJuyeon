#include <iostream>
#include <string>

using namespace std;

int findMovieSeries(int N)
{
    int i = 666;
    int series = 0;
    string movie_name;
    while(true)
    {
        movie_name = to_string(i);
        for(int j = 0; j < movie_name.length()-2; j++)
            if(movie_name[j] == '6' && movie_name[j+1] == '6' && movie_name[j+2] == '6')
            {
                series++;
                if(series == N)
                    return i;
                break;
            }
        i++;
    }
}
int main() {
    int N;
    cin >> N;
    cout << findMovieSeries(N);
}