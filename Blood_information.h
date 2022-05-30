#include<string>
using namespace std;
class Blood_information
{
private:
	int  Quantity;
	string  Type, Received_date, Expiry_date;
public:
	// setters
	void settype(string);
	void setQuantity(int);
	void setreceived_date(string);
	void setexpiry_date(string);

	// getters
	string gettype();
	int getQuantity();
	string getreceived_date();
	string getexpiry_date();
};

