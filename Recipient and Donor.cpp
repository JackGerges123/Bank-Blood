#include<string>
#include"Recipient and Donor.h"
using namespace std;

// setters
	void Recipient::setHospital(string hospital)  { Hospital = hospital; }
	void Recipient::setDoctor(string doctore)   { Doctor = doctore; }
	void Donor::setDisease(string disease) { Disease = disease; }
	void Donor::setMedicine(string medicine) { Medicine = medicine; }
	void Donor::setDate(string date) { Date = date; }

	// getters
	string Recipient::getHospital() { return Hospital; }
	string Recipient::getDoctor() { return Doctor; }
	string Donor::getDisease() { return Disease; }
	string Donor::getMedicine() { return Medicine; }
	string Donor::getDate() { return Date; }


