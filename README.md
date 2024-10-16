## Movie-Booking-CLI

This is a mini project in C language on a movie booking UI.

It is a menu driven C program which is a simulation of a movie booking system.

There is a csv file, which manages some booked seat numbers. Essentially everytime a seat is booked using main.c the csv file
is updated. However this update is valid only for the instance of the run. Once you exit the program and restart, the previously
booked seats are still empty.

Also in the repository might be an executable called main. You can ignore it or use the same name "main" when you create the binary to run your C Code.
Please note, main was created on MacOS and might not run on Windows. You will have to compile main.c in that case to create your own executable. 
You can conpile a C code using `gcc main.c -o main`

Ensure that you have gcc installed on your system.

Instructions to run the code:

```sh
gcc main.c -o main
./main
```
