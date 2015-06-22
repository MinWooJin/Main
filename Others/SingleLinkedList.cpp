#include <iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node *tail;
};

class STT
{
	public:
		Node* Head;
		Node* tempPoint;
		
		STT()
		{
			Head = NULL;
		}
		
		void Create(int data)
		{
			Node* temp = new Node();
			
			temp->data = data;
			temp->tail = Head;
			
			Head = temp;
		}
		
		void PrintAll()
		{
			tempPoint = Head;
			
			while(tempPoint->tail != NULL)
			{
				cout << tempPoint->data << " -> ";
				tempPoint = tempPoint->tail;
			}
			cout << tempPoint->data << endl;
		}
};

int main()
{
	STT *st = new STT();
	
	for(int i=0; i<10; i++)
		st->Create(i);
	st->PrintAll();
	
	return 0;
}
