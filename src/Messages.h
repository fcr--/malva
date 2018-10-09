/*****************************************************************************/
/***																	   ***/
/***		Modificado por G.J.L.P.										   ***/
/***		A�adidos nuevos mensajes que indican falta de alg�n 	 	   ***/
/***		Fichero de Configuraci�n (No espec�fico para ning�n	  		   ***/
/***		problema) o nuevos errores.				  					   ***/
/***																	   ***/
/*****************************************************************************/

#ifndef RLFAP_MESSAGES
#define RLFAP_MESSAGES

#ifndef MAX_BUFFER
#define MAX_BUFFER 200
#endif

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct Messages
{
	enum value
	{
		WrongNumArgs = 1,
		ConfFileNotFound = 2,
		CelarCstFileNotFound = 3,
		CelarDomFileNotFound = 4,
		CelarVarFileNotFound = 5,
		CelarCtrFileNotFound = 6,
		MallocError = 7,
		FreeError = 8,
		MaxcutFileNotFound = 9,
		ConfigFileNotFound = 10,
		SkeletonFileNotFound = 11,
		InstanceProblemFileNotFound = 12,
		ResultFileNotFound = 13,
		IndexOutOfRange = 14,
		Other = -1,
	};
};

inline void show_message(Messages::value value)
{
	switch (value)
	{
		case Messages::WrongNumArgs:
			cout << endl << "Error: number of arguments in the execution call is incorrect !!" << endl;
			break;
		case Messages::ConfFileNotFound:
			cout << endl << "Error: It's imposible find Configuration file !!" << endl;
			break;
		/* Espec�ficos de RLFAP */
		case Messages::CelarCstFileNotFound:
			cout << endl << "Error: It is imposible find the Celar problem definition file (cst.txt) !!" << endl;
			break;
		case Messages::CelarDomFileNotFound:
			cout << endl << "Error: It is imposible find the Celar domains file (dom.txt) !!" << endl;
			break;
		case Messages::CelarVarFileNotFound:
			cout << endl << "Error: It is imposible find the Celar links file (var.txt) !!" << endl;
			break;
		case Messages::CelarCtrFileNotFound:
			cout << endl << "Error: It is imposible find the Celar constraints file (ctr.txt) !!" << endl;
			break;
		/* Fallos de Memoria */
		case Messages::MallocError:
			cout << endl << "Error: No avalible memory for \"malloc\" operation !!" << endl;
			break;
		case Messages::FreeError:
			cout << endl << "Error: in \"free\" operation !!" << endl;
			break;
		/* Espec�ficos del MaxCut */
		case Messages::MaxcutFileNotFound:
			cout << endl << "Error: It is imposible find the Maxcut file (Maxcut.txt) !!" << endl;
			break;
		/* Gen�ricos de Falta de ficheros de configuracion  adicionales al mensaje 2 */
		case Messages::ConfigFileNotFound:
			cout << endl << "Error: It's imposible find Configuration file (Config.cfg) !!" << endl;
			break;
		case Messages::SkeletonFileNotFound:
			cout << endl << "Error: It's imposible find Skeleton Configuration File (Ske.cfg) !!" << endl;
			break;
		case Messages::InstanceProblemFileNotFound:
			cout << endl << "Error: It's imposible find Instance Problem File !!" << endl;
			break;
		case Messages::ResultFileNotFound:
			cout << endl << "Error: It's imposible find Resultate File !!" << endl;
			break;
		case Messages::IndexOutOfRange:
			cout << endl << "Error: Index out of Range !!" << endl;
			break;
		default: cout << endl << "Unkown Error !!" << endl;
	}

	cout << endl << " " << endl;
	exit(-1);
}

inline void continue_question()
{
	fflush(stdout);
	cout << endl << "Press any key to continue..." << endl;
	fflush(stdin);
	getc(stdin);
}

inline void get_path(const char *source,char *target)
{
	int last = 0;

	for(int i = 0; i < strlen(source); i++)
	{
		target[i] = source[i];
		if(target[i] == '/')
			last = i;
	}
	target[last+1] = '\0';
}

inline unsigned count_lines(char *file_name) // returns the number of lines of a file
{
	char line[MAX_BUFFER];
	FILE *file;
	int count=0;

	if ((file=fopen(file_name,"r"))==NULL)
	{
		fflush(stdout);
		printf("File not found !");
	}
  
	while (!feof(file))
	{
		if (fgets(line,MAX_BUFFER,file)) count++;    		     	
		else
		{
			fclose(file);
			break;
		}
	}	
	return count;
}

#endif
