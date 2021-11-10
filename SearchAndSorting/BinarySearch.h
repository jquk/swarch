#include <vector>

/*
* Implementation of the Binary Search algorithm.
*/
class BinarySearch {
public:
  // constructor
  BinarySearch(const int lower_value, const int upper_value);
  // destructor
  ~BinarySearch();

  // member functions
  const int getIndexOf(const int target);

private:
  // member variables
  int m_lower_value;
  int m_upper_value;
  unsigned int m_int_arrayLength;
};
