//
//  main.cpp
//  function
//
//  Created by bondsam on 06/06/2018.
//  Copyright © 2018 bondsam. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;
struct term {
    float coef;//系数
    int expn;//指数
};
void enter(term t[])
{
    int n;//项数
    cout<<"请输入多项式项数: "<<endl;
    cin>>n;
    for (int i=0; i<100; i++) {
        t[i].coef=0;
        t[i].expn=i;
    }
    cout<<"请输入每一项的系数和指数： "<<endl;
    int ch1,ch2;
    for(int i=0;i<n;i++){
        cout<<"请输入系数： ";
        cin>>ch1;
        cout<<"请输入指数： ";
        cin>>ch2;
        cout<<"---------------------------------"<<endl;
        t[ch2].coef+=ch1;
        t[ch2].expn=ch2;
    }
}
void putup(term t[])
{
    int k=0;
    for (int i=0; i<100; i++) {
        if (t[i].coef!=0) {
            t[k++]=t[i];
        }
    }
    t[k].expn=100;
}
void print(term t[])
{
    int k=0;
    for (int i=0; i<100; i++) {
        if (t[i].coef!=0) {
            t[k++]=t[i];
        }
    }
    t[k].expn=100;
    cout<<"f(x)=";
    if(t[0].expn!=0){
        cout<<t[0].coef<<"x^"<<t[0].expn;}
    else
    cout<<t[0].coef;
    int i=1;
    while(t[i].expn!=100) {
        if (t[i].coef>0&&t[i].expn!=0) {
            cout<<'+'<<t[i].coef<<"x^"<<t[i].expn;
        }
        if (t[i].coef<0&&t[i].expn!=0) {
            cout<<t[i].coef<<"x^"<<t[i].expn;
        }
        if (t[i].expn==0) {
            cout<<t[i].coef;
        }
        i++;
    }
    cout<<endl;
}
void Plus(term t[])
{
    term t1[100],t2[100];
    cout<<"第一个多项式： \n";
    enter(t1);
    cout<<"第二个多项式： \n";
    enter(t2);
    for (int i=0; i<100; i++) {
        t[i].coef=t1[i].coef+t2[i].coef;
    }
    print(t);
}
void Minus(term t[])
{
    term t1[100],t2[100];
    cout<<"第一个多项式： \n";
    enter(t1);
    cout<<"第二个多项式： \n";
    enter(t2);
    for (int i=0; i<100; i++) {
        t[i].coef=t1[i].coef-t2[i].coef;
    }
    print(t);
}
double cal(term t[],int x)
{
    double sum=0;
    enter(t);
    print(t);
    int i=0;
    while (t[i].expn!=100) {
        sum+=t[i].coef*pow(x, t[i].expn);
        i++;
    }
    return sum;
}
int main()
{
    term t[100];
    for (int i=0; i<100; i++) {
        t[i].coef=0;
        t[i].expn=i;
    }
    term tx[2];
    tx[0].coef=3;tx[0].expn=2;
    tx[1].coef=2;tx[1].expn=4;
    int choice;
    cout<<"请选择要实现的功能：   \n实现一元多项式的输入和输出选1   \n能够进行一元多项式相加选2   \n能够进行一元多项式相减选3  \n计算一元多项式在x处的值选4\n";
    cin>>choice;
    switch (choice) {
        case 1:
            enter(t);
            print(t);
            break;
            
        case 2:
            Plus(t);
            break;
        case 3:
            Minus(t);
            break;
        case 4:
            int x;
            cout<<"请输入你想要的x值： ";
            cin>>x;
            cout<<cal(t,x)<<endl;
        default:
            break;
    }
}















