/*****************************************************************************/
/***																	   ***/
/***		Modificado por G.J.L.P.										   ***/
/***		Añadidos nuevos mensajes que indican falta de algún 	 	   ***/
/***		Fichero de Configuración (No específico para ningún	  		   ***/
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

inline void show_message(const char * msg)
{
	cout << endl << "Error: " << msg << endl;
	cout << endl << " " << endl;
	exit(-1);
}

inline void show_message(Messages::value value)
{
	switch (value)
	{
		case Messages::WrongNumArgs:
			show_message("number of arguments in the execution call is incorrect !!");
			break;
		case Messages::ConfFileNotFound:
			show_message("It's imposible find Configuration file !!");
			break;
		/* Específicos de RLFAP */
		case Messages::CelarCstFileNotFound:
			show_message("It is imposible find the Celar problem definition file (cst.txt) !!");
			break;
		case Messages::CelarDomFileNotFound:
			show_message("It is imposible find the Celar domains file (dom.txt) !!");
			break;
		case Messages::CelarVarFileNotFound:
			show_message("It is imposible find the Celar links file (var.txt) !!");
			break;
		case Messages::CelarCtrFileNotFound:
			show_message("It is imposible find the Celar constraints file (ctr.txt) !!");
			break;
		/* Fallos de Memoria */
		case Messages::MallocError:
			show_message("No avalible memory for \"malloc\" operation !!");
			break;
		case Messages::FreeError:
			show_message("in \"free\" operation !!");
			break;
		/* Específicos del MaxCut */
		case Messages::MaxcutFileNotFound:
			show_message("It is imposible find the Maxcut file (Maxcut.txt) !!");
			break;
		/* Genéricos de Falta de ficheros de configuracion  adicionales al mensaje 2 */
		case Messages::ConfigFileNotFound:
			show_message("It's imposible find Configuration file (Config.cfg) !!");
			break;
		case Messages::SkeletonFileNotFound:
			show_message("It's imposible find Skeleton Configuration File (Ske.cfg) !!");
			break;
		case Messages::InstanceProblemFileNotFound:
			show_message("It's imposible find Instance Problem File !!");
			break;
		case Messages::ResultFileNotFound:
			show_message("It's imposible find Resultate File !!");
			break;
		case Messages::IndexOutOfRange:
			show_message("Index out of Range !!");
			break;
		default: show_message("Unkown Error !!");
	}
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
