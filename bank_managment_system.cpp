#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <ctime>
#include <algorithm>
#include <limits>
#include <random>
#include <queue>
#include <fstream>
#include <stdio.h>
using namespace std;
class Transaction;
class Account;




enum TransactionType {
    Deposit,
    Withdraw,
    Transfer
};

class Transaction {
    static int nextID;  

public:
    int transactionID;
    TransactionType type;
    int fromAccount;
    int toAccount;
    double amount;

    Transaction(TransactionType t, const int& from, const int& to, double amt)
        : transactionID(++nextID), type(t), fromAccount(from), toAccount(to), amount(amt) {
    }
};

// Initialize static member
int Transaction::nextID = 0;










class Utility {
public:
    static void clearScreen() {
        cout << string(50, '\n');
    }

    static void displayHeader(const string& header) {
        cout << "\n" << string(50, '=') << endl;
        cout << setw(25 + header.length() / 2) << header << endl;
        cout << string(50, '=') << endl;
    }

    static void displaySuccess(const string& message) {
        cout << "\n? Success: " << message << endl;
    }

    static void displayError(const string& message) {
        cout << "\n? Error: " << message << endl;
    }

    static void waitForKey() {
        cout << "\nPress Enter to continue...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    }

  
};
class Account {
public:
    int account_no;
    string name;
    string type;
    double balance;
    string status;
    Account(int  accNO, string  accNAME, string accType, double initalBalance) {
        account_no = accNO;
        name = accNAME;
        type = accType;
        balance = initalBalance;
        status = "Active";
    }




    void display() const {
      

        cout << left
            << setw(15) << account_no
            << setw(20) << name
            << setw(15) << type
            << setw(15) << std::fixed << std::setprecision(2) << balance
            << setw(10) << status << endl;
        




    }
    bool deposit(double amount) {
        if (amount <= 0) {
            cout << "Deposit amount must be positve" << endl;
            return false;
        }
        balance += amount;
        return true;
    }
    bool Withdraw(double amount) {
        if (amount <= 0) {
            cout << "Withdrawl amount must be positive" << endl;
            return false;
        }
        if (amount > balance) {
            cout << "Insufficient funds" << endl;
            return false;
        }
        balance -= amount;
        return true;

    }
};
class Account_Node {
public:
    Account data;
    Account_Node* next;
    Account_Node(const Account& acc) :data(acc), next(nullptr) {

    }

};
class Bank {
private:
    Account* search_account(int account_number) {
        Account_Node* current = head;
        while (current != nullptr) {
            if (current->data.account_no == account_number) {
                return &(current->data);
            }
            current = current->next;
        }
        return nullptr;






    }

    void quickSort(vector<Account>& accounts, int low, int high) {
        if (low < high) {
            int pi = partition(accounts, low, high);
            quickSort(accounts, low, pi - 1);
            quickSort(accounts, pi + 1, high);
        }
    }

    int partition(vector<Account>& accounts, int low, int high) {
        double pivot = accounts[high].balance;
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (accounts[j].balance > pivot) {  // Sort in descending order
                i++;
                swap(accounts[i], accounts[j]);
            }
        }
        swap(accounts[i + 1], accounts[high]);
        return i + 1;
    }








public:
    int lastAccountNumber = 1000;
    queue<Transaction> transactionQueue;
    vector<Transaction> transactionHistory;
    Account_Node* head;
    Bank() :head(nullptr) {

    }
    int generateAccountNumber() {
        return ++lastAccountNumber;
    }
    void add_account(const Account& acc) {
        Account_Node* newnode = new Account_Node(acc);
        if (!head) {
            head = newnode;

        }
        else {
            Account_Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newnode;
        }
        Utility::displaySuccess("Account created successfully");
    }


