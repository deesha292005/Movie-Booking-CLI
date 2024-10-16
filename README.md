## Movie-Booking-CLI

This is a mini project in C language on a movie booking UI.

It is a menu driven C program which is a simulation of a movie booking system.
Currently it does a one time read from the csv file, purely for UI purposes.
It reads which seat numbers have been booked and displays them red, the others green, allowing users to purchase those seats.
The code however does not dynamically update the csv file, when a new seat is booked.

Instructions to run the code:

```sh
gcc -o main.c main
./main
```
