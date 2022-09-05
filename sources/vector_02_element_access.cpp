/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_02_element_access.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:14:12 by gkintana          #+#    #+#             */
/*   Updated: 2022/09/05 11:08:59 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector_templates.hpp>

int main() {
	srand(time(NULL));
	std::cout << PURPLE "At Tests" DEFAULT << std::endl
	          << "Int Vector: ";
	{
		ft::vector<int> ft_vec;
		std::vector<int> std_vec;
		vectorPushLoop(ft_vec, std_vec, 15, false, true);
		compareAtOutput(ft_vec, std_vec);
	}

	return 0;
}
