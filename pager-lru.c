/*
 * File: pager-lru.c
 * Author:       Andy Sayler
 *               http://www.andysayler.com
 * Adopted From: Dr. Alva Couch
 *               http://www.cs.tufts.edu/~couch/
 *
 * Project: CSCI 3753 Programming Assignment 4
 * Create Date: Unknown
 * Modify Date: 2012/04/03
 * Description:
 * 	This file contains an lru pageit
 *      implmentation.
 */

#include <stdio.h> 
#include <stdlib.h>

#include "simulator.h"

void pageit(Pentry q[MAXPROCESSES]) { 
    
    /* This file contains the stub for an LRU pager */
    /* You may need to add/remove/modify any part of this file */

    /* Static vars */
    static int initialized = 0;
    static int tick = 1; // artificial time
    static int timestamps[MAXPROCESSES][MAXPROCPAGES];
  

    /* Local vars */
    int proctmp;
    int pagetmp;
    int pc;
    int lru = 1000000000;
    int replacePage;

    /* initialize static vars on first run */
    if(!initialized){
	for(proctmp=0; proctmp < MAXPROCESSES; proctmp++){
	    for(pagetmp=0; pagetmp < MAXPROCPAGES; pagetmp++){
		timestamps[proctmp][pagetmp] = 0; 
	    }
	}
	initialized = 1;
    }
    
for(proctmp = 0; proctmp< MAXPROCESSES; proctmp++){


    if(q[proctmp].active) {
        // program counter for process
        pc = q[proctmp].pc;              
        pagetmp = pc/PAGESIZE; 
        
        timestamps[proctmp][pagetmp] =tick;
         //check if page is swapped in
        if(!q[proctmp].pages[pagetmp]) {
            if(!pagein(proctmp,pagetmp)){
                //find page that has not been used most recently for the given process
                    for(int page = 0; page < MAXPROCPAGES; page++){
                        if(timestamps[proctmp][page]< lru
                         && q[proctmp].pages[page]){
                            replacePage = page;
                            lru = timestamps[proctmp][page];
                    
                   }
                }
                pageout(proctmp,replacePage);
            }
        } 
    }
    tick++;
}

    
} 
