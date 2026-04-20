/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replaceInput.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 01:22:13 by pjelinek          #+#    #+#             */
/*   Updated: 2026/04/19 18:59:57 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "fstream"

void replaceInput(std::ifstream &inFile, std::ofstream &outFile,
				  const std::string str,
				  const std::string str2)
{

	std::string line;

	while (std::getline(inFile, line))
	{
		std::string finalString;
		std::string before;
		size_t end;

		while (line.size())
		{
			end = line.find(str);

			if (end == std::string::npos) // if find returns size_t(-1)
			{
				finalString.append(line + '\n');
				break;
			}
			before = line.substr(0, end);
			line = line.substr(end + str.size(), line.size());
			finalString.append(before + str2);
		}
		if (end != std::string::npos) // if find returns size_t(-1)
		{
			finalString += "\n";
		}
		outFile << finalString;
		//std::cout << finalString;
	}
}
