#include "../headers/compare_base.h"

namespace compare {

template<typename T>
bool compare_base<T>::vaildate_results() {
	return (result_algorithm_1 == result_algorithm_2);
}

}
