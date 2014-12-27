#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int heapSize = 4;	// 초기 힙의 크기
int *heap;	

void insertHeap(int item, int *n);
void deleteHeap(int *n);
void makeTreeHeap(int n);
void printHeap(int n);
void heapFull();

void insertHeap(int item, int *n)
{	
	// 원소 item을 heap에 삽입, n은 현재 히프의 크기(원소 수)
	int i;
	// int temp;
	if ( *n == heapSize-1  ) heapFull(*n);
	*n = *n + 1;
	i = *n;
	heap[i] = item;
	/*
	heap[i] = item;
	if ( i == 1 ) heap[i] = item;
	else {
		for ( i = *n ; item < heap[i/2] ; i = i/2 ) {
			if ( item <= heap[i/2] ) break;
			else  {
			heap[i] = heap[i/2];
			}
		}
	}
	heap[i] = item;
	*/
}

void deleteHeap(int *n)
{
	heap[1] = heap[*n];
	*n = *n - 1;
	/*
	int temp, item, i, j;
	if ( *n == 0 ) printf("\nHeap is empty\n");
	else {
		item = heap[1];
		temp = heap[*n];
		*n = *n - 1;
		i = 1;	// root
		j = 2;	// j는 i의 왼쪽 자식노드
		while ( j <= *n ) {
			if ( j < *n ) {
				if ( heap[j] < heap[j+1] ) j = j + 1;
			}
			if ( temp >= heap[j] );
			heap[i] = heap[j];
			i = j;
			j = j * 2; // i와 j를 한 레벨 아래로 이동
		}
		heap[i] = temp;
	}
	*/
}

void makeTreeHeap(int n)
{
	int i, j, p, temp;
	for ( i = n/2 ; i >= 1 ; i-- ) {
		p = i;
		for ( j = 2*p ; j <= n ; j = 2*j ) {
			if ( j < n ) { 
				if ( heap[j] < heap[j+1] ) j++;
			}
			if ( heap[p] < heap[j] ) {
				temp = heap[p];
				heap[p] = heap[j];
				heap[j] = temp;
				p = j;
			}
		}
	}
}

void printHeap(int n)
{
	int i, j = 2;
	if ( n != 0 ) {
		printf("\n");
		for ( i = 1 ; i <= n ; i = i++ ) {
			printf("%d ", heap[i]);
			if ( i == (j-1) ) {
				printf("\n");
				j = j * 2;
			}
		}
		printf("\n");
	}
}

void heapFull(int n)
{
	int i;
	int *array;
	array = (int *)malloc(sizeof(int)*heapSize-1);
	for ( i = 1 ; i <= n ; i++ ) {
		array[i] = heap[i];
	}
	heapSize = heapSize * 2;
	heap = (int *)realloc(heap, (sizeof(int)*heapSize-1));
	for ( i = 1 ; i <= n ; i++ ) {
		heap[i] = array[i];
	}
}

void main()
{
	int menu = 0;
	int item;
	int n = 0; // 히프의 원소수 저장
	heap = (int*)malloc(sizeof(int)*heapSize-1);
	while (menu != 9) {
		printf("\n히프 연산\n\n");
		printf("1. 삽입\n");
		printf("2. 삭제\n");
		printf("9. 종료\n\n");
		printf("선택 : ");
		scanf("%d", &menu);
		switch(menu) {
		case 1 : 
			printf("\n삽입할 원소값 : ");
			scanf("%d", &item);
			insertHeap(item, &n);
			makeTreeHeap(n);
			printHeap(n);
			break;
		case 2 :
			deleteHeap(&n);
			makeTreeHeap(n);
			printHeap(n);
			break;
		case 9 :
			printf("\n프로그램 종료\n");
			break;
		default :
			printf("\n잘못 선택함\n");
			break;
		}
	}
	getch();
}
