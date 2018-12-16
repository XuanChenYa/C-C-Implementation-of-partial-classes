#pragma once
#include<iostream>
template<typename T>
class MyPointer
{
public:
	/*nullptr constructor*/
	MyPointer() :Pointer(nullptr) {}
	/*pointer constructor*/
	MyPointer(T*ptr) :Pointer(ptr)
	{
		std::cout << "malloc the memory£º" << ptr << std::endl;
	}
	/*copy constructor */
	MyPointer(const MyPointer&ptr)
	{
		Pointer = ptr.Pointer;
	}
	/* The destructor releases the pointer */
	~MyPointer()
	{
		std::cout << "free the memory"<<Pointer<<std::endl;
		delete Pointer;
		Pointer = nullptr;
	}
	/* Transfer of operation right */
	MyPointer&  TurnAuthority(MyPointer<T>& _Ptr)
	{
		if (this != &_Ptr)
		{
			Pointer = _Ptr.Pointer;
			_Ptr.Pointer = NULL;
		}
		return *this;
	}
	/* Print Pointer */
	void PrintPointer()
	{
		if (sizeof(Pointer) == 0)
		{
			std::cout << "Error: The pointer has no address or size error." << std::endl;
			exit(0);
		}
		else
		{
			std::cout << *Pointer << std::endl;
		}
	}
	/* Returns the Pointer */
	T* ReturnPointer()const
	{
		return this->Pointer;
	}
	/* Overload operator* */
	T& operator*()
	{
		return *Pointer;
	}
	/* Overload operator-> */
	T* operator->()
	{
		return Pointer;
	}
	/* Copies a pointer */
	T& operator=(T*ptr)
	{
		Pointer = ptr;
		return *Pointer;
	}
	/* Returns the size of */
	size_t ReturnSize()
	{
		return (size_t)sizeof(Pointer);
	}
private:
	T*Pointer;
};