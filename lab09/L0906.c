#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define USERNAME_LENGTH_MAX 64
#define PASSWORD_LENGTH_MAX 1024
#define CREDENTI_LENGTH_MAX 1024

typedef char credential_t[2][CREDENTI_LENGTH_MAX];

credential_t credentials[] = {
    {"admin", "admin"}, {"user1", "1234"}, {"user2", "5678"}};
ssize_t credentials_len = sizeof(credentials) / sizeof(credentials[0]);

int userid;
char username[USERNAME_LENGTH_MAX];
char password[PASSWORD_LENGTH_MAX];

int i, ch, isroot;

/**
 * Get user id from username
 * @param[in] username name of the user
 * @param[in] credentials pointer to credentials
 * @return user id, -1 on failure
 */
int
get_user_id(char username[USERNAME_LENGTH_MAX], credential_t credentials[],
            ssize_t credentials_len)
{
	for (i = 0; i < credentials_len; ++i) {
		if (strncmp(username, credentials[i][0], USERNAME_LENGTH_MAX) ==
		    0)
			return i;
	}
	return -1;
}

/**
 * Authorize user by username and password
 * @param[in] username name of the user
 * @param[in] password password of the user
 * @param[in] credentials pointer to credentials for tested for authorization
 * @return userid, -1 on error
 */
int
authorize_user(char username[USERNAME_LENGTH_MAX],
               char password[PASSWORD_LENGTH_MAX], credential_t credentials[],
               ssize_t credentials_len)
{
	int userid = get_user_id(username, credentials, credentials_len);
	if (userid < 0)
		return -1;
	if (strncmp(password, credentials[userid][1], PASSWORD_LENGTH_MAX) != 0)
		return -1;
	return userid;
}

/**
 * Change user password
 * @param[in] username name of the user
 * @param[in] password new password to set
 * @param[in,out] credentials pointer to credentials for change password
 * @return -1 on error, 0 on succeed
 */
int
change_password_by_username(char username[USERNAME_LENGTH_MAX],
                            char password[PASSWORD_LENGTH_MAX],
                            credential_t credentials[], ssize_t credentials_len)
{
	int userid = get_user_id(username, credentials, credentials_len);
	if (userid < 0)
		return -1;
	if (strncpy(credentials[userid][1], password, PASSWORD_LENGTH_MAX) !=
	    0) {
		puts("Error change password");
		return -1;
	}
	return 0;
}

int
main(void)
{
program_start:
	puts("LOGIN SYSTEM\n");
	fputs("Username: ", stdout);
	isroot = 0;
	fgets(username, USERNAME_LENGTH_MAX, stdin);
	username[strlen(username) - 1] = '\0';
	fputs("Password: ", stdout);
	fgets(password, PASSWORD_LENGTH_MAX, stdin);
	password[strlen(password) - 1] = '\0';

	putchar('\n');

	switch (
	    authorize_user(username, password, credentials, credentials_len)) {
	case -1:
		puts("Error Username or Password");
		break;
	case 0:
		puts("Welcome my lovely admin!");
		isroot = 1;
		break;
	default:
		puts("Welcome!");
	}

	if (isroot) {
		fputs("Change password for users? (y to change): ", stdout);
		if (getchar() == 'y') {
			puts("Select user to change password");
			for (i = 0; i < credentials_len; i++)
				printf("%d.%s\n", i + 1, credentials[i][0]);
			printf("Select (1-%d): ", i);
			scanf("%d", &userid);
			--userid;
			while ((ch = getchar()) != EOF && ch != '\n')
				;
			if (userid < 0 || userid >= credentials_len)
				fputs("Invalid user\n", stderr);
			else {
				fputs("New Password: ", stdout);
				fgets(password, PASSWORD_LENGTH_MAX, stdin);
				password[strlen(password) - 1] = '\0';
				strcpy(credentials[userid][1], password);
				puts("\n---RESET---");
				goto program_start;
			}
		}
	}

	return 0;
}
