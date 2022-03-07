#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
using namespace std;

void operation(FILE *fout);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Wrong Input\nIt must be only one number\n");
        return 0;
    }
    FILE *fout = fopen("result.txt", "w");
    if (fout == NULL)
    {
        printf("Error with output file\n");
        return 0;
    }
    fprintf(fout, "2056308\n");
    int n = atoi(argv[1]);
    while (n--)
    {
        operation(fout);
    }
    fclose(fout);
    return 1;
}

void operation(FILE *fout)
{
    int rand_n = rand() % 3 + 3;
    vector<int> numbers(rand_n + 1);
    vector<int> op(rand_n);
    for (int j = 0; j < rand_n + 1; j++)
    {
        numbers[j] = rand() % 100 + 1;
    }
    // random number for operation 0-> add, 1-> subtract, 2-> multiplication, 3-> division;
    for (int j = 0; j < rand_n; j++)
    {
        op[j] = rand() % 4;
    }
    for (int j = 0; j < rand_n; j++)
    {
        fprintf(fout,"%d ",numbers[j]);
        switch (op[j])
        {
        case 0:
            fprintf(fout,"+ ");
            break;
        case 1:
            fprintf(fout,"- ");
            break;
        case 2:
            fprintf(fout,"x ");
            break;
        case 3:
            fprintf(fout,"/ ");
            break;
        default:
            break;
        }
    }
    fprintf(fout,"%d",numbers[rand_n]);
    for(int j=0; j<rand_n;j++){
        if(op[j]==2){
            numbers[j+1]=numbers[j]*numbers[j+1];
            numbers[j]=0;
            op[j]=-1;
        }
        else if(op[j]==3){
            numbers[j+1]=numbers[j]/numbers[j+1];
            numbers[j]=0;
            op[j]=-1;
        }
    }
    op.erase( remove (op.begin(), op.end(), -1), op.end());
    numbers.erase( remove (numbers.begin(), numbers.end(), 0), numbers.end() );
    int res=numbers[0],z=1;
    for(auto& it:op){
        if(it==0){
            res+=numbers[z];
        }
        else if(it==1){
            res-=numbers[z];
        }
        z++;
    }
    fprintf(fout," = %d\n",res);
}