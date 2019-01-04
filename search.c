/****************************

LICENSE

https://github.com/mintorchid/mintFileSearch

Copyright 2018-2019 mintorchid 992652081@qq.com



Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at

   http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License.

****************************/

#include<stdio.h>
#include<string.h>

int main(){
    int id;
    char filename[] = "001";
    const char SUFFIX[] = ".txt";
    char src[28] = "./";

    FILE *fr = NULL;
    const int MEM = 1024 * 2;
    char buff[MEM];
    char input[64];
    char term[256][256];
    char ans[512][128];
    char *temp;
    int tcount, anscount, i, j, t;
    int search[256];

    int bevery_search;
    int total_search, every_search;
    int ans_search[512];
    char tans[128];

    while(1){
        gets(input);
            fflush(stdin);
            gets(buff);

            bevery_search = 0;//TODO

            anscount = 0;
            tcount = 0;
            temp = strtok(buff, " ");
            while(temp != NULL) {
                strcpy(term[tcount], temp);
                tcount++;
                temp = strtok(NULL, " ");
            }

            id = 1;
            strcpy(filename, "001");
            strcpy(src, "./");
            strcat(src, filename);
            strcat(src, SUFFIX);
            fr = fopen(src, "r");
            while(fr){
                for(i = 0; i < tcount; i++)
                {
                    search[i] = 0;
                }
                while(!feof(fr)){
                    memset(buff, '\0', sizeof(buff));
                    fgets(buff, MEM, fr);

                        for(i = 0; i < tcount; i++)
                        {
                            temp = strstr(buff, term[i]);
                            while(temp != NULL) {
                                if((temp + strlen(term[i]))[0] == ' ' || (temp + strlen(term[i]))[0] == '\0') {
                                    if(strcmp(temp, buff) == 0 || (temp - 1)[0] == ' ') {
                                        search[i]++;
                                    }
                                }
                                temp = strstr(temp + strlen(term[i]), term[i]);
                            }
                        }
                }
                fclose(fr);

                total_search = 0;
                for(i = 0; i < tcount; i++)
                {
                    total_search += search[i];
                }

                every_search = 1;
                for(i = 0; i < tcount; i++)
                {
                    if(search[i] == 0) {
                        every_search = 0;
                        break;
                    }
                }

                if (total_search > 0) {
                    if (bevery_search == 0 || (bevery_search == 1 && every_search == 1)) {
                        strcpy(ans[anscount], filename);
                        strcat(ans[anscount], SUFFIX);
                        ans_search[anscount] = total_search;
                        anscount++;
                    }
                }


                strcpy(src, "./");
                id++;
                sprintf(filename, "%d", id);
                if(id < 100) {
                    char temp[4] = "0";
                    strcat(temp, filename);
                    strcpy(filename, temp);
                    if (id < 10) {
                    char temp[4] = "0";
                    strcat(temp, filename);
                    strcpy(filename, temp);
                    }
                }

                strcat(src, filename);
                strcat(src, SUFFIX);
                fr = fopen(src, "r");
            }


                for(i = 0; i < anscount - 1; i++)
                {
                    for(j = 0; j < anscount - 1 -i; j++)
                    {
                        if (ans_search[j] < ans_search[j + 1]) {
                            t = ans_search[j];
                            ans_search[j] = ans_search[j + 1];
                            ans_search[j + 1] = t;

                            strcpy(tans, ans[j]);
                            strcpy(ans[j], ans[j + 1]);
                            strcpy(ans[j + 1], tans);
                        }
                    }
                }


            for(i = 0; i < anscount; i++)
            {
                printf("%s", ans[i]);
                if (i != anscount - 1) {
                    printf(" ");
                }
                else {
                    printf("\n");
                }
            }
        }
    return 0;
}