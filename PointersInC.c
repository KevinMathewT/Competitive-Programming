#include <stdio.h>

void x(int * p){
	printf("%d\n", *p);
    *p = -1;
	printf("%d\n", *p);
}

int main(){
	int a[] = {6, 6, 7, 8, 9, 10};
	int *b = &a; *b+=3; int i;
	for(i=0;i<sizeof(a)/sizeof(a[0]);i++) printf("%d ", a[i]); printf("\n");
	printf("%d %d %d ", (*b++), b, a[0]);
	printf("---------------------------------------------\n");

	int z = 4;
	printf("%d\n", z);
	x(&z);
	printf("%d\n", z);
}
