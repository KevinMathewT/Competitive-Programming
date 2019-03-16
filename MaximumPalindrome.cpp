#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

string s1;
unordered_map<ll, unordered_map<ll, ll> > dp1, dp2;
char s[100000];

void te(){
	getline(cin, s1);
	ll point = 0, m = 1e9+7, p = 27;

	for(ll i=0;i<s1.size();i++){
		if(isalpha(s1[i]) && s[i] != ' ')
			s[point++] = tolower(s1[i]);
	}

	// for(ll i=0;i<point;i++)
	// 	cout << s[i];
	// cout << "\n";

	for(ll i=0;i<point;i++){
		ll hash = 0;
		ll p_pow = 1;
		for(ll j=i;j<point;j++){
			hash = (hash + ((s[j] - 'a' + 1) * p_pow)) % m;
			p_pow = (p * p_pow) % m;
			dp1[i][j] = hash;
			// cout << i << " " << j << " " << hash << "\n";
		}
	}

	for(ll i=point-1;i>=0;i--){
		ll hash = 0;
		ll p_pow = 1;
		for(ll j=i;j>=0;j--){
			hash = (hash + ((s[j] - 'a' + 1) * p_pow)) % m;
			p_pow = (p * p_pow) % m;
			dp2[j][i] = hash;
			// cout << i << " " << j << " " << hash << "-\n";
		}
	}

	ll mx = 0;

	for(ll i=0;i<point;i++)
		for(ll j=i;j<point;j++){
			if(dp1[i][j] == dp2[i][j]){
				// cout << "sdfghjkljhgfdfgh\n";
				mx = max(mx, abs(i-j) + 1);
			}
		}

	if(mx == point)
		cout << "pure palindrome\n";
	else
		cout << mx << "\n";
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
	cin.ignore(256, '\n');
	while(T--)
		te();

	return 0;
}