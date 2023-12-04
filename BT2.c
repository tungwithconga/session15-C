#include<stdio.h>

struct Student{
	char fullName[50];
	int age;
	char phone[20];
	char email[50];
};

void inputStudent(struct Student *s1){
	printf("Nhap ho va ten sinh vien:");
	gets(s1->fullName);
	
	printf("Nhap so tuoi:");
	scanf("%d",&s1->age);
	
	printf("Nhap sdt cua sinh vien:");
	scanf("%s",&s1->phone);
	
	printf("Nhap email:");
	scanf("%s",&s1->email);
}

void display(struct Student *s1){
	printf("\nThong tin sinh vien:\n");
	printf("Full name: %s\n",s1->fullName);
	printf("Age: %d\n",s1->age);
	printf("Phone: %s\n",s1->phone);
	printf("Email: %s\n",s1->email);
}

int main(){
	struct Student s1;
	inputStudent(&s1);
	display(&s1);
	return 0;
}


