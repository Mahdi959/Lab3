//*******************************
//
//File Name: cs211_lab3b
//
//A Program to 
//
//
//Programmer: "Mahdi Ashrafee"
//
//Date Written: "Oct 21 2022"
//
//Data last revised: "Oct 21 2022"
//
//*******************************
#include <stdio.h>
#include <stdlib.h>

#define BUFFSIZE 81

int main()
{
    File *input_file,
        *output_file;
        
    char input_name[15],
         output_name[15],
         buffer[BUFFSIZE];
         
    int     c;
    
    fputs("***File Copy Program***, stdout");
    
    fprintf(stdout,"Enter the name of the input file :");
    fscanf(stdin, "%s",input_name);
    
    fprintf("Enter the name of the output file :" )
    
    
    
    input_file = fopen(input_name,"r");
    if (input_file == Null)
    {
        fputs("***Can't open input file***",stdout);
        exit(0);
    }
    output_file = fopen(output_name,"w");
    if(output_file == Null){
        fputs("***Can't open output file***",stdout);
        exit(0);
    }
    
    while((fgets(buffer,BUFFSIZE,input_file)) != NULL)
     fputs(buffer,output_file);
     
     fclose(input_file);
     fclose(output_file);
    

    return 0;
}
