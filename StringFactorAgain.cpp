#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

void te(){
    const ll p = 31;
    const ll m = 4294967296;
    ll hash_value = 0;
    ll p_pow = 1;

    unordered_map<ll, ll> freq;

    ll n;
    cin >> n;
    string s;

    ll maxi = -1;
    for(ll i=0;i<n;i++){
    	cin >> s;
    	ll val = 0;
    	hash_value = 0;
    	ll j = 1;
    	p_pow = 1;
    	for (ll k=0;k<s.size();k++) {
    		// cout << c;
        	hash_value = (hash_value + (s[k] - 'a' + 1) * p_pow) & (m - 1);
        	p_pow = (p_pow * p) & (m - 1);
        	freq[hash_value]+=j;
        	j++;
        	maxi = max(maxi, freq[hash_value]);
    	}
    	// cout << "\n";
    }

    // ll maxi = -1;

    // for(ll i=0;i<n;i++){
    // 	// cin >> s[i];
    // 	ll val = 0;
    // 	ll j = 1;
    // 	hash_value = 0;
    // 	p_pow = 1;
    // 	for (ll i=0;i<s[i].size();i++) {
    //     	hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
    //     	p_pow = (p_pow * p) % m;
    //     	maxi = max(maxi, (j) * freq[hash_value]);
    //     	// cout << freq[hash_value] << "\n";
    //     	j++;
    // 	}
    // }

    cout << maxi << "\n";

    // string a;
    // cin >> a;
    // cout << a << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T;
	cin >> T;
	while(T--)
		te();

	return 0;
}