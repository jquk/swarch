#include "BinarySearch.h"
#include <iostream>
#include <cstdlib>

int main(int argc, char *argv[])
{
  BinarySearch binarySearch;// = new BinarySearch();
  binarySearch.setArray(0, 200);

  int target = atoi(argv[1]);
  unsigned int index = binarySearch.getIndexOf(target);
  std::cout << "index: " << index << std::endl;
  return 0;
}
