
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

/*****************************************************************************/
int ValidCiph(unsigned char p)
/*****************************************************************************/
{
    return (p>=0x30)&&(p<=0x39);
}
/*****************************************************************************/
int ValidSysAdr(unsigned char *p)
/*****************************************************************************/
{
    int ret=0;

    if(ValidCiph(p[0])&&
       ValidCiph(p[1])&&
       ValidCiph(p[2])&&
       ValidCiph(p[3])&&
       atoi((const char*)p)>0x800)
    {
       ret=1;
    }
    return ret;
}


/*****************************************************************************/
int findsys(const char *fname, char *outfname)
/*****************************************************************************/
{
    FILE *h;
    unsigned char buf[0x10004]={0};
    unsigned char mem[0x10004]={0};
    int strmem=0, endmem=0, readbytes, ok, testb, newaddr;

    h=fopen(fname,"rb");
    if(h==NULL)
    {
        return 3;
    }
    readbytes=fread(buf,1,0x10002,h);
    fclose(h);
    if(readbytes<16)
    {
        return 4;
    }
    strmem=buf[0]|(buf[1]<<8);
    endmem=strmem+readbytes-2;
    memmove(mem+strmem,buf+2,readbytes-2);

    // seek for next sys, skip the 1st
    if(mem[0x805]==0x9e)
    {
        strmem=0x806;
    }
    if(mem[0x80a]==0x9e)
    {
        strmem=0x80b;
    }
    ok=-1;
    newaddr=0x801;
    for(;strmem<endmem;strmem++)
    {
        if(mem[strmem]==0x9e)
        {
            if(ValidSysAdr(mem+strmem+1))
            {   /*sys2064*/
                ok=4;
                if(mem[strmem-5]==0)
                {
                    if(memcmp(mem+strmem-4,"1001",4)==0)
                    {   /*hiddensysline: \01001x2066 */
                        ok=9;
                        break;
                    }
                    if(memcmp(mem+strmem-4," SCC",4)==0)
                    {   /*hiddensysline: \0 SCCx2066 */
                        ok=9;
                        break;
                    }
                    if(memcmp(mem+strmem-4,"\xD0\xC5\xD4\x21",4)==0)
                    {   /*hiddensysline: \0PET!x2088 (bitimploder)*/
                        ok=9;
                        break;
                    }
                }
                break;
            }
            else if(mem[strmem+1]==0x20)
            {
                if(ValidSysAdr(mem+strmem+2))
                {   /*sys 2064*/
                    ok=4;
                    break;
                }
                if(mem[strmem+2]==0x28)
                {   /*sys (2064)*/
                    if(ValidSysAdr(mem+strmem+3))
                    {
                        ok=4;
                        break;
                    }
                }
            }
            else if(mem[strmem+1]==0x28)
            {
                if(ValidSysAdr(mem+strmem+2))
                {   /*sys(2064)*/
                    ok=4;
                    break;
                }

            }
            else if(mem[strmem+1]==0xff) /*sysPI*656 (ABCruncher)*/
            {
                if((mem[strmem+2]==0xac)&&(mem[strmem+3]==0x36))
                {
                    ok=4;
                    break;
                }

            }
        }
        else if( (*(unsigned int*)(mem+strmem+0x00)==0x8538A978) &&
                 (*(unsigned int*)(mem+strmem+0x04)==0x9AF9A201) &&
                 (mem[strmem+0x08]==0xBD) )
        {
            /* mr. cross */
            testb=strmem-(*(unsigned short int*)(mem+strmem+0x09));
            if (testb == 0x4c )
            {
                ok=0;
                newaddr=strmem;
            	break;
            }
        }
    }
    if(ok>=0)
    {
        strmem-=ok;
        readbytes=endmem-strmem;
        if(newaddr==0x801)
	        sprintf(outfname,"%s_%04x.prg",fname,strmem);
        else
            sprintf(outfname,"%s_%04x.%04x",fname,strmem,newaddr);
        h=fopen(outfname,"wb");
        if(!h)
        {
            return 2;
        }
        fputc(newaddr&0xff,h);
        fputc(newaddr>>8  ,h);
        fwrite(mem+strmem,readbytes,1,h);
        fclose(h);
    }
    else
    {
        return 1;
    }

    return 0;
}
/*****************************************************************************/
int main(int argc, char *argv[])
/*****************************************************************************/
{
    int i;
    char outfname[MAX_PATH]={0};
    if(argc<2)
    {
        printf("FindSYS v0.4 (/) iAN CooG\r\n");
        printf("Provide a prg please\r\n");
        return 1;
    }
    i=findsys(argv[1],outfname);
    switch(i)
    {
        case 0:
        printf("Created %s\r\n",outfname);
        break;
        case 1:
        printf("Found nothing in %s\r\n",argv[1]);
        break;
        case 2:
        printf("Create Error %s\r\n",outfname);
        break;
        case 3:
        printf("Open Error %s\r\n",argv[1]);
        break;
        case 4:
        printf("Too short file %s\r\n",argv[1]);
        break;
    }

return 0;
}
