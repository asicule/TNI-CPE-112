run: out/L$(LAB)$(ITEM).out
	./out/L$(LAB)$(ITEM).out
clean:
	rm out/*
out/L$(LAB)$(ITEM).out: lab$(LAB)/L$(LAB)$(ITEM).c
	clang -ansi -pedantic -pedantic-errors -o out/L$(LAB)$(ITEM).out lab$(LAB)/L$(LAB)$(ITEM).c
