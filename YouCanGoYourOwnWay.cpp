#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n;
string s;

void te(ll test){
	cin >> n >> s;

	cout << "Case #" << (test) << ": ";
	for(ll i=0;i<2*n-2;i++)
		if(s[i] == 'E')
			cout << 'S';
		else
			cout << 'E';

	cout << "\n";
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
	for(ll i=1;i<=T;i++)
		te(i);

	return 0;
}