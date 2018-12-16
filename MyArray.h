#ifndef _MYARRAYS_H_
#define _MYARRAYS_H_
#include<iostream>
template<typename T>
class MyArray
{
private:
	/*指针*/
	T *array_Data;
	/*大小*/
	int array_Size;
	/*最大*/
	int array_Max;
	/*初始化*/
	void init()
	{
		array_Data = new T[array_Max];
		array_Size = 0;
		array_Max = 1;
	}
	/*释放内存*/
	void free()
	{
		delete[]array_Data;
	}
	/*判断数组下标合法性*/
	inline bool InvalidateIndex(int Array_Index)
	{
		if (Array_Index >= 0 && Array_Index<array_Size)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
public:
	MyArray()
	{
		init();
	}
	MyArray(int Array_Size, T Array_Value)
	{
		if (Array_Size == 0)
		{
			init();
		}
		else
		{
			array_Size = Array_Size;
			array_Max = Array_Size;
			array_Data = new T[array_Max];
			for (int i = 0; i < Array_Size; ++i)
			{
				array_Data[i] = Array_Value;
			}
		}
	}
	MyArray(const MyArray&arr)
	{
		array_Size = arr.array_Size;
		array_Max = arr.array_Max;
		array_Data = new T[array_Max];
		memcpy(array_Data, arr.array_Data, array_Size * sizeof(T));
	}
	MyArray&operator=(const MyArray&arr)
	{
		if (this == &arr)
		{
			return *this;
		}
		array_Size = arr.array_Size;
		array_Max = arr.array_Max;
		T *m_Temp = new T[array_Max];
		memcpy(m_Temp, arr.array_Data, array_Size * sizeof(T));
		delete[] array_Data;
		array_Data = m_Temp;
		return *this;
	}
	~MyArray()
	{
		free();
	}
	void	PrintArray()
	{
		if (array_Size == 0)
		{
			std::cout << "Error: The empty arrays can't be Printed." << std::endl;
			exit(0);
		}
		else
		{
			for (int i = 0; i < array_Size; ++i)
			{
				std::cout << array_Data[i] << "\t";
			}
			std::cout << std::endl;
		}
	}
	int		end()const
	{
		return array_Size;
	}
	T	GetArrayAt(int Arrays_Index)
	{
		if (InvalidateIndex(Arrays_Index))
		{
			std::cout << "Error:This Arrays subscript is not detected!" << std::endl;
			exit(0);
		}
		return array_Data[Arrays_Index];
	}
	void	SetArrayAt(int Arrays_Index, T Array_Value)
	{
		if (InvalidateIndex(Arrays_Index))
		{
			std::cout << "Error:This Arrays subscript is not detected!" << std::endl;
			exit(0);
		}
		else
		{
			array_Data[Arrays_Index] = Array_Value;
		}
	}
	void	SetArraySize(int Arrays_Size)
	{
		if (Arrays_Size < array_Size)
		{
			for (int i = Arrays_Size; i < array_Size; ++i)
			{
				array_Data[i] = 0;
			}
		}
		if (array_Size <= Arrays_Size && Arrays_Size <= array_Max)
		{
			for (int i = array_Size; i < Arrays_Size; ++i)
			{
				array_Data[i] = 0;
			}
		}
		if (Arrays_Size > array_Max)
		{
			array_Max = Arrays_Size;
			T *temp = new T[array_Max];
			memcpy(temp, array_Data, Arrays_Size * sizeof(T));
			for (int i = Arrays_Size; i < Arrays_Size; ++i)
			{
				temp[i] = 0;
			}
			delete[] array_Data;
			array_Data = temp;
		}
		array_Size = Arrays_Size;
	}
	void	DeleteArrayAt(int Arrays_Index)
	{
		if (InvalidateIndex(Arrays_Index))
		{
			std::cout << "Error:This Arrays subscript is not detected!" << std::endl;
			exit(0);
		}
		else
		{
			for (int i = Arrays_Index; i < array_Size; ++i) {
				array_Data[i] = array_Data[i + 1];
			}
			array_Data[array_Size - 1] = 0;
			array_Size--;
		}
	}
	void	PushBackArray(T Array_Value)
	{
		if (array_Size<array_Max)
		{
			array_Data[array_Size] = Array_Value;
		}
		else
		{
			array_Max *= 2;
			T*temp = new T[array_Max];
			memcpy(temp, array_Data, array_Size * sizeof(T));
			delete[]array_Data;
			array_Data = temp;
			array_Data[array_Size] = Array_Value;
		}
		++array_Size;
	}
	void	InserAtArray(int Arrays_Index, T Array_Value)
	{
		if (Arrays_Index<0 || Arrays_Index>array_Size)
		{
			std::cout << "Error:This Arrays subscript is not detected!" << std::endl;
			exit(0);
		}
		else if (array_Size<array_Max)
		{
			for (int i = array_Size - 1; i >= Arrays_Index; --i)
			{
				array_Data[i + 1] = array_Data[i];
			}
			array_Data[Arrays_Index] = Array_Value;
		}
		else
		{
			array_Max *= 2;
			T*temp = new T[array_Max];
			memcpy(temp, array_Data, array_Size * sizeof(T));
			delete[]array_Data;
			array_Data = temp;
			for (int i = array_Size - 1; i >= Arrays_Index; --i)
			{
				array_Data[i + 1] = array_Data[i];
			}
			array_Data[Arrays_Index] = Array_Value;
		}
		++array_Size;
	}
	T operator[](int Array_Index)const
	{
		if (Array_Index<0 || Array_Index >= array_Size)
		{
			std::cout << "Error:This Arrays subscript is not detected!" << std::endl;
			exit(0);
		}
		return array_Data[Array_Index];
	}
	int begin()const
	{
		return (array_Size - array_Size);
	}
};
#endif