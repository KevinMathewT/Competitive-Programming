#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional> // for less 
#include <iostream> 
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long long ll;
typedef tree<ld, null_type, less<ld>, rb_tree_tag, tree_order_statistics_node_update> pbds; 

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

void te(){
	ll n, t;
	cin >> n >> t;
	vector<ll> l, r;

	for(ll i=0;i<n;i++){
		ll a, b;
		cin >> a >> b;
		l.push_back(a);
		r.push_back(b);
	}

	map<ll, vector<ll> > mv;
	map<ll, vector<ll> > mw;

	for(ll i=0;i<n;i++){
		mv[r[i]].push_back(l[i]);
		mw[l[i]].push_back(r[i]);
	}

	sort(l.begin(), l.end());
	sort(r.begin(), r.end());
	ll pos = 0;
	ll pot = 0;
	ll size = 0;
	ll sizf = 0;
	ll ans = 0;
	ll ant = 0;

	pbds p;
	pbds q;

	for(ll i=0;i<n;i++){
		ll s = l[i] - 1;
		ll e = s + t;

		while(true){
			if(r[pos] > e || pos == n)
				break;
			for(ll i=0;i<mv[r[pos]].size();i++){
				p.insert(mv[r[pos]][i]);
				size++;
			}
			pos++;
		}
		
		while(true){
			if(l[pot] > e || pot == n)
				break;
			for(ll i=0;i<mv[l[pot]].size();i++){
				p.insert(mv[r[pot]][i]);
				size++;
			}
			pos++;
		}

		// cout << size - p.order_of_key(s+1) << "-\n";

		ans = max((ll)ans, (ll)(size-p.order_of_key(s+1)));
	}

	// cout << ans << "-\n";
	cout << max((ll)0, ans - (n - ans)) << "\n";
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