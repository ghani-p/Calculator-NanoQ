make:
	g++ calc.cpp \
	EXPRESSION/Postfix/Postfix.cpp \
	EXPRESSION/Prefix/Prefix.cpp \
	EXPRESSION/Infix/Infix.cpp \
	MEMORY/Memori/Memori.cpp \
	COMMAND/Perintah/Perintah.cpp \
	NUMBER/Arab/Arab.cpp \
	NUMBER/Logika/Logika.cpp \
	NUMBER/Operand/Operand.cpp \
	NUMBER/Romawi/Romawi.cpp \
	-o CalculatorOOP
	./CalculatorOOP