#include <stdexcept>


int* FindLastElement(const int* begin, const int* end, bool (*predicate) (int)) {
    if (begin == nullptr or end == nullptr or begin >= end){
        return const_cast<int*>(end);
    }
    int* result = const_cast<int*>(end);
    int* p = const_cast<int*>(begin);
    while (p < end){
        if(predicate(*p)){
            result = p;
        }
        p++;
    }
    return result;
}