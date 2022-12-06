#include <stdio.h>

// Function to fill int array with values
void fill_arr(int* iArr, int val, int sz)
{
    for(int i=0; i < sz; i++)
    {
        iArr[i] = val;
    }
}

void increment_arr(char* str, int* iArr)
{
    int ascii;
    for(int i=0; str[i] != '\0'; i++)
    {
        ascii = (int)str[i];
        iArr[ascii] += 1;

    }
}

int main(int argc, char** argv)
{
    // Create an array with one spot for each possible char
    int iArr[126];
    fill_arr(iArr, 0, 126);

    // Loop through argv strings; convert to ASCII; Add 1 in arr
    for(int i=1; i < argc; i++)
    {
        increment_arr(argv[i], iArr);
    }

    // Loop through iArr, printf on each element that exists
    for(int i=0; i < 126; i++)
    {
        if(iArr[i] > 0)
        {
            printf("%c:%d\n", (char)i, iArr[i]);
        }
    }

    return 0;
}

/*
./my_ngram "abcd"
int iArr[126] ----> [, , , , ... , , ]
fill_arr(iArr, 0, 126); ----> iArr[126] =  [0, 0, 0, ... , 0, 0]
increment_arr(argv[1], iArr);
argv[1] = "abcd";
argv[1][0] = 'a' ----> (int)argv[1][0] = 97 = ascii_1
argv[1][1] = 'b' ----> (int)argv[1][1] = 98 = ascii_2
iArr[ascii_1] += 1 ----> iArr[97] += 1 ----> [0, 0, 0, ...., 1, 0, ... , 0, 0 ]
iArr[ascii_2] += 1 ----> iArr[98] += 1 ----> [0, 0, 0, ...., 1, 1, ... , 0, 0 ]
iArr = [0, 0, 0, ...., 1, 1, 1, 1, ..., 0, 0]
for (int i=0; i < 126; i++)
(char)97 = 'a';
iArr[i]= iArr[97] = 1; 
printf("%c:%d\n", (char)i, iArr[i])
a:1
b:1
c:1
d:1
// Test
*/