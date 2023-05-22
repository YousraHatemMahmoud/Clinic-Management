/* clinic management system*/

#include <stdio.h>
#include <stdlib.h>
#include "STD_types.h"
#include <string.h>
#include "file.h"

/*Struct for Patient Data*/

typedef struct node_type node;

struct node_type
{
	u16 ID;
	u8 Gender;
	u16 Age;
	f32 Slots;
	u8* Name;
	node* Next;
};

/*Functions prototype*/

void Add_patient(node* Head,u8* name,u8 Gender,u16 age,u16 id);
u16 search_ID (node* Head,u16 id);
void Edit_data(node* Head,u8* name,u8 gender,u16 age,u16 id);
void show_available(node1* head1);
void reserv(node* Head,f32 slot,u16 id);
void Delete_Slot(node1** head1,f32 slot);
void Add_Slot(node1* head1,f32 slot);
void cancel_reserv(node* Head,u16 id);
void show_reservation(node* Head);
void show_record(node* Head,u16 id);

/*global variable to check if the linked list is empty*/
u16 first_element = 0;

int main(void)
{
	
	/*creat Head for patient struct*/
	node* Head = (node*) malloc(sizeof(node));
	Head->Next = NULL;
	
	/*create linked list for slots*/
	node1* first = (node1*) malloc(sizeof(node1));
	first->time = 2;
	head1 = first;
	
	node1* second = (node1*) malloc(sizeof(node1));
	second->time = 2.5;
	
	node1* third = (node1*) malloc(sizeof(node1));
	third->time = 3;
	
	node1* fourth = (node1*) malloc(sizeof(node1));
	fourth->time = 4;
	
	node1* fifth = (node1*) malloc(sizeof(node1));
	fifth->time = 4.5;
	
	first->tail = second;
	second->tail = third;
	third->tail = fourth;
	fourth->tail = fifth;
	fifth->tail = NULL;
	
	u16 mode=0;
	
	while(1)
	{
		printf("////////////////////////////////// \n");
		printf("//////////////Hello//////////////  \n");
		
		/*choose Mode*/
		printf("Please Enter 1 for Admin mode or 2 for User mode: ");
		scanf("%d",&mode);
		
		if (mode == 1)
		{
			/*Admin mode*/
			u16 i,choise;
			u16 pass;
			printf("Please Enter the password: ");
			scanf("%d",&pass);
			
			/*check password*/
			while(pass != 1234 && i < 2)
			{
				printf("Incorrect password please try again: ");
				scanf("%d",&pass);
				i++;
			}
			if (i == 2)
			{
				/*if password is incorrect*/
				/*close the programm*/
				printf("Thank you \n");
				break;
			}
			else
			{
				/*correct password*/
			    /*Admin Features*/
				printf("Please Enter \n 1 to Add new patient record\n 2 to Edit patient record\n 3 to Reserve a slot with the doctor\n 4 to Cancel reservation \n");
				printf("Your choise: ");
				scanf("%d",&choise);
				
				switch(choise)
				{
					case 1:
					{
						/*Add patient record*/
						u8 name[100];
						u8 gender;
						u16 age,id,x=0;
						
						printf("Enter the patient ID: ");
						scanf("%d",&id);
						
						printf("Enter the patient age: ");
						scanf("%d",&age);
						
						printf("Enter the 'F' for female or 'M' for Male: ");
						scanf(" %c",&gender);
						
						printf("Enter the patient name: ");
						fflush(stdin);
						gets(name);
						
						
						/*search if the ID isn't unique*/
						do
						{
							x = search_ID (Head,id);
							if (x == 1)
							{
								printf("please Enter unique ID: ");
								scanf("%d",&id);
							}
						}while(x != 0);
						
						/*first patient in the list*/
						if (first_element == 0)
						{
							Head->Name = name;
							Head->Gender = gender;
							Head->Age = age;
							Head->ID = id;
							
							first_element = 1;
						}
						
						/*if the list isn't empty*/
						else
						{
							Add_patient(Head,name,gender,age,id);
						}
						printf("Information Added thank you \n");
						break;
					}
					
					case 2:
					{
						/*Edit patient record*/
						u8 name[100];
						u8 gender;
						u16 age;
						u16 id,x=0;
						printf("Enter user ID: ");
						scanf("%d",&id);
						
						/*search if the ID is exist*/
						x = search_ID(Head,id);
						
						if (x == 1)
						{
							/*Edit data*/
							printf("Enter the new data \n");
                            
							Edit_data(Head,name,gender,age,id);
							printf("The data has been modified \n");
							
							printf("Enter the patient age: ");
							scanf("%d",&age);
							
							printf("Enter the F for female or M for Male: ");
							scanf(" %c",&gender);
							
                            printf("Enter the patient name: ");
							fflush(stdin);
							gets(name);
								
						}
                        
						else
						{
							printf("Incorrect ID \n");
						}
						break;
					}
					
					case 3:
					{
						/*Reserve a slot with the doctor*/
						u16 id,x=0;
						f32 slot;
						printf("Enter the ID: ");
						scanf("%d",&id);
						x = search_ID (Head,id);
						
						if (x == 1)
						{
							show_available(head1);
							printf("Enter your Slot: ");
							scanf("%f",&slot);
							reserv(Head,slot,id);
							printf("the slot is reserved \n");
							Delete_Slot(&head1,slot);
						}
						else
						{
							printf("Incorrect ID \n");
						}
						
						break;
					}
					
					case 4:
					{
						/*Cancel reservation*/
						u16 id;
						printf("enter the ID to cancel its reservation: ");
						scanf("%d",&id);
						cancel_reserv(Head, id);
						printf("the reservation is cancel \n");
						
						break;
					}
				}
			}
			
		}
		
		else if (mode == 2)
		{
			/*User Mode*/
			u16 choise;
			printf("Please Enter \n 1 to View patient record\n 2 to View today reservations\n");
			printf("Your choise: ");
			scanf("%d",&choise);
			
			/*user Features*/
			switch(choise)
			{
				case 1:
				{
					/*View patient record*/
					u16 id,x=0;
					printf("Please Enter the ID: ");
					scanf("%d",&id);
					x = search_ID(Head,id);
					if (x == 1)
					{
						show_record(Head,id);
					}
					else
					{
						printf("Incorrect ID \n");
					}
					break;
				}
				
				case 2:
				{
					/*View today reservations*/
					show_reservation(Head);
					break;
				}
			}
		}
		
		/*wrong choise for mode*/
		else
		{
			printf("Opps! Wrong Number \n");
		}
	}
	
	
	return 0;
}


