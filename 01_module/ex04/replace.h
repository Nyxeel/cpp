/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 01:23:01 by pjelinek          #+#    #+#             */
/*   Updated: 2026/02/13 03:58:12 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_H
#define REPLACE_H

#include "fstream"
#include "string"

void replaceInput(std::ifstream &file, std::string filename,
				  const std::string str,
				  const std::string str2);

#endif /* REPLACE_H */
