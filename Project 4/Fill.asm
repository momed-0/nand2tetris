//Author: Mohammed N
// File name:Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.



//infinite loop to check the keypress
(LOOP)
@KBD
D = M;
@WHITE
D;JEQ

//else blacken the screen
@row
M = 0;
(BLACKLOOP)

//check the condition --8191 registers
@row
D = M;
@8192
D = D -A;
@LOOP
D;JEQ

//blacken
@SCREEN
D = A;
@row
D = D + M
@address
A = D;
M = -1;

//increment the row and go to blackloop
@row
M = M + 1;
@BLACKLOOP
0;JMP






//code to white the pixel
(WHITE)
@row
M = 0;

(WHITELOOP)

//check the condition --8191 registers
@row
D = M;
@8192
D = D -A;
@LOOP
D;JEQ

//whiten
@SCREEN
D = A;
@row
D = D + M
@address
A = D;
M = 0;

//increment the row and go to whiteloop
@row
M = M + 1;
@WHITELOOP
0;JMP