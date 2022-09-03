/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_05_modifiers.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:26:38 by gkintana          #+#    #+#             */
/*   Updated: 2022/09/03 18:32:29 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector_templates.hpp>

int main() {
	srand(time(NULL));
	std::cout << PURPLE "Vector Push Back Tests" DEFAULT << std::endl
	          << "Char Vector: ";
	resetTestCount();
	{
		ft::vector<char> ft_vec;
		std::vector<char> std_vec;
		vectorPushLoop(ft_vec, std_vec, 42, true, true);
	}

	/*------------------------------------------------------------------------*/

	std::cout << "Int Vector: ";
	resetTestCount();
	{
		ft::vector<int> ft_vec;
		std::vector<int> std_vec;
		vectorPushLoop(ft_vec, std_vec, 42, true, true);
	}

	/*------------------------------------------------------------------------*/

	std::cout << "String Vector: ";
	resetTestCount();
	{
		ft::vector<std::string> ft_vec;
		std::vector<std::string> std_vec;
		vectorPushLoop(ft_vec, std_vec, 42, "Hello World!", true, true);
	}

	return 0;
}
