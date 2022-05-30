#include<string>
#include"user.h"

using namespace std;
class Recipient :public user
{
private:
	string  Hospital, Doctor;
public:
   //setters
	void setHospital(string);
	void setDoctor(string);

	// getters
	string getHospital();
	string getDoctor();
};
class Donor :public user
{
private:
	string Disease;
	string Medicine;
	string Date;
public:

	// setters
	void setDisease(string);
	void setMedicine(string);
	void setDate(string);

	// getters
	string getDisease();
	string getMedicine();
	string getDate();



};
