#include <stdexcept>
#include <vector>

std::vector<int> Unique(std::vector<int> vec_in) {
    size_t size_in = size(vec_in);
    std::vector<int> vec_out;
    vec_out.reserve(size_in);
    for (auto elem : vec_in) {
        bool elem_in_in = false;
        for (auto elem_out : vec_out){
            if (elem_out == elem){
                elem_in_in = true;
                break;
            }
            else if (elem_out > elem){
                break;
            }
        }
        if (elem_in_in == false){
            vec_out.push_back(elem);
        }
    }
    vec_out.shrink_to_fit();
    return vec_out;
}
