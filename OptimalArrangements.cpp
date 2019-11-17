#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;

ll n, h[110][110];
vector<ll> q;
unordered_map<ll, ll> m;

void solve(){
	cin >> n;
	for(ll i=0;i<n;i++)
		for(ll j=0;j<n;j++)
			cin >> h[i][j];

	q.clear();
	m.clear();

	for(ll i=0;i<n;i++){
		ll mx = -1, pos = -1;
		for(ll j=0;j<n;j++){
			ll tot = 0;
			if(m[j] == 1)
				continue;
			for(ll k=0;k<n;k++){
				if(m[k] == 1)
					continue;
				tot += h[j][k];
			}
			if(tot > mx){
				mx = tot;
				pos = j;
			}
		}

		q.push_back(pos);
		m[pos] = 1;
	}

	for(ll i=0;i<q.size();i++)
		cout << (q[i] + 1) << " ";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	solve();

	return 0;
}