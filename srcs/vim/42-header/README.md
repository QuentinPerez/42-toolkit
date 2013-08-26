42-toolkit	42-header
==========

This plugin generate header like 42.

Auto dispatch:

    - ./configure

Vim setting you can source file:

    - echo "source /path/to/make-header.vim" >> $HOME/.vimrc

Or you can put file to $HOME/.vim/plugin:

    - cp make-header.vim $HOME/.vim/plugin

Export variable env:

    - echo "export MAIL42=YourMail" >> YourProfileFile
    - echo "export USER42=YourUser" >> YourProfileFile

Example:
<code>
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/26 15:43:21 by qperez            #+#    #+#             */
/*   Updated: 2013/08/26 15:43:21 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
</code>

## License

42-toolkit is available under the [GNU General Public License, version 3](LICENSE).
