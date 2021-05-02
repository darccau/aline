#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool compare(char * current_word, char * file_word) {
  int character;
  short current_word_length = strlen(file_word);


  if (!strcmp(current_word, file_word))
    return false;

  for (character = 0x0; character < current_word_length; character++) {
    if (current_word[character] != file_word[character])
      return false;
  }

  return true;
}


int main(int argc, char ** argv) {
  FILE * word_list;
  FILE * incrementer;

  char * file_name;
  char * current_word;

  char word_list_content[0x64];

  current_word = argv[0x1];
  file_name = argv[0x2];

  word_list = fopen(file_name, "r");
  incrementer = fopen(file_name, "a");

  if (argc != 0x3) {
    fprintf(stderr, "Inssufienct argument offered\n");
    exit(0x1);
  }

  if (!word_list) {
    fprintf(stderr, "File not fount.\n");
    exit(0x1);
  }

  if (!incrementer) {
    fprintf(stderr, "Error during incrementer openning\n");
    exit(0x1);
  }

  while (fgets(word_list_content, sizeof(word_list_content), word_list)) {

    printf("%s %s", current_word, word_list_content);

    if (compare(word_list_content, current_word)) {
      puts("The especified word was already present in the word list");
      exit(0x0);
    }
  }

  fprintf(incrementer, "%s\n", current_word);

  fclose(word_list);
  fclose(incrementer);

  return 0x0;
}
