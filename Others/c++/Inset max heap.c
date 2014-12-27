#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENT 10 //최대 히프 크기 -1
#define HEAP_FULL(n) (n == MAX_ELEMENT-1) //히프 full을 정의 
#define HEAP_EMPTY(n) (!n) //히프가 비어있다는 조건 정의 

typedef struct {
    int key;
    //추가 하고 싶은 필드
}element;
element heap[MAX_ELEMENT]; //정의한 히프의 크기만큼 빈 히프 생성 
int n = 0; 

void push(element item, int *n) //push함수 구현, 따로 히프가 다 찼을때는 구현하지않음 
{
    int i;
    if (HEAP_FULL(*n)) {
        fprintf(stderr, "The heap is full.\n");
        exit(1);
    }
    i = ++(*n);
    while ((i != 1) && (item.key > heap[i/2].key)) {
        heap[i] = heap[i/2];
        i /= 2;
    }
    heap[i] = item;
}

void printheap(int n) //히프를 print하는 함수 구현. \n로 level을 구분한다. 
{
    int i, j = 2;
    if (n != 0) {
        printf("\n");
        for(i = 1; i <= n; i++) {
            printf("%d ", heap[i].key);
            if (i == (j-1)) {
                printf("\n");
                j = j*2;
            }
        }
        printf("\n");
    }
}

int main(int argc, char *argv[])
{
  int menu = 0; 
  element item;
  
  while (menu != 3) {
        printf("===Menu===\n");
        printf("1. 삽입\n");
        printf("2. 출력\n");
        printf("3. 프로그램 종료\n");
        scanf("%d", &menu);
        switch(menu) {
            case 1:
                printf("삽입할 원소값 입력: "); //삽입 메뉴, 한개의 원소를 삽입한다. 
                scanf("%d", &item.key);
                push(item, &n);
                printf("성공적으로 삽입 되었습니다.\n");
                break;
            case 2:
                printf("\nHeap를 출력합니다.\n"); //출력메뉴, 출력을 한다. 
                printheap(n);
                printf("\n");
                break;
            case 3:
                printf("\n프로그램 종료\n"); //프로그램 종료 메뉴 
                break;
            default :
                printf("\n다시 선택해 주세요.\n"); //메뉴 오류 처리 
                break;
        }
  }
  printf("성공적으로 종료 되었습니다.\n"); 
  system("PAUSE");	
  return 0;
}
