#include <stdexcept>
#include <vector>


std::vector<size_t> FindAll(std::vector<int>& vec, bool (*func) (int)) {
    std::vector<size_t> vec_out;
    if (vec.empty() or func == nullptr){
        return vec_out;
    }
    vec_out.reserve(size(vec));
    size_t size_vec = size(vec);
    for (size_t i = 0; i < size_vec; ++i) {
        if (func(vec[i])){
            vec_out.push_back(i);
        }
    }
    vec_out.shrink_to_fit();
    return vec_out;
}

const std::vector<size_t> FindAll(const std::vector<int>& vec, bool (*func) (int)) {
    std::vector<size_t> vec_out;
    if (vec.empty() or func == nullptr){
        return vec_out;
    }
    vec_out.reserve(size(vec));
    size_t size_vec = size(vec);
    for (size_t i = 0; i < size_vec; ++i) {
        if (func(vec[i])){
            vec_out.push_back(i);
        }
    }
    vec_out.shrink_to_fit();
    return vec_out;
}
