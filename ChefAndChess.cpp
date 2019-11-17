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

ll n, fact[20000010], M = 1000000007;

ll modexpo(ll x, ll p){
	if(p == 0)
		return 1;
	if(p == 1)
		return x;
	if(p % 2 == 0)
		return modexpo((x * x) % M, p / 2);
	return (x * (modexpo((x * x) % M, p / 2))) % M;
}

void solve(){
	cin >> n;
	if(n % 2 == 1) n++;
	n /= 2;

	cout << (fact[2 * n] * modexpo((modexpo(2, n) * fact[n]) % M, M - 2)) % M << "\n";
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	fact[1] = 1;
	for(ll i=2;i<=20000010;i++)
		fact[i] = (i * fact[i-1]) % M;

	ll T;
	cin >> T;
	while(T--)
		solve();

	return 0;
}