    void display_all_accounts() const {
        if (!head) {
            Utility::displayError("No account to display");
            return;
        }



        const Account_Node* temp = head;
        cout << left
            << setw(15) << "Account #"
            << setw(20) << "Name"
            << setw(15) << "Type"
            << setw(15) << "Balance"
            << setw(10) << "Status" << endl;

        cout << string(75, '-') << endl;
        while (temp) {
            temp->data.display();

            cout << endl;
            temp = temp->next;

        }

    }
    void saveToFile(const string& filename) const {
        ofstream outFile(filename);
        if (!outFile) {
            Utility::displayError("Failed to open file for saving.");
            return;
        }

        Account_Node* temp = head;
        while (temp) {
            outFile << temp->data.account_no << "|"
                << temp->data.name << "|"
                << temp->data.type << "|"
                << temp->data.balance << "|"
                << temp->data.status << endl;
            temp = temp->next;
        }

        outFile.close();
        Utility::displaySuccess("Accounts saved to file.");
    }


    void loadFromFile(const string& filename) {
        int maxAccNum= 0;
        ifstream inFile(filename);
        if (!inFile) {
            Utility::displayError("File not found. Starting with empty list.");
            return;
        }
        while (head) {
            Account_Node* temp = head;
            head = head->next;
            delete temp;
        }

        head = nullptr;
        Account_Node* tail = nullptr;

        int accNo;
        string name, type, status;
        double balance;
        maxAccNum = lastAccountNumber;
        while (inFile >> accNo) {
            inFile.ignore(); // ignore |
            getline(inFile, name, '|');
            getline(inFile, type, '|');
            inFile >> balance;
            inFile.ignore(); // ignore |
            getline(inFile, status);

            if (accNo > maxAccNum) {
                maxAccNum = accNo;
            }



            Account acc(accNo, name, type, balance);
            acc.status = status;

            Account_Node* newNode = new Account_Node{ acc };
            if (!head)
                head = tail = newNode;
            else {
                tail->next = newNode;
                tail = newNode;
            }
        }
        if (tail) {
            tail->next = nullptr;
        }

        inFile.close();
        Utility::displaySuccess("Accounts loaded from file.");
        lastAccountNumber = maxAccNum;
    }































    void search_Account_() {
        int accNo;
        cout << "Enter account number to search: ";
        cin >> accNo;

        Account* acc = search_account(accNo);

        if (acc != nullptr) {
            cout << "Account found:\n";
            acc->display();
        }
        else {
            cout << "Account not found!\n";
        }
    }



    void deposit_to_account() {
        int accNo;
        double amount;

        cout << "\nEnter account number: ";
        cin >> accNo;

        Account* acc = search_account(accNo);

        if (acc == nullptr) {
            Utility::displayError("Account not found!");
            return;
        }

        if (acc->status != "Active") {
            Utility::displayError("Account is inactive!");
            return;
        }

        cout << "Enter amount to deposit: ";
        cin >> amount;

        /*if (acc->deposit(amount)) {
            Utility::displaySuccess("Deposit successful!");
            cout << "New balance: " << fixed << setprecision(2)
                << acc->balance << endl;
        }
        else {
            Utility::displayError("Deposit failed.");
        }*/
        transactionQueue.push(Transaction(Deposit, accNo, 0, amount));
        Utility::displaySuccess("Deposit added to transaction queue.");
    }




    void withdraw_from_account() {
        int accNo;
        double amount;

        cout << "\nEnter account number: ";
        cin >> accNo;

        Account* acc = search_account(accNo);

        if (acc == nullptr) {
            Utility::displayError("Account not found!");
            return;
        }

        if (acc->status != "Active") {
            Utility::displayError("Account is inactive!");
            return;
        }

        cout << "Enter amount to withdraw: ";
        cin >> amount;

        /*if (acc->Withdraw(amount)) {
            Utility::displaySuccess("Withdrawal successful!");
            cout << "New balance: $" << fixed << setprecision(2)
                << acc->balance << endl;
        }
        else {
            Utility::displayError("Withdrawal failed!");
        }*/
        transactionQueue.push(Transaction(Withdraw, accNo, 0, amount));
        Utility::displaySuccess("Withdrawal added to transaction queue.");
    }


