#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, countAns, val[100010], vis[100010], fact[100010], seive[100010];
vector<ll> gcd, factors(0);
vector<pair<ll, ll> > ans;
vector<ll> tree[100010];

void factorize(ll x){
	factors.clear();

	while(x != 1){
		factors.push_back(seive[x]);
		x /= seive[x];
	}
}

void seiveOfEratosthenes(){
	for(ll i=2;i<100010;i++)
		seive[i] = i;

	for(ll i=2;i*i<100010;i++)
		if(seive[i] == i)
			for(ll j=i*i;j<100010;j+=i)
				seive[j] = i;
}

void dfs(ll x, ll d){
	vis[x] = 1;
	ll leaf = 1;
	for(ll i=0;i<tree[x].size();i++)
		if(vis[tree[x][i]] == 0)
			leaf = 0;

	if(leaf == 0){
		factorize(val[x]);
		// cout << val[x] << "-------\n";
		// for(ll i=0;i<factors.size();i++)
		// 	cout << factors[i] << " " ;
		// cout << "\n";

		for(ll i=1;i<(1<<factors.size());i++){
			ll p = 1;
			for(ll j=0;j<factors.size();j++)
				if(i & (1<<j)){
					// cout << 1 << " ";
					p *= factors[j];
				}
				else
					// cout << 0 << " ";
			// cout << "\n";
			// cout << p << "-\n";
			fact[p]++;
		}

		for(ll i=0;i<tree[x].size();i++)
			if(vis[tree[x][i]] != 1)
				dfs(tree[x][i], d + 1);

		for(ll i=1;i<(1<<factors.size());i++){
			ll p = 1;
			for(ll j=0;j<factors.size();j++)
				if(i & (1 << j))
					p *= factors[j];
			fact[p]--;
		}
	}

	if(leaf == 1){
		ll countAns = 0;
		factorize((ll)(__gcd(val[x], val[1])));

		cout << x << " " << val[x] << "--------\n";
		for(ll i=0;i<factors.size();i++)
			cout << factors[i] << " " ;
		cout << "\n";

		for(ll i=1;i<(1<<factors.size());i++){
			ll p = 1, addOrNot = 0;
			cout << p << "\n";
			for(ll j=0;j<factors.size();j++){
				// cout << "HEY\n";
				if(i & (1<<j)){
					// cout << 1 << "-";
					p *= factors[j];
					addOrNot ^= 1;
				}
				else{
					// cout << 0 << "-";
				}

				// cout << "\n";
				// cout << p << "---\n";
			}

			if(addOrNot == 1)
				countAns += fact[p];
			else
				countAns -= fact[p];
			cout << countAns << "/-\n";
		}


		cout << countAns << "\n";
		cout << d - 2 - countAns << "---\n";
		ans.push_back(make_pair(d - 2 - countAns, x));
		countAns = 0;
	}
}

void te(){
	cin >> n;
	for(ll i=0;i<100010;i++){
		fact[i] = 0;
		vis[i] = 0;
	}
	vis[1] = 1;
	for(ll i=1;i<=n;i++)
		cin >> val[i];

	for(ll i=0;i<n-1;i++){
		ll u, v;
		cin >> u >> v;

		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	seiveOfEratosthenes();

	for(ll i=0;i<tree[1].size();i++)
		dfs(tree[1][i], 2);

	sort(ans.begin(), ans.end());
	for(ll i=ans.size()-1;i>=0;i--)
		cout << ans[i].second << " " << ans[i].first << "\n";;
	cout << "\n";
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