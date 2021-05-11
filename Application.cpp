#include "Application.h"

Application::Application() 
    : command(-1), interType(InterfaceType::UNDEFINED)
{
    msg.first =
    "\n\t Done";
    msg.second =
    "\n\t Fail";
    return;
}

Application::~Application(){ return; }

int Application::Run() 
{
    int cmd (0);
    while(1)
    {

        std::cout << 
        "\n\t Linked List Test "
        "\n\t (1)   Singly Linked List ( Stack ) "
        "\n\t (2)   Singly Linked List ( Queue )"
        "\n\t (0)   Terminate Programme \n";
        std::cin >> cmd;
        switch (cmd)
        {
            case 1:
            interType = InterfaceType::STACK;
            base = new MyStack<ItemType>[1];
            break;
            case 2:
            interType = InterfaceType::QUEUE;
            base = new MyQueue<ItemType>[1];
            break;
            case 0:
            Destroy();
            return 1;
            break;
        default:
            break;
        }
        bool isTerminated = false;
        while (!isTerminated) {
            switch (GetCommand(interType)) {
            case 1:
                Add();
                break;
            case 2:
                Remove();
                break;
            case 3:
                Print();
                break;
            case 4:
                Size();
                break;
            case 0:
                isTerminated = true;
                break;
            default:
                break;
            }

        }
    }
	return 1;
}

int Application::GetCommand(InterfaceType _type) 
{
    switch (_type)
    {
        case InterfaceType::STACK:
        {
            std::cout <<
            "\n\t (1)   Push"
            "\n\t (2)   Pop"
            "\n\t (3)   Print"
            "\n\t (4)   Size"
            "\n\t (0)   Exit\n";
            break;
        }
        case InterfaceType::QUEUE:
        {
            std::cout <<
            "\n\t (1)   Add"
            "\n\t (2)   Remove"
            "\n\t (3)   Print"
            "\n\t (4)   Size"
            "\n\t (0)   Exit\n";
            break;
        }
        
    default:
        break;
    }
    std::cin >> command;
    return command;
}

int Application::Add() 
{
    ItemType temp;
    temp.SetAll();
    switch (interType)
    {
        case InterfaceType::STACK:
        {
            base->Push(temp);
            break;
        }
        case InterfaceType::QUEUE:
        {
            base->Add(temp);
            break;
        }
        default:
            break;
    }
    std::cout << msg.first;
    return 1;
}

int Application::Remove() 
{
    ItemType temp;
    switch (interType)
    {
        case InterfaceType::STACK:
        {
            temp = base->Pop();
            break;
        }
        case InterfaceType::QUEUE:
        {
            temp = base->Remove();
            break;
        }
        default:
            break;
    }
    std::cout << 
    "\n\t - Removed Item - \n" <<
    temp;
    return 1;
}


int Application::Print() 
{
    base->Print();
    return 1;
}

int Application::Destroy()
{
    delete[] base;
    return 1;
}

int Application::Size()
{
    std::cout << 
    "\n\t Current Size : " << base->GetSize();
    return 1;
}