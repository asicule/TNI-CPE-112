#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define USERNAME_LENGTH_MAX 64
#define PASSWORD_LENGTH_MAX 1024
#define CREDENTI_LENGTH_MAX 1024

char credentials[][2][CREDENTI_LENGTH_MAX] = {
    {"admin", "admin"}, {"user1", "1234"}, {"user2", "5678"}};
ssize_t credentials_len = sizeof(credentials) / sizeof(credentials[0]);

char username[USERNAME_LENGTH_MAX];
char password[PASSWORD_LENGTH_MAX];

int i, ch;

int
main(void)
{
	puts("LOGIN SYSTEM\n");
	fputs("Username: ", stdout);
	fgets(username, sizeof(username), stdin);
	username[strlen(username) - 1] = '\0';
	fputs("Password: ", stdout);
	fgets(password, sizeof(password), stdin);
	password[strlen(password) - 1] = '\0';

	putchar('\n');
	for (i = 0; i < credentials_len; ++i) {
		if (strncmp(username, credentials[i][0], sizeof(username)) != 0)
			continue;
		if (strncmp(password, credentials[i][1], sizeof(password)) !=
		    0) {
			puts("Error Username or Password");
			break;
		}
		switch (i) {
		case 0:
			puts("Welcome my lovely admin!");
			break;
		default:
			puts("Welcome!");
		}
		break;
	}
	if (i >= credentials_len)
		puts("Error Username or Password");

	return 0;
}
