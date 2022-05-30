#include<string>
using namespace std;
class user
{
private:
	int Id;
	int Age;
	string Name;
	string Mail;
	string Password;
	string Gender;
	string Blood_type;
public:

	// setters
	void setId(int);
	void setAge(int);
	void setName(string);
	void setMail(string);
	void setPassword(string);
	void setGender(string);
	void setBlood_type(string);

	// getters
	int getId();
	int getAge();
	string getName();
	string getMail();
	string getPassword();
	string getGender();
	string getBlood_type();
	
};

