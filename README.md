Trabajo práctico II de la materia Autómatas, Teoría de Lenguajes y Compiladores
Victoria Mesa Alcorta
Alan Pierri
Juan Pablo Rey
Año 2012

Instrucciones
=============

make tp
	*Compila el trabajo practico.
make clean
	*Borra la compilación del trabajo.
cat <archivo> | ./tp
	*Arma un Analizador Sintáctico Descendente con Retroceso (ASDR) a partir del archivo <archivo>.
echo <string> | ./tp
	*Arma un Analizador Sintáctico Descendente con Retroceso (ASDR) a partir del texto <string>.
./tp
	*Arma un Analizador Sintáctico Descendente con Retroceso (ASDR) a partir de la entrada que se le ingrese a continuación.
./genASDR <archivo>
	*Arma un Analizador Sintáctico Descendente con Retroceso (ASDR) a partir de la entrada que se le ingrese a continuación.
./ASDR <cadena>
	*Acepta o rechaza una cadena segun el lenguaje con el que se armó dicho archivo.
./clean
	*Borra el ASDR generado.

*EJEMPLO*
	make clean && make tp && cat example.txt | ./tp && ./ASDR xyyxyzzy
	make tp && ./genASDR example3.txt && ./ASDR aabbbaabb