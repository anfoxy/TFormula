#include "TFormula.h"

TFormula::TFormula(char form[])
{

  SIZEF = strlen(form);
  SIZEP = SIZEF;
  Formula = new char[SIZEF];
  PostfixForm = new char[255];

  for (int i = 0; i < strlen(form); i++) {
    Formula[i] = form[i];
    PostfixForm[i] = 0;
  }
}

TFormula::~TFormula()
{
  delete[]Formula;
  delete[]PostfixForm;
  SIZEF = 0;
  SIZEF = 0;
}

int TFormula::FormulaChecker()
{
  TStack ot;
  TStack INTSTACK;
  int ERROR = 0;
  int sc = 0;
  for (int i = 0; i < SIZEF; i++) {
    if (Formula[i] == '(') {
      ot.Put(1);
      INTSTACK.Put(i);
      sc++;
    }
    else {
      if (Formula[i] == ')') {
        ot.Put(2);
        sc++;
        if (INTSTACK.IsEmpty() == 0) {
          cout << INTSTACK.Get() << " " << i << endl;
        }
        else {
          ERROR++;
          cout << "?" << " " << i << endl;
        }
      }
      else {
        sc++;
        ot.Put(3);
      }

    }

  }
  while (INTSTACK.IsEmpty() == 0) {
    cout << INTSTACK.Get() << " " << "?" << endl;
    ERROR++;
  }
  char *SCOB;
  SCOB = new char[sc];

  for (int i = 0; i < sc; i++) {
    if (i > 9) cout << i % 10;
    else cout << i;
  }
  cout << endl;
  for (int i = 0; i < sc; i++) {
    if (ot.End() == 2) {
      SCOB[i] = ')';
      ot.Get();
    }
    else {
      if (ot.End() == 1) {
        SCOB[i] = '(';
        ot.Get();
      }
      else {
        SCOB[i] = ' ';
        ot.Get();
      }
    }
  }
  for (int i = sc - 1; i > -1; i--) {
    cout << SCOB[i];
  }
  cout << endl;
  return ERROR;
}
int TFormula::proverka(char i) {
  int s = -1;
  switch (i)
  {
  case '(':
    s = 0;
    break;
  case ')':
    s = 1;
    break;
  case '+':
    s = 2;
    break;
  case '-':
    s = 2;
    break;
  case '*':
    s = 3;
    break;
  case '/':
    s = 3;
    break;
  case ' ':
    s = -2;
    break;
  }
  return s;
}

void TFormula::PostfixFormPrint(void)
{
  for (int i = 0; i < SIZEP; i++) {
    cout << PostfixForm[i];
  }
}

