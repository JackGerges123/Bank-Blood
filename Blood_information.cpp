#include "Blood_information.h"
// setters
void Blood_information::settype(string type) { Type = type; }
void Blood_information::setQuantity(int quantity) { Quantity = quantity ; }
void Blood_information::setreceived_date(string received_date) { Received_date = received_date; }
void Blood_information::setexpiry_date(string rxpiry_date) { Expiry_date = rxpiry_date; }

// getters
string Blood_information::gettype() { return Type; }
int Blood_information::getQuantity() { return Quantity; }
string Blood_information::getreceived_date() { return Received_date; }
string Blood_information::getexpiry_date() { return Expiry_date; }
