## Movie-Booking-CLI

This is a mini project in C language on a movie booking UI.

It is a menu driven C program which is a simulation of a movie booking system.

There is a csv file, which manages some booked seat numbers. Essentially everytime a seat is booked using main.c the csv file
is updated. However this update is valid only for the instance of the run. Once you exit the program and restart, the previously
booked seats are still empty.

Instructions to run the code:

```sh
gcc main.c -o main
./main
```
