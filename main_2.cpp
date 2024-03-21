#include<vector>
#include<iostream>
using namespace std;

int l=0,r=0,current = 1;
long long result,amount;
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

        current=current*2+1;
        v.push_back((current)%2);
        l++;
        dfs(n);
        current=(current-1)/2;
        v.pop_back();
        l--;

        current=current*2;
        v.push_back((current)%2);
        r++;
        dfs(n);
        current=current/2;
        v.pop_back();
        r--;

    }
}

long long factorial(int n){
    if(n-1>0){
        result = n*factorial(n-1);
    }
    else{
        result = 1;
    }
    return result;
}

long long catalan(int n){
    amount = factorial(n*2)/(factorial(n+1)*factorial(n));
    return amount;
}

int main()
{
    int n;
    unsigned long long combinations;
    while(cin >> n){

        combinations = catalan(n);
        if(combinations>1e+4){
            cout << "There are " << combinations << " combinations in total." << endl;
            cout << "There are too many combinations to output." << endl;
        }
        else if(n>12){
            cout << "There are too many combinations to output." << endl;
        }
        else{
            dfs(n);
            cout << "There are " << combinations << " combinations in total." << endl;
        }

    }
    return 0;

}
