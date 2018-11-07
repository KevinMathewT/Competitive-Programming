#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

void te(){
	vector<vector<ll> > a(3);
	for(ll i=0;i<3;i++)
		for(ll j=0;j<3;j++){
			ll val; cin >> val;
			a[i].push_back(val);
		}

	vector<pair<ll, vector<ll> > > v;

	for(ll i=0;i<3;i++)
		v.push_back(make_pair(accumulate(a[i].begin(), a[i].end(), 0), a[i]));

	sort(v.begin(), v.end());

	ll b[3][3];

	for(ll i=0;i<3;i++)
		for(ll j=0;j<3;j++)
			b[i][j] = v[i].second[j];

	if(accumulate(b[1], b[1]+3, 0) > accumulate(b[0], b[0]+3, 0) && (b[1][0] >= b[0][0]) && (b[1][1] >= b[0][1]) && (b[1][2] >= b[0][2]) && accumulate(b[2], b[2]+3, 0) > accumulate(b[1], b[1]+3, 0) && (b[2][0] >= b[1][0]) && (b[2][1] >= b[1][1]) && (b[2][2] >= b[1][2]))
		cout << "yes\n";
	else
		cout << "no\n";
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