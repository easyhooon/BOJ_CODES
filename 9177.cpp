#include <bits/stdc++.h>

using namespace std;

bool flag;


int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
    string fir,sec,thr;

	cin >> n;

    while(n--){

        cin >> fir >> sec >> thr;

        if(flag){
            cout << "Data set n: yes" <<'\n';
        }
        else{
            cout << "Data set n: no" <<'\n';
        }

    }


	return 0;
}