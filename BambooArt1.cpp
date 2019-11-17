#include<bits/stdc++.h>
typedef long long ll;
    
using namespace std;
    
int main(){

    freopen("input.txt", "r", stdin);       //Comment
    freopen("output.txt", "w", stdout);     //this out
    ios::sync_with_stdio(false);
    cin.tie(NULL);                          //this.
    cout.tie(0);                            //or this.
    
    ll  N, x, i, B[100005] = {}, d, max = 0, ans, k;
    vector<ll> A;

    cin >> N;

    for(i = 0; i < N; i++){
        cin >> x;
        A.push_back(x);
        B[A[i]] = 1;
    }

    sort(A.begin(), A.end());

    ll c = 0;

    for(x = 0; x < N; x++){
        for(i = x + 1; i < N; i++){
            ans = 2;
            d = A[i] - A[x];
            k = d + A[i];
            while(k <= A[N-1]){
                if(x == 0 && i == 1)
                    c++;
                if(B[k] == 0)break;
                ans++;
                k += d;
            }
            if(max < ans)max = ans;

            // cout << x << ' ' << i << " " << c << "\n";
        }
    }

    cout << c << "\n";
    cout << max << endl;
    cout << endl;

    return 0;
}