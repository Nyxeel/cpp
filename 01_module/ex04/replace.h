/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 01:23:01 by pjelinek          #+#    #+#             */
/*   Updated: 2026/02/13 12:05:05 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_H
#define REPLACE_H

#include "fstream"
#include "string"

void replaceInput(std::ifstream &file, std::ofstream &outFile,
				  const std::string str,
				  const std::string str2);

#endif /* REPLACE_H */
