#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unistd.h>

using namespace std;

struct User {
    string Name;
    string Address;
    string Password;
    string Father_Name;
    string Mother_Name;
    string ID;
    string CNIC_Number;
    string Father_CNIC_Number;
    string Mother_CNIC_Number;
    string Pin;
    long double Balance;
    int Age;
};

class Bank {
private:
    struct Admin {
        int Pin[4] = {1, 2, 3, 4};
        string Id = "B3TA-BLOCKER";
        string password = "GIKI_Cyber";
    };

    Admin admin;
    vector<User> users;

public:
    Bank() {}

    void main_screen() {
        system("CLS");
        cout << "\t\t\t ******* Kali Bank ******* " << endl << endl << endl << endl;
        User_type();
    }

    void readUserDataFromFile(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Error opening file: " << filename << endl;
            return;
        }

        string line;
        // Skip header line if exists
        getline(file, line);
        while (getline(file, line)) {
            stringstream ss(line);
            User user;
            getline(ss, user.Name, ',');
            getline(ss, user.Address, ',');
            getline(ss, user.Password, ',');
            getline(ss, user.Father_Name, ',');
            getline(ss, user.Mother_Name, ',');
            getline(ss, user.ID, ',');
            getline(ss, user.CNIC_Number, ',');
            getline(ss, user.Father_CNIC_Number, ',');
            getline(ss, user.Mother_CNIC_Number, ',');
            getline(ss, user.Pin, ',');
            ss >> user.Balance;
            ss.ignore();
            ss >> user.Age;
            users.push_back(user);
        }

