#include <stdio.h>
#include <string.h>

#include "defs.h"

int main()
{
  int choice = -1;
  AnimalArrayType aniArr;
  initAnimalArray(&aniArr, MAX_CAP);    // Initialize animal collection structure
  loadAnimalData(&aniArr);    // Load animal data into the animal collection

  char welcomeMsg[] = "Hello! Welcome to Steven Lin's Animal Data Storage\n";
  printf("==================================================\n");
  printf(welcomeMsg);
  printf("==================================================~\n");

  // Menu user input
  printMenu(&choice);
  while(choice != 0) {

    if(choice == 1) {    // Add animal
      AnimalType animal;

      printf("Enter animal ID: ");
      scanf("%d", &animal.id);
      if(animal.id < 0) {    // User must enter positive ID
        printf("~ Error! Enter a positive ID value.\n");
        choice = -1;
        continue;
      }

      int speciesChoice = 0;
      printf("Enter species [1->Dog, 2->Cat, 3->Other]: ");
      scanf("%d", &speciesChoice);
      if(validateSpecies(speciesChoice, &animal.species) == -1) {    // Species choice must be 1-3
        printf("~ Error! Choose a valid species option.\n");
        choice = -1;
        continue;
      }
      
      printf("Enter name: ");
      scanf("%s", animal.name);
      if(strlen(animal.name) >= MAX_STR) {
        printf("~ Error! The name can be at most 32 characters.\n");    // Name can be at most 32 characters
        choice = -1;
        continue;
      }

      printf("Enter gender [M or F]: ");
      scanf("%s", animal.gender);
      if((strcmp(animal.gender, "M") != 0) && (strcmp(animal.gender, "F") != 0)) {    // Restrict gender to M and F
        printf("~ Error! The gender must be either M or F.\n");
        choice = -1;
        continue;
      }

      int years = 0, months = 0;
      printf("Enter age, years [0 to 99]: ");
      scanf("%d", &years);
      if(years < 0 || years > 99) {    // Years 0 to 99 (inclusive) 
        printf("~ Error! Years must be from 0 to 99 inclusive.\n");
        choice = -1;
        continue;
      }
      printf("Enter age, months [1 to 12]: ");
      scanf("%d", &months);
      if(months < 1 || months > 12) {    // Months 1 to 12 (inclusive)
        printf("~ Error! Months must be from 1 to 12 inclusive.\n");
        choice = -1;
        continue;
      }
      animal.age = (years * 12) + months;    // Calculate the age w/ years & months

      addAnimal(&aniArr, &animal);    // Add the animal
    }

    else if(choice == 2) {    // Delete animal
      int deleteChoice = 0;
      printf("Enter the ID of the animal to remove: ");
      scanf("%d", &deleteChoice);
      if(delAnimal(&aniArr, deleteChoice)) {
        printf("~ Error! ID is not in the animal collection.\n");
        choice = -1;
        continue;
      }
    }

    else if(choice == 3) {    // Print animals
      printAnimals(&aniArr);
    }

    else if(choice == 4) {    // Prints animals by species
      int speciesChoice = 0;
      SpeciesType species = C_CAT;
      printf("Enter species to print [1->Dog, 2->Cat, 3->Other]: ");
      scanf("%d", &speciesChoice);
      if(validateSpecies(speciesChoice, &species) == -1) {    // Species choice must be 1-3
        printf("~ Error! Choose a valid species option.\n");
        choice = -1;
        continue;
      }
      printAnimalsBySpecies(&aniArr, species);
    }

    printMenu(&choice);
  }

  cleanupAnimalArray(&aniArr);    // Free memory
  return(0);
}


/*
  Function:  printMenu
  Purpose:   prints menu to the terminal. allows the user to input content, interact, and manipulate
             a collection of animal data.
       in:   '*choice' to store the user's selections
*/
void printMenu(int *choice)
{
  int c = -1;
  int numOptions = 4;

  printf("\nMAIN MENU\n");
  printf("  (1) Add animal\n");
  printf("  (2) Delete animal\n");
  printf("  (3) Print all animals\n");
  printf("  (4) Print animals by species\n");
  printf("  (0) Exit\n\n");

  printf("Please enter your selection: ");
  scanf("%d", &c);

  if (c == 0) {
    *choice = c;
    return;
  }

  while (c < 0 || c > numOptions) {
    printf("Please enter your selection: ");
    scanf("%d", &c);
  }

  *choice = c;
}

