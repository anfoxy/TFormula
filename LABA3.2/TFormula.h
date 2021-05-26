#pragma once
#include "TStack.h"
#include "TRecord.h"
#include "TTable.h"
#include <cstring>
const int MaxLength = 255; // ������������ ������ ������� ������
class TFormula {
private:
  char *Formula; // ������� ������
  char *PostfixForm; // ����������� ������
  int SIZEF;
  int SIZEP;
public:
  TFormula(char form[]);
  ~TFormula();
  int FormulaChecker(void);// �������� ������������
  int proverka(char i);
  void PostfixFormPrint(void);
  void FormulaConverter(void); // ������� � ����������� �����
  double alg(double p2, double p1, char s);
  double FormulaCalculator(void); // ���������� ����������
  void GetTab(TTable<double>* varTable);
  void SetTabl(TTable<double>* varTable);
};