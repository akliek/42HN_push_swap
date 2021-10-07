# 42HN_push_swap
Summary:

This programm sort data on a stack, with a limited set of instructions, using the lowest possible number of actions and knowledge about standard sorting algorithms.

Foreword:

The Push_swap project is a very simple and highly effective algorithm project: data will need to be sorted. You have at your disposal a set of int values, 2 stacks and a set of instructions to manipulate both stacks. Goal ? Write a program in C called push_swap which calculates and displays on
the standard output the smallest program using Push_swap instruction language that sorts the integer arguments received.

Links:

Wikipedia about sorting algorithms: https://en.wikipedia.org/wiki/Sorting_algorithm

Subject PDF: https://github.com/akliek/42HN_push_swap/blob/master/en.subject.pdf

# Clone
Open a terminal and run following command:
```
git clone <repository url>
```
# Instalation
Then go to created repository and run following command:
```
make
```
# Run
After insatalation run following command:
```
./push_swap <numbers>
```
# What does otput mean?
```
Programm sort numbers by using following operations:
      sa : swap a - swap the first 2 elements at the top of stack a.
           Do nothing if there is only one or no elements.
      sb : swap b - swap the first 2 elements at the top of stack b.
           Do nothing if there is only one or no elements.
      ss : sa and sb at the same time.
      pa : push a - take the first element at the top of b and put it at the top of a.
           Do nothing if b is empty.
      pb : push b - take the first element at the top of a and put it at the top of b.
           Do nothing if a is empty.
      ra : rotate a - shift up all elements of stack a by 1.
           The first element becomes the last one.
      rb : rotate b - shift up all elements of stack b by 1.
           The first element becomes the last one.
      rr : ra and rb at the same time.
      rra : reverse rotate a - shift down all elements of stack a by 1.
            The last element becomes the first one.
```
# Visualization
For visualization and understanding how algorithm works I recommand use this program: https://github.com/o-reo/push_swap_visualizer
# How to run visualizer?
Firstly you need to install python3 with following command:
```
brew install python3
```
If you dont have Homebrew manager firstly install it by running following command:
```
ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)" 2> /dev/null
```
Open a terminal in push_swap project folder and run following command:
```
git clone https://github.com/o-reo/push_swap_visualizer.git
```
After that move file pyviz.py to push_swap project folder and run following command:
```
python3 pyviz.py `ruby -e "puts (<min_number>..<max_number>).to_a.shuffle.join(' ')"` 
```

