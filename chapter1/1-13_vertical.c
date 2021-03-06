#include<stdio.h>

int main()
{
	int c,i,length[10],max = 0;
	for(i = 0 ; i < 10 ; ++i)
	{
		length[i] = 0;
	}
	i = 0;
	while((c = getchar()) != EOF && i < 10)
	{
		if(c == ' ' || c == '\t' || c == '\n')
		{
			++i;		//means a word is over and goto next index now to store length of next word
		}
		else
		{
			++length[i];	//counting the length of a word
		}
	}
	printf("\n");			//just for formating so that output comes in next line
	for(i = 0 ; i < 10 ; ++i)
	{
		if(length[i] >= max)
		{
			max = length[i];//determining the longest word i.e the index with max. value
		}
	}
	printf("max : %d\n",max);	//optional...printing the max length of word
	for(i = 0 ; i < 10 ; ++i)
		printf("%d ",length[i]);	//optional...printing the valuse of various indices
	printf("\n");			//new line...so that next output comes in new line
	while(max > 0)			//starting from max. value
	{
		for(i = 0 ; i < 10 ; ++i)
		{
			if(length[i] >= max)
				printf("||\t");	//if the length is greater than current value of max....print a bar
			else
				printf("  \t");	//here if length of a particular value is less than current max. value...print a blank
		}
		printf("\n");			//one level of graph is complete now \n for next level
		--max;				//going one level down
	}
	for(i = 0 ; i < 10 ; ++i)
		printf("%d \t",i);		//just printing the indices under each bar
	printf("\n");
	return 0;
}
