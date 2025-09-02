# to-do list

## 02/09

- [ ] check medium post on chunk sorting, in study-notes.md
- [ ] fix sort_five

## 01/09

- [X] tiny sort done
- [ ] ft_big_sort missing
- [ ] A and B are not using (rr) and (rrr)

## 31/08

- [ ] make b have a target node to be at the top as well. it should always be the biggest number from its chunk
- [ ] rot/rev rot until that target is at the top. Thats when you check for rr/rrr

## 30/08

- [X] general cleanup and divided functions with +25  lines
- [X] added check before long array creation that checks is arguments are digits
- [X] working functions that calculate costs, send nodes in target chunk to top and pushes said nodes
- [ ] next step is to sort each chunk after they are sent to stack B
- [X] for a stack of size 3 program segfaults, need to hard code a sorting for <= 3

## 29/08

- did further work on chunk push
- [X] created a mini_stack_print function that prints both A and B in a simple more visual format

## 28/08

- [X] debug ft_chunk_cost and ft_sendchunk, A stays unchanged and B is empty, maybe i dont need double pointers
    - [X]  NOT DONE, BOT IS ACTING LIKE NODE FURTHREST FROM BOTTOM IS BETTER, THIS IS THE OPPOSITE
    - fixed
- [X] push all the nodes in target chunk from A to B
- [ ] start sorting B

## 27/08

- [X] debug ft_targetnode, segfaulting in some cases;
- [X] try to do push operations without using malloc;

## 26/08

- [X] completed ft_checksort
- [X] todo from yesterday

## 25/08

- [X] added chunk id to each node when creating Stack A
- [X] finish function to check for sorted stack
- [X] function to search for nodes in Stack A that knows what chunk we want to process and push to Stack B
- [X] [sorta] function that works with the one above that pushes nodes to B and does the necessary movements to do so, doing so in the most effiecient way possible (possible as in my capabilities [and my time])

## 23/08

- [X] created a sqrt_floor fucntion to determine chunksize
- [X] still need to add chunk id to each node, according to its index

## 19/08

- [X] continue chunking sort logic (see  chunking.c and copilot chat)
- [X] started learning binary search, using it in
    * chunk logic calculation
    * searching for numbers in tab to get their indexes

Note!
- don't get lost in the sauce, stop researching if it is not gonna be applicable
- evaluate your progress aka pick up the pace

## 08/08

- [X] libft Makefile
    - needs work, very rough atm

- [ ] valgrind reports conditional jumps when testing movements

## 06/08

- [X] ground-work for actual algorythm creation is done
- [X] movement functions done (writing each instruction eg "ra" will be done after movementfunction is called)
    - [X] created a tester function for movements
    - [X] Stack B is created when empty and PushB is called

- [X] libft/gnl/pf port missing Makefile
- [X] start working on actual push_swap logic

## 10/07

libft port almost done, still need to:
- [X] create a Makefile that compiles everything;
- [X] double check that everything is portable and possible conflicts between projects

- [X] start writing my push_swap logic detailed yesterday

## 09/07

- [X] need to finish ft_printf port to libft
- [X] then add libft to push_swap
- [X] optional: port gnl as well

regarding push_swap:
- when converting args to ints:
    - I will add them to an int array and to a linked list
    - the linked list will have a pointer to the next node and two more variables:
    - an index which will refer to its organized position
    - the value which it must hold, the arg conv to int

How will I determine the correct indexes? By organizing the int array with sort_int_tab and when I need to know were a node should be,
I will do a number search of the value which that node holds in the sorted array, then set the index var inside that node to the index
of the number in the array.

The indexes vars in each node will all be **-1** before getting a correct index set.
