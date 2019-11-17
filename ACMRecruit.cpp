#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

const ll p = 27, m = 1e9 + 7;
ll n, dp[1000][1000], hash_dp[1000][1000];
string dict[10000];
char curr[100000];
unordered_map<ll, ll> mp;

ll hash(char[] s, ll size){
	ll hash = 0, p_pow = 1;

	for(ll i=0;i<size;i++){
		hash = (hash + ((s[i] * (p_pow)) % m)) % m;
		p_pow = (p_pow * p) % m;
	}

	return hash;
}

void te(){
	cin >> n;
	for(ll i=0;i<n;i++)
		cin >> dict[i];

	for(ll i=0;i<n;i++){
		for(ll j=0;j<dict[i].size();j++){
			ll hash = 0, p_pow = 1;

			for(ll i=0;i<dict[i].size;i++){
				hash = (hash + ((s[i] * (p_pow)) % m)) % m;
				p_pow = (p_pow * p) % m;
			}

			mp[hash] = 1;
		}
	}

	ll t;
	for(ll i=0;i<t;i++){
		char c;
		cin >> c;
		
		curr[i] = c;
		for(ll j=0;j<=i;j++){
			for(ll k=1;k<=i+1;k++){
				char temp[k];
				ll pos = 0;
				
				for(ll l=j;l<j+k;l++)
					
			}
		}
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