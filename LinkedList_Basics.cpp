//Linked list programs
#include<iostream>
using namespace std;
struct node
{
	int info;
	node*link;
};
	node *start=NULL;
	void creation();
	void traversal();
	void insertAtBeg();
	void insertionAtEnd();
	void insertInSortedLL();
	void insertAfterGivenITem();
	void searching();
	void searchingInSorted();
	void delettAtBeg();
	void deleteAtEnd();
	void deleteGivenItem();
	void deleteFollowingNode();
int main()
{
	cout<<"press 1 for creation"<<endl;
	cout<<"press 2 for traversal"<<endl;
	cout<<"press 3 for insertioAtBeg"<<endl;
	cout<<"press 4 for insertioAtEnd"<<endl;
	cout<<"press 5 for Insertion in sorted LL"<<endl;
	cout<<"press 6 for Insertion after given item"<<endl;
	cout<<"press 7 for searching"<<endl;
	cout<<"press 8 for searching in sorted"<<endl;
	cout<<"press 9 for deletion at beg"<<endl;
	cout<<"press 10 for deletion at end"<<endl;
	cout<<"press 11 for delete given item"<<endl;
	cout<<"press 12 or deletion of a node which is following given node"<<endl;
	
	do
	{
	int choice ;
	cout<<"Enter choice     ";
	cin>>choice;
	switch(choice)
	{
		case 1: creation();break;
		case 2: traversal();break;
		case 3: insertAtBeg();break;
		case 4: insertionAtEnd();break;
		case 5: insertInSortedLL();break;
		case 6: insertAfterGivenITem();break;
		case 7: searching();break;
		case 8: searchingInSorted();break;
		case 9: delettAtBeg();break;
		case 10: deleteAtEnd();break;
		case 11: deleteGivenItem();break;
		case 12: deleteFollowingNode();break;
		default:cout<<"invalid choice"<<endl;
	}	} while(1);
}


	void creation()
	{
		if(start==NULL)
		{
		  node* newadd	=new node;
		  int item;
		  cout<<"enter the item    ";    //A->B->C->X
		  cin>>newadd->info;
		  // int item;  cin>>item;  newadd->info=item;    //syntax:info[newadd]   c++: newadd->info
		  newadd->link=NULL;
		  start=newadd;
		
		}
	
	}
	void traversal()
	{
		if(start==NULL)
		{
			cout<<"empty list cant be traversed";
			return;
		}
		node *ptr=start;
		while(ptr!=NULL)
		{
			cout<<ptr->info<<"-->";
			ptr=ptr->link;	
		}
		cout<< "NULL";
	}
	void insertAtBeg()
	{
		node *newadd=new node;
		int item;
		cout<<"enter item   ";
		cin>>newadd->info;
		newadd->link=start;
		start=newadd;
		
		
	}
	void insertionAtEnd()
	{
		node *ptr=start;
		while(ptr->link!=NULL)
		{
			ptr=ptr->link;   //A  B   C   D 
		}
		node *newadd=new node;
		cin>>newadd->info;
		newadd->link=NULL;
		ptr->link=newadd;
	}
	void insertInSortedLL()
	{
		int item;
		cout<<"enter item   ";
		cin>>item;
		node* newadd=new node;
		newadd->info=item;
		if(item<start->info)
		{
			newadd->link=start;
			start=newadd;
		}
		node*save=start,*ptr= start->link;
	
		while(ptr!=NULL)
		{
			if(item<ptr->info)
			{
				newadd->link=save->link;
				save->link=newadd;
				break;
			}
			else
			{
				save=ptr;
				ptr=ptr->link;
			}
		}
	}
	void insertAfterGivenITem()
	{
	int item;
	cout<<"enter iten after which you want to insert the new node    ";
	cin>>item;
     node *ptr=start,*loc;;
	 while(ptr!=NULL)
	 {
	 	if(item==ptr->info)
	 	{
	 		loc=ptr;
	 		break;
		 }
		 else
		 {
		 	ptr=ptr->link;
		 }
	}      
	
	node * newadd=new node;
	cout<<"enter item   ";
	cin>>newadd->info;    
	newadd->link=loc->link;
	loc->link=newadd;       
		
	}
	void searching()
	{
		int item;
		cout<<"enter the item to search    ";
		cin>>item;
		node* ptr=start;
		while(ptr!=NULL)
		{
			if(ptr->info==item)
			{
				cout<<"item found at   "<<ptr<<"  physical address"<<endl;
				break;
			}
			else
			{
				ptr=ptr->link;
			}
		}
		
	}
	void searchingInSorted()
	{
		int item;
		cout<<"enter item "<<endl;
		cin>>item;
		if(item<start->info)
		{
			cout<<"not present"<<endl; return;
		}
		node *ptr=start->link;
		while(ptr!=NULL)
		{
		if(item==ptr->info)
		{
			cout<<"found "<<endl;break;
		}
		else if(item<ptr->info)
		{
			cout<<"not found"<<endl;
		}
		else
		{
			ptr=ptr->link;
		}
	}}
	
	void delettAtBeg()
	{
		if(start==NULL)
		{
			cout<<"underflow";
			return;
		}
		int item=start->info;
		node* loc=start;
		start=start->link;
		delete loc;
	}
	void deleteAtEnd()    //A->B->C->D X
	{ 
	node* ptr=start,*save;
	while(ptr->link!=NULL)
	{
		save=ptr;
		ptr=ptr->link;
		
	}
	save->link=NULL;
	
	
	/* //OR
	node *ptr=start;
	while(ptr->link->link!=NULL)
	{
	ptr->link=NULL;	
	}
		 */		
	}
	void deleteGivenItem()
	{
		int item;
		cout<<"enter item"<<endl;
		cin>>item;
		node * ptr=start;
		node *locp,*loc;
		while(ptr!=NULL)
		{
			if(ptr->info==item)
			{
				loc=ptr;
				break;
			}
			else
			{
				locp=ptr;
				ptr=ptr->link;
			}
		}
		
		locp->link=loc->link;
		
	}
	void deleteFollowingNode()     //A-> B->c>
	{
		int item;
		cout<<"enter item";
		cin>>item;
		
		node*ptr=start,*locp,*loc;
		while(ptr!=NULL)
		{
			if(ptr->info==item)
			{
				locp=ptr;
				loc=ptr->link;
				break;
			}
			else
			{
				ptr=ptr->link;
			}
		}
		
		locp->link=loc->link;
		
		}
		
	
		
