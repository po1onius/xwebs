#include "webserver.h"
#include <getopt.h>
int main(int argc, char** argv)
{
    struct option opt[]={{"port",1,NULL,'p'},{"mode",1,NULL,'m'},{"timeout",1,NULL,'t'},{"threadcount",0,NULL,'n'},{NULL,0,NULL,0}};
    int index;
    int port = 23333;
    int mode = 3;
    int timeout = 6000;
    int threadcount = 6;
    while(1)
    {
        char c=(char)getopt_long(argc,argv,"p:m:t:n",opt,&index);
        if(c<0)
        {
            break;
        }
        switch (c)
        {
            case 'p' :
            {
                port=atoi(optarg);
                break;
            }
            case 'm' :
            {
                mode=atoi(optarg);
                break;
            }
            case 't' :
            {
                timeout = atoi(optarg);
                break;
            }
            case 'n':
            {
                threadcount = atoi(optarg);
                break;
            }
            default :
            {
                break;
            }
        }
    }
    WebServer server(port,mode, timeout, false,threadcount);
    server.Start();
}
