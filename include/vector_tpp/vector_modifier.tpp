/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_modifier.tpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 10:55:37 by gkintana          #+#    #+#             */
/*   Updated: 2022/09/11 23:06:26 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
void vectorTester::clearVectors(ft::vector<T> &ft, std::vector<T> &std) {
	ft.clear();
	std.clear();
	compareVectors(ft, std);
}

template <typename T>
void vectorTester::singleInsert(ft::vector<T> &ft, std::vector<T> &std, size_t option,
                                size_t offset, typename identity<T>::type value) {
	if (option == BEGIN) {
		ft.insert(ft.begin() + offset, value);
		std.insert(std.begin() + offset, value);
	} else if (option == END) {
		ft.insert(ft.end() - offset, value);
		std.insert(std.end() - offset, value);
	}
	compareVectors(ft, std);
}

template <typename T>
void vectorTester::rangedInsert(ft::vector<T> &ft, std::vector<T> &std, size_t option,
                                size_t offset, size_t n, typename identity<T>::type value) {
	if (option == BEGIN) {
		ft.insert(ft.begin() + offset, n, value);
		std.insert(std.begin() + offset, n, value);
	} else if (option == END) {
		ft.insert(ft.end() - offset, n, value);
		std.insert(std.end() - offset, n, value);
	}
	compareVectors(ft, std);
}

template <typename T, typename InputIterator>
void vectorTester::iteratorInsert(ft::vector<T> &ft, std::vector<T> &std, size_t option,
                                  size_t offset, InputIterator first, InputIterator last) {
	if (option == BEGIN) {
		ft.insert(ft.begin() + offset, first, last);
		std.insert(std.begin() + offset, first, last);
	} else if (option == END) {
		ft.insert(ft.end() - offset, first, last);
		std.insert(std.end() - offset, first, last);
	}
	compareVectors(ft, std);
}

template <typename T>
void vectorTester::singleErase(ft::vector<T> &ft, std::vector<T> &std, size_t option,
                               size_t offset) {
	if (option == BEGIN) {
		ft.erase(ft.begin() + offset);
		std.erase(std.begin() + offset);
	} else if (option == END) {
		ft.erase(ft.end() - offset);
		std.erase(std.end() - offset);
	}
	compareVectors(ft, std);
}

template <typename T>
void vectorTester::rangedErase(ft::vector<T> &ft, std::vector<T> &std, size_t option1,
                               size_t offset1, size_t option2, size_t offset2) {
	size_t size_before_erase = ft.size();

	if (option1 == BEGIN && option2 == BEGIN) {
		ft.erase(ft.begin() + offset1, ft.begin() + offset2);
		std.erase(std.begin() + offset1, std.begin() + offset2);
	} else if (option1 == BEGIN && option2 == END) {
		ft.erase(ft.begin() + offset1, ft.end() - offset2);
		std.erase(std.begin() + offset1, std.end() - offset2);
	} else if (option1 == END && option2 == BEGIN) {
		ft.erase(ft.end() - offset1, ft.begin() + offset2);
		std.erase(std.end() - offset1, std.begin() + offset2);
	} else if (option1 == END && option2 == END) {
		ft.erase(ft.end() - offset1, ft.end() - offset2);
		std.erase(std.end() - offset1, std.end() - offset2);
	}
	compareVectors(ft, std);

	/**
	** @brief    encountered some segmentation faults when using the rangedErase multiple times, in
	**           order to fix that issue I added this for loop to fill back the values that were erased
	**           and allow continuous use of rangedErase without having to reconstruct the vector
	*/
	for (size_t i = ft.size(); i < size_before_erase; i++) {
		size_t random_value = std::rand() % 123456789;
		ft.push_back(random_value);
		std.push_back(random_value);
	}
}

/**
** @brief    pushes random values to both ft and std containers
**
** @param ft     address of container with ft namespace
** @param std    address of container with std namespace
** @param len    amount of times push_back will be used
*/
template <typename T>
void vectorTester::pushLoop(ft::vector<T> &ft, std::vector<T> &std, size_t len) {
	for (size_t i = 0; i < len; i++) {
		size_t random_value = std::rand() % 123456789;
		ft.push_back(random_value);
		std.push_back(random_value);
		compareVectors(ft, std);
	}
}

/**
** @brief    pushes the exact same string to both ft and std containers according to
**           the size of len
**
** @param str    std::string to be pushed to the ft and std vectors
*/
template <typename T>
void vectorTester::pushLoop(ft::vector<T> &ft, std::vector<T> &std, size_t len,
                            std::string str) {
	for (size_t i = 0; i < len; i++) {
		ft.push_back(str);
		std.push_back(str);
		compareVectors(ft, std);
	}
}

template <typename T>
void vectorTester::popLoop(ft::vector<T> &ft, std::vector<T> &std, size_t len) {
	for (size_t i = 0; i < len; i++) {
		ft.pop_back();
		std.pop_back();
		compareVectors(ft, std);
	}
}
