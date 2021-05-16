#pragma once
#include <iostream>
#include <fstream>
#include "ItemType.h"
#include "Array.h"
#include "ArrayDeque.h"
#include "BaseLinkedList.h"
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"
#include "MyQueue.h"
#include "MyStack.h"
#include "MyDoublyQueue.h"
#include "MyDoublyStack.h"
#include "MyListInterface.h"
#include "SpaceEfficientList.h"
#include "MySEList.h"

enum class InterfaceType 
{
    STACK, QUEUE, LIST, UNDEFINED
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

    int Set();

    int Get();

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