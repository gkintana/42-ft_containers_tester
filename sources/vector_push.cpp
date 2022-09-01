/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_push.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:26:38 by gkintana          #+#    #+#             */
/*   Updated: 2022/09/01 14:41:30 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector_templates.hpp>

int main() {
	srand(time(NULL));
	std::cout << PURPLE "Vector Push Back Tests" DEFAULT << std::endl
	          << "Char Vector: ";
	{
		ft::vector<char> ft_vec;
		std::vector<char> std_vec;
		vectorPushLoop(ft_vec, std_vec, 32, 127);
	}

	/*------------------------------------------------------------------------*/

	std::cout << "Int Vector: ";
	{
		ft::vector<int> ft_vec;
		std::vector<int> std_vec;
		vectorPushLoop(ft_vec, std_vec, 0, 42);
	}

	/*------------------------------------------------------------------------*/

	std::cout << "String Vector: ";
	{
		ft::vector<std::string> ft_vec;
		std::vector<std::string> std_vec;
		vectorPushLoop(ft_vec, std_vec, 0, 42, "Hello World!");
	}

	return 0;
}
