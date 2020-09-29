#include <bits/stdc++.h>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v;

    int n, s, e , sum;
    int min_sum = INT_MAX;
   
    cin >> n;

    for(int i = 0; i < n; i++){
        int input;
        cin >> input;
        v.push_back(input);
    }

    // sort(v, v+n); //정렬 먼저 조지고

    s = 0;
    e = n-1;

    while(s < e){
        sum = v[s] + v[e];
        
        if (abs(sum) < abs(min_sum))
            min_sum = sum;
        
        if(abs(v[s] + v[e]) >= abs(v[s] + v[e-1]))
            e--;
        
        else if(e + 1 < n && abs(v[s] + v[e]) > abs(v[s] + v[e+1]))
            e++;
        
        //else if(s-1 > 0 && abs(v[s] + v[e]) > abs(v[s-1] + v[e]))
        //    s--;
        else 
            s++;
    }

    // for(int i = 0; i < n-1; i++){
    //     for(int j = i+1; j < n; j++){
    //         tmp = abs(v[i] + v[j]);
    //         if(tmp < ans) {
    //             ans = tmp;
    //             x = i;
    //             y = j;
    //         }            
    //     }
    // }
    //시간초과 삘인데 

    cout << min_sum << '\n';
}