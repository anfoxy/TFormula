#pragma once
#include "TStack.h"
#include "TRecord.h"
#include "TTable.h"
#include <cstring>
const int MaxLength = 255; // максимальный размер входной строки
class TFormula {
private:
  char *Formula; // входная строка
  char *PostfixForm; // постфиксная запись
  int SIZEF;
  int SIZEP;
public:
  TFormula(char form[]);
  ~TFormula();
  int FormulaChecker(void);// проверка правильности
  int proverka(char i);
  void PostfixFormPrint(void);
  void FormulaConverter(void); // перевод в постфиксную форму
  double alg(double p2, double p1, char s);
  double FormulaCalculator(void); // вычисление результата
  void GetTab(TTable<double>* varTable);
  void SetTabl(TTable<double>* varTable);
};