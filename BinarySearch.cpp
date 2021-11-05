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
#include <math.h>       /* round, floor, ceil, trunc */

/*
*
*/
BinarySearch::BinarySearch() { }

/*
*
*/
const unsigned int BinarySearch::getIndexOf(const int target)
{
  int finished = 0;
  int counter = 0;
  unsigned int index = (unsigned int)(this->m_int_arrayLength/2);
  std::cout << "m_int_arrayLength: " << this->m_int_arrayLength << ", target: " << target << ", index: " << index << std::endl;

  while ((finished==0) && (counter < 50)) {
    if (target < m_int_array[index]) {
      this->higher_boundary = index;
      index -= round((this->higher_boundary - this->lower_boundary)/2);
      counter++;
      std::cout << "index: " << index << ", counter: " << counter << ", finished: " << finished << std::endl;
    } else if (target > m_int_array[index]) {
      this->lower_boundary = index;
      index += round((this->higher_boundary - this->lower_boundary)/2);
      // index += (unsigned int)((unsigned int)(this.m_int_arrayLength/2)/2);
      counter++;
      std::cout << "index: " << index << ", counter: " << counter << ", finished: " << finished << std::endl;
    } else {
      finished = 1;
    }
  }
  std::cout << "__\ntarget: " << target << ", index: " << index << ", m_int_array[index]: " << m_int_array[index] << ", counter: " << counter << ", finished: " << finished << std::endl;
  return index;
}



/*
*
*/
// template <typename T> inline T const& BinarySearch::getIndexOf(T const &target) {
//
//    return ;
// }

/*
*
*/
void BinarySearch::setArray(const int lower, const int higher)
{
    for (int i = lower; i <= higher; i++) {
        this->m_int_array[i] = lower + i;
    }
    this->m_int_arrayLength = (higher - lower);
    this->lower_boundary = lower;
    this->higher_boundary = higher;
    std::cout << "m_int_array[0]: " << m_int_array[0] << ", m_int_array[last]: " << m_int_array[(higher - lower)] << std::endl;
}
