#include <iostream>
#include <math.h>
#include <conio.h>
#include <time.h>
#include <fstream>
#include <iomanip>
using namespace std;

void CreateTable(int *tab)
{
	for (int i = 0; i < 997; i++)
	{
		tab[i] = 0;
	}
}
/*******************************************************************************/
bool InsertLinear(int *tab, int key)
{
	int value = pow(2, (key % 10));
	int where = ((key % 1000) + value + 1) % 997;
	int i = where;
	for (i; i < 997; i++)
	{
		if (i == 996 && tab[i] > 0) //you're in last position, go to the begin
		{
			cout << "Last!" << endl;
			i = 0;
		}

		if (tab[i] <= 0)
		{
			tab[i] = key;
			return true;
		}
		if (tab[i] == key)
		{
			cout << "Key already exist" << endl;
		}
	}
}
bool FindingLinear(int *tab, int key)
{
	int counter = 0;
	int value = pow(2, (key % 10));
	int where = ((key % 1000) + value + 1) % 997;
	for (int i = where; i < 997; i++)
	{
		if (i == 996 && tab[i] != key)
		{
			i = 0;
		}
		if (tab[i] == key)
		{
			cout << "Found it!" << endl;
			return true;
		}
		counter++;
		if (counter == 997)
		{
			cout << "Don't found it!" << endl;
			return false;
		}
	}
	return false;

}
bool DeletingLinear(int *tab, int key)
{
	int counter = 0;
	if (FindingLinear(tab, key) == true)
	{
		int value = pow(2, (key % 10));
		int where = ((key % 1000) + value + 1) % 997;
		for (int i = where; i < 997; i++) {
			if (i == 996 && tab[i] != key)
			{
				i = 0;
			}
			if (tab[i] == key)
			{
				tab[i] = -1;
				cout << "Deleted element " << key << endl;
				return true;
			}
			counter + 1;
			if (counter == 997)
				return false;
		}
	}
	else
	{
		cout << "Cannot delete, element doesn't exist" << endl;
		return false;
	}

}
void AddManyLinear(int *tab, int X)
{
	bool flag;
	int helpTab[1000];
	int howManyElements = 0;
	for (int i = 0; i < X; i++)
	{
		do
		{
			int rnd = rand() % 20000 + 20000;
			flag = true;
			for (int j = 0; j <= howManyElements; j++)
			{
				if (rnd == helpTab[j])
				{
					howManyElements++;
					flag = false;
				}
				else if (rnd != helpTab[j])
				{
					helpTab[j] = rnd;
					flag = true;
				}
				if (flag == true)
				{
					InsertLinear(tab, rnd);
				}
			}

		} while (flag != true);
	}
}
/*************************************************************************/
bool InsertDouble(int *tab, int key)
{
	int i = 0;
	int value = pow(2, (key % 10));
	int where = ((key % 1000) + value + 1) % 997;
	int secondWhere = (3 * key) % 19 + 1;
	int index = (where + secondWhere * i) % 997;
	do
	{
		int index = where + secondWhere * i;
		if (index >= 997)
		{
			index = index % 997;
		}
		if (tab[index] <= 0)
		{
			tab[index] = key;
			return true;
		}
		else
		{
			i++;
		}
	} while (tab[index] > 0);
}
bool FindingDouble(int *tab, int key)
{
	int i = 0;
	int value = pow(2, (key % 10));
	int where = ((key % 1000) + value + 1) % 997;
	int secondWhere = (3 * key) % 19 + 1;
	int index = (where + secondWhere * i) % 997;
	if (tab[where] <= 0)
	{
		cout << "In this place, isn't any element " << endl;
		return false;
	}
	else
	{
		do
		{
			int index = where + secondWhere * i;
			if ((index) >= 997)
			{
				index = index % 997;
			}

			if (tab[index] <= 0)
			{
				cout << "Brak!" << endl;
				return false;
			}
			else if (tab[index] == key)
			{
				cout << "Found!";
				return true;
			}
			else
			{
				i++;
			}
		} while (tab[index] > 0);
	}
}
bool DeleteDouble(int *tab, int key)
{
	if (FindingDouble(tab, key))
	{
		int i = 0;
		int value = pow(2, (key % 10));
		int where = ((key % 1000) + value + 1) % 997;
		int secondWhere = (3 * key) % 19 + 1;
		int index = (where + secondWhere * i) % 997;
		do
		{
			int index = where + secondWhere * i;
			if ((index) >= 997)
			{
				index = index % 997;
			}
			if (tab[index] == key)
			{
				cout << "Deleted!";
				tab[index] = -1;
				return true;
			}
			else
			{
				i++;
			}
		} while (tab[index] > 0);
		return true;

	}
	cout << "Cannot delete provided element" << endl;
	return false;
}
void AddManyDouble(int *tab, int X)
{
	bool flag;
	int helpTab[5000];
	int howManyElements = 0;
	for (int i = 0; i < X; i++)
	{
		do
		{
			int rnd = rand() % 20000 + 20000;
			flag = true;
			for (int j = 0; j <= howManyElements; j++)
			{
				if (rnd == helpTab[j])
				{
					howManyElements++;
					flag = false;
				}
				else if (rnd != helpTab[j])
				{
					helpTab[j] = rnd;
					flag = true;
				}
				if (flag == true)
				{
					InsertDouble(tab, rnd);
				}
			}
		} while (flag != true);
	}
}
void Display(int *tab, int indexmin, int indexmax)
{
	for (int i = indexmin; i <= indexmax; i++)
	{

		cout << "/";
		cout.width(4);
		cout << i;
		cout << ".";
		cout.width(6);
		cout << tab[i];
		cout << "";
	}
	cout << endl;
}
int Count(int *tab)
{
	int counter = 0;
	for (int i = 0; i < 997; i++)
	{
		if (tab[i] > 0)
			counter++;
	}
	return counter;
}
int main()
{
	cout << "1. Linear" << endl;
	cout << "2. Double" << endl;
	int choice;
	cin >> choice;

	switch (choice) {
	case 1: {
		srand(time(NULL));
		int k1, k2, k3, k4, x;
		clock_t begin, end;
		double time_spent;
		begin = clock();
		std::string name = "inlab06.txt";
		std::ifstream file;
		file.open(name.c_str());
		if (!file.good()) return -3;
		else
			file >> x >> k1 >> k2 >> k3 >> k4;
		file.close();
		int tab[997];
		CreateTable(tab);
		DeletingLinear(tab, k1);
		InsertLinear(tab, k1);
		Display(tab, 0, 100);
		AddManyLinear(tab, x);
		Display(tab, 0, 100);
		InsertLinear(tab, k2);
		InsertLinear(tab, k3);
		InsertLinear(tab, k4);
		Display(tab, 0, 100);
		Display(tab, 500, 600);
		DeletingLinear(tab, k3);
		DeletingLinear(tab, k4);
		Display(tab, 0, 100);
		Display(tab, 500, 600);
		end = clock();
		time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
		cout << "The running time of the algorithm: "  << time_spent << endl;
		break;
	}
	case 2: {
		srand(time(NULL));
		int k1, k2, k3, k4, X;
		clock_t begin, end;
		double time_spent;
		begin = clock();
		std::string name = "inlab06.txt";
		std::ifstream file;
		file.open(name.c_str());
		if (!file.good()) return -3;
		else
			file >> X >> k1 >> k2 >> k3 >> k4;
		file.close();
		int tab[997];
		CreateTable(tab);
		DeleteDouble(tab, k1);
		InsertDouble(tab, k1);
		Display(tab, 0, 100);
		AddManyDouble(tab, X);
		Display(tab, 0, 100);
		InsertDouble(tab, k2);
		InsertDouble(tab, k3);
		InsertDouble(tab, k4);
		Display(tab, 0, 100);
		Display(tab, 500, 600);
		DeleteDouble(tab, k3);
		DeleteDouble(tab, k4);
		Display(tab, 0, 100);
		Display(tab, 500, 600);
		cout << Count(tab);
		end = clock();
		time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
		cout << "The running time of the algorithm: "  << time_spent << endl;
		break;
	}
	default: {
		cout << "Wrong choice" << endl;
	}
	}
	return 0;
}


