#include "Header.h"

Queue::~Queue()
{
	delete[] Wait;
}
void Queue::Add(User _u)
{
	if (!IsFull())
	{
		Wait[QueueLength] = _u;
		QueueLength++;
	}
}
Queue::Queue(int m)
{
	MaxQueueLength = m;
	Wait = new User[MaxQueueLength];

	QueueLength = 0;
}
void Queue::Clear()
{
	QueueLength = 0;
}
bool Queue::IsEmpty()
{
	return QueueLength == 0;
}
bool Queue::IsFull()
{
	return QueueLength == MaxQueueLength;
}
int Queue::GetCount()
{
	return QueueLength;
}
void Queue::Show()
{
	int mm = 0;
	int* t = new int[10];
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << setw(15) << "Num |" << setw(11) << "Status |" << setw(16)
		<< "Num/of/pages |" << setw(12) << "Priority |"
		<< setw(15) << " time in line |" << " Progress: |" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < QueueLength; i++)
	{
		if (i == 0)
		{
			t[i] = Wait[i].str * 2;
			cout << Wait[i] << setw(10) << t[i] << " sec. |" << " printing    |" << endl;
			Sleep(50);
		}
		else
		{
			t[i] = Wait[i].str * 2;
			t[i] += t[i - 1];
			cout << Wait[i];/*<< setw(6) <<*/ con_s(t[i]); cout << setw(3)
				<< t[i] % 60 << " sec. |" << " stand by   |" << endl;
			Sleep(50);
		}
	}
	cout << "-------------------------------------------------------------------------------" << endl;
}

void Queue::Show1()
{
	cout << "----------------------------------------------------------------------" << endl;
	cout << setw(15) << "Number |" << setw(11) << "Status |" << setw(16)
		<< "Num/of/pages |" << setw(12) << "Priority |"
		<< setw(16) << "Expected time |" << endl;
	cout << "----------------------------------------------------------------------" << endl;
	for (int i = 0; i < QueueLength; i++)
	{
		cout << Wait[i] << setw(6) << Wait[i].str * 2 << "  sec.   |" << endl;
		Sleep(50);
	}
	cout << "----------------------------------------------------------------------" << endl;
}

User Queue::Extract()
{
	if (!IsEmpty())
	{


		User max_pri = Wait[0];
		int pos_max_pri = 0;
		for (int i = 1; i < QueueLength; i++)
		{
			if (max_pri.Pri < Wait[i].Pri)
			{
				max_pri = Wait[i];
				pos_max_pri = i;
			}
		}
		max_pri = Wait[pos_max_pri];
		int tmp2 = Wait[pos_max_pri].Pri;

		for (int i = pos_max_pri; i < QueueLength - 1; i++)
		{
			Wait[i] = Wait[i + 1];

		}
		QueueLength--;
		return max_pri;
	}

}

User::User()
{
	Name = "Name";
	id = 0;
	str = 0;
	Pri = 0;

}

User::User(string _n, int _str)
{
	Name = _n;
	str = _str;
	id = 0;
	Pri = 0;
}

void User::id_p(int _n)
{
	id = _n + 1;
}

string User::Get_name()
{
	return Name;
}

void User::Set_pri(int n)
{
	Pri = n;
}

ostream& operator<<(ostream& os, User& _u)
{
	os << '|' << setw(13) << _u.id << '|' << setw(10) << _u.Name << '|'
		<< setw(15) << _u.str << '|' << setw(11) << _u.Pri << '|';
	return os;
}

string rand_n()
{
	string* name = new string[4]{ "Admin","Teacher","Student","User" };
	return name[rand() % 4];
}

int rand_str()
{
	int str_r = rand() % 30 + 1;
	return str_r;
}

void con_s(int ss)
{
	if (ss > 60)
	{
		int mm = ss / 60;
		cout << setw(2) << mm << setw(5) << "min.";
	}
	else if (ss == 60)cout << setw(2) << 1 << setw(5) << "min.";
	else
	{
		cout << "       ";
	}


}

