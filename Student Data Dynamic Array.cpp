#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

struct Data
{
	string name;
	int reg_no;
	Data* next;
	Data* prev;
};

float Datanum = 1, Regno, count = 1;
int op;
Data* n;
Data* head;
Data* temp;
class Student_Data
{
public:
	void Display();
	//void Append();
	void Remove();
	void Insert();
	void InsertAtHead();
	void InsertAtTail();
	void Find();
};

void Clear();

int main()
{
	Student_Data s;
	n = new Data;
	head = n;
	temp = n;
	n->prev = NULL;
	n->next = NULL;
	cout << "Enter Student's Data: \n";
	cout << "Name: ";
	getline(cin, n->name);;
	cout << "Registration Number: ";
	cin >> n->reg_no;
	system("CLS");
	do
	{
		cout << "\t\t\t\tSTUDENT DATA MANAGEMENT SYSTEM\n\n";
		cout << "Choose From The Following: \n";
		cout << "1. Display\n";
		cout << "2. Remove\n";
		cout << "3. Insert\n";
		cout << "4. Insert at head\n";
		cout << "5. Insert at Tail\n";
		cout << "6. Find\n";
		cout << "Any Key to Exit\n";

		cin >> op;
		Clear();

		switch (op)
		{
		case 1:
			s.Display();
			Clear();
			break;
		case 2:
			s.Remove();
			Clear();
			break;
		case 3:
			s.Insert();
			Clear();
			break;
		case 4:
			s.InsertAtHead();
			Clear();
			break;
		case 5:
			s.InsertAtTail();
			Clear();
			break;
		case 6:
			s.Find();
			Clear();
			break;
		default:
			exit;
			break;
		}
	} while (op == 1 || op == 2 || op == 3 || op == 4 || op == 5 || op == 6);
}

void Student_Data::Display()
{
	
	int op;
Start:
	cout << "1. From first to last\n";
	cout << "2. From last to first\n";
	cin >> op;
	switch (op)
	{
								// From first to last

	case 1:
		temp = head;
		while (temp != NULL)
		{
			cout << "Registration Number:\t" << temp->reg_no;
			cout << "\t\tName:\t" << temp->name << endl;
			temp = temp->next;
		}
		break;

									// From Last to first

	case 2:
		temp = head;
	//	while (temp->next != NULL)
	//		temp = temp->next;
		do
		{
			cout << "Registration Number:\t" << temp->reg_no;
			cout << "\t\tName:\t" << temp->name << endl;
			temp = temp->prev;
		} while (temp != NULL);
		break;

	default:
	{
		cout << "Choose from the options..\n";
		goto Start;
	}
	}
}

void Student_Data::Remove()
{
	cout << "\nDeleting\n";
up:
	
	cout << "1. Delete by Index\n";
	cout << "2. Delete by Registration Number\n";;
	cin >> op;
	switch (op)
	{
	case 1:
	{

		float count = 1;
	START:
		temp = head;
		int i = 0;
		while (temp != NULL)
		{
			cout << i << ".\t";
			cout << "Registration Number:\t" << temp->reg_no;
			cout << "\t\tName:\t" << temp->name << endl;
			temp = temp->next;
		}
		temp = head;
		cout << "Index Number: ";
		cin >> Datanum;
		if (count > Datanum)
			goto START;
		while (count < Datanum)
		{
			temp = temp->next;
			count++;
		}
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		delete(temp);
		break;
	}
	case 2:
	{
		temp = head;
		int i = 0;
		while (temp != NULL)
		{
			cout << i << ".\t";
			cout << "Registration Number:\t" << temp->reg_no;
			cout << "\t\tName:\t" << temp->name << endl;
			temp = temp->next;
		}
		temp = head;
		cout << "Registration Number of the student you want to remove: ";
		cin >> Regno;
		while (temp->reg_no != Regno)
		{
			temp = temp->next;
			if (temp == NULL)
			{
				cout << "Data couldnot be found..\n";
				goto up;
			}
		}
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		delete(temp);
		break;
	}
	}

}

void Student_Data::Insert()
{
Again:
	float Datanum, Regno, count = 0;
	cout << "\nInserting\n";
	temp = head;
	n = new Data;

								// Insert at a given Index

	cout << "After which Index: ";
	cin >> Datanum;
	while (temp != NULL) {
		temp = temp->next;
		count++;
	}
	if (Datanum > count)
	{
		cout << "Index Not Initialized yet..\n";
		goto Again;
	}
		count = 1;
		temp = head;
	cout << "Enter Student's Data: \n";
	cout << "Name: ";
	cin.ignore();
	getline(cin, n->name);
	cout << "Registration Number: ";
	cin >> n->reg_no;
	while (count != Datanum)
	{
		temp = temp->next;
		count++;
	}
	n->next = temp->next;
	temp->next = n;
	n->prev = temp;
	temp->next->prev = n;
}

void Student_Data::InsertAtHead()
{
	n = new Data;
	cout << "Enter Student's Data: \n";
	cout << "Name: ";
	cin.ignore();
	getline(cin, n->name);
	cout << "Registration Number: ";
	cin >> n->reg_no;
	n->next = head;
	head->prev = n;
	n->prev = NULL;
	head = n;
}

void Student_Data::InsertAtTail()
{
	n = new Data;
	cout << "Enter Student's Data: \n";
	cout << "Name: ";
	cin.ignore();
	getline(cin, n->name);
	cout << "Registration Number: ";
	cin >> n->reg_no;
	n->next = NULL;
	temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = n;
	n->prev = temp;
}

void Student_Data::Find()
{
	cout << "Enter the registration number of the student you want to find: ";
	cin >> Regno;
	temp = head;
	while (temp != NULL)
	{
		if (temp->reg_no == Regno)
		{
			cout << "\nName:\t" << temp->name;
			cout << "\tRegistration Number:\t" << temp->reg_no << endl;
			break;
		}
		else
			temp = temp->next;
		if (temp->next == NULL)
		{
			if (temp->reg_no != Regno)
			{
				cout << "Student Not Found...\n";
				break;
			}
		}
	}
}
void Clear()
{
	system("pause");
	system("CLS");
}
