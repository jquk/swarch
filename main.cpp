#include "BinarySearch.h"
#include <iostream>
#include <cstdlib>

/*
*
*/
int main(int argc, char *argv[])
{
  int target = atoi(argv[1]);
  int lower_boundary = atoi(argv[2]);
  int upper_boundary = atoi(argv[3]);
  BinarySearch binarySearch(lower_boundary, upper_boundary);
  // binarySearch.setArray(atoi(argv[2]), atoi(argv[3]));
  unsigned int index = binarySearch.getIndexOf(target);
  std::cout << "index: " << index << std::endl;
  return 0;
}
