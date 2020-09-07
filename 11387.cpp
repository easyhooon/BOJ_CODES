#include <bits/stdc++.h>
using namespace std;


long long op[2],f[2], cc[2], cdr[2], asi[2];
long long w_op[2],w_f[2], w_cc[2], w_cdr[2], w_asi[2];


long long measureCP(long long op, long long f, long long cc, long long cdr, long long asi)
{
	long long CP = op * (100 + f)*((100 - min(cc, (long long)100)) + min(cc, (long long)100) * cdr) * (100 + (asi));

	return CP;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> op[0] >> f[0] >> cc[0] >> cdr[0] >> asi[0];

	cin >> op[1] >> f[1] >> cc[1] >> cdr[1] >> asi[1];

	cin >> w_op[0] >> w_f[0] >> w_cc[0] >> w_cdr[0] >> w_asi[0];

	cin >> w_op[1] >> w_f[1] >> w_cc[1] >> w_cdr[1] >> w_asi[1];

	//cout << f[0] * 0.01f << '\n';
	//소수점 계산 잘 되나 확인 
	long long k_c_cp = measureCP(op[0], f[0], cc[0], cdr[0], asi[0]);
	//cout << k_c_cp << '\n';
	
	long long k_n_cp = measureCP(op[0]-w_op[0] + w_op[1], f[0]-w_f[0]+w_f[1], cc[0]-w_cc[0]+w_cc[1], cdr[0]-w_cdr[0]+w_cdr[1], asi[0]-w_asi[0]+w_asi[1]);
	//cout << k_n_cp << '\n';

	long long p_c_cp = measureCP(op[1], f[1], cc[1], cdr[1], asi[1]);
	//cout << p_c_cp << '\n';

	long long p_n_cp = measureCP(op[1]- w_op[1] + w_op[0], f[1]-w_f[1]+w_f[0], cc[1]-w_cc[1]+w_cc[0], cdr[1]-w_cdr[1]+w_cdr[0], asi[1]-w_asi[1]+w_asi[0]);
	//cout << p_n_cp << '\n';

	if (k_n_cp > k_c_cp) cout << "+"<< '\n';
	else if (k_n_cp == k_c_cp) cout << "0" << '\n';
	else cout << "-" << '\n';

	if (p_n_cp > p_c_cp) cout << "+" << '\n';
	else if (p_n_cp == p_c_cp) cout << "0" << '\n';
	else cout << "-" << '\n';
	return 0;
}