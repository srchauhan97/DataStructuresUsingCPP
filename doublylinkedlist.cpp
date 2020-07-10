#include<iostream>
using namespace std;

class node
{
	public:
		int key;
		int data;
		node *next;
		node *pre;
		
		node()
		{
			key = 0;
			data = 0;
			next = NULL;
			pre = NULL;
		}
		node(int k,int d)
		{
			key = k;
			data = d;
		}
};




class doublylinkedlist
{
	public:
		node* head;
		
		doublylinkedlist()
		{
			head = NULL;
		}
		//1.Check if the node exists or not.
		
		node* nodeExists(int k)
		{	
			node *temp = NULL;
			node *ptr = head;
			while(ptr != NULL)
			{
				if(ptr->key == k)
				{
					temp = ptr;
				}
				ptr= ptr->next;
			}
			return temp;
		}
		
		//2. Append the node(at the end)
		void append(node * n)
		{
			if(nodeExists(n->key) != NULL)
			{
				cout<<"Node already exists "<<endl;
			}
			else
			{
				if(head == NULL)
				{
					head = n;
					cout<<"node append done."<<endl;
				}
				else
				{
					node *ptr = head;
					if(ptr->next == NULL)
					{
						ptr->next == n;
						n->pre = ptr;
						cout<<"Node append done"<<endl;
					}
					else
					{
						ptr = ptr->next;
					}
				}
			}
		}
		
		//3.Prepend node(at the start of doubly linked list)
		
		void prepend(node *n)
		{
			if(nodeExists(n->key)!=NULL)
			{
				cout<<"Node already exists "<<endl;
			}
			else
			{
				if(head == NULL)
				{
					head = n;
					cout<<"node append done."<<endl;
				}
				else
				{
				n->next = head;
				head->pre = n;
				head=n;
				cout<<"Node prepend done"<<endl;
				}
			}
		}
		
		//4.Insert the node after the given node
		void insertNode(int k, node* n)
		{
			//here also we need to check whether the node exist or not.
			//nut here we will not use if condition as we need to get that node's address
			node* temp = nodeExists(k);
			if(temp == NULL)
			{
				cout<<"node does not exists "<<endl;
			}
			else
			{
				//here we need to check whether new node with that keyword already exist or not
				if(nodeExists(n->key)!=NULL)
				{
					cout<<"Node already exists with that key. "<<endl;
				}
				else
				{
					node* temp2 = temp->next;
					//inserting at the end
					if(temp2 == NULL)
					{
						temp->next = n;
						n->pre = temp;
						cout<<"node inserted between"<<endl;
					}
					else
					{
						n->next = temp ->  next;	
						temp2->pre = n;
						n->pre = temp;
						temp->next = n;
						cout<<"node inserted between"<<endl;
					}
				}
			}
		}
		
		void deleteNode( int key)
		{
			node* ptr = nodeExists(key);
			if(ptr == NULL)
			{
				cout<<"Node does not exists"<<endl;
			}
			else
			{
				if(head->key == key)
				{
					head = head->next;
					cout<<"node deleted from the list"<<endl;
				}
				else
				{
					node *nextnode = ptr->next;
					node *prenode = ptr->pre;
					
					if(nextnode == NULL)
					{
						nextnode->pre == NULL;
						cout<<"Node deleted at the end"<<endl;
					}
					else
					{
						prenode->next = nextnode;
						nextnode->pre = prenode;
						cout<<"Node deleted in between"<<endl;
					}
				}
			}
		}
		
		void updateNode(int k, int d)
		{
			node* ptr = nodeExists(k);
			if(ptr != NULL)
			{
				ptr->data = d;
				cout<<"Data updated"<<endl;
			}
			else
			{
				cout<<"Node does not exists"<<endl;
			}
		}
		
		void printNode()
		{
			if(head == NULL)
			{
				cout<<"Linked list is empty"<<endl;
			}
			else
			{
				cout<<"Doubly linked list values are"<<endl;
				node* temp = head;
				while(temp != NULL)
				{
				cout<<"("<<temp->key<<","<<temp->data<<")"<<endl;
				temp = temp->next;
				}
			}
		}
};

int main()
{
	doublylinkedlist obj;
	int option;
	int Key,Data,k;
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
		node *n1 = new node();
		switch(option)
		{
			case 0:
				break;
			
			case 1:
				cout<<"Enter key and data of node to be appended"<<endl;
				cin>>Key;
				cin>>Data;
				n1->key = Key;
				n1->data = Data;
				obj.append(n1);
				break; 
				
			case 2:
				cout<<"Enter the key and data of node to be prepended"<<endl;
				cin>>Key;
				cin>>Data;
				n1->key = Key;
				n1->data = Data;
				obj.prepend(n1);
				break;
			
			case 3:
				cout<<"enter the key after which node to be added"<<endl;
				cin>>k;
				cout<<"enter the key and data of the node to be appended"<<endl;
				cin>>Key;
				cin>>Data;
				n1->key = Key;
				n1->data=Data;
				obj.insertNode(k,n1);
				break;
				
			case 4:
				cout<<"Enter the key of the node to be deleted"<<endl;
				cin>>k;
				obj.deleteNode(k);
				break;
			
			case 5:
				cout<<"enter teh key and new data of the node to be udated"<<endl;
				cin>>Key;
				cin>>Data;
				obj.updateNode(Key, Data);
				break;
				
			case 6:
				obj.printNode();
				break;
				
			case 7:
				system("cls");
				break;
				
			default:
				cout<<"invalid entry"<<endl;	
				
		}
	}while(option != 0);
	
	return 0;
}
