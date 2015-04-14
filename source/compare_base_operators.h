#include "../headers/compare_base.h"

namespace compare {

template<typename T>
compare_base<T>& compare_base<T>::operator =(const T& input) {
	data = input;
}

}
