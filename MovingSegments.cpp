#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;

// Kevin Mathew T
// Birla Institute of Technology, Mesra
// GitHub - https://github.com/KevinMathewT
// CodeForces - https://codeforces.com/profile/KevinMathew
// CodeChef - https://www.codechef.com/users/KevinMathew
// HackerRank - https://www.hackerrank.com/KevinMathew?

ll n, l[1010], r[1010], v[1010];

map<ll, vector<pair<ll, ll> > > mp;
map<ll, ll> vk;

void solve(){
	cin >> n;
	for(ll i=0;i<n;i++)
		cin >> l[i] >> r[i] >> v[i];

	for(ll i=0;i<n;i++)
		mp[v[i]].push_back({l[i], r[i]});

	for(ll i=0;i<n;i++){
		if(vk[v[i]] == 0){
			vk[v[i]] = 1;
			ll s = v[i];
			cout << "-------------\n";
			cout << s << "\n";

			vector<ll> cmp;

			for(ll j=0;j<mp[s].size();j++){
				cmp.push_back(mp[s][j].first);
				cmp.push_back(mp[s][j].second);
				cout << mp[s][j].first << ' ' << mp[s][j].second << "\n";
			}

			sort(cmp.begin(), cmp.end());

			map<ll, ll> rev, forw;

			for(ll i=0;i<cmp.size();i++){
				rev[cmp[i]] = i;
				rev[i] = cmp[i];
			}

			ll arr[cmp.size() + 10];
			fill(arr, arr + cmp.size() + 10, 0);
			
			for(ll j=0;j<mp[s].size();j++){
				arr[forw[mp[s][j].first]]++;
				arr[forw[mp[s][j].second] + 1]--;
			}

			for(ll j=0;j<cmp.size() + 10;j++)
				cout << arr[j] << " ";
			cout << "\n";

			for(ll j=0;j<cmp.size() + 10;j++)
				if(arr[j] == 3){
					cout << "NO\n";
					return;
				}
		}
	}

	cout << "YES\n";
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
		solve();

	return 0;
}