#include "../headers/compare_base.h"

namespace compare {

template<typename T>
compare_base<T>::~compare_base(){}; //empty virtual constructor to securely call the destructor of derivated classes

}
