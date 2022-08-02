# push_swap

**About The Project**

This project will make you sort data on a stack in ascending order, with a limited set of instructions, using the lowest possible number of actions. For sorting you can use only 2 stacks: Stack a and Stack b. The sorting depends on the stack size (different algorithms are used).
If the stack could not be created (e.g. in case of invalid input), an error message is returned.
Otherwise, the return of the program are the instructions used for sorting.

<br>**Getting Started**

* to compile only the sorting program:
<br>`make all`


* to compile the checker
<br>`make bonus`

<br>**Prerequisites**

* Installed C-Compiler like gcc, cc or clang.


<br>**Usage**

* To use only the sorting program, type:

  <br>`./push_swap <NUMBERS>`
  <br><br>_Example:_
  <br><br>`ARG="494 656 601 385 383 427 607 838 627 23 53 4564 234 233 565 676 5651 890 5758 098 54 65 34 67565 6778 232"`

  <br>`./push_swap $ARG`  
  <br>
* To use the sorting program together with checker, type:

    <br>`./push_swap <NUMBERS> | ./checker <NUMBERS>`

    <br>_Example_:

    <br>`./push_swap $ARG | ./checker $ARG`

<br>**Roadmap**

* :boom: Resolve segfault behaviour for big stack sizes on Linux machines.

* Set parting of chunks according to mathematical formula.

<br>**Contributing**

If you have a suggestion that would make this better, please fork the repo and create a pull request. You can also simply open an issue with the tag "enhancement". Don't forget to give the project a star! Thanks again!


<br>**Acknowledgments**

* Many thanks for support and patience to: 

    :heart_decoration: Heleen [https://github.com/heleenoomen]


* Great tester to validate the number of instructions:
  
    https://github.com/lmalki-h/push_swap_tester


* Simple, but very useful visualizer for the sorting algorithm:

    https://pypi.org/project/push-swap-gui/
  
