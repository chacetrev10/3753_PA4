# 3753_PA4

Contact Info: Chace Trevino chtr8005@colorado.edu

Makefile(Unchanged from one provided)

-File that contains the commands that tells the compiler to create executable tests

pager-lru.c

-My implementation of least recently used paging algorithm

pager-predict.c

-My implementation of a paging algorithm that determines the current page, loads in the current page, and
also loads in future pages that might be needed. The pagein function from simulator.c has a line that will 
tell you what page is being loaded in. After running pager-lru, I used printf("process=%2d page=%3d start pagein\n",process,page);
for every time pagein is executed. I echo'd this output to a file in which I parsed the data so that each process
had its own file showing the flow of its process and pages. After looking over all the files, I was able to determine
given a page, the next possible pages it would go to. 

# To run and execute:

1) Import my pager-lru.c and pager-predict.c into the original PA4 folder

2) Type "make" in command prompt in correct directory

3) ./pager-lru or ./pager-predict to test
