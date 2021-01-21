/*
Rajpreet Judge
CSE 222
Nick Macias
01/23/2020

This program features linked lists and interacting with a list by adding, searching, deleteing nodes from this 
list. However I could not figure out how to sort the list with my add function and only managed to get the 
functionaility working of the program. deleting a node "works" if you delete a node lets say in the middle of a list
and then try to add a number the next value will skip over a good chunk of the nodes and point to the last node.
I lost quite a bit of hairs during this, was hoping to discuss where I went wrong during office hours
*/


#include<stdio.h>

//initializing my struct node
struct node{
  int data;
  int next;
  int valid;
};

#define MYNULL -1

//Function declarations
void init(struct node*);//done
int add(struct node*,int);
void print(struct node*);//done
int delete(struct node*, int);
int search(struct node*, int);//done
int get_node(struct node*);//done
void release_node(struct node*, int);//done

// main does the parsing the handles calling functions and user interface
void main() {
  
  struct node list[100];
  char input[120], letter[120], y;
  int num=0, result=0, index=0,ret, test;

  init(list);
  printf("> ");

  fgets(input,120,stdin);
  result = sscanf(input,"%s%d",letter,&num);

  if(result == EOF || result == 0) {
    printf("i number (where number is any legal integer). \n p This will print the list in order, on one line, with the numbers separated by spaces.\n s number, This searches for the given number, and prints either FOUND or NOT FOUND.\nd number, This deletes the node containing the given number, and prints either SUCCESS or NODE NOT FOUND. \n x, This should cause the program to exit.\n");
  }
    if(*letter == 'i') {

      if(search(list,num)==1) 
        printf("NODE ALREADY IN LIST\n");
      else if(add(list,num)==1)
        printf("SUCCESS\n");
      else
        printf("OUT OF SPACE\n");
    }
    if(*letter == 'p'){
      print(list);
    }
    if(*letter == 's'){
      int retval;
      if(search(list,num)==1)
        printf("NODE IS FOUND\n");
      else
        printf("NODE NOT FOUND\n");
    }
    if(*letter == 'd') {
     if(result == 1)
      printf("i number (where number is any legal integer). \n p This will print the list in order, on one line, with the numbers separated by spaces.\n s number, This searches for the given number, and prints either FOUND or NOT FOUND.\nd number, This deletes the node containing the given number, and prints either SUCCESS or NODE NOT FOUND. \n x, This should cause the program to exit.\n");

     else if(test = delete(list,num)==1)
       printf("NODE DELETED\n");
     else
       printf("NODE NOT FOUND\n");
    }     
    
    
  while(*letter != 'x') {
    printf("> ");
    fgets(input,120,stdin);
    result = sscanf(input,"%s%d",letter,&num);
    if(result == EOF) {
      printf("i number (where number is any legal integer). \n p This will print the list in order, on one line, with the numbers separated by spaces.\n s number, This searches for the given number, and prints either FOUND or NOT FOUND.\nd number, This deletes the node containing the given number, and prints either SUCCESS or NODE NOT FOUND. \n x, This should cause the program to exit.\n");
    }

    if(*letter == 'i'){
    
      if(search(list,num)==1) 
        printf("NODE ALREADY IN LIST\n");
      else if(add(list,num)==1) {
        printf("SUCCESS\n");
      }
      else
        printf("OUT OF SPACE\n");
      
    }
  
    if(*letter == 'p'){
      print(list);
    }
    if(*letter == 's'){
      int retval;
      if(search(list,num)==1)
        printf("NODE IS FOUND\n");
      else
        printf("NODE NOT FOUND\n");
    } 
    if(*letter == 'd') {
     if(result == 1)
      printf("i number (where number is any legal integer). \n p This will print the list in order, on one line, with the numbers separated by spaces.\n s number, This searches for the given number, and prints either FOUND or NOT FOUND.\nd number, This deletes the node containing the given number, and prints either SUCCESS or NODE NOT FOUND. \n x, This should cause the program to exit.\n");  
     else if(test = delete(list,num)==1)
       printf("NODE DELETED\n");
     else
       printf("NODE NOT FOUND\n");
    }   
  }
  return;
}


//searchs for the number you want to add or delete
int search(struct node*x, int num) { //done

  int ptr;
  ptr=x[0].next;

  while(ptr != MYNULL) { 
    if(x[ptr].data == num){
      return (1);
    }
    ptr=x[ptr].next;
  }
  return (0);
}

//initializes the linked list
void init(struct node * x) {//done

  x[0].data=42;
  x[0].next=MYNULL;
  x[0].valid=1;

  for(int i=1;i<100;i++) {
    x[i].data=0;
    x[i].next=-2;
    x[i].valid=0;
  }

  return;
}

//releases the node at user command
void release_node(struct node*x, int index) {//done

  x[index].valid=0;
  return;

}

//gets node location to add or returns -1 if full
int get_node(struct node*x) {//done

  for(int i=0;i<99;i++){
    if(x[i].valid==0){
      x[i].valid=1;
      return(i);
    }    
  }
  return(MYNULL);
}

//prints data values-----------------------------
void print(struct node*x) { //done

  int ptr;
  ptr=x[0].next;//next equals index
  while(ptr != MYNULL) {
    printf("%d  ",x[ptr].data);
    ptr=x[ptr].next;
  }
  printf("\n");
  return;
}

//----------------------------------- deletes values entered by user
int delete(struct node*x,int num) {

  int prev, curr;

  if(search(x,num) == 0)
    return 0;

  prev=0;
  curr=x[prev].next;

  printf("delete function x[prev] value %d", prev);

  while(curr != -1){
  if(x[curr].data == num) {
    x[prev].next=x[curr].next;
    release_node(x,curr);  
    return 1;
    }
  prev=curr;
  curr=x[curr].next;
  }
}
//suppose to add a number in sorted order but I managed to revert this function back to a "working" condition after turning it into a seg fault machine
int add(struct node*x, int num) {

  int index, prev, curr;
  index=get_node(x);
  printf("index = %d\n",index);
  prev=0;

   
  if(index == MYNULL)
    return 0;
  else{
    x[index].data=num;
    x[index-1].next = index;
    x[index].next=-1;
    return 1;
  }
}





