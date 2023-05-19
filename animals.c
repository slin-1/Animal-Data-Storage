#include "defs.h"

/*
  Function:  addAnimal
  Purpose:   stores a copy of the give animal into its correct position in the given animal collection.
             animals stored in ascending alphabetical order by species, and within the species,
             the age should be descending
       in:   '*arr' structure elements
      out:   '*arr' with the newly added animal
       in:   '*an' to be added
*/
void addAnimal(AnimalArrayType *arr, AnimalType *an) {
  if(arr->size >= arr->capacity) {    // check if arr cannot accomodate new animal
    return;
  }

  int index = 0;
  for(int i=0; i<arr->size; ++i) {
    // edge case (for when identical species & age animals are added)
    if(arr->elements[i].species == an->species) {
      if(arr->elements[i].age == an->age) {
        ++index;
        continue;
      }
    }
    
    if(arr->elements[i].species >= an->species) {    // animal species is greater or equal to new animal species
      if(arr->elements[i].age <= an->age) {    // stop searching if array animal age is less or equal to new animal
        break;
      }
    }
    ++index;
  }
  
  for(int j=arr->size; j>index; --j) {    // Shift array to the end to make room for new animal
    copyAnimal(&arr->elements[j], &arr->elements[j-1]);
  }

  copyAnimal(&arr->elements[index], an);
  ++(arr->size);
}

/*
  Function:  delAnimal
  Purpose:   removes the animal with the given id from the given animal collection if possible
       in:   '*arr' animal collection structure elements
      out:   '*arr' may have an element removed
       in:   'id' to identify the animal
   return:   returns a success(removal) or error(no removal) flag
*/
int delAnimal(AnimalArrayType *arr, int id) {
  int removed = C_OK, index = 0;

  if(id < 0) {    // ID should be positive
    return removed = C_NOK;
  }

  for(int i=0; i<arr->size; ++i) {
    if(arr->elements[i].id == id) {
      break;
    }
    ++index;
  }

  if(index >= arr->size) {    // Check if there was NOT a found index to remove
    removed = C_NOK;
  }
  else {
    for(int j=index; j<arr->size-1; ++j) {
    copyAnimal(&arr->elements[j], &arr->elements[j+1]);
    }
    --(arr->size);
  }

  return removed;
}

/*
  Function:  copyAnimal
  Purpose:   performs a deep copy of the animal in the '*oldAn' parameter, into
             the '*newAn' parameter
      out:   '*newAn' as the new animal structure
       in:   '*oldAn' as the animal to be copied
*/
void copyAnimal(AnimalType *newAn, AnimalType *oldAn) {
  initAnimal(oldAn->id, oldAn->species, oldAn->name, oldAn->gender, oldAn->age, newAn);
}

/*
  Function:  validateSpecies
  Purpose:   verifies the choice from the user in the menu matches a valid species.
             menu options: 1 for dogs, 2 for cats, 3 for other species
       in:   'choice' the user's input
      out:   's' is returned as the correct species
   return:   returns a success(valid) or error(non-valid) flag
*/
int validateSpecies(int choice, SpeciesType *s) {
  if(choice == 1) {
    *s = C_DOG;
    return C_OK;
  }
  else if(choice == 2) {
    *s = C_CAT;
    return C_OK;
  }
  else if(choice == 3) {
    *s = C_OTHER;
    return C_OK;
  }
  return C_NOK;
}


/*
  Function:  printAnimals
  Purpose:   prints all the animals in the given collection. outputted in a formatted manner
       in:   '*arr' animal collection structure
*/
void printAnimals(AnimalArrayType *arr) {
  for(int i=0; i<arr->size; ++i) {
    printf("%4d :", arr->elements[i].id);
    printf(" %-11s :",  arr->elements[i].name);

    // Determine species
    if(arr->elements[i].species == 0) {
      char cat[] = "Cat";
      printf(" %-5s :", cat);
    } 
    else if(arr->elements[i].species == 1) {
      char dog[] = "Dog";
      printf(" %-5s :", dog);
    }
    else {
      char other[] = "Other";
      printf(" %-5s :", other);
    }

    printf(" %s;", arr->elements[i].gender);

    // Determine ages
    int temp = arr->elements[i].age , years = 0, months = 0;
    years = temp / 12;
    months = temp - years*12;
    printf(" Age: %3d yrs, %3d mths", years, months);
  
    printf("\n");
  }
}

/*
  Function:  printAnimalsBySpecies
  Purpose:   prints the animals that match the given species in the given animal collection
       in:   '*arr' animal collection structure to print
       in:   's' specific species to print
*/
void printAnimalsBySpecies(AnimalArrayType *arr, SpeciesType s){
  AnimalArrayType tempArr;
  initAnimalArray(&tempArr, MAX_CAP);
  int count = 0;

  for(int i=0; i<arr->size; ++i) {
    if(arr->elements[i].species == s) {
      copyAnimal(&tempArr.elements[count], &arr->elements[i]);
      ++tempArr.size;
      ++count;
    }
  }
  printAnimals(&tempArr);
  cleanupAnimalArray(&tempArr);
}

/*
  Function:  cleanupAnimalArray
  Purpose:   deallocates dynamically allocated memory inside the given animal collection
       in:   '*arr' as the animal structure to deallocate memory from
*/
void cleanupAnimalArray(AnimalArrayType *arr){
  free(arr->elements);
}