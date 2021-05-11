#pragma once
#include <iostream>

#include "ItemType.h"
#include "BaseLinkedList.h"
#include "SinglyLinkedList.h"
#include "MyQueue.h"
#include "MyStack.h"

enum class InterfaceType 
{
    STACK, QUEUE, UNDEFINED
};
class Application 
{
public:
    Application();
    ~Application();

    int Run();

    int GetCommand(InterfaceType _type);

    int Add();

    int Remove();

    int Print();

    int Size();

    int Destroy();

private:

    InterfaceType interType;
    int command;
    BaseLinkedList<ItemType>* base;
    std::pair<std::string, std::string> msg;

};