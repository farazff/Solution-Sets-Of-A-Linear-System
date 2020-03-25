#include <iostream>
using namespace std;

float a[100][100];

int pcol = 1,row,col,upperrow = 1;
	
void interchange(int non_zero,int lastpivot)
{
	float temp[col+2];

	for(int i=1;i<=col;i++)
	{
		temp[i]=a[non_zero][i];
	}
	for(int i=1;i<=col;i++)
	{
		a[non_zero][i]=a[lastpivot][i];
	}
	for(int i=1;i<=col;i++)
	{
		a[lastpivot][i]=temp[i];
	}
}	
	
void print()
{
	
	for(int i=1;i<=row;i++)
	{
		for(int j=1;j<=col+1;j++)
		{
			printf("%.1f\t",a[i][j]);
		}
		printf("\n");
	}	
	printf("\n");
}	

int findfirstnonzero()
{
	for(int i=upperrow;i<=row;i++)
	{
		if(a[i][pcol]!=0)
		{
			return i;
		}
	}
	return 0;
}

int hasAnswer()
{
	for(int i=1;i<=row;i++)
	{
		int allrowzero=1;
		for(int j=1;j<=col;j++)
		{
			if(a[i][j]!=0)
				allrowzero=0;
		}
		if(allrowzero==1)
		{
			if(a[i][col+1]!=0)
			{
				return 0;
			}
		}
	}	
	return 1;
}

int main()
{
	printf("Solving equation problem\n");
	printf("Faraz Farangizadeh\n");
	printf("Code: 9726060\n");
	printf("Enter the number of rows : ");
	scanf("%d",&row);
	printf("Enter the number of columns : ");
	scanf("%d",&col);
	
	// Taking Inputs
	
	printf("Enter the AUGMENTED Matrix:\n");
	for(int i=1;i<=row;i++)
	{
		for(int j=1;j<=col+1;j++)
		{
			scanf("%f",&a[i][j]);
		}
	}
	
	printf("Your Matrix is : \n");
	print();
	
	while(pcol<=col)
	{
		if( findfirstnonzero()!=0 )
		{
			int firstnonzero = findfirstnonzero();
			interchange(firstnonzero,upperrow);
			float pivot = a[upperrow][pcol];
			for(int i=1;i<=col+1;i++)
			{
				a[upperrow][i]/=pivot;
			}
			
			for(int i=upperrow+1;i<=row;i++)
			{
				float temp = a[i][pcol];
				for(int j=1;j<=col+1;j++)
				{
					a[i][j] = a[i][j] - (temp)*a[upperrow][j];
				}
			}
			
			for(int i=1;i<=upperrow-1;i++)
			{
				float temp = a[i][pcol];
				for(int j=1;j<=col+1;j++)
				{
					a[i][j] = a[i][j] - (temp)*a[upperrow][j];
				}
			}
			//print();
			pcol++;
			upperrow++;
		}
		else
		{
			pcol++;
		}
		print();
	}
	print();
	
	if(hasAnswer() == 0)
	{
		printf("Incosistent\n");
		return 0;
	}
	
	for(int i=1;i<=row;i++)
	{
		for(int j=1;j<=col;j++)
		{
			if(a[i][j]==1)
			{
				printf("%c = %.2f ",'a'+j-1,a[i][col+1]);
				for(int k=j+1;k<=col;k++)
				{
					if(a[i][k]!=0)
					{
						printf("+(%.2f%c) ",-a[i][k],'a'+k-1);
					}
				}
			}
		}
		printf("\n");
	}	
		
}
