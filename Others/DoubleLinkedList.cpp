#include <iostream>
using namespace std;

class Node
{
	public:
		Node* Next;
		int data;
		Node* Prev;
};

class STT
{
	public:
		Node* Head;
		Node* tempPoint;
		
		STT()
		{
			Head = new Node();
			Head->Next = NULL;
			Head->Prev = NULL;
		}
		
		void Create(int data)
		{
			Node* temp = new Node();
			
			Head->Prev = temp;
			
			temp->data = data;
			temp->Next = Head;
			
			Head = temp;
		
			
		}
		
		void printAll()
		{
			tempPoint = Head;
			
			while(tempPoint->Next != NULL && tempPoint->Next->data != 0)
			{
				cout << tempPoint->data << " -> ";
				tempPoint = tempPoint->Next;
			}
			cout << tempPoint->data << endl;
		}
};

int main()
{
	STT *st = new STT();
	
	st->Create(5);
	st->Create(3);
	st->Create(1);
	st->Create(8);
	st->Create(9);
	
	st->printAll();
	return 0;
}
