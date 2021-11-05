#include <vector>

class BinarySearch {
public:
    // initialize
    BinarySearch(const int lower_value, const int upper_value);
    // BinarySearch(const int target);
    ~BinarySearch();


    // encryption related functions
    const unsigned int getIndexOf(const int target);

    // void setArray(const int lower, const int upper);
    // int *getArray(int *arraySize);

private:
    int lower_value;
    int upper_value;
    unsigned int m_int_arrayLength;
};
