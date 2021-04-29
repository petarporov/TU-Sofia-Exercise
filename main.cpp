#include"Menu.cpp"
#include"Funcs.cpp"

int main()
{
    List* list = NULL;
    int choice = -1;
    while(choice != 0){
        menu(&choice);
        switch(choice){
        case 1:
            pushN(&list);
            break;
        case 2:
            push(&list);
            break;
        case 3:
            deleteByID(&list);
            break;
        case 4:
            changeData(&list);
            break;
        case 5:
            printByManufacturer(list);
            break;
        case 6:
            sortList(&list);
            printAllStocks(list);
            break;
        }
    }
    writeInFile(list);
    return 0;
}


