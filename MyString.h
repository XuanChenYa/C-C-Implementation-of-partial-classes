#ifndef __MYSTRING_H__
#define __MYSTRING_H__
/*
  项目人:轩辰
  项目内容:声明MyString类
  项目时间:3/20-2019
*/
class MyString
{
public:
  MyString(const char* str=0);
  MyString(const MyString& str);
  MyString& operator= (const MyString&str);
  MyString& operator= (const char* str);
  MyString& operator+= (const char* str);
  MyString& operator+= (const MyString& str);
  bool compareTo(const char* str);
  ///operator int return Length Values
  operator int()const
  {
    return length;
  }
  int GetLength()const;
  char* get_str()const;
  char* SubString(const int leftNum,const int rightNum)const;
  char* SubString(const int rightNum)const;
  ~MyString();
private:
  MyString& set_Str(const char* str);
  char*CopysPro(char*a,const char*b);
  void initValues(const char* data_str);
  int length=0;
  char*data_str;
};
#endif
