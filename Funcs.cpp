#include"Funcs.h"

void writeInFile(List* list){
    ofstream file;
    file.open("data.bin", ios::out | ios::binary);
    while(list != NULL){
        file.write((char*)&list->stock, sizeof(list->stock));
        list = list->next;
    }
    file.close();
}

void sortList(List** head){
    List* current = *head;
    Stock max;
    List* tempList;

    while(current != NULL){
        max = current->stock;
        tempList = current;
        while(tempList != NULL){
            if(tempList->stock.price > max.price){
                Stock temp = tempList->stock;
                max = tempList->stock;
                tempList->stock = current->stock;
                current->stock = temp;
            }
            tempList = tempList->next;
        }
        current = current->next;
    }
}

void printByManufacturer(List* list){
    cout<<"Enter wanted Manufacturer: ";
    string manif;
    cin>>manif;
    cout<<"Enter minimum stock count: ";
    int min;
    cin>>min;
    while(list != NULL){
        if(list->stock.manufacturer == manif && list->stock.count > min){
            printStock(list->stock);
        }
        list = list->next;
    }
}

void changeData(List** list){
    List* current = *list;
    int id;
    cout<<"Enter wanted ID: ";
    cin>>id;
    while(current != NULL){
        if(current->stock.id == id){
            current->stock = enterData(*(list));
            return;
        }
        current = current->next;
    }
    cout<<"There is no Stock with such ID!!!\n";
}

void printAllStocks(List* list){
    List* temp = list;
    while(temp != NULL){
        printStock(temp->stock);
        temp = temp->next;
    }
}

void deleteByID(List** head){
    cout<<"Enter wanted ID: ";
    int id;
    cin>> id;
    List* current = *head;
    if((*head) == NULL)
        return;

    if((*head)->stock.id == id){
        *head = current->next;
        delete current;
        cout<<"------Deleted!\n";
        return;
    }
    List* toDelete;
    while(current != NULL && current->next != NULL){
        if(current->next->stock.id == id){
            toDelete = current->next;
            current->next = toDelete->next;
            delete toDelete;
            cout<<"------Deleted!\n";
            return;
        }
        current = current->next;
    }
    cout<<"There is no Stock with such ID!!!\n";
}

void printStock(Stock st){
    cout<< "ID: " << st.id << "\nName: " << st.name << "\nManufacturer: " << st.manufacturer << "\nCount: " << st.count << "\nPrice: "<< st.price <<endl;
}

void push(List** list){
    List* new_list = new List();
    Stock stock = enterData(*(list));
    new_list->stock = stock;
    new_list->next = *list;
    *list = new_list;
}

Stock enterData(List* list){
    Stock st;
    bool correct = false;
    int id;
    do{
        cout<<"Enter ID:";
        cin>>id;
        correct = checkID(id, list);
    }while(correct == false);
    st.id = id;

    cout<<"Enter Name: ";
    cin>>st.name;
    cout<<"Enter manufacturer: ";
    cin>>st.manufacturer;
    cout<<"Enter Stock Count: ";
    cin>>st.count;
    cout<<"Enter Price per one Stock: ";
    cin>>st.price;
    return st;
}

bool checkID(int id, List* list){
    List* current = list;
    while(current != NULL){
        if(current->stock.id == id){
            cout<<"This ID already exist!\n";
            return false;
        }
        current = current->next;
    }
    return true;
}

void pushN(List** list){
    cout<<"How many Stocks do you want to add: ";
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        push(list);
    }
}
