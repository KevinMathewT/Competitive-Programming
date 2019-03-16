#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

void te(){
	string s;
	cin >> s;
	// cout << s.size() << "\n";

	ll n = s.size();
	ll a[n];

	a[0] = 0;
	// cout << a[0] << "\n";
	for(ll i=1;i<n;i++){
		if(s[i-1] == 'A' && s[i] == 'B')
			a[i] = a[i-1] + 1;
		else if(s[i-1] == 'B' && s[i] == 'A')
			a[i] = a[i-1] - 1;
		else
			a[i] = a[i-1];
		// cout << a[i] << " ";
	}

	for(ll i=1;i<n-1;i++)
		if(a[i-1] != a[i] && a[i] == a[i+1]){
			cout << "YES\n";
			return;
		}

	cout << "NO\n";
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