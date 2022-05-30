#include"fileRecipient and fileDonor.cpp"
#include"fileBlood_information.cpp"
#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
vector<Recipient>recipient;
vector<Donor> donor;
vector<Blood_information>blood_information;
string choose;
int index_donor ;
int index_recipient ;

void Start();   
void Login();     
void Register();   
void delete_account();
int check_password();
void Back();
void display_blood();
void choose_option();
void update_data();
void request_donation();
void display_data(); 
void search_About_blood();
void bloodtype_request();
void Same_Data(string);

using namespace std;
int main()
{
	fileRecipient FR;
	fileDonor FD;
	file_boold FB;
	FD.read(donor);
	FB.read(blood_information);
	FR.read(recipient);
	FR.write(recipient);
	Start();
	return 0;
}
void Start()
{

	cout << "----------------------------------------------------------------\n";
	cout << "                    Bank Blood system \n";
	cout << "----------------------------------------------------------------\n";
	cout << "1-Donor\n";
	cout << "2-Recipient\n\n";
	cout << "Enter:";
	cin >> choose;
	if (choose == "1" || choose == "2")
	{
		int S = 3;
		while (S > 0)
		{
			int D;
			cout << "1 # Sign up\n";
			cout << "2 # Sign in\n\n";
			cout << "Enter:";
			cin >> D;

			if (D == 1)
			{
				Register();
				break;
			}
			else if(D == 2)
			{
				Login();
				break;
			}

		
	else
	{
		cout << "Please Enter a correct choose..?\n\n";
	}
	S--;
	}
}

	
}
void Register()
{

	int id, age;
	Donor d;
	Recipient r;
	fileRecipient FR;
	fileDonor FD;
	string Name, Mail, Password, Gender, Blood_type, Disease, Medicine, Date, Hospital, Doctor, check,go_next;

	
	if (choose == "1" || choose == "2")
	{
		cout << "Enter your Age:";
		cin >> age;
		cout << endl;

		if (choose == "1")
		{
			if (age < 18 || age > 60)
			{
				cout << "You cannot donate blood because your age is not appropriate and blood donation may cause health damage to you\n";
				Register();
			}
		}
		cout << "1-Enter your Name:";
		cin >> Name;
		cout << endl;
		cout << "2-Enter your Password:";
		cin >> Password;
		cout << endl;
		cout << "3-Enter your Id:";
		cin >> id;
		cout << endl;
		cout << "4-Enter your Mail:";
		cin >> Mail;
		cout << endl;
		cout << "5-Enter your Gender:";
		cin >> Gender;
		cout << endl;
		cout << "6-Enter your Blood type:";
		cin >> Blood_type;
		transform(Blood_type.begin(), Blood_type.end(), Blood_type.begin(), ::toupper);
		cout << endl;
		if (choose == "1")
		{
			int c = 3; 
			while (c > 0)
			{
				cout << "Do you have a disease \n";
				cout << "1 # yes\n";
				cout << "2 # no\n\n";
				cout << "Enter:";
				cin >> check;
				transform(check.begin(), check.end(), check.begin(), ::tolower);
				if (check == "1" || check == "2" || check == "yes" || check == "no" )
				{
					break;
				}
				else
				{
					cout << "Please Enter a correct choose..?\n\n";
				}
				c--;
				if (c == 0)
				{
					cout << "Error\n";
					Register();
				}
			}

			if (check == "1" || check == "yes")
			{
				cout << "Please Write your disease:";
				cin >> Disease;
				cout << endl;
				int c = 3;
				while (c > 0)
				{
					cout << "Do you take any medicine ?\n";
					cout << "1 # yes\n";
					cout << "2 # no\n\n";
					cout << "Enter:";
					cin >> check;
					transform(check.begin(), check.end(), check.begin(), ::tolower);
					if (check == "1" || check == "2" || check == "yes" || check == "no")
					{
						break;
					}
					else
					{
						cout << "Please Enter a correct choose..?\n\n";
					}
					c--;
					if (c == 0)
					{
						cout << "Error\n";
						Register();
					}
				}
				if (check == "1" || check == "yes")
				{
					cout << "Please Wite your medicine that you take:";
					cin >> Medicine;
					cout << endl;
				}
				else
				{
					Medicine = "null";
				}
			}
			else
			{
				Disease = "null";
				Medicine = "null";
			}
			cout << "Enter your Date:";
			cin >> Date;

			d.setId(id);
			d.setPassword(Password);
			d.setName(Name);
			d.setMail(Mail);
			d.setBlood_type(Blood_type);
			d.setAge(age);			
			d.setDisease(Disease);
			d.setGender(Gender);
			d.setDate(Date);
			d.setMedicine(Medicine);
			donor.push_back(d);
			FD.write(donor);
		}
		else
		{

			cout << "Enter your Hospital:";
			cin >> Hospital;
			cout << endl;
			cout << "Enter your Doctor:";
			cin >> Doctor;
			cout << endl;

			r.setId(id);
			r.setPassword(Password);
			r.setName(Name);
			r.setGender(Gender);
		    r.setDoctor(Doctor);
			r.setMail(Mail);
			r.setAge(age);
			r.setBlood_type(Blood_type);
			r.setHospital(Hospital);
			recipient.push_back(r);
			FR.write(recipient);

		}
	}
	else
	{
		cout << "Please Enter a correct choose..?\n\n";
		Register();
	}
	cout << "successfully registered\n";
	cout << "To go to Login 1 \n";
	cout << "To return to the main menu 2 \n";
	cin >> go_next;
	if (go_next == "1")
	{
		Login();
	}
		
		else
		{
		Start();
		}
}
void Login()
{

	int id;
	string password;
	bool found = false;
	cout << "----------------------------" << endl;
	cout << "Enter your user id : ";
	cin >> id;
	cout << "Enter your password : ";
	cin >> password;
	cout << "----------------------------" << endl;
	if (choose == "1")
	{
		
		for (int i = 0; i < donor.size(); i++)
		{

			if (id == donor[i].getId() && password == donor[i].getPassword()) {
				index_donor = i;
				found = true;
				choose_option();
			}
		}
		if (found == false) {
			cout << "user not found" << endl;
			Login();
		}
		found = false;
	}
	else if (choose == "2")
	{
		for (int i = 0; i < recipient.size(); i++) {

			if (id == recipient[i].getId() && password == recipient[i].getPassword()) {
				index_recipient = i ;
				found = true;
				choose_option();

			}
		}
		if (found == false) {
			cout << "user not found\n" << endl;
			Login();
		}
		found = false;
	}
}

