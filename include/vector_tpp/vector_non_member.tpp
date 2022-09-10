/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_non_member.tpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 22:22:30 by gkintana          #+#    #+#             */
/*   Updated: 2022/09/10 23:20:17 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
void vectorTester::relationalOper(ft::vector<T> &ft1, std::vector<T> &std1,
                                  ft::vector<T> &ft2, std::vector<T> &std2,
                                  size_t option) {
	if (option == EQUAL) {
		(ft1 == ft2) == (std1 == std2) ? addOK() : addKO();
	} else if (option == NOT_EQUAL) {
		(ft1 != ft2) == (std1 != std2) ? addOK() : addKO();
	} else if (option == LESS) {
		(ft1 < ft2) == (std1 < std2) ? addOK() : addKO();
	} else if (option == LESS_EQUAL) {
		(ft1 <= ft2) == (std1 <= std2) ? addOK() : addKO();
	} else if (option == GREATER) {
		(ft1 > ft2) == (std1 > std2) ? addOK() : addKO();
	} else if (option == GREATER_EQUAL) {
		(ft1 >= ft2) == (std1 >= std2) ? addOK() : addKO();
	} else {
		std::cerr << RED "Invalid option. Skipping test case" DEFAULT << std::endl;
		return;
	}
}
