#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <algorithm>
#include <cmath>
#include <numeric>


namespace libra 
{
    class vector{
        using size_type = size_t;
        using pointer = float*;
        using const_pointer = const pointer;
    
    public:

        size_type size;
        size_type max_size;
        pointer values;
        static constexpr size_type default_size {5};

        vector() : size(0), max_size(default_size), values(nullptr) {}

        vector(size_t n = default_size) : size(n), max_size(n), values(new float[max_size]) {}

        vector(const vector& v) : size(v.size), max_size(v.max_size), values(new float[max_size]) {
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

        bool equals(vector& v) {
            if(this->size == v.size) {
                for(auto i=0; i < size; i++) {
                    if(this->values[i] != v.values[i])
                        return false;
                }
                return true;
            }
            return false;
        }

        void addScalar(float s) {
            std::transform(this->begin(), this->end(), this->begin(), [s](float &f) { return f+s; });
        }

        void subtractScalar(float s) {
            std::transform(this->begin(), this->end(), this->begin(), [s](float &f) { return f-s; });
        }

        void multiplyScalar(float s) {
            std::transform(this->begin(), this->end(), this->begin(), [s](float &f) { return f*s; });
        }

        void divideScalar(float s) {
            std::transform(this->begin(), this->end(), this->begin(), [s](float &f) { return f/s; });
        }

        void raiseToPower(float k) {
            std::transform(this->begin(), this->end(), this->begin(), [k](float &f) { pow(f, k); });
        }

        bool addVector(vector& v) {
            if(this->size == v.size) {
                std::transform (this->begin(), this->end(), v.begin(), this->begin(), std::plus<float>());
                return true;
            }
            return false;
        }

        bool subtractVector(vector v) {
            if(this->size == v.size) {
                std::transform (this->begin(), this->end(), v.begin(), this->begin(), std::minus<float>());
                return true;
            }
            return false;
        }

        bool multiplyVector(vector v) {
            if(this->size == v.size) {
                std::transform (this->begin(), this->end(), v.begin(), this->begin(), std::multiplies<float>());
                return true;
            }
            return false;
        }

        bool divideVector(vector& v) {
            if(this->size == v.size) {
                std::transform (this->begin(), this->end(), v.begin(), this->begin(), std::divides<float>());
                return true;
            }
            return false;
        }

        float dotProduct(vector& v) {
            float output = 0;

            if (this->size == v.size)
            {
                output = std::inner_product(this->begin(), this->end(), v.begin(), 0.0f);
            }

            return output;
        }

        bool orthogonal(vector& v) {
            return this->size == v.size ? this->dotProduct(v) == 0.0f : false;
        }

        void crossProduct(vector v) {

        }

        float magnitude() {
            return std::sqrt(this->squaredMagnitude());
        }

        float squaredMagnitude() {
            float out[this->size];
            std::copy(this->begin(), this->end(), out);
            std::transform(out, out+this->size, out, [](float &f) { pow(f, 2.0f); });
            return std::accumulate(this->begin(), this->end(), 0.0f);
        }

        void normalize(vector v) {
            float mag = this->magnitude();
            this->divideScalar(mag);
        }

    };
};

#endif // VECTOR_HPP