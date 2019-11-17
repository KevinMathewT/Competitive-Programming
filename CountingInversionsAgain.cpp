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

ll n, a[1000010], b[1000010], q;

ll merge(ll arr[], ll temp[], ll left, ll mid, ll right) {
   ll i, j, k;
   ll count = 0;
   
   i = left;
   j = mid;
   k = left;

   while ((i <= mid - 1) && (j <= right)) {
      if (arr[i] <= arr[j]) { 
         temp[k++] = arr[i++];
      }else{
         temp[k++] = arr[j++];
         count += (mid - i);
      }
   }

    while (i <= mid - 1)
       temp[k++] = arr[i++];

    while (j <= right)
       temp[k++] = arr[j++];
   
    for (i=left; i <= right; i++)
       arr[i] = temp[i];
    return count;
}

ll mergeSort(ll arr[], ll temp[], ll left, ll right) {
   ll mid, count = 0;

   if (right > left) {
      mid = (right + left)/2;
      count  = mergeSort(arr, temp, left, mid);
      count += mergeSort(arr, temp, mid+1, right);
      count += merge(arr, temp, left, mid+1, right);
   }
   return count;
}

ll arrInversion(ll arr[], ll n) {
   ll temp[n];
   return mergeSort(arr, temp, 0, n - 1);
}

void solve(){
	cin >> n >> q;
	for(ll i=0;i<n;i++)
		cin >> a[i];
	while(q--){
		ll bx;
		cin >> bx;
		for(ll i=0;i<n;i++)
			b[i] = a[i] ^ bx;

		cout << arrInversion(b, n) << "\n";
	}
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
		solve();

	return 0;
}