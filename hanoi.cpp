#include <iostream>

using namespace std;

//void hanoi(int n, char *s,char *i,char *d);
int num_moves=0;



//void hanoi(int n,char *s,char *i,char *d) // s stands for source tower; d stands for destination tower; i stands for intermediate tower
//{
//    //cout << "in hanoi\n";
//    if(n>0)
//    {
//        //cout << num_moves << " hanoi(" << n-1 << "," << s << "," << d << "," << i << ")" << endl;
//        //hanoi(n-1,s,d,i);    // move n-1 disks from source to intermediate tower
//        cout << "Hanoi " << n-1 << " " << s << " " << i << " " << d << endl;
//        hanoi(n-1,s,i,d);
//        //cout<<"Disk "<<n<<" is moved from "<<s<<" to "<<d<<endl;        // move the disk from to source to destination
//        num_moves++;
//        cout << "Hanoi " << n-1 << " " << i << " " << d << " " << s << endl;
//        hanoi(n-1,i,d,s);
//        //cout << num_moves << " hanoi(" << n-1 << "," << i << "," << s << "," << d << ")" << endl;
//        //hanoi(n-1,i,s,d);    // move n-1 disks from intermediate to destination
//    }
//}

void hanoi(int n,char *s,char *d,char *i) // s stands for source tower; d stands for destination tower; i stands for intermediate tower
{
    //cout << "in hanoi\n";
    if(n>0)
    {
        //cout << num_moves << " hanoi(" << n-1 << "," << s << "," << d << "," << i << ")" << endl;
        //hanoi(n-1,s,d,i);    // move n-1 disks from source to intermediate tower
        cout << "Hanoi " << n-1 << " " << s << " " << i << " " << d << endl;
        hanoi(n-1,s,i,d);
        //cout<<"Disk "<<n<<" is moved from "<<s<<" to "<<d<<endl;        // move the disk from to source to destination
        num_moves++;
        cout << "Hanoi " << n-1 << " " << i << " " << d << " " << s << endl;
        hanoi(n-1,i,d,s);
        //cout << num_moves << " hanoi(" << n-1 << "," << i << "," << s << "," << d << ")" << endl;
        //hanoi(n-1,i,s,d);    // move n-1 disks from intermediate to destination
    }
}

int main()
{
    int disks;
    cout << "How many disks? ";
    cin >> disks;
    cout << "Hanoi 4 Tower 1, Tower 2, Tower 3" << endl;
    hanoi(disks, "Tower 1", "Tower 2", "Tower 3");
    cout << "It took " << num_moves << " to do this." <<endl;
    return 1;
}
