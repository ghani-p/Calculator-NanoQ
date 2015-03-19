#MAIN PROGRAM
run:
	../bin/Calculator-NanoQ

build:
	g++ calc.cpp \
	COLLECTION/Stack/StackExp.cpp \
	COLLECTION/Vector/VectorExp.cpp \
	EXPRESSION/Postfix/Postfix.cpp EXPRESSION/Prefix/Prefix.cpp EXPRESSION/Infix/Infix.cpp \
	MEMORY/Memori/Memori.cpp COMMAND/Perintah/Perintah.cpp \
	NUMBER/Arab/Arab.cpp NUMBER/Logika/Logika.cpp \
	NUMBER/Operand/Operand.cpp NUMBER/Romawi/Romawi.cpp \
	-o ../bin/Calculator-NanoQ

#COLLECTION
stack:
	g++ COLLECTION/Stack/UnitTest.cpp COLLECTION/Stack/StackExp.cpp \
	-o COLLECTION/Stack/TestStack
teststack:
	COLLECTION/Stack/TestStack

vector:
	g++ COLLECTION/Vector/UnitTest.cpp COLLECTION/Vector/VectorExp.cpp \
	-o COLLECTION/Vector/TestVector
testvector:
	COLLECTION/Vector/TestVector


#COMMAND
perintah:
	g++ COMMAND/Perintah/UnitTest.cpp COMMAND/Perintah/Perintah.cpp \
	MEMORY/Memori/Memori.cpp COLLECTION/Vector/VectorExp.cpp \
	-o COMMAND/Perintah/TestPerintah
testperintah:
	COMMAND/Perintah/TestPerintah


#EXPRESSION
infix:
	g++ EXPRESSION/Infix/UnitTest.cpp EXPRESSION/Infix/Infix.cpp \
	EXPRESSION/Postfix/Postfix.cpp \
	COLLECTION/Stack/StackExp.cpp COLLECTION/Vector/VectorExp.cpp \
	NUMBER/Operand/Operand.cpp NUMBER/Arab/Arab.cpp \
	NUMBER/Romawi/Romawi.cpp NUMBER/Logika/Logika.cpp \
	-o EXPRESSION/Infix/TestInfix
testinfix:
	EXPRESSION/Infix/TestInfix

postfix:
	g++ EXPRESSION/Postfix/UnitTest.cpp EXPRESSION/Postfix/Postfix.cpp \
	COLLECTION/Stack/StackExp.cpp COLLECTION/Vector/VectorExp.cpp \
	NUMBER/Operand/Operand.cpp NUMBER/Arab/Arab.cpp \
	NUMBER/Romawi/Romawi.cpp NUMBER/Logika/Logika.cpp \
	-o EXPRESSION/Postfix/TestPostfix
testpostfix:
	EXPRESSION/Postfix/TestPostfix

prefix:
	g++ EXPRESSION/Prefix/UnitTest.cpp EXPRESSION/Prefix/Prefix.cpp \
	EXPRESSION/Postfix/Postfix.cpp \
	COLLECTION/Stack/StackExp.cpp COLLECTION/Vector/VectorExp.cpp \
	NUMBER/Operand/Operand.cpp NUMBER/Arab/Arab.cpp \
	NUMBER/Romawi/Romawi.cpp NUMBER/Logika/Logika.cpp \
	-o EXPRESSION/Prefix/TestPrefix
testprefix:
	EXPRESSION/Prefix/TestPrefix


#MEMORY
memori:
	g++ MEMORY/Memori/UnitTest.cpp MEMORY/Memori/Memori.cpp \
	COLLECTION/Vector/VectorExp.cpp \
	-o MEMORY/Memori/TestMemori
testmemori:
	MEMORY/Memori/TestMemori


#NUMBER
arab:
	g++ NUMBER/Arab/UnitTest.cpp NUMBER/Arab/Arab.cpp \
	NUMBER/Operand/Operand.cpp \
	-o NUMBER/Arab/TestArab
testarab:
	NUMBER/Arab/TestArab

logika:
	g++ NUMBER/Logika/UnitTest.cpp NUMBER/Logika/Logika.cpp \
	NUMBER/Operand/Operand.cpp \
	-o NUMBER/Logika/TestLogika
testlogika:
	NUMBER/Logika/TestLogika

operand:
	g++ NUMBER/Operand/UnitTest.cpp NUMBER/Operand/Operand.cpp \
	-o NUMBER/Operand/TestOperand
testoperand:
	NUMBER/Operand/TestOperand

romawi:
	g++ NUMBER/Romawi/UnitTest.cpp NUMBER/Romawi/Romawi.cpp \
	NUMBER/Operand/Operand.cpp NUMBER/Arab/Arab.cpp \
	-o NUMBER/Romawi/TestRomawi
testromawi:
	NUMBER/Romawi/TestRomawi
