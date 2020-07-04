#include<iostream>
#include<string>
using namespace std;

class Stack
{
	int top;
	int*arr;
	int n;
	
	public:
		Stack(int size)
		{
			this->n = size;
			arr=new int[this->n];
			top=-1;
			for(int i=0;i<size;i++)
			{
				arr[i]=0;
			}
		}
		
		bool isEmpty()
		{
			if(top == -1)
				return true;
			else
				return false;
		}
		
		bool isFull()
		{
			if(top == n)
				return true;
			else
				return false;
		}
		
		void Push(int Val)
		{
			if(isFull()){
				cout<<"stack overflow"<<endl;}
			else{
				top++;
				arr[top] = Val;}
		}
		
		int Pop()
		{
			if(isEmpty()){
				cout<<"stack underflow"<<endl;
				return 0;}
			else{
				int PopValue = arr[top];
				arr[top] = 0;
				return PopValue;
				top--;}				
		}
		
		int Count()
		{
			return top+1;
		}
		
		int GetSpecific(int Pos)
		{
			if(isEmpty())
				cout<<"Stack is empty"<<endl;
			else
				return arr[Pos];
		}
		
		void change(int Pos, int Val)
		{
			arr[Pos] = Val;
			cout<<"new value at changed location is"<<arr[Pos]<<endl;
		}
		
		void display()
		{
			cout<<"Values in the stack are"<<endl;
			for(int i=n-1;i>=0;i--)
			{
				cout<<arr[i]<<endl;
			}
		}
};

int main()
{
	int n;
	cout<<"Enter the number of elements"<<endl;
	cin>>n;
	Stack S(n);
	int opt,pos,val;
	
	do
	{
		cout<<endl;
		cout<<"Select operation to be performed, enter 0 to exit the loop"<<endl;
		cout<<"1.Push"<<endl;
		cout<<"2.Pop"<<endl;
		cout<<"3.IsEmpty"<<endl;
		cout<<"4.IsFull"<<endl;
		cout<<"5.Peek"<<endl;
		cout<<"6.Count"<<endl;
		cout<<"7.Change"<<endl;
		cout<<"8.Display"<<endl;
		cout<<"9.Clear screen"<<endl<<endl;
	
		cin>>opt;
		switch(opt)
		{
			case 1:
				cout<<"Enter the value to be added to stack"<<endl;
				cin>>val;
				S.Push(val);
				break;
				
			case 2:
				cout<<"Popped value is: "<<S.Pop()<<endl;
				break;
				
			case 3:
				if(S.isEmpty())
					cout<<"stack is empty"<<endl;
				else
					cout<<"Stack is not empty"<<endl;
				break;
			
			case 4:
				if(S.isFull())
					cout<<"stack is full"<<endl;
				else
					cout<<"Stack is not full"<<endl;
				break;
		
			case 5:
				cout<<"Enter the position"<<endl;
				cin>>pos;
				cout<<S.GetSpecific(pos)<<endl;
				break;
				
			case 6:
				cout<<"No of entries in stack is"<<S.Count();
				break;
			
			case 7:
				cout<<"Enter the position and value"<<endl;
				cin>>pos>>val;
				S.change(pos,val);
				break;
			
			case 8:
				S.display();
				break;
				
			case 9:
				system("cls");
				break;
				
			default:
				cout<<"Select the valid option"<<endl;
		}
	}while(opt !=0);
	
	return 0;
}
