# Pagerank
A C language implementation of the Pagerank algorithm applied to large graphs from the SNAP dataset.

## File Formatting
This program is compatible with the following format : [source id]\t[destination id]\n  
The files cannot have opening comments or any extraneous data.  

## Usage

To change the source file, damping factor or required precision edit pagerank.c and make the desired changes in the pagerank function call.

Build using the included makefile and run ./pagerank  

Output should resemble this :  

Reading file  
File read in 0 seconds et 0 miliseconds  
Sorted adjacency list, building transition matrix  
Transition Matrix Build, computing Pagerank  
Matrix width : 1  
Matrix height : 5  
( 0.25419182 )  
( 0.13803153 )  
( 0.13803153 )  
( 0.20599015 )  
( 0.26375502 )  
Ranks ordered by id  
Matrix width : 5  
Matrix height : 1  
( 0.13803153 0.13803153 0.20599015 0.25419182 0.26375502 )  
Ranks sorted from lowest to highest  
Ran for 64 iterations  
Ran in 0 seconds and 0 miliseconds

## Acknowlegements 
All code written by Simon Pereira  
Large graphs are from the SNAP datasets by Jure Leskovec and Andrej Krevl  
Available at https://snap.stanford.edu/data/