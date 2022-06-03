# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/25 15:35:43 by cassassi          #+#    #+#              #
#    Updated: 2022/06/03 14:31:03 by cassassi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-------------------VECTOR-------------------------------------#

VECTOR	= std_vector

VECTOR2	= ft_vector

VSRC	= std_mains/vector_std.cpp

VSRC2	= ft_mains/vector_main.cpp

VOBJS	= $(VSRC:%.cpp=%.o)

VOBJS2	= $(VSRC2:%.cpp=%.o)

#------------------------MAP--------------------------------#

MAP		= std_map

MAP2	= ft_map

MSRC	= std_mains/map_std.cpp

MSRC2	= ft_mains/map_main.cpp

MOBJS	= $(MSRC:%.cpp=%.o)

MOBJS2	= $(MSRC2:%.cpp=%.o)

#------------------------STACK--------------------------------#

STACK	= std_stack

STACK2	= ft_stack

SSRC	= std_mains/stack_std.cpp

SSRC2	= ft_mains/stack_main.cpp

SOBJS	= $(SSRC:%.cpp=%.o)

SOBJS2	= $(SSRC2:%.cpp=%.o)

#----------------------MAIN42----------------------------------#

TEST42	= std_test42

TEST422	= ft_test42

TSRC	= std_mains/main42_std.cpp

TSRC2	= ft_mains/main42.cpp

TOBJS	= $(TSRC:%.cpp=%.o)

TOBJS2	= $(TSRC2:%.cpp=%.o)

#--------------------------------------------------------#

CCXX		= c++

FLAGS	= -Wall -Werror -Wextra -std=c++98

#--------------------------------------------------------#

all :		$(VECTOR) $(VECTOR2) $(MAP) $(MAP2) $(STACK) $(STACK2) $(TEST42) $(TEST422)

vector:		$(VECTOR) $(VECTOR2)

map:		$(MAP) $(MAP2)

stack:		$(STACK) $(STACK2)

test:		$(TEST42) $(TEST422)
	
$(VECTOR):	$(VOBJS)
			$(CCXX) -o $(VECTOR) $(VOBJS) $(FLAGS)

$(VECTOR2):	$(VOBJS2)
			$(CCXX) -o $(VECTOR2) $(VOBJS2) $(FLAGS)

$(MAP):		$(MOBJS)
			$(CCXX) -o $(MAP) $(MOBJS) $(FLAGS)

$(MAP2):	$(MOBJS2)
			$(CCXX) -o $(MAP2) $(MOBJS2) $(FLAGS)

$(STACK):	$(SOBJS)
			$(CCXX) -o $(STACK) $(SOBJS) $(FLAGS)

$(STACK2):	$(SOBJS2)
			$(CCXX) -o $(STACK2) $(SOBJS2) $(FLAGS)

$(TEST42):	$(TOBJS)
			$(CCXX) -o $(TEST42) $(TOBJS) $(FLAGS)
			
$(TEST422): $(TOBJS2)
			$(CCXX) -o $(TEST422) $(TOBJS2) $(FLAGS)
			
clean:		
			rm -f $(VOBJS) $(VOBJS2) $(MOBJS) $(MOBJS2) $(SOBJS) $(SOBJS2) $(TOBJS) $(TOBJS2)
			
fclean: 	clean
			rm -f $(VECTOR) $(VECTOR2) $(MAP) $(MAP2) $(STACK) $(STACK2) $(TEST42) $(TEST422)

re: 		fclean all

%.o:%.cpp
			$(CCXX) $(FLAGS) -o $@ -c $<
