#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew

void te(){
	ll n, m; cin >> n >> m;
	ll a[m]; for(ll i=0;i<m;i++) cin >> a[i];

	sort(a, a+m);
	ll minimum = LLONG_MAX;
	for(ll i=0;i+n-1<m;i++)
		minimum = min(minimum, a[i+n-1]-a[i]);

	cout << minimum << "\n";
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