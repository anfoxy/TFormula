#include <iostream>
#include "TFormula.h"
void main() {
  setlocale(LC_ALL, "Russian");

 #define TESTS
 #ifdef TESTS
 
  double r;
  {
    char d1[] = "8.5 - (91 - 78 / 4)  * 7";
    cout << "Форммула : " << d1 << endl;
    TFormula a1(d1);
    a1.FormulaConverter();
    cout << "Expected pizExpr: 8.5 91 78 4 / - 7 * -" << endl;
    cout << "Actual pizExpr:   ";
    a1.PostfixFormPrint();
    cout << endl;
    r = a1.FormulaCalculator();
    cout << "Expected res: -492" << endl;
    cout << "Actual res:   " << r << endl;
    cout << endl;
  }
  {
    char d1[] = "-3 / (-3)";
    cout << "Форммула : " << d1 << endl;
    TFormula a1(d1);
    a1.FormulaConverter();
    cout << "Expected pizExpr: -3 -3 /" << endl;
    cout << "Actual pizExpr:   ";
    a1.PostfixFormPrint();
    cout << endl;
    r = a1.FormulaCalculator();
    cout << "Expected res: 1" << endl;
    cout << "Actual res:   " << r << endl;
    cout << endl;
  }
  cout << endl;
  cout << "Expressions with variables:" << endl;
  {
    TTable<double>* varTable = new TTable<double>[20];
    char d1[] = "alf - (91 - bet/4) * gam";
    cout << "Форммула : " << d1 << endl;
    TFormula a1(d1);
    a1.FormulaConverter();
    cout << "Expected pizExpr: alf 91 bet 4 / - gam * -" << endl;
    cout << "Actual pizExpr:   ";
    a1.PostfixFormPrint();
    cout << endl;
    a1.GetTab(varTable);

    varTable->outputVarTable();
    cout << "Enter alf = 8.5 bet = 4 gam = 3.3 " << endl;
    double s[3];
    s[0] = 8.5;
    s[1] = 4;
    s[2] = 3.3;
    varTable->inputVarValuesAV(s);
    varTable->outputVarTable();
    a1.SetTabl(varTable);
    r = a1.FormulaCalculator();
    cout << "Expected res: -288.5" << endl;
    cout << "Actual res:   " << r << endl;
    cout << endl;
  }

 #else
 #endif

  getchar();
  getchar();
}