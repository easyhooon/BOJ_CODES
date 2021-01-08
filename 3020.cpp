
// #include <bits/stdc++.h>

// using namespace std;

// const int N_MAX = 200000;
// const int H_MAX = 500000;

// int N_arr[N_MAX+1];
// int cnt_arr[H_MAX+1];

// int n, h;

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     cin >> n >> h;

//     for (int i = 1; i <= n; i++){
//         cin >> N_arr[i];
//     }

//     for(int i = 1; i <= h; i++){
//         for (int j = 1; j <= n; j++){
//             if((j % 2) != 0){
//                 if(i <= N_arr[j]) cnt_arr[i]++;
//             }
//             else{
//                 if((h-i) <= (h- N_arr[j])) cnt_arr[i]++;
//             }
//         }
//     }

//     int min_cnt = 987654321;
//     for(int i = 1; i <= h; i++){
//         // cout << cnt_arr[i] << ' ';
//         min_cnt = min(min_cnt, cnt_arr[i]);
//     }

//     // cout << min_cnt << '\n';

//     int cnt = 0;

//     for (int i =1; i <= h; i++){
//         if(min_cnt == cnt_arr[i])
//             cnt++;
//     }

//     cout << min_cnt << ' ' << cnt << '\n';
        
//     return 0;
// }
#include <bits/stdc++.h>

using namespace std;
int top[100001];
int bottom[100001];
int n, h;
int result = 200001, result_cnt = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> n >> h;

	for (int i = 0; i < n/2; i++) 
		cin >> top[i] >> bottom[i];
		
	sort(top, top + (n / 2));
	sort(bottom, bottom + (n / 2));

	for (int i = 1; i <= h; i++) {

		int val = lower_bound(top, top + (n / 2), i ) - top ;
		val += upper_bound(bottom, bottom + (n / 2), h-i ) - bottom ;
		val = n - val;

		if (result == val)
			result_cnt++;
		else if (result > val) { 
			result = val;
			result_cnt = 1;
		}
	}

	cout << result << ' ' << result_cnt << '\n';

}