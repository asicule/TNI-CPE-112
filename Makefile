run: out/L$(LAB)$(ITEM).out
	./out/L$(LAB)$(ITEM).out
out/L$(LAB)$(ITEM).out: lab$(LAB)/L$(LAB)$(ITEM).c
	clang lab$(LAB)/L$(LAB)$(ITEM).c -o out/L$(LAB)$(ITEM).out
