/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 07:23:36 by jcheron           #+#    #+#             */
/*   Updated: 2025/03/24 07:44:42 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(): Form() {}

ShrubberyCreationForm::ShrubberyCreationForm(
		const std::string &target)
	: Form("ShrubberyCreationForm", target, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(
		const ShrubberyCreationForm &src): Form() {
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(
		const ShrubberyCreationForm &src) {
	if (this != &src) {}
	return *this;
}

void	ShrubberyCreationForm::_executeConcrete() const {
	std::ofstream	file((this->getTarget() + "_shrubbery").c_str());
	if (!file.good())
		throw std::runtime_error("Cannot open file");
	const int num_trees = 5;
	std::string tree[] = {
        "                                                         .                    ",
        "                                              .         ;                    ",
        "                 .              .              ;%     ;;                     ",
        "                   ,           ,                :;%  %;                      ",
        "                    :         ;                   :;%;'     .,               ",
        "           ,.        %;     %;            ;        %;'    ,;                 ",
        "             ;       ;%;  %%;        ,     %;    ;%;    ,%'                  ",
        "              %;       %;%;      ,  ;       %;  ;%;   ,%;'                   ",
        "               ;%;      %;        ;%;        % ;%;  ,%;'                     ",
        "                `%;.     ;%;     %;'         `;%%;.%;'                       ",
        "                 `:;%.    ;%%. %@;        %; ;@%;%'                          ",
        "                    `:%;.  :;bd%;          %;@%;'                            ",
        "                      `@%:.  :;%.         ;@@%;'                             ",
        "                        `@%.  `;@%.      ;@@%;                               ",
        "                          `@%%. `@%%    ;@@%;                                ",
        "                            ;@%. :@%%  %@@%;                                 ",
        "                              %@bd%%%bd%%:;                                  ",
        "                                #@%%%%%:;;                                   ",
        "                                %@@%%%::;                                    ",
        "                                %@@@%(o);  . '                               ",
        "                                %@@@o%;:(.,'                                 ",
        "                            `.. %@@@o%::;                                    ",
        "                               `)@@@o%::;                                    ",
        "                                %@@(o)::;                                    ",
        "                               .%@@@@%::;                                    ",
        "                               ;%@@@@%::;.                                   ",
        "                              ;%@@@@%%:;;;.                                  ",
        "                          ...;%@@@@@%%:;;;;,..                               "
    };
	for (size_t i = 0; i < sizeof(tree) / sizeof(tree[0]); i++) {
		for (int j = 0; j < num_trees; j++)
			file << tree[i] << " ";
		file << std::endl;
	}
	file.close();
}
