/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_02_element_access.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:14:12 by gkintana          #+#    #+#             */
/*   Updated: 2022/09/08 17:55:16 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector_templates.hpp>

int main() {
	srand(time(NULL));

	vectorTester test;
	std::cout << PURPLE "At Tests" DEFAULT << std::endl;
	{
		ft::vector<int> ft_vec;
		std::vector<int> std_vec;
		test.pushLoop(ft_vec, std_vec, 42);
		test.compareAt(ft_vec, std_vec);
		test.printTestResults("At Tests    ");
	}

	return 0;
}
