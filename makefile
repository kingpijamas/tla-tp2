CC = gcc
FLEX = flex
FILES = lex.yy.c utils.c Grammar.c LinkedList.c grammarProcessing.c generation.c
LEXFILES = tp.l
OUT_EXE=tp
COPTS= -g

tp:
	@-rm -f tp
	@$(FLEX) $(LEXFILES)
	@$(CC) $(COPTS) -o $(OUT_EXE) $(FILES)
	@-rm -f *.yy.c
	@printf "TP made. Read instructions on how to make an analyzer on \"README.md\"\n"

.PHONY: clean

clean:
	@-rm -f *.o core
	@-rm -f ASDR*
	@-rm tp

#rebuild: clean build
