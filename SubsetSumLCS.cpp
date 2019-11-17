#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, a[100000], k;


bool cmp(pair<pair<ll, ll>, ll> a, pair<pair<ll, ll>, ll> b){
	return (abs(a.F.F - k) < abs(b.F.F - k));
}

set<pair<pair<ll, ll>, ll> , decltype(&cmp) > s(&cmp);
ll iter;

void solve(){
	// cout << iter++ << "\n";
	if(s.empty())
		return;
	pair<pair<ll, ll>, ll> pr = *s.begin();
	// cout << pr.F.F << " " << pr.F.S << " " << pr.S << "\n";
	s.erase(s.begin());

	ll sum = 0, flag = 1;
	for(ll i=0;i<n;i++){
		if((pr.F.S & (1 << i)) != 0){
			// cout << pr.F.S << " ";
			// cout << i << " ";
			sum += a[i];
		}
		else
			flag = 0;
	}

	// cout << "\n" << sum << "-\n";

	if(sum == k){
		for(ll i=0;i<n;i++)
			if((pr.F.S & (1 << i)) != 0)
				cout << a[i] << " ";
		cout << "\n";
		return;
	}

	for(ll i=0;i<n;i++){
		if(!(pr.F.S & (1 << i) || pr.S & (1 << i))){
			pr.S ^= (1 << i);
			s.insert(pr);
			pr.S ^= (1 << i);
			pr.F.F += a[i];
			pr.F.S |= (1 << i);
			s.insert(pr);
			break;
		}
	}

	solve();
}

void te(){
	// iter = 0;
	cin >> n;
	for(ll i=0;i<n;i++)
		cin >> a[i];
	cin >> k;

	s.insert(make_pair(make_pair(0, 0), 0));
	// cout << (*s.begin()).F << " " << (*s.begin()).S << "\n";

	solve();
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