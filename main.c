#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_ELEMENTS 35

typedef struct
{
    int key;
} Element;

typedef struct
{
    Element elements[MAX_ELEMENTS];
    int top;
} Stack;

void initialize(Stack *stack)
{
    stack->top = -1;
}

bool isFull(Stack *stack)
{
    return stack->top == MAX_ELEMENTS - 1;
}

bool isEmpty(Stack *stack)
{
    return stack->top == -1;
}

bool push(Stack *stack, int value)
{
    if (isFull(stack))
    {
        printf("A pilha está cheia. Não é possível empilhar.\n");
        return false;
    }

    stack->top++;
    stack->elements[stack->top].key = value;
    return true;
}

bool pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("A pilha está vazia. Não é possível desempilhar.\n");
        return false;
    }

    stack->top--;
    return true;
}

void display(Stack *stack)
{
    printf("Pilha: ");
    for (int i = 0; i <= stack->top; i++)
    {
        printf("[%d]", stack->elements[i].key);
    }
    printf("\n\nNúmero de elementos na pilha: %d\n", stack->top + 1);
}

int main()
{
    char option = '1';
    int value;
    Stack stack;
    initialize(&stack);

    while (option != '0')
    {
        system("clear"); // Use "clear" para limpar a tela do terminal em sistemas Unix-like
        printf("==========>Menu da Pilha<==========\n");
        printf("__________________________\n");
        printf("      1-->Empilhar\n");
        printf("      2-->Desempilhar\n");
        printf("      3-->Exibir\n");
        printf("      0-->Sair\n");
        printf("__________________________\n");
        printf("\nOpção: ");
        scanf(" %c", &option);

        switch (option)
        {
            case '1':
            {
                if (isFull(&stack))
                    printf("A pilha está cheia. Não é possível empilhar.\n");
                else
                {
                    printf("\nDigite o valor para empilhar: ");
                    scanf("%d", &value);

                    if (push(&stack, value))
                        printf("Empilhado com sucesso\n");
                }

                printf("\nPressione qualquer tecla para continuar.\n");
                getchar();
                break;
            }

            case '2':
            {
                if (isEmpty(&stack))
                    printf("A pilha está vazia. Não é possível desempilhar.\n");
                else
                {
                    if (pop(&stack))
                        printf("Desempilhado com sucesso\n");
                }

                printf("\nPressione qualquer tecla para continuar.\n");
                getchar();
                break;
            }

            case '3':
            {
                display(&stack);

                printf("\nPressione qualquer tecla para continuar.\n");
                getchar();
                break;
            }
        }
    }
    return 0;
}
