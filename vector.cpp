template <typename T>
class Vector {
public:

    Vector(): data_(nullptr), size_(0), cap_(0) {}

    size_t Size() const {
        return size_;
    }

    bool IsEmpty() const {
        return size_ == 0;
    }

    size_t Capacity() const {
        return cap_;
    }

    ~Vector() {
        delete[] data_;
    }

    T& operator[](size_t i) {
        return data_[i];
    }

    const T& operator[](size_t i) const {
        return data_[i];
    }

    void PushBack(const T& value) {
        if (size_ == cap_) {
            int new_cap = (cap_ == 0 ? 1 : cap_ * 2);
            T* new_data = new T[new_cap];
            for (size_t i = 0; i < size_; i++) {
                new_data[i] = data_[i];
            }
            delete[] data_;
            data_ = new_data;
            cap_ = new_cap;
        }
        data_[size_++] = value;
    }

    void PopBack() {
        size_--;
    }

    void Clear() {
        size_ = 0;
    }

    void Reserve(size_t new_cap) {
        if (new_cap > cap_) {
            T* new_data = new T[new_cap];
            for (size_t i = 0; i < size_; i++) {
                new_data[i] = data_[i];
            }
            delete[] data_;
            data_ = new_data;
            cap_ = new_cap;
        }
            
    }

    void Resize(size_t new_size) {
        while (size_ < new_size) {
            PushBack(T{});
        }
        while (size_ > new_size) {
            PopBack();
        }
    }

    void ShrinkToFit() {
        if (cap_ == size_) {
            return;
        }
        T* new_data = new T[size_];
        for (size_t i = 0; i < size_; i++) {
            new_data[i] = data_[i];
        }
        delete[] data_;
        data_ = new_data;
        cap_ = size_;
    }
    
    Vector(const Vector& other) {
        size_ = other.size_;
        cap_ = other.cap_;
        if (cap_ != 0) {
            data_ = new T[cap_];
            for (size_t i = 0; i < size_; i++) {
                data_[i] = other.data_[i];
            }
        } else {
            data_ = nullptr;
        }
    }

    Vector& operator=(const Vector& other) {
        if (this == &other) {
            return *this;
        }
        delete[] data_;
        size_ = other.size_;
        cap_ = other.cap_;
        if (cap_ != 0) {
            data_ = new T[cap_];
            for (size_t i = 0; i < size_; i++) {
                data_[i] = other.data_[i];
            }
        }
        return *this;
    }

    bool operator==(const Vector& other) const {
        if (size_ != other.size_) {
            return false;
        }
        for (size_t i = 0; i < size_; i++) {
            if (data_[i] != other.data_[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const Vector& other) const {
        return !(*this == other);
    }

    T* begin() {
    return data_;
}

    T* end() {
        return data_ + size_;
    }

    const T* begin() const {
        return data_;
    }

    const T* end() const {
        return data_ + size_;
    }

private:

    T* data_;
    size_t size_;
    size_t cap_;

};