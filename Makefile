CC := gcc
CFLAGS := -g -Wall -Wextra -Wno-unused-parameter -Wno-sign-compare
LIBS := -lSDL2

default: out/hangman_gui.elf out/hangman_cli.elf

out/%.elf: out/%.o out/hangman.o | out
	$(CC) -o $@ $^ $(LIBS)

out/%.o: src/%.c | out
	$(CC) $(CFLAGS) -c -o $@ $<

out:
	@mkdir $@

.PHONY: clean
clean:
	@rm -rvf out