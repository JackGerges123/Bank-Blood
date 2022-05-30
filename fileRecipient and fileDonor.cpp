#include"Recipient and Donor.h"
#include<string>
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
class fileRecipient
{
public:
	void read(vector<Recipient>& recipient)
	{
		Recipient re;
		ifstream file1;
		file1.open("fileRecipien.txt", ios::in);
		if (file1.is_open())
		{
			
			while (!file1.eof())
			{
				
				string f;
				int id;
				int age;
				string Name, Mail, Password, Gender, Blood_type, Hospital, Doctor;
				file1 >> id >> Password>> Name >> Mail >> age >> Gender >> Blood_type >> Hospital >> Doctor;
				re.setId(id);
				re.setPassword(Password);
				re.setName(Name);
				re.setMail(Mail);
				re.setAge(age);
				re.setGender(Gender);
				re.setBlood_type(Blood_type);
				re.setHospital(Hospital);
				re.setDoctor(Doctor);

				recipient.push_back(re);
				
				
			}
			file1.close();
		}
		

		else
		{
			cout << "file can't open" << endl;
		}


	}
	void write(vector<Recipient> & recipient)
	{
	ofstream file2;
	file2.open("fileRecipien.txt", ios::out );
		if (file2.is_open())
		{
			
			int flag = 0;
				for (int i = 0; i < recipient.size(); i++)
				{
					file2 << recipient[i].getId() << "\t" <<recipient[i].getPassword() << "\t" << recipient[i].getName() << "\t" << recipient[i].getMail() << "\t" << recipient[i].getAge() << "\t" << recipient[i].getGender() << "\t" << recipient[i].getBlood_type() << "\t" << recipient[i].getHospital() << "\t" << recipient[i].getDoctor();
					if (flag < recipient.size()-1)
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
class fileDonor
{
public:
	void read(vector<Donor>& donor)
	{
		Donor dor;
		ifstream file1;
		file1.open("fileDonor.txt", ios::in);
		
		if (file1.is_open())
		{
			while (!file1.eof())
			{
				

				int id;
				int age;
				string Name, Mail, Password, Gender, Blood_type, Disease, Medicine, Date;
				file1 >> id >> Password >> Name >> Mail >> age >> Gender >> Blood_type >> Disease >> Medicine >> Date;
				dor.setId(id);
				dor.setPassword(Password);
				dor.setName(Name);
				dor.setMail(Mail);
				dor.setAge(age);
				dor.setGender(Gender);
				dor.setBlood_type(Blood_type);
				dor.setDisease(Disease);
				dor.setMedicine(Medicine);
				dor.setDate(Date);
				
				donor.push_back(dor);
			}
			file1.close();
		}
		else
		{
			cout << "file can't open" << endl;
		}


	}
	void write(vector<Donor>& donor)
	{
		ofstream file2;
		Donor dor;
		file2.open("fileDonor.txt", ios::out);
		if (file2.is_open())
		{
			int flag = 0;
			
		for (int i = 0; i < donor.size(); i++)
		{
			file2 << donor[i].getId() << "\t" << donor[i].getPassword() << "\t" << donor[i].getName() << "\t" << donor[i].getMail() << "\t" << donor[i].getAge() << "\t" << donor[i].getGender() << "\t" << donor[i].getBlood_type() << "\t" << donor[i].getDisease() << "\t" << donor[i].getMedicine() << "\t" << donor[i].getDate();
			if (flag < (donor.size()-1))
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