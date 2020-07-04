#include<iostream>
#include<string>
using namespace std;

class Queue
{
	int F;
	int R;
	int arr[5];	
	public:
		Queue()
		{
			F=-1;
			R=-1;
			for(int i=0;i<5;i++)
			{
				arr[i]=0;
			}
		}
		
		bool isEmpty()
		{
			if(R==-1 && F==-1)
				return true;
			else
				return false;
		}
		
		bool isFull()
		{
			if(R == sizeof(arr)-1)
				return true;
			else
				return false;
		}
		void enqueue(int val)
		{	
			if(isFull())
				return;
			else if(isEmpty()){
				R=F=0;
				arr[R]=val;}
			else
			{
				R++;
				arr[R]=val;}	
		}
		int dequeue()
		{
			int x;
			if(isEmpty())
				return 0;
			else if( F == R)
			{
				x= arr[F];
				arr[F]=0;
				R=-1;
				F=-1;
			}
			else
			{
				x = arr[F];
				arr[F]=0;
				F++;
			}
			return x;
		}
		int count()
		{
			return(R-F+1);
		}
		
		void display()
		{
			for(int i=0;i<=4;i++)
			{
				cout<<arr[i]<<" ";
			}
		}
};

int main()
{
	//int n;
	//cout<<"Enter the number of elements"<<endl;
	//cin>>n;
	Queue Q;
	int opt,val;
	
	do
	{
		cout<<endl;
		cout<<"Select operation to be performed, enter 0 to exit the loop"<<endl;
		cout<<"1.Enqueue"<<endl;
		cout<<"2.Dequeue"<<endl;
		cout<<"3.IsEmpty"<<endl;
		cout<<"4.IsFull"<<endl;
		cout<<"5.Count"<<endl;
		cout<<"6.Display"<<endl;
		cout<<"7.Clear screen"<<endl;
	
		cin>>opt;
		switch(opt)
		{
			case 0:
				break;
			case 1:
				cout<<"Enter the value to be added to Queue"<<endl;
				cin>>val;
				Q.enqueue(val);
				break;
				
			case 2:
				cout<<"Popped value is:"<<Q.dequeue()<<endl;
				break;
				
			case 3:
				if(Q.isEmpty())
					cout<<"Queue is empty"<<endl;
				else
					cout<<"Queue is not empty"<<endl;
				break;
			
			case 4:
				if(Q.isFull())
					cout<<"Queue is full"<<endl;
				else
					cout<<"Queue is not full"<<endl;
				break;
		
			case 5:
				cout<<"Total elements in the Queue is"<<endl;
				break;
				
			case 6:
				Q.display();
				break;
			
			case 7:
				system("cls");
				break;
				
			default:
				cout<<"Select the valid option"<<endl;
		}
	}while(opt !=0);
	
	return 0;
}
