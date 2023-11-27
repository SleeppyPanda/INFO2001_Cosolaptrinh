#include <stdio.h>
//usewith any array
int main(){
	//input
	int n,e, search, a=0;
	printf("nhap vao so luong so hang: ");
	scanf("%d", &n);
	int arr[n];
	for(e=1; e<=n; e++){
		printf("nhap vao so thu %d: ", e);
		scanf("%d", &arr[e]);
	}printf("nhap so can tim: ");
	scanf("%d", &search);
	//program
	for(e=1; e<=n; e++){
		if (arr[e]==search){
			a=1;
			break;
		}
	}
	//output
	if (a==0)
		printf("Khong co so can tim.");
	else
		printf("So can tim o vi tri: %d", e);
	return 0;
}

