#include "hangman.h"
#include <string.h>

hangman_s* hangman_new(const char* _sentence) {
	hangman_s* tmp = (hangman_s*)malloc(sizeof(hangman_s));
	tmp->sentence = _sentence;
	tmp->tried = (char*)malloc(30);
	
	tmp->show = (bool*)malloc(sizeof(int) * strlen(_sentence));
	for (int i = 0; i < strlen(_sentence); i++) {
		if (_sentence[i] == ' ') tmp->show[i] = true;
		else tmp->show[i] = false;
	}

	return tmp;
}

int compare(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

bool hangman_completed(hangman_s* hs) {
	for (int i = 0; i < strlen(hs->sentence); i++) {
		if (!hs->show[i]) return false;
	}
	return true;
}

hangman_code hangamn_try(hangman_s* hs, char character) {
	if (hs == NULL || character < 'A' || character > 'z') return HM_PASSED_NULL;

	for (int i = 0; i < strlen(hs->tried); i++) {
		if (hs->tried[i] == character) {
			return HM_ALREADY_TRIED;
		}
	}

	hs->tried[strlen(hs->tried)] = character;
	hs->tried[strlen(hs->tried)] = '\0';

	bool has_ch = false;
	for (int i = 0; i < strlen(hs->sentence); i++) {
		if (hs->sentence[i] == character) {
			hs->show[i] = true;
			has_ch = true;
		}
	}

	if (!has_ch) hs->tries++;

	return HM_FINE;
}

hangman_code hangamn_destroy(hangman_s* hs) {
	if (hs == NULL) return HM_PASSED_NULL;
	free(hs->tried);
	free(hs->show);
	free(hs);
	hs = NULL;
	return HM_FINE;
}
