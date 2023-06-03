
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include "lib.h"



int main(int argc, char *argv[])
{
  char arg_for_file[PATH_MAX] = { 0 };
  char arg_for_dir[PATH_MAX] = { 0 };
  int number_elements[2] = { 0, 0 };
  int *numb_elements = number_elements;

  printf("\nАвтор:Коломійцев Володимир-922Б\nГрупа:КН-922Б\nНомер лабараторної роботи:14\nТема:Строки Взаємодія з файлами\n\n");
  printf("Вивести структуру файлів та каталогів, як це робить утиліта Linux tree.\n\n");

  switch (Check_Write_In_Data(argc, argv)) {
  case 1:
    printf("Ви не ввели ніякі дані\n");
    return 1;
    break;

  case 2:
    printf("Ви ввели некоректну кількість даних\n");
    return 1;
    break;

  case 3:
    printf("Не можливо отримати доступ до файлу або дерикторії\n");
    return 1;
    break;
  }

  strcat(arg_for_file, *(argv + 2));
  strcat(arg_for_dir, *(argv + 1));

  FILE *output_file = fopen(arg_for_file, "a");
  fprintf(output_file, "%s\n|\n", arg_for_dir);
  fclose(output_file);

  Write_Struct_Dir(numb_elements, arg_for_file, arg_for_dir, arg_for_dir);

  FILE *out_file = fopen(arg_for_file, "a");
  fprintf(output_file, "\nКількість дирикторій:%d  Кількість файлів:%d", *(numb_elements), *(numb_elements + 1));
  fclose(out_file);

  return 0;
}















