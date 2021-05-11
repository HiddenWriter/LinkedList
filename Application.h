#pragma once
#include <iostream>
#include <fstream>
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

private:

    int GetCommand(InterfaceType _type);

    int Add();

    int Remove();

    int Print();

    int Size();

    int Destroy();

    bool LoadTestCase();

    bool GenerateTestCase();

private:

    InterfaceType interType;
    int command;
    BaseLinkedList<ItemType>* base;
    std::pair<std::string, std::string> msg;

};