    void transfer_from_account() {
        int fromAccNo, toAccNo;
        double amount;

        cout << "\nEnter source account number: ";
        cin >> fromAccNo;

        Account* from = search_account(fromAccNo);
        if (from == nullptr) {
            Utility::displayError("Source account not found!");
            return;
        }

        if (from->status != "Active") {
            Utility::displayError("Source account is inactive!");
            return;
        }

        cout << "Enter destination account number: ";
        cin >> toAccNo;

        if (fromAccNo == toAccNo) {
            Utility::displayError("Cannot transfer to the same account!");
            return;
        }

        Account* to = search_account(toAccNo);
        if (to == nullptr) {
            Utility::displayError("Destination account not found!");
            return;
        }

        if (to->status != "Active") {
            Utility::displayError("Destination account is inactive!");
            return;
        }

        cout << "Enter amount to transfer: ";
        cin >> amount;

        /*if (from->Withdraw(amount)) {
            to->deposit(amount);
            Utility::displaySuccess("Transfer successful!");
            cout << "Source account balance: " << fixed << setprecision(2)
                << from->balance << endl;
            cout << "Destination account balance: " << fixed << setprecision(2)
                << to->balance << endl;
        }
        else {
            Utility::displayError("Insufficient funds!");
        }*/
        transactionQueue.push(Transaction(Transfer, fromAccNo, toAccNo, amount));
        Utility::displaySuccess("Transfer added to transaction queue.");

    }



    void process_transactions() {
        while (!transactionQueue.empty()) {
            Transaction t = transactionQueue.front();
            transactionQueue.pop();

            Account* from = search_account(t.fromAccount);
            Account* to = search_account(t.toAccount);

            bool success = false;

            switch (t.type) {
            case Deposit:
                if (from && from->status == "Active") {
                    success = from->deposit(t.amount);
                    if (success) {
                        Utility::displaySuccess("Deposit processed for account " + to_string(t.fromAccount));
                    }
                    else {
                        Utility::displayError("Deposit failed for account " + to_string(t.fromAccount));
                    }
                }
                else {
                    Utility::displayError("Deposit failed: account not found or inactive.");
                }
                break;

            case Withdraw:
                if (from && from->status == "Active") {
                    success = from->Withdraw(t.amount);
                    if (success) {
                        Utility::displaySuccess("Withdrawal processed for account " + to_string(t.fromAccount));
                    }
                    else {
                        Utility::displayError("Withdrawal failed for account " + to_string(t.fromAccount));
                    }
                }
                else {
                    Utility::displayError("Withdrawal failed: account not found or inactive.");
                }
                break;

            case Transfer:
                if (from && to && from->status == "Active" && to->status == "Active") {
                    success = from->Withdraw(t.amount);
                    if (success) {
                        to->deposit(t.amount);
                        Utility::displaySuccess("Transfer processed from account " + to_string(t.fromAccount) + " to " + to_string(t.toAccount));
                    }
                    else {
                        Utility::displayError("Transfer failed: insufficient funds.");
                    }
                }
                else {
                    Utility::displayError("Transfer failed: source or destination account not found or inactive.");
                }
                break;
            }

            if (success) {
                transactionHistory.push_back(t); // Save to history if successful
            }
        }

        if (transactionHistory.empty()) {
            cout << "No transactions were processed.\n";
        }
        else {
            cout << "All queued transactions processed.\n";
        }
    }

    




    void display_transaction_history() {
        if (transactionHistory.empty()) {
            cout << "No transaction history available.\n";
            return;
        }

        cout << "\n--- Transaction History ---\n";
        cout << left
            << setw(10) << "ID"
            << setw(12) << "Type"
            << setw(15) << "From Account"
            << setw(15) << "To Account"
            << setw(10) << "Amount" << '\n';

        cout << string(62, '-') << '\n'; 

        for (const auto& t : transactionHistory) {
            string typeStr;
            switch (t.type) {
            case Deposit:  typeStr = "Deposit";  break;
            case Withdraw: typeStr = "Withdraw"; break;
            case Transfer: typeStr = "Transfer"; break;
            }

            cout << left
                << setw(10) << t.transactionID
                << setw(12) << typeStr
                << setw(15) << t.fromAccount
                << setw(15) << t.toAccount
                << setw(10) << fixed << setprecision(2) << t.amount
                << '\n';
        }
    }



