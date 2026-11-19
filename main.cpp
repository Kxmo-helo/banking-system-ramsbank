#include <iostream>
#include <string>

using namespace std;

int option;

const int SIZE = 3;
string names [SIZE]={"Josh","Melvin","Rudy"};
int accNumbers [SIZE]={1001,1002,1003};
int pins [SIZE]={1111,2222,33331};
double balances [SIZE]={500.00,12000.00,5400.00};


int login()
{
    int acc, pin;

    for(int attempt = 1; attempt <= 3; attempt++)
    {
        cout<<"Enter Account number : "<<endl;
        cin>>acc;
        cout<<"Enter Pin : "<<endl;
        cin>>pin;

        for(int i=0; i<SIZE; i++)
        {
            if(accNumbers[i] == acc && pin == pins[i])
            {
                cout<<"Welcome, "<<names[i]<<endl;
                return i;
            }
        }

        cout<<"Invalid details. Attempt "<<attempt<<" of 3."<<endl;
    }

    return -1;
}

void showBalance(int user)
{
    cout<<"Your balance is : "<<endl;
    cout<<"R"<<balances[user]<<endl;
}

void sendCash(int user)
{
    int recipientAcc, recipient = -1;
    double sendAmount;

    cout<<"Recipient account number: ";
    cin>>recipientAcc;

    for(int i=0; i<SIZE; i++)
    {
        if(accNumbers[i] == recipientAcc)
        {
            recipient = i;
        }
    }

    if(recipient == -1 || recipient == user)
    {
        cout<<"Invalid recipient."<<endl;
        return;
    }

    cout<<"Amount to send: R";
    cin>>sendAmount;

    if(sendAmount <= 0 || sendAmount > balances[user])
    {
        cout<<"Invalid amount or insufficient funds."<<endl;
    }
    else
    {
        balances[user] = balances[user] - sendAmount;
        balances[recipient] = balances[recipient] + sendAmount;
        cout<<"R"<<sendAmount<<" sent to "<<names[recipient]<<endl;
    }
}

void deposit(int user)
{
    double depositAmount;

    cout<<"Enter amount to deposit: R";
    cin>>depositAmount;

    if(depositAmount > 0)
    {
        balances[user] = balances[user] + depositAmount;
        cout<<"Your new balance is R"<<balances[user]<<endl;
    }
    else
    {
        cout<<"Invalid amount."<<endl;
    }
}

void withdraw(int user)
{
    double withdrawAmount;

    cout<<"How much do you want to withdraw R";
    cin>>withdrawAmount;

    if(withdrawAmount <= 0)
    {
        cout<<"Invalid amount."<<endl;
    }
    else if(balances[user] < withdrawAmount)
    {
        cout<<"Enter smaller amount."<<endl;
    }
    else
    {
        balances[user] = balances[user] - withdrawAmount;
        cout<<"Your new balance is R"<<balances[user]<<endl;
    }
}

void menu(int user)
{
    do
    {
        cout<<"\n=========WELCOME TO RAMS' BANK========="<<endl;
        cout<<"Select an option"<<endl;
        cout<<"1.Deposit"<<endl;
        cout<<"2.Send Cash"<<endl;
        cout<<"3.Withdraw"<<endl;
        cout<<"4.Check Balance"<<endl;
        cout<<"5.Exit"<<endl;
        cin>>option;

        switch(option)
        {
        case 1:
            deposit(user);
            break;
        case 2:
            sendCash(user);
            break;
        case 3:
            withdraw(user);
            break;
        case 4:
            showBalance(user);
            break;
        case 5:
            cout<<"GOODBYE"<<endl;
            break;
        default:
            cout<<"Invalid option. Please choose 1 to 5"<<endl;
        }
    } while(option != 5);
}


int main()
{
    int user = login();

    if(user == -1)
    {
        cout<<"Too many failed attempts. Goodbye."<<endl;
    }
    else
    {
        menu(user);
    }

    return 0;
}