void search_About_blood()
{
	string t;
	bool check2 = false;
	
	cout << "Enter the blood type:";
	cin >> t;
	transform(t.begin(), t.end(), t.begin(), ::toupper);
	for (int i = 0; i < blood_information.size(); i++)
	{
		if (t == blood_information[i].gettype())
		{
			cout << "Successful operation This blood type is available\n\n";
			check2 = true;
			Back();
		}
	}
	if (check2 == false)
	{
		cout << "This blood type is not available...\n\n";
		Back();
	}
	
}
void delete_account()
{
	string p;
	fileRecipient FR;
	fileDonor FD;
	bool found = false;
	int c = 3;
	cout << "----------------------------" << endl;
	cout << "Enter your password : ";
	cin >> p;
	cout << "----------------------------" << endl;
	if (choose == "1")
	{
		if (p == donor[index_donor].getPassword())
		{
			found = true;
			donor.erase(donor.begin() + index_donor );
			cout << "Your account is deleted...\n\n";
			FD.write(donor);
			Start();
		}
		if (found == false)
		{
			if (c > 0)
			{
				cout << "Wrong password please Try again..?\n" << endl;
				delete_account();
			}
			else
			{

				choose_option();
			}
			c--;
		}
		found = false;
	}
	else
	{
		if (p == recipient[index_recipient].getPassword())
		{
			found = true;
			recipient.erase(recipient.begin() + index_recipient );
			cout << "Your account is deleted..\n\n";
			FR.write(recipient);
			Start();

		}

		if (found == false) {
			
			if (c > 0)
			{
				cout << "Wrong password please Try again..?\n" << endl;
				delete_account();
			}
			else
			{

				choose_option();
			}
			c--;
		}
		found = false;
	}
}

