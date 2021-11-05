class BinarySearch {
public:
    // initialize
    BinarySearch();
    BinarySearch(const int target);

    // encryption related functions
    const unsigned int getIndexOf(const int target);

    void setArray(const int lower, const int higher);

private:
    /*const*/ int target;//if it is const, it must be initialized at construction time.
    int m_int_array[1000];
    unsigned int m_int_arrayLength;
    unsigned int lower_boundary;
    unsigned int higher_boundary;
};
