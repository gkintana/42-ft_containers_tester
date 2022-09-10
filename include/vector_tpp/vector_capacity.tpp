/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_capacity.tpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 12:37:36 by gkintana          #+#    #+#             */
/*   Updated: 2022/09/10 13:21:37 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
void vectorTester::resizeAndCompare(ft::vector<T> &ft,std::vector<T> &std,
                                    size_t new_size, typename identity<T>::type value) {
	ft.resize(new_size, value);
	std.resize(new_size, value);
	compareVectors(ft, std);
}

template <typename T>
void vectorTester::reserveAndCompare(ft::vector<T> &ft,std::vector<T> &std,
                                     size_t new_cap) {
	ft.reserve(new_cap);
	std.reserve(new_cap);
	compareVectors(ft, std);
}

template <typename T>
void vectorTester::capacityExceptions(ft::vector<T> &ft,std::vector<T> &std,
                                      size_t new_size, bool is_resize) {
	bool ft_exception = false,
	     std_exception = false;

	try {
		is_resize ? ft.resize(new_size) : ft.reserve(new_size);
	} catch (std::exception &e) {
		ft_exception = true;
	}

	try {
		is_resize ? std.resize(new_size) : std.reserve(new_size);
	} catch (std::exception &e) {
		std_exception = true;
	}

	ft_exception == std_exception ? addOK() : addKO();
}
