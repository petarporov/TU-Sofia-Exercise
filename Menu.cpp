#include"Header.h"
#include"Menu.h"

void menu(int* choice){
    cout<<"0. Exit.\n";
    cout<<"1. Create list and enter Stocks from keyboard.\n";
    cout<<"2. Add new Stock from keybord.\n";
    cout<<"3. Delete data by ID.\n";
    cout<<"4. Change Stock data.\n";
    cout<<"5. Print the Stocks from wanted manufacturer with higher count than wanted.\n";
    cout<<"6. Print all stocks in descending order by price.\n";
    cin>>*choice;
}
