#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, p[60], freq[5], a[5];;

void te(){
	cin >> n;
	for(ll i=0;i<n;i++)
		cin >> p[i];
	for(ll i=0;i<5;i++){
		cin >> a[i];
		freq[i] = 0;
	}

	ll final_ans = 0;

	for(ll i=0;i<n;i++){
		p[i] += final_ans;
		ll flag = 0;
		while(p[i] != 0){
			if(p[i] < a[0]){
			// cout << p[i] << "\n";
				flag = 1;
				final_ans = p[i];
				p[i] = 0;
				continue;
			}
			if(p[i] >= a[4]){
				freq[4] += p[i] / a[4];
				p[i] -= ((ll)(p[i] / a[4])) * a[4];
			}
			if(p[i] >= a[3]){
				freq[3] += p[i] / a[3];
				p[i] -= ((ll)(p[i] / a[3])) * a[3];
			}
			if(p[i] >= a[2]){
				freq[2] += p[i] / a[2];
				p[i] -= ((ll)(p[i] / a[2])) * a[2];
			}
			if(p[i] >= a[1]){
				freq[1] += p[i] / a[1];
				p[i] -= ((ll)(p[i] / a[1])) * a[1];
			}
			if(p[i] >= a[0]){
				freq[0] += p[i] / a[0];
				p[i] -= ((ll)(p[i] / a[0])) * a[0];
			}
		}

		if(flag == 0)
			final_ans = 0;
	}

	for(ll i=0;i<5;i++)
		cout << freq[i] << " ";
	cout << "\n" << final_ans << "\n";
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