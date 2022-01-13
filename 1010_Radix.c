#include <iostream>
#include <cctype>
#include <algorithm>
#include <cmath>
#include <string>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
long long convert(string n,long long radix) {
	long long sum = 0;
	int index=0,tmp=0;
	for(auto it=n.rbegin();it!=n.rend();it++) {
		tmp = isdigit(*it)?*it-'0':*it-'a'+10;
		sum += tmp*pow(radix,index++);
	}
	return sum;
}
long long find_radix(string n,long long num) {
	char it = *max_element(n.begin(),n.end());
	long long low = (isdigit(it)?it-'0':it-'a'+10)+1;
	long long high = max(low,num);
	while(low<=high) {
		long long mid = (low+high)/2;
		long long t = convert(n,mid);
		if(t<0||t>num) high = mid - 1;
		else if(t==num) return mid;
		else low = mid + 1;
	} 
	return -1;
}

int main(int argc, char** argv) {
	string n1,n2;
	long long tag=0,radix=0,result_radix;
	cin>>n1>>n2>>tag>>radix;
	result_radix = tag==1?find_radix(n2,convert(n1,radix)):find_radix(n1,convert(n2,radix));
	if(result_radix!=-1) {
		printf("%lld",result_radix);
	} else {
		printf("Impossible");
	}
	
	return 0;
}