void Add_patient(node* Head,u8* name,u8 gender,u16 age,u16 id)
{
	node* ptr = Head;
	
	/*create new node*/
	node* new = (node*) malloc(sizeof(node));
	
	/*assign it's data*/
	new->Name = name;
	new->Gender = gender;
	new->Age = age;
	new->ID = id;
	new->Next = NULL;
	
	while(ptr->Next != NULL)
	{
		ptr = ptr->Next;
	}
	ptr->Next = new;
	
}

u16 search_ID (node* Head,u16 id)
{
	u8 x=0;
	node* ptr = Head;
	
	while(ptr != NULL)
	{
		if (ptr->ID == id )
		{
			/*ID Found*/
			x=1;
		}
		
		ptr = ptr->Next;
	}
	
	return x;
	
	
}

void Edit_data(node* Head,u8* name,u8 gender,u16 age,u16 id)
{
	node* ptr = Head;
	
	while(ptr->ID != id)
	{
		ptr = ptr->Next;
	}
	
	/*Assign new data*/
	ptr->Name = name;
	ptr->Gender = gender;
	ptr->Age = age;
	
}

void show_available(node1* head1)
{
	node1* ptr = head1;
	
	printf("the available slots is \n");
	
	while(ptr != NULL)
	{
		printf("%0.1f \n",ptr->time);
		ptr = ptr->tail;
	}
}

void reserv(node* Head,f32 slot,u16 id)
{
	node* ptr = Head;
	
	while(ptr->ID != id && ptr != NULL)
	{
		ptr = ptr->Next;
	}
	ptr->Slots = slot;
	
}

void Delete_Slot(node1** head1,f32 slot)
{
	node1* temp = *head1;
	node1* prev = *head1;
	
	if (temp != NULL && temp->time == slot)
    {
        *head1 = temp->tail;
        free(temp);
    }
    else
    {
        while (temp != NULL && temp->time != slot)
        {
            prev = temp;
            temp = temp->tail;
        }

        if (temp != NULL)
        {
            prev->tail = temp->tail;
            free(temp);
        }
    }
}

void Add_Slot(node1* head1,f32 slot)
{
	node1* ptr = head1;
	node1* prev = head1;
	
	/*Add New Slots*/
	node1* new = (node1*) malloc(sizeof(node1));
	new->time = slot;
	new->tail = NULL;
	
	while(ptr->time < new->time &&ptr != NULL)
	{
		prev = ptr;
		ptr = ptr->tail;
	}
	
	prev->tail = new;
	new->tail = ptr;
	
}

void cancel_reserv(node* Head,u16 id)
{
	f32 temp=0;
	node* ptr = Head;
	
	while (ptr->ID != id)
	{
		ptr = ptr->Next;
	}
	
	temp = ptr->Slots;
	ptr->Slots = 0.0;
	Add_Slot(head1,temp);
}

void show_record(node* Head,u16 id)
{
	node* ptr = Head;
	
	/*search ID*/
	while(ptr->ID != id && ptr != NULL)
	{
		ptr = ptr->Next;
	}
	
	printf("Name is %s \n",ptr->Name);
	printf("Gender is %c \n",ptr->Gender);
	printf("Age is %d \n",ptr->Age);
	
}

void show_reservation(node* Head)
{
	node* ptr = Head;
	
	while (ptr != NULL)
	{
		printf("the reservation is at time %0.1f for ID %d \n",ptr->Slots,ptr->ID);
		ptr = ptr->Next;
	}
	
}