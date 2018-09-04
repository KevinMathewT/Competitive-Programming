#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew

void te(){
	ll n, m, k; cin >> n >> m >> k;
	ll a[n]; for(ll i=0;i<n;i++) cin >> a[i];
	ll op[n], l[m], r[m], d[m];
	for(ll i=0;i<n;i++) op[i] = 0;
	for(ll i=0;i<m;i++)
		cin >> l[i] >> r[i] >> d[i];

	ll nop[m];
	for(ll i=0;i<m;i++) nop[i] = 0;
	for(ll i=0;i<k;i++){
		ll x, y; cin >> x >> y;
		nop[x-1]++;
		if(y < m)
			nop[y]--;
	}
	for(ll i=1;i<m;i++)
		nop[i] = nop[i] + nop[i-1];

	for(ll i=0;i<m;i++){
		op[l[i]-1] += nop[i] * d[i];
		if(r[i] < n)
			op[r[i]] -= nop[i] * d[i];
	}


	for(ll i=1;i<n;i++)
		op[i] = op[i] + op[i-1];
	for(ll i=0;i<n;i++)
		a[i] += op[i];
	for(ll i=0;i<n;i++)
		cout << a[i] << " ";
	cout << "\n";
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	// ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	te();

	return 0;
}