#include "pch.h"
#include "Application.h"

Application::Application() {
    this->command = -1;
    return;
}

Application::~Application(){ return; }

int Application::Run() {
	bool isTerminated = false;
	while (!isTerminated) {
		switch (GetCommand()) {
		case 1:
			Add();
			break;
		case 2:
			Delete();
			break;
		case 3:
			Search();
			break;
		case 4:
			Display();
			break;
		case 0:
			isTerminated = true;
			break;
		default:
			break;
		}

	}
	return 1;
}

int Application::GetCommand() {
    std::cout << "\t * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
    std::cout << "\t * Simple Sorted List Programme.                   *\n";
    std::cout << "\t * 1 : Add data.                                   *\n";
    std::cout << "\t * 2 : Delete data.                                *\n";
    std::cout << "\t * 3 : Search data.                                *\n";
    std::cout << "\t * 4 : Display all data.                           *\n";
    std::cout << "\t * 0 : Exit.                                       *\n";
	std::cout << "\t * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
	std::cout << "\t: ";

    std::cin >> this->command;
    switch (this->command)
    {
    case 1:
        this->command = 1;
        break;
    case 2:
        this->command = 2;
        break;
    case 3:
        this->command = 3;
        break;
    case 4:
        this->command = 4;
        break;
    case 0:
        this->command = 0;
        break;
    default:
        break;
    }
    return this->command;
}

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