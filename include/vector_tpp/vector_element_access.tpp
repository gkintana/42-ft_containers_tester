/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_element_access.tpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 10:29:11 by gkintana          #+#    #+#             */
/*   Updated: 2022/09/10 10:39:22 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
void vectorTester::KOLoop(ft::vector<T> &ft, std::vector<T> &std) {
	for (size_t i = 0; i < std::max(ft.size(), std.size()); i++) {
		addKO();
	}
}

template <typename T>
void vectorTester::operatorLoop(ft::vector<T> &ft, std::vector<T> &std) {
	if (ft.size() != std.size()) {
		KOLoop(ft, std);				
	} else {
		for (size_t i = 0; i < ft.size(); i++) {
			ft[i] == std[i] ? addOK() : addKO();
		}
	}
}

template <typename T>
void vectorTester::operatorModify(ft::vector<T> &ft, std::vector<T> &std, size_t n,
					typename identity<T>::type value) {
	if (n >= ft.size()) {
		std::cerr << YELLOW "Index (" << n << ") exceeds vector size, and will cause undefined behavior. Skipping Test Case" DEFAULT << std::endl;
		return;
	}
	ft[n] = std[n] = value;
}

template <typename T>
void vectorTester::atLoop(ft::vector<T> &ft, std::vector<T> &std) {
	if (ft.size() != std.size()) {
		KOLoop(ft, std);
	} else {
		for (size_t i = 0; i < ft.size(); i++) {
			ft.at(i) == std.at(i) ? addOK() : addKO();
		}
	}
}

template <typename T>
void vectorTester::atModify(ft::vector<T> &ft, std::vector<T> &std, size_t n,
				typename identity<T>::type value) {
	ft.at(n) = std.at(n) = value;
}

template <typename T>
void vectorTester::atException(ft::vector<T> &ft, std::vector<T> &std, size_t n) {
	try {
		ft.at(n);
		/**
		** @brief    the ft.at(n) above would usually throw an error provided that
		**           n is greater than or equal to ft.size(). However if n is within
		**           range of the vector's size, I will then compare it's value to
		**           the std vector and add an OK or KO accordingly
		*/
		ft.at(n) == std.at(n) ? addOK() : addKO();
	} catch (std::out_of_range &e) {
		addOK();
	}
}

template <typename T>
void vectorTester::compareFrontBack(ft::vector<T> &ft, std::vector<T> &std, bool is_front) {
	/**
	** @brief    added an if statement to check if both the ft and std containers
	**           are empty or not before proceeding with the tests, to ensure that
	**           undefined behavior will not be encountered
	*/
	if (!ft.empty() && !std.empty()) {
		if (is_front) {
			ft.front() == std.front() ? addOK() : addKO();
		} else {
			ft.back() == std.back() ? addOK() : addKO();
		}
	}
}

template <typename T>
void vectorTester::dataLoop(ft::vector<T> &ft, std::vector<T> &std) {
	if (ft.size() != std.size()) {
		KOLoop(ft, std);
	} else {
		T *ft_ptr = ft.data(),
			*std_ptr = std.data();
		for (size_t i = 0; i < ft.size(); i++) {
			*ft_ptr == *std_ptr ? addOK() : addKO();
		}
	}
}

template <typename T>
void vectorTester::dataModify(ft::vector<T> &ft, std::vector<T> &std, size_t n,
				typename identity<T>::type value) {
	if (n >= ft.size()) {
		std::cerr << YELLOW "Index (" << n << ") exceeds vector size, and will cause undefined behavior. Skipping Test Case" DEFAULT << std::endl;
		return;
	}
	T *ft_ptr = ft.data() + n,
		*std_ptr = std.data() + n;
	*ft_ptr = *std_ptr = value;
}

