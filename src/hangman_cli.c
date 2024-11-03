#include "hangman.h"

#define CURSOR_UP(x) printf("\033[%dF", x)
#define CURSOR_LEFT(x) printf("\033[%dD", x)
#define LINE_ERASE printf("\033[2K\r")

void hangman_display(hangman_s* hs) {
	for (size_t i = 0; i < strlen(hs->sentence); i++) {
		if (hs->show[i]) putchar(hs->sentence[i]);
		else putchar(' ');
		if (hs->sentence[i] != ' ') putchar(' ');
	}
	putchar('\n');
	for (size_t i = 0; i < strlen(hs->sentence); i++) {
		if (hs->sentence[i] != ' ')
			fputs("\u2501", stdout);
		putchar(' ');
	}
}

int main(int argc, char* argv[]) {

	// create a game instance
	hangman_s* ginstance;
	char sentence[1024];
	char user_input[1024];

	printf("sentence >> ");
	fgets(sentence, 1024, stdin);
	sentence[strlen(sentence) - 1] = '\0';

	LINE_ERASE;
	CURSOR_UP(1);
	LINE_ERASE;

	ginstance = hangman_new(sentence);
	hangman_display(ginstance);

	while (!hangman_completed(ginstance)) {

		if (ginstance->tries >= 5) {
			break;
		}
	
		printf("\n%d >> ", 5 - ginstance->tries);
		fgets(user_input, 1024, stdin);
		user_input[strlen(user_input) - 1] = '\0';

		hangamn_try(ginstance, user_input[0]);

		LINE_ERASE;
		CURSOR_UP(3);
		LINE_ERASE;
		
		hangman_display(ginstance);
	}

	if (hangman_completed(ginstance)) printf("\nYou won\n");
	else printf("\nYou lost\n");

	hangamn_destroy(ginstance);
	return 0;
}
