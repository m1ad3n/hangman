#ifndef HANGMAN_HEADER
#define HANGMAN_HEADER

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>

#define TITLE "Hangman"

typedef struct {
	const char* sentence;
	char* tried;
	bool* show;
	int tries;
} hangman_s;

typedef enum {
	HM_FINE 			= 0,
	HM_ALREADY_TRIED 	= 1,
	HM_PASSED_NULL 		= 2,
} hangman_code;

hangman_s* hangman_new(const char* _sentence);
hangman_code hangamn_try(hangman_s* hs, char character);
hangman_code hangman_sort(hangman_s* hs);
bool hangman_completed(hangman_s* hs);
hangman_code hangamn_destroy(hangman_s* hs);

#endif
