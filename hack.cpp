#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct{
    int arr[MAX];
    int top;
}Stack;
void initStack(Stack *stack) {
    stack->top=-1;
}
bool isEmpty(Stack *stack) {
    return stack->top==-1;
}
bool isFull(Stack *stack){
	return stack->top==MAX-1;
}
void pushStack(Stack *stack,int value){
	if (isFull(stack)){
        printf("Ngan xep da day!\n");
        return;
    }
    stack->arr[++stack->top]=value;
    printf("Da them vao ngan xep!\n");
}
int popStack(Stack *stack) {
    if (isEmpty(stack)) {
       printf("Ngan xep rong khong the lay phan tu!\n");
        return -1;
    } 
    return stack->arr[stack->top--];
}
int peekStack(Stack *stack) {
    if (isEmpty(stack)) {
        return -1;
    }
    return stack->arr[stack->top];
}
int sizeStack(Stack *stack) {
    return stack->top+1;
}
void printStack(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Ngan xep rong!\n");
    } else {
        printf("Các phan tu trong ngan xep: ");
        for (int i = 0; i <= stack->top; i++) {
            printf("%d ", stack->arr[i]);
        }
        printf("\n");
    }
}
void reverseStack(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Ngan xep rong!\n");
    } else {
        printf("Cac phan tu trong ngan xep theo thu tu dao nguoc la: ");
        for (int i = stack->top;i >= 0;i--) {
            printf("%d ",stack->arr[i]);
        }
        printf("\n");
    }
}
void clearStack(Stack *stack){
	for (int i = 0; i <= stack->top; i++) {
        stack->arr[i]=0;
    }
    stack->top=-1;
}
int main() {
    Stack stack;
    initStack(&stack);
    int choice, value;
    do{
        printf("==================MENU=================\n");
        printf("1.Them phan tu vao ngan xep\n");
        printf("2.Lay phan tu ra khoi ngan xep(pop)\n");
	    printf("3.Kiem tra phan tu tren cung cua ngan xep (peek/top)\n");
	    printf("4.Kiem tra ngan xep co rong khong (isEmpty)\n");
	    printf("5.Lay kich thuoc ngan xep (size)\n");
	    printf("6.In toan bo ngan xep(display)\n");
	    printf("7. Xoa toan bo ngan xep (clear)\n");
	    printf("8.In cac phan tu theo thu tu nguoc lai (reverse)\n");
	    printf("0. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Nhap gia tri can them: ");
                scanf("%d", &value);
                pushStack(&stack,value);
                break;
            case 2:
                printf("phan tu duoc lay ra tu Stack la %d\n",popStack(&stack));
                break;
            case 3:
                value=peekStack(&stack);
                if (value !=-1){
                    printf("Phan tu tren cung cua ngan xep là: %d\n",value);
                }else{
                	printf("Ngan xep rong \n");
				}
                break;
            case 4:
                if(isEmpty(&stack)){
                	printf("Ngan xep rong\n");
				}else{
					printf("Ngan xep da co phan tu\n");
				}
                break;
            case 5:
                printf("Kich thuoc ngan xep: %d\n", sizeStack(&stack));
                break;
            case 6:
                printStack(&stack);
                break;
            case 7:
                clearStack(&stack);
                printf("Ngan xep da duoc xoa toan bo\n");
                break;
            case 8:
                reverseStack(&stack);
                break;
            case 0:
                printf("Thoat chuong trinh.\n");
                return 0;
            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (choice != 0);
    return 0;
}

