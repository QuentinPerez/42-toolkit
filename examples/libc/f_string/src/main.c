/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/28 18:08:55 by qperez            #+#    #+#             */
/*   Updated: 2013/10/30 14:52:43 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <f_string/f_print.h>
#include <f_string/f_string.h>
#include <f_memory/f_memory.h>
#include <stdlib.h>

int	main(int argc, const char **argv)
{
	char	dest[50];
	char	*line;

	uf_memset(dest, '\0', sizeof(dest));
	uf_print_str("Copy Hello to dest\n");
	uf_strcpy(dest, "Hello\n");
	uf_print_str(dest);
	uf_memset(dest, '\0', sizeof(dest));
	uf_print_str("Copy 2 first byte of 42-toolkit\n");
	uf_strncpy(dest, "42-toolkit", 2);
	uf_print_str(dest);
	uf_print_str("\nAdd -tool\n");
	uf_strcat(dest, "-tool");
	uf_print_str(dest);
	uf_print_str("\nAdd kit\n");
	uf_strncat(dest, "kitfoobarhello", 16);
	uf_print_str(dest);
	uf_print_str("\n");
	uf_print_memory(dest, 50);
	uf_print_floating_nbr(345.409, 10);
	uf_print_str("\nCat mode: Quit press q<enter>\n");
	line = uf_getline(0);
	while (line != NULL)
	{
		if (uf_strcmp(line, "q\n") == 0)
		{
			uf_print_str("See you later !\n");
			free(line);
			return (0);
		}
		uf_print_str(line);
		free(line);
		line = uf_getline(0);
	}
	(void)argv;
	(void)argc;
	return (0);
}
