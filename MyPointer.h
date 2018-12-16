#pragma once
#include<iostream>
template<typename T>
class MyPointer
{
public:
	/*nullptr constructor*/
	MyPointer() :Pointer(nullptr), Pointer_size(new size_t) {}
	/*pointer constructor*/
	MyPointer(T*ptr) :Pointer(ptr), Pointer_size(new size_t)
	{
		std::cout << "malloc the memory£º" << ptr << std::endl;
		*Pointer_size = 1;
	}
	/*copy constructor */
	MyPointer(const MyPointer&ptr)
	{
		Pointer = ptr.Pointer;
		Pointer_size = ptr.Pointer_size;
		++(*Pointer_size);
	}
	/* The destructor releases the pointer */
	~MyPointer()
	{
		std::cout << "free the memory"<<Pointer<<std::endl;
		delete Pointer;
		delete Pointer_size;
		Pointer = nullptr;
		Pointer_size = nullptr;
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
		if (Pointer_size == 0)
		{
			std::cout << "Error: The pointer has no address or size error." << std::endl;
			exit(0);
		}
		else
		{
			std::cout << *Pointer << std::endl;
		}
	}
	T* ReturnPointer()const
	{
		return this;
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
		Pointer_size =(size_t*) sizeof(ptr);
		Pointer = ptr;
		return *Pointer;
	}
	/* Returns the size of */
	size_t ReturnSize()
	{
		return *Pointer_size;
	}
private:
	T*Pointer;
	size_t*Pointer_size;
};