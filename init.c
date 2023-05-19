#include "defs.h"

/*
  Function:  initAnimalArray
  Purpose:   initialize fields of the given AnimalArrayType parameter to default values.
             elements is allocated memory respective to the 'cap' and AnimalType
             capacity is initialized to 'cap'
             size is initialized to 0
      out:   '*arr' of AnimalArrayType becomes initialized
       in:   'cap' array capacity
*/
void initAnimalArray(AnimalArrayType *arr, int cap) {
  arr->elements = calloc(cap, sizeof(AnimalType));    // dynamically allocated array of AnimalType
  arr->capacity = cap;
  arr->size = 0;
}

/*
  Function:  initAnimal
  Purpose:   initializes fields of the given AnimalType parameter to default values.
       in:   'id' integer
       in:   's' SpeciesType value
       in:   'name' string
       in:   'gender' string
       in:   'age' integer
      out:   '*an' AnimalType becomes initialized
*/
void initAnimal(int i, SpeciesType s, char *n, char *g, int a, AnimalType *an) {
  an->id = i;
  an->species = s;
  strcpy(an->name, n);
  strcpy(an->gender, g);
  an->age = a;
}

/*
  Function:  loadAnimalData
  Purpose:   fills the given animal collection structure with animal data.
      out:   '*arr' is loaded with data
*/
void loadAnimalData(AnimalArrayType *arr)
{
  AnimalType a;

  initAnimal(1008, C_DOG, "Josie", "F", 18, &a);    // There are 16 animals
  addAnimal(arr, &a);
  initAnimal(1001, C_DOG, "Nala", "F", 60, &a);
  addAnimal(arr, &a);
  initAnimal(1017, C_CAT, "Matcha", "M", 84, &a);
  addAnimal(arr, &a);
  initAnimal(1002, C_DOG, "Miley", "F", 41, &a);
  addAnimal(arr, &a);
  initAnimal(1032, C_OTHER, "Jojo", "M", 3, &a);
  addAnimal(arr, &a);
  initAnimal(1004, C_DOG, "Levi", "M", 31, &a);
  addAnimal(arr, &a);
  initAnimal(1013, C_CAT, "Maya", "F", 121, &a);
  addAnimal(arr, &a);
  initAnimal(1018, C_CAT, "Maggie", "F", 96, &a);
  addAnimal(arr, &a);
  initAnimal(1029, C_OTHER, "Tank", "M", 3, &a);
  addAnimal(arr, &a);
  initAnimal(1007, C_DOG, "Zane", "M", 48, &a);
  addAnimal(arr, &a);
  initAnimal(1027, C_OTHER, "Prince", "M", 16, &a);
  addAnimal(arr, &a);
  initAnimal(1016, C_CAT, "Vader", "M", 62, &a);
  addAnimal(arr, &a);
  initAnimal(1024, C_OTHER, "Aries", "M", 108, &a);
  addAnimal(arr, &a);
  initAnimal(1021, C_CAT, "Ruby", "F", 60, &a);
  addAnimal(arr, &a);
  initAnimal(1023, C_OTHER, "Nero", "F", 44, &a);
  addAnimal(arr, &a);
  initAnimal(1033, C_OTHER, "Jotaro", "M", 3, &a);
  addAnimal(arr, &a);
}