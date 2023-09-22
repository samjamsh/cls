#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#endif

int main(int argc, char *argv[]) {
#ifdef _WIN32
	int option;
	
	if (argc > 2) {
		printf("parameter error: too many parameters\n");	
		return 0;
	} 
	else if (argc == 1) {
	    option = 0;
    }
	else if (argc == 2 && strcmp(argv[1], "-i") == 0) {
	    option = 1;
	}

	else if (argc == 2 && strcmp(argv[1], "-h") == 0) {
		
		char *program_name = argv[0];
		
		printf("This is help message of MCP (Multplatform Clear Program) version 1.0\nusage: %s {option}\n\n[option]\n       -i  ignore default cursor location: this options cleans the terminal screen but do not put cursor on the default location (left top or on the left at the top) it just cleans and ignore cursor location\n\nexample: %s\n", program_name, program_name);
		
		return 0;	
	}
	
	else {
		printf("parameter error: invalid parameter\n");
		return 0;
    }
	
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    

    COORD coord = {0, 0}; // define a coordenada de inicio para (0, 0)
    

    DWORD count;
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    GetConsoleScreenBufferInfo(hConsole, &csbi);


    DWORD cellCount = csbi.dwSize.X * csbi.dwSize.Y;

 
    FillConsoleOutputCharacter(hConsole, ' ', cellCount, coord, &count);
    
    
    switch (option) {
    	case 0:
    		SetConsoleCursorPosition(hConsole, coord);
    		break;
    		
    	case 1:
            coord = csbi.dwCursorPosition;
            SetConsoleCursorPosition(hConsole, coord);
            break;
 		
    	default:
    		printf("source code syntax error\n");
	}

    return 0;
    
#else
    printf("operational system not supported\n");
    return 0;
    
#endif
return 0;
}
