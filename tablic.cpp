#include <iostream>
#define N 1001

using namespace std;

int num;
int qcnt;
int posx[N];  
int posy[N]; 
int disx[N];  
int disy[N];  
void move(int ansx, int ansy, int cur)
{
    for (int j = cur + 1; j <= qcnt; j++)
    {
        if (posx[j] == posx[cur])
        {
            posy[j] += ansy;    
            if (posy[j] > num) 
            {
                posy[j] -= num;
            }
        }
        if (posy[j] == disy[cur])
        {
            posx[j] += ansx;   
            if (posx[j] > num) 
            {
                posx[j] -= num;
            }
        }
    }
}

int main()
{
    cin >> num >> qcnt;
    for (int i = 1; i <= qcnt; i++)
    {
        int value;  
        cin >> value >> disx[i] >> disy[i];
        posy[i] = value % num;
        if (posy[i] == 0)
        {
            posy[i] = num;
        }
        posx[i] = (value - posy[i]) / num + 1;
    }
    for (int i = 1; i <= qcnt; i++)
    {
        int ansx;  
        int ansy;  
        if (disx[i] >= posx[i])  
        {
            ansx = disx[i] - posx[i];
        } else  
        {
            ansx = disx[i] - posx[i] + num;
        }
        if (disy[i] >= posy[i])  
        {
            ansy = disy[i] - posy[i];
        } else  
        {
            ansy = disy[i] - posy[i] + num;
        }
        move(ansx, ansy, i);         
        cout << ansx + ansy << endl;  
    }
    return 0;
}

