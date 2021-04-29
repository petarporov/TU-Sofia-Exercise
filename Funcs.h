#ifndef FUNCS_H_INCLUDED
#define FUNCS_H_INCLUDED

#include"List.h"

void pushN( List** list);
Stock enterData(List* list);
void push(List** list);
bool checkID(int id, List* list);
void printStock(Stock st);
void printAllStocks(List* list);
void deleteByID(List** list);
void changeData(List** list);
void printByManufacturer(List* list);
void sortList(List** head);
void writeInFile(List* list);

#endif // FUNCS_H_INCLUDED