void display_blood()
{
	cout << "-------------------------------------------------------------------\n";
	cout << "Blood  :" << "    " << "Type" << "    " << "Quantity" << "    " << "Received date" << "    " << "Expiry date" << endl;
	cout << "-------------------------------------------------------------------\n";

	for (int i = 0; i < blood_information.size(); i++)
	{

		cout << "Blood " << i + 1 << "  |" << "    " << blood_information[i].gettype() << "    " << "   " << blood_information[i].getQuantity() << "        " << blood_information[i].getreceived_date() << "        " << blood_information[i].getexpiry_date() << endl;
		cout << "-------------------------------------------------------------------\n";

	}
	Back();

}

void Same_Data(string type )
{
	string  Name, Mail, Password, Gender, Blood_type;
	int id,Age;
	if (type == "1")
	{
		cout << "Enter The Id :";
		    cin >> id;
			int s = check_password();
		   if  (s == 1 || s == 2 )
		   {
			   if ( s == 1)
			   {
				   donor[index_donor].setId(id);
			   }
			   else 
			   {
				   recipient[index_recipient].setId(id);
			   }
		   }
		   else
		   {
			   cout << "Failed! Please try again..?\n\n";
			   update_data();
		   }
	}
	else if (type == "2")
	{
		cout << "Enter The Password :";
		cin >> Password;
		int s = check_password();
		if (s == 1 || s == 2)
		{
			if (s == 1)
			{
				donor[index_donor].setPassword(Password);
			}
			if (s == 2)
			{
				recipient[index_recipient].setPassword(Password);
			}
		}
		else
		{
			cout << "Failed! Please try again..?\n\n";
			update_data();
		}
	}
	else if (type == "3")
	{
		cout << "Enter The Name :";
		cin >> Name;
		int s = check_password();
		if (s == 1 || s == 2)
		{
			if (s == 1)
			{
				donor[index_donor].setName(Name);
			}
			if ( s == 2)
			{
				recipient[index_recipient].setName(Name);
			}
		}
		else
		{
			cout << "Failed! Please try again..?\n\n";
			update_data();
		}
	}
	else if (type == "4")
	{
		cout << "Enter The  Age :";
		cin >> Age;
		int s = check_password();
		if (s == 1 || s == 2)
		{
			if (s == 1)
			{
				donor[index_donor].setAge(Age);
			}
			if (s == 2)
			{
				recipient[index_recipient].setAge(Age);
			}
		}
		else
		{
			cout << "Failed! Please try again..?\n\n";
			update_data();
		}
	}
	else if (type == "5")
	{
		cout << "Enter The Mail :";
		cin >> Mail;
		int s = check_password();
		if (s == 1 || s == 2)
		{
			if ( s == 1)
			{
				donor[index_donor].setMail(Mail);
			}
			if (s == 2)
			{
				recipient[index_recipient].setMail(Mail);
			}
		}
		else
		{
			cout << "Failed! Please try again..?\n\n";
			update_data();
		}
	}
	else if (type == "6")
	{
		cout << "Enter The Gender :";
		cin >> Gender;
		int s = check_password();
		if (s == 1 || s == 2)
		{
			if (s == 1)
			{
				donor[index_donor].setGender(Gender);
			}
			if (s == 2)
			{
				recipient[index_recipient].setGender(Gender);
			}
		}
		else
		{
			cout << "Failed! Please try again..?\n\n";
			update_data();
		}
	}
	else if (type == "7")
	{
		cout << "Enter The Blood_type :";
		cin >> Blood_type;
		transform(Blood_type.begin(), Blood_type.end(), Blood_type.begin(), ::toupper);
		int s = check_password();
		if (s == 1 || s == 2)
		{
			if (s == 1)
			{
				donor[index_donor].setBlood_type(Blood_type);
			}
			if ( s == 2)
			{
				recipient[index_recipient].setBlood_type(Blood_type);
			}
		}
		else
		{
			cout << "Failed! Please try again..?\n\n";
			update_data();
		}
	}
	
}
void request_donation() {
	int p;
	bool check = false;
	Blood_information blood;
	fileDonor FD;
	file_boold BI;
	string date;
	if (donor[index_donor].getAge() < 18 || donor[index_donor].getAge() > 60)
	{
		cout << "You cannot donate blood because your age is not appropriate and blood donation may cause health damage to you\n";
		
		choose_option();
	}
	else {
		if (donor[index_donor].getDisease() == "null" && donor[index_donor].getMedicine() == "null")
		{
			cout << "you can donate ,To confirm the donation request, press 1 :";
			cin >> p;
			if (p == 1)
			{
				cout << "Enter today's date : ";
				cin >> date;
				for (int i = 0; i < blood_information.size(); i++)
				{
					if (donor[index_donor].getBlood_type() == blood_information[i].gettype())
					{
						blood_information[i].setQuantity(blood_information[i].getQuantity() + 1);
						blood_information[i].setreceived_date(date);
						cout << "Your donation request has been confirmed, thank you .\n\n";
						check = true;
					}

				}
				if (check == false)
				{
					blood.settype(donor[index_donor].getBlood_type());
					blood.setQuantity(0);
					blood.setreceived_date(date);
					blood.setexpiry_date("30/9/2021");
					blood_information.push_back(blood);
					cout << "Your donation request has been confirmed, thank you .\n\n";

				}
				BI.write(blood_information);
				Back();
			}
			else 
			{
				cout << "Failed! Please try again!\n";
				choose_option();
			}
		}
		else
		{
			cout << "you cannot donate because you have some diseases and blood donation may cause health damage to you \n\n";
			choose_option();
		}
	}

}

