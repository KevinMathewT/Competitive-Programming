#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

void te(){
	ll n;
	cin >> n;

	ll a[n+1];
	for(ll i=2;i<=n;i++)
		cin >> a[i];

	ll leaf[n+1];
	for(ll i=0;i<=n;i++)
		leaf[i] = 1;

	for(ll i=2;i<=n;i++){
		leaf[a[i]] = 0;
		// cout << leaf[i] << "\n";
	}

	ll b[n+1] = {0};
	for(ll i=0;i<=n;i++)
		b[i] = 0;

	for(ll i=2;i<=n;i++){
		if(leaf[i] == 1)
			b[a[i]]++;
		// cout << leaf[i] << " " << b[i] << "\n";
	}

	for(ll i=1;i<=n;i++){
		if(leaf[i] == 0 && b[i] < 3){
			cout << "NO\n";
			return;
		}
	}

	cout << "YES\n";
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	te();

	return 0;
}