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

string a, b;
vector<pair<char, ll> > c, d;

void solve(){
	c.clear();
	d.clear();
	cin >> a >> b;

	c.push_back(make_pair(b[0], 1));
	for(ll i=0;i<b.size();i++)
		if(b[i] == c[c.size()-1].first)
			c[c.size()-1].second = c[c.size()-1].second + 1;
		else
			c.push_back(make_pair(b[i], 1));


	d.push_back(make_pair(a[0], 1));
	for(ll i=0;i<a.size();i++)
		if(a[i] == d[d.size()-1].first)
			d[d.size()-1].second = d[d.size()-1].second + 1;
		else
			d.push_back(make_pair(a[i], 1));

	if(c.size() != d.size()){
		cout << "NO\n";
		return;
	}

	for(ll i=0;i<c.size();i++){
		if(c[i].first != d[i].first || c[i].second < d[i].second){
			cout << "NO\n";
			return;
		}
	}

	cout << "YES\n";
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
	while(T--)
		solve();

	return 0;
}