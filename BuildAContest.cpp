#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, m, a[100010], ans[100010];
unordered_map<ll, ll> um;
unordered_map<ll, ll> found;
ll countFound;

void te(){
	countFound = 0;
	cin >> n >> m;
	for(ll i=0;i<m;i++)
		cin >> a[i];

	for(ll i=0;i<m;i++){
		// cout << um[a[i]] << " " << countFound << "\n";
		if(um[a[i]] == 0){
			found[a[i]] = 1;
			countFound++;
		}

		um[a[i]]++;

		if(countFound == n){
			ans[i] = 1;
			for(ll i=1;i<=n;i++){
				um[i]--;
				if(um[i] == 0){
					found[i] = 0;
					countFound--;
				}
			}
		}
		else
			ans[i] = 0;
	}

	// cout << "\n";

	for(ll i=0;i<m;i++)
		cout << ans[i] << "";
	cout << "\n";
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