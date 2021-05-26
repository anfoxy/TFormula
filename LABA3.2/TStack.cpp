#include "TStack.h"

TStack::TStack(int Size) {// �����������
  DataCount = 0;
  if (Size == 0) { Size = MaxMemSize; }
  MemSize = Size;
  pMem = new TELEM[MemSize];
  Hi = -1;
}

void TStack::Print() {
  for (int i = 0; i < DataCount; i++) cout << pMem[i] << endl;

TStack :: ~TStack() { //����������
  delete[]pMem;
}

int TStack::GetNextIndex(int index) { // �������� ��������� ������
  return ++index;
}

int TStack::IsEmpty(void) const { return DataCount == 0; }

int TStack::IsFull(void) const { return DataCount == MemSize; }

void TStack::Put(const TELEM &Val) { // �������� ��������
  Hi = GetNextIndex(Hi);
  pMem[Hi] = Val;
  DataCount++;
}

TELEM TStack::Get(void) { // ������� ��������
  DataCount--;
  return pMem[Hi--];
}

TELEM TStack::End(void) { // ������� ��������
  TELEM n = pMem[Hi];
  return n;
}