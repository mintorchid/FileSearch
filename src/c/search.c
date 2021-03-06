/****************************

LICENSE

https://github.com/mintorchid/mintFileSearch

Copyright 2018-2019 mintorchid 992652081@qq.com



Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at

   http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License.

****************************/

#include "search.h"

int get_total_frequency (const int count, const int frequency[BLOCK]) {
    int total = 0;

    for(int i = 0; i < count; i++)
    {
        total += frequency[i];
    }

    return total;
}

int get_every_frequency (const int count, const int frequency[BLOCK]) {
    int every = 1;

    for(int i = 0; i < count; i++)
    {
        if(frequency[i] == 0) {
            every = 0;
            return every;
        }
    }

    return every;
}
