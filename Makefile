OUTDIR ?= out
TARGET ?= $(OUTDIR)/L$(LAB)$(ITEM)
SRCS ?= lab$(LAB)/L$(LAB)$(ITEM).c

CC := clang

CFLAGS := -ansi -pedantic -pedantic-errors

.PHONY = run clean format

run: $(TARGET)
	$^
clean:
	$(RM) -r $(OUTDIR)
$(TARGET): $(SRCS) $(OUTDIR)
	$(CC) -o $@ $(SRCS)
$(OUTDIR):
	@mkdir -p $(OUTDIR)
format:
	clang-format --verbose -i lab*/*.c
