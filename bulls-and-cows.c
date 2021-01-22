// https://leetcode.com/problems/bulls-and-cows/

char * getHint(char * secret, char * guess){
    int sec[10] = {0}, gue[10] = {0}, i, cows = 0, bulls = 0;

    for(i = 0; secret[i] != '\0'; ++i){
        if(secret[i] == guess[i])
            ++bulls;
        else{
            ++sec[secret[i] - '0'];
            ++gue[guess[i] - '0'];
        }
    }
    
    for(i = 0; i < 10; ++i)
        cows += (sec[i] < gue[i] ? sec[i] : gue[i]);

    char* ans = (char *)malloc(sizeof(char)*50);
    sprintf(ans, "%dA%dB\0", bulls, cows);
    return ans;
}
