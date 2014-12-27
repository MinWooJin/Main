#include <iostream>
using namespace std;

struct Order {
	int dest;
	int nPassenger;
	int profit;

	Order() {}
	Order(int _dest, int _nPassenger, int _profit) : dest(_dest), nPassenger(_nPassenger), profit(_profit) {}
};

struct TrainStatus {
	int pos;
	int order;

	int income;
	int nPassenger;
	int nPassengerDisembarkingAt[8];

	TrainStatus()
	{
		pos = 0;
		order = 0;
		income = 0;
		nPassenger = 0;
		for(int i=0; i<8; i++)
			nPassengerDisembarkingAt[i] = 0;
	}
};

int capacity;
int nLastCity;
int nOrder;

int nOrderFrom[7];
Order orderFrom[7][22];
int maxIncome;

void Backtracking(TrainStatus& trainStatus)
{
	int& curPos = trainStatus.pos;
	int& curOrder = trainStatus.order;

	if( curOrder == nOrderFrom[ curPos ] ) {
		
		TrainStatus newStatus(trainStatus);
		newStatus.pos++;
		newStatus.order = 0;

		if( newStatus.pos == nLastCity ) {
			if( newStatus.income > maxIncome )
				maxIncome = newStatus.income;
		}else {
			newStatus.nPassenger -= newStatus.nPassengerDisembarkingAt[newStatus.pos];
			Backtracking(newStatus);
		}

	}else {
		
		TrainStatus newStatus1(trainStatus), newStatus2(trainStatus);

		newStatus1.order++;
		Backtracking(newStatus1);

		if( newStatus2.nPassenger + orderFrom[curPos][curOrder].nPassenger <= capacity ) {
			newStatus2.nPassenger += orderFrom[curPos][curOrder].nPassenger;
			newStatus2.income += orderFrom[curPos][curOrder].profit;
			newStatus2.nPassengerDisembarkingAt[orderFrom[curPos][curOrder].dest] += orderFrom[curPos][curOrder].nPassenger;
			newStatus2.order++;
			Backtracking(newStatus2);
		}
		
	}
}

int main()
{
	while( true ) {
		
		cin>>capacity>>nLastCity>>nOrder;
		if( capacity == 0 )
			break;

		maxIncome = 0;
		for(int i=0; i<7; i++)
			nOrderFrom[i] = 0;

		for(int i=0; i<nOrder; i++) {
			int start, dest, nPassenger;
			cin>>start>>dest>>nPassenger;

			orderFrom[start][nOrderFrom[start]] = Order(dest, nPassenger, (dest-start)*nPassenger);
			nOrderFrom[start]++;
		}

		TrainStatus trainStatus;
		Backtracking(trainStatus);

		cout<<maxIncome<<endl;
	}

	return 0;
}