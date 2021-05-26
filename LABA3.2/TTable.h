#pragma once

#include <string>
#include <iostream>

using namespace std;

template <class T>
class TTable

{

private:

  TRecord<T> *records; // ������ �������

  unsigned int tabSize; //������ �������

  unsigned int recCount; //���������� ������� � �������

public:

  TTable(unsigned int _tabSize = 20); //�����������

  ~TTable(); //����������

  T GetValue(const string &_Name); //�������� �������� �� ����� ������

  void Add(TRecord<T> temp); //�������� ������ � �������

  string GetName(int ind); //�������� ��� ������

  void inputVarValues(); // ���� �������� ����������
  void inputVarValuesAV(double* s); // ���� �������� ����������

  void outputVarTable(); //������� ��� ������� �� �������

};

template<class T>
inline TTable<T>::TTable(unsigned int _tabSize)
{
  tabSize = _tabSize;
  records = new TRecord<T>[tabSize];
  recCount = 0;
}

template<class T>
inline TTable<T>::~TTable()
{
  delete[]records;
}

template<class T>
inline T TTable<T>::GetValue(const string & _Name)
{
 T val = NULL;
  for (int i = 0; i < recCount; i++) {
    if (records[i].GetName() == _Name) {
      val = records[i].GetValue();
    }
  }
  return val;
}

template<class T>
inline void TTable<T>::Add(TRecord<T> temp)
{
  records[recCount] = temp;
  recCount++;
}

template<class T>
inline string TTable<T>::GetName(int ind)
{
  string val ;
  val=records[ind].GetName();
  return val;
}

template<class T>
void TTable<T>::inputVarValues()
{
  for (int i = 0; i < recCount; i++) {
    T t;
    cin >> t;
    records[i].SetValue(t);
  }
}

template<class T>
inline void TTable<T>::inputVarValuesAV(double* s)
{
  for (int i = 0; i < recCount; i++) {
   
    records[i].SetValue(s[i]);
  }

}

template<class T>
inline void TTable<T>::outputVarTable()
{
  printf("_______________\n");
  printf("  Name   Value \n");
  for (int i = 0; i < recCount; i++) {
    printf("_______________\n");
    cout << "   " << records[i].GetName() <<"      " << records[i].GetValue() << endl;
  }
  printf("_______________\n");
}
