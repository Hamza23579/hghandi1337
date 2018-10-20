# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    main.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yidabdes <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/02 15:26:00 by yidabdes          #+#    #+#              #
#    Updated: 2018/09/02 15:26:12 by yidabdes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

 echo $1 | sed 's/.$//' | sed 's/.$//' > name;
 NAME=$(<name)
echo "
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char const *argv[])
{
		$NAME($2);
		return 0;
}" > main
cat $1 > cm.c;
cat main >> cm.c;
rm main;
rm name;
gcc -o cm cm.c
./cm
rm cm;
rm cm.c;

