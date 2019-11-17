#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
#define M 1000000007

// Kevin Mathew T
// Birla Institute of Technology, Mesra
// GitHub - https://github.com/KevinMathewT
// CodeForces - https://codeforces.com/profile/KevinMathew
// CodeChef - https://www.codechef.com/users/KevinMathew
// HackerRank - https://www.hackerrank.com/KevinMathew?

ll n, m, c;

ll power(ll x, ll a){
	if(a == 0) return 1;
	if(a == 1) return x;
	if(a % 2 == 0) return power((x * x) % M, a / 2);
	return (x * (power((x * x) % M, a / 2))) % M;
}

ll getburn(ll x){
	ll tot = 0;

	for(ll i=1;i<=m;i++){
		tot = (tot + power(x, __gcd(m, i))) % M;
	}

	return (tot * power(m, M - 2)) % M;
}

void solve(){
	cin >> n >> m >> c;
	ll color = power(power(c, n), n);

	cout << getburn(color) << "\n";
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	solve();

	return 0;
}