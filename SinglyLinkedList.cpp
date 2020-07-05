#include<iostream>
using namespace std;

class Node
{
	public:
		int k;     //key of the node
		int d;     //data of the node
		Node *N;
		
		Node()
		{
			k=0;
			d=0;
			N = NULL;
		}
		Node(int k,int d)
		{
			this->k = k;
			this->d = d;
		}
};

class SinglyLinkedList
{
	public:
		Node* H;     //head pointer
		
		SinglyLinkedList()
		{
			H = NULL;
		}
		
		SinglyLinkedList(Node *n)
		{
			H = n;
		}
		// 1. To check the existance of the node using key value
		Node* NodeExists(int key)     // we will check the existance of node using key
		{
			Node *temp = NULL;        //creating the temp pointer to store the return address of the existing node
			Node *ptr = H;            //now assigning the head pointer to the pointer variable
			if(ptr->k == key)
			{
				//if key is found then save this address to temp pointer
				temp = ptr;
			}
			else
				ptr = ptr->N; //is key is not matched, the we need to check next node.so the add of next node is stored in N which can be accessed with ptr
			return temp;
		}
		
		//2. Append using key value(Insert at the end of the list)
		void AppendNode(Node *n)
		{
			//we will firsr check the given node already exist or not using key
			if(NodeExists(n->k)!=NULL)  //now here we are passing the key value. this key value is accessible only using node type pointer.
			{
				cout<<"Node already exists"<<endl;
			}
			else
			{
				//here we will check whether the head pointer is null or not
				if(H == NULL)
				{
					H = n;
					cout<<"Node appended"<<endl;
				}
				else
				{
				//if head pointor is not null, then use other pointor variable to store that head pointor for trasversing the list.
					Node *ptr = H;
				//we will traverse the list untill the next add in node's is NULL.Once it is null,then we will assign the nwe node add to the next of last ptr
					while(ptr->N != NULL)
					{
						ptr = ptr->N;
					}
					ptr->N = n;
				}
			}
		}
		
		// 3.Prepend node (at the start of the list)
		
		void PrependNode(Node *n)
		{
			//we will firsr check the given node already exist or not using key
			if(NodeExists(n->k)!=NULL)  //now here we are passing the key value. this key value is accessible only using node type pointer.
			{
				cout<<"Node already exists"<<endl;
			}
			else
			{
				n->N = H;
				H=n;
				cout<<"Node prepended"<<endl;
			}
		}
		//4.Insert a node
		void InsertNode(int key, Node *n)
		{
			Node *ptr = NodeExists(key);
			if(ptr == NULL)
			{
				cout<<"No Node exist"<<endl;
			}
			else
			{
				//now before assignig add of new node to the previous node, we need to check if the key value of new node is unique.
				if(NodeExists(n->k)!=NULL)
				{
					cout<<"Node already exists"<<endl;
				}
				else
				{
					/*Node* temp = ptr->N;
					ptr->N = n;
					n->N = temp;*/
					n->N = ptr->N;   //we linked new node to next node.
					ptr->N = n;
				}
			}
			
		}
		
		//5.Delete the node
		void DeleteNode(int key)
		{
			if(H == NULL)
			{
				cout<<"Node does not exist"<<endl;
			}
			else if(H != NULL)
			{
				if(H->k == key)
				{
					H = H->N;
					cout<<"Code unlinked with key"<<endl;
				}
				else
				{
					Node* temp = NULL;
					Node* prevptr = H;
					Node* CurrentPtr = H->N;
					while(CurrentPtr != NULL)
					{
						if(CurrentPtr->k == key)
						{
							temp = CurrentPtr;
							CurrentPtr = NULL;
						}
						else
						{
							prevptr= prevptr->N;
							CurrentPtr = CurrentPtr->N;
						}
					}
					if(temp != NULL)
					{
						prevptr->N = CurrentPtr->N;
						cout<<"node is unlinked form the list"<<endl;
					}
					
				}
			}
			
		}
		//6. Updateing the node using key value
		void updateNodebyKey(int key, int data)
		{
			Node* ptr = NodeExists(key);
			if(ptr != NULL)
			{
				ptr->d =data;
				cout<<"Node data updates Successfuly"<<endl; 	
			}	
			else
			{
				cout<<"Node does not exist"<<endl;
			}
		}
		
		void display()
		{
			if(H == NULL)
			{
				cout<<" No nodes in this list"<<endl;
			}
			else
			{
				cout<<endl<<"Singly list values are";
				Node *temp = H;
				while(temp != NULL)
				{
					cout<<"("<<temp->k<<","<<temp->d<<")  --->";
					temp=temp->N;
				}
			}
		}
};


int main()
{
	SinglyLinkedList s;
	int option;
	int key1,k1,data1;
	do
	{
		cout<<"Select the option or 0 to exit"<<endl;
		cout<<"1.Append"<<endl;
		cout<<"2.Prepend"<<endl;
		cout<<"3.Insert node after specific"<<endl;
		cout<<"4.delete node after specific"<<endl;
		cout<<"5.Update node by key"<<endl;
		cout<<"6.Display node"<<endl;
		cout<<"7.Clear screeb"<<endl;
		
		cin>>option;
		Node* n1 = new Node();
		switch(option)
		{
			case 0:
				break;
			
			case 1:
				cout<<"enter key and data"<<endl;
				cin>>key1;
				cin>>data1;
				n1->d = data1;
				n1->k = key1;
				s.AppendNode(n1);
				break;
			
			case 2:
				cout<<"enter key and data"<<endl;
				cin>>key1;
				cin>>data1;
				n1->d = data1;
				n1->k =key1;
				s.PrependNode(n1);
				
			case 3:
				cout<<"enter the key after which we need to entere th node"<<endl;
				cin>>k1;
				cout<<"enter the key and data of the node to be entered"<<endl;
				cin>>key1;
				cin>>data1;
				n1->d = data1;
				n1->k = key1;
				s.InsertNode(k1,n1);
				break;
				
			case 4:
				cout<<"enter the key of node to be deleted"<<endl;
				cin>>k1;
				s.DeleteNode(k1);
				break;
				
			case 5:
				cout<<"enter the key and new data to be updated of the node"<<endl;
				cin>>key1;
				cin>>data1;
				n1->k = key1;
				n1->d = data1;
				s.updateNodebyKey(key1,data1);
				break;
			
			case 6:
				s.display();
				
			case 7:
				system("cls");
      			break;
				
			default:
				cout<<"Invalid entry"<<endl;
		}
			
	}while(option!=0);
	return 0;
}
