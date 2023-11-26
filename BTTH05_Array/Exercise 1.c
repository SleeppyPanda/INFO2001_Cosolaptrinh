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
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int a[n];
    for (int i = 1; i <= n; i++) {
        printf("Enter element %d: ", i);
        scanf("%d", &a[i]);
    }
    int number;
    do{
		printf("choose 1 for selectionsoft\nchoose 2 for bubblesort\nchoose 3 for end\n");
    	printf("Enter your choose: ");
    	scanf("%d", &number);
		if(number==1){
			clock_gettime(CLOCK_MONOTONIC, &start); 
			selectionsoft( n, a);
   	 		printf("\nSorted array: ");
    		for (int i = 1; i <= n; i++) {
      			printf("%d ", a[i]);
    		}printf("\n");
   	 		clock_gettime(CLOCK_MONOTONIC, &end);
			time_used = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000.0;
  			printf("time used: %f second\n\n", time_used);
		}else if(number==2){
			clock_gettime(CLOCK_MONOTONIC, &start);  
			bubblesort(n, a);
    		printf("\nSorted array: ");
    		for (int i = 1; i <= n; i++) {
        		printf("%d ", a[i]);
    		}printf("\n");
    		clock_gettime(CLOCK_MONOTONIC, &end);
			time_used = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000.0;
  			printf("time used: %f second\n\n", time_used);
  		}else if(number==3){
  			break;
		}else printf("please re-choose option\n\n");
	}while (number!=3);
    return 0;
}
