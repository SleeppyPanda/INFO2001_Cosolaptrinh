#include <stdio.h>
int main() {
	int n, i,sum=0;
	float average;
	printf("nhap vao so so hoc sinh trong lop: ");
	scanf("%d", &n);
	int arr[n];
	for(i=0; i<n; i++){
		printf("nhap vao diem cua hoc sinh thu %d: ", i+1);
		scanf("%d", &arr[i]);
		sum=sum+arr[i];
	}average=sum/n;
	printf("diem trung binh cua lop la %f", average);
	return 0;
}

