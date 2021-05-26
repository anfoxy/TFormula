#pragma once
#include <string>
#include <iostream>

using namespace std;

template <class T>
class TRecord

{

private:

  string Name;

  T Value;

public:

  TRecord(string _Name = "", T _Value = T(0)); //Конструктор
  ~TRecord();
  string GetName() { return Name; } //Получить имя

  T GetValue() { return Value; } //Получить значение

  void SetValue(const T& temp) { Value = temp; } //Задать значение
  void SetName(const string& temp) { Name = temp; } //Задать значение
 TRecord& operator=(const TRecord& rec);
 bool operator==(const TRecord& rec);
};

template<class T>
inline TRecord<T>::TRecord(string _Name, T _Value)
{
  Name  = _Name;
  Value = _Value;
}

template<class T>
inline TRecord<T>::~TRecord()
{
  Name = "";
  Value = NULL;
}

template<class T>
 TRecord<T> & TRecord<T>::operator=(const TRecord & rec)
{
   Name = rec.Name;
   Value = rec.Value;
  return *this;
}
 template<class T>
 bool TRecord<T>::operator==(const TRecord & rec)
 {
   bool flag = 0;
   if ((Name == rec.Name) && (Value == rec.Value)) flag = 1;

   return flag;
 }
