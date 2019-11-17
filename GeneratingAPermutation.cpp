#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;

// Kevin Mathew T
// Birla Institute of Technology, Mesra
// GitHub - https://github.com/KevinMathewT
// CodeForces - https://codeforces.com/profile/KevinMathew
// CodeChef - https://www.codechef.com/users/KevinMathew
// HackerRank - https://www.hackerrank.com/KevinMathew?

ll n, k, a[100010];

void solve(){
	cin >> n >> k;

	if(n == 1){
		if(k == 0) cout << 1 << "\n";
		else cout << "-1\n";
		return;
	}

	if(n == 2){
		if(k == 2) cout << "1 2" << "\n";
		else cout << "-1\n";
		return;
	}

	a[0] = 0;
	a[1] = n-2;
	ll i = 2;
	while(true){
		a[i] = a[i-1] - 2;
		if(a[i] <= 0)
			break;
		i++;
	}

	// for(ll j=0;j<i;j++)
	// 	cout << a[j] << ' ';
	// cout << "\n";

	for(ll j=1;j<i;j++)
		a[j] += a[j-1];

	// for(ll j=0;j<i;j++)
	// 	cout << a[j] << ' ';
	// cout << "\n";

	ll mn = ((n * (n + 1)) / 2) - 1;
	if(k < mn || k > (mn + a[i - 1])){
		cout << -1 << "\n";
		return;
	}


	// cout << mn << " " << (mn + a[i - 1]) << "\n";
	// cout << i << "\n";

	ll pos = -1, diff = k - mn, df;
	for(ll j=0;j<i;j++)
		if(a[j] <= diff){
			pos = j;
			df = diff - a[j];
		}

	// cout << pos << "---\n";

	ll l = 1, r = n;

	// cout << r << "////////////\n";

	for(ll j=0;j<pos;j++){
		cout << l << " " << r << " ";
		l++;
		r--;
	}

	// cout << '\n';
	// cout << diff << " ";
	// cout << l << ' ' << r << "----\n";
	// cout << r - diff << "\n";

	for(ll j=l;j<r;j++){
		if(j == (r - df))
			cout << r << " ";
		cout << j << " ";
	}

	if(df == 0)
		cout << r;

	cout << "\n";
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T;
	cin >> T;
	while(T--)
		solve();

	return 0;
}