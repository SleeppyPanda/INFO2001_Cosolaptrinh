#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// add struct here	
struct subjectpoint{
	int BIT2002;
	int BIT3003;
	int BIT3001;
};
struct birthday{
	int day;
	int month;
	int year;
};
struct student{
	int STT;
	char name[50];
	char classname[50];
	char stdcode[50];
	char gender[10];
	struct birthday std;
	struct subjectpoint sb;
};
void print(struct student stud[]){
	int a;
	printf("sinh vien thu %d\n", stud[a].STT);
	printf("ho va ten sinh vien: %s\n", stud[a].name);
	printf("lop cua sinh vien: %s\n", stud[a].classname);
	printf("ma so sinh cua sinh vien: %s\n", stud[a].stdcode);
	printf("gioi tinh cua sinh vien: %s\n", stud[a].gender);
	printf("ngay sinh cua sinh vien: %d/%d/%d\n", stud[a].std.day, stud[a].std.month, stud[a].std.year);
	printf("diem tung mon cho sinh vien:\n	diem mon co so lap trinh: %d\n	diem mon dai so tuyen tinh: %d\n	diem mon giai tich: %d\n\n", stud[a].sb.BIT2002, stud[a].sb.BIT3001, stud[a].sb.BIT3003);
}	
void sortbyname(int n, struct student stud[]) {
    int swapped;
    struct student a;
    int i, j;
    for (i = 1; i < n; i++) {
        swapped = 0;
        for (j = 0; j < n - i; j++) {
            if (strcmp(stud[j].name , stud[j+1].name) >= 0){
                a = stud[j];
                stud[j]=stud[j+1];
                stud[j+1]=a;
                swapped = 1;
            }
        }
        if (swapped == 0) {
            break;
        }
    }
}
void sortbypoint01(int n, struct student stud[]) {
    int swapped;
    struct student a;
    int i, j;
    for (i = 1; i < n; i++) {
        swapped = 0;
        for (j = 0; j < n - i; j++) {
            if (stud[j].sb.BIT2002 > stud[j+1].sb.BIT2002) {
                a = stud[j];
                stud[j]=stud[j+1];
                stud[j+1]=a;
                swapped = 1;
            }
        }
        if (swapped == 0) {
            break;
        }
    }
}
void sortbypoint02(int n, struct student stud[]) {
    int swapped;
    struct student a;
    int i, j;
    for (i = 1; i < n; i++) {
        swapped = 0;
        for (j = 0; j < n - i; j++) {
            if (stud[j].sb.BIT3001 > stud[j+1].sb.BIT3001) {
                a = stud[j];
                stud[j]=stud[j+1];
                stud[j+1]=a;
                swapped = 1;
            }
        }
        if (swapped == 0) {
            break;
        }
    }
}
void sortbypoint03(int n, struct student stud[]) {
    int swapped;
    struct student a;
    int i, j;
    for (i = 1; i < n; i++) {
        swapped = 0;
        for (j = 0; j < n - i; j++) {
            if (stud[j].sb.BIT3003 > stud[j+1].sb.BIT3003) {
                a = stud[j];
                stud[j]=stud[j+1];
                stud[j+1]=a;
                swapped = 1;
            }
        }
        if (swapped == 0) {
            break;
        }
    }
}
int main() {
	int a, i, s;
	//nhap vao bang thong tin sinh vien
	printf("nhap vao si so sinh vien: ");
	scanf("%d", &i);
	struct student stud[i]; // add struct
	// nhap thong tin can thiet
	printf("nhap day du cac thong tin sau:\n");
	for(a=0; a<i; a++){
		printf("sinh vien thu %d \n", a+1);
		stud[a].STT=a+1;
		printf("ho va ten sinh vien: ");
		getchar();
		fgets(stud[a].name,sizeof(stud[a].name), stdin);
		stud[a].name[strcspn(stud[a].name, "\n")] = '\0';
		while(getchar() != '\n');
		printf("lop cua sinh vien: ");
		fgets(stud[a].classname,sizeof(stud[a].classname), stdin);
		stud[a].classname[strcspn(stud[a].classname, "\n")] = '\0';
		while(getchar() != '\n');
		printf("gioi tinh cua sinh vien: ");
		fgets(stud[a].gender,sizeof(stud[a].gender), stdin);
		stud[a].gender[strcspn(stud[a].gender, "\n")] = '\0';
		while(getchar() != '\n');
		printf("ma so cua sinh vien: ");
		fgets(stud[a].stdcode,sizeof(stud[a].stdcode), stdin);
		stud[a].stdcode[strcspn(stud[a].stdcode, "\n")] = '\0';
		while(getchar() != '\n');
		printf("ngay sinh cua sinh vien: ");
		scanf("%d/%d/%d", &stud[a].std.day , &stud[a].std.month , &stud[a].std.year);		
		printf("diem tung mon cho sinh vien:\n");
		printf("diem mon co so lap trinh: ");
		scanf("%d", &stud[a].sb.BIT2002);
		printf("diem mon dai so tuyen tinh: ");
		scanf("%d", &stud[a].sb.BIT3001);
		printf("diem mon giai tich: ");
		scanf("%d", &stud[a].sb.BIT3003);
	}
	//su dung mot trong cac lenh sau de thuc hien
	do{
		printf("su dug mot trong cac lenh sau: \n	1 for print\n	2 for update\n	3 for search\n	4 for soft\n	5 for end\nChon lenh ban muon su dung: ");
 		//dung strcmp(1, 2) de so sanh chuoi
		scanf("%d", &s);
		if(s==1){
			for(a=0; a<i; a++){
				printf(&stud[a]);
			}
		}else if(s==2){
			int number, b;
			char studentcode[50];
			printf(" nhap ma sinh vien phan ban muon cap nhat:\n");
			getchar();
			fgets(studentcode, 50, stdin);
			studentcode[strcspn(studentcode, "\n")] = '\0';
			while(getchar() != '\n');
			for(a=0; a<i; a++){
				if(strcmp(stud[a].stdcode, studentcode)==0){
					print(&stud[a]);
					printf("sinh vien thu %d \n", a+1);
					stud[a].STT=a+1;
					printf("ho va ten sinh vien: ");
					getchar();
					fgets(stud[a].name,sizeof(stud[a].name), stdin);
					stud[a].name[strcspn(stud[a].name, "\n")] = '\0';
					while(getchar() != '\n');
					printf("lop cua sinh vien: ");
					fgets(stud[a].classname,sizeof(stud[a].classname), stdin);
					stud[a].classname[strcspn(stud[a].classname, "\n")] = '\0';
					while(getchar() != '\n');
					printf("gioi tinh cua sinh vien: ");
					fgets(stud[a].gender,sizeof(stud[a].gender), stdin);
					stud[a].gender[strcspn(stud[a].gender, "\n")] = '\0';
					while(getchar() != '\n');
					printf("ma so cua sinh vien: ");
					fgets(stud[a].stdcode,sizeof(stud[a].stdcode), stdin);
					stud[a].stdcode[strcspn(stud[a].stdcode, "\n")] = '\0';
					while(getchar() != '\n');
					printf("ngay sinh cua sinh vien: ");
					scanf("%d/%d/%d", &stud[a].std.day , &stud[a].std.month , &stud[a].std.year);		
					printf("diem tung mon cho sinh vien:\n");
					printf("diem mon co so lap trinh: ");
					scanf("%d", &stud[a].sb.BIT2002);
					printf("diem mon dai so tuyen tinh: ");
					scanf("%d", &stud[a].sb.BIT3001);
					printf("diem mon giai tich: ");
					scanf("%d", &stud[a].sb.BIT3003);
				}
			}//update+search done
		}else if(s==3){
			int search, number, number02, number03;
			char stdname[50];
			printf("nhap phan ban muon tim kiem: \n	1 for name\n	2 for student code\n");//search
			scanf("%d", &search);
			do{
				if(search==1){
					printf("nhap ten sinh vien ban muon tim: ");
					getchar();
					fgets(stdname, sizeof(stdname), stdin);
					stdname[strcspn(stdname, "\n")] = '\0';
					while(getchar() != '\n');
					for(a=0; a<i; a++){
						if(strcmp(stud[a].name, stdname)==0){
							print(&stud[a]);
						}
					}
				}else if(search==2){
					printf("nhap ma sinh vien ban muon tim: ");
					getchar();
					fgets(stdname, sizeof(stdname), stdin);
					stdname[strcspn(stdname, "\n")] = '\0';
					while(getchar() != '\n');
					for(a=0; a<i; a++){
						if(strcmp(stud[a].stdcode, stdname)==0){
							print(&stud[a]);
						}
					}
				}
			}while(search==1 || search==2);
				//print+search done
			}else if(s==4){
			int number;
			printf("chon cach sap xep\n	1 for following name\n	2 for following subject point\n");
			scanf("%d", &number);
			if(number==1){
				sortbyname(a,stud);
				for (a = 0; a < i; a++) {
        			print(&stud[a]);
   				}
			}else if(number==2){
				int number01;
				printf("chon mon muon sap xep\n	1 for co so lap trinh\n	2 for dai so tuyen tinh\n	3 for giai tich\n");
				scanf("%d", &number01);
				if(number01==1){
					sortbypoint01(a,stud) ;
					for ( a = 0; a < i; a++) {
        			print(&stud[a]);
   				}
				}else if(number01==2){
					sortbypoint02(a,stud); 
					for ( a = 0; a < i; a++) {
        				print(&stud[a]);
   					}
				}else if(number01==3){
					sortbypoint03(a,stud); 
					for ( a = 0; a < i; a++) {
        			print(&stud[a]);
   					}
   				}
			}
		}	//soft done
	}while(s!=5);
	return 0;
}
