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

ll n, k, a[100010], b[100010];
unordered_map<ll, ll> c, d;

void solveit(){
	cin >> n >> k;
	c.clear();
	d.clear();
	for(ll i=0;i<n;i++) cin >> a[i];
	for(ll i=0;i<n;i++) cin >> b[i];

	for(ll i=0;i<n;i++) c[a[i]]++;
	for(ll i=0;i<n;i++) d[b[i]]++;

	ll m = 0, ba = 0;

	for(ll i=0;i<=k/2;i++)
		if(!(k % 2 == 0 && i == (k/2)))
		m += c[i] * c[k-i];
	for(ll i=0;i<=k/2;i++)
		if(!(k % 2 == 0 && i == (k/2)))
		ba += d[i] * d[k-i];

	// cout << m << ' ' << ba << "\n";
	if(k % 2 == 0){
		m += (c[k/2] * (c[k/2] - 1)) / 2;
		ba += (d[k/2] * (d[k/2] - 1)) / 2;
	}	

	// cout << m << ' ' << ba << "\n";
	if(m > ba)
		cout << "MAHMOUD\n";
	else if(ba > m)
		cout << "BASHAR\n";
	else
		cout << "DRAW\n";
}

int main()
{   
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	solveit();

	return 0;
}