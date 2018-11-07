#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

bool comp(int a, int b) 
{ 
    return (a < b); 
} 

void te(){
	ll n;
	cin >> n;
	ll a[n];

	for(ll i=0;i<n;i++)
		cin >> a[i];

	ll l = a[0], r = 400;
	for(ll i=0;i<n;i++)
		l = max(l, a[i]);
	ll votes_req = accumulate(a, a+n, 0);

	// cout << l << " " << votes_req << "\n";

	while(l < r){
		ll tot = 0;
		ll mid = (l + r) / 2;
		for(ll i=0;i<n;i++)
			tot += mid - a[i];

		if(tot > votes_req)
			r = mid;
		else
			l = mid + 1;
	}

	cout << l << "\n";
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	te();

	return 0;
}