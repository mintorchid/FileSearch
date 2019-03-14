/****************************

LICENSE

https://github.com/mintorchid/mintFileSearch

Copyright 2018-2019 mintorchid 992652081@qq.com



Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at

   http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License.

****************************/

#include <stdio.h>
#include <string.h>

#include "search.h"

int tok (char buffer[BUFFER_Size], char str[BLOCK][BLOCK], const char *delim) {
    int count = 0;

    char *temp = strtok(buffer, delim);
    while (temp != NULL) {
        strcpy(str[count], temp);
        count++;
        temp = strtok(NULL, delim);
    }

    return count;
}

void init_array (const int size, int *array) {
    for(int i = 0; i < size; i++)
    {
        array[i] = 0;
    }
}

int main() {

    //data block
    //char input[BLOCK];//input from keyboard
    int term_count;
    char term[BLOCK][BLOCK];//terms will be search
    int frequency[BLOCK];//the frequency of term which be searched
    int total_frequency, every_frequency;
    int answer_count;
    int answer_frequency[BLOCK];
    char answer_filename[BLOCK][BLOCK];

    //buffer
    char buffer[BUFFER_Size];
    int i, j;//use to cycle
    int temp_int;
    char *temp_char_star;
    char temp_char_array[BLOCK];

    //file
    char src[28] = "./";//search source address
    char filename[] = "001";
    const char SUFFIX[] = ".txt";//filename suffix
    FILE *fr = NULL;//put file will be search
    int id;//TODO, use to change filename

    //TODO
    int bevery_frequency;//TODO, to explain if need exact search

    while(1){
        //gets(input);
            //fflush(stdin);
            gets(buffer);

            bevery_frequency = 0;//TODO

            answer_count = 0;

            term_count = tok(buffer, term, delim);

            id = 1;
            strcpy(filename, "001");
            strcpy(src, "./");
            strcat(src, filename);
            strcat(src, SUFFIX);
            fr = fopen(src, "r");
            while(fr){
                init_array(term_count, frequency);
                while(!feof(fr)){
                    memset(buffer, '\0', sizeof(buffer));
                    fgets(buffer, sizeof(buffer), fr);

                        for(i = 0; i < term_count; i++)
                        {
                            temp_char_star = strstr(buffer, term[i]);
                            while(temp_char_star != NULL) {
                                if((temp_char_star + strlen(term[i]))[0] == ' ' || (temp_char_star + strlen(term[i]))[0] == '\0' || (temp_char_star + strlen(term[i]))[0] == '\n') {
                                    if(strcmp(temp_char_star, buffer) == 0 || (temp_char_star - 1)[0] == ' ') {
                                        frequency[i]++;
                                    }
                                }
                                temp_char_star = strstr(temp_char_star + strlen(term[i]), term[i]);
                            }
                        }
                }
                fclose(fr);

                total_frequency = get_total_frequency(term_count, frequency);

                every_frequency = get_every_frequency(term_count, frequency);

                if (total_frequency > 0) {
                    if (bevery_frequency == 0 || (bevery_frequency == 1 && every_frequency == 1)) {
                        strcpy(answer_filename[answer_count], filename);
                        strcat(answer_filename[answer_count], SUFFIX);
                        answer_frequency[answer_count] = total_frequency;
                        answer_count++;
                    }
                }


                strcpy(src, "./");
                id++;
                sprintf(filename, "%d", id);
                if(id < 100) {
                    char temp_char_star[4] = "0";
                    strcat(temp_char_star, filename);
                    strcpy(filename, temp_char_star);
                    if (id < 10) {
                    char temp_char_star[4] = "0";
                    strcat(temp_char_star, filename);
                    strcpy(filename, temp_char_star);
                    }
                }

                strcat(src, filename);
                strcat(src, SUFFIX);
                fr = fopen(src, "r");
            }


                for(i = 0; i < answer_count - 1; i++)
                {
                    for(j = 0; j < answer_count - 1 -i; j++)
                    {
                        if (answer_frequency[j] < answer_frequency[j + 1]) {
                            temp_int = answer_frequency[j];
                            answer_frequency[j] = answer_frequency[j + 1];
                            answer_frequency[j + 1] = temp_int;

                            strcpy(temp_char_array, answer_filename[j]);
                            strcpy(answer_filename[j], answer_filename[j + 1]);
                            strcpy(answer_filename[j + 1], temp_char_array);
                        }
                    }
                }


            for(i = 0; i < answer_count; i++)
            {
                printf("%s", answer_filename[i]);
                if (i != answer_count - 1) {
                    printf(" ");
                }
                else {
                    printf("\n");
                }
            }
        }
    return 0;
}