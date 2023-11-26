#include <stdio.h>
//only use uith sorted array
int search(int first, int last, int find, int d[]){
	if(first> last)
		return 0;
	else{
		int mid = (first + last)/2;
		if (d[mid]==find)
			return mid;
		else if(d[mid]>find)
			return search(first, mid-1, find, d);
		else
			return search(mid+1, last, find, d);
	}
}// khai báo hàm
int main(){
	//input
	int n, i, number;
	printf("nhap n: ");
	scanf("%d", &n);
	int arr[n];
	for(i=1; i<=n; i++){
		printf("nhap %d: ", i+1);
		scanf("%d", &arr[i]);
	}printf("nhap so can tim: ");
	scanf("%d", &number);
	//program
	int a = search(1, n, number, arr);
	//output
	if (a==0)
		printf("Khong co so can tim.");
	else
		printf("So can tim o vi tri: %d", a);
	return 0;
}
