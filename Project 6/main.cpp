#include <fstream>    // read write files
#include <queue>      //internal buffer between each pass
#include <string>     //instruction are saved as C++ stings.
#include <sstream>  //for clearing the whitespaces

#include "parser.hpp"
#include "symbolTable.hpp"

using namespace std;

//defining symbol table and parsser
SymbolTable MyST;
Parser MyParser;

int main(int argc, char const *argv[]) {
    string fnameIn, fnameOut;   //input and output file names
    ifstream fIn; //input file -- *.asm
    ofstream fOut; //output file -- *.hack

    //FIFO Buffer to parse and process Instructions
    queue<string> queue1, queue2; 

    /* handling parameters*/
    if (argc < 2) {
        throw runtime_error("main(): plseas specify input file MyAssembler *.asm [*.hack]");
    } else {
        fnameIn = string(argv[1]);
        // check if the input file is a .asm?
        if (fnameIn.find(".asm") == string::npos)
            throw runtime_error("main(): input fime must be .asm");
        fIn.open(fnameIn);
        // check the specified file is able to open?
        if (!fIn.is_open()) {
            throw runtime_error("main(): unable to open file " + fnameIn);
        }
        //process the output file name
        if (argc == 2) {
            string::size_type idx = fnameIn.find_last_of('.');  // find the base name
            fnameOut = fnameIn.substr(0, idx) + ".hack";        // change to .hack
        } else if (argc == 3) {
            fnameOut = string(argv[2]);
        } else {
            throw runtime_error("main(): too many parameters");
        }
        //open the output file
        fOut.open(fnameOut);
        if (!fOut.is_open()) {
            throw runtime_error("main(): unable to open file " + fnameOut);
        }


        /* Pre pass: read source file clean-up the code */
        string line;
        /* read each line from the .asm file */
        while (getline(fIn, line)) {
            /* remove comments */
            string::size_type idx = line.find("//");
            string lineRmComm = line.substr(0, idx);

            // Remove spaces
            stringstream ss(lineRmComm);
            string instruction;
            string lineWithoutSpaces;
            while (ss >> instruction) {
                lineWithoutSpaces += instruction;
            }
            //if the line is empty donot add that instruction queue
             if (lineWithoutSpaces.empty()) continue;
            

            queue1.push(lineWithoutSpaces);

        }

        /* First pass read lables build symbol table*/
       
        while (!queue1.empty()) {
            line = queue1.front();
            queue1.pop();
           
            /* Is this line a L-instruction (Label) */
            if (line.find('(') != string::npos && line.find(')') != string::npos) {
                string::size_type idx_L = line.find_last_of('(');
                string::size_type idx_R = line.find_first_of(')');
                line = line.substr(idx_L + 1, idx_R - 1);
                //add the label to the symbol table with the labelCounter (hold the curren ROM address)
                MyST.addLabel(line);
                
                continue;  // skip the push to the queue2 (since a label)
            } else {
                MyST.incLabelCounter();  // move the label counter to the next line (ROM Address)
            }
            //if the line empty  don;t push
            if(line.empty()) continue;
            queue2.push(line);
        }

        /* Second pass Translate instructions */

        while (!queue2.empty()) {
            line = queue2.front();
            queue2.pop();
           
            string macCode = MyParser.parseInst(line);  // translate into machine code
            //write to output file
            fOut << macCode << endl;
        }
        //close all the files
        fIn.close();
        fOut.close();
       
    }
    return 0;
}