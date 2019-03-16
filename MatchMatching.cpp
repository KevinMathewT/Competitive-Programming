#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, m, a[1010], num[10];

void te(){
	cin >> n >> m;

	num[1] = 2;
	num[2] = 5;
	num[3] = 5;
	num[4] = 4;
	num[5] = 5;
	num[6] = 6;
	num[7] = 3;
	num[8] = 7;
	num[9] = 6;

	ll small = LLONG_MAX;
	for(ll i=0;i<m;i++){
		cin >> a[i];
		small = min(small, num[a[i]]);
	}
	vector<pair<ll, ll> > v;
	for(ll i=0;i<m;i++){
		v.push_back(make_pair(-num[a[i]], a[i]));
	}

	sort(v.begin(), v.end());

	ll flag = 0;
	vector<pair<ll, ll> > ve;

	cout << small << "\n";
	
	for(ll i=m-1;i>=0;i--){
		if(-v[i].first <= n){
			if(n % -v[i].first < small && n % -v[i].first != 0)
				continue;
			ve.push_back(make_pair(v[i].second, n/-v[i].first));
			n = n % -v[i].first;
			if(n < small)
				break;
			i = m;
		}
	}

	sort(ve.begin(), ve.end());

	for(ll i=ve.size()-1;i>=0;i--){
		for(ll j=0;j<ve[i].second;j++)
			cout << ve[i].first;
	}
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