#include"Blood_information.h"
#include<string>
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
class file_boold
{
public:
	void read(vector<Blood_information>& blood_information)
	{
		Blood_information Bi;
		ifstream file1;
		file1.open("fileBlood_information.txt", ios::in);
		if (file1.is_open())
		{
			while (!file1.eof())
			{
				int Quantity;
				string  Type, Received_date, Expiry_date;
				file1 >> Type >> Quantity >> Received_date >> Expiry_date;
				Bi.settype(Type);
				Bi.setQuantity(Quantity);
				Bi.setreceived_date(Received_date);
				Bi.setexpiry_date(Expiry_date);

				blood_information.push_back(Bi);

			}
			file1.close();
		}


		else
		{
			cout << "file can't open" << endl;
		}


	}
	void write(vector<Blood_information>& blood_information)
	{
		
		ofstream file2;
		Blood_information Bi;
		file2.open("fileBlood_information.txt", ios::out);
		if (file2.is_open())
		{
			int flag = 0;

			for (int i = 0; i < blood_information.size(); i++)
			{
				file2 << blood_information[i].gettype() << "\t" << blood_information[i].getQuantity() << "\t" << blood_information[i].getreceived_date() << "\t" << blood_information[i].getexpiry_date();
				if (flag < (blood_information.size() - 1))
					file2 << endl;
				flag++;
			}

			file2.close();
		}
		else
		{
			cout << "file can't open" << endl;
		}

	}


};

