#include <stdexcept>


double ApplyOperations(double a, double b, double (**arr_func)(double, double), size_t size) {
    double result = 0;
    if (size == 0 or arr_func == nullptr){
        return 0.0;
    }
    for (size_t i = 0; i < size; ++i){
        if (arr_func[i] != nullptr){
            result += arr_func[i](a, b);
        }
    }
    return result;
}