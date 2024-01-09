# 376_W23_CPP_Basics

>**Note:** Everything you program must be named *exactly* as written here.  Pay attention to upper/lower case.
>**Note:** There are a LOT of versions of C++.  If you run into questions, it is generally safe to look for C++2011 references unless otherwise noted.

Time to learn the basics of C++.  

**FIRST! -** Read the documentation at https://www.ibm.com/docs/en/zos/2.4.0?topic=only-overloading-operators-c.

Write down any questions you have and bring them to class.

Now, read up on what ```friend``` symbols are in C++.

Write down any questions you have and bring them to class.

## Tasks

1.  Create a class called ```Enemy```.  It should be broken up into a header file called ```enemy.h``` and a source file called ```enemy.cpp```.  It should have private instance variables called
	- name (```std::string```).  Cannot be blank or longer than 25 charaters.
	- hp (```int```).  Can't be less than zero.
	- speed (```float```). Must be between 0 and 1.0 (inclusive). 
	- Getters and setters for each property.  Naming convention must get ```getName```, ```setHp``` etc.  Setters must throw an exception (```std::invalid_argument``` is easiest) when a constraint is violated.

2.  Overload the ```<``` operator such that an instance is less than another instance when its ```hp``` is lower than the other instance.

3.  Overload the ```>``` and ```==``` operators.  Don't rewrite logic; rewrite them in terms of one another.  For instance, ```==``` means not ```<``` and not ```>```.

4.  Overload an ```ostream``` so that you can print a representation of an ```Enemy``` object.  It must follow the format ```name, hp, speed```, for instance, ```Flying Grizzywick, 200, 0.5```.  Note that ```ostream``` does not go inside of the class's namespace, but rather the global namespace.  It can be made a ```friend``` though, if we wish for it to be able to access private data of an ```Enemy```.