        file.close();
    }

    void User_type() {
        system("CLS");
        cout << "\t\t\t ******* Kali Bank ******* " << endl << endl << endl << endl;
        int choice;
        cout << "1. Admin" << endl;
        cout << "2. User Login " << endl;
        cout << "3. Sign up" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                Admin_verification();
                break;
            case 2:
                User_login();
                break;
            case 3:
                User_Signup();
                break;
            case 4:
                system("CLS");
                cout << endl << endl << "     **** Thank you for using the Kali Bank **** " << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                main_screen();
                break;
        }
    }

    void Admin_verification() {
        system("CLS");
        cout << "\t\t\t ******* Kali Bank ******* " << endl << endl << endl << endl;
        string id, password;
        cout << "Admin Verification" << endl;
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Password: ";
        cin >> password;
        bool flag = false;
        if (id == admin.Id && password == admin.password) {
            flag = true;
        } else {
            cout << "Invalid credentials. Returning to main screen." << endl;
            main_screen();
        }
        if (flag) {
            system("CLS");
            cout << "\t\t\t ******* Kali Bank ******* " << endl << endl << endl << endl;
            start:
            char ch;
            cout << "{ 1 }.For Complete Record " << endl;
            cout << "{ 2 }. For Specific Search " << endl;
            cout << "Enter  your choice : ";
            cin >> ch;
            switch (ch) {
                case '1':
                    Complete_Record();
                    break;
                case '2':
                    Specific_search();
                    break;
                default:
                    cout << "Wrong Entry";
                    goto start;
            }
        }
        back:
        char ch;
        cout << endl << endl << "{1}.For Previous Page " << endl;
        cout << "{2}.For searching again" << endl;
        cout << "Enter your choice : ";
        cin >> ch;

        switch (ch) {
            case '1':
                main_screen();
                break;
            case '2':
                goto start;
            default:
                cout << "Wrong Entry ";
                for (int i = 0; i < 5; i++) {
                    cout << " . ";
                    sleep(1);
                }
                goto back;
        }
    }

    void Complete_Record() {
        system("CLS");
        cout << "\t\t\t ******* Kali Bank ******* " << endl << endl << endl << endl;
        cout << "Complete Record" << endl;
        for (const auto& user : users) {
            cout << "Name: " << user.Name << endl;
            cout << "Address: " << user.Address << endl;
            cout << "ID: " << user.ID << endl;
            cout << "CNIC Number: " << user.CNIC_Number << endl;
            cout << "Father's CNIC Number: " << user.Father_CNIC_Number << endl;
            cout << "Mother's CNIC Number: " << user.Mother_CNIC_Number << endl;
            cout << "Balance: " << user.Balance << endl;
            cout << "Age: " << user.Age << endl;
            cout << "---------------------------" << endl;
        }
    }

    void Specific_search() {
        system("CLS");
        cout << "\t\t\t ******* Kali Bank ******* " << endl << endl << endl << endl;
        string id;
        cout << "Specific Search" << endl;
        cout << "Enter user ID: ";
        cin >> id;
        bool found = false;
        for (const auto& user : users) {
            if (user.ID == id) {
                cout << "User found!" << endl;
                cout << "Name: " << user.Name << endl;
                cout << "Address: " << user.Address << endl;
                cout << "ID: " << user.ID << endl;
                cout << "CNIC Number: " << user.CNIC_Number << endl;
                cout << "Father's CNIC Number: " << user.Father_CNIC_Number << endl;
                cout << "Mother's CNIC Number: " << user.Mother_CNIC_Number << endl;
                cout << "Balance: " << user.Balance << endl;
                cout << "Age: " << user.Age << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << endl << endl << "User not found." << endl << endl;
            cout << "Directing you to the Home Page ";
            for (int i = 0; i < 5; i++) {
                cout << " .";
                sleep(1);
            }
        }
    }

    void User_Signup() {
        system("CLS");
        cout <<
"\t\t\t ******* Kali Bank ******* " << endl << endl << endl << endl;
        User user;
        system("CLS");
        cout << "\t\t\t ******* Kali Bank ******* " << endl << endl << endl << endl;
        cout << "User Signup" << endl;
        cout << "Name: ";
        cin.ignore();
        getline(cin, user.Name);
        cout << "Address: ";
        getline(cin, user.Address);
        cout << "Password: ";
        cin >> user.Password;
        cout << "Father's Name: ";
        cin.ignore();
        getline(cin, user.Father_Name);
        cout << "Mother's Name: ";
        getline(cin, user.Mother_Name);
        cout << "ID: ";
        cin >> user.ID;
        cout << "CNIC Number: ";
        cin >> user.CNIC_Number;
        cout << "Father's CNIC Number: ";
        cin >> user.Father_CNIC_Number;
        cout << "Mother's CNIC Number: ";
        cin >> user.Mother_CNIC_Number;
        cout << "Pin: ";
        cin >> user.Pin;
        cout << "Balance: ";
        cin >> user.Balance;
        cout << "Age: ";
        cin >> user.Age;
        users.push_back(user);
        cout << "User signup successful!" << endl;
        sleep(2);
        main_screen();
    }

    void User_login() {
        system("CLS");
        cout << "\t\t\t ******* Kali Bank ******* " << endl << endl << endl << endl;
        string id, password;
        cout << "User Login" << endl;
        cout << "ID: ";
        cin >> id;
        cout << "Password: ";
        cin >> password;
        bool found = false;
        for (size_t i = 0; i < users.size(); ++i) {
            if (users[i].ID == id && users[i].Password == password) {
                found = true;
                User_choice(i);
                break;
            }
        }
        if (!found) {
            cout << "Invalid credentials." << endl
                 << " Returning to main screen.";
            for (int i = 0; i < 5; i++) {
                cout << " .";
                sleep(1);
            }
            main_screen();
        }
    }

    void User_choice(int index) {
        system("CLS");
        cout << "\t\t\t ******* Kali Bank ******* " << endl << endl << endl << endl;
        start:
        int choice;
        cout << "1. Cash Deposit" << endl;
        cout << "2. Money Transfer" << endl;
        cout << "3. Account Status" << endl;
        cout << "4. Delete Account" << endl;
        cout << "5. Logout" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                Cash_Deposit(index);
                break;
            case 2:
                Money_Transfer(index);
                break;
            case 3:
                Account_status(index);
                break;
            case 4:
                Delete_Account(index);
                break;
            case 5:
                system("CLS");
                cout << "Logging out.";
                for (int i = 0; i < 5; i++) {
                    cout << " .";
                    sleep(1);
                }
                main_screen();
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                goto start;
                break;
        }
    }

    void Cash_Deposit(int index) {
        system("CLS");
        cout << "\t\t\t ******* Kali Bank ******* " << endl << endl << endl << endl;
        double amount;
        cout << "Cash Deposit" << endl;
        cout << "Enter the amount to deposit: ";
        cin >> amount;
        users[index].Balance += amount;
        cout << "Deposit successful!" << endl;
        User_choice(index);
    }

    void Money_Transfer(int index) {
        system("CLS");
        cout << "\t\t\t ******* Kali Bank ******* " << endl << endl << endl << endl;
        string targetId;
        double amount;
        cout << "Money Transfer" << endl;
        cout << "Enter the recipient's ID: ";
        cin >> targetId;
        int targetIndex = -1;
        for (size_t i = 0; i < users.size(); ++i) {
            if (users[i].ID == targetId) {
                targetIndex = i;
                break;
            }
        }
        if (targetIndex != -1) {
            system("CLS");
            cout << "\t\t\t ******* Kali Bank ******* " << endl << endl << endl << endl;
            cout << "Enter the amount to transfer: ";
            cin >> amount;
            if (users[index].Balance >= amount) {
                users[index].Balance -= amount;
                users[targetIndex].Balance += amount;
                cout << "Money transfer successful!" << endl;
            } else {
                cout << "Insufficient balance.";
                for (int i = 0; i < 5; i++) {
                    cout << " .";
                    sleep(1);
                }
                User_choice(index);
            }
        } else {
            cout << "Recipient not found.";
            for (int i = 0; i < 5; i++) {
                cout << " .";
                sleep(1);
            }
        }
        User_choice(index);
    }

    void Account_status(int index) {
        system("CLS");
        cout << "\t\t\t ******* Kali Bank ******* " << endl << endl << endl << endl;
        cout << "Account Status" << endl;
        cout << "Name: " << users[index].Name << endl;
        cout << "Address: " << users[index].Address << endl;
        cout << "ID: " << users[index].ID << endl;
        cout << "CNIC Number: " << users[index].CNIC_Number << endl;
        cout << "Father's CNIC Number: " << users[index].Father_CNIC_Number << endl;
        cout << "Mother's CNIC Number: " << users[index].Mother_CNIC_Number << endl;
        cout << "Balance: " << users[index].Balance << endl;
        cout << "Age: " << users[index].Age << endl;
        User_choice(index);
    }

    void Delete_Account(int index) {
        system("CLS");
        cout << "\t\t\t ******* Kali Bank ******* " << endl << endl << endl << endl;
        cout << "Delete Account" << endl;
        users.erase(users.begin() + index);
        system("CLS");
        cout << "Account deleted." << endl;
        sleep(2);
        main_screen();
    }
};

int main() {
    Bank bank;
    bank.readUserDataFromFile("customer.csv");
    bank.main_screen();
    return 0;
}
