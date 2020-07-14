#pragma once

class Application {
public:
    Application();
    ~Application();

    int Run();

    int GetCommand();

    int Add();

    int Delete();

    int Search();

    int Display();

private:

    int command;
    SinglyLinkedList<ItemType> ItemList;

};