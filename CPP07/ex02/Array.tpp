//
// Created by Vojtěch Parkán on 21.09.2025.
//

// Default constructor - creates empty array
template<typename T>
Array<T>::Array() : _data(nullptr), _size(0) {
}

// Parameterized constructor - creates array of n elements
template<typename T>
Array<T>::Array(unsigned int n) : _data(new T[n]()), _size(n) {
}

// Copy constructor
template<typename T>
Array<T>::Array(const Array<T>& other) : _data(new T[other._size]), _size(other._size) {
    for (unsigned int i = 0; i < _size; i++) {
        _data[i] = other._data[i];
    }
}

// Copy assignment operator
template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
    if (this != &other) {
        delete[] _data;
        _size = other._size;
        _data = new T[_size];
        for (unsigned int i = 0; i < _size; i++) {
            _data[i] = other._data[i];
        }
    }
    return *this;
}

// Destructor
template<typename T>
Array<T>::~Array() {
    delete[] _data;
}

// Non-const subscript operator with bounds checking
template<typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= _size) {
        throw std::out_of_range("Index out of bounds");
    }
    return _data[index];
}

// Const subscript operator with bounds checking
template<typename T>
const T& Array<T>::operator[](unsigned int index) const {
    if (index >= _size) {
        throw std::out_of_range("Index out of bounds");
    }
    return _data[index];
}

// Size getter
template<typename T>
unsigned int Array<T>::size() const {
    return _size;
}
