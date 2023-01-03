#include <bits/stdc++.h>
#define int long long int
using namespace std;
#define maxn 10000001
bool isprime(int n){
    //miller algo check prime in o(logn).
    if(n==1) return false;
    if(n==2||n==3) return true;
    if(n%2==0||n%3==0)return false;
    for(int i=5;i<=sqrt(n);i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

void sieve(int n){
    bool isprime[n+1];
    fill(isprime,isprime+n+1,true);
    isprime[1]=false;
    for(int i=2;i<=sqrt(n);i++){
        if(isprime[i]){
            for(int j=i*i;j<=n;j+=i){
                isprime[j]=false;
            }
        }
    }
    for(auto &it:isprime){
        cout<<it<<" ";
    }
}

//primefactor in o(logn)
vector<int>leastprime(maxn,0);
void l_prime(){
    //call l_prime from main function.
    leastprime[1]=1;
    for(int i=1;i<maxn;i++){
        leastprime[i]=i;
    }
    for(int i=2;i*i<maxn;i++){
        if(leastprime[i]==i){
            for(int j=i*i;j<maxn;j+=i){
                if(leastprime[j]==j)
                leastprime[j]=i;
            }
        }
    }

    return;
}
vector<int> getFactorization(int x)
{
    vector<int> ret;
    int y;
    while (x != 1)
    {
       y=leastprime[x];
       while (x%y==0)
       {
        x/=y;
       }
       ret.push_back(y);
       
    }
    return ret;
}

//count the factors of number in an array o(nlog(max))
//call_lprime also
// if n is very large the we have traverse through all prime number till 10^5 (remember n div spoj solution)
int totalfactor(int n){
    //total=(1+c1)*(1+c2)*(1+c3).....(1+cn) and cn is count of distinct prime factor of n
    int y;
    int ans=1;
    while(n!=1){
        int c=0;
        y=leastprime[n];
        while(n%y==0){
            n/=y;
            c++;
        }
        ans*=(1+c);

    }
    return ans;
    
}
// do google about euler totient fn : this fn count the how main numbers are prime with respect to n from 1 to n-1 or gcd(x,n)=1x<=n-1


// if number is greater than 10^6 then we cant store lpf so for this
#define k 100000
bool prime[k];
vector<int> primes;
void seive(){
    //call sieve
    fill(prime, prime+k, true);
	for(int i = 3; i*i < k; i+=2){
		if(prime[i])
			for(int j = i*i; j < k; j += 2*i)
				prime[j] = false;
	}
	primes.push_back(2);
	for(int i = 3; i < k; i += 2)
		if(prime[i])
			primes.push_back(i);
}
int factor(int n){
    int ans=1;
    for(auto &it:primes){
        int y=it;
        int cn=0;
        if(y>n){
            break;
        }
        while(n%y==0){
            n/=y;
            cn++;
        }
        ans*=(1+cn);
    }
    if(n>1){
        ans*=2;
    }
    return ans;
}

// next_permutation
void next_permuatation1(){
    string s;
    // int arr[]; or vector
    do{
        cout<<s<<" "; // it will print all permuation of this
    }while(next_permutation(s.begin(),s.end()));
}


//jaha pe integer ka jagah pe string ka jarurat hoga to hum waha string hi input le lenge except conveting into string
signed main(){
    int tt;
    cin>>tt;
    l_prime();
    while(tt--)
    {
                int n;
                cin>>n;
                
                cout<<totalfactor(n);
                
    }
}