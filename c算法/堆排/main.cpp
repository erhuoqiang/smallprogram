#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

vector<int> vector_random;
vector<int> vector_reversed;
vector<int> vector_sorted;

const int MAXSIZE = 1024;
/*  Implement a Heap class here (from the slides)  */
class Heap
{
private:
    unsigned int data[MAXSIZE];
    int last;

public:
    int compare_num;
    Heap(){last=-1; compare_num = 0;  for(int i=0;i<MAXSIZE;i++)data[i]=0;}  //因为后面判断第一次父节点是-1 没有进去所以compare_num一开始为1
    ~Heap() { }; //destructor
    void InsertHeap( unsigned int newthing);
    int DeleteRoot();
    void PrintHeap();
};


void Heap::PrintHeap()
{//print in array order
    //printf( "HEAP: \n" );
    for(int i=0; i<=last;i++){
    printf( "%d ",data[i]);
    }
    printf( "\n" );
}

//创建堆
void Heap::InsertHeap( unsigned int newthing)
{
    data[last+1]=newthing;
    last=last+1;
    int temp, swindex=last, parindex=0;  //swindex是当前插入的位置, parindex是代表父节点的位置
    bool swapping=true;
    while (swapping)
    {
        swapping=false;
        if(swindex%2==0) parindex=swindex/2-1;  //is a right child
        else  parindex=swindex/2;  //is a left child

        if(parindex >=0 &&   (compare_num++,data[swindex]>data[parindex]) )//你们老师PPT给的程序有个小BUG   这里需要加上父节点不为-1的判断并且放在 data[swindex]>data[parindex]前面
        {

            temp=data[swindex];
            data[swindex]=data[parindex];
            data[parindex]=temp;
            swapping=true;
            swindex=parindex;
        }
    }
}

//进行堆排序
int Heap::DeleteRoot()
{
    int temp = 0, last_num = last, temp_last = last;
    int  swindex=0, parindex=0;
    while(last_num != 0)
    {
        temp = data[last_num];
        data[last_num] = data[0];
        data[0] = temp;

        last_num--;

        last = 0;
        for( int i = 1; i <= last_num; i++ )
        {
            data[last+1]=data[i];
            last=last+1;
            swindex=last, parindex=0;  //swindex是当前插入的位置, parindex是代表父节点的位置


            if(swindex%2==0) parindex=swindex/2-1;  //is a right child
            else  parindex=swindex/2;  //is a left child

            if(parindex >=0 &&   (compare_num++,data[swindex]>data[parindex]) )//你们老师PPT给的程序有个小BUG   这里需要加上父节点不为-1的判断并且放在 data[swindex]>data[parindex]前面
            {
                    temp=data[swindex];
                    data[swindex]=data[parindex];
                    data[parindex]=temp;
            }

        }

    }
    last = temp_last;
    return 0;
}


/* this is a possible prototype for the heapsort function */
/* the char* filename is just for printing the name, the file is opened and dealt with in the main() */
void heapsort(vector<int> &sortingvector,int number_of_elements, char* filename){
  /* Heap myHeap; .//declare a Heap instance here */
  /* Using the sortingvector, INSERT elements into the Heap */
    class Heap heap;
    for(int i = 0; i < number_of_elements; i++)
    {
        heap.InsertHeap(sortingvector[i]);
    }

  /* After building the heap from the file, PRINT the current state of the heap before sorting */
    printf("Heap before sorting:%s\n",filename);
     heap.PrintHeap();

  /* STORE how many comparisons were made until this point */
    printf("InsertHeap: %d comparisons\n",heap.compare_num);
    heap.compare_num = 0; //重新计数
  /* DELETE elements from the Heap, copying it back to the vector in a way that it is sorted */
  /* STORE how many comparisons were made for the deletion process */
    heap.DeleteRoot();
    printf("DeleteRoot: %d comparisons\n",heap.compare_num);
  /* PRINT the number of comparisons for the Insert and Deletion tasks */

  /* Print the state of the vector after sorting */
    printf("Vector after sorting:\n");
    heap.PrintHeap();

}




int main( int argc, char** argv ){//get filename from arguments
	char expression[100];
	int number;
	ifstream input_file_random;
	ifstream input_file_reversed;
	ifstream input_file_sorted;
	if(argc==4) {
	  input_file_random.open(argv[1]);
	  input_file_reversed.open(argv[2]);
	  input_file_sorted.open(argv[3]);
	}
	else {printf("The program needs 3 filenames, in this order: random, reversed and sorted.\n");exit(0);}
	int number_of_elements_random=0;
	while(input_file_random >> number){
		sscanf(expression,"%d",&number);
		/*Comment out this printout, this is just to check that the file can be read */
//		printf("%d ",number );
		vector_random.push_back(number);
		number_of_elements_random++;
	}
	/*Comment out this printout, this is just to check that the array was copied */
	printf("File %s:\n", argv[1]);
	for(int count=0;count<number_of_elements_random;count++){
		printf("%d ",vector_random[count]);
	}
	printf("\n");
	/*end printout*/

	int number_of_elements_reversed=0;
	while(input_file_reversed >> number){
		sscanf(expression,"%d",&number);
		/*Comment out this printout, this is just to check that the file can be read */
//		printf("%d ",number );
		vector_reversed.push_back(number);
		number_of_elements_reversed++;
	}
	/*Comment out this printout, this is just to check that the array was copied */
	printf("File %s:\n", argv[2]);
	for(int count=0;count<number_of_elements_reversed;count++){
		printf("%d ",vector_reversed[count]);
	}
	printf("\n");
	/*end printout*/

	int number_of_elements_sorted=0;
	while(input_file_sorted >> number){
		sscanf(expression,"%d",&number);
		/*Comment out this printout, this is just to check that the file can be read */
//		printf("%d ",number );
		vector_sorted.push_back(number);
		number_of_elements_sorted++;
	}
	/*Comment out this printout, this is just to check that the array was copied */
	printf("File %s:\n", argv[3]);
	for(int count=0;count<number_of_elements_sorted;count++){
		printf("%d ",vector_sorted[count]);
	}
	printf("\n");
	/*end printout*/

	/* Implement or call your Heap sort here, the Heap class with methods should be copied/implemented before main() */
	heapsort(vector_random, number_of_elements_random, argv[1]);
	cout << endl;
	heapsort(vector_reversed, number_of_elements_reversed, argv[2]);
	cout << endl;
	heapsort(vector_sorted, number_of_elements_sorted, argv[3]);
}
