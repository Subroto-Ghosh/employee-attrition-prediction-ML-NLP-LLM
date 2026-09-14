#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef enum {
    TOKEN_NONE,
    TOKEN_NUMBER,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_MULTIPLY,
    TOKEN_DIVIDE,
    TOKEN_LPAREN,
    TOKEN_RPAREN,
    TOKEN_IDENTIFIER
} TokenType;

typedef struct {
    TokenType type;
    char* value;
} Token;

Token create_token(TokenType type, const char* value) {
    Token token;
    token.type = type;
    token.value = strdup(value);
    return token;
}

void free_token(Token token) {
    free(token.value);
}

Token get_next_token(const char* expression, int* position) {

    while (isspace(expression[*position])) {
        (*position)++;
    }

    if (expression[*position] == '\0') {
        return create_token(TOKEN_NONE, "");
    }

    if (isalpha(expression[*position])) {
        char buffer[100];
        int i = 0;

        while (isalnum(expression[*position])) {
            buffer[i++] = expression[(*position)++];
        }
        buffer[i] = '\0';

        return create_token(TOKEN_IDENTIFIER, buffer);
    }

    if (isdigit(expression[*position])) {
        char number[100];
        int i = 0;

        while (isdigit(expression[*position])) {
            number[i++] = expression[(*position)++];
        }
        number[i] = '\0';

        return create_token(TOKEN_NUMBER, number);
    }

    char current_char = expression[(*position)++];

    switch (current_char) {
        case '+': return create_token(TOKEN_PLUS, "+");
        case '-': return create_token(TOKEN_MINUS, "-");
        case '*': return create_token(TOKEN_MULTIPLY, "*");
        case '/': return create_token(TOKEN_DIVIDE, "/");
        case '(': return create_token(TOKEN_LPAREN, "(");
        case ')': return create_token(TOKEN_RPAREN, ")");
        default:  return create_token(TOKEN_NONE, "");
    }
}

int main() {

    char expression[200];
    printf("Enter expression: ");
    fgets(expression, sizeof(expression), stdin);

    int position = 0;
    Token token;

    do {
        token = get_next_token(expression, &position);

        if (token.type == TOKEN_NONE) {
            break;
        }

        switch (token.type) {
            case TOKEN_IDENTIFIER:
                printf("IDENTIFIER: %s\n", token.value);
                break;
            case TOKEN_NUMBER:
                printf("NUMBER: %s\n", token.value);
                break;
            case TOKEN_PLUS:
            case TOKEN_MINUS:
            case TOKEN_MULTIPLY:
            case TOKEN_DIVIDE:
                printf("OPERATOR: %s\n", token.value);
                break;
            case TOKEN_LPAREN:
            case TOKEN_RPAREN:
                printf("PARENTHESIS: %s\n", token.value);
                break;
            default:
                break;
        }

        free_token(token);

    } while (token.type != TOKEN_NONE);

    return 0;
}