void TFormula::FormulaConverter(void)
{

  TStack INTSTACK;
  TStack CHARSTACK;
  int temp = 0;
  int s;
  int j = 0;
  for (int i = 0; i < SIZEF; i++) {
    s = proverka(Formula[i]);
    if (s != -2) {
      if (s == -1) {
        PostfixForm[j] = Formula[i];
        j++;
        temp = 1;
        PostfixForm[j] = ' ';

      }
      else {
        if ((s == 2 && i == 0) || (temp == 0 && s == 2)) {
          PostfixForm[j] = Formula[i];
          j++;
          PostfixForm[j] = ' ';
        }
        else { 
          PostfixForm[j] = ' ';
          j++;
          PostfixForm[j] = ' ';
          if ((s == 0) || (s > INTSTACK.End()) || (INTSTACK.IsEmpty() != 0)) {
            if (s == 0)  j--;
            temp = 0;
            INTSTACK.Put(s);
            CHARSTACK.Put(i);
          }
          else {
            if (s == 1) {
              while (INTSTACK.End() != 0) {
                PostfixForm[j] = Formula[(int)CHARSTACK.Get()];
                INTSTACK.Get();
                j++;
                PostfixForm[j] = ' ';
                j++;
                PostfixForm[j] = ' ';
              }
              j--;
              INTSTACK.Get();
              CHARSTACK.Get();
            }
            else {
              while (s <= INTSTACK.End()) {

                PostfixForm[j] = Formula[(int)CHARSTACK.Get()];
                INTSTACK.Get();

                j++;
                PostfixForm[j] = ' ';
                j++;
                PostfixForm[j] = ' ';
              }
              INTSTACK.Put(s);
              CHARSTACK.Put(i);

            }


          }
        }
      }
    }
  }
  if (INTSTACK.End() == 1) {
    j--;
    INTSTACK.Get();
    INTSTACK.Get();
    CHARSTACK.Get();
    CHARSTACK.Get();
  }
  while (CHARSTACK.IsEmpty() == 0) {

    j++;
    PostfixForm[j] = Formula[(int)CHARSTACK.Get()];
    j++;
    PostfixForm[j] = ' ';
  }
  SIZEP = j;

}
double TFormula::alg(double p2, double p1, char s) {
  double res = -1;
  switch (s)
  {
  case '+':
    res = p1 + p2;
    break;
  case '-':
    res = p1 - p2;
    break;
  case '*':
    res = p1 * p2;
    break;
  case '/':
    if (p2 != 0)  res = p1 / p2;
    else res = 999999999;
    break;
  }
  return res;
}
double TFormula::FormulaCalculator(void)
{

  int min = 0;
  int temp2 = 0;
  int temp3 = 0;
  int temp = 0;
  double p1 = 0, p2 = 0;
  double res = 0;
  TStack INTSTACK;
  for (int i = 0; i < SIZEP; i++) {
    if ((PostfixForm[i] == '-') && (PostfixForm[i + 1] != ' ')&&(i!= SIZEP-1)) {
      INTSTACK.Put(-1);
      temp = 0;
      min = 1;
    }
    else {

      if ((PostfixForm[i] == '+') || (PostfixForm[i] == '-') || (PostfixForm[i] == '*') || (PostfixForm[i] == '/')) {
        p2 = INTSTACK.Get();
        p1 = INTSTACK.Get();
        res = alg(p2, p1, PostfixForm[i]);
        if (res == 999999999) {
          cout << "вычисление невозможно" << endl;
          return 1;
        }
        INTSTACK.Put(res);
      } else {
        if (PostfixForm[i] == ' ') {
          temp = 1;
        }  else {
          if (PostfixForm[i] == '.') {
            p1 = 0;
            temp2 = INTSTACK.Get();
            for (int j = i+1; PostfixForm[j] != ' '; j++) {
              temp3 = temp3 * 10 + (PostfixForm[j] - '0');
              p1++;
              i = j;
            }
            if (temp2 < 0) {
              INTSTACK.Put(temp2 - (static_cast<double>(temp3) / pow(10, p1)));
            }
            else {
              INTSTACK.Put(temp2 + (static_cast<double>(temp3) / pow(10, p1)));
            }
            temp3 = 0;

          }else{
          if (temp == 0 && i > 0) {
            temp2 = INTSTACK.Get();
            if (min == 1) {
              INTSTACK.Put(temp2 * (PostfixForm[i] - '0'));
              min = 0;
            }
            else {
              INTSTACK.Put((temp2 * 10) + PostfixForm[i] - '0');
            }
          }
         
            else {
              INTSTACK.Put(PostfixForm[i] - '0');
              temp = 0;
            }
          }
        }

      }
    }
  }
  double r = INTSTACK.End();
  return r;

}


void TFormula::GetTab(TTable<double>* varTable)
{
  TRecord<double> rec;
  TRecord<double> rec2;
  string x="";
  char* form;
  int ind = 0;
  form = new char[10];
  for (int i = 0; i < SIZEP; i++) {
    if ((PostfixForm[i] != '+') && (PostfixForm[i] != '-') && (PostfixForm[i] != '*') && (PostfixForm[i] != '/')) {
      if((PostfixForm[i] > '9') || (PostfixForm[i]  < '1') && (PostfixForm[i] != ' ') && (PostfixForm[i] != '.')) {
        form[ind] = PostfixForm[i];
        ind++;
      }
      if (PostfixForm[i] == ' ' && ind > 0) {
        form[ind] = '\0';
        x = form;
        rec.SetName(x);
        if (rec == rec2) {}
        else {
          varTable->Add(rec);
        }
        rec2 = rec;
        ind = 0;
      }
    }

  }
}

void TFormula::SetTabl(TTable<double>* varTable)
{
  string x = ""; 
  string x2 = "";
  char* form;
  form = new char[10];
  int ind = 0;
  int n = 0;
  char * tab2;
  char* formul;
  formul = new char[SIZEP];
  for (int i = 0; i < SIZEP + 1; i++) {
    formul[i] = PostfixForm[i];
  }
  for (int i = 0; i < SIZEP; i++) {
    if ((formul[i] != '+') && (formul[i] != '-') && (formul[i] != '*') && (formul[i] != '/')) {
      if ((formul[i] > '9') || (formul[i] < '1') && (formul[i] != ' ') && (formul[i] != '.')) {
        form[ind] = formul[i];
        ind++;
      } else {
        if (formul[i] == ' ' && ind > 0) {
          form[ind] = '\0';
          x = form;
          x2 = to_string(varTable->GetValue(x));

          tab2 = new char[x2.length() + 1];
          strcpy_s(tab2, strlen(x2.c_str()) + 1, x2.c_str());
          for (int j = 0; (j < strlen(tab2) && j < 5); j++) {
            if (tab2[j] == ',') {
              PostfixForm[n] = '.';
              n++;
            }
            else {
              PostfixForm[n] = tab2[j];
              n++;
            }
          }
          PostfixForm[n] = ' ';
          n++;
          ind = 0;
        } else {
          PostfixForm[n] = formul[i];
          n++;
        }
      }
    
    } else {
      PostfixForm[n] = formul[i];
      n++;
    }
  }
  SIZEP = n;



}
