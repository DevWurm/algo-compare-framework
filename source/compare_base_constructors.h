#include "../headers/compare_base.h"
#include <string>

using std::string;

namespace compare {

template<typename T>
compare_base<T>::compare_base() {
	type = typeid(T).name();
}

template<typename T>
compare_base<T>::compare_base(const T& input):data(input) {
	type = typeid(T).name();
}

}
