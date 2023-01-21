#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, board;
    cin >> n;
    while(n--){
        cin >> board;
        int cnt = 1;
        int oct;
        bitset<10> pos;
        bitset<10> x;
        while(board && cnt <= 18){
            oct = board%10;
            switch(oct){
                case 0:
                    cnt +=3;
                    break;
                case 1:
                    if(cnt <= 7)
                        pos.set(cnt);
                    else
                        x.set(cnt-9);
                    cnt += 3;
                    break;
                case 2:
                    if(cnt <= 7)
                        pos.set(cnt+1);
                    else
                        x.set(cnt+1-9);
                    cnt += 3;
                    break;
                case 3:
                    if(cnt <= 7){
                        pos.set(cnt);
                        pos.set(cnt+1);
                    }else{
                        x.set(cnt-9);
                        x.set(cnt+1-9);
                    }
                    cnt += 3;
                    break;
                case 4:
                    if(cnt <= 7)
                        pos.set(cnt+2);
                    else
                        x.set(cnt+2-9);
                    cnt += 3;
                    break;
                case 5:
                    if(cnt <= 7){
                        pos.set(cnt);
                        pos.set(cnt+2);
                    }else{
                        x.set(cnt-9);
                        x.set(cnt+2-9);
                    }
                    cnt += 3;
                    break;
                case 6:
                    if(cnt <= 7){
                        pos.set(cnt+2);
                        pos.set(cnt+1);
                    }else{
                        x.set(cnt+2-9);
                        x.set(cnt+1-9);
                    }
                    cnt += 3;
                    break;
                case 7:
                    if(cnt <= 7){
                        pos.set(cnt);
                        pos.set(cnt+1);
                        pos.set(cnt+2);
                    }else{
                        x.set(cnt-9);
                        x.set(cnt+1-9);
                        x.set(cnt+2-9);
                    }
                    cnt += 3;
                    break;
            }
            board = board/10;
        }
        if(pos[1] && pos[2] && pos[3]){
            if(x[1] == x[2] && x[2] == x[3]){
                if(x[1]){
                    cout << "X wins" << endl;
                    continue;
                }else{
                    cout << "O wins" << endl;
                    continue;
                }
            }
        }
        if(pos[4] && pos[5] && pos[6]){
            if(x[4] == x[5] && x[5] == x[6]){
                if(x[4]){
                    cout << "X wins" << endl;
                    continue;
                }else{
                    cout << "O wins" << endl;
                    continue;
                }
            }
        }
        if(pos[7] && pos[8] && pos[9]){
            if(x[7] == x[8] && x[8] == x[9]){
                if(x[7]){
                    cout << "X wins" << endl;
                    continue;
                }else{
                    cout << "O wins" << endl;
                    continue;
                }
            }
        }
        if(pos[1] && pos[4] && pos[7]){
            if(x[1] == x[4] && x[4] == x[7]){
                if(x[1]){
                    cout << "X wins" << endl;
                    continue;
                }else{
                    cout << "O wins" << endl;
                    continue;
                }
            }
        }
        if(pos[2] && pos[5] && pos[8]){
            if(x[2] == x[5] && x[5] == x[8]){
                if(x[2]){
                    cout << "X wins" << endl;
                    continue;
                }else{
                    cout << "O wins" << endl;
                    continue;
                }
            }
        }
        if(pos[3] && pos[6] && pos[9]){
            if(x[3] == x[6] && x[6] == x[9]){
                if(x[3]){
                    cout << "X wins" << endl;
                    continue;
                }else{
                    cout << "O wins" << endl;
                    continue;
                }
            }
        }
        if(pos[1] && pos[5] && pos[9]){
            if(x[1] == x[5] && x[5] == x[9]){
                if(x[1]){
                    cout << "X wins" << endl;
                    continue;
                }else{
                    cout << "O wins" << endl;
                    continue;
                }
            }
        }
        if(pos[3] && pos[5] && pos[7]){
            if(x[3] == x[5] && x[5] == x[7]){
                if(x[3]){
                    cout << "X wins" << endl;
                    continue;
                }else{
                    cout << "O wins" << endl;
                    continue;
                }
            }
        }
        if(pos[1] && pos[2] && pos[3] && pos[4] && pos[5] && pos[6] && pos[7] && pos[8] && pos[9])
            cout << "Cat's" << endl;
        else
            cout << "In Progress" << endl;
    }

}