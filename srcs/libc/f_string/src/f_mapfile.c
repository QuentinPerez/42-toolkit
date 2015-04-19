/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_mapfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 22:26:46 by qperez            #+#    #+#             */
/*   Updated: 2015/04/19 14:08:17 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/mman.h>
#include <fcntl.h>
#include <f_error/m_error.h>
#include <stdint.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdbool.h>

char	*uf_mapfile(const char *name, size_t *len,
					int map_flags, bool private)
{
	char		*ret;
	int			fd;
	struct stat	st;

	if ((fd = open(name, O_RDWR)) == -1)
		return ((char *)M_ERROR(0, "An error has occured"));
	if (fstat(fd, &st) != 0)
	{
		close(fd);
		return ((char *)M_ERROR(0, "The file parameter are not"
		"available"));
	}
	if ((ret = mmap(NULL, st.st_size, map_flags,
		private == true ? MAP_PRIVATE : MAP_SHARED, fd, 0)) == MAP_FAILED)
	{
		close(fd);
		return ((char *)M_ERROR(0, "Could'nt map the file"));
	}
	*len = st.st_size;
	close(fd);
	return (ret);
}

bool	uf_unmapfile(void *addr, size_t len)
{
	return (munmap(addr, len) != 0);
}
