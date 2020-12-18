#include "Data.h"
template<typename T>
Data<T>::Data(const T& value) {
	m_value = value;
}
template<class T>
const T& Data<T>::get() {
    return m_value;
}
template<class T>
void Data<T>::set(const T& value) {
    m_value = value;
}
template<class T>
Data<T>::~Data() { 

}