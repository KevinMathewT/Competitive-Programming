#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
#define F first
#define S second

// Kevin Mathew T
// Birla Institute of Technology, Mesra
// GitHub - https://github.com/KevinMathewT
// CodeForces - https://codeforces.com/profile/KevinMathew
// CodeChef - https://www.codechef.com/users/KevinMathew
// HackerRank - https://www.hackerrank.com/KevinMathew?

ll n, b, a[1000010];
priority_queue<pair<ll, ll> > pq;

void solve(){
	cin >> n >> b;
	for(ll i=0;i<n;i++)
		cin >> a[i];
	pq.empty();

	for(ll i=0;i<n;i++)
		pq.push({a[i], - i - 1});

	for(ll i=0;i<b;i++){
		pair<ll, ll> pll = pq.top();
		pq.pop();

		cout << -pll.S << " ";

		pll.F -= 1;
		pq.push(pll);
	}
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