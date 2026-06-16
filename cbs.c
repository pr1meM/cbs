#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void show_help_menu() {
  printf("cbs list of commands: \n\n");
  printf("\033[1mcbs\033[0m");
  puts(" -- type cbs with the following arguments");
  printf("\033[1mfirst arg\033[0m");
  puts(" -- enter the name of your context/process binary");
  printf("\033[1msecond arg\033[0m");
  puts(" -- enter the offset");

  printf("\033[1mExample: \033[0m");
  printf("cbs challenge 44 \n\n");



}



int main(int argc, char *argv[]) {
  
  
  // if no arguments or typed: csb help -> show help menu
  if(argc < 2) {
    printf("Error: give arguments\n\n");
    show_help_menu();
    return 0;
  }

  if(argc > 3) {
    printf("Too many arguments\n\n");
    show_help_menu();
    return 0;
  }

  if(strcmp(argv[1], "help") == 0) {
    show_help_menu();
    return 0;
  }
  
  if(argc < 3) {
    printf("Error: need binary name AND offset\n\n");
    show_help_menu();
    return 1;
  }

  // create FILE
  FILE *solve = fopen("solve.py", "w");

  if(solve == NULL) {
    perror("Failed creating file: ");
    exit(1);
  }
  

  // CONTENT
  fputs("# clear black pwn buffer overflow template\n", solve);
  fputs("from pwn import *\n\n", solve);
  fprintf(solve, "context.binary = (\"./%s\")\n\n", argv[1]);
  fputs("# remote or local? Switch by setting the switch bool\n\n", solve);
  fputs("HOST = \"\"\n", solve);
  fputs("PORT = None\n", solve);
  fputs("switch = False\n", solve);
  fputs("if switch:\n", solve);
  fputs("   p = remote(HOST, PORT)\n", solve);
  fputs("else:\n", solve);
  fprintf(solve, "   p = process(\"./%s\")\n", argv[1]);
  fputs("\n\n", solve);
  fputs("#==== Debugging space ====\n\n", solve);
  fputs("# gdb.attach(p, \'\'\'\n", solve);
  fputs("# break *0x....... enter breakpoint\n\n", solve);
  fputs("# ''')\n", solve);
  fputs("# pause()\n\n", solve);

  fputs("\n\n#==== Space for variables ====\n\n", solve);
  fputs("\n\n", solve);

  fprintf(solve, "payload = b\"A\" * %s # space for rop-chains and so on ....\n\n", argv[2]);
  fputs("# p.recvuntil(b\"\")\n", solve);
  fputs("p.send(payload)\n", solve);
  fputs("# p.sendline()\n", solve);
  fputs("p.interactive()\n", solve);

  





  return 0;
}
