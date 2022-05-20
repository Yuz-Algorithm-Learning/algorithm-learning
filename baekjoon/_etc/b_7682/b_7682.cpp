#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    
    string str;
    while(1) {
        cin >> str;

        if(str == "end")
            break;
        
        int n1 = 0, n2 = 0;
        for(int i = 0; i < 9; i++) {
            if(str[i] == 'X')
                n1++;
            else if(str[i] == 'O')
                n2++;
        }

        bool n1_x = false, n2_o = false;
        if(str[0] == str[1] && str[1] == str[2] && str[2] == 'X') n1_x = true;
        if(str[0] == str[1] && str[1] == str[2] && str[2] == 'O') n2_o = true;
        if(str[3] == str[4] && str[4] == str[5] && str[5] == 'X') n1_x = true;
        if(str[3] == str[4] && str[4] == str[5] && str[5] == 'O') n2_o = true;
        if(str[6] == str[7] && str[7] == str[8] && str[8] == 'X') n1_x = true;
        if(str[6] == str[7] && str[7] == str[8] && str[8] == 'O') n2_o = true;

        if(str[0] == str[3] && str[3] == str[6] && str[6] == 'X') n1_x = true;
        if(str[0] == str[3] && str[3] == str[6] && str[6] == 'O') n2_o = true;
        if(str[1] == str[4] && str[4] == str[7] && str[7] == 'X') n1_x = true;
        if(str[1] == str[4] && str[4] == str[7] && str[7] == 'O') n2_o = true;
        if(str[2] == str[5] && str[5] == str[8] && str[8] == 'X') n1_x = true;
        if(str[2] == str[5] && str[5] == str[8] && str[8] == 'O') n2_o = true;

        if(str[0] == str[4] && str[4] == str[8] && str[8] == 'X') n1_x = true;
        if(str[0] == str[4] && str[4] == str[8] && str[8] == 'O') n2_o = true;

        if(str[2] == str[4] && str[4] == str[6] && str[6] == 'X') n1_x = true;
        if(str[2] == str[4] && str[4] == str[6] && str[6] == 'O') n2_o = true;

        if(n1_x && !n2_o && n1 - n2 == 1) cout << "valid\n";
        else if(!n1_x && n2_o && n1 == n2) cout << "valid\n";
        else if(!n1_x && !n2_o && n1 == 5 && n2 == 4) cout << "valid\n";
        else cout << "invalid\n";
    }

    return 0;
}