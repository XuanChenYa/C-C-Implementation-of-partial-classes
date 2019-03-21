/*
  项目人:轩辰
  项目内容:实现MyString类
  项目时间:3/20-2019
*/
#include<iostream>
#include<cstring>
#include"MyString.h"
using namespace std;
///Copy Set Values Set Length
inline MyString::MyString(const char* str)
{
  if(str)
  {
    set_Str(str);
  }
  else
  {
    data_str=new char[length];
    *data_str='\0';
  }
}
///Copy Set data_str Length And Copy Values
inline MyString::MyString(const MyString& str)
{
  set_Str(str.data_str);
}
///Delete[] data_str Transfr set_Str(str.data_str) Return for *this
inline MyString& MyString::operator=(const MyString& str)
{
  if(this==&str)
    return *this;
  delete[] data_str;
  set_Str(str.data_str);
  return *this;
}
///Delete[] data_str Transfr set_Str(str) Return for *this
inline MyString& MyString::operator= (const char* str)
{
  if(data_str==str)
    return *this;
  delete[] data_str;
  set_Str(str);
  return *this;
}
///if null throwd Excetion else Add Values return*this
inline MyString& MyString::operator+= (const char* str)
{
  initValues(data_str);
  char*temp=CopysPro(data_str, str);
  delete[] data_str;
  data_str=temp;
  length=strlen(data_str);
  return *this;
}
///if null throwd Excetion else Add Transfr MyString Values return*this
inline MyString& MyString::operator+= (const MyString& str)
{
  initValues(data_str);
  char*temp=CopysPro(data_str, str.data_str);
  delete[] data_str;
  data_str=temp;
  length=strlen(data_str);
  return *this;
}
///Detecting content throws an exception……
inline void MyString::initValues(const char* data_str)
{
  if(strlen(data_str)==0)
  {
    throw "The content is empty and cannot be added……";
    exit(-1);
  }
}
///Copy A Values And B Values Add temp return temp
char* MyString::CopysPro(char*A,const char*B)
{
  int a=strlen(A);
  int b=strlen(B);
  int num=a+b;
  char*temp=new char[num+1];
  for(int i=0;i<a;i++)
  {
    temp[i]=A[i];
  }
  for(int i=0;i<b;i++)
  {
    temp[i+a]=B[i];
  }
  temp[num]='\0';
  return temp;
}
///SubString return ((leftnum -> rightnum)Values)
inline char*  MyString::SubString(const int leftNum,const int rightNum)const
{
  if((leftNum<0||rightNum<0)||leftNum>=rightNum||(leftNum>length||rightNum>length))
  {
    throw "The index is Error arrayIndex not big this arrayIndex……";
  }
  char*arr=new char[rightNum-leftNum+1];
  for(int i=0,j=leftNum;j<rightNum;j++,i++)
  {
    arr[i]=data_str[j];
  }
  arr[rightNum-leftNum]='\0';
  return arr;
}
///SubString return ((0 -> rightnum)Values)
inline char* MyString::SubString(const int rightNum)const
{
  if(rightNum<=0||rightNum>length)
  {
    throw "The index is Error arrayIndex not big this arrayIndex……";
  }
  char*arr=new char[rightNum+1];
  for(int i=0;i<rightNum;i++)
  {
    arr[i]=data_str[i];
  }
  arr[rightNum]='\0';
  return arr;
}
///Contrast value, return bool type
bool MyString::compareTo(const char* str)
{
  if(length!=strlen(str))
  {
    return false;
  }
  for(int i=0;i<=length;i++)
  {
    if(data_str[i]!=str[i])
    {
      return false;
    }
  }
  return true;
}
///Set New str (Strlen(Path))Values+1 Copy Values for me
inline MyString& MyString::set_Str(const char* str)
{
  length=strlen(str);
  data_str=new char[length+1];
  strcpy(data_str,str);
  return *this;
}
///Get data_str Values
inline char* MyString::get_str()const
{
  return data_str;
}
///return char*Length Values
inline int MyString::GetLength()const
{
  return length;
}
///Delete data_str data
inline MyString::~MyString()
{
  delete[] data_str;
}
