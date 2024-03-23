#include<vector>
#include<iostream>
using namespace std;


int l=0,r=0;
vector<int> v;

void dfs(int n){

    if(v.size() == n*2){
        if(l==r){
            for(int i=0; i < v.size(); i++){
            if(v[i]){cout << "(";}
            else{cout << ")";}
                }
            cout << endl;
            }
        }

    if(r>l || l>n){return;}
    else{

        v.push_back(1);
        l++;
        dfs(n);
        v.pop_back();
        l--;

        v.push_back(0);
        r++;
        dfs(n);
        v.pop_back();
        r--;

    }
}

long long combin(int m,int n){
    
    if(n>1 && m!=n){
        return combin(m-1,n)+combin(m-1,n-1);
    }
    else if(m==n){
        return 1;
    }
    else if(n=1){
        return m;
    }

}

long long catalan(int n){

    return combin(n*2,n)/(n+1);

}

int main(){

    int n;
    string choice ;
    while(cin >> n){
        if(n<100){
            cout << "There are " << catalan(n) << " combinations in total." << endl;
            cout << "Do you want to output them? (y/n)" << endl;
            cin >> choice;
            if(choice=="y"){
                dfs(n);
                cout << endl;
            }
            else if(choice=="n"){
                cout << "All right." << endl << endl;
            }
        }
        else{
            cout << "Please enter an integer less than 17" << endl << endl;
        }
    }
    return 0;

}
