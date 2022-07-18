# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/21 14:20:20 by asaboure          #+#    #+#              #
#    Updated: 2022/07/18 18:28:03 by asaboure         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FTVEC	=	ft_vector
FTMAP	=	ft_map
FTSTACK	=	ft_stack

VEC	= 	vector
MAP	=	map
STACK =	stack

VECSRCS	=	main_vector.cpp
MAPSRCS =	main_map.cpp
STACKSRCS =	main_stack.cpp

HPP		=	vector.hpp\
			inc/iterator.hpp\
			inc/type_traits.hpp\
			inc/utils.hpp\
			inc/algorithm.hpp\
			map.hpp\
			inc/utility.hpp\
			inc/BSTiterator.hpp\
			stack.hpp

BONUSOBJS	= ${BONUSSRCS:.c=.o}

CC		= c++

CFLAGS	= -Wall -Wextra -Werror -std=c++98 -Iinc/# -g -O0

DEFINES = -DNAME=std

LOGS	= ./logs

RM		= rm -f

all:	${FTVEC} ${VEC} ${FTMAP} ${MAP} ${FTSTACK} ${STACK} ${LOGS}
	./${FTVEC} > logs/ft_vector.log; ./${VEC} > logs/vector.log; ./${FTMAP} > logs/ft_map.log; ./${MAP} > logs/map.log; ./${FTSTACK} > logs/ft_stack.log; ./${STACK} > logs/stack.log; 
	
${LOGS}:
	mkdir ${LOGS}

${FTVEC}: ${VECSRCS} ${HPP}
	${CC} ${CFLAGS} -o ${FTVEC} ${VECSRCS}

${VEC}: ${VECSRCS}
		${CC} ${CFLAGS} ${DEFINES} -o ${VEC} ${VECSRCS}
		
${FTMAP}: ${MAPSRCS} ${HPP}
	${CC} ${CFLAGS} -o ${FTMAP} ${MAPSRCS}

${MAP}: ${MAPSRCS}
		${CC} ${CFLAGS} ${DEFINES} -o ${MAP} ${MAPSRCS}

${FTSTACK}: ${STACKSRCS} ${HPP}
	${CC} ${CFLAGS} -o ${FTSTACK} ${STACKSRCS}

${STACK}: ${STACKSRCS}
		${CC} ${CFLAGS} ${DEFINES} -o ${STACK} ${STACKSRCS}

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

bonus:

clean:
	 ${RM} ${OBJS}

fclean:	clean
	${RM} ${FTVEC} ${VEC} ${FTMAP} ${MAP} ${FTSTACK} ${STACK}

re:		fclean all

coffee:
	@clear
	@echo ""
	@echo "                   ("
	@echo "	                     )     ("
	@echo "               ___...(-------)-....___"
	@echo '           .-""       )    (          ""-.'
	@echo "      .-''''|-._             )         _.-|"
	@echo '     /  .--.|   `""---...........---""`   |'
	@echo "    /  /    |                             |"
	@echo "    |  |    |                             |"
	@echo "     \  \   |                             |"
	@echo "      '\ '\ |                             |"
	@echo "        '\ '|                             |"
	@echo "        _/ /\                             /"
	@echo "       (__/  \                           /"
	@echo '    _..---""` \                         /`""---.._'
	@echo " .-'           \                       /          '-."
	@echo ":               '-.__             __.-'              :"
	@echo ':                  ) ""---...---"" (                :'
	@echo "\'._                '"--...___...--"'              _.'"
	@echo '   \""--..__                              __..--""/'
	@echo "     '._     """----.....______.....----"""         _.'"
	@echo '         ""--..,,_____            _____,,..--"""'''
	@echo '                      """------"""'
	@sleep 0.5
	@clear
	@echo ""
	@echo "                 ("
	@echo "	                  )      ("
	@echo "               ___..(.------)--....___"
	@echo '           .-""       )   (           ""-.'
	@echo "      .-''''|-._      (       )        _.-|"
	@echo '     /  .--.|   `""---...........---""`   |'
	@echo "    /  /    |                             |"
	@echo "    |  |    |                             |"
	@echo "     \  \   |                             |"
	@echo "      '\ '\ |                             |"
	@echo "        '\ '|                             |"
	@echo "        _/ /\                             /"
	@echo "       (__/  \                           /"
	@echo '    _..---""` \                         /`""---.._'
	@echo " .-'           \                       /          '-."
	@echo ":               '-.__             __.-'              :"
	@echo ':                  ) ""---...---"" (                :'
	@echo "\'._                '"--...___...--"'              _.'"
	@echo '   \""--..__                              __..--""/'
	@echo "     '._     """----.....______.....----"""         _.'"
	@echo '         ""--..,,_____            _____,,..--"""'''
	@echo '                      """------"""'
	@sleep 0.5
	@clear
	@echo ""
	@echo "               ("
	@echo "	                  )     ("
	@echo "               ___..(.------)--....___"
	@echo '           .-""      )    (           ""-.'
	@echo "      .-''''|-._      (       )        _.-|"
	@echo '     /  .--.|   `""---...........---""`   |'
	@echo "    /  /    |                             |"
	@echo "    |  |    |                             |"
	@echo "     \  \   |                             |"
	@echo "      '\ '\ |                             |"
	@echo "        '\ '|                             |"
	@echo "        _/ /\                             /"
	@echo "       (__/  \                           /"
	@echo '    _..---""` \                         /`""---.._'
	@echo " .-'           \                       /          '-."
	@echo ":               '-.__             __.-'              :"
	@echo ':                  ) ""---...---"" (                :'
	@echo "\'._                '"--...___...--"'              _.'"
	@echo '   \""--..__                              __..--""/'
	@echo "     '._     """----.....______.....----"""         _.'"
	@echo '         ""--..,,_____            _____,,..--"""'''
	@echo '                      """------"""'
	@sleep 0.5
	@clear
	@echo ""
	@echo "             (         ) "
	@echo "	              )        ("
	@echo "               ___)...----)----....___"
	@echo '           .-""      )    (           ""-.'
	@echo "      .-''''|-._      (       )        _.-|"
	@echo '     /  .--.|   `""---...........---""`   |'
	@echo "    /  /    |                             |"
	@echo "    |  |    |                             |"
	@echo "     \  \   |                             |"
	@echo "      '\ '\ |                             |"
	@echo "        '\ '|                             |"
	@echo "        _/ /\                             /"
	@echo "       (__/  \                           /"
	@echo '    _..---""` \                         /`""---.._'
	@echo " .-'           \                       /          '-."
	@echo ":               '-.__             __.-'              :"
	@echo ':                  ) ""---...---"" (                :'
	@echo "\'._                '"--...___...--"'              _.'"
	@echo '   \""--..__                              __..--""/'
	@echo "     '._     """----.....______.....----"""         _.'"
	@echo '         ""--..,,_____            _____,,..--"""'''
	@echo '                      """------"""'i

.PHONY:		all clean fclean re coffee bonus
