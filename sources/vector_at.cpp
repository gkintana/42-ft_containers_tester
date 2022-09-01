/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_at.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:14:12 by gkintana          #+#    #+#             */
/*   Updated: 2022/09/01 15:46:29 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector_templates.hpp>

int main() {
	srand(time(NULL));
	std::cout << PURPLE "Vector At Tests" DEFAULT << std::endl
	          << "Int Vector: ";
	{
		ft::vector<int> ft_vec;
		std::vector<int> std_vec;
		vectorPushLoop(ft_vec, std_vec, 15);
		compareAtOutput(ft_vec, std_vec);
	}

	return 0;
}
