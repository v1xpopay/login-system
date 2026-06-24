#include <stdio.h>
#include <string.h>

#define MAX_USERS 3
#define MAX_ATTEMPTS 3

typedef struct {
    char username[50];
    char password[50];
    int is_admin;
} User;

User users[MAX_USERS] = {
    {"admin", "12345678", 1},
    {"nayuu", "thefinalboss", 0},
    {"guest", "guest123", 0}
};

User* find_user(const char *username) {
    for (int i = 0; i < MAX_USERS; i++) {
        if (strcmp(users[i].username, username) == 0)
            return &users[i];
    }
    return NULL;
}

void admin_panel() {
    printf("\n=== ADMIN PANEL ===\n");
    printf("All registered users:\n");
    for (int i = 0; i < MAX_USERS; i++) {
        printf("  - %s (%s)\n", users[i].username, users[i].is_admin ? "admin" : "user");
    }
}

void user_panel(const char *username) {
    printf("\n=== WELCOME %s ===\n", username);
    printf("1. View profile\n");
    printf("2. Logout\n");

    int choice;
    printf("Choice: ");
    scanf("%d", &choice);

    if (choice == 1)
        printf("Profile: %s | Role: normal user\n", username);
    else
        printf("Logged out.\n");
}

int main() {
    char username[50], password[50];
    int attempts = 0;

    printf("=== LOGIN SYSTEM ===\n");

    while (attempts < MAX_ATTEMPTS) {
        printf("\nUsername: ");
        scanf("%s", username);
        printf("Password: ");
        scanf("%s", password);


        if (strlen(password) < 8) {
            printf("Password too short (min 8 chars)\n");
            continue;
        }

        User *u = find_user(username);

        if (u && strcmp(u->password, password) == 0) {
            printf("Access granted!\n");

            if (u->is_admin)
                admin_panel();
            else
                user_panel(username);

            return 0;
        } else {
            attempts++;
            printf("Wrong credentials. %d attempt(s) left.\n", MAX_ATTEMPTS - attempts);
        }
    }

    printf("\nToo many failed attempts. Account locked.\n");
    return 0;
}