    void display_accounts_sorted_by_balance() {
        vector<Account> accounts;
        Account_Node* current = head;

        while (current) {
            accounts.push_back(current->data);
            current = current->next;
        }

        if (accounts.empty()) {
            Utility::displayError("No accounts to display.");
            return;
        }

        quickSort(accounts, 0, accounts.size() - 1); // Sort using Quick Sort

        cout << "\n--- Accounts Sorted by Balance (High to Low) ---\n";
        cout << left
            << setw(15) << "Account #"
            << setw(20) << "Name"
            << setw(15) << "Type"
            << setw(15) << "Balance"
            << setw(10) << "Status" << endl;

        cout << string(75, '-') << endl;
        for (const auto& acc : accounts) {

            acc.display();
            cout << endl;
        }
    }





































    bool delete_account(int account_number) {
        Account_Node* current = head;
        Account_Node* prev = nullptr;

        while (current != nullptr) {
            if (current->data.account_no == account_number) {
                if (prev == nullptr) {
                    head = current->next; // Deleting head
                }
                else {
                    prev->next = current->next;
                }
                delete current;
                return true; // Deleted successfully
            }
            prev = current;
            current = current->next;
        }
        return false; // Not found
    }


















    ~Bank() {
        while (head) {
            Account_Node* temp = head;
            head = head->next;
            delete temp;
        }
    }


};

void create_account(Bank& bank) {

    int accNo = bank.generateAccountNumber();
    string name, type;
    double initialBalance;

    Utility::displayHeader("Create New Account");
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter account type (Savings/Current): ";
    getline(cin, type);
    while (true) {
        std::cout << "Enter initial balance: ";
        std::cin >> initialBalance;

        if (std::cin.fail() || initialBalance < 0) {
            Utility::displayError("Invalid amount! Please enter a non-negative number.");
            std::cin.clear(); // Clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            break;
        }
    }
    

    Account newAcc(accNo, name, type, initialBalance);
    bank.add_account(newAcc);
}

void showMenu() {

    Utility::displayHeader("BANKING MANAGEMENT SYSTEM");
    cout << "\n=== Banking Management System ===\n";
    cout << "1. Create New Account\n";
    cout << "2. Display All Accounts\n";
    cout << "3. Search Account\n";
    cout << "4. Deposit\n";
    cout << "5. Withdraw\n";
    cout << "6. Transfer Funds\n";
    cout << "7. Show Account Transactions\n";
    cout << "8. Display Accounts Sorted by Balance\n";
    cout << "9. Delete Account\n";
    cout << "10. Process Transactions\n";
    cout << "11. Exit\n";
    cout << "Select an option (1-11): ";
}

int main() {
    Bank bank;
    bank.loadFromFile("accounts.txt");









    float choice1;
    int choice;
    do {
        showMenu();
        cin >> choice1;
        choice = choice1;
        switch (choice) {
        case 1:
            create_account(bank);
            bank.saveToFile("accounts.txt");
            break;
        case 2:
            bank.display_all_accounts();
            break;
        case 3:
            bank.search_Account_();
            break;
        case 4:
            bank.deposit_to_account();

            break;
        case 5:
            bank.withdraw_from_account();

            break;
        case 6:
            bank.transfer_from_account();
            break;
        case 7:
            bank.display_transaction_history();
            break;
        case 8:
            bank.display_accounts_sorted_by_balance();
            break;
        case 9:
            int accNo;
            cout << "Enter account number to delete: ";
            cin >> accNo;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                Utility::displayError("Invalid input!");
                break;
            }

            if (bank.delete_account(accNo)) {
                Utility::displaySuccess("Account deleted successfully.");
                bank.saveToFile("accounts.txt"); // Save updated list
            }
            else {
                Utility::displayError("Account not found.");
            }
            break;
        case 10:
            bank.process_transactions();
            bank.saveToFile("accounts.txt");
            break;
        case 11:
            cout << "\nThank you for using the Banking Management System. Goodbye!\n";
            bank.saveToFile("accounts.txt");
            break;
        default:
            Utility::displayError("Invalid option. Please try again.");
            cin.clear();
            cin.ignore();
            break;
        }

        if (choice != 11) {
            Utility::waitForKey();
            Utility::clearScreen();
        }

    } while (choice != 11);

    return 0;

}