void Back()
{
	string character;

	cout << "To return to the previous menu press B !\n";
	cout << "To logout press L !\n\n";
	cout << "Enter:";
	cin >> character;
	int S = 3;
	while (S > 0)
	{
		if (character == "B")
		{
			choose_option();
			break;
		}
		else if (character == "L")
		{
			Start();
			break;
		}
		else
		{
			cout << "Failed! Please try again!\n\n";
		}
		S--;
	}
	choose_option();
}
void bloodtype_request()
{
	int quantity_m;
	string Blood_m;
	file_boold FB;
	bool check = false;
	string e;
	string hospital;
	cout << "Enter the blood type that you need :";
	cin >> Blood_m;
	cout << "Enter the blood quantity that you need :";
	cin >> quantity_m;
	for (int i = 0; i < blood_information.size(); i++)
	{
		if (Blood_m == blood_information[i].gettype())
		{
			check = true;
			if (quantity_m < blood_information[i].getQuantity())
			{

				cout << "Do you want to send the quantity to your" << recipient[index_recipient].getHospital() << "Hospital ? \n";
				cout << "1-yes\n";
				cout << "2-no\n\n";
				cout << "Enter : ";
				cin >> e;
				transform(e.begin(), e.end(), e.begin(), ::tolower);
				if (e == "1" || e == "yes")
				{
					cout << "Donation reception is successful\n\n";
					blood_information[i].setQuantity(blood_information[i].getQuantity() - quantity_m);
					FB.write(blood_information);
					Back();
					break;
				}
				else if (e == "2" || e == "no")
				{
					cout << "Enter the Hospital : ";
					cin >> hospital;
					blood_information[i].setQuantity(blood_information[i].getQuantity() - quantity_m);
					FB.write(blood_information);
					break;
				}
				else
				{
					int count = 3;
					while (count > 0)
					{
						cout << "Faild choose! Try again\n\n";
						bloodtype_request();

					}
					break;
				}
			}
			else if (quantity_m > blood_information[i].getQuantity())
			{

				cout << "There is no such quantity because it is large\n";
				cout << "Please wait until the required quantity is available\n";
				break;
			}
			else
			{
				cout << "There are no quantities of this blood type\n\n";
				break;
			}
		}
	}
	if (check == false)
	{
		cout << "This blood type does not exist\n\n";
	}
	Back();
}
void update_data()
{
	fileRecipient Fr;
	fileDonor Fd;
	string check_update, C, Disease, Medicine, Date, Hospital, Doctor;

	cout << "Do you want to continue??\n";
	cout << "1-yes\n";
	cout << "2-no\n\n";
	cout << "Enter:";
	cin >> C;
	transform(C.begin(), C.end(), C.begin(), ::tolower);
	if (C == "yes" || C == "1")
	{
		cout << "1 # Update your id\n";
		cout << "2 # Update your password\n";
		cout << "3 # Update your name\n";
		cout << "4 # Update your Age\n";
		cout << "5 # Update your mail\n";
		cout << "6 # Update your gender\n";
		cout << "7 # Update your Blood_type\n";
		if (choose == "1")
		{
			cout << "8 # Update your disease\n";
			cout << "9 # Update your Date\n";
			cout << "10 # Return to\n\n";
			cout << "Enter the operation number:";
			cin >> check_update;
			if (check_update == "1" || check_update == "2" || check_update == "3" || check_update == "4" || check_update == "5" || check_update == "6" || check_update == "7")
			{
				Same_Data(check_update);
			}
			else if (check_update == "8")
			{
				cout << "Enter The Disease :";
				cin >> Disease;
				string check_medic;
				cout << "Do you take a medicine?\n";
				cout << "1-yes\n";
				cout << "2-no\n\n";
				cout << "Enter:";
				cin >> check_medic;
				transform(check_medic.begin(), check_medic.end(), check_medic.begin(), ::tolower);
				if (check_medic == "1" || check_medic == "yes")
				{
					cout << "Enter The Medicine :";
					cin >> Medicine;
				}
				else if (check_medic == "no" || check_medic == "2")
				{
					Medicine = donor[index_donor].getMedicine();
				}
				else
				{
					cout << "Failed! Please try again..\n\n";
					update_data();
				}
				if (check_password() == 1)
				{
					donor[index_donor].setMedicine(Medicine);
					donor[index_donor].setDisease(Disease);
				}
				else
				{
					cout << "Failed! Please try again..\n\n";
					update_data();
				}

			}
			else if (check_update == "9")
			{
				cout << "Enter date :";
				cin >> Date;
				if (check_password() == 1)
				{
					donor[index_donor].setDate(Date);
				}
				else
				{
					cout << "Failed! Please try again!\n\n";
					update_data();
				}

			}
			else if (check_update == "10")
			{
				Back();

			}

			else
			{
				cout << "Failed! Please try again..\n\n";
				update_data();
			}

			Fd.write(donor);
		}

		else
		{
			cout << "8 # Update your Hospital\n";
			cout << "9 # Update your Doctor\n";
			cout << "10 # Return To\n\n";
			cout << "Enter the operation number:";
			cin >> check_update;

			if (check_update == "1" || check_update == "2" || check_update == "3" || check_update == "4" || check_update == "5" || check_update == "6" || check_update == "7")
			{
				Same_Data(check_update);
			}
			else if (check_update == "8")
			{
				cout << "Enter The Hospital:";
				cin >> Hospital;
				if (check_password() == 2)
				{
					recipient[index_recipient].setHospital(Hospital);
				}
				else
				{
					cout << "Failed! Please try again..\n\n";
					update_data();
				}

			}
			else if (check_update == "9")
			{
				cout << "Enter The Doctor:";
				cin >> Doctor;
				if (check_password() == 2)
				{
					recipient[index_recipient].setDoctor(Doctor);
				}
				else
				{
					cout << "Failed! Please try again!\n\n";
					update_data();
				}

			}
			else if (check_update == "10")
			{
				Back();

			}
			else
			{
				cout << "Failed! Please try again!\n\n";
				update_data();
			}

			Fr.write(recipient);
		}



	}
	else if (C == "no" || C == "2")
	{
		Back();
	}
	else
	{
		cout << "Failed choose! Try again ..\n\n";
		update_data();
	}

	cout << "Data has been updated successfully...\n\n";
	choose_option();

}
int check_password()
{
	int value;
	string check_password;
	cout << "To save the changes, Please Enter your password:";
	cin >> check_password;
	if (choose == "1")
	{
		if (check_password == donor[index_donor].getPassword())
		{
			value = 1;
		}
	}
	else if (choose == "2")
	{
		if (check_password == recipient[index_recipient].getPassword())
		{
			value = 2;
		}
	}
	else
	{
		value = 3;
	}
	return value;
}
void display_data()
{
	if (choose == "1")
	{
		cout << "Your Name: " << donor[index_donor].getName()<<endl;
		cout << "Your ID: " << donor[index_donor].getId() << endl;
		cout << "Your Password: " << donor[index_donor].getPassword() << endl;
		cout << "Your Mail: " << donor[index_donor].getMail() << endl;
		cout << "Your Age: " << donor[index_donor].getAge() << endl;
		cout << "Your Gender: " << donor[index_donor].getGender() << endl;
		cout << "Your Blood type: " << donor[index_donor].getBlood_type() << endl;
		cout << "Your Disease: " << donor[index_donor].getDisease() << endl;
		cout << "Your Medicine: " << donor[index_donor].getMedicine() << endl;
		cout << "Your Date: " << donor[index_donor].getDate()<<endl;

	}
	else
	{
		cout << "Your Name: " << recipient[index_recipient].getName() << endl;
		cout << "Your ID: " << recipient[index_recipient].getId() << endl;
		cout << "Your Password: " << recipient[index_recipient].getPassword() << endl;
		cout << "Your Mail: " << recipient[index_recipient].getMail() << endl;
		cout << "Your Age: " << recipient[index_recipient].getAge() << endl;
		cout << "Your Gender: " << recipient[index_recipient].getGender() << endl;
		cout << "Your Blood type: " << recipient[index_recipient].getBlood_type() << endl;
		cout << "Your Hospital: " << recipient[index_recipient].getHospital() << endl;
		cout << "Your Doctor: " << recipient[index_recipient].getDoctor()<<endl;

	}
	Back();
}
void choose_option()
{
	if (choose == "2")
	{
		int enter;
		cout << endl;
		cout << "***********Operations**************\n";
		cout << "1 # Display your data\n";
		cout << "2 # Display all blood data\n";
		cout << "3 # Search for the availability\n";
		cout << "4 # Rquest blood type\n";
		cout << "5 # Update your account\n";
		cout << "6 # Delete your account\n";
		cout << "7 # Logout\n";
		cout << "8 # Exit the program\n\n";
		cout << "Enter your operation:";
		cin >> enter;
		switch (enter)
		{
		case 1:
			cout << "Your Data\n";
			display_data();
			break;
		case 2:
			cout << "Data Blood\n";
			display_blood();
			break;
		case 3:
			cout << "Search for blood\n";
			search_About_blood();
			break;
		case 4:
			cout << "Request Blood\n";
			bloodtype_request();
			break;
		case 5:
			cout << "Update data\n";
			update_data();
			break;
		case 6:
			cout << "Delete Account\n";
			delete_account();
			break;
		case 7:
			Start();
			break;
		case 8:
			exit(0);
		default:
			cout << "Failed Please Enter a correct choose..?\n\n";
			choose_option();
			break;
		}
	}
	else
	{
		int enter;
		cout << endl;
		cout << "************************Operations***********************\n";
		cout << "1 # Display your data\n";
		cout << "2 # donation request\n";
		cout << "3 # Update account\n";
		cout << "4 # Delete account\n";
		cout << "5 # Logout\n";
		cout << "6 # Exit the program\n\n";
		cout << "Enter your operation:";
		cin >> enter;
		switch (enter)
		{
		case 1:
			cout << "Your Data\n";
			display_data();
			break;
		case 2:
			cout << "request donation\n";
			request_donation();
			break;
		case 3:
			cout << "Update data\n";
			update_data();
			break;
		case 4:
			cout << "Delete Account\n";
			delete_account();
			break;
		case 5:
			Start();
			break;
		case 6:
			exit(0);
			break;
		default:
			cout << "Failed Please Enter a correct choose..?\n\n";
			choose_option();
			break;

		}
	}

}