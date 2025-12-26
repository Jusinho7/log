#include <iostream>
#include <string> 
using namespace std;

struct Identity {
    string name;
    string first_name;
    string birthday;
    string place_of_birth;
    string marital_status;
    string nationality;
    string origin;
};

int main() {
    Identity id;

    cout << "Welcome to my biography\n";
    cout << "I introduce myself:\n\n";

    id.name = "Rasolovoahangy";
    id.first_name = "Sitraka Jose Luc";
    id.birthday = "July 12, 2004";
    id.place_of_birth = "Sahalava";
    id.marital_status = "Single";
    id.nationality = "Malagasy";
    id.origin = "Betsileo";

    cout << "\tName: " << id.name << endl;
    cout << "\tFirst name: " << id.first_name << endl;
    cout << "\tBirthday: " << id.birthday << endl;
    cout << "\tPlace of birth: " << id.place_of_birth << endl;
    cout << "\tMarital status: " << id.marital_status << endl;
    cout << "\tNationality: " << id.nationality << endl;
    cout << "\tOrigin: " << id.origin << endl;

    return 0;
}
