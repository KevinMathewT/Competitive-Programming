#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

void te(){
	ll n;
	cin >> n;
	ll a[n];
	vector<ll> start, end;
	
	for(ll i=0;i<n;i++)
		cin >> a[i];

	if(a[0] != -1)
		start.push_back(0);
	for(ll i=1;i<n;i++)
		if(a[i] != -1 && a[i-1] == -1)
			start.push_back(i);

	for(ll i=0;i<n-1;i++)
		if(a[i] != -1 && a[i+1] == -1)
			end.push_back(i);
	if(a[n-1] != -1)
		end.push_back(n-1);

	ll decflag = 0;

	if(end[end.size()-1] != )
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