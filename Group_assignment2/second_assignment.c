#include <stdio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#define MAXN 1500

int continueOrquit();
int isWrong(char answer[]);

int main(void) {
  char questions[10][MAXN]={"1) What distinguishes 'software engineering' from 'programming' or 'computer science'?","2) Software engineering can be thought of as 'programming integrated over time'.What practices can we introduce to our code to make it   sustainable (able to react to necessary change) over its life cycle, from conception to introduction to maintenance to deprecation?","3) Why if you are maintaining a project that is used by other engineers, the most important lesson about 'it works' versus 'it is maintainable' is given by the 'Hyrum’s Law' and discussions of change and maintenance over time must be aware of it?","4) Teamwork is without doubt the best route to producing great software, so how does one build (or find) a great team and what are the related 'three pillars' of social skills?","5) Perhaps no software engineering tool is quite as universally adopted throughout the industry as version control.What are the differences between Centralized VCS Versus Distributed VCS and why their use has become such an unambiguous norm in software engineering?","6) My program for X failed the testing and gave error Y. The last change I made was Z, can you help take a look?","7)	My program must perform task X. Its time complexity should be as small as possible. Each data structure has its own advantage, Y is faster for W meanwhile Z is faster for V. Which data structure should I use? Data structure Y or data structure Z?","8)	Usually, a code has to be as efficient as possible, but at the same time it should readable and maintainable. How do we find the right balance between readability and time efficiency?","9)	It’s important to have a code which satisfies the client, and so it should work in all scenarios. How to write meaningful unit tests to test the functionality and efficiency of the code?","10) How should the code be structured for it to be as readable and maintainable as possible? When should we create a different function because the other one is too large becoming incomprehensible?"};
  char rightanswers[10][MAXN]={"The field of Software Engineering focuses on applying engineering processes to the creation, maintenance and design of software at every level,so it implies the application of some theoretical knowledge to build something real and precise","There are mainly three fundamental principles that software organizations should keep in mind when designing, architecting, and writing their code: Time and Change (How code will need to adapt over the length of its life), Scale and Growth (How an organization will need to adapt as it evolves) and Trade-os and Costs (how an organization makes decisions, based on the lessons of Time and Change) and Scale and Growth.","Hyrum’s Law represents the practical knowledge that—even with the best of intentions, the best engineers, and solid practices for code review—we cannot assume perfect adherence to published contracts or best practices. As an API owner, you will gain some flexibility and freedom by being clear about interface promises, but in practice, the complexity and difficulty of a given change also depends on how useful a user finds some observable behavior of your API.","These three principles are the foundation on which all healthy interaction and collaboration are based. Pillar 1: 'Humility', you are not the center of the universe (nor is your code!). You’re neither omniscient nor infallible. You’re open to self-improvement. Pillar 2: 'Respect', you genuinely care about others you work with. You treat them kindly and appreciate their abilities and accomplishments. Pillar 3: 'Trust', you believe others are competent and will do the right thing, and you’re OK with letting them drive when appropriate. If you perform a root-cause analysis on almost any social conflict, you can ultimately trace it back to a lack of humility, respect, and/or trust.","In centralized VCS implementations, the model is one of a single central repository (likely stored on some shared compute resource for your organization), while a Distributed VCS world does not enforce the constraint of a central repository: if you have a copy (clone, fork) of the repository, you have a repository that you can commit to as well as all of the metadata necessary to query for information about things like revision history. Recall that software engineering is programming integrated over time; we’re drawing a distinction (in dimensionality) between the instantaneous production of source code and the act of maintaining that product over time. That basic distinction goes a long way to explaining the importance of, and hesitation toward, VCS: at the most fundamental level, version control is the engineer’s primary tool for managing the interplay between raw source and time. We can conceptualize VCS as a way to extend a standard filesystem.","First of you all you have to check the error messages. The error messages consist of two parts, the error message and the stack trace. The error message is what’s wrong- good error messages are helpful and tell you what you should do. The stack-trace/tracebacks on the other hand is where it’s wrong. So it’s important to understand the error message as it allows us to identify immediately the whereabouts and the reason of the encountered problems.","Since the program is commissioned by the client, then the programmer must first understand what the objective and the feature is needed most, according to his needs then we know if we have to put more weight  whether on W or on V, after all this process of careful analysis of the conceptualized problem we can start design the optimal algorithm and data structure for it.","We can use a citation by Abelson & Sussman: Programs must be written for people to read, and only incidentally for machines to execute, which means in general It’s more important that a program can be easily understood than for it to be as efficient as possible, since nowadays thanks to the hardware resources we have, performance ceased to be a major limiting fact. Efficiency of the program becomes important only when the performance may become a major issue for the normal functioning of the code, however overall simplicity, readability is still more important, since performance optimized code is more complex, harder to read and maintain, and surely more bug-prone than the simplest working solution.","For unit testing, we can follow 2 types of approaches: Test driven where first you do the tests and then the code, and vice versa code first, test second. Instead of writing code, then writing test.  Write code then look at what you think the code should be doing. Think about all the intended uses of it and then write a test for each case. Writing tests is usually faster but more involved than the coding itself. The tests should test the intention. Thinking about the intentions most of the time you wind up finding corner cases which you didn’t consider beforehand.","When it comes to making readable and maintainable code, there are many rules. First, it’s important to have comments and a nitid documentation, while it’s important to have comments, at the same time you must be careful to avoid obvious comment which sometimes can do more harm than good. Second, it’s important to follow a consistent style of indentation, naming scheme and whenever it’s possible group few lines of code which are similar (for example codes to load the templates). Worth mentioning is also the DRY principle which stands for Don’t Repeat Yourself, it follows the principle: automate repetitive task, so the same piece of code should not be repeated over and over again. Avoid deep nesting as it makes the hard to read and follow and therefore should also limit the line length. Last not for importance is the name of variables, they shouldn’t be letters but have a meaning which can be understood right away by others programmer. It’s important to never create a function which is too large, as it becomes difficult to follow the logical reasoning behind it and to maintain, most of the time it can be divided in smaller pieces which are more readable and maintainable."};
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
        printf("Answer %d is wrong, the correct answer is:\n%s\n",i+1,rightanswers[i]);
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