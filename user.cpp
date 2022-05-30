#include<string>
#include<iostream>
#include"user.h"
using namespace std;
	//setters
	void user::setId(int id) { Id = id; }
	void user::setAge(int age) { Age = age; }
	void user::setName(string name) { Name = name; }
	void user::setMail(string mail) { Mail = mail; }
	void user::setPassword(string password) { Password = password; }
	void user::setGender(string gender) { Gender = gender; }
	void user::setBlood_type(string blood_type) { Blood_type = blood_type; }

	// getters
	int user::getId() { return Id; }
	int user::getAge() { return Age; }
	string user::getName() { return Name; }
	string user::getMail() { return Mail; }
	string user::getPassword() { return Password; }
	string user::getGender() { return Gender; }
	string user::getBlood_type() { return Blood_type; }


	