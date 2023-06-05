#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int test(char *string)
{
  for(int i=0;i<strlen(string);i++)
  {
    if(!(string[i]>=48 && string[i]<=57) && string[i]!='-')
    {
      return 0;
    }
  }
  return 1;
}
void simple_assembler(int n,char *program[n],int registers[],int c)
{
  char a,*address,temp1[50],temp2;
  for(int i=0;i<n;i++)
  {
    if(strstr(program[i],"mov"))
    {
      strcpy(temp1,program[i]);
      address=strtok(temp1," ");
      for(c=1;address;c++)
      {
        if(c==2)
        {
          temp2=address[0];
        }
        else if(c==3)
        {
          registers[temp2]=(test(address)) ? atoi(address):registers[address[0]];
        }
        address=strtok(NULL," ");
      }
    }
    else if(strstr(program[i],"inc"))
    {
      sscanf(program[i],"inc %c",&a);
      registers[a]++;
    }
    else if(strstr(program[i],"dec"))
    {
      sscanf(program[i],"dec %c",&a);
      registers[a]--;
    }
    else if(strstr(program[i],"jnz"))
    {
      strcpy(temp1,program[i]);
      address=strtok(temp1," ");
      for(c=1;address;c++)
      {
        if(c==2)
        {
          if(address[0]==48 || (address[0]>=97 && address[0]<=122 && !registers[address[0]]))
          {
            break;
          }
        }
        else if(c==3)
        {
          i+=(test(address)==0) ? registers[address[0]]-1:atoi(address)-1;
        }
        address=strtok(NULL," ");
      }
    }
  }
}
