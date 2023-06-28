#include <bits/stdc++.h> 
using namespace std;

// Implementation of Min Heap
vector<int> minHeap(int n, vector<vector<int>>& q) {
    
}



class Heap {
    public:
        int arr[100];
        int size;

        Heap() {
            arr[0] = -1;
            size  = 0;
        }

        void insert(int val) {
            size = size + 1;
            int index = size;
            arr[index] = val;

            while (index > 1) {
                int parent = index / 2;

                if(arr[parent] < arr[index]) {
                    swap(arr[parent], arr[index]);
                    index = parent;
                } else {
                    return ;
                }
            }
            
        }

        void deleteFromHeap() {
            if(size == 0) {
                return ;
            }

            arr[1] = arr[size];
            size--;

            int i = 1;
            while (i < size) {
                int leftIndex = 2*i;
                int rightIndex = 2*i+1;

                if (leftIndex < size && arr[i] < arr[leftIndex]) {
                    swap(arr[i], arr[leftIndex]);
                    i = leftIndex;
                } else if(rightIndex < size && arr[i] < arr[rightIndex]) {
                    swap(arr[i], arr[rightIndex]);
                    i = rightIndex;
                } else {
                    return ;
                }
                
            }
            
        }

        void print() {
            for (int i = 1; i < size + 1; i++) {
                cout<< arr[i] << " ";
            } cout<<endl;   
            
        }
};

int main() {
    Heap h;
    h.insert(50);
    h.insert(20);
    h.insert(10);
    h.insert(70);
    h.insert(80);
    h.print();
}