#include <screen.h>
#include <colors.h>
#include <types.h>

void main() { //main function
  creset();   //cursor reset
  sclear();   //screen clear

  print("WELCOME ADVENTURER TO THE DARK FOREST OF PROGRAMMING...\n");
  printf("CTRL", CYAN_ON_BLACK);
  printf("-", GRAY_ON_BLACK);
  printf("TAB\n", CYAN_ON_BLACK);
  print("FEATURING: ");
  printf("Plug_And_Cree", RED_ON_BLACK);
  print(" AND ");
  printf("MRtecno98", GREEN_ON_BLACK);

  scrolldown(2); //2 is the number of lines to scroll
  //scrollup(1);
  while(true);
}
