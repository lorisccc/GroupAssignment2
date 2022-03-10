import time

def main():
    questions=["1) My program for X failed the testing and gave error Y. The last change I made was Z, can you help take a look?",
    "2)My program must perform task X. Its time complexity should be as small as possible. Each data structure has its own advantage, Y is faster for W meanwhile Z is faster for V. Which data structure should I use? Data structure Y or data structure Z?",
    "3)Usually, a code has to be as efficient as possible, but at the same time it should readable and maintainable. How do we find the right balance between readability and time efficiency?",
    "4)It’s important to have a code which satisfies the client, and so it should work in all scenarios. How to write meaningful unit tests to test the functionality and efficiency of the code?",
    "5)How should the code be structured for it to be as readable and maintainable as possible? When should we create a different function because the other one is too large becoming incomprehensible?"]
    answers=["1","2","3","4","5"]
    quit=False
    while(not quit):
        correct=0
        wrong_answers=[0,0,0,0,0,0,0,0,0,0]
        start=time.time()
        for i in range(5):
            answer=input(f"{questions[i]}\n")
            if len(answer)==0 or not(answer.isalnum()) :
                wrong_answers[i]=1
            else:
                correct+=1
        end=time.time()
        print(f"Right answers: {correct}")
        print(f"Time: {end-start}")
        for i in range(10):
            if wrong_answers[i]==1:
                print(f"Right answer for question {i+1}:\n{answers[i]}")
        choice=input("Continue or quit(enter the word or 1 for continue and 0 for quit)").upper()
        if choice==0 or choice =="QUIT" or len(choice)==0:
            quit=True

main()



if __name__ == '__main__':
    main