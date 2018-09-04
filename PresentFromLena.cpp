#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void te(){
	ll n; cin >> n;
	string s;
	for(ll i=0;i<n;i++){
		for(ll j=n-i-1;j>=0;j--)
			cout << "  ";
		for(ll j=0;j<i;j++)
			cout << j << " ";
		cout << i << " ";
		for(ll j=i-1;j>=0;j--)
			cout << j << " ";
		cout << "\n";
	}
	for(ll i=0;i<=n;i++) cout << i << " ";
	for(ll i=n-1;i>=0;i--) cout << i << " ";
	cout << "\n";
	for(ll i=n-1;i>=0;i--){
		for(ll j=n-i-1;j>=0;j--)
			cout << "  ";
		for(ll j=0;j<i;j++)
			cout << j << " ";
		cout << i << " ";
		for(ll j=i-1;j>=0;j--)
			cout << j << " ";
		cout << "\n";
	}
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	te();

	return 0;
}