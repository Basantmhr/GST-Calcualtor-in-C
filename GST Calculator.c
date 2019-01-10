/*--------------------------HEADER_FILES----------------------------*/ 
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<conio.h>



/*--------------------------VARIABLE_DECLARATION----------------------------*/ 
int slab=0,flag;
int Record_id;
float amount,total_amount,GST;
char name[30];         //variable to add the name of item


/*--------------------------FUNCTIONS----------------------------*/ 
void cal_amount();    // function to calculate the amount of GST on an item
void putData();      //function to Write Data to a File
void getData(int id);     // function to Read Data to a File
void slab_select();
void show_all();

/*--------------------------MAIN_FUNCTION----------------------------*/ 
main()
{ 
 int choice;
	system("cls");
	     do{ system("cls");
		     printf("\n\t\t\t\t**********************************************************\n");
			 printf("\n\t\t\t\t                  GST CALCULATOR                          \n");
			 printf("\n\t\t\t\t**********************************************************\n");
		     printf("\n1.Add a GST Record:");
		     printf("\n2.Show a GST Record:");
		     printf("\n3.Show All Products");
		     printf("\n4.Exit");
		     printf("\nEnter Your Choice::");
		     scanf("%d",&choice);
		     switch(choice){
			        case 1: putData();
			                break;
			        case 2: printf("\n Enter Record ID::");
			                scanf("%d",&Record_id);
					        getData(Record_id);
			                break;
			        case 3: show_all();
			                break;
			        case 4:exit(0);
			        default: printf("\nPlease Enter A valid Choice!!!");
			  
		                   };
	        }while(choice!=4);
}


/*--------------------------FUNCTION_TO_WRITE_DATA----------------------------*/ 
void putData(){
    FILE *file;
    file=fopen("GST_Data.dat","a");
    fflush(stdin);
    printf("\nEnter The Name of Item::");
    gets(name);
    slab_select();
    if(slab==0)
    slab_select();

	
	printf("\n Enter The amount of the Item::");
	scanf("%f",&amount);
	printf("\n Enter a Record ID::");
	scanf("%d",&Record_id);
	GST=amount*slab*0.01;
	total_amount=amount + GST;
	fprintf(file,"%d %s %f %d %f %f \n",Record_id,name,amount,slab,GST,total_amount);
	printf("\n Data Saved Successfully!!");
	printf("\n Press Any Key to Return to Main Menu::");
	char ch =getch();
	fclose(file);
}

/*--------------------------FUNCTION_TO_READ_DATA----------------------------*/ 
void getData(int id){ 
FILE *file;
file = fopen("GST_Data.dat","r");

         if(!file){
         	printf("\n File Not Found!!");
         	exit(0);
		 }

         while(fscanf(file,"%d %s %f %d %f %f \n",&Record_id,name,&amount,&slab,&GST,&total_amount)!=EOF)
		{
			 
			if(Record_id==id)
		
		   {
			flag=1;
			printf("\n\t\t\t\t**********************************************************\n");
			printf("\n\t\t\t\t RECORD ID   :: %ld",id);
			printf("\n\t\t\t\t ITEM NAME   :: %s",name );
			printf("\n\t\t\t\t AMOUNT      :: %.2f Rs",amount);
			printf("\n\t\t\t\t GST SLAB    :: %d %%",slab);
			printf("\n\t\t\t\t GST         :: %.2f Rs",GST);
			printf("\n\t\t\t\t TOTAL AMOUNT:: %.2f Rs",total_amount);
			printf("\n\t\t\t\t**********************************************************\n");
			printf("\nPress Any Key to Return to Main Menu::");
			char ch =getch();
			continue;
		   }
	    }
	         if(flag==0)
           	{
		printf("\n\t\t\t\t SORRY!!!!!!!! NO DATA FOUND PLEASE TRY AGAIN:");
	        }

	fclose(file);
 }
 
 
 /*--------------------------FUNCTION_TO SELECT_A SLAB----------------------------*/ 
void slab_select(){
	int choice;
	
	
	printf("\nSelect A GST Slab::");
	printf("\n1.  5%% ");
	printf("\n2. 12%% ");
	printf("\n3. 18%%");
	printf("\n4. 28%%");
	printf("\n Choose Your Choice::");
	scanf("%d",&choice);
	switch(choice){
		case 1: slab = 5;
		         break;
		case 2: slab =12;
		        break;
	    case 3: slab = 18;
		         break;
		case 4: slab =28;
		        break;	
		default: printf("\n Enter a Valid slab!");
						  
	};

}

/*--------------------------FUNCTION_TO_SHOW_ALL_RECORDS----------------------------*/ 
void show_all(){
	
	FILE *file;
	file = fopen("GST_Data.dat","r");
	if(!file)
	{
	printf("\n\nFILE NOT FOUND!!!");
	exit(0);}
	else{
	
	 while(fscanf(file,"%d %s %f %d %f %f \n",&Record_id,name,&amount,&slab,&GST,&total_amount)!=EOF)
		{
			 
			
		
		   
			printf("\n\t\t\t\t**********************************************************\n");
			printf("\n\t\t\t\t RECORD ID   :: %ld",Record_id);
			printf("\n\t\t\t\t ITEM NAME   :: %s",name );
			printf("\n\t\t\t\t AMOUNT      :: %.2f Rs",amount);
			printf("\n\t\t\t\t GST SLAB    :: %d %%",slab);
			printf("\n\t\t\t\t GST         :: %.2f Rs",GST);
			printf("\n\t\t\t\t TOTAL AMOUNT:: %.2f Rs",total_amount);
			printf("\n\t\t\t\t**********************************************************\n");
			printf("\n\n\n");
			
		
	    }
		printf("\n\nEnter any Key to Go to main Menu"); 
		char ch = getch();
		
		
	
}
}
/*--------------------------END_OF_PROJECT----------------------------*/ 
