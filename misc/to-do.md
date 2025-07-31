# to-do list

## 10/07

libft port almost done, still need to:
- [ ] create a Makefile that compiles everything;
- [ ] double check that everything is portable and possible conflicts between projects

- [ ] start writing my push_swap logic detailed yesterday

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
