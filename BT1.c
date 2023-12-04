#include<stdio.h>
#include<string.h>
struct Student{
	char name[50];
	int age;
	char phone[15];
	char address[50];
};
int main(){
	struct Student sv1;
	strcpy(sv1.name, "Lo Van Duc");
	sv1.age=26;
	strcpy(sv1.address, "Dinh Thon, Dong Da, Ha Noi");
	strcpy(sv1.phone, "0720233324");
	printf("Ten: %s\n",sv1.name);
	printf("Tuoi: %d\n",sv1.age);
	printf("Sdt: %s\n",sv1.phone);
	printf("Dia Chi: %s\n",sv1.address);
}
