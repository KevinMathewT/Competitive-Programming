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

ll n, m, mn, r, w;
pair<pair<ll, ll>, ll> a[200010];

void solve(){
	cin >> n >> m;
	for(ll i=0;i<n;i++){
		ll b, c;
		cin >> b >> c;
		a[i].first.first = b;
		a[i].first.second = c;
		a[i].second = i + 1;
	}

	sort(a, a + n);
	vector<ll> ans(0), sep(0), sep2(0);

	ll tot = 0, pos = 0, excess = 0;

	for(ll i=n-1;i>=0;i--){
		tot += a[i].first.first;
		ans.push_back(i);
		r++;
		if(tot >= m){
			excess = tot - m;
			pos = i;
			break;
		}
	}

	sort(ans.begin(), ans.end());

	for(ll i=0;i<pos;i++)
		if(a[i].first.second == 1)
			sep.push_back(i);

	sort(sep.begin(), sep.end());

	ll p1 = sep.size() - 1, p2 = 0;

	while(ans.size() > 0 && sep.size() > 0 && p1 >= 0 && p2 < ans.size() && excess >= 0){
		if(a[ans[p2]].first.second == 1){
			p2++;
			continue;
		}

		if(a[ans[p2]].first.first - a[sep[p1]].first.first <= excess){
			excess = excess - (a[ans[p2]].first.first - a[sep[p1]].first.first);
			ans[p2] = sep[p1];
			p1--;
			p2++;
		}
		else
			break;
	}


	// while(ans.size() > 0 && excess >= 0 && sep.size() > 0 && p1 >= 0 && p2 < ans.size()){
	// 	if(a[ans[p2]].first.second == 1){
	// 		p2++;
	// 		continue;
	// 	}
	// 	if((a[ans[p2]].first.first - a[sep[p1]].first.first) <= excess){
	// 		excess -= (a[ans[p2]].first.first - a[sep[p1]].first.first);
	// 		ans[p2] = sep[p1];
	// 	}
	// 	p1--;
	// 	p2++;
	// }

	sort(ans.begin(), ans.end());

	for(ll i=0;i<ans.size();i++)
		if(a[ans[i]].first.second == 1)
			w++;

	cout << r << " " << w << "\n";
	for(ll i=0;i<ans.size();i++)
		ans[i] = a[ans[i]].second;

	sort(ans.begin(), ans.end());
	for(ll i=0;i<ans.size();i++)
		cout << ans[i] << " ";
	cout << "\n";
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	solve();

	return 0;
}