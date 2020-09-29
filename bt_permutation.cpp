#include <bits/stdc++.h>

using namespace std;

void permute()
{
    vector<int> v = {0, 0, 0, 0, 1, 1};

    do{
        for(int i = 0; i <v.size(); i++)
        {
            if(v.at(i) == 0)
                cout << i+1 << ' ';
        }

        cout << '\n';
    }while(next_permutation(v.begin(), v.end()));
}

int main()
{
    permute();

    return 0;
}