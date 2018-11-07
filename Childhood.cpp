#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra


// Merge Sort code taken from GeeksForGeeks

ll  _mergeSort(ll arr[], ll temp[], ll left, ll right); 
ll merge(ll arr[], ll temp[], ll left, ll mid, ll right); 
  
/* This function sorts the input array and returns the 
   number of inversions in the array */
ll mergeSort(ll arr[], ll array_size) 
{ 
    ll *temp = (ll *)malloc(sizeof(ll)*array_size); 
    return _mergeSort(arr, temp, 0, array_size - 1); 
} 
  
/* An auxiliary recursive function that sorts the input array and 
  returns the number of inversions in the array. */
ll _mergeSort(ll arr[], ll temp[], ll left, ll right) 
{ 
  ll mid, inv_count = 0; 
  if (right > left) 
  { 
    /* Divide the array llo two parts and call _mergeSortAndCountInv() 
       for each of the parts */
    mid = (right + left)/2; 
  
    /* Inversion count will be sum of inversions in left-part, right-part 
      and number of inversions in merging */
    inv_count  = _mergeSort(arr, temp, left, mid); 
    inv_count += _mergeSort(arr, temp, mid+1, right); 
  
    /*Merge the two parts*/
    inv_count += merge(arr, temp, left, mid+1, right); 
  } 
  return inv_count; 
} 
  
/* This funt merges two sorted arrays and returns inversion count in 
   the arrays.*/
ll merge(ll arr[], ll temp[], ll left, ll mid, ll right) 
{ 
  ll i, j, k; 
  ll inv_count = 0; 
  
  i = left; /* i is index for left subarray*/
  j = mid;  /* j is index for right subarray*/
  k = left; /* k is index for resultant merged subarray*/
  while ((i <= mid - 1) && (j <= right)) 
  { 
    if (arr[i] <= arr[j]) 
    { 
      temp[k++] = arr[i++]; 
    } 
    else
    { 
      temp[k++] = arr[j++]; 
  
     /*this is tricky -- see above explanation/diagram for merge()*/
      inv_count = inv_count + (mid - i); 
    } 
  } 
  
  /* Copy the remaining elements of left subarray 
   (if there are any) to temp*/
  while (i <= mid - 1) 
    temp[k++] = arr[i++]; 
  
  /* Copy the remaining elements of right subarray 
   (if there are any) to temp*/
  while (j <= right) 
    temp[k++] = arr[j++]; 
  
  /*Copy back the merged elements to original array*/
  for (i=left; i <= right; i++) 
    arr[i] = temp[i]; 
  
  return inv_count; 
} 
  
/* Driver program to test above functions */
int main() 
{ 
  freopen("input.txt", "r", stdin);   //Comment
  freopen("output.txt", "w", stdout);   //this out.
  ios::sync_with_stdio(false);      //Not
  cin.tie(NULL);              //this.
  cout.tie(0);

  ll T;
  cin >> T;
  while(T--){
    ll s;
    cin >> s;
    ll a[s], b[s], arr[s];
    for(ll i=0;i<s;i++)
      cin >> a[i];

    for(ll i=0;i<s;i++)
      cin >> b[i];

    map<ll, ll> m;
    for(ll i=0;i<s;i++)
      m[a[i]] = i+1;
    for(ll i=0;i<s;i++)
      b[i] = m[b[i]];
    cout << mergeSort(b, s) * 2 << "\n";
  }

  return 0; 
} 