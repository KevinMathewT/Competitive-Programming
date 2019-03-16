#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, k, freq[26];
string s;

void te(){
	cin >> n >> k;
	cin >> s;
	for(ll i=0;i<26;i++)
		freq[i] = 0;

	for(ll i=0;i<=n-k;i++){
		ll flag = 1, j;
		for(j=i+1;j<i+k;j++){
			if(s[j] != s[i]){
				flag = 0;
				break;
			}
		}
		i = j-1;
		// cout << i << " " << flag << "\n";;

		if(flag == 1)
			freq[s[i] - 'a']++;
	}

	ll mx = 0;
	for(ll i=0;i<26;i++)
		mx = max(mx, freq[i]);

	cout << mx << "\n";
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