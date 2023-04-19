# Preparo das regras do Makefile em arquivo texto
#
# #comentario
# target:  dependency1 dependency2 ...
# <tab> command
#
# :> make -f Makefile

#construcao do executavel
my_exec: codigo.o
	g++ -o my_exec codigo.o

# compilacao do codigo
codigo.o: codigo.cpp
	g++ -c codigo.cpp

# limpando o diretorio
clean:
	rm codigo.o