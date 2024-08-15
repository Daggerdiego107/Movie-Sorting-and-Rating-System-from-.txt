# Movie-Sorting-and-Rating-System-from-.txt

This is a C++ project that like any other requires you to have a compiler of your choice, in my case I used a Windows Subsystem for Linux (WSL) where I installed and used Ubuntu 22.04.4 LTS for its compiling and development. This is a OOP project that uses inheritance, polymorphism, operator overloading, references as well as many other concepts.

It also divides in 3 parts:
- Each class has its own .cpp and .h files
- A main.cpp file
- The text file that cointains the movies and episodes in a special format

# Text File Format:

  Movies:
  p,20191245,The Lion King,118,drama
  (Type),(ID),(Name),(Duration),(Genre)

  Episodes:
  c,20160150-S02E09,Chapter Nine: The Gate,62,accion,Stranger Things T2,9
  (Type),(ID),(Episode Name),(Duration),(Genre),(Series Title and Season),(Episode Number)

In the .txt file format it uses a type "c" for episodes of a specific series and type "p" for movies. You can add your own text following the formats provided above to test it out with further cases
