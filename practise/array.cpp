#include<iostream>
#include<vector>
using namespace std;
int main()
 {
	//code
	int T, n, *arr=NULL;
	int i=0, j=0;
	int factor=-1;
	int *res = (int *)malloc(T*sizeof(int));
	cin>>T;
    while(j<T){
        cin>>n;
        arr = (int *)malloc(n*sizeof(int));
        for(i=0; i<n; i++){
            cin>>arr[i];
        }
        
        for(i=n-1; i>=0; i--){
            factor = factor*(-1);
            res[j] += factor*arr[i]*arr[i];
        }
        free(arr);
        j++;
        factor = -1;
    }
    for(i=0;i<T;i++)
        cout<<res[i]<<endl;

	return 0;
}