/*
* Binary Search Algorithm - Iterative and recursive implementation.
*
* Problem description:
* Given a "sorted" array of n integers and a target value, determine if the target exists in the array in logarithmic time,
* using the binary search algorithm. If the target exists in the array, return the array index.
*
* Note 1: Logarithmic time: O(log n), means that execution time grows in proportion to the logarithm of the input size:
* as an example, if 10 items takes at most some amount of time x , and 100 items takes at most, say, 2x , and 10,000 items takes at most 4x.
*
* Note 2: If a linear search is implemented, sequentially checking each array element of the array,
* then the worst-case time complexity is O(n), as it takes at most n comparisons, where n is the size of the input.
* With the linear search, it is not possible to take advantage of the fact that the array is sorted out.
*
* Binary search is a "Divide and Conquer algorithm", that takes advantage of the fact that the array is sorted out,
* to reduce the searching space by half on each iteration, discarding the half that doesn't contain the target.
*/

#include "BinarySearch.h"
#include <iostream>
#include <math.h>/* round, floor, ceil, trunc */


/*
* Constructor.
* The lower_value and upper_value input parameters are used,
* to create a sorted array in which the Binary Search algorithm
* will try to find a target value passed to the function getIndexOf.
*/
BinarySearch::BinarySearch(const int lower_value, const int upper_value)
: lower_value(lower_value), upper_value(upper_value), m_int_arrayLength(upper_value - lower_value)
{
}


/*
* Destructor
*/
BinarySearch::~BinarySearch() { }


/*
* Public member function.
* Returns the index of 'target' in the sorted array defined with the construction parameters.
* Returns -1 if the target is not found in the sorted array.
*/
const int BinarySearch::getIndexOf(const int target)
{
  unsigned int retVal;
  int m_int_array[this->m_int_arrayLength];
  unsigned int lower_boundary = 0;
  unsigned int upper_boundary = this->m_int_arrayLength;
  unsigned int old_lower_boundary = lower_boundary + 1;//ensure they are different at the beginning, to not break the while loop.
  unsigned int old_upper_boundary = upper_boundary - 1;//ensure they are different at the beginning, to not break the while loop.

  for (int i = 0; i <= this->m_int_arrayLength; i++) {
    m_int_array[i] = this->lower_value + i;
  }

  int counter = 0;
  unsigned int index = (unsigned int)(this->m_int_arrayLength/2);

  // the second exit condition is just to ensure it will finish.
  while ((m_int_array[index] != target) && ((old_lower_boundary != lower_boundary) && (old_upper_boundary != upper_boundary))/*(counter < this->m_int_arrayLength)*/) {
    if (target < m_int_array[index]) {
      old_upper_boundary = upper_boundary;
      upper_boundary = index;
      std::cout << "target: " << target << " < array[" << index << "]-->" << m_int_array[index] << ", {lower, upper}={" << lower_boundary << ", " << upper_boundary << "}" << ", counter: " << counter << std::endl;
    } else if (target > m_int_array[index]) {
      old_lower_boundary = lower_boundary;
      lower_boundary = index;
      std::cout << "target: " << target << " > array[" << index << "]-->" << m_int_array[index] << ", {lower, upper}={" << lower_boundary << ", " << upper_boundary << "}" << ", counter: " << counter << std::endl;
    }
    index = round((upper_boundary + lower_boundary)/2);
    counter++;
  }
  std::cout << "target: " << target << " == array[" << index << "]-->" << m_int_array[index] << ", {lower, upper}={" << lower_boundary << ", " << upper_boundary << "}" << ", counter: " << counter << std::endl;
  if (m_int_array[index] == target) {
    retVal = index;
  } else {
    std::cout << "The target is not in the sorted array\n";
    retVal = -1;
  }
  return retVal;
}
