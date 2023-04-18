##
## EPITECH PROJECT, 2022
## B-OOP-400-BAR-4-1-raytracer-thomas.laprie
## File description:
## Makefile
##

NAME    =	raytracer

CCPP    =	g++

SRC 	=	src/Boxes.cpp \
			src/Camera.cpp \
			src/Color.cpp \
			src/Cones.cpp \
			src/Cylinders.cpp \
			src/Lights.cpp \
			src/ParserFile.cpp \
			src/Planes.cpp \
			src/Point3D.cpp \
			src/Spheres.cpp \
			src/Torus.cpp \
			src/Triangles.cpp \

MAIN	=	main.cpp

OBJ  	=	$(SRC:.cpp=.o)

CPPFLAGS =	-W -Wall -Wextra -g3 -I ./include -lconfig++

SFLAGS	=	-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

all:	$(NAME)

$(NAME):   $(OBJ)
	$(CCPP) $(MAIN) -o $(NAME) $(OBJ) $(CPPFLAGS) $(SFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re