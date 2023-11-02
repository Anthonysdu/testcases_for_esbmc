#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct InnerStruct {
  int innerValue;
  char innerString[20];
};

struct ComplexStruct {
  int intValue;
  double doubleValue;
  struct InnerStruct inner;
};

int main() {
  const int arraySize = 10;
  struct ComplexStruct complexArray[arraySize];
  
  for (int i = 0; i < arraySize; i++) {
    complexArray[i].intValue = rand() % 100;
    complexArray[i].doubleValue = (double)rand() / RAND_MAX;
    complexArray[i].inner.innerValue = rand() % 50;
    strcpy(complexArray[i].inner.innerString, "Hello");
  }

  struct ComplexStruct copiedArray[arraySize];
  for (int i = 0; i < arraySize; i++) {
    memcpy(&copiedArray[i], &complexArray[i], sizeof(struct ComplexStruct));
  }
  
  for (int i = 0; i < arraySize; i++) {
    printf("Array[%d]:\n", i);
    printf("  intValue: %d\n", copiedArray[i].intValue);
    printf("  doubleValue: %lf\n", copiedArray[i].doubleValue);
    printf("  innerValue: %d\n", copiedArray[i].inner.innerValue);
    printf("  innerString: %s\n", copiedArray[i].inner.innerString);
    assert(1);
  }

  assert(arraySize == 10);

  for (int i = 0; i < arraySize; i++) {
    assert(complexArray[i].intValue >= 0 && complexArray[i].intValue < 100);
    assert(complexArray[i].doubleValue >= 0.0 &&
           complexArray[i].doubleValue <= 1.0);
    assert(complexArray[i].inner.innerValue >= 0 &&
           complexArray[i].inner.innerValue < 50);
    assert(strcmp(complexArray[i].inner.innerString, "Hello") == 0);
  }

  assert(complexArray[5].intValue == 150);
  assert(complexArray[8].doubleValue > 2.0);
  assert(complexArray[2].inner.innerValue < -5);
  assert(strcmp(complexArray[6].inner.innerString, "Goodbye") == 0);

  return 0;
}

