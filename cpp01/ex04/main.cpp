/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:48:43 by diodos-s          #+#    #+#             */
/*   Updated: 2024/09/13 12:03:26 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Invalid number of arguments" << std::endl;
		return 1;
	}
	std::ifstream inFile;
	std::string s1;
	std::string s2;

	inFile.open(argv[1]);
	s1 = argv[2];
	s2 = argv[3];
	if (inFile.fail())
	{
		std::cout << "Error opening file." << std::endl;
		return 1;
	}
	std::string line;
	getline(inFile, line);
	size_t pos = 0;
	while ((pos = line.find(s1, pos)) != std::string::npos)
	{
		line.erase(pos, s1.length());
		line.insert(pos, s2);
		pos += s2.length();
	}
	inFile.close();

	std::ofstream outFile;
	outFile.open("file.replace.txt");
	outFile << line << std::endl;
	outFile.close();

	return 0;
}
