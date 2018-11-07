#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll arr[(ll)1e5 + 100];

void te(){
	memset(arr, 1e5 + 100, 0);
	string s;
	cin >> s;
	ll x, y, a, b;
	cin >> x >> y >> a >> b;

	if(x > y){
		ll temp = x;
		x = y;
		y = temp;
		temp = a;
		a = b;
		b = temp;
	}

	map<ll, ll> m;

	for(ll i=0;i<s.length();i++)
		m[s[i]-'0'] = m[s[i]-'0'] + 1;

	if(m[x] != (a + b) || m[y] !=00 a + b){
		cout << -1 << "\n";
		return;
	}

	for(ll i=0;i<s.length();i++)
		arr[i] = s[i] - '0';

	sort(arr, arr+s.length());

	ll flag = 0, flag2 = 0;
	for(ll i=0;i<s.length();i++){
		if(arr[i] == x && flag == 0){
			flag = 1;
			for(ll j=0;j<m[x]-(a+b);j++)
				cout << x;
			for(ll j=0;j<a;j++)
				cout << x << y;
		}
		else if(arr[i] == x && flag == 1)
			continue;
		else if(arr[i] == y && flag2 == 0){
			flag2 = 1;
			for(ll j=0;j<b;j++)
				cout << y << x;
			for(ll j=0;j<m[y]-(a+b);j++)
				cout << y;
		}
		else if(arr[i] == y && flag2 == 1){
			continue;
		}
		else
			cout << arr[i];
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

	ll T;
	cin >> T;
	while(T--)
		te();

	return 0;
}