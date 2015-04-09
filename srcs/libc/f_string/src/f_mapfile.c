/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_mapfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 22:26:46 by qperez            #+#    #+#             */
/*   Updated: 2014/11/26 22:26:48 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/mman.h>
#include <fcntl.h>
#include <f_error/m_error.h>
#include <stdint.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdbool.h>

char	*uf_mapfile(const char *name, size_t *len)
{
	char		*ret;
	int			fd;
	struct stat	st;

	if ((fd = open(name, O_RDONLY)) == -1)
		return ((char *)M_ERROR((size_t)NULL, "An error has occured"));
	if (fstat(fd, &st) != 0)
	{
		close(fd);
		return ((char *)M_ERROR((size_t)NULL, "The file parameter are not"
		"available"));
	}
	if ((ret = mmap(NULL, st.st_size, PROT_READ,
					MAP_FILE | MAP_PRIVATE, fd, 0)) == MAP_FAILED)
	{
		close(fd);
		return ((char *)M_ERROR((size_t)NULL, "Could'nt map the file"));
	}
	*len = st.st_size;
	close(fd);
	return (ret);
}

bool	uf_unmapfile(void *addr, size_t len)
{
	return (munmap(addr, len) != 0);
}
