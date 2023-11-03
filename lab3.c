#define _CRT_SECURE_NO_WARNINGS 
 
#define ALPHABET_SIZE 26 

#define MSG printf("Окей\n") 
 
 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <locale.h> 
 
 
 
 
 
void printUniqueCharacters(char* str) { 
 int count[ALPHABET_SIZE] = { 0 }; 
 int length = 0; 
 
 while (*str) { 
  if (*str >= 'a' && *str <= 'z') { 
   count[*str - 'a']++; 
   length++; 
  } 
  str++; 
 } 
 
 printf("Unique characters: "); 
 for (int i = 0; i < ALPHABET_SIZE; i++) { 
  if (count[i] == 1) { 
   printf("%c ", i + 'a'); 
  } 
 } 
 
 printf("\n"); 
} 
 
void menu() { 
 char str[100]; 
 char choice; 
 
 do { 
  printf("1. Введите строку\n"); 
  printf("2. Выход\n"); 
  printf("Ваш выбор: "); 
  fflush(stdin); 
  scanf(" %c", &choice); 
 
  switch (choice) { 
  case '1': 
   MSG; 
   printf("Введите строку: "); 
   getchar(); 
   fgets(str, sizeof(str), stdin); 
   printf("Результат:\n"); 
   printUniqueCharacters(str); 
   break; 
  case '2': 
   MSG; 
   printf("Выход из программы...\n"); 
   exit(0); 
  default: 
   printf("Неверный выбор.\n Повторите попытку.\n"); 
  } 
 
  printf("\n"); 
 } while (1); 
} 
 
int main() { 
 setlocale(LC_ALL, "Rus"); 
 menu(); 
 return 0; 
}