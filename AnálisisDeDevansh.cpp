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

ll n, a[100010], pos[100010], b[100010], fact[100010], M = 1000000007;

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
	for(ll i=0;i<n;i++)
		cin >> a[i];
	sort(a, a + n);
	a[n] = -1;

	pos[0] = 0;
	pos[1] = 1;

	ll c = 2;
	ll i = 2, j = n-1;
	while(i <= j){
		pos[j--] = c++;
		if(i == j + 1)
			break;
		pos[i++] = c++;
	}

	for(ll i=0;i<n;i++)
		b[i] = a[pos[i]];
	for(ll i=0;i<n;i++)
		cout << b[i] << " ";
	cout << "\n";

	ll p = 1, q = fact[n];
	ll gcd = __gcd(p, q);

	ll curr = 1, curr_fact = 1, arr_fact = 1;
	q = 1;

	for(ll i=1;i<=n;i++){
		q = (q * i) % M;
		if(a[i] == a[i-1]){
			curr++;
			curr_fact = (curr_fact * curr) % M;
		}
		else{
			// cout << p << " " << curr << " " << curr_fact << " " << q << "\n";
			p = (p * curr_fact) % M;
			ll gcd = __gcd(p, q);
			p = (p * modexpo(gcd, M - 2)) % M;
			q = (q * modexpo(gcd, M - 2)) % M;
			curr = 1;
			curr_fact = 1;
		}
	}

	// cout << p << " " << q << "\n";

	gcd = __gcd(p, q);
	p /= gcd;
	q /= gcd;

	cout << (((p * q) % M) + ((p + q) % M)) % M << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	fact[1] = 1;
	for(ll i=2;i<100010;i++)
		fact[i] = (i * fact[i - 1]) % M;
	ll T;
	cin >> T;
	while(T--)
		solve();

	return 0;
}