#include <stdio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#define MAXN 1000

int continueOrquit();
int isWrong(char answer[]);

int main(void) {
  char questions[10][MAXN]={"1) What distinguishes 'software engineering' from 'programming' or 'computer science'?","2) Software engineering can be thought of as 'programming integrated over time'.What practices can we introduce to our code to make it   sustainable (able to react to necessary change) over its life cycle, from conception to introduction to maintenance to deprecation?","3) Why if you are maintaining a project that is used by other engineers, the most important lesson about 'it works' versus 'it is maintainable' is given by the 'Hyrum’s Law' and discussions of change and maintenance over time must be aware of it?","4) Teamwork is without doubt the best route to producing great software, so how does one build (or find) a great team and what are the related 'three pillars' of social skills?","5) Perhaps no software engineering tool is quite as universally adopted throughout the industry as version control.What are the differences between Centralized VCS Versus Distributed VCS and why their use has become such an unambiguous norm in software engineering?","6) My program for X failed the testing and gave error Y. The last change I made was Z, can you help take a look?","7)	My program must perform task X. Its time complexity should be as small as possible. Each data structure has its own advantage, Y is faster for W meanwhile Z is faster for V. Which data structure should I use? Data structure Y or data structure Z?","8)	Usually, a code has to be as efficient as possible, but at the same time it should readable and maintainable. How do we find the right balance between readability and time efficiency?","9)	It’s important to have a code which satisfies the client, and so it should work in all scenarios. How to write meaningful unit tests to test the functionality and efficiency of the code?","10) How should the code be structured for it to be as readable and maintainable as possible? When should we create a different function because the other one is too large becoming incomprehensible?"};
  char rightanswers[10][MAXN]={"1","2","3","4","5","6","7","8","9","10"};
  int wronganswers[10]={0,0,0,0,0,0,0,0,0,0};
  int continuing=1;
  int correct;
  char answer[MAXN];
  while(continuing){
    for(int j=0; j<10;j++){
      wronganswers[j]=0;
    }
    correct=0;
    time_t start,end;
    time(&start);
    for(int i=0; i<10; i++){
      printf("%s\n",questions[i]);
      printf("Answere here or select ENTER to skip the question.\n");
      fgets(answer,MAXN,stdin);
      if(isWrong(answer)){
         wronganswers[i]=1; 
      }
      else{
        correct++;
      }
    }
    time(&end);
    double elapsed = difftime(end,start);
    printf("Correct answers %d\n", correct);
    printf("Time: %.2lf\n",elapsed);
    for(int i=0; i<10;i++){
      if(wronganswers[i]){
        printf("%s\n",rightanswers[i]);
      }
    }
    continuing=continueOrquit();
  }
}

// The feunction ask the user whether he wants to continue the test or quit
int continueOrquit() {
  int choice;

  printf("Enter '1' to continue the test, or '0' to quit:\n");
  while (((scanf("%d", &choice) != 1)) || (choice != 1) && (choice != 0)) {
    printf("Invalid input, try again.\n");
    printf("Enter '1' to continue the test, or '0' to quit:\n");
  }
  getchar();
                              
  return choice;
}

// The function check if the given answer is wrong
int isWrong(char answer[]) {


  // 1 case: No answer given
  if ( strlen(answer) == 0) {
    return 1;
  }
  // 2 case: The answer does contains at least one alphanumerical character
  for (int i=0; i < strlen(answer); i++) {
    if (isalnum(answer[i])) {
      // It contains at least one alphanumerical character
      return 0;
    } 
  }
  // 3 case: The anser does not contain any alphanumerical character, so
  // it's considered wrong
  return 1;
}

// Questions
/*
1) What distinguishes “software engineering” from “programming” or “computer 
science”?
2) Software engineering can be thought of as “programming integrated over time.” 
What practices can we introduce to our code to make it sustainable (able to react to 
necessary change) over its life cycle, from conception to introduction to maintenance 
to deprecation?
3) Why if you are maintaining a project that is used by other engineers, the most 
important lesson about “it works” versus “it is maintainable” is given by the “Hyrum’s
Law” and discussions of change and maintenance over time must be aware of it?
4) Teamwork is without doubt the best route to producing great software, so how does 
one build (or find) a great team and what are the related “three pillars” of social skills?
5) Perhaps no software engineering tool is quite as universally adopted throughout the 
industry as version control. What are the differences between Centralized VCS Versus 
Distributed VCS and why their use has become such an unambiguous norm in 
software engineering?
6) My program for X failed the testing and gave error Y. The last change I made was Z, can you help take a look?
7)	My program must perform task X. Its time complexity should be as small as possible. Each data structure has its own advantage, Y is faster for W meanwhile Z is faster for V. Which data structure should I use? Data structure Y or data structure Z?
8)	Usually, a code has to be as efficient as possible, but at the same time it should readable and maintainable. How do we find the right balance between readability and time efficiency?
9)	It’s important to have a code which satisfies the client, and so it should work in all scenarios. How to write meaningful unit tests to test the functionality and efficiency of the code?
10)	How should the code be structured for it to be as readable and maintainable as possible? When should we create a different function because the other one is too large becoming incomprehensible?

*/

/*
clock_t b1 = clock();

clock_t e1 = clock();
double elapsed1 = (double) (e1 - b1) / CLOCKS_PER_SEC;
*/

/*
time_t start,end;
  double dif;

  time (&start);
  // Do some calculation.
  time (&end);
  dif = difftime (end,start);
  printf ("Your calculations took %.2lf seconds to run.\n", dif );

  return 0;
*/