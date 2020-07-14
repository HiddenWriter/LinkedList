#include "pch.h"
#include "Application.h"

Application::Application() {
    this->command = -1;
    return;
}

Application::~Application(){ return; }

int Application::Add() {
    ItemType temp;
    temp.SetAllRecordFromUser();
    if(ItemList.Add(temp)) {
        std::cout << "\n\t Successfully Done. \n";
        return 1;
    }
    else {
        std::cout << "\n\t Error. \n";
        return 0;
    }    
}

int Application::Delete() {
    ItemType temp;
    temp.SetIDFromUser();
    if(ItemList.Delete(temp)) {
        std::cout << "\n\t Successfully Done. \n";
        return 1;
    }
    else {
        std::cout << "\n\t Error. \n";
        return 0;
    }
}

int Application::Search() {
    ItemType temp;
    temp.SetIDFromUser();
    if(ItemList.GetItem(temp)) {
        std::cout << "\n\t -- Item Information -- \n";
        std::cout << temp;
        return 1;
    }
    else {
        std::cout << "\n\t Error. \n";
        return 0;
    }
}

int Application::Display() {
    ItemList.PrintAllItem();
    return 1;
}