#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<fstream>
#include<string>

using namespace std;

int main(int argc, char** argv)
{

	if(argc < 5)
	{
		printf("Usage: \n");
		printf("./Dump inputDir outputDir listFile bgpdumppath\n");
		exit(EXIT_FAILURE);
	}

	string line;
	string inputDirectory = string(argv[1]);
	string outputDirectory = string(argv[2]);
	ifstream myfile(argv[3]);
	string bgpdumppath = "cd " + string(argv[4]);
  
	FILE *pFile;
	
	
	if(myfile.is_open())
	{	
		while(myfile.good())
		{
			getline(myfile,line);
			string inputfilename= line;
			cout<<inputfilename<<endl;

			string outputfilename = outputDirectory;
			outputfilename = outputfilename + inputfilename + ".txt" ;
			pFile = fopen(outputfilename.c_str(),"w");
			
		
			if(pFile != NULL)
			{
			cout<<"Created file"<<endl;
			int x = system(bgpdumppath.c_str());
			string str = "./bgpdump ";
			str =  str + inputDirectory  + inputfilename + "> " + outputfilename;
			cout<<str<<endl;
			int y = system(str.c_str());
			fclose(pFile);
			}
			
		}
		myfile.close();
	}
	else
		cout<<"Unable to open file"<<endl;

	return 0;
}
