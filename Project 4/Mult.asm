//Author: Mohammed N
// File name: Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)
//
// This program only needs to handle arguments that satisfy
// R0 >= 0, R1 >= 0, and R0*R1 < 32768.

// Multiplication is adding first number second times

//We can also modify the program to loop for smaller no of times
//by taking R0 as larger number and R1 as smaller number


//loop variable start with 0
@i
M = 0;

//result variable
@result
M = 0;

(LOOP)
//check if the condition is valid
//break when i = R1
@i
D = M;
@R1
D = D - M;
@END
D;JEQ

//result = result + R0
@R0
D = M;
@result
M = M + D;

//increment i (the counter)
@i
M = M + 1;

//jump to loop
@LOOP
0;JMP




//store the result in R2 and loop indefinitely
(END)
@result
D = M;
@R2
M = D;
(STOP)
@STOP
0;JMP