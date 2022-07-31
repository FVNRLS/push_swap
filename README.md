**About The Project**
This project will make you sort data on a stack in ascending order, with a limited set of instructions, using the lowest possible number of actions. For sorting you can use only 2 stacks: Stack a and Stack b. The sorting depends on the stack size (different algorithms are used).
If the stack could not be created (e.g. in case of invalid input), an error message message is returned.
Otherwise, the return of the program are the instructions used for sorting.

**Getting Started**

to compile only the sorting program:
make all

to compile sorting program together with checker
make bonus

**Prerequisites**

➡ Installed C-Compiler like gcc, cc or clang.

**Usage**

To use only the sorting program, type:
  ./push_swap <numbers>
Example:
  ARG="494 656 601 385 383 427 607 838 627 23 53 43 56 4564 234 233 565 676 5651 890 5758 098 54 65 34 67565 6778 232"
  ./push_swap $ARG
  
To use the sorting program together with checker, type:
  ./push_swap <numbers> | ./checker
  


**Roadmap**

:boom: Resolve segfault behaviour for big stack sizes on Linux machines.

**Contributing**

If you have a suggestion that would make this better, please fork the repo and create a pull request. You can also simply open an issue with the tag "enhancement". Don't forget to give the project a star! Thanks again!

**Acknowledgments**


