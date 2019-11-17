#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;

// Kevin Mathew T
// Birla Institute of Technology, Mesra
// GitHub - https://github.com/KevinMathewT
// CodeForces - https://codeforces.com/profile/KevinMathew
// CodeChef - https://www.codechef.com/users/KevinMathew
// HackerRank - https://www.hackerrank.com/KevinMathew

ll n, m, a[100010];

void solve(){
	cin >> n >> m;
	for(ll i=0;i<n;i++)
		cin >> a[i];

	priority_queue<ll> pq;
	for(ll i=0;i<n;i++)
		pq.push(a[i]);

	for(ll i=0;i<m;i++){
		ll x = pq.top();
		pq.pop();
		pq.push(x / 2);
	}

	ll tot = 0;
	for(ll i=0;i<n;i++){
		tot += pq.top();
		pq.pop();
	}

	cout << tot << "\n";
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