#include <iostream>
using namespace std;
class num{
public:
	char a[10];
	int o;
};

class hexa: public num{
public:
	int val;
	hexa(){ val =0;}
	void read(){
		cout<<"Enter hexadecimal number "<<endl;
		cin>> a;
	}
	void hextodec(){

		int t, i, j = 1, n=0;
		for(i=0; a[i] != '\0'; i++){
			n++;
			//cout<<a[i];
		}
		for(i=n-1; i>=0; i--){
			if(a[i] > '9'){
				t = a[i] -87;
				val = val + (t*j);
				
			}

			else{
				t = a[i] - 48;
				val = val + (t*j);

			}
		j = j * 16;
		}
		cout<<"Hexadecimal to decimal is "<<val << endl;
	}
};

class octal: public num{
public:
	int val1;
	octal(){ val1 =0; }
	void read(){
		cout<<"Enter octal number"<<endl;
		cin>>o;
	}
	void octaltodec(){
		int j1=1, d;
		while(o != 0){
			d = o%10;
			val1 = val1 + (d * j1);
			o = o/10;
			j1 = j1 * 8;
		}
	cout<<"The octal to decimal is "<<val1<<endl;
	}

	friend int operator+(hexa h1, octal n2);
};

int operator+(hexa n1, octal n2){
	int k = n1.val + n2.val1;
	return k;

}

int operator+(octal n1, int n2){
	int x = n1.val1 + n2;
	return x;
}





int main(){
	hexa j;
	cout<<"Enter j"<<endl;
	j.read();
	j.hextodec();
	octal k,h;
	cout<<"Enter k"<<endl;
	k.read();
	k.octaltodec();
	int  i = j + k;
	cout<<"The value of i = "<<i<<endl<<endl;
	cout<<"Enter h"<<endl;
	h.read();
	h.octaltodec();
	cout<<"Enter a integer number k "<<endl;
	int no;
	cin>>no;
	int y = h+no;
	cout<<"The value of y = "<<y;
	return 0;
}


/*
======== OUTPUT ========

Enter j
Enter hexadecimal number
2b
Hexadecimal to decimal is 43
Enter k
Enter octal number
4756
The octal to decimal is 2542
The value of i = 2585

Enter h
Enter octal number
234
The octal to decimal is 156
Enter a integer number k
11
The value of y = 167

*/



