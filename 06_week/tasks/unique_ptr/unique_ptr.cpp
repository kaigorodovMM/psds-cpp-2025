#include <string>


class UniquePtr {
    public:
        UniquePtr() noexcept : str_(nullptr) {};
        UniquePtr(std::string* str) noexcept : str_(str) {};
        UniquePtr(UniquePtr&& other) noexcept : str_(other.str_){ // конструктор перемещения
            other.str_ = nullptr; 
        }
        ~UniquePtr() {delete str_;};
        // Оператор присваивания перемещением
        UniquePtr& operator=(UniquePtr&& other) noexcept {
            if (str_ != other.str_) { // self assignment check
                delete str_; // delete current resource
                str_ = other.str_; // copy resource pointer from other
                other.str_ = nullptr; // other must be valid and don't result in double free
            }
            return *this;
        }
        std::string& operator*() noexcept {
            return *str_;
        }
        std::string* operator->() noexcept {
            return str_;
        }
        std::string* Get() noexcept {
            return str_;
        }
        std::string* Release() noexcept {
            std::string* temp = str_;
            str_ = nullptr;
            return temp;
        }
        void Reset(std::string* new_str) noexcept {
            delete str_;
            str_ = new_str;
        }
        void Reset() noexcept {
            delete str_;
            str_ = nullptr;
        }
        void Swap(UniquePtr& other) noexcept {
        std::string* temp = str_;
        str_ = other.str_;
        other.str_ = temp;
        }
        operator bool() const noexcept {
            return str_ != nullptr;
        }

    private:
        std::string* str_ = nullptr;
};
UniquePtr MakeUnique(const std::string& str){
    UniquePtr new_ptr(new std::string(str));
    return new_ptr;
}
UniquePtr MakeUnique(std::string&& str){
    return UniquePtr(new std::string(std::move(str)));
}
void Swap(UniquePtr& ptr1, UniquePtr& ptr2){
    ptr1.Swap(ptr2);
}