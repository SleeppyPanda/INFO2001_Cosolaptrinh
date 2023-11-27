#include <stdio.h>
#include <time.h>
void swap(int *x, int *y) {
    int z = *x;
    *x = *y;
    *y = z;
}
void selectionsoft(int n, int a[]){
	
	int i, j;
	for( i = 1; i<n; i++)
    {
        int miniNext = i;
        for ( j = i+1; j<=n; j++)
        {
            if (a[j]<a[miniNext])
                miniNext = j;
        }
        swap(&a[i],&a[miniNext]);
    }
}
void bubblesort(int n, int a[]) {
    int swapped;
    int i, j;
    for (i = 1; i < n; i++) {
        swapped = 0;
        for (j = 1; j < n - i; j++) {
            if (a[j] > a[j + 1]) {
                swap(&a[j], &a[j + 1]);
                swapped = 1;
            }
        }
        if (swapped == 0) {
            break;
        }
    }
}

int main() {
    struct timespec start, end;
	double time_used;
    int n, i;
    printf("nhap vao so luong so hang: ");
    scanf("%d", &n);

    int a[n];
    for ( i = 1; i <= n; i++) {
        printf("nhap vao so hang thu %d: ", i);
        scanf("%d", &a[i]);
    }
    int number;
    do{
	printf("chon mot trong cac lenh sau:\n 1 for selectionsoft\n	2 for bubblesort\n	3 for end\n");
    	printf("lua chon cua ban: ");
    	scanf("%d", &number);
		if(number==1){
			clock_gettime(CLOCK_MONOTONIC, &start); 
			selectionsoft( n, a);
   	 		printf("\nChuoi da sap xep: ");
    		for ( i = 1; i <= n; i++) {
      			printf("%d ", a[i]);
    		}printf("\n");
   	 		clock_gettime(CLOCK_MONOTONIC, &end);
			time_used = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000.0;
  			printf("time used: %f second\n\n", time_used);
		}else if(number==2){
			clock_gettime(CLOCK_MONOTONIC, &start);  
			bubblesort(n, a);
    			printf("\nChuoi da sap xep: ");
    			for ( i = 1; i <= n; i++) {
        			printf("%d ", a[i]);
    			}printf("\n");
    			clock_gettime(CLOCK_MONOTONIC, &end);
			time_used = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000.0;
  			printf("time used: %f second\n\n", time_used);
  		}else if(number==3){
  			break;
		}else printf("lenh khong hop le. Hay chon lai lenh\n\n");
	}while (number!=3);
    return 0;
}
