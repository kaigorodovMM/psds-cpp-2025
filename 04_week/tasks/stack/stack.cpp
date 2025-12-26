#include <vector>


class Stack {
    public:
        void Push(int  value);
        bool Pop();
        int& Top();
        const int& Top() const;
        bool Empty() const;
        size_t Size() const;
        void Clear();
        void Swap(Stack& other);
        bool operator==(const Stack& other) const;
        bool operator!=(const Stack& other) const;
    private:
        std::vector<int> vec;
};


void Stack::Push(int value) {
    vec.push_back(value);
}
bool Stack::Pop() {
    if (vec.empty()) {
        return false;
    }
    vec.pop_back();
    return true;
}

bool Stack::Empty() const {
    return vec.empty();
}

int& Stack::Top(){
    return vec.back();
}

const int& Stack::Top() const {
    return vec.back();
}



size_t Stack::Size() const{
    return vec.size();
}

void Stack::Clear() {
    vec.clear();
}

void Stack::Swap(Stack& other) {
    vec.swap(other.vec);
}

bool Stack::operator==(const Stack& other) const {
    return vec == other.vec;
}
bool Stack::operator!=(const Stack& other) const {
    return !(*this == other);
}



