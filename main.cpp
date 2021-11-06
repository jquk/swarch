#include "BinarySearch.h"
#include <iostream>
#include <cstdlib>
#include <cstring>

/*
* The first parameter must be the algorithm name in Pascal notation style,
* and the rest of the parameters are algorithm-dependent.
* argc represents the number of input parameters stored in the array argv.
* argv[0] contains the name of the current program.
* argv[1] must contain the name of the algorithm to be executed.
* argv[n], being 2 < n < inf, contains the list of input parameters necessary for the chosen algorithm.
*/
int main(int argc, char *argv[])
{
  std::cout << "Running the program " << argv[0] << ", to use the algorithm " << argv[1] << " passing it " << (argc - 2) << " parameters." << std::endl;

  // Add any algorithm to the following chain of if-else blocks.
  if ((std::string(argv[1]) == "BinarySearch") && (argc == 5)) {
    int target = atoi(argv[2]);
    int lower_boundary = atoi(argv[3]);
    int upper_boundary = atoi(argv[4]);
    BinarySearch binarySearch(lower_boundary, upper_boundary);
    int index = binarySearch.getIndexOf(target);
    std::cout << "index: " << index << std::endl;
  } else {
    std::cout << "Wrong or not enough input parameters.\nThe first parameter must be the algorithm name in Pascal notation style, and the rest of the parameters are algorithm-dependent." << std::endl;
  }

  return 0;
}
