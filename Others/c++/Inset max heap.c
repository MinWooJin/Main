#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENT 10 //�ִ� ���� ũ�� -1
#define HEAP_FULL(n) (n == MAX_ELEMENT-1) //���� full�� ���� 
#define HEAP_EMPTY(n) (!n) //������ ����ִٴ� ���� ���� 

typedef struct {
    int key;
    //�߰� �ϰ� ���� �ʵ�
}element;
element heap[MAX_ELEMENT]; //������ ������ ũ�⸸ŭ �� ���� ���� 
int n = 0; 

void push(element item, int *n) //push�Լ� ����, ���� ������ �� á������ ������������ 
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

void printheap(int n) //������ print�ϴ� �Լ� ����. \n�� level�� �����Ѵ�. 
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
        printf("1. ����\n");
        printf("2. ���\n");
        printf("3. ���α׷� ����\n");
        scanf("%d", &menu);
        switch(menu) {
            case 1:
                printf("������ ���Ұ� �Է�: "); //���� �޴�, �Ѱ��� ���Ҹ� �����Ѵ�. 
                scanf("%d", &item.key);
                push(item, &n);
                printf("���������� ���� �Ǿ����ϴ�.\n");
                break;
            case 2:
                printf("\nHeap�� ����մϴ�.\n"); //��¸޴�, ����� �Ѵ�. 
                printheap(n);
                printf("\n");
                break;
            case 3:
                printf("\n���α׷� ����\n"); //���α׷� ���� �޴� 
                break;
            default :
                printf("\n�ٽ� ������ �ּ���.\n"); //�޴� ���� ó�� 
                break;
        }
  }
  printf("���������� ���� �Ǿ����ϴ�.\n"); 
  system("PAUSE");	
  return 0;
}
