#include "ListNXB.h"

ListNXB::ListNXB()
{
}

ListNXB::~ListNXB()
{
}

void ListNXB::AddNXB()
{

	NXB nxb;
	nxb.CreatAccount(vectornxb);
}

void ListNXB::AddListNXB(string path)
{
	ifstream f;
	f.open(path, ios::in);
	while (!f.eof())
	{
		string ten, matkhau;
		getline(f, ten, '\t');
		getline(f, matkhau, '\n');
		NXB a;
		a.SetName(ten);
		a.SetPass(matkhau);
		vectornxb.push_back(a);
	}
	f.close();
}

void ListNXB::XoaNXB(string name)
{
	vector<NXB>::iterator it;
	for (it = vectornxb.begin(); it != vectornxb.end(); it++)
	{
		if (it->GetName() == name)
		{
			vectornxb.erase(it);
			return;
		}
	}
	cout << "Khong Co Nha Xuat Ban Nay" << endl;
}

void UpdateNXBToFile(ListNXB& a)
{
	fstream f;
	f.open("NXB.txt", ios::out);
	vector <NXB> ::iterator it;
	for (it = a.vectornxb.begin(); it != a.vectornxb.end(); it++)
	{
		f << it->GetName() << "\t" << it->GetPass() << "\n";
	}
	f.close();
}