/*
 * File: pager-predict.c
 * Author:       Andy Sayler
 *               http://www.andysayler.com
 * Adopted From: Dr. Alva Couch
 *               http://www.cs.tufts.edu/~couch/
 *
 * Project: CSCI 3753 Programming Assignment 4
 * Create Date: Unknown
 * Modify Date: 2012/04/03
 * Description:
 * 	This file contains a predictive pageit
 *      implmentation.
 */

#include <stdio.h> 
#include <stdlib.h>

#include "simulator.h"

void pageit(Pentry q[MAXPROCESSES]) { 
    
    /* This file contains the stub for a predictive pager */
    /* You may need to add/remove/modify any part of this file */
   
    
    /* Local vars */
    
    int process;
    int page;
    int pc;


    //possible next pages given current page
    //-1 is filler if there are not enough possible pages
    //only did pages 0-14 because on analysis, pages 15-19
    //were never used
    int nextPages[15][3]={
     {1,-1,-1},
     {2,-1,-1},
     {3,-1,-1},
     {4,10,0,},
     {5,-1,-1},
     {6,-1,-1},
     {7,-1,-1},
     {8,-1,-1},
     {0,9,-1},
     {10,-1,-1},
     {0,11,-1},
     {12,0,-1},
     {13,-1,-1},
     {0,9,14},
     {0,-1,-1}};


    for(process = 0; process< MAXPROCESSES; process++){
        if(q[process].active) {

            //declare array of pages for current process 
            //0 = page not needed 
            //1 = page needed
            int addPages[15]= {0};
       
            // program counter for process
            pc = q[process].pc;        
            page = pc/PAGESIZE; 
            addPages[page]= 1;

             //find current page's possible next pages 
            for(int i = 0; i < 3; i++){
                if(nextPages[page][i] != -1){
                    addPages[nextPages[page][i]] = 1;
                     //add next page's next pages if it is 100 percent chance
                    //that current page goes to next page
                    if(nextPages[page][1] == -1 && i ==0){
                        for(int y = 0; y<3;y++){
                            if(nextPages[nextPages[page][0]][y] != -1){
                                addPages[nextPages[nextPages[page][0]][y]] = 1;
                        }

                        }
                    }
                      
                }
            }

       
            for(int j = 0; j < 15; j++){
                if(addPages[j]== 1){
                   if(!q[process].pages[j]){
                    pagein(process,j);
                    }
                        
                }else if(q[process].pages[j]){
                    pageout(process,j);
                }
                
            
        }
        
    }
    }
}
