#include<stdio.h>
struct book {
  int id;
  char name[50];
  char author[50];
  int price;
  int quantity;
};
struct book books[100];

void input_books(int *n) {
  printf("Nhap so luong sach: ");
  scanf("%d", n);
  for (int i = 0; i < *n; i++) {
    printf("Nhap thong tin sach thu %d:\n", i + 1);
    printf("Nhap ma sach: ");
    scanf("%d", &books[i].id);
    printf("Nhap ten sach: ");
    scanf("%s", books[i].name);
    printf("Nhap tac gia: ");
    scanf("%s", books[i].author);
    printf("Nhap gia tien: ");
    scanf("%d", &books[i].price);
    printf("Nhap so luong: ");
    scanf("%d", &books[i].quantity);
  }
}

void display_books(int *n) {
  printf("Thong tin cac sach trong mang la:\n");
  for (int i = 0; i < n; i++) {
    printf("Thong tin sach thu %d:\n", i + 1);
    printf("Ma sach: %d\n", books[i].id);
    printf("Ten sach: %s\n", books[i].name);
    printf("Tac gia: %s\n", books[i].author);
    printf("Gia tien: %d\n", books[i].price);
    printf("So luong: %d\n", books[i].quantity);
  }
}

void add_book(int *n, int pos) {
  if (pos < 0 || pos > *n) {
    printf("Vi tri khong hop le!\n");
    return;
  }
  for (int i = *n; i > pos; i--) {
    books[i] = books[i - 1];
  }
  printf("Nhap thong tin sach can them:\n");
  printf("Nhap ma sach: ");
  scanf("%d", &books[pos].id);
  printf("Nhap ten sach: ");
  scanf("%s", books[pos].name);
  printf("Nhap tac gia: ");
  scanf("%s", books[pos].author);
  printf("Nhap gia tien: ");
  scanf("%d", &books[pos].price);
  printf("Nhap so luong: ");
  scanf("%d", &books[pos].quantity);
  (*n)++;
}

void delete_book(int *n, int id) {
  int index = -1;
  for (int i = 0; i < *n; i++) {
    if (books[i].id == id) {
      index = i;
      break;
    }
  }
  if (index == -1) {
    printf("Khong tim thay sach co ma %d!\n", id);
    return;
  }
  for (int i = index; i < *n - 1; i++) {
    books[i] = books[i + 1];
  }
  (*n)--;
}

void update_book(int n, int id) {
  int index = -1;
  for (int i = 0; i < n; i++) {
    if (books[i].id == id) {
      index = i;
      break;
    }
  }
  if (index == -1) {
    printf("Khong tim thay sach co ma %d!\n", id);
    return;
  }
  printf("Nhap thong tin moi cho sach co ma %d:\n", id);
  printf("Nhap ten sach: ");
  scanf("%s", books[index].name);
  printf("Nhap tac gia: ");
  scanf("%s", books[index].author);
  printf("Nhap gia tien: ");
  scanf("%d", &books[index].price);
  printf("Nhap so luong: ");
  scanf("%d", &books[index].quantity);
}

void sort_books(int n, int order) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (order == 1) {
        if (books[i].price > books[j].price) {
          struct book temp = books[i];
          books[i] = books[j];
          books[j] = temp;
        }
      }
      else if (order == 2) {
        if (books[i].price < books[j].price) {
          struct book temp = books[i];
          books[i] = books[j];
          books[j] = temp;
        }
      }
    }
  }
}

void search_book_by_name(int n, char name[]) {
  int found = 0;
  for (int i = 0; i < n; i++) {
    if (strcmp(books[i].name, name) == 0) {
      printf("Thong tin sach co ten %s:\n", name);
      printf("Ma sach: %d\n", books[i].id);
      printf("Tac gia: %s\n", books[i].author);
      printf("Gia tien: %d\n", books[i].price);
      printf("So luong: %d\n", books[i].quantity);
    }
  }
}
int main(){
	int pos,id,n,order,name;
    do{
	    printf("***************MENU****************\n");
	    printf("1. Nhap so luong va thong tin sach\n");
	    printf("2. Hien thi thong tin sach\n");
	    printf("3. Them sach vao vi tri\n");
	    printf("4. Xoa sach theo ma sach\n");
	    printf("5. Cap nhat thong tin theo ma sach\n");
	    printf("5. Sap xep sach theo gia sach(tang/giam)\n");
	    printf("6. Tim kiem sach theo ten sach\n");
	    printf("7. Tim kiem sach theo khoang gia\n");
	    printf("8. Thoat\n");
	    printf("Chon chuc nang ban muon:");
	    int choice;
	    scanf("%d",&choice);
	    switch(choice){
	    	case 1:
	    		input_books(&n);
	    		break;
	    	case 2:
				display_books(&n);
				break;
			case 3:
				add_book(&n, &pos);
				break;
			case 4:
				delete_book(&n, &id);
				break;
			case 5:
				sort_books(&n, &order);
				break;
			case 6:
				search_book_by_name(&n, &name);
				break;
			case 7:
				break;
			case 8:
				exit(0);
			default:
				printf("Gia tri khong hop le\n");
		}
    }while(1==1);
}
