/****************************

LICENSE

https://github.com/mintorchid/mintFileSearch

Copyright 2018-2019 mintorchid 992652081@qq.com



Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at

   http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License.

****************************/

#include "term.h"

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
