#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <cstdlib>
#include <cmath>
void help()
{
    std::cout << "Параматры:\n'-m' ln;\n'-d' log(y)x\n количесво оперантов  1 для ln и 2 для log(y)x, где второе основание  \n строка должна выглядеть так -m 1 2 3 4 5 6 \n ";
    exit(1);
}
int main(int argc, char **argv)
{
    if (argc==1) {
       std::cout << "Параматры:\n'-m' ln;\n'-d' log(y)x\n количесво оперантов  1 для ln и 2 для log(y)x  \n ";
}
    
    int opt,i,st=0;
    double multi=1,b,d;
    for(i=2; i<argc; i++) {
        st+=1;
    }
    while((opt = getopt(argc, argv, "md:h")) != -1) {
        switch(opt) {  
        case 'm':
        if (( st >1) and (st!=0)){
        help();
    }
            for(i=2; i<argc; i++) {
                b = strtod(argv[i], NULL);
                multi=log(b);
            }
           	std::cout << "ln: " << multi << std::endl;
      		break;
        case 'd':
        if (( st !=2) and (st!=0)){
        help();
    }
            b = strtod(argv[2], NULL);
            for(i=3; i<argc; i++) {
                d = strtod(argv[i], NULL);
                b = log(b)/log(d);
                st+=1;
            }
            	std::cout << "log(y)x: " << b << std::endl;
            
            break;
        case 'h':
            help();
        case '?':
            help();
        default:
        std::cout <<"-h:"<<std::endl;
        help();
        exit(1);
        }
    }
}