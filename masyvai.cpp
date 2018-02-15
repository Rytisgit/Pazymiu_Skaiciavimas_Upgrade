#include <iostream>

using namespace std;

int main()
{
    int *a = new int [1];
    int *b {};
    int index{0},size{1};
    bool aistheone=true;
    int n={0};
    while (n!=-1){
        cin>>n;
        if(n==-1){break;};
        if(aistheone){a[index]=n; cout<<"n is "<<n<<endl;}
        else b[index]=n;
        index++;
        if (index==size){
            if(aistheone){
                    size*=2;
                b= new int [size];
                for(int i = 0;i<size;i++){
                    b[i]=a[i];
                     for(int i = 0;i<size;i++){
                    cout<<"a"<<a[i]<<endl;
                }
                }
                delete a;
            }
            else {
                size*=2;
                a= new int [size];
                for(int i = 0;i<size;i++){
                    a[i]=b[i];
                    for(int i = 0;i<size;i++){
                    cout<<"b"<<b[i]<<endl;
                }
                }
                delete b;
            }
        }

    }

                   if(aistheone){
                for(int i = 0;i<index;i++){
                    cout<<"a ending"<<a[i]<<endl;
                }
            }
            else {
                for(int i = 0;i<index;i++){
                    cout<<"b ending"<<b[i]<<endl;
                }
            }

return 0;
}

