#include "TStack.h"

TStack::TStack(int Size) {// конструктор
  DataCount = 0;
  if (Size == 0) { Size = MaxMemSize; }
  MemSize = Size;
  pMem = new TELEM[MemSize];
  Hi = -1;
}

void TStack::Print() {
  for (int i = 0; i < DataCount; i++) cout << pMem[i] << endl;}

TStack :: ~TStack() { //деструктор
  delete[]pMem;
}

int TStack::GetNextIndex(int index) { // получить следующий индекс
  return ++index;
}

int TStack::IsEmpty(void) const { return DataCount == 0; }

int TStack::IsFull(void) const { return DataCount == MemSize; }

void TStack::Put(const TELEM &Val) { // добавить значение
  Hi = GetNextIndex(Hi);
  pMem[Hi] = Val;
  DataCount++;
}

TELEM TStack::Get(void) { // извлечь значение
  DataCount--;
  return pMem[Hi--];
}

TELEM TStack::End(void) { // извлечь значение
  TELEM n = pMem[Hi];
  return n;
}