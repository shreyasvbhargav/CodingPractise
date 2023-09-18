/*set
N = 5
count = 0
arr = [-1 -1 -1 -1 -1] 
insert(2): arr = [2, -1, -1 ,-1, -1], count = 1
insert(4): arr = [2, 4, -1 ,-1, -1], count = 2
remove(2): arr = [4, -1 -1 ,-1, -1], count = 1
lookup(4): arr = [4, -1 -1 ,-1, -1], count = 1 output - true
clear() : arr = [4, -1 -1 ,-1, -1], count = 0
iterate(func f){ 
    for(i=0; i<count; i++)
    f(arr[i])
}

req:
insert, remove, lookup, clear : O(1)
iterate : O(count)

*/

// [0, N)
// N = 5, arr = [0, 0, 0, 0, 0]
// insert(2) arr = [0, 0, 1, 0, 0]


struct Set1 {
    int N;
    int arr[N];
    
    // O(1)
    void insert(int x) {
        // TODO
        //arr[x] = 1;
    
        arr[x] = 1;
    }
 
    // O(1)
    void remove(int x) {
        // TODO
        //arr[x] = 0;
        
        arr[x] = 0;
    }
 
    // O(1)
    bool lookup(int x) {
        // TODO
        if(arr[x])
           return true;
        return false; 
    }
 
    // O(N)
    void clear() {
        // TODO
        memset(arr, 0, N*sizeof(int));
    }
 /*
 for (int i=0;i<N;i++) {
            f(i);
        }*/
    // O(N)
    void iterate(func_t f) {
        // TODO
        for(int i=0; i<N; i++)
            if(arr[i])
                f(i);
        
    }
};

// N = 5, arr = [-1, -1, -1, -1, -1], count = 0
// insert(2) arr = [2, -1, -1, -1, -1], count = 1
// insert(4) arr = [2, 4, -1, -1, -1], count = 2
// remove(4) arr = [2, 4, -1, -1, -1], count = 1
// arr = [2, -1, 3, 5, -1], count = 3

// lookup(2)

struct Set2 {
    int N;
    int arr[N];
    int count = 0;
 
 //O(count)
    void insert(int x) {
        // TODO
        if(!lookup( x))
            arr[count++] = x;
    }
 
 //O(count)
    void remove(int x) {
        // TODO
        for(int i =0; i<count; i++)
            if(arr[i] == x){
                arr[i] = arr[count-1];
                arr[count-1] = -1;
            }
        count--;
    }
 
  //O(count)
    bool lookup(int x) {
        // TODO
        for(int i =0; i<count; i++)
            if(arr[i] == x)
                return true;
    
        return false;
    }
 
  //O(1)
    void clear() {
        // TODO
        count = 0;
    }
 
  //O(count)
    void iterate(func_t f) {
        // TODO
        for(int i =0; i<=count; i++)
            if(arr[i]>0)
                f(arr[i]);
    }
};


// N = 5, arr = [-1, -1, -1, -1, -1], count = 0
// insert(2) arr = [2, -1, -1, -1, -1], count = 1 index = [-1, -1, 0, -1, -1]
// insert(4) arr = [2, 4, -1, -1, -1], count = 2 index = [-1, -1, 0, -1, 1]

// remove(4) arr = [2, 4, -1, -1, -1], count = 1
// arr = [2, -1, 3, 5, -1], count = 3

struct Set3 {
    int N;
    int arr[N];
    int index[N];
    int count = 0;
    // O(1)
    void insert(int x) {
        // TODO
        if(index[x] == -1){
            arr[count] = x;
            index[x] = count++;
        }
    }
 
    // O(1)
    
    //arr: -1 -1 -1, count = 0, index= -1 -1 -1
    //insert(0) 0 -1 -1, count = 1, index= 0 -1 -1
    //insert(2) 0 2 -1, count = 2, index= 0 -1 1
    //remove(0) 2 -1 -1, count = 1, index= -1 -1 1
    void remove(int x) {
        // TODO
        if(count && index[x] > -1)
        {
            pos = index[x];
            arr[pos] = arr[count-1];
            arr[count-1] = -1;
            count--;
            index[x] = -1;
            index[arr[pos]] = pos;
        }
    }
 
    // O(1)
    bool lookup(int x) {
        // TODO
        if(count){
            if(index[x] > -1)
                return true;
        }
        return false;
    }
 
    // O(1)
    void clear() {
        // TODO
        count = 0;
    }
 
    // O(count)
    void iterate(func_t f) {
        // TODO
        if(count){
            for(i=0; i< count; i++)
                f(arr[i]);
        }
    }
};

// Set1 s = new Set1();
// s.iterate(f)
