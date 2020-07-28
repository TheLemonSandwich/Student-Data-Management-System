#include <iostream>
#include <string>
using namespace std;

struct node
{
	string name;
	int reg;
	node* next;
};
node* n;
node* head;
node* temp;
void InsertatHead();
void InsertatTail();
void InsertatIndex();
void Search();
void Display();
void Delete();

void Clear();
int main()
{
	n = new node;
	cout << "Enter Student's Data:-\n";
	cout << "Student's Name:\t";
	getline(cin, n->name);
	cout << "Registration Number:\t";
	cin >> n->reg;
	n->next = NULL;
	head = n;
	temp = n;
	system("CLS");
	do
	{
	hell:
		cout << "\t\t\t\tSTUDENT DATA MANAGEMENT SYSTEM\n\n";
		cout << "1. Student\n";
		cout << "\n2. Display\n";
		cout << "\n3. Find\n";
		cout << "\n4. Delete\n";
		cout << "\n5. Exit\n";
		int option;
		cin >> option;
		Clear();
		switch (option)
		{
		case 1:
		africa:
			cout << "1. Insert At Head\n";
			cout << "\n2. Insert At Tail\n";
			cout << "\n3. Insert At A Given Index\n";
			cout << "\n4. Main Menu\n";
			int op;
			cin >> op;
			Clear();
			switch (op)
			{
			case 1:
				InsertatHead();
				break;
			case 2:
				InsertatTail();
				break;
			case 3:
				InsertatIndex();
				break;
			case 4:
				goto hell;
			default:
				cout << "Choose from the following\n";
				goto africa;
				break;
			}
			Clear();
			break;

		case 2:
			Display();
			Clear();
			break;
		case 3:
			Search();
			Clear();
			break;
		case 4:
			Delete();
			Clear();
			break;
		case 5:
			goto newyork;
			break;
		default:
			cout << "Choose from the following\n";
			goto hell;
			break;
		}


	} while (true);
newyork:
	return 0;
}

void InsertatHead()
{
	n = new node;
	cin.ignore();
	cout << "Enter Student's Data:-\n";
	cout << "Student's Name:\t";
	getline(cin, n->name);
	cout << "Registration Number:\t";
	cin >> n->reg;
	if (head->name == "") // If no data is left, this function will run
	{
		head = n;
		head->next = NULL;
	}
	else
	{
		n->next = head;
		head = n;
	}
}
void InsertatTail()
{
	n = new node;
	cin.ignore();
	cout << "Enter Student's Data:-\n";
	cout << "Student's Name:\t";
	getline(cin, n->name);
	cout << "Registration Number:\t";
	cin >> n->reg;
	if (head->name == "") // If no data is left, this function will run
	{
		head = n;
		head->next = NULL;
	}
	else
	{
		temp = head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = n;
		n->next = NULL;
	}
}
void InsertatIndex()
{
heaven:
	int count = 0;
	if (head->name == "") // If no data is left, this function will run
	{
		head = new node;
		cout << "No Data Present\n";
		cout << "Storing Data in Head\n\n";
		cout << "Enter Student's Data:-\n";
		cin.ignore();
		cout << "Student's Name:\t";
		getline(cin, head->name);
		cout << "Registration Number:\t";
		cin >> head->reg;
		head->next = NULL;
	}
	else
	{
		cout << "At which Index do you want to Store the data: ";
		int nodenum;
		cin >> nodenum;
		temp = head;
		while (temp != NULL)
		{
			temp = temp->next;
			count++;
		}
		if (count < nodenum)
		{
			cout << "Invalid Index.\n";
			cout << "Choose from 0-" << count << endl;
			goto heaven;
		}
		count = 0;
		temp = head;
		cin.ignore();
		n = new node;
		cout << "Enter Student's Data:-\n";
		cout << "Student's Name:\t";
		getline(cin, n->name);
		cout << "Registration Number:\t";
		cin >> n->reg;
		while (count != nodenum)
		{
			if (count + 1 == nodenum)
				temp->next = n;
			temp = temp->next;
			count++;
		}
		n->next = temp;

	}

}
void Display()
{
	temp = head;
	if (temp->name == "")
	{
		cout << "There is no data left to display\n";
	}
	else
		while (temp != NULL)
		{
			cout << "Student's Name:\t" << temp->name << endl;
			cout << "Registration Number:\t" << temp->reg << endl << endl;
			temp = temp->next;
		}
}
void Search()
{
	string name;
	int reg;
up:
	temp = head;
	if (temp->name == "")
	{
		cout << "There is no Data left to search.\n";
		return;
	}
	int count = 0;
	cout << "1. Search by Registration Number\n";
	cout << "\n2. Search by Student's Name\n";
	int op;
	cin >> op;
	switch (op)
	{
	case 1:
		cout << "Enter Registration Number you want to search: ";
		cin >> reg;
		while (temp != NULL)
		{
			if (temp->reg == reg)
			{
				cout << "Index: " << count << endl;
				goto endoftheworld;
			}
			count++;
			temp = temp->next;
		}
		if (temp == NULL)
		{
			cout << -1 << endl;
		}
		break;

	case 2:
		cin.ignore();
		cout << "Enter the name you want to search: ";
		getline(cin, name);
		while (temp != NULL)
		{
			if (temp->name == name)
			{
				cout << "Index: " << count << endl;
				goto endoftheworld;
			}
			count++;
			temp = temp->next;
		}
		if (temp == NULL)
		{
			cout << -1 << endl;
		}
		break;
	default:
		cout << "Choose from the following\n";
		goto up;
		break;
	}
endoftheworld: {}
}
void Delete()
{
	int reg, count = 0;
	node* temp2 = head->next;
	temp = head;
	cout << "Enter Registration Number you want to delete: ";
	cin >> reg;
	if (temp->reg == reg && temp2 == NULL)
	{
		delete(temp);
		cout << "There is no data left.\n";
		head = new node;
	}
	while (temp2 != NULL)
	{
		if (temp2->reg == reg)
		{
			temp->next = temp2->next;
			delete(temp2);
			goto siliconvalley;
		}
		temp = temp->next;
		temp2 = temp2->next;
		count++;
	}
	if (temp == NULL)
	{
		cout << -1;
	}
siliconvalley: {}
}
void Clear()
{
	system("pause");
	system("CLS");
}