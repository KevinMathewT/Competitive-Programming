#include<stdio.h>

int max(int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}

int main() {
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
  int n, p;
  int st, fi;
  int a[131072], bk[262144] = {
    0
  }, bas = 0, i;
  scanf("%d%d", & n, & p);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    bas = max(a[i], bas);
  }
  for (i = 0; i < n; i++) {
    bk[max(0, a[i] - bas + n)]++;
  }
  for (i = 1; i < 262144; i++) {
    bk[i] += bk[i - 1];
  }
  for (i = 0; i <= n + 1; i++) {
  	printf("%d ", bk[i]);
  }
  printf("\n");

  st = 1;
  for (i = 1; i <= n; i++) {
    while (bk[st + (i - 1)] < i) {
      st++;
    }
  }
  st += (bas - n);

  fi = n;
  for (i = 1; i <= n; i++) {
    while (fi > 0) {
      if (bk[fi + (i - 1)] - (i - 1) < p) {
        break;
      }
      fi--;
    }
  }
  fi += (bas - n);

  if (st > fi) {
    printf("0\n\n");
    return 0;
  }
  printf("%d\n", fi - st + 1);
  for (i = st; i <= fi; i++) {
    if (i != st) {
      printf(" ");
    }
    printf("%d", i);
  }
  printf("\n");
  return 0;
}