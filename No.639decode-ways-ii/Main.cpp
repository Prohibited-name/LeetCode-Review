#include <iostream>
#include <vector>
using namespace std;

//dp[i] -->> 前i个字符的解码总数
//dp[i + 1] = dp[i] * 第i个字符的解码数量 + dp[i - 1] * 第i和i + 1字符的解码数量

int getDecodeWays(char ch1, char ch2){
    if(ch1 == '*' && ch2 == '*'){
        return 15;
    }
    if(ch1 == '*'){
        if(ch2 <= '6')return 2;
        return 1;
    }
    if(ch2 == '*'){
        if(ch1 == '1')return 9;
        if(ch1 == '2')return 6;
        return 0;
    }
    if(ch1 == '1')return 1;
    if(ch1 == '2' && ch2 <= '6')return 1;
    return 0;
}

int decodeWays(std::string &s){
    if(s.length() == 0)return 0;
    long prev = 1;
    long cur = 0;
    if(s[0] == '*'){
        cur = 9;
    }
    else if(s[0] == '0'){
        cur = 0;
    }
    else{
        cur = 1;
    }
    for(int i = 1;i < s.length();i++){
        int temp = cur;
        if(s[i] == '*'){
            cur = (9 * cur + getDecodeWays(s[i - 1], s[i]) * prev) % 1000000007;
        }
        else if(s[i] == '0'){
            cur = getDecodeWays(s[i - 1],s[i]) * prev % 1000000007;
        }
        else{
            cur = (cur + getDecodeWays(s[i - 1], s[i]) * prev) % 1000000007;
        }
        prev = temp;
    }
    return cur;
}



int main(){
    std::string s;
    std::cin >> s;
    std::cout << decodeWays(s) << std::endl;
}