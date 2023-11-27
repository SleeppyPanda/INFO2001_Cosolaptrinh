#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct employee{
	char name[50];
	char employeecode[50];
	char position[50];
	long salary;
};
void print(struct employee emp){
	printf("ho va ten nhan vien: %s\n", emp.name);
	printf("ma so nhan vien: %s\n", emp.employeecode);
	printf("vi tri nhan vien: %s\n", emp.position);
	printf("luong cua nhan vien la: %ld\n", emp.salary);
}
void sortbyname(int n, struct employee emp[]) {
    int swapped;
    struct employee a;
    int i, j;
    for (i = 0; i < n; i++) {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (strcmp(emp[j].name , emp[j+1].name) >= 0){
                a = emp[j];
                emp[j]=emp[j+1];
                emp[j+1]=a;
                swapped = 1;
            }
        }
        if (swapped == 0) {
            break;
        }
    }
}
int main() {
	int n, i;
	printf("nhap vao so luong nhan vien: ");
	scanf("%d", &n);
	getchar();
	struct employee *emp = (struct employee*)malloc(n * sizeof(struct employee));
	for(i=0; i<n; i++){
		printf("nhan vien thu %d \n", i+1);
		printf("ho va ten nhan vien: ");
		fgets(emp[i].name,sizeof(emp[i].name), stdin);
		emp[i].name[strcspn(emp[i].name, "\n")] = '\0';
		printf("ma so nhan vien: ");
		fgets(emp[i].employeecode,sizeof(emp[i].employeecode), stdin);
		emp[i].employeecode[strcspn(emp[i].employeecode, "\n")] = '\0';
		printf("vi tri cua nhan vien: ");
		fgets(emp[i].position,sizeof(emp[i].position), stdin);
		emp[i].position[strcspn(emp[i].position, "\n")] = '\0';
		printf("luong cua nhan vien: ");
		scanf("%ld", &emp[i].salary);
		while(getchar() != '\n');
	}
	int c;
	do{
		printf("chon mot trong cac lenh sau\n	1 for print\n	2 for update\n	3 for sort\n	4 for end\n");
		scanf("%d", &c);
		if(c==1){
			for(i=0; i<n; i++){
				print(emp[i]);
			}
		}else if(c==2){
			int number;
			printf("chon mot trong cac lenh sau\n	1 for insert\n	2 for delete\n	3 for update\n ");
			scanf("%d", &number);
			if(number==1){
				int count;
				printf("nhap vao so nhan vien them vao: ");
				scanf("%d", &count);
				n=n+count;
				getchar();
				emp = (struct employee*)realloc(emp, n * sizeof(struct employee));
				for(i=n-count; i<n; i++){
					printf("nhan vien thu %d \n", i+1);
					printf("ho va ten nhan vien: ");
					fgets(emp[i].name,sizeof(emp[i].name), stdin);
					emp[i].name[strcspn(emp[i].name, "\n")] = '\0';
					printf("ma nhan vien: ");
					fgets(emp[i].employeecode,sizeof(emp[i].employeecode), stdin);
					emp[i].employeecode[strcspn(emp[i].employeecode, "\n")] = '\0';
					printf("vi tri cua nhan vien: ");
					fgets(emp[i].position,50, stdin);
					emp[i].position[strcspn(emp[i].position, "\n")] = '\0';
					printf("luong nhan vien: ");
					scanf("%ld", &emp[i].salary);
					while(getchar() != '\n');
				}
			}else if(number==2){
				int number;
				char empcode[50];
				printf(" nhap ma nhan vien phan ban muon xoa:");
				fgets(empcode, 50, stdin);
				empcode[strcspn(empcode, "\n")] = '\0';
				for(i=0; i<n; i++){
					if(strcmp(emp[i].employeecode, empcode)==0){
						int j;
						for (j=i; j<n-1; j++){
							emp[j]= emp[j+1];
						}
						n= n-1;
						break;
					}
				}
			}else if(number==3){
				int number;
				char empcode[50];
				printf(" nhap ma nhan vien phan ban muon cap nhat:");
				fgets(empcode, 50, stdin);
				empcode[strcspn(empcode, "\n")] = '\0';
				for(i=0; i<n; i++){
					if(strcmp(emp[i].employeecode, empcode)==0){
						printf("nhan vien thu %d \n", i+1);
						printf("ho va ten nhan vien: ");
						fgets(emp[i].name,50, stdin);
						printf("ma nhan vien: ");
						fgets(emp[i].employeecode,50, stdin);
						printf("vi tri cua nhan vien: ");
						fgets(emp[i].position,50, stdin);
						printf("luong cua nhan vien: ");
						scanf("%ld", &emp[i].salary);
					}
				}	
			}
		}else if(c==3){
			sortbyname(n,emp);
			for(i=0; i<n; i++){
				printf("nhan vien thu %d\n", i+1);
				print(emp[i]);
			}
		}
	}while(c!=4);
	free(emp);
	return 0;
}

