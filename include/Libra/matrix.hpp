#ifndef VECTOR_HPP
#define VECTOR_HPP

namespace libra 
{
    class matrix{
        using size_type = size_t;
        using pointer = float*;
        using const_pointer = const pointer;
    
    public:

        size_type size;
        size_type max_size;
        pointer values;
        static constexpr size_type default_size {5};

        matrix() : size(0), max_size(default_size), values(nullptr) {}

        matrix(size_t n = default_size) : size(n), max_size(n), values(new float[max_size]) {}

        matrix(const matrix& v) : size(v.size), max_size(v.max_size), values(new float[max_size]) {
            std::copy(v.values, v.values+v.size, values);
        }

        ~vector() { 
            delete []values;
        }

        pointer begin() {
            return this->values; 
        }

        const_pointer begin() const {
            return this->values;
        }

        pointer end() { 
            return this->values + this->size; 
        }

        const_pointer end() const {
            return this->values + this->size;
        }

        bool empty() const { 
            return size == 0; 
        }

        void clear() { 
            size = 0; 
        }
        
        size_t size() {
            return this->size;
        }

        matrix makeIdentity(unsigned int dim) {

        }

        void convertToIdentity() {

        }

        matrix makeZero(unsigned int dim) {

        }

        void convertToZero() {

        }


    };
};
#endif VECTOR_HPP