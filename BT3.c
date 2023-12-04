#include<stdio.h>
#include<stdlib.h>
struct student{
	char hvt[50];
	int age;
	char sdt[20];
	char email[30];
};
struct student students[100];
void inputStudent(struct student *s) {
  printf("Enter name: ");
  scanf("%s",&s->hvt);
  printf("Enter age: ");
  scanf("%d",&s->age);
  printf("Enter phone: ");
  scanf("%s",&s->sdt);
  printf("Enter email: ");
  scanf("%s",&s->email);
}
void addStudent(struct student students[], int count) {
  inputStudent(&students[count]);
  (count)++;
}
void editStudent(struct student students[], int count, int index) {
  if (index < 0 || index >= count) {
    printf("Invalid index!\n");
    return;
  }
  inputStudent(&students[index]);
}
void deleteStudent(struct student students[], int count, int index) {
  if (index < 0 || index >= count) {
    printf("Invalid index!\n");
    return;
  }
  for (int i = index; i < count - 1; i++) {
    students[i] = students[i + 1];
  }
  (count)--;
}
void printStudents(struct student students[], int count) {
  for (int i = 0; i < count; i++) {
    printf("Student %d:\n", i + 1);
    printf("Name: %s\n", students[i].hvt);
    printf("Age: %d\n", students[i].age);
    printf("Phone: %s\n", students[i].sdt);
    printf("Email: %s\n", students[i].email);
  }
}

int main(){
	int count,index,student;
	do{
		printf("*************MENU**************\n");
		printf("1. Nhap thong tin cac sinh vien\n");
		printf("2. Them sinh vien\n");
		printf("3. Sua thong tin sinh vien\n");
		printf("4. Xoa thong tin sinh vien\n");
		printf("5. Thoat\n");
		printf("Chon chuc nang ban can:");
		int choice;
		scanf("%d",&choice);
		switch(choice){
			case 1:
				inputStudent(students);
				break;
			case 2:
				addStudent(students, count);
				printStudents(students, count);
				break;
			case 3:
				editStudent(students, count, index);
				printStudents(students, count);
				break;
			case 4:
				deleteStudent(students, count, index);
				printStudents(students, count);
				break;
			case 5:
				exit(0);
			default:
				printf("Gia tri khong hop le, vui longg chon gia tri tu 1-5\n");
		}
	}while(1==1);
}
