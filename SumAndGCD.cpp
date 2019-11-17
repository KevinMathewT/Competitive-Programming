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

ll n, a[100010], pre[100010], suff[100010], final[100010];
vector<ll> b(0);

void solve(){
	b.clear();
	cin >> n;
	for(ll i=0;i<n;i++)
		cin >> a[i];
	if(n == 2 && a[0] == a[1]){
		cout << a[0] + a[1] << "\n";
		return;
	}
	a[n] = -1;
	sort(a, a + n);
	for(ll i=1;i<=n;i++)
		if(a[i] != a[i-1])
			b.push_back(a[i-1]);

	pre[0] = suff[b.size() - 1] = -1;
	pre[1] = b[0];
	suff[b.size() - 2] = b[b.size() - 1];
	for(ll i=2;i<b.size();i++){
		// cout << pre[i-1] << " " << b[i-1] << "\n";
		pre[i] = __gcd(pre[i-1], b[i-1]);
		suff[b.size() - 1 - i] = __gcd(suff[b.size() - i], b[b.size() - i]);
	}

	for(ll i=0;i<b.size();i++){
		if(i == 0)
			final[i] = b[i] + suff[i];
		else if(i == b.size() - 1)
			final[i] = b[i] + pre[i];
		else
			final[i] = b[i] + __gcd(pre[i], suff[i]);
	}

	// for(ll i=0;i<b.size();i++)
	// 	cout << pre[i] << " ";
	// cout << "\n";
	// for(ll i=0;i<b.size();i++)
	// 	cout << suff[i] << " ";
	// cout << "\n";
	// for(ll i=0;i<b.size();i++)
	// 	cout << final[i] << " ";
	// cout << "\n";

	cout << *max_element(final, final + b.size()) << "\n";
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