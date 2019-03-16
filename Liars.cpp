#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll intersection(ll l1, ll r1, ll l2, ll r2){
	if((l1 <= r2 && l1 >= l2) || ((r1 <= r2 && r1 >= l2)))
		return (ll)1;
	return (ll)0;
}

void te(){
	ll n;
	cin >> n;
	ll l[n], r[n];
	for(ll i=0;i<n;i++)
		cin >> l[i] >> r[i];

	ll r1 = *min_element(l, l+n);
	ll l1;
	for(ll i=0;i<n;i++)
		if(r[i] == r1){
			l1 = l[i];
			break;
		}

	ll v[n];
	for(ll i=0;i<n;i++)
		v[i] = 0;
	ll ans = 0;

	for(ll i=0;i<n;i++){
		if(intersection(l[i], r[i], l1, r1)){
			v[i] = 1;
			ans++;
		}
	}

	ll interl1 = LLONG_MIN, interr1 = LLONG_MAX;
	for(ll i=0;i<n;i++){
		if(v[i] == 1){
			interl1 = max(interl1, l[i]);
			interr1 = min(interr1, r[i]);
		}
	}

	ll l2, r2;
	for(ll i=0;i<n;i++)
		if(v[i] != 1){
			l2 = l[i];
			r2 = r[i];
		}

	ll secans = 0;
	for(ll i=0;i<n;i++){
		if(intersection(l[i], r[i], l2, r2)){
			v[i] = 2;
			secans++;
		}
	}

	ll interl2 = LLONG_MIN, interr2 = LLONG_MAX;
	for(ll i=0;i<n;i++){
		if(v[i] == 2){
			interl2 = max(interl2, l[i]);
			interr2 = min(interr2, r[i]);
		}
	}

	ll ans1, ans2;

	if(ans >= interl1 && ans <= interr1)
		ans1 = ans;
	else
		ans1 = -1;

	if(secans >= interl2 && secans <= interr2)
		ans2 = secans;
	else
		ans2 = -1;

	cout << ans << " " << interl1 << " " << interr1 << "\n";
	cout << secans << " " << interl2 << " " << interr2 << "\n";

	cout << max(ans1, ans2) << "\n";
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