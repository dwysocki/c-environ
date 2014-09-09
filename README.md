# c-environ


CSC344 Assignment 1:

The main purpose of this program is to use C library and system calls, along with dynamic memory allocation. The program maintains a sorted linked list of items with two fields. The first, "key" should hold a string representing the name for a value, and the second, "contents" should hold the string value of this item, as obtained from some sytem or library command. The running program allows queries of keys, as well as listing of all the pairs, Exactly how to prompt and display them is up to you. The keys contain the following (hints on where to find these are in parentheses).

- progname - the name of the running program (argv)
- user - the login name of the user (getlogin)
- host - the name of the machine the program is running on (uname)
- uid - the users userid # (getuid)
- tty - the user's current terminal (ttyname)
- date - the current day and time (asctime)
- cwd - the current working directory (getcwd)
- files - the number of files in the current directory (readdir)
- term - the user's terminal type (getenv)
- args - the total number of chars of all program arguments (argv)

Methods for obtaining a couple of these will be given in class. 
